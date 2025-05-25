/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : Tauno Erik
 * Date               : 2025-05-25
 * Description        : VTF IRQ interrupt routine
 *********************************************************************************/


#include "debug.h"

/* Global define */


/* Global Variable */ 
uint32_t loendur = 0;

void SysTick_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      Interrupt_VTF_Init
 *
 * @brief   Initializes VTF.
 *
 * @return  none
 */
void Interrupt_VTF_Init(void)
{
    NVIC_EnableIRQ(SysTicK_IRQn);
    SetVTFIRQ((u32)SysTick_Handler, SysTicK_IRQn, 0, ENABLE);
}

/*********************************************************************
 * @fn      Systick_Init
 *
 * @brief   Initializes Systick.
 *
 * @return  none
 */
void Systick_Init(void)
{
    SysTick->SR=0;     // Clears SysTick Status Register 
    SysTick->CNT=0;    // Sets counter to 0
    SysTick->CMP=0xFFFFFF; //0x20; // Sets the Compare Register to 0x20 == 32. Timer counts town from 0x20 to 0
    SysTick->CTLR=0xf; //0x7; // Sets the Control Register (CTLR) to 0x7 (binary 0b111)
    // if 0x7 it runs only once
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
    USART_Printf_Init(115200);
	printf("SystemClk:%d\r\n",SystemCoreClock);
	printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
	printf("Interrupt VTF Test\r\n");

	Interrupt_VTF_Init();
	Systick_Init();
    while(1)
    {
        
    }
}

/*********************************************************************
 * @fn      SysTick_Handler
 *
 * @brief   This function handles SysTick exception.
 *
 * @return  none
 */
void SysTick_Handler(void)
{
    //time=SysTick->CNT;
    //SysTick->CTLR=0; // disables the SysTick timer by clearing its Control Register
    SysTick->SR = 0;  // Clear SysTick staus register
    //printf("delta time:%d\r\n", time-0x20);
    loendur++;
    printf("%u\r\n", loendur);
}
