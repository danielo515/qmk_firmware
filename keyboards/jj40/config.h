/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define VENDOR_ID       0x20A0
#define PRODUCT_ID      0x422D
// TODO: share these strings with usbconfig.h
// Edit usbconfig.h to change these.
#define MANUFACTURER    Kprepublic
#define PRODUCT         jj40

/* matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { B0, B1, B3, B4 }
#define MATRIX_COL_PINS { C4, C5, C6, C7, A4, A5, A6, A7, A3, A2, A1, A0 }


#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 4000  /* Time (in ms) before the one shot key is released */

#define IGNORE_MOD_TAP_INTERRUPT

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN D4
#define BACKLIGHT_LEVELS 12
// #define BACKLIGHT_BREATHING  // Requires #4324 to enable hardware pwm for atmega32a

/* RGB underglow */
// NOTE: for PS2AVRGB boards, underglow commands are sent via I2C to 0xB0.
#define RGBLED_NUM 5
#define RGBLIGHT_ANIMATIONS

// #define LEADER_TIMEOUT 900
#define TAPPING_TERM 200
/* RGB underglow */
// The RGB_DI_PIN value seems to be shared between all PS2AVRGB boards.
// The same pin is used on the JJ40, at least.
#define RGBLED_NUM 5
#define RGB_DI_PIN E2
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 15
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 1

#define BACKLIGHT_BREATHING

#define PERMISSIVE_HOLD

#define TAP_ROTATION_TIMEOUT 350
#define TAP(keycode) register_code16(keycode); unregister_code16(keycode)
#define TAP_WITH_MOD(mod, key) \
  register_code(mod); \
  register_code(key); \
  unregister_code(key); \
  unregister_code(mod)

#define TD_DBL_ARR(ONE,TWO) [_D_##ONE##_##TWO] = ACTION_TAP_DANCE_DOUBLE_SAFE(KC_##ONE,TWO),
#define TD_DBL(ONE,TWO) _D_##ONE##_##TWO
#define TD_DBL_NAM(ONE,TWO) TD(_D_##ONE##_##TWO)

