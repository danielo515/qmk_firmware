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
#include "jj40.h"
#include "keymap_spanish.h"

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TRIPE_TICKS
};

enum tap_dance {
  TD_LBRACES=0,
  TD_RBRACES,
  DOT_COMM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //
/* Qwerty
 * ,------------------------------------------------------------------------------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |      R            |       T      |    Esc      |      ' ?      |         Y      |      U      |     I    |     O    |      P     |
 * +------+------+------+-------------------+--------------+-------------+---------------+----------------+-------------+----------+----------+------------|
 * |   A  |   S  |   D  |      F            |       G      |    Tab      |     Enter     |         H      |      J      |     K    |     L    |      Ñ     |
 * +------+------+------+-------------------+--------------+-------------+---------------+----------------+-------------+----------+----------+------------|
 * |   Z  |   X  |   C  |      V            |       B      |      {      |       }       |         N      |      M      |    ,     |    UP    |      `     |
 * +------+------+------+-------------------+--------------+-------------+---------------+----------------+-------------+----------+----------+------------|
 * | GUI  | Alt  | Shft |   Raise  /        |     Bksp     |    . :      |       |       |    Space/Sft   |   Lower     |   Left   |   Down   |    Right   |
 * `------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
 KC_Q,    KC_W,      KC_E,    KC_R,                    KC_T,           KC_ESC,                ES_APOS,         KC_Y,           KC_U,           KC_I,      KC_O,      KC_P,
 KC_A,    KC_S,      KC_D,    KC_F,                    KC_G,           KC_TAB,                KC_ENT,          KC_H,           KC_J,           KC_K,      KC_L,      KC_SCLN,
 KC_Z,    KC_X,      KC_C,    KC_V,                    KC_B,           TD(TD_LBRACES),        TD(TD_RBRACES),  KC_N,           KC_M,           KC_COMMA,  KC_UP,     ES_GRV,
 KC_LGUI, KC_LCTRL,  KC_LALT, LT(_RAISE, KC_KP_SLASH), SFT_T(KC_BSPC), KC_DOT ,               ES_PIPE,         SFT_T(KC_SPC),  OSL(_LOWER),    KC_LEFT,   KC_DOWN,   KC_RGHT
),
/* Lower
 * ,-------------------------------------------------------------------------------------------------------------------------------.
 * |    ª    |    !   |    "    |     #    |     $    |     %    |     &    |     /    |     (    |     )    |     =    |   Bksp   |
 * |---------+--------+---------+----------+----------+---------------------+----------+----------+----------+----------+----------|
 * |    @    |   F1   |   F2    |    F3    |    F4    |    -     |     _    |     _    |     +    |          |          |    |     |
 * |---------+--------+---------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
 * |  ctl+z  |   F7   |   F8    |    F9    |    F10   |    [     |     ]    |    ^     |  ISO |   |          |          |  Enter   |
 * |---------+--------+---------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |         |        |         |          |          |     (    |     )    |          |          |          |          |          |
 * `-------------------------------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD,       KC_EXLM,    KC_AT,      KC_HASH,   KC_DLR,     KC_PERC,     KC_CIRC,    KC_AMPR,       KC_ASTR,      KC_LPRN,    KC_RPRN,   KC_BSPC, \
  ES_AT,         KC_F1,      KC_F2,      KC_F3,     KC_F4,      ES_MINS,     ES_UNDS,    KC_UNDS,       ES_PLUS,      KC_LCBR,    KC_RCBR,   KC_PIPE, \
  LCTL(KC_Z),    KC_F7,      KC_F8,      KC_F9,     KC_F10,     ES_LBRC,     ES_RBRC,    S(KC_LBRACKET),    S(KC_NUBS),   _______,    _______,   _______, \
   _______,      _______,    _______,    _______,   _______,    ES_LPRN,     ES_RPRN,    _______,       _______,      _______,    _______ ,  _______\
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |  ``` |      |      |   7  |   8  |   9  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   4  |   5  |   6  |  +   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RST  |      |      |      |      |             |      |   0  |   /  |  *   |  #   |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       TRIPE_TICKS,    KC_6,      KC_BSPC,     KC_7,        KC_8,         KC_9,       KC_MINS, \
  KC_DEL,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,          KC_F6,     KC_BSLS,     KC_4,        KC_5,         KC_6,       KC_PLUS, \
  _______,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,         KC_F12,    _______,     KC_1,        KC_2,         KC_3,       KC_ENTER, \
  RESET  ,    _______,    _______,    _______,    _______,    _______,        _______,   _______,     KC_0,        KC_SLASH,     KC_PAST,    ES_HASH \
)
};

void dance_brace_finished (qk_tap_dance_state_t *state, void *user_data, bool left) {
    register_code(KC_RALT);
  if (state->count == 1) {
    left ? register_code(KC_LBRC) : register_code(ES_PLUS);// [
  } else {
    left ? register_code(KC_QUOT) : register_code(ES_CCED);// {
  }
}

void dance_brace_reset (qk_tap_dance_state_t *state, void *user_data,bool left) {
    unregister_code(KC_RALT);
  if (state->count == 1) {
    left ? unregister_code(KC_LBRC) : unregister_code(ES_PLUS);// [
  } else {
    left ? unregister_code(KC_QUOT) : unregister_code(ES_CCED);// {
  }
}

void dance_left_brace_finished (qk_tap_dance_state_t *state, void *user_data) {
  dance_brace_finished(state,user_data,true);
}
void dance_left_brace_reset (qk_tap_dance_state_t *state, void *user_data) {
dance_brace_reset(state,user_data,true);
}

void dance_right_brace_finished (qk_tap_dance_state_t *state, void *user_data) {
  dance_brace_finished(state,user_data,false);
}
void dance_right_brace_reset (qk_tap_dance_state_t *state, void *user_data) {
dance_brace_reset(state,user_data,false);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRACES] = ACTION_TAP_DANCE_FN_ADVANCED (NULL,dance_left_brace_finished,dance_left_brace_reset),
    [TD_RBRACES] = ACTION_TAP_DANCE_FN_ADVANCED (NULL,dance_right_brace_finished,dance_right_brace_reset),
    [DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_COMM)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  keyevent_t event = record->event;
  if (event.pressed)
  {
    switch (keycode)
    {
    case TRIPE_TICKS:
      SEND_STRING("[[[ ");
      return false;
      break;
    }
  }
  return true;
}
