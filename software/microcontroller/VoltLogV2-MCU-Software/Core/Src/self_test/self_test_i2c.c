/*
 * self_test_i2c.c
 *
 *  Created on: Sep 17, 2024
 *      Author: alex
 */
#include "self_test_i2c.h"
#include "main.h"
#include "self_test_conf.h"
#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

void uart_send_message(char* msg)
{
    HAL_UART_Transmit(&UART_PORT, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
}

/* Function to scan I2C bus and output results over UART */
void scan_I2C_bus(void)
{
    uart_send_message("\r\nScanning I2C bus:\r\n");

    HAL_StatusTypeDef result;
    uint8_t i;
    char buffer[20];

    for (i = 1; i < 128; i++) {

        result = HAL_I2C_IsDeviceReady(&I2C_PORT, (uint16_t)(i << 1), 2, 2);

        if (result == HAL_OK) {
            sprintf(buffer, "0x%X", i); // Format the address
            uart_send_message(buffer); // Send address over UART
        } else {
            uart_send_message("."); // No device found at this address
        }
    }
    uart_send_message("\r\n");
}
