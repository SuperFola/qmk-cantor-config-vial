// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum custom_keycodes {
    M_EACUT = SAFE_RANGE,  // é
    M_EAGRV,  // è
    M_EACIR,  // ê
    M_AAGRV,  // à
    M_AACIR,  // â
    M_UAGRV,  // ù
    M_UACIR,  // û
    M_OACIR,  // ô
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case M_EACUT:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_E));
            break;
        case M_EAGRV:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_E));
            break;
        case M_EACIR:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_E));
            break;
        case M_AAGRV:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_A));
            break;
        case M_AACIR:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_A));
            break;
        case M_UAGRV:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_U));
            break;
        case M_UACIR:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_U));
            break;
        case M_OACIR:
            if (record->event.pressed)
                SEND_STRING(SS_LALT(SS_TAP(X_I)) SS_DELAY(100) SS_TAP(X_O));
            break;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layout
    [0] = LAYOUT_split_3x6_3(
        KC_DEL,     KC_Q,       KC_W,        KC_E,        KC_R,        KC_T,            KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,       KC_CAPS,
        KC_LALT,    KC_A,       SFT_T(KC_S), CMD_T(KC_D), CTL_T(KC_F), LT(1, KC_G),     LT(1, KC_H), CTL_T(KC_J), CMD_T(KC_K), SFT_T(KC_L), KC_SCLN,    KC_LALT,
        MO(4),      KC_Z,       KC_X,        KC_C,        KC_V,        KC_B,            KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,    XXXXXXX,
                                             KC_TAB,   LT(3, KC_SPC),  KC_ESC,          OSL(2),      KC_BSPC,     KC_ENT
    ),

    // symbols
    [1] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_TRNS,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,           KC_LT,      KC_UNDS,    KC_EQL,     KC_HASH,    KC_TRNS,    KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRV,            KC_MINS,    KC_DQT,     KC_QUOT,    KC_ASTR,    KC_PLUS,    KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,           KC_GT,      KC_AMPR,    KC_PERC,    KC_EXLM,    KC_BSLS,    KC_TRNS,
                                         KC_TRNS,    KC_TRNS,    KC_TRNS,           KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    // OSL french
    [2] = LAYOUT_split_3x6_3(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    M_EACUT,    M_EAGRV,    XXXXXXX,        XXXXXXX,    M_UAGRV,    XXXXXXX,    M_OACIR,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    M_AAGRV,    M_AACIR,    XXXXXXX,    M_EACIR,    XXXXXXX,        XXXXXXX,    M_UACIR,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    A(KC_C),    XXXXXXX,    XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                            KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    // functions and arrows
    [3] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                 KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_F14,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F15,
                                   KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // numpad
    [4] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_DOT,  KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX,
                                   KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    )
};

    // [n] = LAYOUT_split_3x6_3(
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //                                KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    // )
