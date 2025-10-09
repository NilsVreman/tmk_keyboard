#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

/**
 * Quick intro to shorthands:
 * xCTL = <Left/Right> Control
 * xSFT = <Left/Right> Shift
 * xALT = <Left/Right> Alt
 * xGUI = <Left/Right> GUI (Windows/Command key)
 * xBRC = <Left/Right> Bracket
 * SCLN = Semicolon
 * QUOT = Quote
 * COMM = Comma
 * SLSH = Slash
 * ENT  = Enter
 * SPC  = Space
 * BSPC = Backspace
 * FNx  = Fn key, where x is the Fn key number in fn_actions
 * GRV  = Grave
 * NUHS = Non-US Hash (ISO key, next to left shift on UK/US keyboards)
 * NUBS = Non-US Backslash (ISO key, next to left shift on UK/US keyboards)
 */

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: alphas
     * ,-----------------------------.,-----------------------------.
     * |Tab |   Q|   W|   E|   R|   T||   Y|   U|   I|   O|   P|   -|
     * |-----------------------------||-----------------------------|
     * |L1  |   A|   S|   D|   F|   G||   H|   J|   K|   L|   ;|   '|
     * |-----------------------------||-----------------------------|
     * |Shft|   Z|   X|   C|   V|   B||   N|   M|   ,|   .|   /|Ctrl|
     * |-----------------------------||-----------------------------|
     * |Ctrl| Alt| Win| Alt| Win|  L2|| Spc|Bspc| Ent|  L1|  L2|  L3|
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, MINS,
		 FN1,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,
		LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RCTL,
		LCTL, LALT, LGUI, LALT, LGUI,  FN2,  SPC, BSPC,  ENT,  FN1,  FN2,  FN3
		),
	/* 0.5: Flip Win and Alt
     * ,-----------------------------.,-----------------------------.
     * |    |    |    |    |    |    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * |    | Win| Alt| Win| Alt|    ||    |    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, LGUI, LALT, LGUI, LALT, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS
		),
	/* 1: symbols and arrows
     * ,-----------------------------.,-----------------------------.
     * |   `|   !|   "|   £|   $|   %||   ^|   &|   *|   (|   )|   =|
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||Left|  Up|Down|Rght|   ||   #|
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||   [|   {|   }|   ]|   \|    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |  L3||    |    | Del|    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 GRV,  FN9, FN10, FN11, FN12, FN13, FN14, FN15, FN16, FN17, FN18,  EQL,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LEFT, DOWN,   UP, RGHT, FN24, NUHS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LBRC, FN22, FN21, RBRC, NUBS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,  FN3, TRNS, DEL, TRNS, TRNS, TRNS, TRNS
		),
	/* 2: numpad, f-keys and large scale movement
     * ,-----------------------------.,-----------------------------.
     * | Esc|    |  F7|  F8|  F9| F12||    |   7|   8|   9|   =|    |
     * |-----------------------------||-----------------------------|
     * |  L3| Alt|  F4|  F5|  F6| F11||    |   4|   5|   6|   +|   ~|
     * |-----------------------------||-----------------------------|
     * |    |    |  F1|  F2|  F3| F10||    |   1|   2|   3|    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||   0|    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 ESC, TRNS,   F2,   F3,   F9,  F12, TRNS,    7,    8,    9,  EQL,   NO,
		 FN3, LALT,   F4,   F5,   F6,  F11, TRNS,    4,    5,    6, FN20, FN23,
		TRNS, TRNS,   F1,   F2,   F3,  F10, TRNS,    1,    2,    3, SLSH, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,    0, TRNS, TRNS, TRNS, TRNS, TRNS
		),
	/* 3: function and media, Everyting else is blocked
     * ,-----------------------------.,-----------------------------.
     * |    |Prev|Next|  V-|  V+|    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |Tab-|Tab+|    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * |    |PScr| Ins| App|Play|Mute||    |    |    |    |SwWA|    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||    |    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		TRNS,   NO,   NO, VOLD, VOLU, MUTE,   NO,   NO,   NO,   NO,   NO,   NO,
		TRNS,   NO,  FN5,  FN8,  FN7,  FN6,   NO,   NO,   NO,   NO,   NO,   NO,
		TRNS,   NO,   NO, MPRV, MNXT, MPLY, PSCR,  INS,  APP,   NO,  FN0, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS
		),
};

const action_t PROGMEM fn_actions[] = {
	// Layers
	[0] = ACTION_LAYER_TOGGLE(1), // Flip Win/Alt layer
	[1] = ACTION_LAYER_MOMENTARY(2),
	[2] = ACTION_LAYER_MOMENTARY(3),
	[3] = ACTION_LAYER_MOMENTARY(4),

	// Unused
	[4] = ACTION_LAYER_MOMENTARY(5),

	// Macros
	[5] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT),
	[6] = ACTION_MODS_KEY(MOD_LALT, KC_RGHT),
	[7] = ACTION_MODS_KEY(MOD_LCTL, KC_TAB), // Ctrl+Tab
	[8] = ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_TAB), // Ctrl+Shift+Tab

	// Special Characters
	[9]  = ACTION_MODS_KEY(MOD_LSFT, KC_1), // !
	[10] = ACTION_MODS_KEY(MOD_LSFT, KC_2), // "
	[11] = ACTION_MODS_KEY(MOD_LSFT, KC_3), // £
	[12] = ACTION_MODS_KEY(MOD_LSFT, KC_4), // $
	[13] = ACTION_MODS_KEY(MOD_LSFT, KC_5), // %
	[14] = ACTION_MODS_KEY(MOD_LSFT, KC_6), // ^
	[15] = ACTION_MODS_KEY(MOD_LSFT, KC_7), // &
	[16] = ACTION_MODS_KEY(MOD_LSFT, KC_8), // *
	[17] = ACTION_MODS_KEY(MOD_LSFT, KC_9), // (
	[18] = ACTION_MODS_KEY(MOD_LSFT, KC_0), // )
	[19] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // _
	[20] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL), // +
	[21] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // }
	[22] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC), // {
	[23] = ACTION_MODS_KEY(MOD_LSFT, KC_NUHS), // ~
	[24] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS), // |
};
