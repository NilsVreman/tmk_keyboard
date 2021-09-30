#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0:
     * ,-----------------------------.,-----------------------------.
     * |Tab |   Q|   W|   E|   R|   T||   Y|   U|   I|   O|   P|   Å|
     * |-----------------------------||-----------------------------|
     * |Ctrl|   A|   S|   D|   F|   G||   H|   J|   K|   L|   Ö|   Ä|
     * |-----------------------------||-----------------------------|
     * |Shft|   Z|   X|   C|   V|   B||   N|   M|   ,|   .|   -| Ent|
     * |-----------------------------||-----------------------------|
     * |Alt | Win|Ctrl|  L3| Win|  L1|| Spc|  L2|Shft|BSpc| Del|    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC,
		LCTL,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,
		LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,  ENT,
		LALT, LGUI, LCTL,  FN3, LGUI,  FN1,  SPC,  FN2, LSFT, BSPC,  DEL,   NO
		),
	/* 0.5:
     * ,-----------------------------.,-----------------------------.
     * |    |    |    |    |    |    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||    |    |    |    |    |    |
     * |-----------------------------||-----------------------------|
     * | Win|    |    |    | Alt|    ||    |    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		LGUI, TRNS, TRNS, TRNS, LALT, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS
		),
	/* 1:
     * ,-----------------------------.,-----------------------------.
     * | Esc|Prev|Next|  V-|  V+|Mute||   /|   (|   )|   \|   ?|   +|
     * |-----------------------------||-----------------------------|
     * |    |    |Home|PgUp|PgDn| End||   [|   {|   }|   ]|   *|   '|
     * |-----------------------------||-----------------------------|
     * |    |Play|Alt<|Tab-|Tab+|Alt>||   =|   <|   >|   ~|   ^|    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||    |  L3|    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 ESC, MPRV, MNXT, VOLD, VOLU, MUTE, FN16, FN18, FN20, FN25, FN24, MINS,
		TRNS, TRNS, HOME, PGUP, PGDN,  END, FN19, FN17, FN23, FN21, FN29, NUHS,
		TRNS, MPLY,  FN5,  FN8,  FN7,  FN6, FN22, NUBS, FN30, FN28, FN27, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  FN3, TRNS, TRNS, TRNS, TRNS
		),
	/* 2:
     * ,-----------------------------.,-----------------------------.
     * |Esc |   !|   "|   #|   %|   &||    |Bspc| Del|    |    | Ent|
     * |-----------------------------||-----------------------------|
     * |    |   ||   @|XXXX|   $|XXXX||Left|Down|  Up|Rhgt|    |    |
     * |-----------------------------||-----------------------------|
     * |    |Ct-Z|    |   `|   ´|    ||    |Menu| Ins|PrSc|    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |  L3||    |    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 ESC,  FN9, FN10, FN12, FN14, FN15,   NO, BSPC,  DEL,   NO,   NO, FN28,
		TRNS, FN31, FN11,   NO, FN13,   NO, LEFT, DOWN,   UP, RGHT,   NO,   NO,
		TRNS,  FN4,   NO, FN26,  EQL,   NO,   NO,  APP,  INS, PSCR,   NO, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,  FN3, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS
		),
	/* 3:
     * ,-----------------------------.,-----------------------------.
     * | Esc|    |  F1|  F2|  F3|  F4||    |   7|   8|   9|    |W->A|
     * |-----------------------------||-----------------------------|
     * |    | Alt|  F5|  F5|  F7|  F8||    |   4|   5|   6|    |    |
     * |-----------------------------||-----------------------------|
     * |    |    |  F9| F10| F11| F12||   0|   1|   2|   3| Win|    |
     * |-----------------------------||-----------------------------|
     * |    |    |    |    |    |    ||   0|    |    |    |    |    |
     * `-----------------------------'`-----------------------------'
     */
	KEYMAP(
		 ESC,   NO,   F1,   F2,   F3,   F4,   NO,    7,    8,    9,   NO,  FN0,
		TRNS, LALT,   F5,   F6,   F7,   F8,   NO,    4,    5,    6,   NO,   NO,
		TRNS,   NO,   F9,  F10,  F11,  F12,    0,    1,    2,    3, LGUI, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,    0, TRNS, TRNS, TRNS, TRNS, TRNS
		),
};

const action_t PROGMEM fn_actions[] = {
	// Layers
	[0] = ACTION_LAYER_TOGGLE(1),
	[1] = ACTION_LAYER_MOMENTARY(2),
	[2] = ACTION_LAYER_MOMENTARY(3),
	[3] = ACTION_LAYER_MOMENTARY(4),

	// Unused

	// Macros
	[4] = ACTION_MODS_KEY(MOD_LCTL, KC_Z),
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


