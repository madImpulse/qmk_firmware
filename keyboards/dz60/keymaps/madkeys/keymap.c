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
        KC_LCTL, KC_LGUI, KC_LALT,                   LT(_MADLOWER, KC_SPC),  KC_SPC,  LT(_MADRAISE, KC_SPC),           KC_RALT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_MADLOWER] = LAYOUT_wrapper(
        KC_TILD,  MADROWNUMLOW,    _______, _______,  _______,  _______,
        KC_TILD,  MADROWQLOW,               _______, _______, _______,
        KC_DEL ,  MADROWALOW,               KC_PIPE,          _______,<
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
        _______, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, RGB_RNOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
