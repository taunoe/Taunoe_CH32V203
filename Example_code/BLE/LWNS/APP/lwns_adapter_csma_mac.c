/********************************** (C) COPYRIGHT *******************************
 * File Name          : lwns_adapter_csma_mac.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2021/06/20
 * Description        : lwns适配器，模拟csma的mac协议
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
#include "lwns_adapter_csma_mac.h"
#include "lwns_sec.h"

//每个文件单独debug打印的开关，置0可以禁止本文件内部打印
#define DEBUG_PRINT_IN_THIS_FILE    1
#if DEBUG_PRINT_IN_THIS_FILE
  #define PRINTF(...)       PRINT(__VA_ARGS__)
#else
  #define PRINTF(...)       do{} while(0)
#endif

#if LWNS_USE_CSMA_MAC //是否使能模仿csma的mac协议，注意只能使能一个mac层协议。

//for lwns_packet_buffer save
__attribute__((aligned(4))) static lwns_qbuf_list_t qbuf_memp[QBUF_MANUAL_NUM];

    //for lwns_route_entry manage
  #if ROUTE_ENTRY_MANUAL_NUM
__attribute__((aligned(4))) static lwns_route_entry_data_t route_entry_memp[ROUTE_ENTRY_MANUAL_NUM];
  #endif

//for neighbor manage
__attribute__((aligned(4))) static lwns_neighbor_list_t neighbor_memp[LWNS_NEIGHBOR_MAX_NUM];

static void ble_new_neighbor_callback(lwns_addr_t *n);     //发现新邻居回调函数
static BOOL ble_phy_output(uint8_t *dataptr, uint8_t len); //发送接口函数
static void RF_2G4StatusCallBack(uint8_t sta, uint8_t crc, uint8_t *rxBuf);

static uint8_t  lwns_adapter_taskid;
static uint16_t lwns_adapter_ProcessEvent(uint8_t task_id, uint16_t events);
static uint8_t  lwns_phyoutput_taskid;
static uint16_t lwns_phyoutput_ProcessEvent(uint8_t task_id, uint16_t events);

/**
 * lwns必用的函数接口，将指针传递给lwns库内部使用
 */
static lwns_fuc_interface_t ble_lwns_fuc_interface = {
    .lwns_phy_output = ble_phy_output,
    .lwns_rand = tmos_rand,
    .lwns_memcpy = tmos_memcpy,
    .lwns_memcmp = tmos_memcmp,
    .lwns_memset = tmos_memset,
    .new_neighbor_callback = ble_new_neighbor_callback,
};

static uint8_t                            ble_phy_manage_state, ble_phy_send_cnt = 0, ble_phy_wait_cnt = 0; //ble phy状态管理，发送次数计数，等待次数计数
static struct csma_mac_phy_manage_struct *csma_phy_manage_list_head = NULL;                                 //mac管理发送列表指针
static struct csma_mac_phy_manage_struct  csma_phy_manage_list[LWNS_MAC_SEND_PACKET_MAX_NUM];               //mac管理发送列表管理数组

volatile uint8_t tx_end_flag=0;

/*********************************************************************
 * @fn      RF_Wait_Tx_End
 *
 * @brief   手动模式等待发送完成，自动模式等待发送-接收完成，必须在RAM中等待，等待时可以执行用户代码，但需要注意执行的代码必须运行在RAM中，否则影响发送
 *
 * @return  none
 */
__attribute__((section(".highcode")))
__attribute__((noinline))
void RF_Wait_Tx_End()
{
    uint32_t i=0;
    while(!tx_end_flag)
    {
        i++;
        __NOP();
        __NOP();
        // 约5ms超时
        if(i>(SystemCoreClock/1000))
        {
            tx_end_flag = TRUE;
        }
    }
}

/*********************************************************************
 * @fn      RF_2G4StatusCallBack
 *
 * @brief   RF 状态回调，注意：不可在此函数中直接调用RF接收或者发送API，需要使用事件的方式调用
 *
 * @param   sta     -   状态类型
 * @param   crc     -   crc校验结果
 * @param   rxBuf   -   数据buf指针
 *
 * @return  None.
 */
