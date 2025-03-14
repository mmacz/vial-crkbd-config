#include QMK_KEYBOARD_H
#include <stdint.h>
#include <stdio.h>
#include "animations/liquid/liquid.h"

enum {
    QWERTY = 0,
    COLEMAK,
    NUMS,
    SYMS,
    ADJU,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(NUMS),  KC_SPC,     KC_ENT,MO(SYMS), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(NUMS),  KC_SPC,     KC_ENT,MO(SYMS), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,MO(ADJU), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [SYMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, KC_TILD, KC_PIPE, KC_PLUS, KC_UNDS,                      KC_MINS,  KC_EQL, KC_BSLS, KC_GRV , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN,                      KC_RPRN, KC_RBRC, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,MO(ADJU),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [ADJU] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                  TG(COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

};

uint8_t current_base = QWERTY;
uint8_t current_highest = QWERTY;
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
        case QWERTY:
            current_base = QWERTY;
            rgb_matrix_sethsv(HSV_CYAN);
            break;
        case COLEMAK:
            current_base = COLEMAK;
            rgb_matrix_sethsv(HSV_RED);
            break;
        default:
            break;
    }
    current_highest = get_highest_layer(state);
    return state;
}

void keyboard_post_init_user(void) {
    rgb_matrix_sethsv(HSV_CYAN);
    rgb_matrix_mode(RGB_MATRIX_BREATHING);
}

static const char CRKBD_LOGO[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};

void oled_render_logo(void) {
    oled_write(CRKBD_LOGO, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_update_animation();
    }
    else {
        oled_render_logo();
        oled_scroll_left();
    }
    return false;
}

oled_rotation_t rot = OLED_ROTATION_0;
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        rot = OLED_ROTATION_180;
        oled_init_animation();
    }
    return rot;
}

