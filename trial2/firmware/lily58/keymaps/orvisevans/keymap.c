#include QMK_KEYBOARD_H

typedef union {
  uint32_t raw;
  struct {
    bool     os_is_windows :1;
  };
} user_config_t;

user_config_t user_config;

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum my_keycodes {
  CYC_LAYR = SAFE_RANGE,
  OS_TOGL,
  COPY,
  CUT,
  PSTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------| TG(1) |    |KC_MPLY|------+------+------+------+------+------|
 * |LCtrl |   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |  /   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |MO[2] | / Space /       \Enter \  | MO[3]|BackSP|Delete|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [0] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_QUOT, KC_COMM, KC_DOT, KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_EQL, \
  KC_LSFT,  KC_A,   KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
  KC_LCTRL, KC_SCLN, KC_Q,   KC_J,    KC_K,    KC_X, TG(1),    KC_MPLY,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
                             KC_LGUI, KC_LALT,MO(2), KC_SPC,   KC_ENT,   MO(3),   KC_BSPC, KC_DELETE \
),
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  +   |
 * |------+------+------+------+------+------|   `   |    |    `  |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |MO[2] | / Space /       \Enter \  | MO[3]|BackSP|Delete|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [1] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_PLUS, \
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS, \
                             KC_LGUI, KC_LALT,MO(2), KC_SPC,  KC_ENT,  MO(3),   KC_BSPC, KC_DELETE \
),
/* CODENAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | PgUp | PgDwn|PrtScr|  Cut |                    |      |      | PgUp | PgDwn|      |  F12 |
 * |------+------+------+------+------+------+                    |------+------+------+------+------+------|
 * |      |      |   |  |   [  |   ]  | Copy |-------.    ,-------| Home | Left |  Up  | Down | Right|  End |
 * |------+------+------+------+------+------+OS_TOGL|    |       |------+------+------+------+------+------|
 * |      | Left |  Up  | Down | Right| Paste|-------|    |-------|      | Left |  Up  | Down | Right|   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  | MO[4]|      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[2] = LAYOUT( \
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, _______, KC_PGUP, KC_PGDN, KC_PSCR, CUT    ,                   _______, _______, KC_PGUP, KC_PGDN, _______, KC_F12, \
  _______, _______, KC_PIPE, KC_LBRC, KC_RBRC, COPY   ,                   KC_HOME, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_END, \
  _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, PSTE   , OS_TOGL, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_BSLS, \
                             _______, _______, _______, _______, _______, MO(4),   _______, _______\
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |NumLok|      |      |      |      | sleep|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |PrtScr|   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  Del |   4  |   5  |   6  |   ,  | calc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| BkSpc|   1  |   2  |   3  |   =  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | Adjust| /       /       \      \  |      |  0   |  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[3] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, KC_SLEP, \
  _______, _______, _______, _______, _______, _______,                     KC_PSCR, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, XXXXXXX, \
  _______, _______, _______, _______, _______, _______,                     KC_DEL,  KC_P4,   KC_P5,   KC_P6,   KC_PCMM, KC_CALC, \
  _______, _______, _______, _______, _______, _______,  _______, _______,  KC_BSPC, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, XXXXXXX, \
                             _______, _______, MO(4),    _______, _______,  _______, KC_P0,   KC_PDOT \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Power |      |      | Debug| Reset|EEPRst|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DF[0]| DF[1]|      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Brt+ | Vol+ |      |      |      |      |-------.    ,-------|RGBTog| Mode+| FX+  | HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Brt- | Vol- |      |      |      |      |-------|    |-------|      | Mode-| FX-  | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |       | /      /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [4] = LAYOUT( \
  KC_PWR,  XXXXXXX, XXXXXXX, DEBUG,   RESET,   EEP_RST,                   RGB_MODE_PLAIN, RGB_MODE_BREATHE,  RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_MODE_KNIGHT, RGB_MODE_XMAS,  RGB_MODE_GRADIENT, RGB_MODE_RGBTEST, XXXXXXX, XXXXXXX, \
  KC_BRIU, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_TOG, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, \
  KC_BRID, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______, _______, _______,  _______ \
  )
};


// Last initialization step
void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

// eeprom reset step
void eeconfig_init_user(void) { // EEPROM is getting reset!
  user_config.raw=0;
  user_config.os_is_windows = true;
  eeconfig_update_user(user_config.raw);
}


// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if the key is pressed down
  if (record->event.pressed) { 
    switch (keycode) {
      case OS_TOGL:
        user_config.os_is_windows ^= 1;
        eeconfig_update_user(user_config.raw);
        break;
      case COPY:
        if (user_config.os_is_windows) {
          SEND_STRING(SS_LCTL("c"));
        } else {
          SEND_STRING(SS_LGUI("c"));
        }
        break;
      case CUT:
        if (user_config.os_is_windows) {
          SEND_STRING(SS_LCTL("x"));
        } else {
          SEND_STRING(SS_LGUI("x"));
        }
        break;
      case PSTE:
        if (user_config.os_is_windows) {
          SEND_STRING(SS_LCTL("v"));
        } else {
          SEND_STRING(SS_LGUI("v"));
        }
        break;
    }
  }
  return true;
}


// Encoders
// https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      if (user_config.os_is_windows) {
        SEND_STRING(SS_LCTL("z"));
      } else {
        SEND_STRING(SS_LGUI("z"));
      }
    } else {
      if (user_config.os_is_windows) {
        SEND_STRING(SS_LCTL("y"));
      } else {
        SEND_STRING(SS_LGUI(SS_LSFT("z")));
      }
    }
  } else if (index == 1) { /* Second encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
  return false;
}

// Lighting Layers
/* https://docs.qmk.fm/#/feature_rgblight?id=lighting-layers */
int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}
