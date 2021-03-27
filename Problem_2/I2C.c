/*
 * I2C.c
 *
 *  Created on: 27 Ara 2020
 *      Author: mehme
 */

#include "I2C.h"


void I2C1_IRQHandler(void){

}


void init_I2C(void){

	//Enable GPIOB
	RCC->IOPENR |= (1U << 1);

	//setup PB8 as AF6
	GPIOB->MODER &= ~(3U << 2*8);
	GPIOB->MODER |= (2 << 2*8);
	GPIOB->OTYPER |= (1U << 8);

	//choose AF from mux
	GPIOB->AFR[1] &=  ~(0xFU << 4*0);
	GPIOB->AFR[1] |=  (6 << 4*0);

	//setup PB9 as AF6
	GPIOB->MODER &= ~(3U << 2*9);
	GPIOB->MODER |= (2 << 2*9);
	GPIOB->OTYPER |= (1U << 9);

	//choose AF from mux
	GPIOB->AFR[1] &=  ~(0xFU << 4*1);
	GPIOB->AFR[1] |=  (6 << 4*1);

	//enable I2C1
	RCC->APBENR1 |= (1U << 21);

	I2C1->TIMINGR |= (3 << 28); //PRESC
	I2C1->TIMINGR |= (0x13 << 0); //SCLL
	I2C1->TIMINGR |= (0xF << 8); //SCLH
	I2C1->TIMINGR |= (0x2 << 16); //SDADEL
	I2C1->TIMINGR |= (0x4 << 20); //SCLDEL

	I2C1->CR1 = (1U << 0); //PE

	NVIC_SetPriority(I2C1_IRQn, 1);
	NVIC_EnableIRQ(I2C1_IRQn);
}




void write_i2c(uint8_t devAddr, uint8_t *data, uint32_t num){

	//Write operation (Send address and register to read)
	I2C1->CR2 = 0;
	I2C1->CR2 |= ((uint32_t)devAddr << 1); // slave address
	I2C1->CR2 |= (num << 16); // Number of byte
	I2C1->CR2 |= (1U << 25); // AUTOEND
	I2C1->CR2 |= (1U << 13); // Generate Start

	for (size_t i=0; i<num; ++i){
		while(!(I2C1->ISR & (1 << 1))); //TXIS
		I2C1->TXDR = data[i];
	}
}


void read_i2c(uint8_t devAddr, uint8_t *data, uint32_t num){

	I2C1->CR2 = 0;
	I2C1->CR2 |= ((uint32_t)devAddr << 1);
	I2C1->CR2 |= (1U << 10); //READ mode
	I2C1->CR2 |= (num << 16); //Number of bytes
	I2C1->CR2 |= (1U << 15); //NACK
	I2C1->CR2 |= (1U << 25); //AUTOEND
	I2C1->CR2 |= (1U << 13); //Generate Start

	for(size_t i=0; i<num; i++){
		while(!(I2C1->ISR & (1 << 2))); // wait until RXNE =1
		data[i] = (uint8_t)I2C1->RXDR;
		}
}

