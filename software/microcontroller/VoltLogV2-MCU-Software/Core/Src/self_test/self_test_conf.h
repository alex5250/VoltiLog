#ifndef SELF_TEST_I2C_CONFIG_H
#define SELF_TEST_I2C_CONFIG_H

#include "stm32f1xx_hal.h"

/* Define the I2C and UART ports */
#define I2C_PORT hi2c2
#define UART_PORT huart1

/* Declare external references to the I2C and UART handles */
extern I2C_HandleTypeDef hi2c2;
extern UART_HandleTypeDef huart1;

#endif /* SELF_TEST_I2C_CONFIG_H */
