#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "danielo515.h"
#include "keymap_spanish.h"

extern keymap_config_t keymap_config;
extern bool on_mac;

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MAC_TGL
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR OSL(_LOWER)
#define KC_RASE OSL(_RAISE)
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_ALT OSM(MOD_LALT)
#define KC_CTL OSM(MOD_LCTL)
#undef KC_AT
#undef KC_PIPE
#define KC_E_SCLN ES_SCLN
#define KC_AT ES_AT
#define KC_EQUO ES_QUOT
#define KC_PIPE ES_PIPE
#define KC_ESLS ES_SLSH
#define KC_SFT OSM(MOD_LSFT)
#define KC_LENT LT(_RAISE,KC_ENT)
#define KC_BKSP SFT_T(KC_BSPC)
#define KC_ACUT ES_ACUT
#undef KC_BSLS
#define KC_BSLS LALT(KC_GRAVE)
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
#define KC_E_LBR ES_LBRC
#define KC_E_RBR ES_RBRC
#define KC_ECIRC ES_CIRC
#define KC_E_QUES ES_QUES
#define KC_E_IQUE ES_IQUE
#define KC_E_AST ES_ASTR
#define KC_E_AMP ES_AMPR
#define KC_T_LEFT TD(LEFT_HOME)
#define KC_T_RIGHT TD(RIGHT_END)
#define KC_T_J TD(J_ENT)
#define KC_T_H TD(H_MINS)
#define KC_T_RGT TD(RGT_HOME)
#undef KC_APOS
#define KC_APOS ES_APOS
#define KC_MAC_TGL MAC_TGL
#define KC_BL_TOGG BL_TOGG
//Tap Dance Declarations
enum td_enum {
  LEFT_HOME = 0,
  J_ENT,
  H_MINS,
  RGT_HOME,
  _TD_COPY,
  _TD_CUT,
};
//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
  [RGT_HOME] = ACTION_TAP_DANCE_DOUBLE_SAFE(KC_RGHT, KC_END),
  [J_ENT] = ACTION_TAP_DANCE_DOUBLE_SAFE(KC_J,KC_ENT),
  [H_MINS] = ACTION_TAP_DANCE_DOUBLE_SAFE(KC_H,KC_SLASH),
  [_TD_COPY] =  ACTION_TAP_DANCE_FN(dance_copy),
  [_TD_CUT] = ACTION_TAP_DANCE_FN(dance_cut),
}; // Fillers to make layering more clear



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,------+------+------+-----+-----+----.                      ,------+-----+-----+------+----+----.
     ESC   , 1   , 2    , 3    , 4    , 5   ,                     6    , 7    , 8  , 9    , 0   ,E_TILD,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
     GUI   , Q    , W    , E    , R   , T  ,                      Y    , U    , I  , O    , P  ,E_SCLN  ,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
     TAB   , A    , FN_S , FN_D , F   , G   ,                     T_H  , T_J  , K   , L   , APOS ,ACUT ,
  //|-----+-------+------+------+-----+-----+-----.   ,---------|------+------+-----+------+----+----|
     SFT  , Z     ,TD_CUT,TD_COPY, V  , B   ,ESC  ,       LENT  , N    , M    ,COMM ,DOT   ,ESLS,BSLS,
  //|-----+-------+------+------+-----+-----+----/     \--------|------+-----+-----+------+----+----|
                                 CTL,LOWR, BKSP ,         S_SPC , RASE ,ALT
  //                           `----+----+-----'         `------+------+----'
  ),
  [_S] = KC_KEYMAP(
  //,------+------+------+-----+-----+----.                     ,------+-----+-----+------+----+----.
    ,      ,      ,      ,     ,     ,                                 ,      ,ASTR,      ,    ,BSPC,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
           , EXLM ,      , EQUO , PERC,ECIRC,                     DLR  ,E_LBR ,E_RBR,     ,     ,    ,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
     DEL   , AT   ,      , E_AST,E_EQL,E_GT,                      E_AMP ,LPRN ,RPRN ,E_COLN,EPLUS,PIPE,
  //|-----+-------+------+------+-----+-----+-----.   ,---------|------+------+-----+------+----+----|
     BL_S,        ,      ,      ,     ,HASH ,    ,      E_IQUE  ,E_QUES,LCBR ,RCBR ,      ,    ,    ,
  //|-----+-------+------+------+-----+-----+----/     \--------|------+-----+-----+------+----+----|
                                      ,    ,DEL ,         DEL   ,      ,
  //                           `----+----+-----'         `------+------+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,------+------+------+-----+-----+----.                     ,------+-----+-----+------+----+----.
    MAC_TGL,BL_TOGG,      ,     ,     ,     ,                      CIRC ,     ,ASTR , LPRN ,RPRN,BSPC,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
           , EXLM , EQUO , HASH , PERC,ECIRC,                          ,E_LBR ,E_RBR,     ,     ,    ,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
     DEL   , AT   ,  DLR , E_AST,E_EQL,E_GT,                      E_AMP ,LPRN ,RPRN ,E_COLN,EPLUS,PIPE,
  //|-----+-------+------+------+-----+-----+-----.   ,---------|------+------+-----+------+----+----|
     BL_S,        ,      ,      ,     ,     ,    ,      E_IQUE  ,E_QUES,LCBR ,RCBR ,      ,    ,    ,
  //|-----+-------+------+------+-----+-----+----/     \--------|------+-----+-----+------+----+----|
                                      ,    ,DEL ,         DEL   ,      ,
  //                           `----+----+-----'         `------+------+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+-----+----+----.                ,-----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                   F6  , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+-----+----+----|                |-----+----+----+----+----+----|
         ,EXLM,EQUO,HASH ,PERC,ECIRC,                 PGDN,HOME,END ,LPRN,RPRN,    ,
  //|----+----+----+-----+-----+----|               |-----+----+----+----+----+----|
         , AT ,DLR ,E_AST,E_EQL,E_GT,                LEFT ,DOWN, UP ,RGHT,SCLN,DEL,
  //|----+----+----+----+------+----+----.   ,------|------+----+----+----+----+----|
     MUTE,VOLU,VOLD,    ,E_MINS,E_LT ,   ,    E_IQUE ,E_QUES,END ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----/    \------+-----+----+----+----+----+----'
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
      BL_STEP, _______, _______, _______, _______, _______, _______,         _______ , _______, MAC_TGL, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),
 [_D] = KC_KEYMAP(
  //,----+----+----+----+----+----.               ,----+----+----+-----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,E_LBR,E_RBR,ESLS,    ,BSPC,
  //|----+----+----+----+----+----|              |-----+----+----+-----+----+----|
     RST , 1  , 2  , 3  , 4  , 5  ,               EPLUS, 7  , 8  , 9   , 0  ,    ,
  //|----+----+----+----+----+----|              |-----+----+----+-----+----+----|
     DEL ,    ,    ,    ,    ,    ,                    ,  4 ,  5 ,  6  , 0  ,PIPE,
  //|----+----+----+----+----+----+----.    ,----|-----+----+----+-----+----+----|
     BL_S,    ,    ,    ,DOWN,LCBR,LPRN,     LPRN,LCBR,  1  , 2  ,  3  ,RPRN,RCBR,
  //`----+----+----+--+-+----+----+----/    \----+-----+----+----+-----+----+----'
                           ,    ,DEL ,         DEL ,DOT,
  //                  `----+----+----'        `----+----+----'
  ),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;
  if(pressed){
    switch (keycode) {
      case MAC_TGL:
        on_mac = !on_mac;
        on_mac ? SEND_STRING("On mac") : SEND_STRING("Not on MAC");
        return false;
      }
  }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
  }
  return true;
}
