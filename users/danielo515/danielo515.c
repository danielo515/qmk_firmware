#include "danielo515.h"

bool onMac = true;

//**************** Definitions needed for quad function to work *********************//
#ifdef QUAD_DANCE
int cur_dance(qk_tap_dance_state_t *state)
{
  if (state->count == 1)
  {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state->pressed == 0)
      return SINGLE_TAP;
    else
      return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2)
  {
    if (state->interrupted)
      return DOUBLE_SINGLE_TAP;
    else if (state->pressed)
      return DOUBLE_HOLD;
    else
      return DOUBLE_TAP;
  }
  else
    return 6; //magic number. At some point this method will expand to work for more presses
};

//**************** Definitions needed for quad function to work *********************//
# endif

void qk_tap_dance_pair_finished_safe(qk_tap_dance_state_t *state, void *user_data)
{
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->count == 1)
  {
    register_code16(pair->kc1);
  }
  else if (state->count == 2)
  {
    if (state->interrupted)
    {
      TAP(pair->kc1);
      register_code16(pair->kc1);
      state->count = 1; // Reset the counter as we are using the first key
    }
    else
      register_code16(pair->kc2);
  }
};

void qk_tap_dance_pair_reset_safe(qk_tap_dance_state_t *state, void *user_data)
{
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->count == 1)
  {
    unregister_code16(pair->kc1);
  }
  else if (state->count == 2)
  {
    unregister_code16(pair->kc2);
  }
};

//**************** Tap dance functions *********************//

