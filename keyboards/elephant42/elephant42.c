/* Copyright 2020 illness072
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "elephant42.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

/*

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

*/

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
{   // keymap to LED number
    // left
    { 19,  18,  13,  12,  7,   6   }, // R3
    { 20,  17,  14,  11,  8,   5   }, // R2
    { NO_LED, 16, 15, 10, 9,   4   }, // R1
    { NO_LED, NO_LED, 0, 1, 2, 3   }, // R0
    // right
    { 47,  46,  41,  40,  35,  34  }, // R3
    { 48,  45,  42,  30,  36,  33  }, // R2
    { NO_LED, 44, 43, 38, 37,  32  }, // R1
    { NO_LED, NO_LED, 28, 29, 30, 31 }, // R0
}, { // phisical LED position, {x, y} : x = 0..224, y = 0..64
    // left-bg [LED_01-21]
    { 56, 65}, { 77, 68}, { 95, 79}, {109, 91}, 
    { 87, 46}, { 87, 29}, { 87, 12}, { 69, 43}, { 69, 26}, { 69,  8}, 
    { 52, 35}, { 52, 17}, { 52,  0}, { 35,  4}, { 35, 21}, { 35, 38}, 
    { 17, 54}, { 17, 36}, { 17, 19}, {  0, 26}, {  0, 43}, 
    // left-ug [LED_22-27]
    { 25, 49}, { 26, 19}, { 60, 14}, {106, 33}, {107, 72}, { 70, 66}, 
    // right-bg [LED_28-48]
    {199, 65}, {179, 68}, {160, 79}, {146, 91}, 
    {168, 46}, {168, 29}, {168, 12}, {186, 43}, {186, 26}, {186,  8}, 
    {203, 35}, {203, 17}, {203,  0}, {220,  4}, {220, 21}, {220, 38}, 
    {238, 54}, {238, 36}, {238, 19}, {255, 26}, {255, 43}, 
    // right-ug [LED_49-54]
    {230, 49}, {230, 19}, {195, 14}, {149, 33}, {148, 72}, {185, 66}, 
}, {
    // Left-bg [LED_01-21]
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    // left-ug [LED_22-27]
    LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
    // right-bg [LED_28-48]
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    // right-ug [LED_49-54]
    LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW
} };
#endif
