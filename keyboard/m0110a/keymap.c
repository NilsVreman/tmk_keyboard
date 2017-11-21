#include "keymap_common.h"

/*
 * Hasu
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     */
    KEYMAP(
         ESC,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS, NUHS, BSPC,    DEL, FN13, PSLS, PAST, \
         TAB,     Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC,          P7,   P8,   P9, PMNS, \
         FN0,      A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,    ENT,       P4,   P5,   P6, PPLS, \
        LSFT,       Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,  LGUI,    FN0,     P1,   P2,   P3,       \
        LCTL, LALT,                             SPC,                LEFT, DOWN,   UP, RGHT,     P0,       PDOT, PENT),
    /* Layer 1: Special Access
     */
    KEYMAP(
        TRNS,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12, TRNS,   TRNS,   NO,   NO,   NO, \
        TRNS,    NO,  FN1,  FN2,  FN3,   NO,  FN4,  FN5,  FN6,  FN7,   NO,  FN8,  FN9,        MPRV, MNXT, MPLY,   NO, \
        TRNS,   FN10, NUBS, FN11,   NO,   NO, LEFT, DOWN,   UP, RGHT,   NO,   NO,   TRNS,     VOLD, VOLU, MUTE,   NO, \
        TRNS,     EQL, FN12,   NO,   NO,   NO, HOME, PGDN, PGUP,  END,   NO,  TRNS,   TRNS,    INS,  APP, PSCR,       \
        TRNS, TRNS,                            TRNS,                TRNS, TRNS, TRNS, TRNS,     NO,         NO, TRNS),
    /* Layer 2: NOOOOOO
     */
    KEYMAP(
          NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,     NO,   NO,   NO,   NO, \
          NO,    NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,          NO,   NO,   NO,   NO, \
          NO,     NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,     NO,       NO,   NO,   NO,   NO, \
          NO,      NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,    NO,     NO,     NO,   NO,   NO,       \
          NO,   NO,                              NO,                  NO,   NO,   NO,   NO,     NO,         NO,   NO),
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_MODS_KEY(MOD_RALT, KC_2),     // @
    [2] = ACTION_MODS_KEY(MOD_RALT, KC_3),     // £
    [3] = ACTION_MODS_KEY(MOD_RALT, KC_4),     // $
    [4] = ACTION_MODS_KEY(MOD_RALT, KC_7),     // {
    [5] = ACTION_MODS_KEY(MOD_RALT, KC_0),     // }
    [6] = ACTION_MODS_KEY(MOD_RALT, KC_8),     // [
    [7] = ACTION_MODS_KEY(MOD_RALT, KC_9),     // ]
    [8] = ACTION_MODS_KEY(MOD_RALT, KC_MINS),  // backslash
    [9] = ACTION_MODS_KEY(MOD_RALT, KC_RBRC),  // ~ tilde
    [10] = ACTION_MODS_KEY(MOD_RALT, KC_NUBS), // | pipe
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS), // > right pointy-bracket
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),  // ` back-apostrohe
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_0),    // Numpad equals
};
