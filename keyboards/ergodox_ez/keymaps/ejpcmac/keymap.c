// BÉPO layout for Ergodox keyboards.
//
// AUTHOR: Jean-Philippe Cugnet

#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

// Keycodes
#define XXX KC_NO
#define ___ KC_TRANSPARENT

// Layers
#define BEPO 0  // Default layer, for typing in BÉPO.
#define FNAV 1  // Function / navigation / mouse layer.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Default layer
//
// ,-------------------------------------------.                              ,-------------------------------------------.
// |   $   | " 1 | < 2 | > 3 | ( 4 | ) 5 | DEL |                              |  %  | @ 6 | + 7 | - 8 | / 9 | * 0 |   =   |
// |-------+-----+-----+-----+-----+-----------|                              |-----+-----+-----+-----+-----+-----+-------|
// |  TAB  |  B  |  É  |  P  |  O  |  È  | Back|                              | Back|  ^  |  V  |  D  |  L  |  J  |   Z   |
// |-------+-----+-----+-----+-----+-----|space|                              |space|-----+-----+-----+-----+-----+-------|
// |  ESC  |  A  |  U  |  I  |  E  |  ,  |-----|                              |-----|  C  |  T  |  S  |  R  |  N  |   M   |
// |-------+-----+-----+-----+-----+-----|Enter|                              |Enter|-----+-----+-----+-----+-----+-------|
// | Shift |  À  |  Y  |  X  |  .  |  K  |     |                              |     |  '  |  Q  |  G  |  H  |  F  |   W   |
// `-------+-----+-----+-----+-----+-----------,-----------.      ,-----------,-----+-----+-----+-----+-----+-----+-------'
//   |LCtrl| F/N | LAlt|AltGr|Super|           |PgUp |PgDwn|      |BÉPO | DEL |           |LCtrl|AltGr|Super|  Ç  |RCtrl|
//   `-----------------------------'     ,-----|-----|-----|      |-----+------+----.     `-----------------------------'
//                                       |     |Shift|Inser|      | LFn |AltGr|Shift|
//                                       |Space|Enter|-----|      |-----|Enter|Space|
//                                       |     |     | ESC |      | F/N |     |     |
//                                       `-----------------'      `-----------------'
[BEPO] = LAYOUT_ergodox_pretty(
BP_DLR,     BP_DQUO,   BP_LDAQ,  BP_RDAQ,  BP_LPRN,  BP_RPRN,  KC_DEL,                           BP_PERC,   BP_AT,    BP_PLUS,  BP_MINS,  BP_SLSH,  BP_ASTR,  BP_EQL,
KC_TAB,     BP_B,      BP_EACU,  BP_P,     BP_O,     BP_EGRV,  KC_BSPC,                          KC_BSPC,   BP_DCIR,  BP_V,     BP_D,     BP_L,     BP_J,     BP_Z,
KC_ESC,     BP_A,      BP_U,     BP_I,     BP_E,     BP_COMM,                                               BP_C,     BP_T,     BP_S,     BP_R,     BP_N,     BP_M,
KC_LSHIFT,  BP_AGRV,   BP_Y,     BP_X,     BP_DOT,   BP_K,     KC_ENTER,                         KC_ENTER,  BP_QUOT,  BP_Q,     BP_G,     BP_H,     BP_F,     BP_W,
KC_LCTL,    MO(FNAV),  KC_LALT,  KC_ALGR,  KC_LGUI,                                                                   KC_LCTL,  KC_ALGR,  KC_RGUI,  BP_CCED,  KC_RCTL,
                                                               KC_PGUP, KC_PGDOWN,    DF(BEPO),  KC_DEL,
                                                                        KC_INS,       DF(FNAV),
                                              KC_SPC, SFT_T(KC_ENTER),  KC_ESC,       MO(FNAV),  ALGR_T(KC_ENTER), SFT_T(KC_SPC)),

// TODO: Add print.

