/*
 * HTS221.c
 *
 *  Created on: 6 Nov 2023
 *      Author: david
 */

#include "HTS221.h"

uint8_t HTS221_address = HTS221_DEVICE_ADDRESS_0;
//uint8_t HTS221_address = YOUR_DEFAULT_ADDRESS; // Replace with the actual default address

// Read multiple bytes
void HTS221_read_bytes(uint8_t reg_addr, uint8_t* values, size_t length) {
    i2c_master_read(values, length, reg_addr, HTS221_address, 1);
    // Added a delay or a check for 'end_of_read_flag' to ensure data has been read before proceeding
}

// Write multiple bytes
void HTS221_write_bytes(uint8_t reg_addr, uint8_t* values, size_t length) {
    i2c_master_write_multi(values, length, reg_addr, HTS221_address, 0);
}

void HTS221_init(void) {
    uint8_t whoAmI;

    HTS221_read_bytes(HTS221_WHO_AM_I_ADDRESS, &whoAmI, 1);

    if (!(whoAmI == HTS221_WHO_AM_I_VALUE)) {
    	HTS221_address = HTS221_DEVICE_ADDRESS_1;
    	HTS221_read_bytes(HTS221_WHO_AM_I_ADDRESS, &whoAmI, 1);
    }

}

