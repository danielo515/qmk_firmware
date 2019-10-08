#pragma once

#define IGNORE_MOD_TAP_INTERRUPT
// Timeout settings for leader key
#undef  LEADER_TIMEOUT
#define LEADER_TIMEOUT 350
#define LEADER_PER_KEY_TIMING

// Memory saving
#undef NO_DEBUG
#define NO_DEBUG
#undef NO_PRINT
#define NO_PRINT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#undef RGBLIGHT_ANIMATIONS
