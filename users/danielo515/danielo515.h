#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define ACTION_TAP_DANCE_DOUBLE_SAFE(kc1, kc2) { \
    .fn = { NULL, qk_tap_dance_pair_finished_safe, qk_tap_dance_pair_reset_safe }, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),  \
  }

#define TAP(keycode) register_code16(keycode); unregister_code16(keycode)

//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc.
};

enum tap_dance {
  COPY_CUT=0
};

int cur_dance (qk_tap_dance_state_t *state);

void qk_tap_dance_pair_finished_safe(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_pair_reset_safe(qk_tap_dance_state_t *state, void *user_data);
void td_copy_cut (qk_tap_dance_state_t *state, void *user_data);

#endif
