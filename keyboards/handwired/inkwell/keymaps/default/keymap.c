#include QMK_KEYBOARD_H

#include "debug.h"
#include "action_layer.h"


// Layers
#define BASE   0  // Base layer - QWERTY
#define SPEC   1  // Special keys favoring programming in c-like languages
#define NUM    2  // Numeric layer with number row functional keys

// Shortcuts
#define ___     KC_TRNS
#define BSLASH  LSFT(KC_SLSH)
#define CTRLENT LCTL(KC_ENT)
#define SPC_CTL MT(MOD_LCTL, KC_SPACE)


// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_inkwell(

        /*==========================================================================================*/
        /**/  KC_VOLD, /**/   KC_Q,   /**/    KC_W,  /**/   KC_E,   /**/   KC_R,   /**/   KC_T,   /**/
        /*==========================================================================================*/
        /**/  KC_MPLY, /**/   KC_A,   /**/   KC_S,   /**/   KC_D,   /**/   KC_F,   /**/   KC_G,   /**/
        /*==========================================================================================*/
        /**/  KC_MUTE, /**/   KC_Z,   /**/    KC_X,  /**/   KC_C,   /**/   KC_V,   /**/   KC_B,   /**/
        /*==========================================================================================*/
                                                    /**/ KC_LALT, SPC_CTL, XXXXXXX, KC_LGUI, /**/
                                                    /*==============================================*/

        /*==========================================================================================*/
        /**/  	KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,       RESET ,/**/
        /*==========================================================================================*/
        /**/  KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN,   /**/   KC_ENT, /**/
        /*==========================================================================================*/
        /**/  KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,    KC_QUOT,   /**/
        /*==========================================================================================*/
        /**/ KC_LSFT, MO(SPEC), MO(NUM) /**/
        /*==============================================*/
    ),
    [SPEC] = LAYOUT_inkwell(

        /*==========================================================================================*/
        /**/  KC_TILD, KC_GRV,  KC_QUOT, KC_LCBR, KC_RCBR, KC_PLUS,   /**/
        /*==========================================================================================*/
        /**/  KC_BSPC, KC_TAB,  KC_ASTR, KC_LPRN, KC_RPRN, KC_EQUAL,   /**/
        /*==========================================================================================*/
        /**/  KC_ESC,  KC_HASH, KC_PERC, KC_LBRC, KC_RBRC, KC_MINUS,   /**/
        /*==========================================================================================*/
                                                    /**/ KC_LALT, SPC_CTL, KC_LGUI, /**/
                                                    /*==============================================*/

        /*==========================================================================================*/
        /**/  	KC_AMPR, KC_HOME,   KC_UP,      KC_END,   KC_RCBR,  XXXXXXX, /**/
        /*==========================================================================================*/
        /**/  KC_EXLM, KC_LEFT,   KC_DOWN,    KC_RIGHT, KC_COLN,  CTRLENT, /**/
        /*==========================================================================================*/
        /**/  KC_PIPE, KC_UNDS,   KC_LT,      KC_GT,    KC_BSLS,  XXXXXXX,   /**/
        /*==========================================================================================*/
        /**/ KC_LSFT, XXXXXXX, XXXXXXX /**/
        /*==============================================*/
    ),
    [NUM] = LAYOUT_inkwell(

        /*==========================================================================================*/
        /**/  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   /**/
        /*==========================================================================================*/
        /**/  KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   /**/
        /*==========================================================================================*/
        /**/  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   /**/
        /*==========================================================================================*/
                                                    /**/ KC_LALT, SPC_CTL, KC_LGUI, /**/
                                                    /*==============================================*/

        /*==========================================================================================*/
        /**/  	KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL, /**/
        /*==========================================================================================*/
        /**/  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSLS, /**/
        /*==========================================================================================*/
        /**/  KC_NUHS, KC_NUBS, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,   /**/
        /*==========================================================================================*/
        /**/ KC_RSFT, XXXXXXX, XXXXXXX /**/
        /*==============================================*/
    )
};



#define CTRLTAB RCTL(KC_TAB)

#define CTRLTABPrev RCTL(RSFT(KC_TAB))


// Whether or not the command button is engaged.
bool cmd_engaged = false;


// The state tracking is needed

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /// When the
    case KC_LGUI:
      if (record->event.pressed) {
        cmd_engaged = true;
        return true;
      } else {
        // If the command key is raised, unregister meta modifiers
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
