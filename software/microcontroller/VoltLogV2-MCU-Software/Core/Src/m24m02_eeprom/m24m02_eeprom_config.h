/*
 * m24m02_eeprom_config.h
 *
 *  Created on: Sep 19, 2024
 *      Author: alex
 */

#ifndef M24M02_EEPROM_CONFIG_H_
#define M24M02_EEPROM_CONFIG_H_

#include "stm32f1xx_hal.h"
// I2C device addresses for reading and writing
#define I2C_DEV_SELECT_ADDR_WR 0xA0  // Write address: 10100000
#define I2C_DEV_SELECT_ADDR_RD 0xA1  // Read address: 10100001

// I2C memory address size in bytes
#define EEPROM_MEM_ADDRESS_SIZE 2

// I2C timeout in ms
#define EEPROM_I2C_TIMEOUT 100

// Pin definitions for Write Enable
#define EEPROM_WR_EN GPIO_PIN_2  // Adjust pin as needed
#define EEPROM_WR_EN_PORT GPIOA  // Adjust port as needed



/* Define the I2C port */
#define M24M02_I2C_PORT hi2c2

// External handle for I2C
extern I2C_HandleTypeDef M24M02_I2C_PORT;  // Ensure this is declared elsewhere in your project

// Buffers
extern uint8_t WrBuffer[3];
extern uint8_t RdBuffer[3];

#endif /* M24M02_EEPROM_CONFIG_H_ */
