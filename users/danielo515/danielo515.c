#include "danielo515.h"


//**************** Definitions needed for quad function to work *********************//

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
};

//**************** Definitions needed for quad function to work *********************//

void qk_tap_dance_pair_finished_safe(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->count == 1) {
    register_code16 (pair->kc1);
  } else if (state->count == 2) {
    if (state->interrupted){
      TAP(pair->kc1);register_code16 (pair->kc1);
      state->count = 1; // Reset the counter as we are using the first key
    } else register_code16 (pair->kc2);
  }
};

void qk_tap_dance_pair_reset_safe(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;

  if (state->count == 1) {
    unregister_code16 (pair->kc1);
  } else if (state->count == 2) {
    unregister_code16 (pair->kc2);
  }
};

//**************** Tap dance functions *********************//

qk_tap_dance_action_t tap_dance_actions[] = {
  [COPY_CUT] = ACTION_TAP_DANCE_FN(td_copy_cut),
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
};

void td_copy_cut (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    SEND_STRING(SS_LCTRL("x"));
  }
  else {
    SEND_STRING(SS_LCTRL("c"));
  }
  reset_tap_dance (state);
};
