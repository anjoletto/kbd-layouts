#include QMK_KEYBOARD_H

enum layers {
    _LETTERS,
    _SYMBOLS,
    _COMMS,
    _CONTROLS,
};

#define TG_MIC MT(MOD_HYPR, KC_F13)
#define L_SYMS LT(_SYMBOLS, KC_0)

#define L_CTRL MO(_CONTROLS)
#define CL_SPC LT(_COMMS, KC_SPC)
#define ALT_SPC MT(MOD_RALT, KC_SPC)

// overrides
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM);

const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t backspace_override = ko_make_basic(MOD_MASK_GUI, KC_BSPACE, KC_DELETE);
const key_override_t circ_override = ko_make_basic(MOD_MASK_ALT, KC_CIRC, RALT(KC_6));

const key_override_t **key_overrides = (const key_override_t *[]){
    &backspace_override,
    &colon_override,
    &dot_override,
    &comma_override,
    &circ_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LETTERS] = LAYOUT_planck_mit(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXXXX, XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_COLN,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXXXX, XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,
        XXXXXXX, XXXXXXX, XXXXXXX, L_SYMS,  KC_LSFT,      TG_MIC,      CL_SPC,  L_CTRL,  XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SYMBOLS] = LAYOUT_planck_mit(
        KC_TILD, KC_PERC, KC_HASH, KC_DLR,  KC_AT,   XXXXXXX, XXXXXXX, KC_AMPR, KC_CIRC, KC_ASTR, KC_MINS, KC_BSPC,
        KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LT,   XXXXXXX, XXXXXXX, KC_GT,   KC_RPRN, KC_RBRC, KC_RCBR, KC_SLSH,
        KC_EXLM, KC_PIPE, KC_UNDS, KC_QUOT, KC_GRV,  XXXXXXX, XXXXXXX, KC_NO,   KC_DQUO, KC_EQL,  KC_PLUS, KC_QUES,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     XXXXXXX,      ALT_SPC, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_COMMS] = LAYOUT_planck_mit(
        KC_TAB,  KC_7,    KC_8,    KC_9,    KC_NO,   XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_BSPC,
        KC_ESC,  KC_4,    KC_5,    KC_6,    KC_NO,   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_LCTL, KC_1,    KC_2,    KC_3,    KC_NO,   XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   KC_NO,   KC_PSCR, KC_LSFT,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    KC_LGUI,     XXXXXXX,      CL_SPC,  _______,  XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_CONTROLS] = LAYOUT_planck_mit(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   XXXXXXX, XXXXXXX, KC_VOLU, KC_MPRV, KC_NO,   KC_NO,   KC_NO,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, KC_BRIU, KC_NO,   KC_NO,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   XXXXXXX, XXXXXXX, KC_VOLD, KC_MNXT, KC_BRID, KC_NO,   KC_NO,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     XXXXXXX,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
