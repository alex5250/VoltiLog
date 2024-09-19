/*
 * button_api.c
 *
 *  Created on: Sep 17, 2024
 *      Author: alex
 */

#include "main.h"
#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

// Button event enum
typedef enum {
    NO_PRESS, /**< No button press detected */
    SINGLE_PRESS, /**< Single button press detected */
    LONG_PRESS, /**< Long button press detected */
    DOUBLE_PRESS /**< Double button press detected */
} eButtonEvent;

// Constants for button timing
static const uint32_t DEBOUNCE_MILLIS = 20;
static const uint32_t DOUBLE_GAP_MILLIS_MAX = 250;
static const uint32_t LONG_MILLIS_MIN = 800;

// Function to handle debouncing for a given button pin
static bool buttonStateDebounced(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    static uint32_t last_debounce_ts = 0;
    bool stable_state = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET;
    uint32_t now = HAL_GetTick();

    // Debounce handling
    if (now - last_debounce_ts > DEBOUNCE_MILLIS) {
        stable_state = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET;
        last_debounce_ts = now;
    }
    return stable_state;
}

// Generalized function to detect button press events for any button
static eButtonEvent getButtonEvent(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    static uint32_t button_down_ts = 0;
    static uint32_t button_up_ts = 0;
    static bool double_pending = false;
    static bool long_press_pending = false;
    static bool button_down = false;

    eButtonEvent button_event = NO_PRESS;
    uint32_t now = HAL_GetTick();

    // Check for state change (debounced)
    bool current_state = buttonStateDebounced(GPIOx, GPIO_Pin);
    if (button_down != current_state) {
        button_down = current_state;
        if (button_down) {
            // Button pressed down
            button_down_ts = now;
        } else {
            // Button released
            button_up_ts = now;

            // Handle double press
            if (double_pending) {
                button_event = DOUBLE_PRESS;
                double_pending = false;
            } else {
                double_pending = true;
            }

            // Cancel any long press pending
            long_press_pending = false;
        }
    }

    // Handle single press if double press gap time expired
    if (!button_down && double_pending && (now - button_up_ts > DOUBLE_GAP_MILLIS_MAX)) {
        double_pending = false;
        button_event = SINGLE_PRESS;
    }
    // Handle long press detection


    return button_event;
}

// Wrapper function for detecting left button events
eButtonEvent getLeftButtonEvent()
{
    return getButtonEvent(GPIOA, GPIO_PIN_6); // Assuming GPIOB and pin 7 for the left button
}

// Wrapper function for detecting right button events
eButtonEvent getRightButtonEvent()
{
    return getButtonEvent(GPIOA, GPIO_PIN_7); // Assuming GPIOB and pin 6 for the right button
}
