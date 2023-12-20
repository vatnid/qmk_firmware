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
#include "os_detection.h"

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
 ,CMDDOT
 ,POUND
 ,SCRSHT
 ,EMOJI
// ,TPZR
 ,BACK
 ,EXLMS
 ,EXLMW
 ,EXLMD
 ,EXLMZ
 ,EXLMG
 ,EXLMI
 ,EXLMY
 ,CMDCTL
 ,ESCAPE
 ,CURROS
};


// Tap Dance declarations
enum {
  TD_QUOT
 ,TD_CLN
 ,TD_MINS
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),
  [TD_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLN, KC_SCLN),
};


#define STENO LSFT_T(KC_NO)
#define QWERTY LT(_QWERTY, KC_NO)
//#define LEFT MO(_LEFT)
//#define RIGHT MO(_RIGHT)
#define LEFT LT(_LEFT, KC_SPC)
#define RIGHT LT(_RIGHT, KC_SPC)
//#define FUNCL MO(_FUNC)
#define FUNCL LT(_FUNC, KC_ENT)
#define FUNCR LT(_FUNC, KC_0)
#define CTLESC LCTL_T(KC_ESC)
#define CTLQT RCTL_T(KC_QUOT)
#define LSFTETR LSFT_T(KC_ENT)
#define RSFTETR RSFT_T(KC_ENT)
#define SFTDOT RSFT_T(KC_DOT)
#define OPTEQL ROPT_T(KC_EQL)
#define POUND ROPT(KC_3)
#define SCRSHT LCMD(S(KC_4))
#define EMOJI LCTL(LCMD(KC_SPC))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  ///*
  // Original steno layer
  [_STENO_DEFAULT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      STN_N3, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,               STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      STN_N4, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,               STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      QWERTY, KC_LSFT, KC_LCTL, KC_LOPT, KC_LCMD,  KC_SPC,               KC_VOLD, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 STN_N5,  STN_A,   STN_O,                 STN_E,  STN_U,   STN_N6
                             //`--------------------------'            `--------------------------'
  ),
  //*/

  /*
  // Steno layer
  [_STENO_DEFAULT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     XXXXXXX, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,               STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      QWERTY, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,               STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 KC_VOLD, STN_A,   STN_O,                 STN_E,  STN_U,   KC_VOLU
                             //`--------------------------'            `--------------------------'
  ),
  */

  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      CTLESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,  KC_MINS,TD(TD_QUOT),
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
       STENO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 KC_LOPT, KC_LCMD,  LEFT,                 RIGHT,  SFTDOT,  KC_ROPT
                           //`----------------------------'            `--------------------------'

  ),

  [_LEFT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
      KC_PGUP, KC_MUTE, KC_VOLD,  KC_UP,  KC_VOLU, KC_BRIU,              KC_DLR,   KC_1,    KC_2,   KC_3,   KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_PGDN, KC_MPLY, KC_LEFT, KC_DOWN,KC_RIGHT, KC_BRID,              KC_MINS,  KC_4,    KC_5,   KC_6,   KC_SLSH, KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      LSFTETR, KC_MPRV, KC_HOME, SCRSHT,  KC_END,  KC_MNXT,               POUND,   KC_7,    KC_8,   KC_9,   KC_PLUS, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,               FUNCR,  _______, OPTEQL
                           //`----------------------------'            `--------------------------'
  ),

  [_RIGHT] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     _______,S(KC_NUBS),KC_NUBS, KC_LBRC, KC_RBRC, KC_TILD,             KC_CIRC, KC_UNDS, KC_PLUS, KC_QUES, KC_PERC, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_AT,  KC_ASTR, KC_LPRN, KC_RPRN,  EMOJI,               KC_HASH, KC_MINS, KC_EQL,  KC_EXLM,TD(TD_CLN),KC_DQT,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, POUND,   KC_DLR,  KC_LCBR, KC_RCBR, KC_BSLS,              KC_AMPR, KC_GRV,  KC_LT,   KC_GT,  KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                 _______, _______, FUNCL,               _______, _______,  _______
                             //`--------------------------'            `--------------------------'
  ),

  // Idea: IPA layer?
  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, CURROS,  XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, _______,              _______, XXXXXXX, XXXXXXX
                             //`--------------------------'            `--------------------------'
  ),

  /*
  // Discontinued - DuckDuckGo bang search on Firefox layer
  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.            ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX,  EXLMW,  XXXXXXX, XXXXXXX, XXXXXXX,               EXLMY,  XXXXXXX,  EXLMI,  XXXXXXX, XXXXXXX, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX,  EXLMS,   EXLMD,  XXXXXXX,  EXLMG,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
     KC_LSFT,  EXLMZ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX, _______,              _______, XXXXXXX, XXXXXXX
                             //`--------------------------'            `--------------------------'
  ),
  */

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
    case CMDCTL:
      if (record->event.pressed) {
        if (detected_host_os() == OS_MACOS) {
          register_code(KC_LCMD);
        } else {
          register_code(KC_LCTL);
        }
      } else {
        if (detected_host_os() == OS_MACOS) {
          unregister_code(KC_LCMD);
        } else {
          unregister_code(KC_LCTL);
        }
      }
      return false;

    case ESCAPE:
      // Tap
      if (record->tap.count) {
        tap_code16(KC_ESC);
        return false;
      }
      // Held
      if (record->event.pressed) {
        if (detected_host_os() == OS_MACOS) {
          register_code(KC_LCTL);
        } else {
          register_code(KC_LWIN);
        }
      // Release
      } else {
        if (detected_host_os() == OS_MACOS) {
          unregister_code(KC_LCTL);
        } else {
          unregister_code(KC_LWIN);
        }
      }
      return false;

    /*
    case ESCAPE:
      // Tap
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_ESC);
        return false;
      // Held
      } else if (record->event.pressed) {
        if (detected_host_os() == OS_MACOS) {
          register_code(KC_LCTL);
        } else {
          register_code(KC_LWIN);
        }
      // Release
      } else {
        if (detected_host_os() == OS_MACOS) {
          unregister_code(KC_LCTL);
        } else {
          unregister_code(KC_LWIN);
        }
      }
      return false;
    */
    
    case SCRSHT:
      if (record->event.pressed) {
        if (detected_host_os() == OS_MACOS) {
            tap_code16(LCMD(S(KC_4)));
        } else {
            tap_code16(SWIN(KC_S));
        }
        return false;
      }
      break;
    case EMOJI:
      if (record->event.pressed) {
        if (detected_host_os() == OS_MACOS) {
            tap_code16(LCTL(LCMD(KC_SPC)));
        } else {
            tap_code16(LWIN(KC_DOT));
        }
        return false;
      }
      break;

    case CURROS:
      if (record->event.pressed) {
        //os_variant_t os_type;
        //os_type = detected_host_os();
        switch (detected_host_os()) {
          case OS_LINUX:
            SEND_STRING("Linux");
            break;
          case OS_WINDOWS:
            SEND_STRING("Windows");
            break;
          case OS_MACOS:
            SEND_STRING("macOS");
            break;
          case OS_IOS:
            SEND_STRING("iOS");
            break;
          default:
            SEND_STRING("unknown");
            break;
        }
        return false;
      }
      break;

    /*
    // DuckDuckGo bang search functions
    case EXLMS:
      if (record->event.pressed) {
        tap_code16(RCMD(KC_T));
        SEND_STRING("!s ");
        return false;
      }
      break;
    case EXLMW:
      if (record->event.pressed) {
        tap_code16(RCMD(KC_T));
        SEND_STRING("!w ");
        return false;
      }
      break;
    case EXLMD:
      if (record->event.pressed) {
        tap_code16(RCMD(KC_T));
        SEND_STRING("!wikt ");
        return false;
      }
      break;
    case EXLMZ:
      if (record->event.pressed) {
        tap_code16(RCMD(KC_T));
        SEND_STRING("!wzh ");
        return false;
      }
      break;
    case EXLMG:
      if (record->event.pressed) {
        tap_code16(RCMD(KC_T));
        SEND_STRING("!g ");
        return false;
      }
      break;
    case EXLMI:
      if (record->event.pressed) {
        tap_code16(RCMD(KC_T));
        SEND_STRING("!spi ");
        return false;
      }
      break;
    case EXLMY:
      if (record->event.pressed) {
        tap_code16(RCMD(KC_T));
        SEND_STRING("!yt ");
        return false;
      }
      break;
    */
    /*
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
    */
    /*
    case FUNCL:
      if (record->tap.count && record->event.pressed) { //tapped
        tap_code16(KC_ENT);
        return false;
      }
      break;
    case FUNCR:
      if (record->tap.count && record->event.pressed) { //tapped
        tap_code16(KC_0);
        return false;
      }
      break;
    */
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


// Detect OS and swap
os_variant_t os_type;
uint32_t startup_exec(uint32_t trigger_time, void *cb_arg) {
    if (is_keyboard_master()) {
        os_type = detected_host_os();
        if (os_type) {
            // Not Mac if it's neither macOS not iOS
            bool not_mac = !(os_type == OS_MACOS) && !(os_type == OS_IOS);
            // Swap if not Mac
            if (keymap_config.swap_lctl_lgui != not_mac) {
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = not_mac;
                //eeconfig_update_keymap(keymap_config.raw);
            }
        }
    }
    return os_type ? 0 : 500;
}

void keyboard_post_init_user(void)
{
  defer_exec(100, startup_exec, NULL); // Swap GUI and CTL keys if not Mac
  steno_set_mode(STENO_MODE_GEMINI); // initialize steno protocol
}