qk_tap_dance_action_t tap_dance_actions[] = {
    [COPY_CUT] = ACTION_TAP_DANCE_FN(td_copy_cut),
    [PASTE_DANCE] = ACTION_TAP_DANCE_FN(td_paste),
    [_TD_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [_TD_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [_TD_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [_TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [_TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [_TD_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [_TD_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [_TD_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [_TD_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [_TD_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [_TD_F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
    [_TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
    [_TD_H_ENTER] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_ENT),
    [_TD_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON),
    [_TD_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BSLASH),
};

void td_copy_cut(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    onMac ?  SEND_STRING(SS_LGUI("x")) :   SEND_STRING(SS_LCTRL("x"));
  }
  else
  {
    onMac ?  SEND_STRING(SS_LGUI("c")) : SEND_STRING(SS_LCTRL("c"));
  }
  reset_tap_dance(state);
};

void td_paste(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count == 2)
  {
    onMac ?  SEND_STRING(SS_DOWN(X_RSHIFT) SS_LGUI("v") SS_UP(X_RSHIFT)) :   SEND_STRING(SS_DOWN(X_RSHIFT) SS_LCTRL("v") SS_UP(X_RSHIFT));
  }
  else
  {
    onMac ?  SEND_STRING(SS_LGUI("v")) : SEND_STRING(SS_LCTRL("v"));
  }
  reset_tap_dance(state);
};

//**************** Handle keys function *********************//
bool altPressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  // dynamically generate these.
  case EPRM:
    if (record->event.pressed)
    {
      eeconfig_init();
    }
    return false;
    break;
  case ARROW:
    if (record->event.pressed) SEND_STRING("->");
    return false;
  case F_ARROW:
    if (record->event.pressed) SEND_STRING("=>");
    return false;
  case GREP:
    if (record->event.pressed) SEND_STRING(" | grep "); return false;
  case AC_A:// Accent á
    if (record->event.pressed) SEND_STRING(SS_LALT("e") "a"); return false;
  case AC_E:// Accent é
    if (record->event.pressed) SEND_STRING(SS_LALT("e") "e"); return false;
  case AC_I:// Accent í
    if (record->event.pressed) SEND_STRING(SS_LALT("e") "i"); return false;
  case AC_O:// Accent ó
    if (record->event.pressed) SEND_STRING(SS_LALT("e") "o"); return false;
  case CUT:
    if (record->event.pressed) {
     onMac ?  SEND_STRING(SS_LGUI("x")) : SEND_STRING(SS_LCTRL("x"));
    }
    return false;
  case COPY:
    if (record->event.pressed) {
     onMac ?  SEND_STRING(SS_LGUI("c")) : SEND_STRING(SS_LCTRL("c"));
    }
    return false;
  case PASTE:
    if (record->event.pressed) {
     onMac ?  SEND_STRING(SS_LGUI("v")) : SEND_STRING(SS_LCTRL("v"));
    }
    return false;
  case SAVE:
    if (record->event.pressed) {
     onMac ?  SEND_STRING(SS_LGUI("s")) : SEND_STRING(SS_LCTRL("s"));
    }
    return false;
  case UNDO:
    if (record->event.pressed) {
     onMac ?  SEND_STRING(SS_LGUI("z")) : SEND_STRING(SS_LCTRL("z"));
    }
    return false;
  case FIND:
    if (record->event.pressed) {
     onMac ?  SEND_STRING(SS_LGUI("f")) : SEND_STRING(SS_LCTRL("f"));
    }
    return false;
  case CHG_LAYOUT:
    if (record->event.pressed) {
     onMac ?  SEND_STRING(SS_LCTRL(" ")) : SEND_STRING(SS_LCTRL("f"));
    }
    return false;
  case RGB_SLD:
    if (record->event.pressed)
    {
      rgblight_mode(1);
    }
    return false;
    break;
    //First time alt + tab, and alt stays sticky. Next press we just send tab. Any other key releases the alt
  case ALT_TAB:
    if (record->event.pressed)
    {
      if (altPressed)
      {
        tap_code(KC_TAB);
      }
      else
      {
        altPressed = true;
        layer_on(7); // go to movement layer
        onMac ? register_code(KC_LGUI) : register_code(KC_LALT);
        tap_code(KC_TAB);
      }
    }
    return false;
  // avoid alt releasing if the key is of movement
  case KC_RIGHT ... KC_UP:
    if (altPressed)
    {
      return true; // yes QMK, do your stuff
    }
  }
  // Reset sticky alt tab
  if (altPressed)
  {
    onMac ?  unregister_code(KC_LGUI) : unregister_code(KC_LALT);
    altPressed = false;
    layer_off(7);
    return false;
  }
  return true;
};

//**************** LEADER *********************//
#ifdef LEADER_ENABLE
LEADER_EXTERNS();

void leader_start() {
  rgblight_setrgb_range(5, 100, 199, 10,15);
};

void leader_end(){
  rgblight_setrgb_range(200, 200, 255, 10,15);
};

void matrix_scan_user(void)
{
  LEADER_DICTIONARY()
  {
    leading = false;
    leader_end();
    /*  ONE KEY */
    SEQ_ONE_KEY(KC_T)
    {
      SEND_STRING("``" SS_TAP(X_LEFT));
    }
    // International spanish accent vovels
    SEQ_ONE_KEY(KC_A)
    {
      SEND_STRING(SS_LALT("e") "a");
    }
    SEQ_ONE_KEY(KC_E)
    {
      SEND_STRING(SS_LALT("e") "e");
    }
    SEQ_ONE_KEY(KC_I)
    {
      SEND_STRING(SS_LALT("e") "i");
    }
    SEQ_ONE_KEY(KC_O)
    {
      SEND_STRING(SS_LALT("e") "o");
    }
    SEQ_ONE_KEY(KC_U)
    {
      SEND_STRING(SS_LALT("e") "u");
    }
    SEQ_ONE_KEY(KC_N) // ñ
    {
      SEND_STRING(SS_LALT("n") "n");
    }
    SEQ_ONE_KEY(KC_G) // grep
    {
      SEND_STRING(" | grep ");
    }
    SEQ_TWO_KEYS(KC_D, KC_G) // vim delete all
    {
      if(onMac){
        SEND_STRING(SS_LGUI("a") SS_TAP(X_D));
      } else {
        SEND_STRING(SS_LCTRL("a") SS_TAP(X_D));
      }
    }
    SEQ_TWO_KEYS(KC_F, KC_T)
    {
      SEND_STRING("feat():" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    // ### LAYER CHANGE
    SEQ_ONE_KEY(KC_1)
    {
      layer_on(1);
    }
    SEQ_ONE_KEY(KC_H) // control enter, because yes
    {
      SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_ENTER) SS_UP(X_LCTRL));
    }
    // paste all
    SEQ_ONE_KEY(KC_P)
    {
      if(onMac){
        SEND_STRING(SS_LGUI("a") SS_LGUI("v"));
      } else {
        SEND_STRING(SS_LCTRL("a") SS_LCTRL("v"));
      }
    }
    SEQ_THREE_KEYS(KC_M, KC_A, KC_C)
    {
      onMac = true;
      rgblight_setrgb(255, 255, 255);

    }
    SEQ_THREE_KEYS(KC_W, KC_I, KC_N)
    {
      onMac = false;
      rgblight_setrgb(255, 255, 0);
    }
    /*  Copy all */
    SEQ_ONE_KEY(KC_Y)
    {
      if(onMac){
        SEND_STRING(SS_LGUI("a") SS_LGUI("c"));
      } else {
        SEND_STRING(SS_LCTRL("a") SS_LCTRL("c"));
      }
    }
    //emoji bar
    SEQ_TWO_KEYS(KC_E, KC_E)
    {
      SEND_STRING(SS_DOWN(X_LGUI) SS_LCTRL(" ") SS_UP(X_LGUI));
    }

    SEQ_TWO_KEYS(KC_F, KC_F)
    {
      SEND_STRING("ps -ef | grep ");
    }
    // Triple ticks
    SEQ_TWO_KEYS(KC_T, KC_T)
    {
      SEND_STRING("```" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "```" SS_TAP(X_UP));
    }
    SEQ_TWO_KEYS(KC_H, KC_T)
    {
      SEND_STRING("https://");
    }

    leader_end();
  }
}
#endif // LEADER
