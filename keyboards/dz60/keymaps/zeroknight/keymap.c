#include QMK_KEYBOARD_H

/*
 * ZeroKnight's personal DZ60 keymap
 * Used with my QXP.
 */

/* Blank layer template

    [...] = LAYOUT_60_tsangan(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______,          _______,                   _______,                                     _______,          _______, _______
    )
*/

#define LED_ROWS 2
#define LED_COLS 8
#define LED_AT(r, c) (r * LED_COLS + c)
#define LED_SPC LED_AT(1, 2), 4

enum KeyboardLayers {
    _BL = 0,  // Base Layer
    _EL,      // Extension Layer
    _ML,      // Media/Misc Layer
    _CL,      // Control Layer
    _NL,      // Numpad Layer
};

#define FN_1 LT(_EL, KC_GRV)
#define FN_2 LT(_ML, KC_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_60_tsangan(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        SC_LSPO,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          SC_RSPC, FN_1,
        KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                                      KC_RALT,          FN_2,    KC_RCTL
    ),
    [_EL] = LAYOUT_60_tsangan(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
        _______,          KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, KC_INS,  _______, KC_PSCR, KC_SCRL, KC_PAUS, _______,
        _______,          KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______,          _______,                   _______,                                     KC_HYPR,          MO(_CL), _______
    ),
    [_ML] = LAYOUT_60_tsangan(
        KC_MSTP, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,           KC_EJCT,
        _______,          _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______,
        KC_CAPS,          _______, KC_VOLD, _______, KC_FIND, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, KC_CALC, _______, _______, TG(_NL), KC_MUTE, KC_MPRV, KC_MNXT, _______,          _______, MO(_CL),
        _______, _______,          _______,                   KC_MPLY,                                     _______,          _______, _______
    ),
    [_CL] = LAYOUT_60_tsangan(
        KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EE_CLR,           QK_RBT,
        _______,          RGB_TOG, RGB_MOD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______,          RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, GUI_TOG,          _______,                   _______,                                     _______,          _______, _______
    ),
    [_NL] = LAYOUT_60_tsangan(
        _______, _______, _______, _______, _______, _______, _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PENT,
        _______,          _______, _______, _______, _______, _______, TG(_NL), _______, KC_P1,   KC_P2,   KC_P3,            _______, _______,
        _______, _______,          _______,                   KC_P0,                                       KC_PDOT,          XXXXXXX, _______
    )
};

// Shift+Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL
};

// Lighting Layers

const rgblight_segment_t PROGMEM ll_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    // Illuminate bottom left area when Caps Lock is on
    {LED_AT(1, 0), 2, 180, 128, 255}
);

const rgblight_segment_t PROGMEM ll_capsword[] = RGBLIGHT_LAYER_SEGMENTS(
    // Illuminate spacebar when Caps Word is active
    {LED_SPC, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM ll_layer_EL[] = RGBLIGHT_LAYER_SEGMENTS(
    // Illuminate spacebar when Extended Layer is on
    {LED_SPC, HSV_AZURE}
);

const rgblight_segment_t PROGMEM ll_layer_ML[] = RGBLIGHT_LAYER_SEGMENTS(
    // Illuminate spacebar when Media Layer is on
    {LED_SPC, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM ll_layer_CL[] = RGBLIGHT_LAYER_SEGMENTS(
    // Illuminate bottom right area red when Control Layer is active
    {LED_AT(1, LED_COLS - 2), 2, HSV_RED}
);

const rgblight_segment_t PROGMEM ll_layer_NL[] = RGBLIGHT_LAYER_SEGMENTS(
    // Illuminate area around "numpad" when Numpad Layer is on
    {LED_AT(0, LED_COLS - 4), 3, HSV_CYAN},
    {LED_AT(1, LED_COLS - 4), 3, HSV_CYAN}
);

const rgblight_segment_t* const PROGMEM light_layers[] = RGBLIGHT_LAYERS_LIST(
    ll_capslock, ll_capsword, ll_layer_EL, ll_layer_ML, ll_layer_NL, ll_layer_CL
);

void keyboard_post_init_user(void) {
    rgblight_layers = light_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

void caps_word_set_user(bool active) {
    rgblight_set_layer_state(1, active);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _EL) && !layer_state_cmp(state, _CL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ML) && !layer_state_cmp(state, _CL));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NL));
    rgblight_set_layer_state(5, layer_state_cmp(state, _CL));
    return state;
}
