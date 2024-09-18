/*
 * ui.h
 *
 *  Created on: Sep 17, 2024
 *      Author: alex
 */

#ifndef UI_H_
#define UI_H_
#include <stdbool.h>
// Function to draw the main screen on the display
void draw_main_screen(float voltage, float current, int memory_percentage, bool is_recording);
void draw_settings_screen(int sample_rate, int sample_amount, int shunt_calibration);

#endif /* UI_H_ */
