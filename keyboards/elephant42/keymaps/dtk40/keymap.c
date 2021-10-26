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
    KC_LRST,
    WM_EXPOSEE,
    WM_PREV_DESK,
    WM_NEXT_DESK,
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

// dtk
#define ____  KC_TRNS
#define KC_F_ LT(TLD_CBR, KC_F)
#define KC_U_ LT(TLD_CBR, KC_U)
#define KC_P_ LT(GRV_BRC, KC_P)
#define KC_L_ LT(GRV_BRC, KC_L)
#define KC_A_ LALT_T(KC_A)
#define KC_O_ LALT_T(KC_O)
#define KC_R_ LGUI_T(KC_R)
#define KC_I_ RGUI_T(KC_I)
#define KC_S_ LCTL_T(KC_S)
#define KC_E_ RCTL_T(KC_E)
#define KC_T_ LSFT_T(KC_T)
#define KC_N_ RSFT_T(KC_N)
#define KC_G_ LT(NUM_BLK, KC_G)
#define KC_M_ LT(NUM_BLK, KC_M)
#define KC_Z_ LT(LAY_LIT, KC_Z)
#define KC_D_ LT(SYMBLS, KC_D)
#define KC_H_ LT(SYMBLS, KC_H)
#define KC_BSP_ LT(NUM_ARR, KC_BSPC)
#define KC_SPC_ LT(NUM_ARR, KC_SPC)
#define KC_DEL_ LT(FN_NAV, KC_DEL)
#define KC_ENT_ LT(FN_NAV, KC_ENT)
#define KC_WM LT(WM, WM_EXPOSEE)
#define KC_PRVD WM_PREV_DESK
#define KC_NXTD WM_NEXT_DESK

// Layer declarations
enum {
  CM_NIX = 0,
  CM_OSX,
  CM_WIN,
  QWERTY_,
  NUM_ARR,
  FN_NAV,
  SYMBLS,
  GRV_BRC,
  TLD_CBR,
  WM,
  NUM_BLK,
  LAY_LIT,

  DTK_NUM_OF_LAYERS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [CM_NIX] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     TAB , Q  , W  , F_ , P_ , B  ,                          J  , L_ , U_ , Y  ,SCLN,BSLS,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ESC , A_ , R_ , S_ , T_ , G_ ,                          M_ , N_ , E_ , I_ , O_ ,QUOT,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
           Z_ , X  , C  , D_ , V  ,                          K  , H_ ,COMM,DOT ,SLSH,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                          WM ,BSP_,DEL_,XXXX,     XXXX,ENT_,SPC_,ALGR
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [CM_OSX] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     ____,____,____,____,____,____,                         ____,____,____,____,____,____,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ____,____,____,____,____,____,                         ____,____,____,____,____,____,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [CM_WIN] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     ____,____,____,____,____,____,                         ____,____,____,____,____,____,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ____,____,____,____,____,____,                         ____,____,____,____,____,____,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____

  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [QWERTY_] = LAYOUT_kc( \
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

  [NUM_ARR] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
      1  , 2  , 3  , 4  , 5  , 6  ,                          7  , 8  , 9  , 0  ,MINS,EQL ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     GRV ,XXXX,XXXX,XXXX,CAPS,XXXX,                         LEFT,DOWN, UP ,RGHT,LBRC,RBRC,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         XXXX,XXXX,XXXX,XXXX,XXXX,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [FN_NAV] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
      F1 , F2 , F3 , F4 , F5 , F6 ,                          F7 , F8 , F9 ,F10 ,F11 ,F12 ,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     TILD,XXXX,XXXX,XXXX,XXXX,XXXX,                         HOME,PGDN,PGUP,END ,LCBR,RCBR,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         XXXX,XXXX,XXXX,XXXX,XXXX,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [SYMBLS] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     EXLM, AT ,HASH,DLR ,PERC,CIRC,                         AMPR,ASTR,LPRN,RPRN,UNDS,PLUS,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,                         XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [GRV_BRC] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     GRV ,XXXX,XXXX,XXXX,XXXX,XXXX,                         XXXX,XXXX,XXXX,XXXX,LBRC,RBRC,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,                         XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  [TLD_CBR] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     TILD,XXXX,XXXX,XXXX,XXXX,XXXX,                         XXXX,XXXX,XXXX,XXXX,LCBR,RCBR,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,                         XXXX,XXXX,XXXX,XXXX,XXXX,XXXX,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),


  [WM] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     ____,____,____,____,____,____,                         ____,____,____,____,____,____,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ____,____,____,____,____,____,                         PRVD,NXTD,PRVD,NXTD,____,____,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),


  [NUM_BLK] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     ____,____, F7 , F8 , F9 ,F10 ,                         XXXX, 7  , 8  , 9  ,____,____,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ____,____, F4 , F5 , F6 ,F11 ,                         XXXX, 4  , 5  , 6  ,____,____,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____, F1 , F2 , F3 ,F12 ,                         XXXX, 1  , 2  , 3  ,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____, 0  ,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),


  [LAY_LIT] = LAYOUT( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     TO(1),TO(2),TO(3),TO(4),TO(5),TO(6),                   TO(7),TO(8),TO(9),TO(0),RGB_VAI,RGB_TOG,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ____,____,____,____,____,____,                         ____,____,____,____,    RGB_VAD,RGB_MOD,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_T):
        case RSFT_T(KC_N):
            return TAPPING_TERM_SFT;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LT(WM, WM_EXPOSEE):
    if (record->tap.count && record->event.pressed) {
      if (layer_state_is(CM_NIX)) {
        tap_code(KC_LGUI);
      } else if (layer_state_is(CM_OSX)) {
        register_code(KC_LCTL);
        tap_code(KC_UP);
        unregister_code(KC_LCTL);
      } else if (layer_state_is(CM_WIN)) {
        register_code(KC_LGUI);
        tap_code(KC_TAB);
        unregister_code(KC_LGUI);
      }
      return false;
    }
    break;
  case WM_PREV_DESK:
    if (record->event.pressed) {
      if (layer_state_is(CM_NIX)) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_UP);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
      } else if (layer_state_is(CM_OSX)) {
        register_code(KC_LCTL);
        tap_code(KC_LEFT);
        unregister_code(KC_LCTL);
      } else if (layer_state_is(CM_WIN)) {
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_LEFT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
      }
      return false;
    }
    break;
  case WM_NEXT_DESK:
    if (record->event.pressed) {
      if (layer_state_is(CM_NIX)) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_DOWN);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
      } else if (layer_state_is(CM_OSX)) {
        register_code(KC_LCTL);
        tap_code(KC_RGHT);
        unregister_code(KC_LCTL);
      } else if (layer_state_is(CM_WIN)) {
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_RGHT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
      }
      return false;
    }
    break;
  case KC_LRST:
    if (record->event.pressed) {
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
    // static char layer_names[DTK_NUM_OF_LAYERS][25] = {"Colemak on Linux", "Colemak on OSX", "Colemak on Win 10", "QWERTY", "Numbers and Arrows", "Fn Keys and Nav", "Symbols", "Grave and Brackets", "Tilde and Curly Brackets", "Window Manager on Linux", "Window Manager on OSX", "Window Manager on Win 10", "Num Block", "Layers n Lights"};
    static char layer_names[DTK_NUM_OF_LAYERS][14] = {"Colemak Linux", "Colemak OSX", "Colemak Win10", "QWERTY", "Num + Arrows", "FN Keys + Nav", "Symbols", "Grv + Square", "Tilde + Curly", "WM Linux", "WM OSX", "WM WIN", "Numpad", "Layers + Lite"};
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
