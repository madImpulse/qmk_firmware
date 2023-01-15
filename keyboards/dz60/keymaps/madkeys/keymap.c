#include QMK_KEYBOARD_H
#include "madkeys.h"

#define LAYOUT_wrapper(...)  LAYOUT_directional (__VA_ARGS__)

enum maddz60_layers {
  _MADBASE,
  _MADLOWER,
  _MADRAISE,
  _MADSET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MADBASE] = LAYOUT_wrapper(
        KC_GRV,         MADROWNUM,              KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,         MADROWQ,                KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC,         MADROWA,                KC_QUOT,          KC_ENT,
        KC_LSFT, MADROWZ,                KC_SLSH, KC_RSFT, KC_UP,   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                   MO(_MADLOWER),  KC_SPC,  MO(_MADRAISE),           KC_RALT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_MADLOWER] = LAYOUT_wrapper(
        KC_TILD,  MADROWNUMLOW,    _______, _______,  _______,  _______,
        KC_TILD,  MADROWQLOW,               _______, _______, _______,
        KC_DEL ,  MADROWALOW,               KC_PIPE,          _______,
        _______,    MADROWZLOW,      KC_END, _______, _______,   _______,
        _______, _______, _______,                   _______,  _______,  MO(_MADSET),           _______, _______, _______, _______, _______
    ),

    [_MADRAISE] = LAYOUT_wrapper(
        KC_GRV ,  MADROWNUMRAI,   _______, _______,  _______,  _______,
        KC_GRV ,  MADROWQRAI,              _______,  _______,  _______,
        KC_DEL ,  MADROWARAI,               KC_BSLS,           _______,
        _______,    MADROWZRAI,      KC_PGDN, _______, _______,  _______,
        _______,  _______, _______,                   MO(_MADSET),  _______,  _______,           _______, _______, _______, _______, _______
    ),

    [_MADSET] = LAYOUT_wrapper(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
