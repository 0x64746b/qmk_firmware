
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


#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
#define STEP 32
uint8_t kp = 0;
#endif

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    KC_LRST
};

#define KC_LOW LOWER
#define KC_RAI RAISE
#define KC_ KC_NO
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

#define KC_LSPC LT(_LOWER, KC_SPC)
#define KC_RSPC LT(_RAISE, KC_SPC)

#define KC_MDEL CMD_T(KC_DEL)
#define KC_CTAB CTL_T(KC_TAB)
#define KC_SENT SFT_T(KC_ENT)
#define KC_STAB SFT_T(KC_TAB)
#define KC_ABSP ALT_T(KC_BSPC)

#define KC_CDEL CTL_T(KC_DEL)

#define KC_VU KC__VOLUP
#define KC_VD KC__VOLDOWN
#define KC_MU KC__MUTE

#define KC_LTOG RGB_TOG
#define KC_LMOF RGB_MOD
#define KC_LMOP RGB_RMOD
#define KC_LHUI RGB_HUI
#define KC_LHUD RGB_HUD
#define KC_LVAI RGB_VAI
#define KC_LVAD RGB_VAD
#define KC_LSAI RGB_SAI
#define KC_LSAD RGB_SAD


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     TAB , Q  , W  , E  , R  , T  ,                          Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                          H  , J  , K  , L  ,SCLN,QUOT,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
           Z  , X  , C  , V  , B  ,                          N  , M  ,COMM,DOT ,SLSH,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         LALT,LCMD,LSPC,LSFT,     CDEL,RSPC,SENT,ABSP
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                          6  , 7  , 8  , 9  , 0  ,EQL ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     LCTL,EXLM,AT  ,HASH,DLR ,PERC,                         CIRC,AMPR,ASTR,TILD,PLUS,GRV ,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          PIPE,LABK,LCBR,LBRC,LPRN,                         RPRN,RBRC,RCBR,RABK,BSLS,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         LALT,LCMD,    ,LSFT,     CDEL,    ,SENT,ABSP
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                          F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
         ,LTOG,LMOF,LVAI,LHUI,LSAI,                         LEFT,DOWN, UP ,RGHT,    ,F12 ,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          LRST,LMOP,LVAD,LHUD,LSAD,                         HOME,PGDN,PGUP,END ,    ,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----+----'
                         LALT,LCMD,    ,LSFT,     CDEL,    ,SENT,ABSP
  //                    `----+----+----+----'    `----+----+----+----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_LRST:
    if (record->event.pressed) {
#ifdef RGB_MATRIX_ENABLE
      eeconfig_update_rgb_matrix_default();
      rgb_matrix_enable();
#endif
#ifdef RGBLIGHT_ENABLE
      eeconfig_update_rgblight_default();
      rgblight_enable();
#endif
    }
    break;
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
    } else {
      layer_off(_LOWER);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
    } else {
      layer_off(_RAISE);
    }
    return false;
    break;
  }
#ifdef OLED_DRIVER_ENABLE
  if (record->event.pressed) {
    kp = (kp + 1) % STEP;
  }
#endif
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
  if (is_keyboard_master()) {
    char disp[(21*4)+1] = {0};
    static char layer_names[_NUM_OF_LAYERS][10] = {"Default", "Lower", "Raise", "Adjust"};
    static char l1[] = "                \x94\x95\x96\x97";
    static char l2[] = "                \xB4\xB5\xB6\xB7";
    static char r1[] = "                \x98\x99\x9A\x9B";
    static char r2[] = "                \xB8\xB9\xBA\xBB";
    int space = kp % STEP;
    if (space > STEP / 2) space = STEP - space;
    if (kp < STEP / 2) {
      snprintf(disp, 84, "Layer: %s\n\n%s\n%s\n",
               layer_names[get_highest_layer(layer_state)], l1 + space, l2 + space);
    } else {
      snprintf(disp, 84, "Layer: %s\n\n%s\n%s\n",
               layer_names[get_highest_layer(layer_state)], r1 + space, r2 + space);
    }
    oled_write(disp, false);
  } else {
    static char *logo = "\n"
      "\x8f\x90\x91\x92\x93\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\n"
      "\xaf\xb0\xb1\xb2\xb3\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae\n"
      "\xcf\xd0\xd1\xd2\xd3\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca\xcb\xcc\xcd\xce\n";
    oled_write(logo, false);
  }
}
#endif