static void RF_2G4StatusCallBack(uint8_t sta, uint8_t crc, uint8_t *rxBuf)
{
    switch(sta)
    {
        case RX_MODE_RX_DATA:
        {
            if(crc == 1)
            {
                PRINTF("crc error\n");
            }
            else if(crc == 2)
            {
                PRINTF("match type error\n");
            }
            else
            {
                uint8_t *pMsg;
  #if LWNS_ENCRYPT_ENABLE //是否启用消息加密
                if(((rxBuf[1] % 16) == 1) && (rxBuf[1] >= 17) && (rxBuf[1] > rxBuf[2]))
                { //对齐后数据区最少16个字节，加上真实数据长度一字节
                    //长度校验通过，所以rxBuf[1] - 1必为16的倍数
                    pMsg = tmos_msg_allocate(rxBuf[1]); //申请内存空间，真实数据长度不需要解密
                    if(pMsg != NULL)
                    {
                        lwns_msg_decrypt(rxBuf + 3, pMsg + 1, rxBuf[1] - 1); //解密数据
                        if((rxBuf[2] ^ pMsg[rxBuf[2]]) == pMsg[rxBuf[2] + 1])
                        {
                            pMsg[0] = rxBuf[2];      //校验通过，存储真实数据长度
                            PRINTF("send rx msg\n"); //发送接收到的数据到接收进程中
                            tmos_msg_send(lwns_adapter_taskid, pMsg);
                        }
                        else
                        {
                            PRINTF("verify rx msg err\n"); //校验失败
                            tmos_msg_deallocate(pMsg);
                        }
                    }
                    else
                    {
                        PRINTF("send rx msg failed\n"); //申请内存失败，无法发送接收到的数据
                    }
                }
                else
                {
                    PRINTF("bad len\n"); //包长度不对
                }
  #else
                if(rxBuf[1] >= LWNS_PHY_OUTPUT_MIN_SIZE)
                { //数据长度符合，才会发送至协议栈内部处理
                    pMsg = tmos_msg_allocate(rxBuf[1] + 1);
                    if(pMsg != NULL)
                    {
                        PRINTF("send rx msg\n"); //发送接收到的数据到接收任务中
                        tmos_memcpy(pMsg, rxBuf + 1, rxBuf[1] + 1);
                        tmos_msg_send(lwns_adapter_taskid, pMsg);
                    }
                    else
                    {
                        PRINTF("rx msg failed\n"); //申请内存失败，无法发送接收到的数据
                    }
                }
                else
                {
                    PRINTF("bad len\n"); //包长度不对
                }
  #endif
                //当接收到一个数据包时，将本时间段内的还未开始的发送任务停止，等待下一时间段发送，已经开始的发送任务不暂停，模仿csma/ca，进行防碰撞相关检测。
                if(ble_phy_manage_state == BLE_PHY_MANAGE_STATE_WAIT_SEND)
                { //等待发送状态中收到数据包
                    PRINTF("send delay\n");
                    ble_phy_manage_state = BLE_PHY_MANAGE_STATE_RECEIVED;         //等待发送周期内收到了数据包状态
                    tmos_stop_task(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_EVT);   //竞争发送权限失败，放弃自己的发送任务。
                    tmos_clear_event(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_EVT); //放弃自己的发送任务
                }
            }
            tmos_set_event(lwns_adapter_taskid, LWNS_PHY_RX_OPEN_EVT); //重新打开接收
            break;
        }
        case TX_MODE_TX_FINISH:
        case TX_MODE_TX_FAIL:
            tmos_stop_task(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_FINISH_EVT); //停止超时计数
            tmos_set_event(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_FINISH_EVT); //进入发送完成处理
            break;
        default:
            break;
    }
}

/*********************************************************************
 * @fn      RF_Init
 *
 * @brief   RF 初始化.
 *
 * @param   None.
 *
 * @return  None.
 */
