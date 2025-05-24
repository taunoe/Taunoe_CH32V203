/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : Tauno Erik
 * Version            : V1.0.0
 * Date               : 2025-05-21
 * Description        : GPIO pins

 *******************************************************************************/

#include "debug.h"
#include <stdio.h>
#include <inttypes.h> // For PRIu32

/* Global define */
#define DELAY_VAL 250

/* Global Variable */

/*********************************************************************
 * @fn      GPIO_Toggle_INIT
 *
 * @brief   Initializes GPIOA.0
 *
 * @return  none
 */
void init_PA0(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // GPIOA

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void init_PA1(void)
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void init_PA4(void)
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void init_PA5(void)
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void init_PA6(void)
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void init_PA7(void)
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void init_PB1(void) // On board LED
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void init_PA11(void)
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void init_PA12(void)
{
    // 1. Define the GPIO Initialization Structure
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 2. Enable the APB2 Clock for GPIOA
    // GPIOA is connected to the APB2 bus.
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3. Configure Pin PA1
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;         // Select Pin 1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // Set as Output Push-Pull
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // Set the output speed

    // 4. Apply the configuration to GPIOA
    GPIO_Init(GPIOA, &GPIO_InitStructure);
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
    uint32_t  i = 0;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("GPIO Toggle TEST\r\n");
    init_PA0();
    init_PA1();
    init_PA4();
    init_PA5();
    init_PA6();
    init_PA7();
    init_PB1();
    init_PA11();
    init_PA12();

    while(1)
    {
        //GPIO_WriteBit(GPIOA, GPIO_Pin_0, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
        i++;

        // PA0
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);   // Set PA0 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET); // Set PA0 Low
        Delay_Ms(DELAY_VAL);

        // PA1
        GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);   // Set PA1 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET); // Set PA1 Low
        Delay_Ms(DELAY_VAL);

        //PA4
        GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);   // Set PA4 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET); // Set PA4 Low
        Delay_Ms(DELAY_VAL);

        //PA5
        GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);   // Set PA5 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET); // Set PA5 Low
        Delay_Ms(DELAY_VAL);

        //PA6
        GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_SET);   // Set PA6 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_RESET); // Set PA6 Low
        Delay_Ms(DELAY_VAL);

        //PA7
        GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_SET);   // Set PA7 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_RESET); // Set PA7 Low
        Delay_Ms(DELAY_VAL);

        // PB1
        GPIO_WriteBit(GPIOB, GPIO_Pin_1, Bit_SET);   // Set PB1 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOB, GPIO_Pin_1, Bit_RESET); // Set PB1 Low
        Delay_Ms(DELAY_VAL);

        // PA11
        GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_SET);   // Set PA11 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_RESET); // Set PA11 Low
        Delay_Ms(DELAY_VAL);

        // PA12
        GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);   // Set PA12 High
        Delay_Ms(DELAY_VAL);
        GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_RESET); // Set PA12 Low
        Delay_Ms(DELAY_VAL);

        printf("i = %" PRIu32 "\r\n", i);
    }
}
