/*
 * button_api.h
 *
 *  Created on: Sep 17, 2024
 *      Author: alex
 */

#ifndef BUTTON_API_H_
#define BUTTON_API_H_

#include "main.h"
#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Enum representing different button events.
 */
typedef enum {
    NO_PRESS, /**< No button press detected */
    SINGLE_PRESS, /**< Single button press detected */
    LONG_PRESS, /**< Long button press detected */
    DOUBLE_PRESS /**< Double button press detected */
} eButtonEvent;

/**
 * @brief  Reads the current state of the right button with debounce handling.
 * @note   Debouncing is implemented with a delay of 20 milliseconds.
 * @retval The current state of the right button: true if pressed, false otherwise.
 */
bool buttonRightState(void);

/**
 * @brief  Reads the current state of the left button with debounce handling.
 * @note   Debouncing is implemented with a delay of 20 milliseconds.
 * @retval The current state of the left button: true if pressed, false otherwise.
 */
bool buttonLeftState(void);

/**
 * @brief  Detects the type of press event (single, double, or long) for the left button.
 * @note   The following timing thresholds are used:
 *          - Double press: 250ms gap maximum.
 *          - Long press: 800ms press minimum.
 * @retval eButtonEvent type representing the event for the left button.
 */
eButtonEvent getLeftButtonEvent(void);

/**
 * @brief  Detects the type of press event (single, double, or long) for the right button.
 * @note   The following timing thresholds are used:
 *          - Double press: 250ms gap maximum.
 *          - Long press: 800ms press minimum.
 * @retval eButtonEvent type representing the event for the right button.
 */
eButtonEvent getRightButtonEvent(void);

#endif /* BUTTON_API_H_ */