void RF_Init(void)
{
    uint8_t    state;
    rfConfig_t rfConfig;
    tmos_memset(&rfConfig, 0, sizeof(rfConfig_t));
    rfConfig.accessAddress = 0x17267162; // 禁止使用0x55555555以及0xAAAAAAAA ( 建议不超过24次位反转，且不超过连续的6个0或1 )，正确符合相应规则的accessaddress接入地址约有23亿个
    rfConfig.CRCInit = 0x555555;
    rfConfig.Channel = 8;
    rfConfig.LLEMode = LLE_MODE_BASIC; //|LLE_MODE_EX_CHANNEL; // 使能 LLE_MODE_EX_CHANNEL 表示 选择 rfConfig.Frequency 作为通信频点
    rfConfig.rfStatusCB = RF_2G4StatusCallBack;
    state = RF_Config(&rfConfig);
    PRINTF("rf 2.4g init: %x\n", state);
}

/*********************************************************************
 * @fn      lwns_init
 *
 * @brief   lwns初始化.
 *
 * @param   None.
 *
 * @return  None.
 */
void lwns_init(void)
{
    uint8_t       s;
    lwns_config_t cfg;
    tmos_memset(&cfg, 0, sizeof(lwns_config_t));
    cfg.lwns_lib_name = (uint8_t *)VER_LWNS_FILE; //验证函数库名称，防止版本出错
    cfg.qbuf_num = QBUF_MANUAL_NUM;               //必须分配，至少1个内存单位，根据你程序中使用的端口数对应模块使用的qbuf单位来定义。
    cfg.qbuf_ptr = qbuf_memp;                     //mesh最多使用3个qbuf单位，(uni/multi)netflood最多使用2个，其他模块都使用1个。
    cfg.routetable_num = ROUTE_ENTRY_MANUAL_NUM;  //如果需要使用mesh，必须分配路由表内存空间。不然mesh初始化不会成功。
  #if ROUTE_ENTRY_MANUAL_NUM
    cfg.routetable_ptr = route_entry_memp;
  #else
    cfg.routetable_ptr = NULL;
  #endif
    cfg.neighbor_num = LWNS_NEIGHBOR_MAX_NUM;                      //邻居表数量，必须分配
    cfg.neighbor_list_ptr = neighbor_memp;                         //邻居表内存空间
    cfg.neighbor_mod = LWNS_NEIGHBOR_AUTO_ADD_STATE_RECALL_ADDALL; //邻居表初始化默认管理模式为接收所有包，添加所有邻居并且过滤重复包的模式
  #if LWNS_ADDR_USE_BLE_MAC
    GetMACAddress(cfg.addr.v8); //蓝牙硬件的mac地址
  #else
    //自行定义的地址
    uint8_t MacAddr[6] = {0, 0, 0, 0, 0, 1};
    tmos_memcpy(cfg.addr.v8, MacAddr, LWNS_ADDR_SIZE);
  #endif
    s = lwns_lib_init(&ble_lwns_fuc_interface, &cfg); //lwns库底层初始化
    if(s)
    {
        PRINTF("%s init err:%d\n", VER_LWNS_FILE, s);
    }
    else
    {
        PRINTF("%s init ok\n", VER_LWNS_FILE);
    }
    lwns_adapter_taskid = TMOS_ProcessEventRegister(lwns_adapter_ProcessEvent);
    lwns_phyoutput_taskid = TMOS_ProcessEventRegister(lwns_phyoutput_ProcessEvent);
    tmos_start_task(lwns_phyoutput_taskid, LWNS_PHY_PERIOD_EVT, MS1_TO_SYSTEM_TIME(LWNS_MAC_PERIOD_MS));
    tmos_memset(csma_phy_manage_list, 0, sizeof(csma_phy_manage_list)); //清除发送管理结构体
    ble_phy_manage_state = BLE_PHY_MANAGE_STATE_FREE;                   //清除phy状态
    RF_Shut();
    RF_Rx(NULL, 0, USER_RF_RX_TX_TYPE, USER_RF_RX_TX_TYPE); //打开RF接收，如果需要低功耗管理，在其他地方打开。
}

/*********************************************************************
 * @fn      ble_new_neighbor_callback
 *
 * @brief   当发现一个新邻居时的回调函数.
 *
 * @param   n  - 新邻居的地址.
 *
 * @return  None.
 */
