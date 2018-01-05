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
#define _VSC  3
#define _MOUSE  4
#define _MARKDOWN  5
#define _F  6
#define _D  7
#define _A  8
#define _S  9
#define _J  10
#define _K  11

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TRIPE_TICKS,
  T_TERM,
  FIX_ALL,
  BLK_COMMENT,
  LINE_COMMENT,
  MAC_TGL,
  CMD_SHIFT_P,
};

enum tap_dance {
  TD_LBRACES=0,
  TD_RBRACES,
  DOT_COMM
};


#define MOUSE_UP KC_MS_UP
#define MOUSE_DOWN KC_MS_DOWN
#define MOUSE_LEFT KC_MS_LEFT
#define MOUSE_RIGHT KC_MS_RIGHT
#define CLICK KC_MS_BTN1
#define RCLICK KC_MS_BTN2
#define WHEEL_UP KC_MS_WH_UP
#define ALT_TAB LALT(KC_TAB)
#define ALT_F4 LALT(KC_F4)
#define WHEEL_DOWN KC_MS_WH_DOWN
#define FN_F LT(_F,KC_F)
#define FN_D LT(_D,KC_D)
#define FN_S LT(_S,KC_S)
#define FN_A LT(_A,KC_A)
#define FN_K LT(_K,KC_K)
#define FN_J LT(_J,KC_J)
#define SFT_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //
/* Qwerty
 * ,----------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * |  Esc    |      Q      |      W     |       E      |      R            |       T      |     |       |         Y      |      U      |     I    |     O    |      P     |
 * +---------+-------------+------------+--------------+-------------------+--------------+-------------+----------------+-------------+----------+----------+------------|
 * |  Tab    |      A      |      S     |       D      |      F            |       G      |   Enter     |         H      |      J      |     K    |     L    |      ´     |
 * +---------+-------------+------------+--------------+-------------------+--------------+-------------+----------------+-------------+----------+----------+------------|
 * |    {    |      Z      |      X     |       C      |      V            |       B      |     }       |         N      |      M      |    ,     |    UP    |      Ñ     |
 * +---------+-------------+------------+--------------+-------------------+--------------+-------------+----------------+-------------+----------+----------+------------|
 * |   GUI   |    Ctrl     |    ALT     |   Raise  /   |     Bksp          |        . :   |     ' ?     |    Space/Sft   |    Lower    |   Left   |   Down   |    Right   |
 * `----------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
 KC_ESCAPE,       KC_Q,          KC_W,           KC_E,                   LT(_MOUSE,KC_R),   KC_T,           ES_PIPE,              KC_Y,           KC_U,           KC_I,      KC_O,        KC_P    ,  \
 KC_TAB,          FN_A,          FN_S,           FN_D,                   FN_F,              KC_G,           KC_ENT,               KC_H,           FN_J,           FN_K,      KC_L,        ES_ACUT ,  \
 TD(TD_LBRACES),  KC_Z,          KC_X,           KC_C,                   LT(_VSC, KC_V),    KC_B,           TD(TD_RBRACES),       KC_N,           KC_M,           KC_COMMA,  ES_APOS,     KC_SCLN ,  \
 OSM(MOD_RGUI),   OSM(MOD_LCTL), OSM(MOD_LALT),  LT(_RAISE, KC_KP_SLASH), SFT_T(KC_BSPC),   KC_DOT ,        OSL(_LOWER),          SFT_SPC,    KC_LEFT,        KC_DOWN,   KC_UP,       KC_RGHT    \
),
/* Lower
 * ,-----------+-----------------------------------------------------------------------------------------------------------------------------------------.
 * |     %     |   ª    |    !   |     "     |      #     |      $     |    &     |       /        |       (        |     ~      |      =     |    Bksp   |
 * |-----------+--------+--------+-----------+------------+------------+----------+----------------+----------------+------------+------------+-----------|
 * |    -      |   @    |   *    |    $      |     &      |     -      |    _     |      HOME      |       [        |     ]      |     +      |     Ç     |
 * |-----------+--------+--------+-----------+------------+------------+----------+----------------+----------------+------------+------------+-----------|
 * |    [      | ctl+z  |   F7   |  Ctrl+C   |   Ctrl+V   |     F12    |    ]     |      >         |        ^       |            |            |           |
 * |-----------+--------+--------+-----------+------------+------------+----------+----------------+----------------+------------+------------+-----------|
 * |     (     |        |        |           |            |            |    )     |                |                |            |            |           |
 * `-----------------------------------------------------------------------------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_PERC,    KC_TILD,       KC_EXLM,    KC_AT,        ES_HASH,        KC_DLR,     KC_CIRC,    KC_AMPR,        KC_ASTR      ,   ALGR(KC_4),  KC_RPRN,   KC_BSPC, \
  ES_MINS,    ES_AT,         KC_PAST,    KC_DLR,       ES_AMPR,        ES_MINS,    ES_UNDS,    KC_HOME,       ES_LBRC       ,   ES_RBRC,     ES_PLUS,   KC_PIPE, \
  ES_LBRC,    LCTL(KC_Z),    KC_F7,      LCTL(KC_C),   LCTL(KC_V),     KC_F12,     ES_RBRC,    S(KC_NUBS),    S(KC_LBRACKET),   _______,     _______,   _______, \
  ES_LPRN,    _______,       _______,    _______,      _______,        ES_COLN,    _______,    _______,       KC_HOME       ,   KC_END,      _______ ,  _______\
),

/* Raise
 * ,-------------------------------------------------------------------------------------------------------------------------------------------.
 * |    º    |    1     |    2     |   3      |    4     |      ```      |    6     |              |     7    |     8    |     9    |   Bksp   |
 * |---------+----------+----------+----------+----------+--------------------------+--------------+----------+----------+----------+----------|
 * |   Del   |    F1    |    F2    |    F3    |    F4    |      F5       |    F6    |    HOME      |     4    |     5    |     6    |    -     |
 * |---------+----------+----------+----------+----------+---------------|----------+--------------+----------+----------+----------+----------|
 * |         |    F7    |    F8    |    F9    |    F10   |      F11      |    F12   |     <        |     1    |     2    |     3    |    +     |
 * |---------+----------+----------+----------+----------+---------------+----------+--------------+----------+----------+----------+----------|
 * |   RST   |          |          |          |          |               |    ;     |      ,       |     0    |     /    |    *     |    .     |
 * `-------------------------------------------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       TRIPE_TICKS,    KC_6,      KC_BSPC,     KC_7,        KC_8,         KC_9,       KC_BSPC, \
  KC_DEL,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,          KC_F6,     KC_HOME,     KC_4,        KC_5,         KC_6,       ES_MINS, \
  _______,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,         KC_F12,    KC_NUBS,     KC_1,        KC_2,         KC_3,       KC_KP_PLUS, \
  RESET  ,    _______,    _______,    _______,    _______,    _______,        ES_SCLN,   KC_COMMA,     KC_0,        KC_SLASH,     KC_PAST,    KC_DOT \
),
/* TEMPLATE
 * ,---------------------------------------------------------------------------------------------------------------------------------------------------.
 * |           |          |          |             |    T_TERM     |           |           |           |           |           |           |CMD_SHIFT_P|
 * |-----------+----------+----------+-------------+---------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |           |          |          |   FIX_ALL   |               |           |           |           |           |           |LINE_COMMNT|           |
 * |-----------+----------+----------+-------------+---------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |           |          |          |             |  BLK_COMMENT  |           |           |           |           |           |           |           |
 * |-----------+----------+----------+-------------+---------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |  MAC MOD  |          |          |             |               |           |           |           |           |           |           |           |
 * `---------------------------------------------------------------------------------------------------------------------------------------------------'
 */
