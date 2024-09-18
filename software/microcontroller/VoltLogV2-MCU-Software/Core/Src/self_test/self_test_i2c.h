#ifndef SELF_TEST_I2C_H
#define SELF_TEST_I2C_H

#include "stm32f1xx_hal.h"

/* Function prototypes */
void uart_send_message(char *msg);
void scan_I2C_bus(void);

#endif /* SELF_TEST_I2C_H */
