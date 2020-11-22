#include QMK_KEYBOARD_H

#include "version.h"
#include <print.h>

// Layers - General
#define PRI_ 0
#define NUM_ 1
#define FUN_ 2
#define SYM_ 3
#define PAD_ 4
#define NAV_ 5
#define SYS_ 6
#define RGB_ 7
#define DBG_ 8

// Layers - Games
#define GAMES_ 9
#define CELESTE_ 10

// Keycodes
enum custom_keycodes {
  KC_START = SAFE_RANGE,
  KC_RAISE,
  KC_LOWER,
  KC_ADJUST,
  KC_NUM_EXIT,
  KC_BS_DEL
};

// Shortcuts
#define SC_UNDO  LCTL(KC_Z)
#define SC_WLEFT RCTL(KC_LEFT)
#define SC_WDOWN RCTL(KC_DOWN)
#define SC_WUP   RCTL(KC_UP)
#define SC_WRGHT RCTL(KC_RGHT)
#define SC_PC_ALL RCTL(KC_A)

#define SC_MAC_UNDO RGUI(KC_Z)
#define SC_MAC_CUT RGUI(KC_X)
#define SC_MAC_COPY RGUI(KC_C)
#define SC_MAC_PASTE RGUI(KC_V)
#define SC_PC_UNDO RCTL(KC_Z)
#define SC_PC_CUT RCTL(KC_X)
#define SC_PC_COPY RCTL(KC_C)
#define SC_PC_PASTE RCTL(KC_V)

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layer: Primary (PRI_)
  [PRI_] = LAYOUT_stack(
  // Left Hand
  // _______  _______            _______ _______   _______  _______   _______   _______
     KC_TAB,  KC_Q,              KC_W,   KC_E,     KC_R,    KC_T,
     KC_ESC,  KC_A,              KC_S,   KC_D,     KC_F,    KC_G,
     KC_LSFT, MT(MOD_LCTL,KC_Z), KC_X,   KC_C,     KC_V,    KC_B,     TT(RGB_), _______,
                                         TT(FUN_), KC_LALT, TT(NUM_), KC_ENT,   KC_BS_DEL,

  // Right Hand
  // _______    _______  _______   _______  _______  _______   _______              _______
                         KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,                 KC_BSLS,
                         KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,              KC_QUOT,
     _______,   KC_CAPS, KC_N,     KC_M,    KC_COMM, KC_DOT,  MT(MOD_RCTL,KC_SLSH), KC_RSFT,
     KC_BS_DEL, KC_SPC,  MO(NUM_), KC_RALT, TT(FUN_)
  ),

  // Layer: Number (NUM_)
  [NUM_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
     KC_CIRC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
     KC_MINS, KC_PAST, _______, _______, KC_LPRN, KC_LPRN, KC_LSFT, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______    _______  _______   _______  _______  _______  _______  _______
                         KC_CIRC,  KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______,
                         KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
     _______,   _______, KC_RPRN,  KC_RPRN, KC_COMM, KC_DOT, KC_SLSH,  KC_PPLS,
     KC_BS_DEL, KC_SPC,  MO(NUM_), KC_RALT, TT(FUN_)
  ),

  // Layer: Function (FUN_)
  [FUN_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
     _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
                       _______, _______, _______, _______, _______, _______,
                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______
  ),

  // Layer: Symbol (SYM_)
  [SYM_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, KC_TILD, _______, _______, _______, _______,
     _______, KC_GRV,  KC_LCBR, _______, KC_RCBR, _______,
     _______, _______, KC_LABK, _______, KC_RABK, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
                       KC_PPLS, KC_LBRC, KC_COLN, KC_RBRC, KC_PIPE, _______,
                       KC_QUOT, KC_LPRN, KC_DQUO, KC_RPRN, KC_BSLS, KC_EQL,
     _______, _______, KC_MINS, KC_LCBR, KC_UNDS, KC_RCBR, KC_TILD, KC_GRV,
     _______, _______, _______, _______, _______
  ),

  // Layer: (Number)Pad (PAD_)
  [PAD_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  /* _______, KC_LPRN, KC_EQL,  KC_SLSH, KC_PAST, KC_PMNS, _______, */
  /* _______, KC_RPRN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_COMM, */
  /*          KC_CIRC, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_EQL, */
  /* _______, KC_DLR,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, */
  /*                   KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______, */
  /* _______, _______, */
  /* _______, */
  /* _______, KC_BSPC, KC_P0 */

  // Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
                       _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______
  ),

  // Layer: Navigation (NAV_)
  [NAV_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,
     _______, _______, KC_LSFT, _______, _______, _______,
     _______, KC_LCTL, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
                       SC_WLEFT, SC_WDOWN, SC_WUP,  SC_WRGHT, _______, _______,
                       KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  _______, _______,
     _______, _______, KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   _______, _______,
     _______, _______, _______, _______, _______
  ),

  // Layer: System (SYS_)
  [SYS_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______  _______  _______  _______     _______     _______      _______    _______
                       KC_SLCK, SC_PC_ALL,  _______,    _______,     _______,   _______,
                       _______, SC_PC_UNDO, SC_PC_COPY, SC_PC_PASTE, SC_PC_CUT, _______,
     _______, _______, KC_LGUI, KC_DEL,     _______,    _______,     _______,   _______,
     _______, _______, _______, _______,    _______
  ),

  // Layer: RGB (RGB_)
  [RGB_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______  _______  _______  _______  _______  _______   _______  _______
                       _______, RGB_HUI, RGB_HUD, _______,  _______, _______,
                       RGB_MOD, RGB_VAI, RGB_VAD, RGB_RMOD, _______, _______,
     _______, _______, _______, RGB_SAI, RGB_SAD, _______,  _______, _______,
     _______, _______, _______, _______, _______
  ),

  // Layer: Debug (DBG_)
  [DBG_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
                       _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______
  ),

  // Layer: Games (GAMES_)
  [GAMES_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______, _______,

  // Right Hand
  // _______  _______  _______       _______  _______  _______  _______  _______
                       TG(CELESTE_), _______, _______, _______, _______, _______,
                       _______,      _______, _______, _______, _______, _______,
     _______, _______, _______,      _______, _______, _______, _______, _______,
     _______, _______, _______,      _______, _______
  ),

  // Layer: Game (CELESTE_)
  [CELESTE_] = LAYOUT_stack(
  // Left Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
     _______, _______, _______, KC_UP,   KC_R,    KC_T,
     KC_ESC,  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
     _______, _______, _______, KC_C,    _______, _______, _______, _______,
                                _______, _______, KC_D,    KC_ENT,  _______,

  // Right Hand
  // _______  _______  _______  _______  _______  _______  _______  _______
                       TG(CELESTE_), _______, KC_D,    _______, KC_P,    _______,
                       _______,      KC_J,    KC_D,    KC_G,    _______, _______,
     _______, _______, _______,      _______, _______, _______, _______, _______,
     _______, KC_J,    KC_G,         _______, _______
  )
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case PRI_:
            oled_write_P(PSTR("Primary\n"), false);
            break;
        case NUM_:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case FUN_:
            oled_write_P(PSTR("Funtion\n"), false);
            break;
        case SYM_:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case PAD_:
            oled_write_P(PSTR("Number Pad\n"), false);
            break;
        case NAV_:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case SYS_:
            oled_write_P(PSTR("System\n"), false);
            break;
        case RGB_:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        case DBG_:
            oled_write_P(PSTR("Debug\n"), false);
            break;
        case GAMES_:
            oled_write_P(PSTR("Games\n"), false);
            break;
        case CELESTE_:
            oled_write_P(PSTR("Celeste\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
    //uint32_t mode = rgblight_get_mode();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

void keyboard_post_init_user(void) {
  debug_enable = true;
  debug_matrix = false;
  debug_keyboard = false;
}

static bool bs_del_flag = false;

void update_tri_layer_d(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    /* uprintf("Adjust On.\n"); */
    layer_on(layer3);
  } else {
    /* uprintf("Adjust Off.\n"); */
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case KC_RAISE:
      if (record->event.pressed) {
        /* uprintf("Raise On.\n"); */
        layer_on(NUM_);
      } else {
        /* uprintf("Raise Off.\n"); */
        layer_off(NUM_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;

    case KC_LOWER:
      if (record->event.pressed) {
        /* uprintf("Lower On.\n"); */
        layer_on(PAD_);
      } else {
        /* uprintf("Lower Off.\n"); */
        layer_off(PAD_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;

    case KC_ADJUST:
      if (record->event.pressed) {
        /* uprintf("Adjust On.\n"); */
        layer_on(FUN_);
      } else {
        /* uprintf("Adjust Off.\n"); */
        layer_off(FUN_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;
  }

  switch (keycode) {
    case KC_NUM_EXIT:
        layer_off(NUM_);
        return false;

    case KC_BS_DEL:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LSFT)) {
          unregister_code(KC_LSFT);
          register_code(KC_DEL);
          bs_del_flag = true;
        } else {
          register_code(KC_BSPC);
        }
      } else {
        if (bs_del_flag) {
          unregister_code(KC_DEL);
          register_code(KC_LSFT);
          bs_del_flag = false;
        } else {
          unregister_code(KC_BSPC);
        }
      }

      return false;
  }

  return true;
}

enum combos {
  CMB_DF,
  CMB_JK,
  CMB_DV,
  CMB_SF,
  CMB_SD,
  CMB_QW,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CMB_DF] = COMBO_ACTION(df_combo),
  [CMB_JK] = COMBO_ACTION(jk_combo),
  [CMB_DV] = COMBO_ACTION(dv_combo),
  [CMB_SF] = COMBO_ACTION(sf_combo),
  [CMB_SD] = COMBO_ACTION(sd_combo),
  [CMB_QW] = COMBO_ACTION(qw_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  oled_write_P(PSTR("\n\n"), false);
  switch(combo_index) {
    case CMB_DF:
    case CMB_JK:
      if (pressed) {
        /* uprintf("DF or JK pressed.\n"); */
        layer_on(SYM_);
      } else {
        /* uprintf("DF or JK unpressed.\n"); */
        layer_off(SYM_);
      }
    break;

    case CMB_DV:
      if (pressed) {
        /* uprintf("DV pressed.\n"); */
        layer_on(NAV_);
      } else {
        /* uprintf("DV unpressed.\n"); */
        layer_off(NAV_);
      }
    break;

    case CMB_SF:
      if (pressed) {
        /* uprintf("SF pressed.\n"); */
        layer_on(PAD_);
      } else {
        /* uprintf("SF unpressed.\n"); */
        layer_off(PAD_);
      }
    break;

    case CMB_SD:
      if (pressed) {
        /* uprintf("SD pressed.\n"); */
        layer_on(SYS_);
      } else {
        /* uprintf("SD unpressed.\n"); */
        layer_off(SYS_);
      }
    break;

    case CMB_QW:
      /* if (pressed) { */
      /*   set_oneshot_layer(GAMES_, ONESHOT_START); */
      /* } else { */
      /*   clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED); */
      /* } */

      if (pressed) {
        layer_on(GAMES_);
      } else {
        layer_off(GAMES_);
      }
    break;

    default:
    break;
  }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT(MOD_LCTL, KC_Z):
      return true;
    case MT(MOD_RCTL, KC_SLSH):
      return true;
    default:
      return false;
  }
}