// Function / navigation / mouse layer.
//
// ,-------------------------------------------.                              ,-------------------------------------------.
// |       | F1  | F2  | F3  | F4  | F5  | F6  |                              | F12 | F6  | F7  | F8  | F9  | F10 |  F11  |
// |-------+-----+-----+-----+-----+-----+-----|                              |-----+-----+-----+-----+-----+-----+-------|
// |       |Next |LClic| Up  |RClic|WhUp | Vol |                              |     |PgUp |Home | Up  | End |     |       |
// |-------+-----+-----+-----+-----+-----| Up  |                              |     |-----+-----+-----+-----+-----+-------|
// |       |Prev |Left |Down |Right|WhDn |-----|                              |-----|Left |Down | Up  |Right|     |       |
// |-------+-----+-----+-----+-----+-----| Vol |                              |     |-----+-----+-----+-----+-----+-------|
// | ----- |Undo | Cut |Copy |Paste|     |Down |                              |     |     |     |     |     |     |       |
// `-------+-----+-----+-----+-----+-----------,-----------.      ,-----------`-----------+-----+-----+-----+-----+-------'
//   | --- | --- | --- | --- | --- |           |Home | End |      | --- | --- |           | --- | --- | --- |     |BOOT |
//   `-----------------------------'     ,-----|-----|-----|      |-----+-----+-----.     `----------------------------'
//                                       |     |     | --- |      | --- |     |     |
//                                       |     | --- |-----|      |-----| --- |     |
//                                       |     |     | --- |      | --- |     |     |
//                                       `-----------------'      `-----------------'
//
[FNAV] = LAYOUT_ergodox_pretty(
XXX,  KC_F1,       KC_F2,       KC_F3,       KC_F4,        KC_F5,          KC_F6,                       KC_F12,  KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,  KC_F11,
XXX,  KC_MS_BTN5,  KC_MS_BTN1,  KC_MS_UP,    KC_MS_BTN2,   KC_MS_WH_UP,    KC_VOLU,                     XXX,     KC_PGUP,  KC_HOME,  KC_UP,    KC_END,    XXX,     XXX,
XXX,  KC_MS_BTN4,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  KC_MS_WH_DOWN,                                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  XXX,     XXX,
___,  KC_UNDO,     S(KC_DEL),   C(KC_INS),   S(KC_INS),    XXX,            KC_VOLD,                     XXX,     XXX,      XXX,      XXX,      XXX,       XXX,     XXX,
___,  ___,         ___,         ___,         ___,                                                                          ___,      ___,      ___,       XXX,     QK_BOOT,
                                                                           KC_HOME,  KC_END,      ___,  ___,
                                                                                        ___,      ___,
                                                                            XXX,  ___,  ___,      ___,  ___,  XXX),
};

/* helper function to switch on of the right LED ON/OFF */
static void indicate_using_led(const uint8_t led, const bool enabled) {
  if (enabled) {
    ergodox_right_led_on(led);
  } else {
    ergodox_right_led_off(led);
  }
}

/* Runs constantly in the background, in a loop */
void matrix_scan_user(void) {

  /* red led for shift */
  if (keyboard_report->mods & MOD_BIT(KC_LSFT) ||
    ((get_oneshot_mods() & MOD_BIT(KC_LSFT)) && !has_oneshot_mods_timed_out())) {
    indicate_using_led(1, true);
  } else {
    indicate_using_led(1, false);
  }

  /* green led for alt */
  if (keyboard_report->mods & MOD_BIT(KC_LALT) ||
    ((get_oneshot_mods() & MOD_BIT(KC_LALT)) && !has_oneshot_mods_timed_out())) {
    indicate_using_led(2, true);
  } else {
    indicate_using_led(2, false);
  }

  /* blue led for function mode */
  if (IS_LAYER_ON(FNAV)) {
    indicate_using_led(3, true);
  } else {
    indicate_using_led(3, false);
  }
};
