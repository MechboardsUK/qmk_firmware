/* Copyright 2019 Elliot Powell
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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    RGB_MOD,  KC_1,    KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,   KC_MINS, KC_EQL,          KC_BSPC,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_TAB,           KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,           KC_P7,   KC_P8,   KC_P9,            \
    KC_CAPS,          KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
    KC_LSFT, KC_BSLS, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT, KC_UP,    KC_P1,   KC_P2,   KC_P3,            \
    KC_LCTL, KC_LGUI, KC_LALT,                    KC_SPC,                       KC_RALT,         KC_RCTL, KC_LEFT, KC_DOWN,  KC_RGHT, KC_P0,   KC_PDOT, KC_PENT  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

int RGB_current_mode;

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
  enum rgb_matrix_effects {
      RGB_MATRIX_SOLID_COLOR = 1,
  #ifdef RGB_MATRIX_KEYPRESSES
      RGB_MATRIX_SOLID_REACTIVE,
  #endif
      RGB_MATRIX_EFFECT_MAX
  };

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
