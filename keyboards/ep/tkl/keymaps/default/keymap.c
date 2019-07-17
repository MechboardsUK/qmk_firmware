/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

void keyboard_post_init_user(){
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
        KC_ESC, KC_ESC,             KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,       KC_PSCR,  LT(1, KC_SLCK),  MT(MOD_LCTL, KC_PAUSE),\
               KC_GRV,   KC_1,     KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,      KC_INS,   KC_HOME,  KC_PGUP,\
               KC_TAB,   KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,       KC_DEL,   KC_END,   KC_PGDN,\
               KC_CAPS,  KC_A,     KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,                               \
               KC_LSFT,  KC_NUBS,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLASH,  KC_RSFT,                          KC_UP,        \
               KC_LCTL,  KC_LGUI,  KC_LALT,                        KC_SPC,                          KC_RALT,  KC_RGUI,  KC_MENU,   KC_RCTRL,      KC_LEFT,  KC_DOWN,  KC_RGHT \
 ),
 [_FN1] = LAYOUT( \
     KC_ESC, KC_ESC,             KC_F1,    KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,      RGB_MOD,  KC_TRNS, RGB_TOG, \
            KC_GRV,   KC_1,     KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,      RGB_HUI,   RGB_SAI,  RGB_VAI,\
            KC_TAB,   KC_Q,     KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_ENT,       RGB_HUD,   RGB_SAD,   RGB_VAD,\
            KC_CAPS,  KC_A,     KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,                               \
            KC_LSFT,  KC_NUBS,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLASH,  KC_RSFT,                          KC_VOLU,       \
            KC_LCTL,  KC_LGUI,  KC_LALT,                        KC_SPC,                          KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL,      KC_LEFT,  KC_VOLD,  RESET \
)
};