[_VSC] = KEYMAP( \
  _______ ,      _______,   _______,   _______,    T_TERM     ,    _______,    _______,   _______,     _______,     _______,      _______     ,  CMD_SHIFT_P, \
  _______ ,      _______,   _______,   FIX_ALL,    _______    ,    _______,    _______,   _______,     KC_LSPO,     KC_RSPC,      LINE_COMMENT,  _______    , \
  _______ ,      _______,   _______,   _______,    _______    , BLK_COMMENT, _______,   _______,     _______,     _______,      _______     ,  _______    , \
  MAC_TGL ,      _______,   _______,   _______,    _______    ,    _______,    _______,   _______,     _______,     _______,      _______     ,  _______ \
),
/* MOUSE
 * ,--------------------------------------------------------------------------------------------------------------------------------------------.
 * |         |          |           |           |           |           |           |           |           |           |   UP      |           |
 * |---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |         |          |           |           |           |           |           |           |   CLICK   |   LEFT    |   DOWN    |   RIGHT   |
 * |---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |         |          |           |           |           |           |           |           |           |           |           |           |
 * |---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |         |          |           |           |           |           |           |           |           |           |           |           |
 * `--------------------------------------------------------------------------------------------------------------------------------------------'
 */
  [_MOUSE] = KEYMAP( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     WHEEL_UP,      MOUSE_UP,   WHEEL_DOWN , \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     CLICK,     MOUSE_LEFT,   MOUSE_DOWN,    MOUSE_RIGHT, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______ \
)
/* FUNCTION F
 *,------------------------------------------------------------------------------------------------------------------------------------------.
 *|          |       |          |           |           |           |            |           |           |           |           | BACKSPACE |
 *|----------+-------+----------+-----------+-----------+-----------+------------+-----------+-----------+-----------+-----------+-----------|
 *|          |  a    |    s     |     d     |      f    |     g     |            |   LEFT    |   UP      |    DOWN   |   RIGHT   |           |
 *|----------+-------+----------+-----------+-----------+-----------+------------+-----------+-----------+-----------+-----------+-----------|
 *|          |       |          |           |           |           |            |           |           |           |           |           |
 *|----------+-------+----------+-----------+-----------+-----------+------------+-----------+-----------+-----------+-----------+-----------|
 *|          |       |          |           |           |           |            |           |           |           |           |           |
 *`------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_F] = KEYMAP( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     KC_F5  ,     KC_F12 ,      _______,    KC_BSPC, \
  KC_DEL ,    KC_DEL ,    _______,    _______,    _______,    _______,    _______,   KC_LEFT,     KC_UP,       KC_DOWN,     KC_RIGHT,    KC_END, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______  \
)
/* Digits
 * ,----------------------------------------------------------------------------------------------------------------------------------------.
 * |    º    |    1     |    2     |   3      |    4     |               |    6     |      7    |     7    |     8    |     9    |   Bksp   |
 * |---------+----------+----------+----------+----------+--------------------------+-----------+----------+----------+----------+----------|
 * |         |          |          |          |          |               |          |     \     |     4    |     5    |     6    |    -     |
 * |---------+----------+----------+----------+----------+---------------|----------+-----------+----------+----------+----------+----------|
 * |         |          |          |          |          |               |          |      .    |     1    |     2    |     3    |    +     |
 * |---------+----------+----------+----------+----------+---------------+----------+-----------+----------+----------+----------+----------|
 * |         |          |          |          |          |               |          |      0    |     0    |     /    |    *     |    .     |
 * `----------------------------------------------------------------------------------------------------------------------------------------'
 */
