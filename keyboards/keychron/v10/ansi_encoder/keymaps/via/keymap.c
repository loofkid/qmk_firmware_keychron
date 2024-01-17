/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

enum td_keycodes {
    KC_FN,
    KC_TD_CAPS
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

td_state_t cur_dance(tap_dance_state_t *state);

void fn_finished(tap_dance_state_t *state, void *user_data);
void fn_reset(tap_dance_state_t *state, void *user_data);

// void tdcaps_finished(tap_dance_state_t *state, void *user_data);
// void tdcaps_reset(tap_dance_state_t *state, void *user_data);

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MACLOCK LCAG(KC_L)
#define KC_WINLOCK LGUI(KC_L)
#define KC_MACCALC HYPR(KC_C)
#define KC_MACNOT HYPR(KC_N)
#define KC_WINNOT LGUI(KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,    KC_LPAD,    RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,             KC_HOME,
        KC_MACLOCK,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_MACNOT,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_PSCR,    KC_TD_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        MC_4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_MACCALC,    KC_LCTL,  KC_LOPT,            KC_LCMD,  KC_SPC,  KC_FN,                     KC_SPC,             KC_RCMD,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,            _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  AS_TOGG,            _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_HOME,
        KC_WINLOCK,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_WINNOT,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_PSCR,    KC_TD_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        MC_4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        KC_CALC,    KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  KC_FN,                     KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_89(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  KC_INS,            _______,
        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,    KC_CAPS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),
};

static td_state_t fn_td_state;
static td_state_t caps_td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN;
}

void fn_finished(tap_dance_state_t *state, void *user_data) {
    fn_td_state = cur_dance(state);
    switch (fn_td_state) {
        case TD_SINGLE_TAP:
            if (layer_state_is(MAC_BASE)) {
                register_code16(C(G(KC_SPC)));
            }
            if (layer_state_is(WIN_BASE)) {
                register_code16(G(KC_DOT));
            }
            break;
        case TD_SINGLE_HOLD:
            if (layer_state_is(MAC_BASE)) {
                layer_move(MAC_FN);
            }
            if (layer_state_is(WIN_BASE)) {
                layer_move(WIN_FN);
            }
            break;
        default:
            break;
    }
}

void fn_reset(tap_dance_state_t *state, void *user_data) {
    if (fn_td_state == TD_SINGLE_HOLD) {
        if (layer_state_is(MAC_FN)) {
            layer_move(MAC_BASE);
        }
        if (layer_state_is(WIN_FN)) {
            layer_move(WIN_BASE);
        }
    }
    if (fn_td_state == TD_SINGLE_TAP) {
        if (layer_state_is(MAC_BASE)) {
            unregister_code16(C(G(KC_SPC)));
        }
        if (layer_state_is(WIN_BASE)) {
            unregister_code16(G(KC_DOT));
        }
    }
}

void tdcaps_finished(tap_dance_state_t *state, void *user_data) {
    caps_td_state = cur_dance(state);
    switch (caps_td_state) {
        case TD_SINGLE_TAP:
            if (is_caps_word_on()) {
                caps_word_off();
            }
            else {
                caps_word_on();
            }
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_CAPS);
            break;
        default:
            break;
    }
}

void tdcaps_reset(tap_dance_state_t *state, void *user_data) {
    switch (caps_td_state) {
        case TD_SINGLE_HOLD:
            unregister_code16(KC_CAPS);
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [KC_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [KC_TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tdcaps_finished, tdcaps_reset)
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE
