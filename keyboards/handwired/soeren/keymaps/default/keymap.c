/* Copyright 2020 arne
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
//enum custom_keycodes {
    //QMKBEST = SAFE_RANGE,
    //QMKURL
//};
enum custom_keycodes {
    ANYKEY = SAFE_RANGE,
    PANIC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
		    KC_VOLD, KC_VOLU, PANIC,
		    LCTL(KC_C), LCTL(KC_V), ANYKEY
    ),
    [_FN] = LAYOUT(
		    KC_WBAK, KC_WFWD,  RESET,
		    _______, XXXXXXX, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ANYKEY:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
		tap_random_base64();
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case PANIC:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("fuck this shit\n" SS_DELAY(1000) SS_LGUI("l"));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
