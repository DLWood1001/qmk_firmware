/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_ANIMATIONS // Removes all Effects
  #undef RGBLIGHT_STATIC_PATTERNS // Removes all Static Effects
  #undef RGBLIGHT_EFFECT_STATIC_LIGHT // Removes Specific Static Effect

  #define RGBLIGHT_EFFECT_RAINBOW_MOOD // Specific Animation
  //#define RGBLIGHT_MODE_RAINBOW_MOOD // Not sure, thought I could choose which animation with this define.
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#undef DEBOUNCE
#undef TAPPING_TERM
#undef TAPPING_TOGGLE

#define COMBO_COUNT 6
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

#define EE_HANDS
#define MASTER_RIGHT

#define RGBLIGHT_SLEEP
#define RGBLIGHT_SPLIT
