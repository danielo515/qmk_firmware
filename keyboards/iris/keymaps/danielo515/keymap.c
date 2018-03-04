#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_spanish.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR OSL(_LOWER)
#define KC_RASE OSL(_RAISE)
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_ALT OSM(MOD_LALT)
#define KC_CTL OSM(MOD_LCTL)
#undef KC_SCLN
#undef KC_AT
#undef KC_PIPE
#define KC_SCLN ES_SCLN
#define KC_AT ES_AT
#define KC_EQUO ES_QUOT
#define KC_PIPE ES_PIPE
#define KC_ESLS ES_SLSH
#define KC_SFT OSM(MOD_LSFT)
#define KC_LENT LT(_RAISE,KC_ENT)
#define KC_BKSP MT(MOD_LSFT,KC_BSPC)
#define KC_ACUT ES_ACUT
#undef KC_BSLS
#define KC_BSLS ES_BSLS
#undef KC_LPRN
#define KC_LPRN ES_LPRN
#undef KC_RPRN
#define KC_RPRN ES_RPRN
#undef KC_LCBR
#define KC_LCBR ES_LCBR
#undef KC_RCBR
#define KC_RCBR ES_RCBR
#undef KC_HASH
#define KC_HASH ES_HASH
#define KC_EPLUS ES_PLUS
#define KC_EMINS ES_MINS
#define KC_ELBR ES_LBRC
#define KC_ERBR ES_RBRC
#define KC_ECIRC ES_CIRC
#define KC_E_QUES ES_QUES
#define KC_E_IQUE ES_IQUE
#define KC_E_AST ES_ASTR
#define KC_E_AMP ES_AMPR
#define KC_T_LEFT TD(LEFT_HOME)
#define KC_T_RIGHT TD(RIGHT_END)
#define KC_T_J TD(J_ENT)
#define KC_T_RGT TD(RGT_HOME)
#undef KC_APOS
#define KC_APOS ES_APOS
//Tap Dance Declarations
enum td_enum {
  LEFT_HOME = 0,
  UP_ALT,
  J_ENT,
  RGT_HOME,
};
//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
  [RGT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END),
  [UP_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_UP, RALT(KC_UP)), // Tap once for 2tap twice for 5
  [J_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_J,KC_ENT), // Tap once for 3 tap twice for 6
}; // Fillers to make layering more clear



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,SCLN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LGUI, A  , S  , D  , F  , G  ,                H  ,T_J , K  , L  ,ACUT,APOS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SFT, Z  , X  , C  , V  , B  ,ESC ,      LENT, N  , M   ,COMM,DOT ,ESLS,BSLS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       CTL,LOWR,BKSP ,         SPC ,RASE,ALT
  //                  `----+----+----'        `----+----+----'
  ),
  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.               ,-----+----+----+-----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,                CIRC, AMPR,ASTR, LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|               |-----+----+----+-----+----+----|
     RST , 1  , 2  , 3  , 4  , 5  ,                E_AST,ELBR,ERBR,     , 0  ,    ,
  //|----+----+----+----+----+----|               |-----+----+----+-----+----+----|
     DEL ,MUTE,LEFT,RGHT, UP ,ELBR,                E_AMP,LPRN,RPRN,COMM ,EPLUS,PIPE,
  //|----+----+----+----+----+----+----.    ,-----|-----+----+----+-----+----+----|
     BL_S,    ,    ,    ,DOWN,    ,LPRN,    E_IQUE,E_QUES,LCBR,RCBR,DOT ,EMINS,    ,
  //`----+----+----+--+-+----+----+----/    \-----+-----+----+----+-----+----+----'
                           ,    ,DEL ,         DEL ,DOT, P0
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.                ,-----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                 F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|                |-----+----+----+----+----+----|
         ,EXLM,EQUO,HASH,PERC,UNDS,                 ECIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|                |-----+----+----+----+----+----|
         , AT ,DLR,VOLU, EQL ,TILD,                 T_LEFT,DOWN, UP ,RGHT,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,------|-----+----+----+----+----+----|
     MUTE,MSTP,MPLY,VOLD,PGDN,EMINS,    ,   E_IQUE ,E_QUES,END ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \------+-----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RESET  , DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_STEP, _______, _______, _______, _______, _______, _______,         _______ , _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )
/* [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.               ,-----+----+----+-----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC, AMPR,ASTR, LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|              |-----+----+----+-----+----+----|
     RST , 1  , 2  , 3  , 4  , 5  ,                 6  , 7  , 8  , 9   , 0  ,    ,
  //|----+----+----+----+----+----|              |-----+----+----+-----+----+----|
     DEL ,MUTE,LEFT,RGHT, UP ,ELBR,               ERBR , P4 , P5 , P6  ,EPLUS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|-----+----+----+-----+----+----|
     BL_S,    ,    ,    ,DOWN,LCBR,LPRN,     RPRN,RCBR, P1 , P2 ,  P3 , EMINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+-----+----+----+-----+----+----'
                           ,    ,DEL ,         DEL ,DOT, P0
  //                  `----+----+----'        `----+----+----'
  ),
 */

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