,[_D] = KEYMAP( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       _______,    KC_6   ,       KC_7   ,    KC_7,        KC_8,         KC_9,       KC_BSPC, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,       ES_BSLS,    KC_4,        KC_5,         KC_6,       ES_MINS, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,       KC_DOT ,    KC_1,        KC_2,         KC_3,       KC_KP_PLUS, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,       KC_0,       KC_0,        KC_SLASH,     KC_PAST,    KC_DOT \
)
/* TEMPLATE
 *,--------------------------------------------------------------------------------------------------------------------------------------------.
 *|           |         |          |           |           |           |           |           |           |           |           |           |
 *|-----------+---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|           |     a   |    s     |     d     |    f      |     g     |           |           |           |           |           |           |
 *|-----------+---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|           |         |          |           |           |           |           |           |           |           |           |           |
 *|-----------+---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|           |         |          |           |           |           |           |           |           |           |           |           |
 *`--------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_A] = KEYMAP( \
  _______,    _______,    _______,    _______,    _______,        ALT_F4 ,    _______,    _______,   _______,     _______,     _______,    _______,   \
  _______,    _______,    _______,    _______,    ALT_TAB,        _______,    _______,    _______,   _______,     _______,     _______,    _______,   \
  _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,   _______,     _______,     _______,    _______, \
  _______,    _______,    _______,    _______,    _______,        _______,    _______,    _______,   _______,     _______,     _______,    _______  \
  )
/* SIMBOL
 *,--------------------------------------------------------------------------------------------------------------------------------------------.
 *|         |          |     "     |           |           |           |           |      <    |     >     |     _     |     -     |     |     |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|   a     |          |    d      |      f    |      g    |           |           |      [    |     (     |     )     |     ]     |    Ñ      |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |      ?    |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |     :     |           |     ;     |           |           |           |           |
 *`--------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_S] = KEYMAP( \
  _______,    _______,    ES_QUOT,    _______,    _______,    _______,    _______,    KC_NUBS   ,  S(KC_NUBS) , ES_UNDS ,     ES_MINS  ,     ES_PIPE,   \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    ES_LBRC   ,  ES_LPRN    , ES_RPRN ,     ES_RBRC  ,     KC_SCLN,   \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    ES_QUES   ,  _______    , _______ ,      _______ ,    _______, \
  _______,    _______,    _______,    _______,    _______,    S(KC_DOT),  ES_SCLN,    _______   ,  _______    , _______ ,      _______ ,    _______  \
  )
/* TEMPLATE
 *,--------------------------------------------------------------------------------------------------------------------------------------------.
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *`--------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_K] = KEYMAP( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______  \
  )
/* TEMPLATE
 *,--------------------------------------------------------------------------------------------------------------------------------------------.
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *`--------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_J] = KEYMAP( \
  _______,         _______,    _______,    _______,      _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  LCTL(KC_A) ,    LCTL(KC_S),  LCTL(KC_D), LCTL(KC_F),   _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  LCTL(KC_Z) ,    LCTL(KC_X),  LCTL(KC_C), LCTL(KC_V),    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  _______,         _______,    _______,    _______,      _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______  \
  )
/* TEMPLATE
 *,--------------------------------------------------------------------------------------------------------------------------------------------.
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *`--------------------------------------------------------------------------------------------------------------------------------------------'
 *
  [_VSC] = KEYMAP( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______
)*/
};