static void ble_new_neighbor_callback(lwns_addr_t *n)
{
    PRINTF("new neighbor: %02x %02x %02x %02x %02x %02x\n", n->v8[0], n->v8[1],
           n->v8[2], n->v8[3], n->v8[4], n->v8[5]);
}

/*********************************************************************
 * @fn      ble_phy_output
 *
 * @brief   lwns发送函数接口
 *
 * @param   dataptr     - 待发送的数据缓冲头指针.
 * @param   len         - 待发送的数据缓冲长度.
 *
 * @return  TRUE if success, FLASE is failed.
 */
static BOOL ble_phy_output(uint8_t *dataptr, uint8_t len)
{
    uint8_t                           *pMsg, i;
    struct csma_mac_phy_manage_struct *p;
    for(i = 0; i < LWNS_MAC_SEND_PACKET_MAX_NUM; i++)
    {
        if(csma_phy_manage_list[i].data == NULL)
        {
            break; //寻找到了一个空的结构体可以使用。
        }
        else
        {
            if(i == (LWNS_MAC_SEND_PACKET_MAX_NUM - 1))
            {
                PRINTF("send failed!\n"); //列表满了，发送失败，直接返回。
                return FALSE;
            }
        }
    }
  #if LWNS_ENCRYPT_ENABLE
    pMsg = tmos_msg_allocate((((len + 1 + 15) & 0xf0) + 1 + 1)); //校验位1位加上后再进行16字节对齐，存储发送长度+1，真实数据长度+1
  #else
    pMsg = tmos_msg_allocate(len + 1); //申请内存空间存储消息，存储发送长度+1
  #endif
    if(pMsg != NULL)
    { //成功申请
        p = csma_phy_manage_list_head;
        if(p != NULL)
        {
            while(p->next != NULL)
            { //寻找发送链表的终点
                p = p->next;
            }
        }
  #if LWNS_ENCRYPT_ENABLE
        //lwns buffer内部预留有两字节，用户可直接使用dataptr[len]进行赋值两字节内容
        dataptr[len] = dataptr[len - 1] ^ len;                      //校验字节仅取最后一个字节和长度进行异或运算，首字节相同port是一样的，可能有影响。和校验比较浪费时间，所以不采用
        pMsg[1] = len;                                              //真实数据长度占一字节，不加密，用来接收做第一步校验
        pMsg[0] = lwns_msg_encrypt(dataptr, pMsg + 2, len + 1) + 1; //获取数据加密后的长度，也就是需要发送出去的字节数，真实数据长度不加密
  #else
        pMsg[0] = len;
        tmos_memcpy(pMsg + 1, dataptr, len);
  #endif
        if(csma_phy_manage_list_head != NULL)
        {
            p->next = &csma_phy_manage_list[i]; //链表添加尾结点
        }
        else
        {
            csma_phy_manage_list_head = &csma_phy_manage_list[i]; //链表为空，则节点作为头结点
        }
        csma_phy_manage_list[i].data = pMsg; //绑定消息
        csma_phy_manage_list[i].next = NULL;
        return TRUE;
    }
    else
    {
        PRINTF("send failed!\n"); //无法申请到内存，则无法发送
    }
    return FALSE;
}

/*********************************************************************
 * @fn      lwns_adapter_ProcessEvent
 *
 * @brief   lwns adapter Task event processor.  This function
 *          is called to process all events for the task.  Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id - The TMOS assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  events not processed.
 */
