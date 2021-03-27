/*
 * mpu6050.c
 *
 *  Created on: 29 Ara 2020
 *      Author: mehme
 */

#include "mpu6050.h"

void read_mpu(uint8_t regAddr, uint8_t *data, uint32_t num){
	uint8_t devAddr = 0x00;
	write_i2c(devAddr, &regAddr, 1);
	read_i2c(devAddr, data, num);

}
void write_mpu(uint8_t regAddr, uint8_t *data, uint32_t num){
	uint8_t devAddr = 0x00;
	write_i2c(devAddr, &regAddr, 1);
	write_i2c(devAddr, data, num);
}
