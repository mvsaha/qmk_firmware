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
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _FCT 5
#define _SETUP 6
#define _MAC 7
#define _WIN 8
#define _LIN 9
#define _MICMUTE 16
#define _OS 17


// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define COLEMAK M(_COLEMAK)
#define DVORAK M(_DVORAK)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define FCT M(_FCT)
#define OS M(_OS)
#define MAC M(_MAC)
#define WIN M(_WIN)
#define LIN M(_LIN)
#define MICMUTE M(_MICMUTE)

#define MACPRNT LGUI(LSFT(KC_3))
#define MACPRNT2 LGUI(LSFT(KC_4))
#define WINPRNT KC_PSCR
#define WINPRNT2 LGUI(KC_PSCR)
#define CYCLWIN LGUI(KC_GRV)
#define MACSLEEP LSFT(LCTL(KC_POWER))
#define WINSLEEP KC_SLEP

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   
[_QWERTY] = {
   {KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,  KC_ESC,  KC_ESC,  KC_Y,  KC_U,    KC_I,    KC_O,    KC_P},
   {KC_A,  KC_S,    KC_D,    KC_F,    KC_G,  KC_ESC,  KC_ENT,  KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN},
   {KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,  KC_QUOT, KC_ESC,  KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH },
   {OS,    KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,  RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
   },

};