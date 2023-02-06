#include QMK_KEYBOARD_H

enum layers {
    _LETTERS,
    _SYMBOLS,
    _COMMS,
    _CONTROLS,
};

#define TG_MIC  MT(MOD_HYPR, KC_F13)
#define L_SYMS  MO(_SYMBOLS)

#define L_CTRL  MO(_CONTROLS)
#define CL_SPC  LT(_COMMS, KC_SPC)

#define RAT_DOT MT(MOD_RALT, KC_DOT)
#define LAT_COM MT(MOD_LALT, KC_COMM)

// overrides
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, RAT_DOT, KC_AT);
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, LAT_COM, KC_AMPR);
const key_override_t circ_override = ko_make_basic(MOD_MASK_ALT, KC_CIRC, RALT(KC_6));

const key_override_t **key_overrides = (const key_override_t *[]){
    &colon_override,
    &dot_override,
    &comma_override,
    &circ_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LETTERS] = LAYOUT_split_3x5_3(
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,               KC_J,    KC_L,    KC_U,    KC_Y,    KC_COLN,
      KC_A,    KC_R,    KC_S,    KC_T,    KC_D,               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,               KC_B,    KC_K,    KC_M,    LAT_COM, RAT_DOT,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        TG_MIC,  L_SYMS,  KC_LGUI,            L_CTRL,  CL_SPC,  KC_LSFT
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
    [_SYMBOLS] = LAYOUT_split_3x5_3(
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
      KC_TILD, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_DEL,
      KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT,              KC_GT,   KC_RPRN, KC_RBRC, KC_RCBR, KC_SLSH,
      KC_EXLM, KC_PIPE, KC_UNDS, KC_QUOT, KC_GRV,             XXXXXXX, KC_DQUO, KC_EQL,  KC_PLUS, KC_QUES,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        XXXXXXX, _______, _______,            _______, _______, _______
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
    [_COMMS] = LAYOUT_split_3x5_3(
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
      KC_TAB,  KC_7,    KC_8,    KC_9,    KC_MUTE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
      KC_ESC,  KC_4,    KC_5,    KC_6,    KC_VOLU,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
      KC_LCTL, KC_1,    KC_2,    KC_3,    KC_VOLD,            KC_MPRV, KC_MPLY, KC_MNXT, KC_PSCR, KC_LSFT,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        XXXXXXX, KC_0,    _______,            _______, _______, _______
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
    [_CONTROLS] = LAYOUT_split_3x5_3(
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,            XXXXXXX, KC_F13,  KC_F14,  KC_F15,  KC_F16,
      KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,            XXXXXXX, KC_F17,  KC_F18,  KC_F19,  KC_F20,
      KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,            XXXXXXX, KC_F21,  KC_F22,  KC_F23,  KC_F24,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        XXXXXXX, _______, QK_BOOT,            _______, _______, _______
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
};
