/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH, Tauno Erik
 * Version            : V1.0.0
 * Date               : 2023/12/29, 2025-05-05
 * Description        : Systick interrupt
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *Systick interrupt:
 *USART1_Tx(PA9). ????
 */

#include "debug.h"

/* Global typedef */

/* Global define */

/* Global Variable */
void SysTick_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

u32 counter = 0;

void SYSTICK_Init_Config(u64 ticks)
{
    SysTick->SR = 0;      // Clears the SysTick Status Register.
    SysTick->CNT = 0;     // Resets the SysTick counter to 0
    SysTick->CMP = ticks; // Sets the Compare Register (CMP) to the value passed in as ticks. When the SysTick->CNT (counter) reaches this CMP value, an interrupt will be generated.
    SysTick->CTLR =0xF;   // == 0b1111, Control Register

    NVIC_SetPriority(SysTicK_IRQn, 1);
    NVIC_EnableIRQ(SysTicK_IRQn);
}

void SysTick_Handler(void)
{
    SysTick->SR = 0;
    counter++;
    printf("Counter:%d\r\n",counter);
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    SystemCoreClockUpdate();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );

    SYSTICK_Init_Config(SystemCoreClock-1);  // 96000000 -1
    // Since SystemCoreClock is typically in Hz (cycles per second), 
    // this configuration will cause the SysTick interrupt to trigger approximately once every second.

    while(1)
    {
    }
}
