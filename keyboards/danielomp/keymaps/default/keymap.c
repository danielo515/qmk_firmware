#include "danielomp.h"

// Tap Dance Declarations
enum
{
  ENT_5 = 0,
  ZERO_1,
  COMMENT
};

enum custom_keycodes
{
  T_TERM = SAFE_RANGE,
  FIX_ALL,
  BLK_COMMENT,
  LINE_COMMENT,
  MAC_TGL,
  CMD_SHIFT_P,
  DBL_0
};

// Layers
enum
{
  NUMPAD = 0,
  VSC,
  RAISE
};

// Are we on a mac ?
bool on_mac = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* LAYER 0
  * ,-----------------------.
  * |   7   |   8   |   9   |
  * |-------+-------+-------|
  * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
  * |-------+-------+-------|
  * |  1/0  |   2   | 3/FN  | 1/0 = Dbl Tap 1 for 0  -  3/FN = Hold 3 for FN
  * `-----------------------'
  */
    [NUMPAD] = KEYMAP(
        KC_7,          KC_8,          KC_9,
        KC_4,          TD(ENT_5),     KC_6,
        TD(ZERO_1),    KC_2,          LT(RAISE, KC_3)),
    /* LAYER 1
  * ,--------------------------------------------.
  * |    DEL    |  Ctr+SFT+P  |       ESC        |
  * |-----------+-------------+------------------|
  * |  FIX_ALL  |  Tgl term   |Block/Line coment |
  * |-----------+-------------+------------------|
  * |  MAC_TGL  |  NUMPAD     |       ____       |
  * `--------------------------------------------'
  */
    [VSC] = KEYMAP(
        KC_DEL,   CMD_SHIFT_P,   KC_ESC,
        FIX_ALL,  T_TERM,             TD(COMMENT),
        MAC_TGL,  TO(NUMPAD),         KC_TRNS),
    /* LAYER 2
  * ,-----------------------------------.
  * |   DEL   |   BKSPACE    |   ESC    |
  * |---------+--------------+----------|
  * |   HOME  |     F5       |   END    |
  * |---------+--------------+----------|
  * |    00   |     VSC      |   ____   |
  * `-----------------------------------'
  */
    [RAISE] = KEYMAP(
        KC_DEL,    KC_BSPC,   KC_ESC,
        KC_HOME,   KC_F5,     KC_END,
        DBL_0,  TO(VSC),   KC_TRNS)

};

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

void dance_comment_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    VSCommand(on_mac, "toggle line comment");
  } else {
    VSCommand(on_mac, "toggle block comment");
  }
  reset_tap_dance (state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
    [ZERO_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_0),
    [COMMENT] = ACTION_TAP_DANCE_FN(dance_comment_finished)
  };

void matrix_init_user(void)
{
}

void matrix_scan_user(void)
{
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  keyevent_t event = record->event;
  if (event.pressed)
  {
    switch (keycode)
    {
    case DBL_0:
      SEND_STRING("00");
      return false;
      break;
    case T_TERM:
      return VSCommand(on_mac, "toggle integrated term");
      break;
    case FIX_ALL:
      return VSCommand(on_mac, "fix all auto");
      break;
    case BLK_COMMENT:
      return VSCommand(on_mac, "toggle block comment");
      break;
    case LINE_COMMENT:
      return VSCommand(on_mac, "toggle line comment");
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

void led_set_user(uint8_t usb_led)
{

  if (usb_led & (1 << USB_LED_NUM_LOCK))
  {
  }
  else
  {
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK))
  {
  }
  else
  {
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK))
  {
  }
  else
  {
  }

  if (usb_led & (1 << USB_LED_COMPOSE))
  {
  }
  else
  {
  }

  if (usb_led & (1 << USB_LED_KANA))
  {
  }
  else
  {
  }
}
