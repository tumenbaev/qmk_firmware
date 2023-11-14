#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "quantum.h"

#define LT1_SPC LT(1, KC_SPC)
#define LT2_S LT(2, KC_S)
#define LT3_TAB LT(3, KC_TAB)
#define CTR_SPC RCTL_T(KC_SPC)
#define CMD_ESC LCMD_T(KC_ESC)
#define CTR_ESC LCTL_T(KC_ESC)
#define SFT_ENT LSFT_T(KC_ENT)
#define OSM_CMD OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNC,
};

enum keycodes {
  QWERTY = SAFE_RANGE,

  FN_1,
  FN_2,
  FN_3,
  FN_4,
};

const key_override_t ctl_h = ko_make_basic(MOD_BIT(KC_RCTL), KC_H, KC_LEFT);
const key_override_t ctl_j = ko_make_basic(MOD_BIT(KC_RCTL), KC_J, KC_DOWN);
const key_override_t ctl_k = ko_make_basic(MOD_BIT(KC_RCTL), KC_K, KC_UP);
const key_override_t ctl_l = ko_make_basic(MOD_BIT(KC_RCTL), KC_L, KC_RGHT);

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

const key_override_t **key_overrides = (const key_override_t *[]){
    &ctl_h,
    &ctl_j,
    &ctl_k,
    &ctl_l,
//     &alt_a,
//     &alt_s,
//     &alt_d,
//     &alt_f,
//     &alt_g,
    NULL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint16_t mods_l_alt = get_mods() & MOD_BIT(KC_LALT);

    if (record->event.pressed) {
        switch (keycode) {
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
            case LT2_S:
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
            /*
            case FN_4:
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(KC_F15);
                } else {
                    tap_code16(LGUI(KC_4));
                }
                return false;
            */
        }
    }
    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

LAYOUT(
    KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    CMD_ESC, KC_A,    LT2_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    XXXXXXX, MO(2),   KC_LCTL, OSM_ALT, SFT_ENT,        TG(3),       LT1_SPC, KC_RCTL, OSM_CMD, XXXXXXX, XXXXXXX
),

LAYOUT( /* 1 */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, KC_TILD, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

LAYOUT( /* 2 */
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

LAYOUT( /* 3 */
    QK_BOOT, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_BTN1, KC_WH_D, KC_WH_U, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),
};
