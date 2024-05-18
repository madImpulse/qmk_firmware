/*
Copyright 2023 Matt F
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "madkeys.h"

// Layer shorthand
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LAYOUT_promenade_grid_wrapper(...) LAYOUT_all(__VA_ARGS__)

#define MADNAVLAYER _LOWER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTRL  | A      | S      | D      | F      | G      |        |        | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | FN     | LALT   | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | LEFT   | DOWN   | UP     | RIGHT  | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_promenade_grid_wrapper(
        KC_ESC,  MADROW12345,                                      KC_MINS, KC_EQL,  MADROW67890,                                      KC_BSPC,
        KC_TAB,  MADROWQWERT,                                      KC_LBRC, KC_RBRC, MADROWYUIOP,                                      KC_QUOT,
        MADCTL,  MADROWASDFG,                                                        MADROWHJKL, MADROWSEMICOL,                        LCTL_T(KC_QUOT),
        KC_LSFT, MADROWZXCVB,                                      KC_END,  KC_PGDN, MADROWNMCDS,                                      KC_RSFT,
        KC_LCTL, KC_LGUI, MADLALTENT, MO(_ADJUST), KC_SPC,  LT(_LOWER, KC_SPC), KC_SPC,  LT(_RAISE, KC_SPC),  MADRALTENT, KC_DOWN, KC_UP,   KC_RGHT, KC_RCTL
    ),

    [_LOWER] = LAYOUT_promenade_grid_wrapper(
        _______,  MADROW12345LOW,                                  KC_MINS, KC_EQL,  MADROW67890LOW,                                   _______,
        _______,  MADROWQWERTLOW,                                  KC_LBRC, KC_RBRC, MADROWYUIOPLOW,                                   _______,
        _______,  MADROWASDFGLOW,                                                     MADROWHJKLLOW, MADROWSEMICOLLOW,                 _______,
        _______,  MADROWZXCVBLOW,                                   KC_END,  KC_PGDN, MADROWNMCDSLOW,                                  _______,
        _______,  _______, _______, MO(_ADJUST), _______,  _______,      _______,      MO(_ADJUST),  _______, _______, _______,   _______, _______
    ),

    [_RAISE] = LAYOUT_promenade_grid_wrapper(
        _______,  MADROW12345RAI,                                  KC_MINS, KC_EQL,  MADROW67890RAI,                                   _______,
        MADTABRAI,  MADROWQWERTRAI,                                  KC_LBRC, KC_RBRC, MADROWYUIOPRAI,                                   _______,
        MADCAPSRAI,  MADROWASDFGRAI,                                                    MADROWHJKLRAI, MADROWSEMICOLRAI,                  _______,
        MADLSFTRAI,  MADROWZXCVBRAI,                                  KC_END,  KC_PGDN, MADROWNMCDSRAI,                                   _______,
        _______,  _______, _______, MO(_ADJUST), _______,  MO(_ADJUST),      _______,      _______,  _______, _______, _______,   _______, _______
    ),

    [_ADJUST] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______,
        QK_BOOT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,                   _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______, QK_BOOT
    )
};
