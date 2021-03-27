/*
 * I2C.h
 *
 *  Created on: 27 Ara 2020
 *      Author: mehme
 */

#ifndef I2C_H_
#define I2C_H_

#include "main.h"


#define MPU6050_ADDRESS			0x68

#define MPU6050_WHO_AM_I		0x75
#define MPU6050_PWR_MGMT_1		0x6B

#define MPU6050_ACCEL_XOUT_H	0x3B
#define MPU6050_ACCEL_XOUT_L	0x3C
#define MPU6050_ACCEL_YOUT_H	0x3D
#define MPU6050_ACCEL_YOUT_L	0x3E

#define MPU6050_GYRO_XOUT_H		0x43
#define MPU6050_GYRO_XOUT_L		0x44

void init_I2C();
void read_i2c(uint8_t devAddr, uint8_t *data, uint32_t num);
void write_i2c(uint8_t devAddr, uint8_t *data, uint32_t num);


typedef struct {
	uint8_t ax;
	uint8_t ay;
	uint8_t az;
	uint8_t gx;
	uint8_t gy;
	uint8_t gz;
}values;


#endif /* I2C_H_ */
