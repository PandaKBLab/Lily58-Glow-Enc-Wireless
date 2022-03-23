
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_DVORAK 0
#define L_QWERTY (1 << 1)
#define L_CODENAV (1 << 2)
#define L_NUMPAD (1 << 3)
#define L_ADJUST (1 << 4)

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_DVORAK:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: DVORAK");
            break;
        case L_QWERTY:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
            break;
        case L_CODENAV:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Code/Nav");
            break;
        case L_NUMPAD:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Numpad");
            break;
        case L_ADJUST:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
    }

    return layer_state_str;
}
