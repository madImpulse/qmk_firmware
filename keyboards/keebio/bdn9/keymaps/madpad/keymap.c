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
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        RALT(KC_F13), RALT(KC_F15), RALT(KC_F17),
        MO(1), RCTL(KC_F15), MO(2),
        KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK
    ),
    /*
        | QK_BOOT          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        QK_BOOT  ,RGB_HUD, RGB_HUI,
        _______, RGB_TOG, RGB_MOD,
        RGB_SAD, RGB_SAI , RGB_RMOD
    ),
        /*
        | QK_BOOT          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB Mode   |
        | Media Previous | End  | Media Next |
     */
    [2] = LAYOUT(
        QK_BOOT, BL_STEP, KC_STOP,
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
