/*
 * m24m02_eeprom.c
 *
 *  Created on: Sep 19, 2024
 *      Author: alex
 */

#include "../m24m02_eeprom/m24m02_eeprom.h"  // Include the header file

#include "../m24m02_eeprom/m24m02_eeprom_config.h"  // Include the config header

uint8_t WrBuffer[3] = {12, 13, 14};  // Write data buffer
uint8_t RdBuffer[3] = {0, 0, 0};    // Read data buffer
volatile uint16_t I2CMemAddress = 0; // Memory address to write/read

/**
 * @brief Write data to the EEPROM
 *
 * This function writes data from the WrBuffer to the EEPROM at the specified I2C address.
 */
void Write_EEPROM(void)
{
    I2CMemAddress = 0;  // Set memory address to start at 0

    // Enable write to EEPROM by pulling write enable pin low
    HAL_GPIO_WritePin(EEPROM_WR_EN_PORT, EEPROM_WR_EN, GPIO_PIN_RESET);

    // Write data to EEPROM
    // Parameters: I2C handle, DevAddress, MemAddress, MemAddSize, data buffer pointer, Size, Timeout
    HAL_I2C_Mem_Write(&M24M02_I2C_PORT, I2C_DEV_SELECT_ADDR_WR, I2CMemAddress, EEPROM_MEM_ADDRESS_SIZE, WrBuffer, sizeof(WrBuffer), EEPROM_I2C_TIMEOUT);

    // Disable writing to EEPROM by setting the write enable pin high
    HAL_GPIO_WritePin(EEPROM_WR_EN_PORT, EEPROM_WR_EN, GPIO_PIN_SET);
}

/**
 * @brief Read data from the EEPROM
 *
 * This function reads data from the EEPROM into the RdBuffer at the specified I2C address.
 */
void Read_EEPROM(void)
{
    I2CMemAddress = 0;  // Set memory address to start at 0

    // Read data from EEPROM
    // Parameters: I2C handle, DevAddress, MemAddress, MemAddSize, data buffer pointer, Size, Timeout
    HAL_I2C_Mem_Read(&M24M02_I2C_PORT, I2C_DEV_SELECT_ADDR_RD, I2CMemAddress, EEPROM_MEM_ADDRESS_SIZE, RdBuffer, sizeof(RdBuffer), EEPROM_I2C_TIMEOUT);

    // A small delay to ensure completion (if needed)
    HAL_Delay(5);

}
