#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define KC_E_COLN LSFT(KC_DOT)
#define KC_E_EQL ES_EQL
#define KC_GUI OSM(MOD_RGUI)
#define KC_R_NUB S(KC_NUBS)
#define KC_E_LT KC_NUBS
#define KC_E_GT S(KC_NUBS)
#define KC_E_TILD ES_TILD
#define KC_E_MINS ES_MINS
#define KC_S_SPC SFT_T(KC_SPC)  // Tap for Space, hold for Shift

#define TAP(keycode) register_code16(keycode); unregister_code16(keycode)

#define ACTION_TAP_DANCE_DOUBLE_SAFE(kc1, kc2) { \
    .fn = { NULL, qk_tap_dance_pair_finished_safe, qk_tap_dance_pair_reset_safe }, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),  \
  }


//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc.
};

int cur_dance (qk_tap_dance_state_t *state);

void qk_tap_dance_pair_finished_safe(qk_tap_dance_state_t *state, void *user_data);
void qk_tap_dance_pair_reset_safe(qk_tap_dance_state_t *state, void *user_data);

#endif
