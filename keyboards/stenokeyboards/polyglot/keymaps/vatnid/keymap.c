/*
Copyright 2023 Samuel Lo <systemx637@gmail.com>, based on 2021 Peter C. Park <peter@stenokeyboards.com>

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

enum polyglot_layers {
 _STENO_DEFAULT = 0
 ,_QWERTY
 ,_LEFT
 ,_RIGHT
 ,_FUNC
};

enum polyglot_keycodes {
  STENO = SAFE_RANGE
 ,QWERTY
 ,LEFT
 ,RIGHT
 ,FUNC
 ,CTLCAP
 ,SCRSHT
 ,EMOJI
 ,TPZR
 ,BACK
};

#define QWERTY LT(_QWERTY, KC_NO)
#define STENO LSFT_T(KC_NO)
#define LEFT MO(_LEFT)
#define RIGHT MO(_RIGHT) 
//#define RIGHT LT(_RIGHT, KC_NO)
#define CTLCAP LCTL_T(KC_CAPS)
#define POUND ROPT(KC_3)
#define FUNCL MO(_FUNC)
#define FUNCR LT(_FUNC, KC_NO)
#define SCRSHT LCMD(S(KC_4))
#define EMOJI LCTL(LCMD(KC_SPC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_STENO_DEFAULT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1, 					     STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2, 					     STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      QWERTY, KC_LSFT, KC_LCTL, KC_LOPT, KC_LCMD,  KC_SPC,    				   KC_VOLD, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 STN_N1,  STN_A,   STN_O,                 STN_E,  STN_U,   STN_N2
                             //`--------------------------'            `--------------------------'

   ),

  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      CTLCAP,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
       STENO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 KC_LOPT, KC_LCMD,  LEFT,                KC_SPC,  RIGHT,  KC_RSFT
                           //`----------------------------'            `--------------------------'

  ),

  [_LEFT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      KC_PGUP, KC_HOME, KC_VOLD, KC_UP,  KC_VOLU, KC_MUTE,               XXXXXXX,  KC_7,    KC_8,   KC_9,   KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_PGDN, KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BRIU,               POUND,   KC_4,    KC_5,   KC_6,   KC_DOT,  _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, SCRSHT, KC_MPRV,  KC_MPLY, KC_MNXT, KC_BRID,              KC_DLR,   KC_1,    KC_2,   KC_3,   _______, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,               KC_0,    FUNCR,   TPZR
                           //`----------------------------'            `--------------------------'
  ),

  [_RIGHT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     XXXXXXX,S(KC_NUBS),KC_NUBS, KC_LBRC, KC_RBRC, KC_TILD,             XXXXXXX, KC_UNDS, KC_PLUS, KC_CIRC, KC_PERC, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_ESC,  KC_AT,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_GRV,              KC_HASH, KC_MINS, KC_EQL,  KC_EXLM, KC_COLN, KC_DQT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS,             KC_AMPR,  EMOJI,  XXXXXXX, XXXXXXX, KC_PIPE, KC_ROPT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 _______, _______,  FUNCL,              XXXXXXX, _______,  XXXXXXX
                             //`--------------------------'            `--------------------------'
  ),

  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  KC_F7,   KC_F8,   KC_F9,   KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  KC_F4,   KC_F5,   KC_F6,   KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  KC_F1,   KC_F2,   KC_F3,   KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, _______,              XXXXXXX, _______, XXXXXXX
                             //`--------------------------'            `--------------------------'
  ),

};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
		    layer_move(_QWERTY);
      }
      return false;
    case STENO:
      if (record->event.pressed) {
        layer_move(_STENO_DEFAULT);
      }
      return false;
  }
  return true;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case QWERTY:
      if (record->tap.count && record->event.pressed) { //tapped
        layer_move(_QWERTY);
        return false;
      }
    /*
    case QWERTY:
      if (record->event.pressed) {
        layer_move(_QWERTY);
      }
      return false;
    */
    case STENO:
      if (record->tap.count && record->event.pressed) { //tapped
        layer_move(_STENO_DEFAULT);
        return false;
      }
      break;
    /*
    case RIGHT:
      if (record->tap.count && record->event.pressed) { //tapped
        tap_code16(KC_SPC);
        return false;
      }
      break;
    */
    case FUNCR:
      if (record->tap.count && record->event.pressed) { //tapped
        SEND_STRING("00");
        return false;
      }
      break;
    case TPZR:
      if (record->event.pressed) {
        SEND_STRING("000");
      }
      return false;
  }
  return true;
}

// initialize steno protocol
void keyboard_post_init_user(void)
{
  steno_set_mode(STENO_MODE_GEMINI);
}
