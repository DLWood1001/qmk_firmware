#include QMK_KEYBOARD_H
#include "version.h"
#include <print.h>

#define PRI_ 0
#define NUM_ 1
#define FUN_ 2
#define SYM_ 3
#define PAD_ 4
#define NAV_ 5
#define SYS_ 6
#define RGB_ 7
#define DBG_ 8

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [PRI_] = LAYOUT_ergodox(
  // Left Hand
  // -------  -------             -------  -------  -------   -------  -------
     _______, _______,            _______, _______, _______,  _______, _______,
     KC_TAB,  KC_Q,               KC_W,    KC_E,    KC_R,     KC_T,    KC_CAPS,
     KC_ESC,  KC_A,               KC_S,    KC_D,    KC_F,     KC_G,
     KC_LSFT, MT(MOD_LCTL, KC_Z), KC_X,    KC_C,    KC_V,     KC_B,    _______,
     TT(FUN_), _______,           KC_LALT, KC_LALT, TT(NUM_), 
                                                              _______, _______,
                                                                       _______,
                                                    KC_ENT,   KC_ESC,  _______,

  // Right Hand 
  // -------   -------    -------   -------  -------  -------                -------
     TG(RGB_), _______,   _______,  _______, _______, _______,               _______,
     _______,  KC_Y,      KC_U,     KC_I,    KC_O,    KC_P,                  KC_BSLS,
               KC_H,      KC_J,     KC_K,    KC_L,    KC_SCLN,               KC_QUOT,
     _______,  KC_N,      KC_M,     KC_COMM, KC_DOT,  MT(MOD_RCTL, KC_SLSH), KC_RSFT,
                          TT(NUM_), KC_RALT, KC_MINS, KC_EQL,                TT(FUN_),
     _______,  MO(DBG_), 
     _______,
     _______,  KC_BS_DEL, KC_SPC
  ),

  [NUM_] = LAYOUT_ergodox(
  // Left Hand
  // -------  -------  -------  -------  -------      -------  -------
     _______, _______, _______, _______, _______,     _______, _______,
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,      KC_PERC, _______,
     KC_CIRC, KC_1,    KC_2,    KC_3,    KC_4,        KC_5,
     KC_MINS, KC_PAST, XXXXXXX, XXXXXXX, KC_LPRN,     KC_LPRN, _______,
     _______, _______, XXXXXXX, XXXXXXX, _______,
                                                      _______, _______,
                                                               _______,
                                         KC_NUM_EXIT, _______, _______,

  // Right Hand
  // -------  -------  -------     -------  -------  -------  -------
     _______, _______, _______,    _______, _______, _______, _______,
     _______, KC_CIRC, KC_AMPR,    KC_PAST, KC_LPRN, KC_RPRN, _______,
              KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_EQL,
     _______, KC_RPRN, KC_RPRN,    KC_COMM, KC_DOT,  KC_SLSH, KC_PPLS,
                       _______,    _______, _______, _______, _______,
     _______, _______,
     _______,
     _______, _______, KC_NUM_EXIT
  ),

  [FUN_] = LAYOUT_ergodox(
  // Left Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

  // Right Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
     _______, _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______,
     _______, _______,
     _______,
     _______, _______, _______
  ),

  [SYM_] = LAYOUT_ergodox(
  // Left Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, KC_TILD, _______, _______, _______, _______, _______,
     _______, KC_GRV,  KC_LCBR, _______, KC_RCBR, _______,
     _______, _______, KC_LABK, _______, KC_RABK, _______, _______,
     _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

  // Right Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, KC_PPLS, KC_LBRC, KC_COLN, KC_RBRC, KC_PIPE, KC_GRV,
              KC_QUOT, KC_LPRN, KC_DQUO, KC_RPRN, KC_SCLN, KC_EQL,
     _______, KC_MINS, KC_LCBR, KC_UNDS, KC_RCBR, KC_TILD, KC_PPLS,
                       _______, _______, _______, _______, _______,
     _______, _______,
     _______,
     _______, _______, _______
  ),

  [PAD_] = LAYOUT_ergodox(
  // Left Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

  // Right Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, KC_LPRN, KC_EQL,  KC_SLSH, KC_PAST, KC_PMNS, _______,
     _______, KC_RPRN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_COMM,
              KC_CIRC, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_EQL,
     _______, KC_DLR,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                       KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______,
     _______, _______,
     _______,
     _______, KC_BSPC, KC_P0
  ),

  [NAV_] = LAYOUT_ergodox(
  // Left Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, KC_LSFT, _______, _______, _______,
     _______, KC_LCTL, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

  // Right Hand
  // -------  -------   -------   -------  -------   -------  -------
     XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
     XXXXXXX, SC_WLEFT, SC_WDOWN, SC_WUP,  SC_WRGHT, XXXXXXX, XXXXXXX,
              KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  XXXXXXX, XXXXXXX,
     XXXXXXX, KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   XXXXXXX, XXXXXXX,
                        XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
     _______, _______,
     _______,
     _______, _______,  _______
  ),

  [SYS_] = LAYOUT_ergodox(
  // left Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

  // Right Hand
  // -------   ------- -------     -------     -------      -------    -------
     _______, _______, _______,    _______,    _______,     _______,   _______,
     _______, KC_SLCK, SC_PC_ALL,  _______,    _______,     _______,   _______,
              _______, SC_PC_UNDO, SC_PC_COPY, SC_PC_PASTE, SC_PC_CUT, _______,
     _______, KC_LGUI, KC_DEL,     _______,    _______,     _______,   _______,
                       _______,    _______,    _______,     _______,   _______,
     _______, _______,
     _______,
     _______, _______, _______
  ),

  [RGB_] = LAYOUT_ergodox(
  // left Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, RGB_SAI, _______, _______, _______, _______,
     KC_LSFT, _______, _______, _______, RGB_VAI, _______, _______,
     _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         RGB_TOG, _______, _______,

  // Right Hand
  // -------   -------  -------  -------  -------  -------  -------
     TG(RGB_), _______, _______, _______, _______, _______, _______,
     _______,  _______, _______, _______, _______, _______, _______,
               RGB_HUI, _______, _______, _______, _______, _______,
     _______,  _______, _______, _______, _______, _______, KC_RSFT,
                        _______, _______, _______, _______, _______,
     _______,  _______,
     _______,
     _______,  _______, RGB_MOD
  ),

  [DBG_] = LAYOUT_ergodox(
  // left Hand
  // -------  -------  -------  -------  -------  -------  -------
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______,
                                                  _______, _______,
                                                           _______,
                                         _______, _______, _______,

  // Right Hand
  // -------  -------  -------  -------  -------  -------  -------
     RESET,   _______, _______, _______, _______, _______, _______,
     DEBUG,   _______, _______, _______, _______, _______, _______,
              _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______,
     _______, _______,
     _______,
     _______, _______, _______
  )
};



extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  
  debug_enable = true;
  debug_matrix = false;
  debug_keyboard = false;
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [NUM_] = {
    // Right Side
    // -------------  -------------  ------------   -------------  -------------
       {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255},
       {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
       {32,255,234},  {32,255,234},  {32,255,234},  {32,255,234},  {32,255,234},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},

    // Left Side
    // -------------  -------------  ------------   -------------  -------------
       {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255},
       {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
       {32,255,234},  {32,255,234},  {32,255,234},  {32,255,234},  {32,255,234},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0}
  },

  [SYM_] = {
    // Right Side
    // -------------  -------------  ------------   -------------  -------------
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {134,255,213}, {85,203,158},  {134,255,213}, {85,203,158},  {134,255,213},
       {243,222,234}, {85,203,158},  {243,222,234}, {85,203,158},  {134,255,213},
       {32,176,255},  {85,203,158},  {32,176,255},  {85,203,158},  {134,255,213},
                      {85,203,158},  {205,255,255}, {85,203,158},  {0,0,0},

    // Left Side
    // -------------  -------------  ------------   -------------  -------------
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0}
  },

  [PAD_] = {
    // Right Side
    // -------------  -------------  ------------   -------------  -------------
       {14,255,255},  {250,159,255}, {250,159,255}, {250,159,255}, {250,159,255},
       {14,255,255},  {33,255,255},  {33,255,255},  {33,255,255},  {250,159,255},
       {250,159,255}, {33,255,255},  {33,255,255},  {33,255,255},  {250,159,255},
       {250,159,255}, {33,255,255},  {33,255,255},  {33,255,255},  {14,255,255},
                      {33,255,255},  {33,255,255},  {141,255,233}, {14,255,255},
    // Left Side
    // -------------  -------------  ------------   -------------  -------------
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {14,255,255},  {0,0,0},       {0,0,0},       {0,0,0}
  },

  [NAV_] = {
    // Right Side
    // -------------  -------------  ------------   -------------  -------------
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,205,155},   {0,205,155},   {0,205,155},   {0,205,155},   {0,0,0},
       {0,205,155},   {0,205,155},   {0,205,155},   {0,205,155},   {0,0,0},
       {31,255,255},  {31,255,255},  {31,255,255},  {31,255,255},  {0,0,0},
                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},

    // Left Side
    // -------------  -------------  ------------   -------------  -------------
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0}
  },

};

