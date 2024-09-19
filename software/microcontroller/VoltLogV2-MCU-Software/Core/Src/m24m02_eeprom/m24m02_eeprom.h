/*
 * m24m02_eeprom.h
 *
 *  Created on: Sep 19, 2024
 *      Author: alex
 */

#ifndef SRC_M24M02_EEPROM_M24M02_EEPROM_H_
#define SRC_M24M02_EEPROM_M24M02_EEPROM_H_
#include "stm32f1xx_hal.h"

#include "../m24m02_eeprom/m24m02_eeprom_config.h"  // Include config file

// Function prototypes
void Write_EEPROM(void);
void Read_EEPROM(void);


#endif /* SRC_M24M02_EEPROM_M24M02_EEPROM_H_ */
