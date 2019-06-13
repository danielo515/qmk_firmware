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
#include "danielo515.h"

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
  TRIPE_TICKS,
  T_TERM,
  FIX_ALL,
  BLK_COMMENT,
  LINE_COMMENT,
  MAC_TGL,
  CMD_SHIFT_P,
  BRACES,
  ARROW,
  COPY,
  CUT,
  PASTE
};

enum tap_dance {
  _TD_LBRACES=0,
  TD_RBRACES,
  TD_J_ENTER,
  _D_H_DASH,
  DOT_COMM,
  TD_FIVE_COMM,
  TD_N_QUES,
  _TD_COPY,
  _TD_CUT,
  TD_DBL(G, ES_EQL),
  TD_DBL(M, KC_ENT),
  V_TAP_DANCE
};

#define rgblight_set_blue        rgblight_sethsv (0xFF,  0xFF, 0xFF);
#define rgblight_set_red         rgblight_sethsv (0x00,  0xFF, 0xFF);
#define rgblight_set_green       rgblight_sethsv (0x78,  0xFF, 0xFF);
#define rgblight_set_orange      rgblight_sethsv (0x1E,  0xFF, 0xFF);
#define rgblight_set_teal        rgblight_sethsv (0xB4,  0xFF, 0xFF);
#define rgblight_set_magenta     rgblight_sethsv (0x12C, 0xFF, 0xFF);
#define rgblight_set_yellow      rgblight_sethsv (0x3C,  0xFF, 0xFF);
#define rgblight_set_purple      rgblight_sethsv (0x10E, 0xFF, 0xFF);
#define rgblight_set_white       rgblight_sethsv (0x00,  0x00, 0xFF);

#define MOUSE_UP KC_MS_UP
#define MOUSE_DOWN KC_MS_DOWN
#define MOUSE_LEFT KC_MS_LEFT
#define MOUSE_RIGHT KC_MS_RIGHT
#define CLICK KC_MS_BTN1
#define RCLICK KC_MS_BTN2
#define WHEEL_UP KC_MS_WH_UP
#define WHEEL_DOWN KC_MS_WH_DOWN
#define ALT_TAB LALT(KC_TAB)
#define ALT_F4 LALT(KC_F4)

// Function letters
#define FN_F LT(_F,KC_F)
#define FN_D LT(_D,KC_D)
#define FN_S LT(_S,KC_S)
#define FN_A LT(_A,KC_A)
#define FN_K LT(_K,KC_K)
#define FN_J LT(_J,KC_J)
#define FN_V LT(_VSC,KC_V)
#define FN_R LT(_MOUSE,KC_R)
// Hold/shot  keys
#define S_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift
#define S_BKSP SFT_T(KC_BSPC)  // Tap for Backspace, hold for Shift
#define LEFT_ALT ALT_T(KC_LEFT)
// One shot guys
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_RGUI)
#define OSLOWER OSL(_LOWER)
#define OSRAISE OSL(_RAISE)
#define R_NUB S(KC_NUBS)
#define OS_SFT OSM(MOD_LSFT)
#define TAP_LBRACE TAP_WITH_MOD(KC_RALT,KC_LBRACKET);
#define TAP_LCBRACE TAP_WITH_MOD(KC_RALT,KC_QUOT);
// Tap dance key codes
#define TD_COMM TD(DOT_COMM)
#define TD_H_DASH TD(_D_H_DASH)
#define TD_J_ENT TD(TD_J_ENTER)
#define FIVE_COMM TD(TD_FIVE_COMM)
#define N_QUES TD(TD_N_QUES)
#define TD_LBRACES TD(_TD_LBRACES)
#define TD_COPY TD(_TD_COPY)
#define TD_PASTE TD(_TD_PASTE)
#define TD_G_EQL TD_DBL_NAM(G, ES_EQL)
#define TD_M_CBR TD_DBL_NAM(M, KC_ENT)
#define TD_V TD(V_TAP_DANCE)
#define TD_X TD(_TD_CUT)


bool on_mac = false;

