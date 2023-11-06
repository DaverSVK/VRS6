/*
 * HTS221.c
 *
 *  Created on: 6 Nov 2023
 *      Author: david
 */

#include "main.h"
#include "HTS221.h"

uint8_t HTS221_address = HTS221_DEVICE_ADDRESS_0;


uint8_t HTS221_Who_Am_I(uint8_t reg_addr) {
	uint8_t data = 0;
	return (i2c_master_read(&data, 1, reg_addr, HTS221_address, 0));
}
