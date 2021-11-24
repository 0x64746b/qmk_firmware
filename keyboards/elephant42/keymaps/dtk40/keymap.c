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

#ifdef OLED_ENABLE
#include <stdio.h>
#endif

enum {
    GNOME_3 = 0,
    GNOME_40,
    OSX,
    WIN_10,

    NUM_SUPPORTED_WMS,
} window_manager = GNOME_3;

const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("smile", 0x1F604),
    UCIS_SYM("catsmile", 0x1F638),
    UCIS_SYM("grin", 0x1F601),
    UCIS_SYM("shrug", 0x1F937),
    UCIS_SYM("expression", 0x1F611),
    UCIS_SYM("zany", 0x1F92A),
    UCIS_SYM("facepalm", 0x1F926),
    UCIS_SYM("roll", 0x1F644),
    UCIS_SYM("grim", 0x1F62C),
    UCIS_SYM("hug", 0x1F917),
    UCIS_SYM("giggle", 0x1F92D),
    UCIS_SYM("exploding", 0x1F92F),
    UCIS_SYM("starstruck", 0x1F929),
    UCIS_SYM("scream", 0x1F631),
    UCIS_SYM("catscream", 0x1F640),
    UCIS_SYM("thumbsup", 0x1F44D),
    UCIS_SYM("thinking", 0x1F914),
    UCIS_SYM("monocle", 0x1F9D0),
    UCIS_SYM("eyebrow", 0x1F928),
    UCIS_SYM("bulb", 0x1F4A1),
    UCIS_SYM("imp", 0x1F608),
    UCIS_SYM("raised", 0x1F64C),
    UCIS_SYM("muscle", 0x1F4AA),
    UCIS_SYM("eyes", 0x1F400),
    UCIS_SYM("worker", 0x1F477),
    UCIS_SYM("guard", 0x1F482),
    UCIS_SYM("student", 0x1F9D1, 0x200D, 0x1F393),
    UCIS_SYM("warn", 0x26A0, 0xFE0F),
    UCIS_SYM("rotating", 0x1F6A8),
    UCIS_SYM("mega", 0x1F4E3)
);

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    WM_GNOME_3 = SAFE_RANGE,
    WM_GNOME_40,
    WM_OSX,
    WM_WIN_10,
    WM_EXPOSEE,
    WM_PREV_DESK,
    WM_NEXT_DESK,
    WM_EMOJI,
};

#define ____  KC_TRNS
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

// dtk
//  Colemak-DH
#define KC_F_ LT(TLD_CBR, KC_F)
#define KC_P_ LT(GRV_BRC, KC_P)
#define KC_A_ LALT_T(KC_A)
#define KC_R_ LGUI_T(KC_R)
#define KC_S_ LCTL_T(KC_S)
#define KC_T_ LSFT_T(KC_T)
#define KC_G_ LT(NUM_BLK, KC_G)
#define KC_Z_ LT(LAY_LIT, KC_Z)
#define KC_D_ LT(SYMBLS, KC_D)
#define KC_L_ LT(GRV_BRC, KC_L)
#define KC_U_ LT(TLD_CBR, KC_U)
#define KC_M_ LT(NUM_BLK, KC_M)
#define KC_N_ RSFT_T(KC_N)
#define KC_E_ RCTL_T(KC_E)
#define KC_I_ RGUI_T(KC_I)
#define KC_O_ LALT_T(KC_O)
#define KC_H_ LT(SYMBLS, KC_H)
#define KC_BSP_ LT(NUM_ARR, KC_BSPC)
#define KC_SPC_ LT(NUM_ARR, KC_SPC)
#define KC_DEL_ LT(FN_NAV, KC_DEL)
#define KC_ENT_ LT(FN_NAV, KC_ENT)

//  Window Manager
#define KC_GNM3 WM_GNOME_3
#define KC_GNM4 WM_GNOME_40
#define KC_OSX WM_OSX
#define KC_WIN WM_WIN_10
#define KC_WM LT(WM, WM_EXPOSEE)
#define KC_PRVD WM_PREV_DESK
#define KC_NXTD WM_NEXT_DESK
#define KC_EMJI WM_EMOJI

//  QWERTY
#define KC_E__ LT(TLD_CBR, KC_E)
#define KC_R__ LT(GRV_BRC, KC_R)
#define KC_S__ LGUI_T(KC_S)
#define KC_D__ LCTL_T(KC_D)
#define KC_F__ LSFT_T(KC_F)
#define KC_V__ LT(SYMBLS, KC_V)
#define KC_U__ LT(GRV_BRC, KC_U)
#define KC_I__ LT(TLD_CBR, KC_I)
#define KC_H__ LT(NUM_BLK, KC_H)
#define KC_J__ RSFT_T(KC_J)
#define KC_K__ RCTL_T(KC_K)
#define KC_L__ RGUI_T(KC_L)
#define KC_SC__ LALT_T(KC_SCLN)
#define KC_M__ LT(SYMBLS, KC_M)

