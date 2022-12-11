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
#define OS_RALT OSM(MOD_RALT)

// overrides
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_AT);
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_AMPR);
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
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,               KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        TG_MIC,  L_SYMS,  KC_LGUI,            L_CTRL,  CL_SPC,  KC_LSFT
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
    [_SYMBOLS] = LAYOUT_split_3x5_3(
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
      KC_TILD, KC_PERC, KC_HASH, KC_DLR,  XXXXXXX,            XXXXXXX, KC_CIRC, KC_ASTR, KC_MINS, KC_DEL,
      KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT,              KC_GT,   KC_RPRN, KC_RBRC, KC_RCBR, KC_SLSH,
      KC_EXLM, KC_PIPE, KC_UNDS, KC_QUOT, KC_GRV,             XXXXXXX, KC_DQUO, KC_EQL,  KC_PLUS, KC_QUES,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        XXXXXXX, _______, _______,            _______, _______, OS_RALT
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
    [_COMMS] = LAYOUT_split_3x5_3(
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
      KC_TAB,  KC_7,    KC_8,    KC_9,    XXXXXXX,            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
      KC_ESC,  KC_4,    KC_5,    KC_6,    XXXXXXX,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
      KC_LCTL, KC_1,    KC_2,    KC_3,    XXXXXXX,            XXXXXXX, KC_LALT, XXXXXXX, KC_PSCR, KC_LSFT,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        XXXXXXX, KC_0,    _______,            _______, _______, _______
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
    [_CONTROLS] = LAYOUT_split_3x5_3(
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,            XXXXXXX, KC_MNXT, XXXXXXX,   XXXXXXX,   XXXXXXX,
      KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,            XXXXXXX, KC_MPLY, XXXXXXX,   XXXXXXX,   XXXXXXX,
      KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,            XXXXXXX, KC_MPRV, XXXXXXX,   XXXXXXX,   XXXXXXX,
   //|--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------|
                        QK_BOOT, _______, _______,            _______, _______, _______
   //                  |--------+--------+--------|          |--------+--------+--------|
    ),
};
