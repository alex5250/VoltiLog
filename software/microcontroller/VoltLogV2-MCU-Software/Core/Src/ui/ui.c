/*
 * ui.c
 *
 *  Created on: Sep 17, 2024
 *      Author: alex
 */
#include "../ssd1306/ssd1306.h"
#include "../ssd1306/ssd1306_fonts.h"
#include <stdbool.h>
#include <stdio.h>
void draw_main_screen(int voltage, int current, int memory_percentage, bool is_recording)
{
    // ssd1306_Fill(Black);

    // Display Voltage
    ssd1306_SetCursor(5, 5);
    ssd1306_WriteString("Voltage:", Font_7x10, White);
    char voltage_str[10];
    sprintf(voltage_str, "%d mV", voltage); // Format voltage with 2 decimal points
    ssd1306_SetCursor(75, 5);
    ssd1306_WriteString(voltage_str, Font_7x10, White);

    // Display Current
    ssd1306_SetCursor(5, 25);
    ssd1306_WriteString("Current:", Font_7x10, White);
    char current_str[10];
    sprintf(current_str, "%d mA", current); // Format current with 3 decimal points
    ssd1306_SetCursor(75, 25);
    ssd1306_WriteString(current_str, Font_7x10, White);

    // Display Memory taken
    ssd1306_SetCursor(5, 45);
    ssd1306_WriteString("Memory taken:", Font_7x10, White);
    char memory_str[10];
    sprintf(memory_str, "%d%%", memory_percentage); // Format memory as percentage
    ssd1306_SetCursor(95, 45);
    ssd1306_WriteString(memory_str, Font_7x10, White);

    // Display Recording Status

    ssd1306_UpdateScreen();
}

void draw_settings_screen(int sample_rate, int sample_amount, int shunt_calibration)
{
    ssd1306_Fill(Black);

    // Display Sample rate
    ssd1306_SetCursor(5, 5);
    ssd1306_WriteString("Sample rate:", Font_7x10, White);
    char sample_rate_str[10];
    sprintf(sample_rate_str, "%ds", sample_rate);
    ssd1306_SetCursor(95, 5);
    ssd1306_WriteString(sample_rate_str, Font_11x18, White);

    // Display Sample amount
    ssd1306_SetCursor(5, 25);
    ssd1306_WriteString("Sample amount:", Font_7x10, White);
    char sample_amount_str[10];
    sprintf(sample_amount_str, "%d", sample_amount);
    ssd1306_SetCursor(95, 25);
    ssd1306_WriteString(sample_amount_str, Font_11x18, White);

    // Display Shunt calibration
    ssd1306_SetCursor(5, 45);
    ssd1306_WriteString("Shunt calibration:", Font_7x10, White);
    char shunt_calibration_str[10];
    sprintf(shunt_calibration_str, "%d", shunt_calibration);
    ssd1306_SetCursor(95, 45);
    ssd1306_WriteString(shunt_calibration_str, Font_11x18, White);

    // Display About
    ssd1306_SetCursor(5, 65);
    ssd1306_WriteString("About", Font_7x10, White);

    // Display USB Transmit Mode
    ssd1306_SetCursor(5, 85);
    ssd1306_WriteString("USB Transmit mode", Font_7x10, White);

    ssd1306_UpdateScreen();
}
