// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _BASE 0
#define _SPECIAL 1
#define _NUMERIC 2

// Macro name shortcuts
#define BASE       MO(_BASE)
#define SPECIAL    MO(_SPECIAL)
#define NUMERIC    MO(_NUMERIC)


// Combo (breakers)
#define PROGnxt RALT(KC_TAB)
#define PROGlst RSFT(RALT(KC_TAB))

#define CMDENTR LCTL(KC_ENT)

// Fillers to make layering more clear
#define ___t___    KC_TRNS
#define _______    KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Note to self: To load this onto the keyboard press the reset button on the back
// navigate to the following in a terminal:
//    .../qmk_firmware/keyboards/planck/keymaps/saha_middle_out
// Then run the following commands:
//    sudo make clean && sudo make KEYMAP=saha_middle_out dfu


[_BASE] = {
    {  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_ESC,   /****/  KC_DELT,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P     },
    {  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_BSPC,  /****/  KC_ENT,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN  },
    {  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     _______,  /****/  _______,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH  },
    {  KC_RSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_SPC,   KC_LGUI,  /****/  KC_RSFT,  SPECIAL,  NUMERIC,  _______,  PROGlst,  PROGnxt  }
},

[_SPECIAL] = {
    {  KC_GRV,   KC_DQUO,  KC_LCBR,  KC_LCBR,  KC_PLUS,  KC_ESC,   /****/  KC_ESC,   KC_AMPR,  KC_HOME,  KC_UP,    KC_END,   KC_P     },
    {  KC_TAB,   KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_EQL,   ___t___,  /****/  CMDENTR,  KC_EXLM,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_QUOT  },
    {  KC_Z,     KC_X,     KC_LBRC,  KC_RBRC,  KC_MINS,  _______,  /****/  ___t___,  KC_PIPE,  KC_UNDS,  KC_COMM,  KC_DOT,   KC_SLSH  },
    {  ___t___,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_SPC,   KC_LGUI,  /****/  KC_RSFT,  ___t___,  _______,  KC_DOWN,  KC_UP,    KC_RGHT  }
},

[_NUMERIC] = {
    {  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  ___t___,  /****/  ___t___,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN  },
    {  KC_1,     KC_2,     KC_3,     KC_4,        KC_5,  ___t___,  /****/  ___t___,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0     },
    {  _______,  _______,  _______,  _______,  _______,  ___t___,  /****/  ___t___,  KC_PIPE,  KC_UNDS,  KC_COMM,  KC_DOT,   KC_SLSH  },
    {  ___t___,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_SPC,   KC_LGUI,  /****/  ___t___,  _______,  ___t___,  _______,  _______,  _______  }
}

};
