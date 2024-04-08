/* Copyright 2019 gtips
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
#include "keymap_combo.h" // following http://combos.gboards.ca/docs/install/ for combos
// !remind me to buy gergo a beer

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
    KC_Q,        KC_W,KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,        KC_S,KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
    LSFT_T(KC_Z),KC_X,KC_C,    KC_V,    LT(_LOWER,KC_B),          KC_N,    KC_M,    KC_COMM, RALT_T(KC_DOT), KC_SLSH,
                               KC_LCTL, KC_SPC,                   LT(_RAISE,KC_HOME), KC_LGUI
  ),

  [_LOWER] = LAYOUT_reviung34(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_UP,   KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_Y),               KC_EQL,  KC_4,    KC_5,    KC_6,    KC_PPLS,
    LSFT(KC_Z),KC_NO, KC_NO,   KC_NO,   KC_TRNS,                  KC_UNDS, KC_1,    KC_2,    KC_3,    KC_PMNS,
                               KC_TRNS, KC_TRNS,                  KC_END,  KC_0
  ),

  [_RAISE] = LAYOUT_reviung34(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_PGUP, KC_NO,   KC_PGDN, KC_NO,   KC_NO,                    KC_EQL,  KC_MINS, KC_NO,   KC_LBRC, KC_RBRC,
    KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,                  KC_UNDS, KC_PLUS, KC_NO,   KC_LCBR, KC_RCBR,
                               KC_TRNS, MO(_ADJUST),              KC_TRNS, KC_TRNS
  ),

  [_ADJUST] = LAYOUT_reviung34(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_NO,   KC_NO,   KC_NO,   KC_F9,   KC_F10,                   KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NUM,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,                  KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_CAPS,
                               KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
