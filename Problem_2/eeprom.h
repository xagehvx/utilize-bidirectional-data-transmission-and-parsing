/*
 * eeprom.h
 *
 *  Created on: 29 Ara 2020
 *      Author: mehme
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#include "main.h"

void read_eeprom(uint16_t regAddr, uint8_t *data, uint32_t num);
void write_eeprom(uint16_t regAddr, uint8_t *data, uint32_t num);

#endif /* EEPROM_H_ */

