#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: alphas
     * ,-----------------------------.,-----------------------------.
     * |Tab |   Q|   W|   E|   R|   T||   Y|   U|   I|   O|   P|   Å|
     * |-----------------------------||-----------------------------|
     * |L1  |   A|   S|   D|   F|   G||   H|   J|   K|   L|   Ö|   Ä|
     * |-----------------------------||-----------------------------|
     * |Shft|   Z|   X|   C|   V|   B||   N|   M|   ,|   .|   -| Ent|
     * |-----------------------------||-----------------------------|
     * |Ctrl| Alt| Win| Alt| Win|  L2|| Spc|Bspc| Del|  L1|  L2|  L3|
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC,
		 FN1,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,
		LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,  ENT,
		LCTL, LALT, LGUI, LALT, LGUI,  FN2,  SPC, BSPC,  DEL,  FN1,  FN2,  FN3
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
     * |    |   !|   "|   #|   %|   &||   /|   (|   )|   \|   ?|   ^|
     * |-----------------------------||-----------------------------|
     * |    |   ||   @|XXXX|   $|XXXX||Left|  Up|Down|Rhgt|   `|   '|
     * |-----------------------------||-----------------------------|
     * |    |XXXX|XXXX| F11| F12|   ¨||   [|   {|   }|   ]|   ´|    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |  L3||    |    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		TRNS,  FN9, FN10, FN12, FN14, FN15, FN16, FN18, FN20, FN25, FN24, FN27,
		TRNS, FN31, FN11,   NO, FN13,   NO, LEFT, DOWN,   UP, RGHT, FN26, NUHS,
		TRNS,   NO,   NO,  F11,  F12, RBRC, FN19, FN17, FN23, FN21,  EQL, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,  FN3, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS
		),
	/* 2: numpad, f-keys and large scale movement
     * ,-----------------------------.,-----------------------------.
     * |Esc |  F1|  F2|  F3|  F4|  F5||   =|   7|   8|   9|   +|   ~|
     * |-----------------------------||-----------------------------|
     * |  L3|Alt |Home|PgUp|PgDn| End||   <|   4|   5|   6|   /|   *|
     * |-----------------------------||-----------------------------|
     * |    |  F6|  F7|  F8|  F9| F10||   >|   1|   2|   3|   -|    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||   0|    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 ESC,   F1,   F2,   F3,   F4,   F5, FN22,    7,    8,    9, MINS, FN28,
		 FN3, LALT, HOME, PGUP, PGDN,  END, NUBS,    4,    5,    6, FN16, FN29,
		TRNS,   F6,   F7,   F8,   F9,  F10, FN30,    1,    2,    3, SLSH, TRNS,
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
	[11] = ACTION_MODS_KEY(MOD_RALT, KC_2), // @
	[12] = ACTION_MODS_KEY(MOD_LSFT, KC_3), // #
	[13] = ACTION_MODS_KEY(MOD_RALT, KC_4), // $
	[14] = ACTION_MODS_KEY(MOD_LSFT, KC_5), // %
	[15] = ACTION_MODS_KEY(MOD_LSFT, KC_6), // &	
	[16] = ACTION_MODS_KEY(MOD_LSFT, KC_7), // /
	[17] = ACTION_MODS_KEY(MOD_RALT, KC_7), // {
	[18] = ACTION_MODS_KEY(MOD_LSFT, KC_8), // (
	[19] = ACTION_MODS_KEY(MOD_RALT, KC_8), // [
	[20] = ACTION_MODS_KEY(MOD_LSFT, KC_9), // )
	[21] = ACTION_MODS_KEY(MOD_RALT, KC_9), // ]
	[22] = ACTION_MODS_KEY(MOD_LSFT, KC_0), // =
	[23] = ACTION_MODS_KEY(MOD_RALT, KC_0), // }
	[24] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS), // ?
	[25] = ACTION_MODS_KEY(MOD_RALT, KC_MINS), // backslash
	[26] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL), // `
	[27] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC), // ^
	[28] = ACTION_MODS_KEY(MOD_RALT, KC_RBRC), // ~
	[29] = ACTION_MODS_KEY(MOD_LSFT, KC_NUHS), // *
	[30] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS), // >
	[31] = ACTION_MODS_KEY(MOD_RALT, KC_NUBS), // |
};
