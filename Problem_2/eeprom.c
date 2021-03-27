/*
 * eeprom.c
 *
 *  Created on: 29 Ara 2020
 *      Author: mehme
 */

#include "eeprom.h"

void read_eeprom(uint16_t regAddr, uint8_t *data, uint32_t num){
	uint8_t devAddr = 0x00;
	uint8_t arr[2];
	arr[0] = 0;
	arr[1] = 0;
	write_i2c(devAddr, arr, 1);
	read_i2c(devAddr, data, num);
}

void write_eeprom(uint16_t regAddr, uint8_t *data, uint32_t num){
	uint8_t devAddr = 0x00;
	uint8_t arr[2];
	arr[0] = 0;
	arr[1] = 0;
	write_i2c(devAddr, arr, 1);
	write_i2c(devAddr, data, num);
}