// tap dance declarations
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

void dance_brace_each( qk_tap_dance_state_t *state, void *user_data){
  if(state->count > 1) reset_tap_dance(state);
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
    [TD_LBRACES] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_brace_each , dance_left_brace_finished,dance_left_brace_reset,300),
    [TD_RBRACES] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_brace_each , dance_right_brace_finished,dance_right_brace_reset,500),
    [DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_COMM)
};


// VSCODE shortcuts

bool on_mac = false;

bool cmd_shift_p (bool isMac) {
   isMac
   ? SEND_STRING(SS_DOWN(X_LSHIFT)SS_LGUI("p")SS_UP(X_LSHIFT))
   : SEND_STRING(SS_DOWN(X_LSHIFT)SS_LCTRL("p")SS_UP(X_LSHIFT));
   return false;
 }

bool VSCommand(bool isMac, char *cmd)
{
  cmd_shift_p(isMac);
  send_string(cmd);
  _delay_ms(10);
  SEND_STRING(SS_TAP(X_ENTER));
  return false;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      register_code(KC_S);
      unregister_code(KC_S);
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_H);
      unregister_code(KC_H);
    }
    SEQ_THREE_KEYS(KC_A, KC_S, KC_D) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}

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
    case T_TERM:
      //return VSCommand(on_mac, "tointerm");
      cmd_shift_p(on_mac);
      SEND_STRING("togit"SS_TAP(X_ENTER));
      return false;
      break;
    case FIX_ALL:
      return VSCommand(on_mac, "fixauto");
      break;
    case BLK_COMMENT:
      return VSCommand(on_mac, "blocom");
      break;
    case LINE_COMMENT:
      return VSCommand(on_mac, "tolic");
      break;
    case CMD_SHIFT_P:
      return cmd_shift_p(on_mac);
      break;
    case MAC_TGL:
      on_mac = !on_mac;
      return false;
      break;
    }
  }
  return true;
}
