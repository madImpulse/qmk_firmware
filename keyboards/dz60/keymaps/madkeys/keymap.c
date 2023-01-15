#include QMK_KEYBOARD_H
#include "madkeys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_wrapper(
        KC_GRV,  MADROW12345,    MADROW67890,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,  MADROWQWERT,    MADROWYUIOP,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC,  MADROWASDFG,    MADROWHJKL,     MADROWSEMICOL, KC_QUOT,          KC_ENT,
        KC_LSFT, MADROWZXCVB,    MADROWNM,       MADROWCOMDOT,  MADROWSLASH, KC_RSFT, KC_UP,   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_RALT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    LAYOUT_wrapper(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
