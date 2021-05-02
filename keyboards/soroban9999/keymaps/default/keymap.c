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
    _Fn1,
    _Fn2,
    _Fn3,
    _Fn4
};

#define _ROTALY_L 3
#define _ROTALY_R 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC__VOLDOWN,KC_BRMD,LCMD(KC_Z)   ,LCMD(KC_MINS),
        KC__VOLUP  ,KC_BRMU,LCMD(S(KC_Z)),LCMD(KC_PLUS),
        KC_MUTE, XXXXXXX, XXXXXXX, LCMD(KC_0),
        KC_P7  , KC_P8  , KC_P9  , LT(_Fn4, KC_PSLS),
        KC_P4  , KC_P5  , KC_P6  , LT(_Fn3, KC_PAST),
        KC_P1  , KC_P2  , KC_P3  , LT(_Fn2, KC_PMNS),
        KC_PEQL, KC_P0  , KC_PDOT, LT(_Fn1, KC_PPLS)
    ),
    [_Fn1] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        KC_ESC , _______, _______, XXXXXXX,
        KC_DEL , KC_BSPC, _______, XXXXXXX,
        KC_TAB , _______, KC_COLN, XXXXXXX,
        KC_PENT, KC_SPC,  KC_COMM, XXXXXXX
    ),
    [_Fn2] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, KC_LABK, KC_RABK, XXXXXXX,
        _______, KC_LCBR, KC_RCBR, XXXXXXX,
        _______, KC_LBRC, KC_RBRC, XXXXXXX,
        _______, KC_LPRN, KC_RPRN, XXXXXXX
    ),
    [_Fn3] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        KC_HOME, KC_UP  , KC_PGUP, XXXXXXX,
        KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
        KC_END , KC_DOWN, KC_PGDN, XXXXXXX,
        _______, KC_INS , _______, XXXXXXX
    ),
    [_Fn4] = LAYOUT(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_RMOD, XXXXXXX,
        KC_D   , KC_E   , KC_F   , XXXXXXX,
        KC_A   , KC_B   , KC_C   , XXXXXXX,
        _______, _______, _______, XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  int duration = clockwise ? _ROTALY_R : _ROTALY_L;

#ifdef VIA_ENABLE
  uint16_t keycode = dynamic_keymap_get_keycode(get_highest_layer(layer_state),duration,index);
#else
  uint16_t keycode = pgm_read_word(&keymaps[get_highest_layer(layer_state)][duration][index]);
#endif

#ifdef CONSOLE_ENABLE
  uprintf("EN: index: %u, clockwise: %u, layer: %u, key: %lu\n",
          index, clockwise, get_highest_layer(layer_state), keycode);
#endif

  tap_code16(keycode);
}
