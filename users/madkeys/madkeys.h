#pragma once
#include QMK_KEYBOARD_H

enum mad_layers {
  _MADBASE,
  _MADLOWER,
  _MADRAISE,
  _MADSETTINGS
};

#base alpha keys and right side special chars

#define MADROW12345  KC_1, KC_2, KC_3, KC_4, KC_5
#define MADROWQWERT  KC_Q, KC_W, KC_E, KC_R, KC_T
#define MADROWASDFG  KC_A, KC_S, KC_D, KC_F, KC_G
#define MADROWZXCVB  KC_Z, KC_X, KC_C, KC_V, KC_B

#define MADROW67890  KC_6, KC_7, KC_8, KC_9, KC_0
#define MADROWYUIOP  KC_Y, KC_U, KC_I, KC_O, KC_P
#define MADROWHJKL   KC_H, KC_J, KC_K, KC_L
#define MADROWNM     KC_N,   KC_M

#define MADROWSEMICOL KC_SCLN
#define MADROWCOMDOT  KC_COMM,  KC_DOT
#define MADROWSLASH   KC_SLSH
