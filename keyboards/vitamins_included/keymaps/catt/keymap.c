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

[BASE] = LAYOUT_ortho_4x12( \
  MO(NUMP),        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, MO(NUMP), \
  MO(SYMB),        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    MO(SYMB), \
  KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN, KC_RSFT , \
  KC_MEH,          KC_LGUI, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC,  KC_BSPC, KC_RCTL, KC_RALT, KC_RGUI, KC_RGUI, KC_MEH    \
),

[WIND] = LAYOUT_ortho_4x12( \
  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,         KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, KC_RCTL, _______ \
),

[SYMB] = LAYOUT_ortho_4x12( \
  _______,         KC_DLR,  KC_HASH, KC_AT,   KC_GRAVE,KC_TILD, SS_SPOT, KC_PIPE, KC_PERC, KC_CIRC, KC_DQUO, _______, \
  _______,         KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_QUES, KC_EXLM, KC_PLUS, KC_ASTR, KC_EQL,  KC_UNDS, _______, \
  _______,         KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN, KC_TAB,  KC_AMPR, KC_MINS, KC_SLSH, KC_BSLS, KC_COLN, _______, \
  _______,         _______, _______, KC_LEFT, KC_UP,   KC_ESC,  KC_ENT,  KC_DOWN, KC_RIGHT,_______, _______, _______ \
),

[NUMP] = LAYOUT_ortho_4x12( \
  _______,         TG(WIND),KC_F1,   KC_F2,   KC_F3,   _______, _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______,         _______, KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_UP,   KC_4,    KC_5,    KC_6,    KC_0,    _______, \
  _______,         _______, KC_F7,   KC_F8,   KC_F9,   KC_RIGHT,KC_DOWN, KC_7,    KC_8,    KC_9,    KC_DOT,  _______, \
  RESET,           _______, KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,  _______, _______, _______, _______, RESET \
),

[BLAN] = LAYOUT_ortho_4x12( \
  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
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
