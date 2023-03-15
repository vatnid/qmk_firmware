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
 ,FUNCL
 ,FUNCR
 ,CTLCAP
 ,CTLQT
 ,LSFTETR
 ,RSFTETR
 ,POUND
 ,SCRSHT
 ,EMOJI
// ,TPZR
 ,BACK
};


// Tap Dance declarations
enum {
    TD_QUOT,
    TD_CLN,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
    [TD_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};


#define STENO LSFT_T(KC_NO)
#define QWERTY LT(_QWERTY, KC_NO)
//#define LEFT MO(_LEFT)
//#define RIGHT MO(_RIGHT)
#define LEFT LT(_LEFT, KC_SPC)
#define RIGHT LT(_RIGHT, KC_SPC)
#define FUNCL MO(_FUNC)
#define FUNCR LT(_FUNC, KC_NO)
#define CTLESC LCTL_T(KC_ESC)
#define CTLQT RCTL_T(KC_QUOT)
#define LSFTETR LSFT_T(KC_ENT)
#define RSFTETR RSFT_T(KC_ENT)
#define POUND ROPT(KC_3)
#define SCRSHT LCMD(S(KC_4))
#define EMOJI LCTL(LCMD(KC_SPC))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_STENO_DEFAULT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      STN_N3, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,               STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      STN_N4, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,               STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      QWERTY, KC_LSFT, KC_LCTL, KC_LOPT, KC_LCMD,  KC_SPC,               KC_VOLD, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 STN_N1,  STN_A,   STN_O,                 STN_E,  STN_U,   STN_N2
                             //`--------------------------'            `--------------------------'

   ),

  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      CTLESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,  TD_CLN,  TD_QUOT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
       STENO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFTETR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 KC_LOPT, KC_LCMD,  LEFT,                 RIGHT,  KC_RCMD, KC_ROPT
                           //`----------------------------'            `--------------------------'

  ),

  [_LEFT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      KC_PGUP, KC_MUTE, KC_VOLD,  KC_UP,  KC_VOLU, KC_BRIU,               POUND,   KC_1,    KC_2,   KC_3,   KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_PGDN, KC_MPLY, KC_LEFT, KC_DOWN,KC_RIGHT, KC_BRID,              KC_MINS,  KC_4,    KC_5,   KC_6,   KC_PLUS, KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      LSFTETR, KC_MPRV, KC_MNXT, KC_HOME, KC_END,  SCRSHT,               KC_DLR,   KC_7,    KC_8,   KC_9,   _______, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,               FUNCR,  KC_DOT,  _______
                           //`----------------------------'            `--------------------------'
  ),

  [_RIGHT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     _______,S(KC_NUBS),KC_NUBS, KC_LBRC, KC_RBRC, KC_TILD,             KC_CIRC, KC_UNDS, KC_PLUS, KC_QUES, KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_AT,  KC_ASTR, KC_LPRN, KC_RPRN,  EMOJI,               KC_HASH, KC_MINS, KC_EQL,  KC_EXLM, KC_COLN, KC_DQT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, POUND,   KC_DLR,  KC_LCBR, KC_RCBR, KC_BSLS,              KC_AMPR,  KC_GRV,  KC_LT,  KC_GT,  KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 _______, _______, FUNCL,               _______, _______,  _______
                             //`--------------------------'            `--------------------------'
  ),

  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  KC_F1,   KC_F2,   KC_F3,   KC_F10, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  KC_F4,   KC_F5,   KC_F6,   KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, _______,              _______, XXXXXXX, XXXXXXX
                             //`--------------------------'            `--------------------------'
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
    case QWERTY:
      if (record->tap.count && record->event.pressed) { //tapped
        layer_move(_QWERTY);
        return false;
      }
    case STENO:
      if (record->tap.count && record->event.pressed) { //tapped
        layer_move(_STENO_DEFAULT);
        return false;
      }
      break;
    case LEFT:
      if (record->tap.count && record->event.pressed) { //tapped
        tap_code16(KC_SPC);
        return false;
      }
      break;
    case RIGHT:
      if (record->tap.count && record->event.pressed) { //tapped
        tap_code16(KC_SPC);
        return false;
      }
      break;
    case FUNCR:
      if (record->tap.count && record->event.pressed) { //tapped
        tap_code16(KC_0);
        return false;
      }
      break;
    /*
    case TPZR:
      if (record->event.pressed) {
        SEND_STRING("000");
      }
      return false;
    */
  }
  return true;
}

// initialize steno protocol
void keyboard_post_init_user(void)
{
  steno_set_mode(STENO_MODE_GEMINI);
}