// Layer declarations
enum {
  COLEMK = 0,
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
  [COLEMK] = LAYOUT_kc( \
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

  [QWERTY_] = LAYOUT_kc( \
  //,----+----+----+----+----+----.                        ,----+----+----+----+----+----.
     ____, Q  , W  , E__, R__, T  ,                          Y  , U__, I__, O  , P  ,MINS,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ____, A_ , S__, D__, F__, G_ ,                          H__, J__, K__, L__,SC__,____,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
           Z_ , X  , C  , V__, B  ,                          N  , M__,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
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
     GNM3,GNM4,OSX ,WIN ,____,____,                         ____,____,EMJI,____,____,____,
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
     TO(0),TO(1),TO(2),TO(3),TO(4),TO(5),                   TO(6),TO(7),TO(8),TO(9),RGB_VAI,RGB_TOG,
  //|----+----+----+----+----+----|                        |----+----+----+----+----+----|
     ____,____,____,____,____,____,                         ____,____,____,____,    RGB_VAD,RGB_MOD,
  //`----+----+----+----+----+----|                        |----+----+----+----+----+----'
          ____,____,____,____,____,                         ____,____,____,____,____,
  //     `----+----+----+----+----+----+----.    ,----+----+----+----+----+----+----'
                         ____,____,____,____,     ____,____,____,____
  //                    `----+----+----+----'    `----+----+----+----'
  ),

  /*[] = LAYOUT_kc( \
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
  */
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
  if (qk_ucis_state.in_progress && record->event.pressed) {
      process_unicode_common(keycode & 255, record); // Strip all the fancy mod tap info, send only the basic keycode
      tap_code(keycode);
      return false;
  }
  switch (keycode) {
  case WM_GNOME_3:
    if (record->event.pressed) {
        window_manager=GNOME_3;
        set_unicode_input_mode(UC_LNX);
    }
    return false;
  case WM_GNOME_40:
    if (record->event.pressed) {
        window_manager=GNOME_40;
        set_unicode_input_mode(UC_LNX);
    }
    return false;
  case WM_OSX:
    if (record->event.pressed) {
        window_manager=OSX;
        set_unicode_input_mode(UC_MAC);
    }
    return false;
  case WM_WIN_10:
    if (record->event.pressed) {
        window_manager=WIN_10;
        set_unicode_input_mode(UC_WINC);
    }
    return false;
  case LT(WM, WM_EXPOSEE):
    if (record->tap.count && record->event.pressed) {
      switch (window_manager) {
      case GNOME_3 ... GNOME_40:
        tap_code(KC_LGUI);
        break;
      case OSX:
        register_code(KC_LCTL);
        tap_code(KC_UP);
        unregister_code(KC_LCTL);
        break;
      case WIN_10:
        register_code(KC_LGUI);
        tap_code(KC_TAB);
        unregister_code(KC_LGUI);
        break;
      default: break;
      }
      return false;
    }
    break;
  case WM_PREV_DESK:
    if (record->event.pressed) {
      switch (window_manager) {
      case GNOME_3 ... GNOME_40:
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_UP);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
        break;
      case OSX:
        register_code(KC_LCTL);
        tap_code(KC_LEFT);
        unregister_code(KC_LCTL);
        break;
      case WIN_10:
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_LEFT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        break;
      default: break;
      }
      return false;
    }
    break;
  case WM_NEXT_DESK:
    if (record->event.pressed) {
      switch (window_manager) {
      case GNOME_3 ... GNOME_40:
        register_code(KC_LCTL);
        register_code(KC_LALT);
        tap_code(KC_DOWN);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
        break;
      case OSX:
        register_code(KC_LCTL);
        tap_code(KC_RGHT);
        unregister_code(KC_LCTL);
        break;
      case WIN_10:
        register_code(KC_LCTL);
        register_code(KC_LGUI);
        tap_code(KC_RGHT);
        unregister_code(KC_LGUI);
        unregister_code(KC_LCTL);
        break;
      default: break;
      }
      return false;
    }
    break;
  case WM_EMOJI:
    if (record->event.pressed) {
        qk_ucis_start();
    }
    return false;
  }
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

#ifdef OLED_ENABLE
void oled_task_user(void) {
  if (is_keyboard_master()) {
    char disp[(21*4)+1] = {0};
    static char layer_names[DTK_NUM_OF_LAYERS][14] = {"Colemak-DH", "QWERTY", "Num + Arrows", "FN Keys + Nav", "Symbols", "Grv + Square", "Tilde + Curly", "Window Managr", "Numpad", "Layers + Lite"};
    static char wm_names[NUM_SUPPORTED_WMS][10] =  {"GNOME 3", "GNOME 40", "OS X", "Win 10"};
    static char rgb_names[22][16] = {
        "Off",
        "Static",
        // "Breathing 0",
        // "Breathing 1",
        // "Breathing 2",
        // "Breathing 3",
        // "Rainbow Mood 0",
        // "Rainbow Mood 1",
        // "Rainbow Mood 2",
        "Rainbow Swirl 0",
        "Rainbow Swirl 1",
        "Rainbow Swirl 2",
        "Rainbow Swirl 3",
        "Rainbow Swirl 4",
        "Rainbow Swirl 5",
        // "Snake 0",
        // "Snake 1",
        // "Snake 2",
        // "Snake 3",
        // "Snake 4",
        // "Snake 5",
        "Knight 0",
        "Knight 1",
        "Knight 2",
        // "Christmas",
        "Stat Gradient 0",
        "Stat Gradient 1",
        "Stat Gradient 2",
        "Stat Gradient 3",
        "Stat Gradient 4",
        "Stat Gradient 5",
        "Stat Gradient 6",
        "Stat Gradient 7",
        "Stat Gradient 8",
        "Stat Gradient 9",
        // "RGB Test",
        "Alternating"
        // "Twinkle 0",
        // "Twinkle 1",
        // "Twinkle 2",
        // "Twinkle 3",
        // "Twinkle 4",
        // "Twinkle 5"
    };
    snprintf(
        disp,
        84,
        "Layer: %s\nWindow Mgr: %s\nUnicode: %u\nRGB: %s\n",
        layer_names[get_highest_layer(layer_state)],
        wm_names[window_manager],
        get_unicode_input_mode(),
        rgb_names[rgblight_get_mode()]
    );
    oled_write(disp, false);
  }
}
#endif
