/*
 * mpu6050.h
 *
 *  Created on: 29 Ara 2020
 *      Author: mehme
 */

#ifndef MPU6050_H_
#define MPU6050_H_

#include "main.h"

void read_mpu(uint8_t regAddr, uint8_t *data, uint32_t num);
void write_mpu(uint8_t regAddr, uint8_t *data, uint32_t num);


#endif /* MPU6050_H_ */


