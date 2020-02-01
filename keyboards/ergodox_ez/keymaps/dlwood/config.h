/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
//#undef NO_DEBUG
//#undef NO_PRINT

#undef DEBOUNCE
#undef TAPPING_TERM
#undef TAPPING_TOGGLE

#define COMBO_COUNT 5
#define COMBO_TERM 30
#define DEBOUNCE 35
#define TAPPING_TOGGLE 2

// Note (Dan): Higher the number, the more likely a tap
// Note (Dan): Lower the number, the more likely a hold
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_RAINDROPS
