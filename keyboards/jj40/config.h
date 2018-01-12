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

#ifndef CONFIG_H
#define CONFIG_H

#define VENDOR_ID       0x20A0
#define PRODUCT_ID      0x422D
// TODO: share these strings with usbconfig.h
// Edit usbconfig.h to change these.
#define MANUFACTURER    winkeyless.kr
#define PRODUCT         jj40

/* matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 15


#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 4000  /* Time (in ms) before the one shot key is released */

#define IGNORE_MOD_TAP_INTERRUPT

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

#define NO_UART 1
#define BOOTLOADHID_BOOTLOADER 1

/* key combination for command */
#define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

#endif
#define LEADER_TIMEOUT 900
#define TAPPING_TERM 200
/* RGB underglow */
// The RGB_DI_PIN value seems to be shared between all PS2AVRGB boards.
// The same pin is used on the JJ40, at least.
#define RGBLED_NUM 5
#define RGB_DI_PIN E2
#define RGBLIGHT_ANIMATIONS

#define BACKLIGHT_LEVELS 12
#define BACKLIGHT_BREATHING

/*
#define GRAVE_ESC_CTRL_OVERRIDE
#define PERMISSIVE_HOLD
*/
#define TAP_ROTATION_TIMEOUT 400
#define TAP(keycode) register_code16(keycode); unregister_code16(keycode)
#define TAP_WITH_MOD(mod, key) \
  register_code(mod); \
  register_code(key); \
  unregister_code(key); \
  unregister_code(mod)