static uint16_t lwns_adapter_ProcessEvent(uint8_t task_id, uint16_t events)
{
    if(events & LWNS_PHY_RX_OPEN_EVT)
    {
        RF_Shut();
        RF_Rx(NULL, 0, USER_RF_RX_TX_TYPE, USER_RF_RX_TX_TYPE); //重新打开接收
        return (events ^ LWNS_PHY_RX_OPEN_EVT);
    }
    if(events & SYS_EVENT_MSG)
    {
        uint8_t *pMsg;
        if((pMsg = tmos_msg_receive(lwns_adapter_taskid)) != NULL)
        {
            // Release the TMOS message,tmos_msg_allocate
            lwns_input(pMsg + 1, pMsg[0]); //将数据存入协议栈缓冲区
            tmos_msg_deallocate(pMsg);     //先释放内存，在数据处理前释放，防止数据处理中需要发送数据，而内存不够。
            lwns_dataHandler();            //调用协议栈处理数据函数
        }
        // return unprocessed events
        return (events ^ SYS_EVENT_MSG);
    }
    // Discard unknown events
    return 0;
}

/*********************************************************************
 * @fn      lwns_phyoutput_ProcessEvent
 *
 * @brief   lwns phyoutput Task event processor.  This function
 *          is called to process all events for the task.  Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id - The TMOS assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  events not processed.
 */
static uint16_t lwns_phyoutput_ProcessEvent(uint8_t task_id, uint16_t events)
{
    if(events & LWNS_PHY_PERIOD_EVT)
    {
        lwns_htimer_update(); //htimer的更新需要和mac的phy管理放一起，保持一致。
        if((csma_phy_manage_list_head != NULL))
        { //有需要发送的包
            if((ble_phy_manage_state == BLE_PHY_MANAGE_STATE_FREE) || (ble_phy_manage_state == BLE_PHY_MANAGE_STATE_RECEIVED))
            { //当前不在发送过程中
                if(ble_phy_manage_state == BLE_PHY_MANAGE_STATE_RECEIVED)
                {                       //当前周期发送碰撞，延迟发送
                    ble_phy_wait_cnt++; //记录发送延迟次数
                }
                else
                {                         //BLE_PHY_MANAGE_STATE_FREE
                    ble_phy_send_cnt = 0; //清除计数
                    ble_phy_wait_cnt = 0; //清除计数
                }
                ble_phy_manage_state = BLE_PHY_MANAGE_STATE_WAIT_SEND; //设置为等待发送状态
                if(ble_phy_wait_cnt >= LWNS_MAC_SEND_DELAY_MAX_TIMES)
                { //发送被取消次数，延迟过多，不再随机等待，立刻开始发送
                    tmos_set_event(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_EVT);
                    PRINTF("too many delay\n");
                }
                else
                {
                    uint8_t rand_delay;
                    rand_delay = tmos_rand() % LWNS_MAC_SEND_DELAY_MAX_625US + BLE_PHY_ONE_PACKET_MAX_625US; //随机延迟，防止冲突，随机延迟等待周期里收到了数据包就下次再发送
                    tmos_start_task(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_EVT, rand_delay);
                    PRINTF("rand send:%d\n", rand_delay);
                }
            }
        }
        tmos_start_task(lwns_phyoutput_taskid, LWNS_PHY_PERIOD_EVT, MS1_TO_SYSTEM_TIME(LWNS_MAC_PERIOD_MS)); //每个周期毫秒检测一次有误数据要发送，并且更新htimer。
        return (events ^ LWNS_PHY_PERIOD_EVT);
    }
    if(events & LWNS_PHY_OUTPUT_EVT)
    { //发送任务，竞争发送成功
        if(ble_phy_manage_state == BLE_PHY_MANAGE_STATE_WAIT_SEND)
        {
            ble_phy_manage_state = BLE_PHY_MANAGE_STATE_SENDING;         //改为发送中状态，竞争包发送完毕，需要等待一下接收方做好准备工作
            tmos_clear_event(lwns_adapter_taskid, LWNS_PHY_RX_OPEN_EVT); //停止可能已经置位的、可能会打开接收的任务
        }
        RF_Shut();
        if(!RF_Tx((uint8_t *)(csma_phy_manage_list_head->data + 1),
              csma_phy_manage_list_head->data[0], USER_RF_RX_TX_TYPE,
              USER_RF_RX_TX_TYPE))
        {
            RF_Wait_Tx_End();
        }
        tmos_start_task(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_FINISH_EVT, MS1_TO_SYSTEM_TIME(LWNS_PHY_OUTPUT_TIMEOUT_MS)); //开始发送超时计数
        return (events ^ LWNS_PHY_OUTPUT_EVT);
    }
    if(events & LWNS_PHY_OUTPUT_FINISH_EVT)
    {                       //发送完成任务
        ble_phy_send_cnt++; //发送计数
        if(ble_phy_send_cnt < LWNS_MAC_TRANSMIT_TIMES)
        {                                                               //发送没结束
            tmos_set_event(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_EVT); //发送次数没结束，继续发送
        }
        else
        {                                                     //发送流程结束
            ble_phy_manage_state = BLE_PHY_MANAGE_STATE_FREE; //清除状态
            RF_Shut();
            RF_Rx(NULL, 0, USER_RF_RX_TX_TYPE, USER_RF_RX_TX_TYPE);      //重新打开接收
            tmos_msg_deallocate(csma_phy_manage_list_head->data);        //释放内存
            csma_phy_manage_list_head->data = NULL;                      //恢复默认参数
            csma_phy_manage_list_head = csma_phy_manage_list_head->next; //链表pop，去除掉首元素
        }
        return (events ^ LWNS_PHY_OUTPUT_FINISH_EVT);
    }
    if(events & SYS_EVENT_MSG)
    {
        uint8_t *pMsg;
        if((pMsg = tmos_msg_receive(lwns_phyoutput_taskid)) != NULL)
        {
            // Release the TMOS message,tmos_msg_allocate
            tmos_msg_deallocate(pMsg); //释放内存
        }
        // return unprocessed events
        return (events ^ SYS_EVENT_MSG);
    }
    return 0;
}

