/* Copyright 2021 konomu
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
#include "g/keymap_combo.h"
#include "keymap_steno.h"

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    STEN,
	EXTN,
	COLE,
	SYM,
	NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [STEN] = LAYOUT( \
     KC_ESC, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_N1, STN_ST1,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
   MO(EXTN), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_N2, STN_ST2,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
							   STN_N3,   STN_A,   STN_O,   STN_E,   STN_U,  STN_N4
    ),
	
	[EXTN] = LAYOUT( \
   XXXXXXX, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_VOLU, KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_DEL,  KC_ESC,
   XXXXXXX, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_VOLD, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,  KC_TAB,
						    A(KC_TAB), KC_MUTE, KC_BSPC,  KC_SPC,  KC_ENT, KC_SLEP
    ),
	
	[COLE] = LAYOUT( \
    KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_MINS,
   KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
						   	   MO(SYM), KC_TAB, KC_BSPC,  KC_SPC,  KC_ENT, MO(NUM)
    ),
	
	[SYM] = LAYOUT( \
   KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_COLN, KC_PIPE,
    KC_GRV, KC_MINS, KC_UNDS, KC_LPRN, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_RPRN,  KC_EQL, KC_SCLN, KC_BSLS,
						   	  XXXXXXX, KC_TAB, KC_BSPC,  KC_SPC,  KC_ENT, XXXXXXX
    ),
	
	[NUM] = LAYOUT( \
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
   XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
						   	  XXXXXXX, KC_TAB, KC_BSPC,  KC_SPC,  KC_ENT, XXXXXXX
    )
};
