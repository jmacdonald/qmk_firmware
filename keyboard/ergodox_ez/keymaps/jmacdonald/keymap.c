#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define CTRL 1 // function keys
#define SYM  2 // symbol keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   =  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   {  |           |   }  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Retn  |
 * |--------+------+------+------+------+------|   (  |           |   )  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LAlt |      | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F1  |Ply/Ps|       | Del  |  F4  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Vol- |       | Vol+ |        |      |
 *                                 | '/L1 |  "   |------|       |------|    _   |Spc/L2|
 *                                 |      |      |  =   |       |  =   |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_LCBR,
        KC_ESC,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LPRN,
        KC_LCTL,        KC_LALT,      KC_NO,  KC_LEFT,KC_RGHT,
                                                      KC_F1,  KC_MPLY,
                                                              KC_VOLD,
                             LT(CTRL, KC_QUOT), LSFT(KC_QUOT),KC_EQL,
        // right hand
        KC_7,        KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,  KC_BSPC,
        KC_RCBR,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENTER,
        KC_RPRN,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,
                             KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC, KC_NO,
        KC_DEL,      KC_F4,
        KC_VOLU,
        KC_EQL,      KC_UNDS,LT(SYM, KC_SPC)
    ),

/* Keymap 1: Ctrl Layer (non-special keys are Ctrl-qualified).
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |  10  |   -  |   =  |  Bkspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   {  |           |   }  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------| Left | Down |  Up  | Right|   ;  |  Retn  |
 * |--------+------+------+------+------+------|   (  |           |   )  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | LAlt |      | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |Space |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[CTRL] = KEYMAP(
       // left hand
        LCTL(KC_GRV),   LCTL(KC_1),   LCTL(KC_2),   LCTL(KC_3),   LCTL(KC_4),   LCTL(KC_5),   LCTL(KC_6),
        LCTL(KC_TAB),   LCTL(KC_Q),   LCTL(KC_W),   LCTL(KC_E),   LCTL(KC_R),   LCTL(KC_T),   KC_LCBR,
        KC_ESC,         LCTL(KC_A),   LCTL(KC_S),   LCTL(KC_D),   LCTL(KC_F),   LCTL(KC_G),
        KC_LSFT,        LCTL(KC_Z),   LCTL(KC_X),   LCTL(KC_C),   LCTL(KC_V),   LCTL(KC_B),   KC_LPRN,
        KC_LCTL,        KC_LALT,      KC_NO,  KC_LEFT,KC_RGHT,
                                                       KC_NO, KC_NO,
                                                              KC_NO,
                                              KC_TRNS, KC_NO, KC_NO,
       // right hand
       LCTL(KC_7),  LCTL(KC_8),   LCTL(KC_9),   LCTL(KC_0),   KC_MINS,       KC_EQL,        KC_BSPC,
       KC_RCBR,     LCTL(KC_Y),   LCTL(KC_U),   LCTL(KC_I),   LCTL(KC_O),    LCTL(KC_P),    KC_BSLS,
                    KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,      LCTL(KC_SCLN), LCTL(KC_ENTER),
       KC_RPRN,     LCTL(KC_N),   LCTL(KC_M),   LCTL(KC_COMM),LCTL(KC_DOT),  LCTL(KC_SLSH), KC_RSFT,
                                  KC_UP,        KC_DOWN,      LCTL(KC_LBRC), LCTL(KC_RBRC), KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_NO, LCTL(KC_SPC)
),

/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |   {  |           |   }  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |------|           |------|   &  |   [  |   ]  |   *  |  |   |        |
 * |--------+------+------+------+------+------|   (  |           |   )  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgDn | PgUp |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYM] = KEYMAP(
       // left hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LCBR,
       KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LPRN,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO, KC_NO,
                                                  KC_NO,
                                    KC_NO, KC_NO, KC_NO,
       // right hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
       KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
                KC_AMPR, KC_LBRC, KC_RBRC, KC_ASTR,  KC_PIPE, KC_NO,
       KC_RPRN, KC_NO,   KC_PGDN, KC_PGUP, KC_NO,    KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_NO, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
