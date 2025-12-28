#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "quantum.h"

enum custom_layers {
  _MAC,
  _LINUX,
  _SYMBOL,
  _MOUSE,
};

#define LT_SPC LT(_SYMBOL, KC_SPC)
#define CTR_SPC RCTL_T(KC_SPC)
#define CMD_ESC LCMD_T(KC_ESC)
#define CTR_ESC LCTL_T(KC_ESC)
#define SFT_ENT LSFT_T(KC_ENT)
#define OSM_CMD OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTR OSM(MOD_RCTL)
#define DF_MAC DF(_MAC)
#define DF_LIN DF(_LINUX)


enum keycodes {
  QWERTY = SAFE_RANGE,

  FN_1,
  FN_2,
  FN_3,
  FN_4,
  BR_U,
  BR_D,
};

// const key_override_t ctl_h = ko_make_basic(MOD_BIT(KC_RCTL), KC_H, KC_LEFT);
// const key_override_t ctl_j = ko_make_basic(MOD_BIT(KC_RCTL), KC_J, KC_DOWN);
// const key_override_t ctl_k = ko_make_basic(MOD_BIT(KC_RCTL), KC_K, KC_UP);
// const key_override_t ctl_l = ko_make_basic(MOD_BIT(KC_RCTL), KC_L, KC_RGHT);

// const uint16_t PROGMEM combo_alt_f[] = {OSM_ALT, KC_F, COMBO_END};
// const uint16_t PROGMEM combo_alt_d[] = {OSM_ALT, KC_D, COMBO_END};

// const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
// combo_t key_combos[] = {
//     COMBO(combo_alt_f, FN_1),
//     COMBO(combo_alt_d, FN_2),
//     COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
// };

// const key_override_t alt_g = ko_make_basic(MOD_BIT(KC_LALT), KC_G, KC_F12);
// const key_override_t alt_f = ko_make_basic(MOD_BIT(KC_LALT), KC_F, FN_1);
// const key_override_t alt_d = ko_make_basic(MOD_BIT(KC_LALT), KC_D, FN_2);
// const key_override_t alt_s = ko_make_basic(MOD_BIT(KC_LALT), KC_S, FN_3);
// const key_override_t alt_a = ko_make_basic(MOD_BIT(KC_LALT), KC_A, FN_4);

// const key_override_t **key_overrides = (const key_override_t *[]){
//     &ctl_h,
//     &ctl_j,
//     &ctl_k,
//     &ctl_l,
//     &alt_a,
//     &alt_s,
//     &alt_d,
//     &alt_f,
//     &alt_g,
//     NULL
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        const uint16_t mods_l_alt = get_mods() & MOD_BIT(KC_LALT);
        const uint16_t mods_r_ctl = get_mods() & MOD_BIT(KC_RCTL);

        switch (keycode) {
            case KC_H:
                if (mods_r_ctl) {
                    unregister_mods(mods_r_ctl);
                    tap_code16(KC_LEFT);
                    register_mods(mods_r_ctl);
                    return false;
                }
                break;
            case KC_J:
                if (mods_r_ctl) {
                    unregister_mods(mods_r_ctl);
                    tap_code16(KC_DOWN);
                    register_mods(mods_r_ctl);
                    return false;
                }
                break;
            case KC_K:
                if (mods_r_ctl) {
                    unregister_mods(mods_r_ctl);
                    tap_code16(KC_UP);
                    register_mods(mods_r_ctl);
                    return false;
                }
                break;
            case KC_L:
                if (mods_r_ctl) {
                    unregister_mods(mods_r_ctl);
                    tap_code16(KC_RGHT);
                    register_mods(mods_r_ctl);
                    return false;
                }
                break;
            /*
            case KC_G:
                if (mods_l_alt) {
                    unregister_mods(mods_l_alt);
                    if (detected_host_os() == OS_MACOS) {
                        tap_code16(KC_F15);
                    } else {
                        tap_code16(LGUI(KC_4));
                    }
                    register_mods(mods_l_alt);
                    return false;
                }
            */
            case KC_F:
                if (mods_l_alt) {
                    unregister_mods(mods_l_alt);
                    if (detected_host_os() == OS_MACOS) {
                        tap_code16(KC_F14);
                    } else {
                        tap_code16(LGUI(KC_3));
                    }
                    register_mods(mods_l_alt);
                    return false;
                }
                break;
            case KC_D:
                if (mods_l_alt) {
                    unregister_mods(mods_l_alt);
                    if (detected_host_os() == OS_MACOS) {
                        tap_code16(KC_F13);
                    } else {
                        tap_code16(LGUI(KC_2));
                    }
                    register_mods(mods_l_alt);
                    return false;
                }
                break;
            case KC_S:
                if (mods_l_alt) {
                    unregister_mods(mods_l_alt);
                    if (detected_host_os() == OS_MACOS) {
                        tap_code16(KC_F16);
                    } else {
                        tap_code16(LGUI(KC_1));
                    }
                    register_mods(mods_l_alt);
                    return false;
                }
                break;
        }
    }
    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_MAC] = LAYOUT(
    KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    CMD_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_BRID, KC_BRIU, KC_LCTL, OSM_ALT, SFT_ENT,   TG(_MOUSE),     LT_SPC,  OSM_CTR, OSM_CMD, KC_VOLD, KC_VOLU
),

[_LINUX] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    CTR_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, OSM_CMD, _______, _______,     _______,      _______, _______, _______, _______, _______
),

[_SYMBOL] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    CW_TOGG, KC_PIPE, KC_TILD, KC_PLUS, KC_EQL,  KC_UNDS, KC_LCBR, KC_LBRC, KC_RCBR, KC_RBRC, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, KC_MINS,     _______,      _______, _______, _______, RGB_MOD, RGB_TOG
),

[_MOUSE] = LAYOUT(
    QK_BOOT, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_BTN1, KC_WH_U, KC_WH_D, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    DF_LIN,  _______, _______, _______, _______,     _______,      _______, _______, _______, _______, DF_MAC
),
};