bool CMD(uint16_t kc) {
  if(on_mac){ TAP(LGUI(kc)); } else { TAP(LCTL(kc)); }
  return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  | H/ENT|   J  |   K  |   L  |   Ñ  |  ´   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | N/?  |  M{  |   ,  |   .  |   '  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  | Ctrl | Alt  |  Up  |Raise | Bksp |Space |Lower |Left  |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,     FN_R,      KC_T,         KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_LEAD,\
  KC_TAB,  FN_A,    FN_S,    FN_D,     FN_F,      TD_G_EQL,     TD_H_DASH,  FN_J,    FN_K,    KC_L,    KC_SCLN, ES_ACUT,\
  OS_SFT , KC_Z,    TD_X,   TD_COPY,   TD_V,      KC_B,         N_QUES,    TD_M_CBR,    TD_COMM, KC_DOT,  ES_APOS, KC_ENT,\
  KC_RGUI, OS_CTL,  OS_ALT,  KC_UP,    OSRAISE,   S_BKSP,       S_SPC,   OSLOWER,   LEFT_ALT, KC_DOWN, KC_UP,   KC_RIGHT \
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ª  |  !   |   !  |   "  |   #  |   %  |   &  |   \  |   +  |   (  |   €  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   @  |   $  |   *  |   &  |   =  |   -  |   _  |   {  |   }  |   /  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Prev | Play | Next |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RESET|      | Home |  End |      |  Del |  Ins |      | PgUp | PgDN |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_EXLM, KC_AT,   ES_HASH, KC_PERC, ES_CIRC, ES_BSLS, ES_PLUS, ES_LPRN, ES_IQUE, _______,\
  KC_CAPS, ES_AT,   KC_DLR,  KC_PAST, ES_AMPR, ES_EQL, ES_MINS, ES_UNDS, ES_LCBR, ES_RCBR, KC_AMPR, ES_PIPE,\
  _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, ES_APOS, _______, _______, _______, _______,\
  RESET  , _______, KC_HOME, KC_END,  _______, KC_DEL,  KC_INS,  _______, KC_PGUP, KC_PGDN, _______, _______\
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   º  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      | Mute | Vol- | Vol+ |      |   =  |   4  |   5  |   6  |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Prev | Play | Next |      |   ¿  |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home |  End |      |      |  Ins |      | PgUp | PgDN |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,  KC_8, KC_9,    KC_0,    _______ ,\
  KC_CAPS, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, ES_EQL,  KC_4,  KC_5, KC_6, _______, ES_BSLS ,\
  _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, ES_IQUE, KC_1,  KC_2, KC_3, _______, _______ ,\
  _______, _______, KC_HOME, KC_END,  _______, _______,  KC_INS,  _______, KC_PGUP, KC_PGDN, _______, _______ \
),
/* TEMPLATE
 * ,---------------------------------------------------------------------------------------------------------------------------------------------------.
 * |           |          |          |             |               |   T_TERM  |           |           |           |           |CMD_SHIFT_P|           |
 * |-----------+----------+----------+-------------+---------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |           |          |          |             |    FIX_ALL    |           |           |           |           |           |LINE_COMMNT|           |
 * |-----------+----------+----------+-------------+---------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |           |          |          |             |      v        |BLK_COMMENT|           |           |           |           |           |           |
 * |-----------+----------+----------+-------------+---------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 * |  MAC MOD  |          |          |             |               |           |           |           |           |           |           |           |
 * `---------------------------------------------------------------------------------------------------------------------------------------------------'
 */
[_VSC] = KEYMAP( \
  _______ ,      _______,   _______,   _______,    _______    ,    T_TERM,    _______,   _______,     _______,     _______,      CMD_SHIFT_P ,  _______, \
  _______ ,      _______,   _______,   _______    ,FIX_ALL    ,   _______,    _______,   _______,     KC_LSPO,     LINE_COMMENT,      LINE_COMMENT,  _______    , \
  _______ ,      _______,   _______,   _______,    _______    , BLK_COMMENT, _______,   _______,     _______,     _______,      _______     ,  _______    , \
  MAC_TGL ,      _______,   _______,   _______,    _______    ,    _______,    _______,   _______,     _______,     _______,      _______     ,  _______ \
),
/* MOUSE
 * ,-----------------------------------------------------------------------------------------------------------------------------------.
 * |         |          |           |           |           |           |        |           |   UP      |          |            |     |
 * |---------+----------+-----------+-----------+-----------+-----------+--------+-----------+-----------+----------+------------+-----|
 * |         |          |           |           |           |           |CLICK   |   LEFT    |   DOWN    |   RIGHT  |            |     |
 * |---------+----------+-----------+-----------+-----------+-----------+--------+-----------+-----------+----------+------------+-----|
 * |         |          |           |           |           |           |        |           |           |          |            |     |
 * |---------+----------+-----------+-----------+-----------+-----------+--------+-----------+-----------+----------+------------+-----|
 * |         |          |           |           |           |           |        |           |           |          |            |     |
 * `-----------------------------------------------------------------------------------------------------------------------------------'
 */
  [_MOUSE] = KEYMAP( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,     WHEEL_UP,      MOUSE_UP,      WHEEL_DOWN ,   _______,      _______,     \
  _______,    _______,    _______,    _______,    _______,    _______,    CLICK,       MOUSE_LEFT,    MOUSE_DOWN,    MOUSE_RIGHT,   _______,      _______,     \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,     WHEEL_DOWN,    _______,        _______,      _______,      _______,     \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,       _______,        _______,       _______,      _______     \
)
/* FUNCTION F
 *,------------------------------------------------------------------------------------------------------------------------------------------.
 *|          |       |          |           |           |           |           |   F2      |    F5     |    F12    |            | BACKSPACE |
 *|----------+-------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+------------+-----------|
 *|          |  a    |    s     |     d     |      f    |     g     |   LEFT    |   UP      |    DOWN   |   RIGHT   |            |           |
 *|----------+-------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+------------+-----------|
 *|          |       |          |           |           |           |           |           |           |           |            |           |
 *|----------+-------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+------------+-----------|
 *|          |       |          |           |           |           |           |           |           |           |            |           |
 *`------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_F] = KEYMAP( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,     KC_F2,     KC_F5  ,     KC_F12 ,      _______,    KC_BSPC, \
  KC_DEL ,    KC_DEL ,    _______,    _______,    _______,    _______,    KC_LEFT,     KC_DOWN,   KC_UP  ,     KC_RIGHT,     KC_HOME ,   KC_END, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,     KC_HOME,   KC_END ,     _______,      _______,    _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,     _______,      _______,    _______  \
)
/* Digits
 * ,-----------------------------------------------------------------------------------------------------------------------------.
 * |    º    |    1     |    2     |   3    |    4   |   5    |    6     |     /     |     7    |     8    |     9    |   Bksp   |
 * |---------+----------+----------+--------+--------+--------+----------+-----------+----------+----------+----------+----------|
 * |         |          |          |        |        |        |          |     \     |     4    |     5    |     6    |    -     |
 * |---------+----------+----------+--------+--------+--------+----------+-----------+----------+----------+----------+----------|
 * |         |          |          |        |        |        |          |      .    |     1    |     2    |     3    |    +     |
 * |---------+----------+----------+--------+--------+--------+----------+-----------+----------+----------+----------+----------|
 * |         |          |          |        |        |        |          |      0    |     0    |     ,    |    *     |    .     |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
,[_D] = KEYMAP( \
  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,        ES_SLSH,    KC_7,        KC_8,         KC_9,     _______,      _______   ,  \
  _______,    _______,    _______,    _______,    _______,    _______,     ES_BSLS,    KC_4,   FIVE_COMM,         KC_6,     ES_MINS,      _______,  \
  _______,    _______,    _______,    _______,    _______,    _______,     KC_DOT ,    KC_1,        KC_2,         KC_3,     KC_KP_PLUS,   _______,  \
  _______,    _______,    _______,    _______,    _______,    _______,     KC_0,       KC_0,        KC_COMM,     KC_PAST,  KC_DOT    ,   _______  \
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
 *|         |          |           |    "      |           |           |     ^     |     [     |     ]     |     -     |     ~     |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |    '      |     =>    |           |     <     |    ([{    |     )     |     >     |     /     |     |     |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |     .,    |     ?     |     {     |    }      |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |     :     |     ;     |           |           |           |           |           |
 *`--------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_S] = KEYMAP( \
  _______,    _______,     _______,   ES_QUOT,    _______,    _______,         ES_CIRC,    ES_LBRC  ,  ES_RBRC         , ES_MINS ,     ALGR(KC_4),  _______,   \
  _______,    _______,    _______,    ES_GRV,     ARROW ,     _______,         KC_NUBS,   TD_LBRACES, TD(TD_RBRACES)  ,  R_NUB  ,     ES_SLSH   ,  ES_PIPE,   \
  _______,    _______,    _______,    _______,    _______,    TD(DOT_COMM),    ES_QUES,   ES_LCBR  ,  ES_RCBR         , KC_LCBR ,      _______  ,  _______, \
  RESET  ,    _______,    _______,    _______,    _______,    S(KC_DOT),       ES_SCLN,    _______ ,  _______         , _______ ,      _______  ,  _______  \
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
  RGB_TOG  ,           RGB_HUI,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  RGB_MODE_PLAIN,      RGB_HUD,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  _______,             RGB_SAI,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  RGB_MODE_KNIGHT,     RGB_SAD,    _______,    _______,    _______,    _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______  \
  )
/* TEMPLATE
 *,--------------------------------------------------------------------------------------------------------------------------------------------.
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |     j     |     '     |    `      |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |    CUT    |    COPY   |   PASTE   |           |           |           |           |           |           |           |
 *|---------+----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
 *|         |          |           |           |           |           |           |           |           |           |           |           |
 *`--------------------------------------------------------------------------------------------------------------------------------------------'
 */
  ,[_J] = KEYMAP( \
  _______,    _______,        LCTL(KC_W),    _______,    _______,        _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  _______,    LCTL(KC_A) ,    LCTL(KC_S),  LCTL(KC_D), LCTL(KC_F),       _______,    _______,    _______   ,     ES_APOS,     ES_GRV  ,      _______ ,    _______, \
  _______,    LCTL(KC_Z) ,    CUT       ,  COPY,       PASTE     ,       LCTL(KC_B), _______,    _______   ,     _______,     _______ ,      _______ ,    _______, \
  _______,    _______,         _______,    _______,    _______,          _______,    _______,    _______   ,     _______,     _______ ,      _______ ,    _______  \
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


void matrix_scan_user(void){};

// ===================== TAP DANCE STUFF

typedef struct {
  bool is_press_action;
  int state;
} tap;


//instanalize an instance of 'tap' for the 'x' tap dance.
static tap v_tap_state = {
  .is_press_action = true,
  .state = 0
};

void v_finished (qk_tap_dance_state_t *state, void *user_data) {
  v_tap_state.state = cur_dance(state);
  switch (v_tap_state.state) {
    case SINGLE_TAP: register_code(KC_V); break;
    case SINGLE_HOLD: layer_on(_VSC); break;
    case DOUBLE_TAP: register_code16(LCTL(KC_V)); break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_V); unregister_code(KC_V); register_code(KC_V);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void v_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (v_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_V); break;
    case SINGLE_HOLD: layer_off(_VSC); break;
    case DOUBLE_TAP: unregister_code16(LCTL(KC_V)); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_V);
  }
  v_tap_state.state = 0;
}


void dance_brace_finished (qk_tap_dance_state_t *state, void *user_data, bool left) {
  if (state->count == 1) {
    register_code(KC_LSHIFT);
    left ? register_code(KC_8) : register_code(KC_9);// [
  } else {
    register_code(KC_RALT);
      if (state->count == 2) {
        left ? register_code(KC_LBRC) : register_code(ES_PLUS);// {
      } else {
      left ? register_code(KC_QUOT) : register_code(ES_CCED);// {
    }
  }
}

void dance_brace_reset (qk_tap_dance_state_t *state, void *user_data,bool left) {
  if (state->count == 1) {
    unregister_code(KC_LSHIFT);
    left ? unregister_code(KC_8) : unregister_code(KC_9);// (
  } else {
    unregister_code(KC_RALT);
    if (state->count == 2) {
      left ? unregister_code(KC_LBRC) : unregister_code(ES_PLUS);// [
    } else {
        left ? unregister_code(KC_QUOT) : unregister_code(ES_CCED);// {
    }
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

void dance_copy (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_C);
  }
  else {
    CMD(KC_C);
  }
  reset_tap_dance (state);
}

void dance_cut (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_X);
  }
  else {
    CMD(KC_X);
  }
  reset_tap_dance (state);
}

