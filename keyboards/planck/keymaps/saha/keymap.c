// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
#include QMK_KEYBOARD_H
#include "planck.h"
//#include "action_layer.h"
//#ifdef AUDIO_ENABLE
//#include "audio.h"
//#endif
/*#include "eeconfig.h"*/
//extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Layers
#define BASE   0  // Base layer - QWERTY
#define SPEC   1  // Special keys favoring programming in c-like languages
#define NUM    2  // Numeric layer with number row functional keys

// Combo (breakers)
#define PROGnxt RALT(KC_TAB)
#define PROGlst RSFT(RALT(KC_TAB))

// Command center shortcuts
#define WRKSPCU LCTL(LALT(KC_UP))
#define WRKSPCD LCTL(LALT(KC_DOWN))

// Shortcuts
#define _______  KC_TRNS
#define ___X___    KC_NO

#define BSLASH  LSFT(KC_SLSH)
#define CTRLENT LCTL(KC_ENT)
#define SPC_CTL MT(MOD_LCTL, KC_SPACE)


/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
Note to self: To load this onto the keyboard press the reset button on the back
navigate to the following in a terminal:
  .../qmk_firmware/
Then run the following commands:
  sudo make planck:saha:dfu (after pressing the button on the back of the kb)
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_planck_grid(
  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_ESC,   /****/  KC_DELT,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     ___X___,  /****/  KC_ENT,   KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,
  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_BSPC,  /****/  KC_ENT,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
  WRKSPCD,  WRKSPCU,  KC_LALT,  KC_LALT,  SPC_CTL,  KC_LGUI,  /****/  KC_LSFT,  MO(SPEC), MO(NUM),  PROGlst,  PROGlst,  PROGnxt
),
[SPEC] = LAYOUT_planck_grid(
  KC_GRV,   KC_QUOT,  KC_LCBR,  KC_RCBR,  KC_PLUS,  KC_ESC,   /****/  KC_DELT,  KC_AMPR,  KC_HOME,  KC_UP,    KC_END,   KC_DQUO,
  KC_TAB,   KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_EQL,   ___X___,  /****/  CTRLENT,  KC_EXLM,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_COLN,
  KC_HASH,  KC_PERC,  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_BSPC,  /****/  CTRLENT,  KC_PIPE,  KC_UNDS,  KC_LABK,  KC_RABK,  KC_BSLS,
  ___X___,  KC_LGUI,  KC_LCTL,  KC_LALT,  SPC_CTL,  KC_LGUI,  /****/  _______,  _______,  _______,  ___X___,  ___X___,  ___X___
),
[NUM] = LAYOUT_planck_grid(
  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_ESC,   /****/  KC_DELT,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_BSPC,  /****/  KC_ENT,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  KC_HASH,  KC_PERC,  KC_LBRC,  KC_RBRC, KC_MINUS,  KC_BSPC,  /****/  KC_ENT,   KC_PIPE,  KC_UNDS,  KC_COMM,  KC_DOT,   KC_SLSH,
  _______,  _______,  KC_LCTL,  KC_LALT,  SPC_CTL,  KC_LGUI,  /****/  _______,  _______,  _______,  ___X___,  ___X___,  ___X___
),
};


#define CTRLTAB RCTL(KC_TAB)
#define CTRLTABPrev RCTL(RSFT(KC_TAB))

bool cmd_engaged = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LGUI:
      if (record->event.pressed) {
        cmd_engaged = true;
        return true;
      } else {
        cmd_engaged = false;
        unregister_code(KC_LSFT);
        unregister_code(KC_LCTL);
        return true;
      }
    case KC_C:
      if (record->event.pressed) {
        if (cmd_engaged) {
          //unregister_code(KC_LGUI);
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(KC_TAB);
          unregister_code(KC_TAB);
          //register_code(KC_LGUI);
          return false;
        } else {
          return true;
        }
      }
    case KC_V:
      if (record->event.pressed) {
        if (cmd_engaged) {
          //unregister_code(KC_LGUI);
          register_code(KC_LCTL);
          register_code(KC_TAB);
          unregister_code(KC_TAB);
          //register_code(KC_LGUI);
          return false;
        } else {
          return true; // Let QMK send the enter press/release events
        }
      }
    default:
      return true;
  }
}
