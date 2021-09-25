/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

// WARNING THIS IS A GERMAN LAYOUT

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "keymap_extras/keymap_german.h"

enum {
    BASE,	// default layer
    SYMB,	// special characters
    NUMB,	// numbers/function/motion
	GAME	// gaming layer
};

/* Combomap
 *
 * .-----------------------------.		.-----------------------------.
 * |     |     |     |     |     |		|     |     |     |     |     |
 * |-----+-----+-----+-----+-----|		|-----+-----+-----+-----+-----|
 * |     |     |     |     |     |		|     |     |     |     |     | 
 * |-----+-----+-----+-----+-----|		|-----+-----+-----+-----+-----|
 * |     |     |     |     |     |		|     |     |     |     |     |
 * '-----------------------------'		'-----------------------------'
 *  		   .-----------------.      .-----------------.   
 *  		   |     |     |     |      |     |     |     |
 *  		   '-----------------'      '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * .--------------------------------.	.--------------------------------.
 * |  Q   |  W  |  F   |  P   |  G  |	|  J  |   L  |   U  |  Y  |   =  |
 * |------+-----+------+------+-----|	|-----+------+------+-----+------|
 * |META/A|ALT/R|SHFT/S|CTRL/T|  D  |	|  H  |CTRL/N|SHFT/E|ALT/I|META/O|
 * |------+-----+------+------+-----|	|-----+------+------+-----+------|
 * |  Z   |  X  |  C   |  V   |  B  |	|  K  |   M  |   ,  |  .  |   -  |
 * '--------------------------------'	'--------------------------------'
 * 				  .-----------------.	.------------------.
 * 				  |SYMB | SPC | TAB |	| BSPC | ENT | NUMB|
 * 				  '-----------------'	'------------------'
 */
[BASE] = LAYOUT_split_3x5_3(
    DE_Q,				DE_W,				DE_F,				DE_P,				DE_G,	DE_J,		DE_L,				DE_U,				DE_Y,				DE_EQL,
    MT(MOD_LGUI,DE_A),	MT(MOD_LALT,DE_R),	MT(MOD_LSFT,DE_S),	MT(MOD_LCTL,DE_T),	DE_D,	DE_H,		MT(MOD_RCTL,DE_N),	MT(MOD_RSFT,DE_E),	MT(MOD_RALT,DE_I),	MT(MOD_RGUI, DE_O),
    DE_Z,				DE_X,				DE_C,				DE_V,				DE_B,	DE_K,		DE_M,				DE_COMM,			DE_DOT,				DE_MINS,

 	TG(SYMB),			KC_SPC,				KC_TAB,											KC_BSPC,	KC_ENT,				TG(NUMB)
    ),
/* Keymap 1: Symbols layer
 *
 * .-----------------------------.		.-----------------------------.
 * |  <  |  >  |  {  |  }  |  \  |		|  &  |  %  |  ~  |  ü  |  @  |
 * |-----+-----+-----+-----+-----|		|-----------------------------|
 * |  '  |  "  |  (  |  )  |  /  |		|  !  |  ?  |  ä  |  ö  |  ß  | 
 * |-----+-----+-----+-----+-----|		|-----------------------------|
 * |  ^  |  #  |  [  |  ]  |  |  |		|  *  |  +  |  €  |  $  |  `  |
 * '-----------------------------'		'-----------------------------'
 *  		   .-----------------.		.------------------.   
 *  		   |     |     |     |		|     |     |      |
 *  		   '-----------------'		'------------------' 
 */
[SYMB] = LAYOUT_split_3x5_3(
    DE_LABK,	DE_RABK,	DE_LCBR,	DE_RCBR,	DE_BSLS,	DE_AMPR,	DE_PERC,	DE_TILD,	DE_UDIA,	DE_AT,
    DE_QUOT,	DE_DQUO,	DE_LPRN,	DE_RPRN,	DE_SLSH,	DE_EXLM,	DE_QUES,	DE_ADIA,	DE_ODIA,	DE_SS,
    DE_CIRC,	DE_HASH,	DE_LBRC,	DE_RBRC,	DE_PIPE,	DE_ASTR,	DE_PLUS,	DE_EURO,	DE_DLR,		DE_GRV,

    KC_TRNS,	KC_TRNS,	KC_TRNS,							KC_TRNS,	KC_TRNS,	KC_TRNS
    ),
/* Keymap 2: Number/Nav layer
 *
 * .------------------------------------.	.-----------------------------.
 * |  F1   |  F2  |  F3   |  F4   | F5  |	|NLCK |  7  |  8  |  9  |GAME |
 * |-------+------+-------+-------+-----|	|-----+-----+-----+-----------|
 * |META/F6|ALT/F7|SHFT/F8|CTRL/F9| F10 |	| ESC |  4  |  5  |  6  |  0  | 
 * |-------+------+-------+-------+-----|	|-----+-----+-----+-----------|
 * |  F11  | F12  |       |       |     |	|     |  1  |  2  |  3  |  ,  |
 * '------------------------------------'	'-----------------------------'
 * 				      .-----------------.	.-----------------.   
 *  			      |     |     |     |	|     |     |     |
 *  			      '-----------------'	'-----------------' 
 */
[NUMB] = LAYOUT_split_3x5_3(
    KC_F1,				KC_F2,				KC_F3,				KC_F4,				KC_F5,		KC_NLCK,	KC_P7,	KC_P8,	KC_P9,	TG(GAME),
    MT(MOD_LGUI,KC_F6),	MT(MOD_LALT,KC_F7),	MT(MOD_LSFT,KC_F8),	MT(MOD_LCTL,KC_F9),	KC_F10,		KC_ESC,		KC_P4,	KC_P5,	KC_P6,	KC_P0,
    KC_F11,				KC_F12,				KC_TRNS,			KC_TRNS,			KC_TRNS,	KC_TRNS,	KC_P1,	KC_P2,	KC_P3,	KC_PDOT,

	KC_TRNS,	KC_TRNS,	KC_TRNS,  															KC_TRNS,	KC_TRNS,	KC_TRNS
    ),
/* Keymap 3: Game layer
 *
 * .-----------------------------.		.-----------------------------.
 * | TAB |  Q  |  W  |  E  |  R  |		|  6  |  7  |  8  |  9  |GAME |
 * |-----+-----+-----+-----+-----|		|-----+-----+-----+-----+-----|
 * |SHFT |  A  |  S  |  D  |  F  |		|  1  |  2  |  3  |  4  |  5  |
 * |-----+-----+-----+-----+-----|		|-----+-----+-----+-----+-----|
 * |CTRL |  Z  |  X  |  C  |  V  |		|  Y  |  I  |  G  |  M  |  0  |
 * '-----------------------------'		'-----------------------------'
 * 			   .-----------------.		.-----------------.
 * 			   | ALT | SPC | ESC |		|  ^  | ENT |BASE |
 * 			   '-----------------'		'-----------------'
 */
[GAME] = LAYOUT_split_3x5_3(
    KC_TAB,		DE_Q,	DE_W,	DE_E,	DE_R,	KC_6,		KC_7,	KC_8,	KC_9,	TG(GAME),
    KC_LSFT,	DE_A,	DE_S,	DE_D,	DE_F,	KC_1,		KC_2,	KC_3,	KC_4,	KC_5,
    KC_LCTL,	DE_Z,	DE_X,	DE_C,	DE_V,	DE_Y,		DE_I,	DE_G,	DE_M,	KC_0,

 	KC_LALT,	KC_SPC,	KC_ESC,					DE_CIRC,	KC_ENT,	TG(BASE)
    )
};
