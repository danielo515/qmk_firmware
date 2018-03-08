#include "danielo515.h"

bool on_mac = false;
// Send control or GUI depending if we are on windows or mac
bool CMD(uint16_t kc) {
  if(on_mac){ TAP(LGUI(kc)); } else { TAP(LCTL(kc)); }
  return false;
}
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
}

//**************** END Definitions needed for quad function to work *********************//

//===== The awesome tap dance for CUT, COPY and PASTE
void dance_copy (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_C);
  } else if (state->interrupted)
        { TAP(KC_C);TAP(KC_C);}
         else CMD(KC_C);

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

void dance_paste (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    TAP(KC_V);
  }
  else {
    CMD(KC_V);
  }
  reset_tap_dance (state);
}

// Slightly better tap dance double: interruption sends double single and any number over double sends the single that number of times
void qk_tap_dance_pair_finished_safe(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  int count = state->count;
  if (state->count == 2) {
    if (state->interrupted){
      TAP(pair->kc1);register_code16 (pair->kc1);
      state->count = 1; // Reset the counter as we are using the first key
    } else register_code16 (pair->kc2);
    return;
  }
  register_code16 (pair->kc1);
  while(--count){
    unregister_code16(pair->kc1);
    register_code16 (pair->kc1);
  }
}

void qk_tap_dance_pair_reset_safe(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  if (state->count == 2) {
    unregister_code16 (pair->kc2);
    return;
  }
  unregister_code16(pair->kc1);
}
