/*
 * LPS25HB.h
 *
 *  Created on: 6 Nov 2023
 *      Author: david
 */
#include "main.h"

#ifndef LPS25HB_H_
#define LPS25HB_H_

#define 	LPS25HB_DEVICE_ADDRESS_1		0xBA

#define 	LPS25HB_WHO_AM_I_VALUE			0xBD
#define 	LPS25HB_WHO_AM_I_ADDRESS		0x0F

#define 	LPS25HB_ADDRESS_CTRL1			0x20

#define 	LPS25HB_ADDRESS_PRESS_OUT_XL	0x28
#define 	LPS25HB_ADDRESS_PRESS_OUT_L		0x29
#define 	LPS25HB_ADDRESS_PRESS_OUT_H		0x2A

#define		LPS25HB_ADDRESS_RPDS_L			0x39
#define		LPS25HB_ADDRESS_RPDS_H			0x3A

uint8_t LPS25HB_Who_Am_I(uint8_t reg_addr);

#endif /* LPS25HB_H_ */
