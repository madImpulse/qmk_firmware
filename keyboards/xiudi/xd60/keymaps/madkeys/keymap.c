#include QMK_KEYBOARD_H
#include "madkeys.h"

#define LAYOUT_wrapper(...)  LAYOUT_60_ansi_split_bs_rshift_space (__VA_ARGS__)

/*
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,
        KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT,          KC_LSFT,                KC_SPC,         KC_ESC,  KC_RGUI, MO(1),    KC_LEFT, KC_DOWN,  KC_RIGHT
    ),
    [1] = LAYOUT_60_ansi_split_bs_rshift_space(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,   KC_F14,
        KC_NO,   KC_WH_U, KC_UP,   KC_WH_D, KC_BSPC,KC_HOME,KC_CALC,KC_NO,  KC_INS, KC_NO,   KC_PSCR, KC_SCRL,  KC_PAUS,           KC_DEL,
        KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_DEL, KC_END, KC_PGDN,KC_NO,  KC_NO,  KC_NO,   KC_HOME, KC_PGUP,  KC_NO,             KC_ENT,
        KC_LSFT, KC_NO,   KC_NO,   KC_APP,  BL_STEP,KC_NO,  KC_NO,  KC_VOLD,KC_VOLU,KC_MUTE, KC_END,  KC_PGDN,  KC_RSFT, KC_PGUP,  KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,          KC_LSFT,                KC_SPC,         KC_ESC,  KC_RGUI, MO(1),    KC_HOME, KC_PGDN,  KC_END
    )
};
*/

enum madddz64_layers {
  _MADBASE,
  _MADLOWER,
  _MADRAISE,
  _MADUML,
  _MADSET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MADBASE] = LAYOUT_wrapper(
        KC_GRV,         MADROWNUM,                                                                                                  KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
        KC_TAB,         MADROWQ,                                                                                                             KC_LBRC, KC_RBRC, KC_BSLS,
        LT(_MADUML, KC_ESC),  MADROWA,                                                                                                             KC_QUOT,  KC_NO,          KC_ENT,
        KC_LSFT, _______, MADROWZ,                                                                                                  KC_RSFT, KC_SLSH,  KC_UP,   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                   LT(_MADLOWER, KC_SPC), LT(_MADRAISE, KC_SPC),         KC_SPC, KC_RALT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_MADLOWER] = LAYOUT_wrapper(
        KC_TILD,        MADROWNUMLOW,                                                                                              _______, _______,  _______, _______,
        KC_TILD,        MADROWQLOW,                                                                                                          _______, _______, _______,
        KC_DEL ,        MADROWALOW,                                                                                                          KC_PIPE, _______, _______,
        _______, _______, MADROWZLOW,                                                                                                  _______,KC_END,  _______, _______,
        _______, _______, _______,                   _______, MO(_MADSET), _______,                                        _______, _______, _______, _______, _______
    ),

    [_MADRAISE] = LAYOUT_wrapper(
        KC_GRV ,  MADROWNUMRAI,                                                                                                   _______, _______,  _______,  KC_SYSTEM_POWER,
        KC_GRV ,  MADROWQRAI,                                                                                                              _______,  _______,  _______,
        KC_DEL ,  MADROWARAI,                                                                                                               KC_BSLS, _______,  _______,
        _______,   _______,  MADROWZRAI,                                                                                                    _______, KC_PGDN, _______, _______,
        _______,  _______, _______,                   MO(_MADSET),  _______,  _______,                                     _______, _______, _______, _______, _______
    ),

    [_MADUML] = LAYOUT_wrapper(
        _______,  MADROWNUMUML,                                                                                                   _______, _______,  _______,  _______,
        _______,  MADROWQUML,                                                                                                              _______,  _______,  _______,
        _______,  MADROWAUML,                                                                                                               _______, _______,  _______,
        _______,  _______,   MADROWZUML,                                                                                                     _______, _______, _______, _______,
        _______,  _______, _______,                   _______,  _______,  _______,                                     _______, _______, _______, _______, _______
    ),

    [_MADSET] = LAYOUT_wrapper(
        _______, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, _______, _______, _______, QK_BOOTLOADER, _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
