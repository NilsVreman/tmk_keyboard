/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
		    K30,  K31, K32, K33, K34,      K36,      K38, K39, K3A       \
		) { \
	    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B}, \
	    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B}, \
	    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B}, \
	    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_NO   , KC_##K36, KC_NO,    KC_##K38, KC_##K39, KC_##K3A, KC_NO}, \
}


static const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: alphas
     * ,-------------------------------------------------.
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  Å|
     * |-------------------------------------------------|
     * |L1   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä|
     * |-------------------------------------------------|
     * |Shft |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|   |
     * |---------------------------------------------|Ent|
     * |Ctrl |Win| L3 |Alt|  L2| Space |  L1|Del|Bspc|   |
     * `-------------------------------------------------'
     */
	KEYMAP(
		 TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC,
		 FN0,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,
		LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,  ENT,
		LCTL, LGUI,  FN2, LALT,  FN1,        SPC,        FN0,  DEL, BSPC
		),
	/* 1: symbols and nav
     * ,-------------------------------------------------.
     * |    §|  !|  "|  #|  ¤|  %|  /|  (|  )|  \|  ?|  ^|
     * |-------------------------------------------------|
     * |L1   |   |  @|  £|  $|  &|Lft| Up|Dwn|Rht|  ~|  '|
     * |-------------------------------------------------|
     * |Shft |  ||   |  `|  ´|  ¨|  [|  {|  }|  ]|   |   |
     * |---------------------------------------------|Ent|
     * |Ctrl |Win| L3 |Alt|  L2| Space |  L1|Del|Bspc|   |
     * `-------------------------------------------------'
     */
	KEYMAP(
		 GRV,  FN6,  FN7,  FN9, FN11, FN13, FN16, FN18, FN20, FN25, FN24, FN27,
		TRNS,   NO,  FN8, FN10, FN12, FN15, LEFT, DOWN,   UP, RGHT, FN28, NUHS,
		TRNS, FN31,   NO, FN26,  EQL, RBRC, FN19, FN17, FN23, FN21,   NO, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS
		),
	/* 2: numerals and mouse helper
     * ,-------------------------------------------------.
     * |Esc  |PgU| Up|PgD|Hom|Bsp|  =|  7|  8|  9|  +|  -|
     * |-------------------------------------------------|
     * |Alt  |Lft|Dwn|Rht|End|Del|  <|  4|  5|  6|  *|  /|
     * |-------------------------------------------------|
     * |Shft |   |   |   |   |Ent|  >|  1|  2|  3|  ^|   |
     * |---------------------------------------------|Ent|
     * |Ctrl |Win| L3 |Alt|  L2|   0   |   ,|  .|    |   |
     * `-------------------------------------------------'
     */
	KEYMAP(
		 ESC, PGUP,   UP, PGDN, HOME, BSPC, FN22,    7,    8,    9, MINS, SLSH,
		LALT, LEFT, DOWN, RGHT,  END,  DEL, NUBS,    4,    5,    6, FN29, FN16,
		TRNS,   NO,   NO,   NO,   NO,  ENT, FN30,    1,    2,    3, FN27, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,          0,       COMM,  DOT, TRNS
		),
	/* 3: function and media
     * ,-------------------------------------------------.
     * |Esc  | F1| F2| F3| F4|PSc|Prv|Nxt|Ply|   |   |   |
     * |-------------------------------------------------|
     * |Alt  | F5| F6| F7| F8|Ins| V-| V+|Mut|   |   |   |
     * |-------------------------------------------------|
     * |Shft | F9|F10|F11|F12|App|   |   |   |   |   |   |
     * |---------------------------------------------|   |
     * |Ctrl |Win| L3 |Alt|  L2|       |    |   |    |   |
     * `-------------------------------------------------'
     */
	KEYMAP(
		 ESC,   F1,   F2,   F3,   F4, PSCR, MPRV, MNXT, MPLY, TRNS, TRNS, TRNS,
		LALT,   F5,   F6,   F7,   F8,  INS, VOLD, VOLU, MUTE, TRNS, TRNS, TRNS,
		TRNS,   F9,  F10,  F11,  F12,  APP, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS
		),
	KEYMAP(
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS, TRNS, TRNS
		),
};

static const action_t fn_actions[] = {
	[0] = ACTION_LAYER_MOMENTARY(1),
	[1] = ACTION_LAYER_MOMENTARY(2),
	[2] = ACTION_LAYER_MOMENTARY(3),
	[3] = ACTION_LAYER_MOMENTARY(4),
	[4] = ACTION_LAYER_MOMENTARY(5),
	[5] = ACTION_LAYER_MOMENTARY(6),
	
	[6]  = ACTION_MODS_KEY(MOD_LSFT, KC_1), // !	
	[7]  = ACTION_MODS_KEY(MOD_LSFT, KC_2), // "
	[8]  = ACTION_MODS_KEY(MOD_RALT, KC_2), // @
	[9]  = ACTION_MODS_KEY(MOD_LSFT, KC_3), // #
	[10] = ACTION_MODS_KEY(MOD_RALT, KC_3), // £
	[11] = ACTION_MODS_KEY(MOD_LSFT, KC_4), // ¤
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

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    return keymaps[(layer)][(key.row)][(key.col)];
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return fn_actions[FN_INDEX(keycode)];
}
