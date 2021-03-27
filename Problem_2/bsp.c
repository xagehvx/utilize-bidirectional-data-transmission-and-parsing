/*
 * bsp.c
 *
 *  Created on: 22 Ara 2020
 *      Author: Mehmet Akif/171024027
 */
#include "bsp.h"

void BSP_init(){
	__disable_irq();
	init_I2C();
	//SystemCoreClockUpdate();	//contains the system frequency
	init_timer1();

	__enable_irq();
}

void init_timer1(){

	RCC->APBENR2 |= (1U<< 11);// enable time1 module clock

	TIM1->CR1=0;// zero out the control register just in case
	TIM1->CR1 |= (1<<7);	// ARPE
	TIM1->CNT=0;// zero out counter

	/*0.1 ms interrupt	 */

	TIM1->PSC=99;
	TIM1->ARR=16;

	TIM1->DIER |= (1 << 0);// update interrupt enable
	TIM1->CR1 |= (1 << 0);// 	tım1 enable

	NVIC_SetPriority(TIM1_BRK_UP_TRG_COM_IRQn,3);
	NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);

}

void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
	TIM1->SR &= ~(1U<<0); //clear update status register

}

void delay_ms(volatile unsigned int s){

	for(int i=s; i>0; i--){
	 SysTick_Config(SystemCoreClock / 1000); // 16 MHz / 1000 ile 1 ms elde edildi.
	 }
}

