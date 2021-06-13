/*
Copyright 2021 Peter C. Park <peter@stenokeyboards.com>

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
#include "keymap_steno.h"

enum twoni_layers {
  _QWERTY = 0
 ,_DVORAK
 ,_COLEMAK
 ,_RAISE
 ,_LOWER
 ,_GEMINI
 ,_PLOVER
 ,_UNI_GEMINI
 ,_UNI_PLOVER
};

enum twoni_keycodes {
  QWERTY = SAFE_RANGE
 ,DVORAK
 ,COLEMAK
 ,RAISE
 ,LOWER
 ,GEMINI
 ,PLOVER
 ,UNI_GEMINI
 ,UNI_PLOVER
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,   RAISE,      LOWER,  KC_SPC, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_DVORAK] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,   KC_S,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,   KC_Z,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,   RAISE,      LOWER,  KC_SPC, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_COLEMAK] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT,   RAISE,      LOWER,  KC_SPC, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   UNI_GEMINI,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   UNI_PLOVER, XXXXXXX,  QWERTY,  DVORAK, COLEMAK, XXXXXXX,                      KC_LEFT, KC_DOWN,  KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT, _______,    XXXXXXX,  KC_SPC, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       GEMINI, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       PLOVER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LSFT, XXXXXXX,    _______,  KC_SPC, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_PLOVER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QWERTY,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QWERTY,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_C,    KC_V,    KC_1,       KC_2,    KC_N,    KC_M
                                      //`--------------------------'  `--------------------------'

  ),

  [_GEMINI] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  					            STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QWERTY, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, 					             STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QWERTY, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, 					             STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          STN_A,   STN_O,  STN_N1,      STN_N2,  STN_E,   STN_U
                                      //`--------------------------'  `--------------------------'

  ),

  [_UNI_PLOVER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QWERTY,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QWERTY,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_C,    KC_V,    KC_1,       KC_2,    KC_N,    KC_M
                                      //`--------------------------'  `--------------------------'

  ),

  [_UNI_GEMINI] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QWERTY, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, 					             STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QWERTY, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, 					             STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  					            STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            STN_A,   STN_O,  STN_N1,     STN_N2,   STN_E,   STN_U
                                      //`--------------------------'  `--------------------------'

  ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_clear();
		    set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        layer_clear();
		    set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        layer_clear();
		    set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case PLOVER:
      if (record->event.pressed) {
        layer_clear();
		    set_single_persistent_default_layer(_PLOVER);
      }
      return false;
    case GEMINI:
      if (record->event.pressed) {
        layer_clear();
        set_single_persistent_default_layer(_GEMINI);
      }
    case UNI_PLOVER:
      if (record->event.pressed) {
        layer_clear();
		    set_single_persistent_default_layer(_UNI_PLOVER);
      }
      return false;
    case UNI_GEMINI:
      if (record->event.pressed) {
        layer_clear();
        set_single_persistent_default_layer(_UNI_GEMINI);
      }
      return false;
  }
  return true;
}

// initialize steno protocol
void matrix_init_user(void)
{
  steno_set_mode(STENO_MODE_GEMINI);
}