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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _ITEM
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ITEM = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                           KC_Q, KC_W, KC_E, KC_COMMA,
                   KC_ESC, KC_A, KC_S, KC_D, KC_F,
                MO(_ITEM),       KC_F2, KC_F3, KC_F5,
                                 KC_LSFT, KC_SPC , KC_LCTL
                     ),
    [_ITEM] = LAYOUT(
                           KC_1, KC_2, KC_3, KC_4,
                   KC_TAB, KC_5, KC_6, KC_7, KC_8,
                MO(_ITEM),       KC_9, KC_0, KC_F5,
                                 KC_LSFT, KC_SPC , KC_LCTL
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }
    return true;
}
