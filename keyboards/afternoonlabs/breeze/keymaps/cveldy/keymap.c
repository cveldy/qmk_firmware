/* Copyright 2021 eithanshavit
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


// LAYERS
enum layer_names {
    _BASE,
    _NAV,
    _NUMPAD,
};


// COMBOS
enum combos {
  DBLSHFT_CAPS
};

const uint16_t PROGMEM dblshft_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};

combo_t key_combos[] = {
  [DBLSHFT_CAPS] = COMBO(dblshft_combo, KC_CAPS),
};


// KEYMAPS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┐
     LT(0,KC_GRV),KC_1,KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    LT(0,KC_MINS),KC_INS,KC_HOME,KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    LT(0,KC_P),LT(0,KC_EQL),KC_DEL,KC_END,KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_UP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_LEFT, KC_DOWN, KC_RIGHT,
  //└────────┴────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘└────────┴────────┴────────┘
                                KC_LCTL, KC_LALT, KC_SPC, LT(_NAV,KC_ENT),   KC_SPC,  MO(_NUMPAD),KC_DEL,KC_RGUI
  //                           └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┐
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,  _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, XXXXXXX,           _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,  _______, _______,
  //└────────┴────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘└────────┴────────┴────────┘
                                _______, _______, _______, _______,          _______, _______, _______, _______
  //                           └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_ESC,  KC_7,    KC_8,    KC_9,    KC_PSLS, KC_BSPC,  _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             KC_TAB,  KC_4,    KC_5,    KC_6,    KC_PAST, KC_DEL,   _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PMNS, KC_PENT,           _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_EQL,  KC_0,    KC_PDOT, KC_PPLS, _______,  _______,  _______, _______,
  //└────────┴────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘└────────┴────────┴────────┘
                                _______, _______, _______, _______,          _______, _______, _______, _______
  //                           └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  )
};


// TAP/HOLD REMAPS
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case LT(0,KC_GRV):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_GRV); // Intercept tap function to send `/~
            } else if (record->event.pressed) {
                tap_code16(KC_ESC); // Intercept hold function to send ESC
            }
            return false;
         case LT(0,KC_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS); // Intercept tap function to send -/_
            } else if (record->event.pressed) {
                tap_code16(KC_BSLS); // Intercept hold function to send \/|
            }
            return false;
         case LT(0,KC_P):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_P); // Intercept tap function to send P
            } else if (record->event.pressed) {
                tap_code16(KC_LBRC); // Intercept hold function to send [/{
            }
            return false;
         case LT(0,KC_EQL):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL); // Intercept tap function to send =/]
            } else if (record->event.pressed) {
                tap_code16(KC_RBRC); // Intercept hold function to send ]/}
            }
            return false;
    }
    return true;
}