/*********************************************************************
 * @fn      lwns_shut
 *
 * @brief   停止lwns，不可以在这lwns_phyoutput_taskid和lwns_adapter_taskid的processEvent中调用。
 *
 * @param   None.
 *
 * @return  None.
 */
void lwns_shut()
{
    uint8_t *pMsg;
    RF_Shut(); //关闭RF接收
    while(csma_phy_manage_list_head != NULL)
    {
        /* 清除所有缓存中待发送的消息 */
        tmos_msg_deallocate(csma_phy_manage_list_head->data);
        csma_phy_manage_list_head->data = NULL;
        csma_phy_manage_list_head = csma_phy_manage_list_head->next;
    }
    tmos_stop_task(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_EVT);
    tmos_clear_event(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_EVT);

    /* 超时重发全部清除 */
    lwns_htimer_flush_all();
    tmos_stop_task(lwns_phyoutput_taskid, LWNS_PHY_PERIOD_EVT); //停止Htimer心跳时钟和发送列表检测
    tmos_clear_event(lwns_phyoutput_taskid, LWNS_PHY_PERIOD_EVT);

    tmos_stop_task(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_FINISH_EVT);
    tmos_clear_event(lwns_phyoutput_taskid, LWNS_PHY_OUTPUT_FINISH_EVT);

    while((pMsg = tmos_msg_receive(lwns_adapter_taskid)) != NULL)
    {
        /* 清除所有缓存的消息 */
        tmos_msg_deallocate(pMsg);
    }
    tmos_stop_task(lwns_adapter_taskid, LWNS_PHY_RX_OPEN_EVT);
    tmos_clear_event(lwns_adapter_taskid, LWNS_PHY_RX_OPEN_EVT);
    tmos_clear_event(lwns_adapter_taskid, SYS_EVENT_MSG);
}

/*********************************************************************
 * @fn      lwns_start
 *
 * @brief   lwns开始运行，在使用lwns_shut后，重新开始时使用。
 *
 * @param   None.
 *
 * @return  None.
 */
void lwns_start()
{
    RF_Shut();
    RF_Rx(NULL, 0, USER_RF_RX_TX_TYPE, USER_RF_RX_TX_TYPE); //打开RF接收，如果需要低功耗管理，在其他地方打开。
    tmos_start_task(lwns_phyoutput_taskid, LWNS_PHY_PERIOD_EVT, MS1_TO_SYSTEM_TIME(LWNS_MAC_PERIOD_MS));
}

#endif /* LWNS_USE_CSMA_MAC */
