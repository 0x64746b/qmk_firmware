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
    {  52, 46 }, {  69, 48 }, {  85, 53 }, {  98, 64 }, {  79, 18 }, {  79,  6 },
    {  79,  9 }, {  63,  6 }, {  63, 18 }, {  63, 30 }, {  47, 24 }, {  47, 12 },
    {  47,  0 }, {  32,  3 }, {  32, 15 }, {  32, 27 }, {  16, 37 }, {  16, 25 },
    {  16, 13 }, {   0, 19 }, {   0, 31 },
    // left-ug [LED_22-27]
    {  22, 33 }, {  24, 11 }, {  56,  8 }, {  95, 19 }, {  96, 46 }, {  58, 43 },
    // right-bg [LED_28-48]
    { 172, 46 }, { 155, 48 }, { 139, 53 }, { 126, 64 }, { 145, 18 }, { 145,  6 },
    { 145,  9 }, { 161,  6 }, { 161, 18 }, { 161, 30 }, { 177, 24 }, { 177, 12 },
    { 177,  0 }, { 192,  3 }, { 192, 15 }, { 192, 27 }, { 208, 37 }, { 208, 25 },
    { 208, 13 }, { 224, 19 }, { 224, 31 },
    // right-ug [LED_49-54]
    { 202, 33 }, { 200, 11 }, { 168,  8 }, { 129, 19 }, { 128, 46 }, { 166, 43 }
}, {
    // left-bg [LED_01-21]
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
