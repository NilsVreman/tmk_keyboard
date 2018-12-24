#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

#define KEYMAP( \
		    K00,  K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
		    K10,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
		    K20,  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
		    K30,  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B \
		) { \
	    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B}, \
	    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B}, \
	    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B}, \
	    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B}, \
}


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: alphas
     * ,-----------------------------.      ,-----------------------------.
     * |Tab |   Q|   W|   E|   R|   T|      |   Y|   U|   I|   O|   P|   Å|
     * |-----------------------------|      |-----------------------------|
     * |L1  |   A|   S|   D|   F|   G|      |   H|   J|   K|   L|   Ö|   Ä|
     * |-----------------------------|      |-----------------------------|
     * |Shft|   Z|   X|   C|   V|   B|      |   N|   M|   ,|   .|   -|XXXX|
     * |--------------------------------.,--------------------------------|
     * |Ctrl| Win|  L3|  |  L1| Alt|  L2|| Spc|Bspc| Del|  |XXXX|  L1| Ent|
     * `--------------'  `--------------'`--------------'  `--------------'
     */
	KEYMAP(
		 TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC,
		 FN0,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,
		LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,   NO,
		LCTL, LGUI,  FN2,  FN0, LALT,  FN1,  SPC, BSPC,  DEL,   NO,  FN0,  ENT
		),
	/* 1: symbols and arrows
     * ,-----------------------------.      ,-----------------------------.
     * |Esc |   !|   "|   #|   %|   &|      |   /|   (|   )|   \|   ?|   ^|
     * |-----------------------------|      |-----------------------------|
     * |    |   ||   @|Tab-|   $|Tab+|      |Left|  Up|Down|Rhgt|XXXX|   '|
     * |-----------------------------|      |-----------------------------|
     * |    |XXXX|XXXX|   `|   ´|   ¨|      |   [|   {|   }|   ]|XXXX|    |
     * |--------------------------------.,--------------------------------|
     * |    |    |    |  |    |    |    ||    |    |    |  |    |    |    |
     * `--------------'  `--------------'`--------------'  `--------------'
     */
	KEYMAP(
		 ESC,  FN6,  FN7,  FN9, FN13, FN15, FN16, FN18, FN20, FN25, FN24, FN27,
		TRNS, FN31,  FN8, FN11, FN12, FN10, LEFT, DOWN,   UP, RGHT,   NO, NUHS,
		TRNS,   NO,   NO, FN26,  EQL, RBRC, FN19, FN17, FN23, FN21,   NO, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS
		),
	/* 2: numpad, f-keys and large scale movement
     * ,-----------------------------.      ,-----------------------------.
     * |Esc |  F1|  F2|  F3|  F4|  F5|      |   =|   7|   8|   9|   +|   ~|
     * |-----------------------------|      |-----------------------------|
     * |Alt |Home|PgUp|PgDn| End| F11|      |   <|   4|   5|   6|   /|   *|
     * |-----------------------------|      |-----------------------------|
     * |    |  F6|  F7|  F8|  F9| F10|      |   >|   1|   2|   3|   -|    |
     * |--------------------------------.,--------------------------------|
     * |    |    |    |  | F12|    |    ||   0|    |    |  |    |    |    |
     * `--------------'  `--------------'`--------------'  `--------------'
     */
	KEYMAP(
		 ESC,   F1,   F2,   F3,   F4,   F5, FN22,    7,    8,    9, MINS, FN28,
		LALT, HOME, PGUP, PGDN,  END,  F11, NUBS,    4,    5,    6, FN16, FN29,
		TRNS,   F6,   F7,   F8,   F9,  F10, FN30,    1,    2,    3, SLSH, TRNS,
		TRNS, TRNS, TRNS,  F12, TRNS, TRNS,    0, TRNS, TRNS, TRNS, TRNS, TRNS
		),
	/* 3: function and media, Everyting else is blocked
     * ,-----------------------------.      ,-----------------------------.
     * |    |Prev|Next|Play|    |    |      |    |    |    |    |    |    |
     * |-----------------------------|      |-----------------------------|
     * |    |  V-|  V+|Mute|    |    |      |    |    |    |    |    |    |
     * |-----------------------------|      |-----------------------------|
     * |    |PScr| Ins| App|    |    |      |    |    |    |    |    |    |
     * |--------------------------------.,--------------------------------|
     * |    |    |  L3|  |    |    |    ||    |    |    |  |    |    |    |
     * `--------------'  `--------------'`--------------'  `--------------'
     */
	KEYMAP(
		  NO, MPRV, MNXT, MPLY,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,
		  NO, VOLD, VOLU, MUTE,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,
		  NO, PSCR,  INS,  APP,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,
		  NO,   NO, TRNS,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO
		),
};

const action_t PROGMEM fn_actions[] = {
	// Layer 1-6
	[0] = ACTION_LAYER_MOMENTARY(1),
	[1] = ACTION_LAYER_MOMENTARY(2),
	[2] = ACTION_LAYER_MOMENTARY(3),
	[3] = ACTION_LAYER_MOMENTARY(4),
	[4] = ACTION_LAYER_MOMENTARY(5),
	[5] = ACTION_LAYER_MOMENTARY(6),

	// Macros
	[10] = ACTION_MODS_KEY(MOD_LCTL, KC_TAB), // Ctrl+Tab
	[11] = ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_TAB), // Ctrl+Shift+Tab

	// Special Characters
	[6]  = ACTION_MODS_KEY(MOD_LSFT, KC_1), // !	
	[7]  = ACTION_MODS_KEY(MOD_LSFT, KC_2), // "
	[8]  = ACTION_MODS_KEY(MOD_RALT, KC_2), // @
	[9]  = ACTION_MODS_KEY(MOD_LSFT, KC_3), // #
	[12] = ACTION_MODS_KEY(MOD_RALT, KC_4), // $
	[13] = ACTION_MODS_KEY(MOD_LSFT, KC_5), // %
	[14] = ACTION_MODS_KEY(MOD_RALT, KC_5), // €
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
