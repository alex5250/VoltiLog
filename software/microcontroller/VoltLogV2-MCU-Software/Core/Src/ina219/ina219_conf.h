/*
 * ina219_conf.h
 *
 *  Created on: Sep 17, 2024
 *      Author: alex
 */



#ifndef INA219_CONFIG_H
#define INA219_CONFIG_H

#include "stm32f1xx_hal.h"

/* INA219 I2C address (default is 0x40 but may vary) */
#define INA219_ADDRESS        0x40  // Replace with the actual address if different

/* Define the I2C port */
#define INA219_I2C_PORT       hi2c2

/* Declare external references to the I2C handle */
extern I2C_HandleTypeDef INA219_I2C_PORT;

/* Calibration values for INA219 */


#endif /* INA219_CONFIG_H */



