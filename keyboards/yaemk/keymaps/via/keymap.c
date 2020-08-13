/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN 1
#define _RGB 2
#define _EMPTY 3

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
// .--------------------------------------------------------------.                 .--------------------------------------------------------------.
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,LCTL(KC_GRV),               KC_ESC , KC_6   , KC_7   , KC_8  , KC_9    , KC_0   , KC_MINS,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,_______ ,                  MO(_RGB), KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
     KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_1   ,                  TT(_FN) , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,\
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     KC_NUBS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_BSPC, KC_BSPC, KC_ENT , KC_ENT , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_NUBS,\
// '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
                                KC_1   , KC_LCTL, KC_LSFT, KC_BSPC, KC_LGUI, KC_CAPS, KC_ENT , KC_SPC , KC_LALT, KC_1   \
//                            '-----------------------------------------------------------------------------------------'
  ),
   [_FN] = LAYOUT( \
// .--------------------------------------------------------------.                 .--------------------------------------------------------------.
    _______ ,_______ ,KC_ACL0 ,KC_ACL1 ,KC_ACL2 , RESET  ,_______ ,                  _______ , RESET  , KC_F10 , KC_F11 , KC_F12 ,_______ ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,KC_BTN1 ,KC_MS_U ,KC_BTN2 , KC_PSCR,_______ ,                  _______ ,_______ , KC_F7  , KC_F8  , KC_F9  ,_______ ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,_______ ,                  _______ ,_______ , KC_F4  , KC_F5  , KC_F6  ,_______ ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ , KC_F1  , KC_F2  , KC_F3  ,_______ ,_______ ,\
// '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
                               _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ \
//                            '-----------------------------------------------------------------------------------------'
  ),
  [_RGB] = LAYOUT( \
// .--------------------------------------------------------------.                 .--------------------------------------------------------------.
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                  _______ , _______,RGB_TOG ,RGB_M_SW,_______ ,_______ ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                  _______ ,_______ ,RGB_HUI ,RGB_HUD ,RGB_SAI ,RGB_SAD ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                  _______ ,_______ ,RGB_MOD ,RGB_RMOD,RGB_SPI ,RGB_SPD ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,RGB_VAI ,RGB_VAD ,_______ ,_______ ,_______ ,\
// '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
                               _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ \
//                            '-----------------------------------------------------------------------------------------'
  ),
  [_EMPTY] = LAYOUT( \
// .--------------------------------------------------------------.                 .--------------------------------------------------------------.
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                  _______ , _______,RGB_TOG ,RGB_M_SW,_______ ,_______ ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                  _______ ,_______ ,RGB_HUI ,RGB_HUD ,RGB_SAI ,RGB_SAD ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                  _______ ,_______ ,RGB_MOD ,RGB_RMOD,RGB_SPI ,RGB_SPD ,_______ ,\
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,RGB_VAI ,RGB_VAD ,_______ ,_______ ,_______ ,\
// '--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
                               _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ \
//                            '-----------------------------------------------------------------------------------------'
  )
};

// clang-format on

#ifdef OLED_DRIVER_ENABLE
/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}
*/
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_kb(uint8_t index, bool clockwise) {
    uint16_t mapped_code = 0;
    if (index == 0) {
        if (clockwise) {
            switch (biton32(layer_state)) {
                case 0:
                default:
                    mapped_code = KC_WH_U;
                    break;
                case 1:
                    mapped_code = KC_AUDIO_VOL_UP;
                    break;
                case 2:
                    mapped_code = KC_PGUP;
                    break;
            }
        } else {
            switch (biton32(layer_state)) {
                case 0:
                default:
                    mapped_code = KC_WH_D;
                    break;
                case 1:
                    mapped_code = KC_AUDIO_VOL_DOWN;
                    break;
                case 2:
                    mapped_code = KC_PGDN;
                    break;
            }
        }

    } else if (index == 1) {
        if (clockwise) {
            switch (biton32(layer_state)) {
                case 0:
                default:
                    mapped_code = KC_WH_U;
                    break;
                case 1:
                    mapped_code = KC_MEDIA_NEXT_TRACK;
                    break;
                case 2:
                    mapped_code = KC_PGUP;
                    break;
            }
        } else {
            switch (biton32(layer_state)) {
                case 0:
                default:
                    mapped_code = KC_WH_D;
                    break;
                case 1:
                    mapped_code = KC_MEDIA_PREV_TRACK;
                    break;
                case 2:
                    mapped_code = KC_PGDN;
                    break;
            }
        }
    }
    tap_code(mapped_code);
}
#endif
