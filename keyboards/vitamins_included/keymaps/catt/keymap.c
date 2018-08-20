#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define WIND 1
#define SYMB 2
#define NUMP 3
#define NAVI 4
#define GAME 5
#define BLAN 6


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  CK_RARW,
  CK_RFRW,
};

#define _______ KC_TRNS 
#define SS_ALFR LALT(KC_SPC)
#define SS_SPOT LGUI(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | RESET|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |Adjust|Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT_ortho_4x12( \
  MO(NUMP),KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, RESET, \
  MO(SYMB),KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    MO(SYMB), \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, KC_ENT , \
  KC_LCTRL,KC_LGUI, KC_LALT, KC_SPC,  KC_ESC,  KC_SPC,  KC_BSPC, KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case CK_RARW:
        SEND_STRING("->");
        return false;
      case CK_RFRW:
        SEND_STRING("=>");
        return false;
    }
  }
  return true;
};
