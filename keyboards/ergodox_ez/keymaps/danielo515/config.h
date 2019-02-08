/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#undef TAPPING_TERM
#define TAPPING_TERM 250

#define ONESHOT_TAP_TOGGLE 2

#define RGBLIGHT_SLEEP

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 50

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 60

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA


#undef  LEADER_TIMEOUT
#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING
