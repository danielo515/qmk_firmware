#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "danielo515.h"

extern keymap_config_t keymap_config;

#define KC_ KC_TRNS

#define KC_LOWR OSL(_LOWER)
#define KC_RASE OSL(_RAISE)
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_ALT OSM(MOD_LALT)
#define KC_CTL OSM(MOD_LCTL)
#define KC_SFT OSM(MOD_LSFT)

#define LENT LT(_RAISE,ENT)
// #define KC_SBSPC SFT_T(KC_BSPACE)

#define T_LEFT TD(LEFT_HOME)
#define T_RIGHT TD(RIGHT_END)
#define KC_T_J TD(J_ENT)
#define KC_T_H TD(H_MINS)
#define KC_T_RGT TD(RGT_HOME)
#define KC_MAC_TGL MAC_TGL
#define KC_BL_TOGG BL_TOGG
#define KC_K_K RCTL_T(KC_K)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,-------+-------+-------+-------+-------+-------.                          ,-------+-------+-------+-------+-------+------.
      ESC   ,   1   ,   2   ,  3    ,  4    ,   5  ,                              6    ,  7    ,   8   ,  9    ,  0    , ASTERISK ,
  //|-------+-------+-------+-------+-------+------|                           |-------+-------+-------+-------+-------+------|
      GUI   ,  Q    ,  W    ,  E    ,   R   ,   T  ,                              Y    ,  U    ,   I   ,   O   ,  P    , SCLN,
  //|-------+-------+-------+-------+-------+------|                           |-------+-------+-------+-------+-------+------|
      TAB   ,  A    , FN_S  , FN_D  ,  FN_F ,  G   ,                              T_H  ,  T_J  ,  K_K  ,   L   , COLN  , QUOT ,
  //|-------+-------+-------+-------+-------+------+---------.       ,---------|-------+-------+-------+-------+-------+------|
      SFT   , Z     ,TD_CUT ,TD_COPY,TD_PASTE,  B  ,  ESC    ,          MACROS ,  N    ,  M    ,  COMM , DOT   , SLSH  , BSLS,
  //|-------+-------+-------+-------+-------+------+--------/         \--------|--------+-------+------+-------+-------+------|
                                        CTL , LOWR , BSPC ,               SPC  , RASE, ALT
  //                                  `------+------+----'              `------+------+----'
  ),
  [_S] = KC_KEYMAP(
  //,-------+-------+-------+-------+-------+-------.                           ,-------+-------+-------+-------+-------+------.
            ,       ,       ,       ,       ,       ,                                   ,       ,       ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+------|
            ,       ,       , QUOT , PERC  , CIRC ,                               DLR   , LBRC  ,  RBRC , ASTR  ,  TILD ,      ,
  //|-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+------|
            ,       ,       ,ASTR ,EQL , GT ,  AMPR ,                              LPRN , RPRN  , COLN  , PLUS  , PIPE ,
  //|-------+-------+-------+-------+-------+-------+---------.       ,---------|-------+-------+-------+-------+-------+------|
           ,        ,       ,       ,GRV ,LT  ,INSERT ,         0  , QUES,  LCBR ,RCBR ,EXLM,       ,      ,
  //|-------+-------+-------+-------+-------+-------+--------/         \--------|--------+-------+------+-------+-------+------|
                                            ,       ,  DEL ,                     ,       ,
  //                                   `----+------+-------'              `------+------+----'
  ),

    [_F] = KC_KEYMAP(
  //,-------+-------+-------+-------+-------+-------.                           ,-------+-------+-------+-------+-------+------.
            ,       ,       ,       ,       ,       ,                                   ,       ,       ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+------|
            ,       ,       ,  ESC  ,       ,       ,                              F12  ,  F2   ,  F5   ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+------|
            ,  TAB  ,  ALT  ,  CTL  ,       ,       ,                              LEFT ,  DOWN ,  UP   , RGHT ,       ,      ,
  //|-------+-------+-------+-------+-------+-------+---------.       ,---------|-------+-------+-------+-------+-------+------|
            ,       ,       ,       ,       ,       ,         ,                 ,       ,       ,       ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------+--------/         \--------|--------+-------+------+-------+-------+------|
                                            ,      ,       ,                     ,       ,
  //                                   ------+------+----'               ------+------+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,------+------+------+-----+-----+----.                     ,------+-----+-----+------+----+----.
    MAC_TGL,BL_TOGG,      ,     ,     ,     ,                      CIRC ,     ,ASTR , LPRN ,RPRN,BSPC,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
           , EXLM , QUOT , HASH , PERC,CIRC,                          ,LBRC ,  RBRC,     ,     ,    ,
  //|------+------+------+------+-----+----|                    |------+------+----+------+-----+----|
     DEL   , AT   ,  DLR ,   ASTR,  EQL, GT,                        AMPR ,LPRN ,RPRN ,COLN,PLUS,PIPE,
  //|-----+-------+------+------+-----+-----+-----.   ,---------|------+------+-----+------+----+----|
     BL_S,        ,      ,      ,     ,     ,    ,              ,  QUES,LCBR ,RCBR ,      ,    ,    ,
  //|-----+-------+------+------+-----+-----+----/     \--------|------+-----+-----+------+----+----|
                                      ,    ,DEL ,         DEL   ,      ,
  //                           `----+----+-----'         `------+------+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+-----+----+----.                ,-----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                   F6  , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+-----+----+----|                |-----+----+----+----+----+----|
         ,EXLM,QUOT,HASH ,PERC,  CIRC,                 PGDN,HOME,END ,LPRN,RPRN,    ,
  //|----+----+----+-----+-----+----|               |-----+----+----+----+----+----|
         , AT ,DLR , ASTR,  EQL,  GT,                LEFT ,DOWN, UP ,RGHT,SCLN,DEL,
  //|----+----+----+----+------+----+----.   ,------|------+----+----+----+----+----|
     MUTE,VOLU,VOLD,    ,  MINS,  LT ,   ,         ,  QUES,END ,    ,    ,    ,    ,
  //`----+----+----+----+----+----+----/    \------+-----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

    [_MACROS] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, T_TERM,                             _______, _______, _______, _______, CMD_S_P, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______,TRI_TICKS,FIX_ALL, ARROW ,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,LN_CMNT ,BLK_CMNT, _______,         _______ , _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
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
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,  LBRC, RBRC,SLSH,    ,BSPC,
  //|----+----+----+----+----+----|              |-----+----+----+-----+----+----|
     RST , 1  , 2  , 3  , 4  , 5  ,               PLUS, 7  , 8  , 9   , 0  ,    ,
  //|----+----+----+----+----+----|              |-----+----+----+-----+----+----|
     DEL ,    ,    ,    ,    ,    ,                    ,  4 ,  5 ,  6  , 0  ,PIPE,
  //|----+----+----+----+----+----+----.    ,----|-----+----+----+-----+----+----|
     BL_S,    ,    ,    ,DOWN,LCBR,LPRN,     LPRN,LCBR,  1  , 2  ,  3  ,RPRN,RCBR,
  //`----+----+----+--+-+----+----+----/    \----+-----+----+----+-----+----+----'
                           ,    ,DEL ,         DEL ,DOT,
  //                  `----+----+----'        `----+----+----'
  ),

/* Template
  [      ] =         (
  //,-------+-------+-------+-------+-------+-------.                           ,-------+-------+-------+-------+-------+------.
            ,       ,       ,       ,       ,       ,                                   ,       ,       ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+------|
            ,       ,       ,       ,       ,       ,                                   ,       ,       ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+------|
            ,       ,       ,       ,       ,       ,                                   ,       ,       ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------+---------.       ,---------|-------+-------+-------+-------+-------+------|
            ,       ,       ,       ,       ,       ,         ,                 ,       ,       ,       ,       ,       ,      ,
  //|-------+-------+-------+-------+-------+-------+--------/         \--------|--------+-------+------+-------+-------+------|
                                            ,      ,       ,                     ,       ,
  //                                   ------+------+----'               ------+------+----'
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
