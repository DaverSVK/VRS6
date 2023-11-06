/*
 * HTS221.h
 *
 *  Created on: 6 Nov 2023
 *      Author: david
 */

#include "main.h"

#ifndef HTS221_H_
#define HTS221_H_


#define 	HTS221_DEVICE_ADDRESS_0		0xBE
#define 	HTS221_DEVICE_ADDRESS_1		0xBF

#define 	HTS221_WHO_AM_I_VALUE		0xBC
#define 	HTS221_WHO_AM_I				0x0F
#define 	HTS221_HUMIDITY_OUT_L 		0x28
#define 	HTS221_HUMIDITY_OUT_H 		0x29

#define 	HTS221_TEMP_OUT_L			0x2A
#define 	HTS221_TEMP_OUT_H			0x2B

#define 	HTS221_H0_rH_x2		0x30
#define		HTS221_H1_rH_x2		0x31
#define 	HTS221_T0_degC_x8	0x32
#define		HTS221_T1_degC_x8	0x33
#define 	HTS221_T1_T0_MSB	0x34
#define 	HTS221_H0_T0_OUT_L	0x36
#define		HTS221_H0_T0_OUT_H	0x37
#define 	HTS221_H1_T0_OUT_L	0x3A
#define		HTS221_H1_T0_OUT_H	0x3B
#define 	HTS221_T0_OUT_L		0x3C
#define		HTS221_T0_OUT_H		0x3D
#define 	HTS221_T1_OUT_L		0x3E
#define		HTS221_T1_OUT_H		0x3F


uint8_t HTS221_Who_Am_I(uint8_t reg_addr);

#endif /* HTS221_H_ */