/*
 * LPS25HB.c
 *
 *  Created on: 6 Nov 2023
 *      Author: david
 */
#include "main.h"

#include "LPS25HB.h"

uint8_t LPS25HB_address = LPS25HB_DEVICE_ADDRESS_1;

uint8_t LPS25HB_Who_Am_I(uint8_t reg_addr) {
	uint8_t data = 0;
	return (i2c_master_read(&data, 1, reg_addr, LPS25HB_address, 0));

}
