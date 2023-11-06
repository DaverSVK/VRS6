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

void HTS221_get_humidity(float* humidity_out) {
    uint8_t h_out_data[2];
    int16_t h_out;

    HTS221_read_bytes(HTS221_HUMIDITY_OUT_L, h_out_data, 2);
    h_out = h_out_data[0] | (h_out_data[1] << 8);

    *humidity_out = h_out;
}

void HTS221_get_temperature(float* temperature_out) {
    uint8_t t_out_buffer[2]; // Buffer to hold the two temperature bytes
    int16_t t_out;

    // Read both temperature registers at once
    HTS221_read_bytes(HTS221_HUMIDITY_OUT_L | 0x80, t_out_buffer, 2);

    // Combine the two bytes into a single 16-bit value
    t_out = (int16_t)((uint16_t)t_out_buffer[1] << 8 | t_out_buffer[0]);

    // Calculate the temperature in Celsius
    *temperature_out = t_out;
}