// TAP DANCE ACTIONS ARRAY

qk_tap_dance_action_t tap_dance_actions[] = {
    [_TD_LBRACES] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL , dance_left_brace_finished,dance_left_brace_reset,300),
    [TD_RBRACES] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL , dance_right_brace_finished,dance_right_brace_reset,200),
    [TD_FIVE_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_5,KC_COMM),
    [DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM,KC_DOT),
    [TD_N_QUES] = ACTION_TAP_DANCE_DOUBLE_SAFE(KC_N,ES_QUES),
    [_D_H_DASH] = ACTION_TAP_DANCE_DOUBLE(KC_H,ES_MINS),
    [_TD_COPY] =  ACTION_TAP_DANCE_FN(dance_copy),
    [_TD_CUT] = ACTION_TAP_DANCE_FN(dance_cut),
    [V_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),
    TD_DBL_ARR(G, ES_EQL)
    TD_DBL_ARR(M, KC_ENT)
};

// VSCODE shortcuts

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
  SEND_STRING(SS_TAP(X_ENTER));
  return false;
}

bool one_shot_was_active = false;

// Runs state check and changes underglow color and animation
// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
uint32_t layer_state_set_user(uint32_t state)
{
  // uint8_t default_layer = eeconfig_read_default_layer();
  switch (biton32(state))
  {
  case _QWERTY:
    rgblight_set_blue;
    rgblight_mode(1);
    break;
  case _LOWER:
    rgblight_set_blue;
    rgblight_mode(2);
    break;

  case _RAISE:
    rgblight_set_yellow;
    rgblight_mode(1);
    break;
  case _VSC:
    rgblight_set_orange;
    rgblight_mode(17);
    break;
  case _MOUSE:
    rgblight_set_green;
    rgblight_mode(22);
    break;
  case _F:
    rgblight_set_orange;
    rgblight_mode(17);
    break;
  case _D:
    rgblight_set_red;
    rgblight_mode(5);
    break;
  case _A:
    rgblight_set_yellow;
    rgblight_mode(5);
    break;
  case _S:
    rgblight_set_orange;
    rgblight_mode(5);
    break;
  case _J:
    rgblight_set_red;
    rgblight_mode(23);
    break;
  case _K:
    rgblight_set_green;
    rgblight_mode(2);
    break;
  default:
    /*       if (default_layer & (1UL << _COLEMAK)) {
        rgblight_set_magenta;
      }
      else if (default_layer & (1UL << _DVORAK)) {
        rgblight_set_green;
      }
      else if (default_layer & (1UL << _WORKMAN)) {
        rgblight_set_purple;
      }
      else {
        rgblight_set_teal;
      } */
    rgblight_mode(1);
    break;
  }
  return state;
}

  uint16_t latest_kc = 0;
  uint16_t latest_rotation = 0;
  char key_count = 0;

  bool process_record_user(uint16_t keycode, keyrecord_t *record)
  {
    keyevent_t event = record->event;
    if (event.pressed)
    {

      if (keycode == latest_kc)
      {
        if (timer_elapsed(latest_rotation) > TAP_ROTATION_TIMEOUT) key_count = 0;
        else key_count++;
      } else {
        key_count = 0;
        latest_kc = keycode;
      }

      latest_rotation = timer_read();

      switch (keycode)
      {
          case OS_CTL:
            one_shot_was_active = true;
            rgblight_setrgb(255, 1, 25);
            break;
          case OS_ALT:
            one_shot_was_active = true;
            rgblight_setrgb(255, 255, 25);
            break;
          case TRIPE_TICKS:
            SEND_STRING("[[[ ");
            return false;
          case T_TERM: return VSCommand(on_mac, "toit");
          case FIX_ALL: return VSCommand(on_mac, "faap");
          case BLK_COMMENT: return VSCommand(on_mac, "tbc");
          case LINE_COMMENT: return VSCommand(on_mac, "tlic");
          case CMD_SHIFT_P: return cmd_shift_p(on_mac);
          case ARROW:
            if (key_count == 0)
            { TAP(ES_EQL); }
            if (key_count == 1)
            { TAP(R_NUB); }
            if (key_count == 2)
            { TAP(KC_SPC); }
            if (key_count == 3)
            { TAP_LCBRACE }
            if (key_count == 4)
            {
              TAP(KC_SPC);
              TAP_WITH_MOD(KC_RALT, KC_NUHS);
              TAP(KC_LEFT);
            }
            return false;
          case MAC_TGL:
            on_mac = !on_mac;
            rgblight_setrgb(255, 255, 0);
            return false;
          case COPY: return CMD(KC_C);
          case CUT: return CMD(KC_X);
          case PASTE: return CMD(KC_V);
          default:
            if(one_shot_was_active){
              rgblight_setrgb(255, 255, 255);
              one_shot_was_active = false;
            }
            break;
      }
    }
    return true;
  }
