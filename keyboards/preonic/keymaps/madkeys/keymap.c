/* Copyright 2024 the madImpulse
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
#include "madkeys.h"
#include "muse.h"

#define LAYOUT_preonic_grid_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

#define MADNAVLAYER _LOWER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   MADROWNUM                                                         | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   MADROWQ                                                           | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   MADROWA                                                           |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   MADROWZ                                                           |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |ENT/ALT|Lower |    Space   |Raise |ENT/ALT| Ctrl| Left |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid_wrapper(
  KC_GRV,  MADROWNUM,             KC_BSPC,
  KC_TAB,  MADROWQ,               KC_DEL,
  MADCTL,  MADROWA,
  KC_LSFT, MADROWZ,               KC_RSFT,
  KC_LCTL, MO(_ADJUST), KC_LGUI, MADLALTENT, LT(LOWER, KC_SPC),  KC_SPC,  LT(RAISE, KC_SPC),   MADRALTENT, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   MADROWNUMLOW                                                      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   MADROWQLOW                                                        | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  DEL |   MADROWALOW                                                        |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   MADROWZLOW                                                        |PRSCRN|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Brite |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------]'
 */
[_LOWER] = LAYOUT_preonic_grid_wrapper(
  _______, MADROWNUMLOW,         KC_BSPC,
  _______, MADROWQLOW,           KC_DEL,
  _______, MADROWALOW,
  _______, MADROWZLOW,           KC_PSCR,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   MADROWNUMRAI                                                      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   MADROWQRAI                                                        |   =  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  DEL |   MADROWARAI                                                        |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   MADROWZRAI                                                        |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid_wrapper(
  _______,    MADROWNUMRAI,        _______,
  MADTABRAI,  MADROWQRAI,          KC_EQL,
  MADCAPSRAI, MADROWARAI,
  MADLSFTRAI, MADROWZRAI,          MADRSFTRAI,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  BL  |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, QK_BOOT, DB_TOGG,   _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  QK_BOOTLOADER, _______, MU_NEXT,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, AU_PREV, AU_NEXT,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
