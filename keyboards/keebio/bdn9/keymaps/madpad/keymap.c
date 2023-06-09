/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        various F-Keys to be used as shortcuts
        and normal media keys in lower row
     */
    [0] = LAYOUT(
        RALT(KC_F13), RALT(KC_F15), RALT(KC_F17),
        MO(1), RCTL(KC_F15), MO(2),
        KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK
    ),
    /*
        rgb control
        | n/a         | rgb hue dec  | rgb hue inc |
        | n/a         | rgb toggle   | rgb next    |
        | rgb sat dec | rgb sat inc  | rgb prev    |
     */
    [1] = LAYOUT(
        KC_NO,   RGB_HUD, RGB_HUI,
        _______, RGB_TOG, RGB_MOD,
        RGB_SAD, RGB_SAI , RGB_RMOD
    ),
        /*
        emergency arrow mode
        | n/a    | n/a   | n/a   |
        | enter  | up    | n/a   |
        | left   | down  | right |
     */
    [2] = LAYOUT(
        KC_NO, KC_NO, KC_NO,
        KC_ENTER, KC_UP, _______,
        KC_LEFT, KC_DOWN, KC_RIGHT
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_F13);
        } else {
            tap_code(KC_F14);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_F15);
        } else {
            tap_code(KC_F16);
        }
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_F17);
        } else {
            tap_code(KC_F18);
        }
    }
    return false;
}
