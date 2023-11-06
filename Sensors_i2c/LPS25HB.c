/*
 * LPS25HB.c
 *
 *  Created on: 6 Nov 2023
 *      Author: david
 */

#include "LPS25HB.h"

uint8_t LPS25HB_address = LPS25HB_DEVICE_ADDRESS_0;
uint16_t LPS25HB_PressureOffset;

void LPS25HB_read_bytes(uint8_t reg_addr, uint8_t* values, size_t length) {
    i2c_master_read(values, length, reg_addr, LPS25HB_address, 1);
    // Added a delay or a check for 'end_of_read_flag' to ensure data has been read before proceeding

}

void LPS25HB_write_bytes(uint8_t reg_addr, uint8_t* values, size_t length) {
    i2c_master_write_multi(values, length, reg_addr, LPS25HB_address, 0);
}


void LPS25HB_init() {
    uint8_t whoAmI = 0;
    LPS25HB_read_bytes(LPS25HB_WHO_AM_I_ADDRESS, &whoAmI, 1);

    if (!(whoAmI == LPS25HB_WHO_AM_I_VALUE)) {
        LPS25HB_address = LPS25HB_DEVICE_ADDRESS_1;

        LPS25HB_read_bytes(LPS25HB_WHO_AM_I_ADDRESS, &whoAmI, 1);
        if (whoAmI == LPS25HB_WHO_AM_I_VALUE) {
           uint8_t start = 10;
        }
    }
}

