// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "os_detection.h"

#include "jpe230.h"

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNC,
};

#define CMD_ESC LCMD_T(KC_ESC)
#define CTR_ESC LCTL_T(KC_ESC)
#define ALT_ENT LALT_T(KC_ENT)
#define SFT_ENT LSFT_T(KC_ENT)
#define CTR_SPC LCTL_T(KC_SPC)
#define OSM_ALT OSM(MOD_RALT)
#define OSM_CTR OSM(MOD_RCTL)
#define OSM_CMD OSM(MOD_LGUI)
#define OSMSCMD OSM(MOD_LGUI | MOD_RSFT)
#define OSMRSFT OSM(MOD_RSFT)
#define OSMLSFT OSM(MOD_LSFT)

enum keycodes {
  QWERTY = SAFE_RANGE,

  FN_1,
  FN_2,
  FN_3,
  FN_4,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        oled_timer_reset();
        set_keylog(keycode, record);

        switch (keycode) {
            case QK_BOOT:
                rgb_matrix_set_color_all(30, 0, 0);
                rgb_matrix_driver.flush();
                oled_off();
                return true;
            case FN_1:
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(KC_F14);
                } else {
                    tap_code16(LGUI(KC_3));
                }
                return false;
            case FN_2:
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(KC_F13);
                } else {
                    tap_code16(LGUI(KC_2));
                }
                return false;
            case FN_3:
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(KC_F16);
                } else {
                    tap_code16(LGUI(KC_1));
                }
                return false;
            case FN_4:
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(KC_F15);
                } else {
                    tap_code16(LGUI(KC_4));
                }
                return false;
        }
    }
    return true;
}
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTR_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSMLSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, OSMRSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MO(2) , SFT_ENT, OSM_ALT,    OSM_CTR, CTR_SPC, MO(1)
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, FN_4   , FN_3   , FN_2   , FN_1   , KC_F12 ,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, OSM_CMD, OSMSCMD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_COPY, KC_PSTE, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MO(3) , _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, OSMSCMD, OSM_CMD, CW_TOGG,                      KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, MO(3)
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_BTN1, KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, XXXXXXX, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD,                      RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, RGB_TOG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// clang-format off