static bool bs_del_flag = false;

void update_tri_layer_d(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    uprintf("Adjust On.\n");
    layer_on(layer3);
  } else {
    uprintf("Adjust Off.\n");
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case KC_RAISE:
      if (record->event.pressed) {
        uprintf("Raise On.\n");
        layer_on(NUM_);
      } else {
        uprintf("Raise Off.\n");
        layer_off(NUM_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;

    case KC_LOWER:
      if (record->event.pressed) {
        uprintf("Lower On.\n");
        layer_on(PAD_);
      } else {
        uprintf("Lower Off.\n");
        layer_off(PAD_);
      }
      update_tri_layer_d(NUM_, PAD_, FUN_);
      return false;

    case KC_ADJUST:
      if (record->event.pressed) {
        uprintf("Adjust On.\n");
        layer_on(FUN_);
      } else {
        uprintf("Adjust Off.\n");
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

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case NUM_:
      set_layer_color(NUM_);
      break;
    case SYM_:
      set_layer_color(SYM_);
      break;
    case PAD_:
      set_layer_color(PAD_);
      break;
    case NAV_:
      set_layer_color(NAV_);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case PRI_:
      ergodox_right_led_1_on();
      break;
    case NUM_:
      ergodox_right_led_2_on();
      break;
    case SYM_:
      ergodox_right_led_3_on();
      break;
    case PAD_:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case SYS_:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case RGB_:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case DBG_:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

enum combos {
  CMB_DF,
  CMB_JK,
  CMB_DV,
  CMB_SF,
  CMB_SD,
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CMB_DF] = COMBO_ACTION(df_combo),
  [CMB_JK] = COMBO_ACTION(jk_combo),
  [CMB_DV] = COMBO_ACTION(dv_combo),
  [CMB_SF] = COMBO_ACTION(sf_combo),
  [CMB_SD] = COMBO_ACTION(sd_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_DF:
    case CMB_JK:
      if (pressed) {
        uprintf("DF or JK pressed.\n");
        layer_on(SYM_);
      } else {
        uprintf("DF or JK unpressed.\n");
        layer_off(SYM_);
      }
    break;

    case CMB_DV:
      if (pressed) {
        uprintf("DV pressed.\n");
        layer_on(NAV_);
      } else {
        uprintf("DV unpressed.\n");
        layer_off(NAV_);
      }
    break;

    case CMB_SF:
      if (pressed) {
        uprintf("SF pressed.\n");
        layer_on(PAD_);
      } else {
        uprintf("SF unpressed.\n");
        layer_off(PAD_);
      }
    break;

    case CMB_SD:
      if (pressed) {
        uprintf("SD pressed.\n");
        layer_on(SYS_);
      } else {
        uprintf("SD unpressed.\n");
        layer_off(SYS_); }
    break;

  }
}

//bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//  uprintf("permissive hold.\n");
//  switch (keycode) {
//    case LSFT_T(KC_TAB):
//      return false;
//    case RSFT_T(KC_MINS):
//      return false;
//    default:
//      return false;
//  }
//}

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LSFT_T(KC_TAB):
      return 125;
    case RSFT_T(KC_MINS):
      return 125;
    default:
      return TAPPING_TERM;
  }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode) {
  switch (keycode) {
    case LSFT_T(KC_TAB):
      return true;
    case RSFT_T(KC_MINS):
      return true;
    default:
      return false;
  }
}

