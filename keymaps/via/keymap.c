#include QMK_KEYBOARD_H
#include "config.h"
#include "quantum.h"
#include "keymap_brazilian_abnt2.h"
#include "sendstring_brazilian_abnt2.h"

enum layer_names {
    _DEFAULT,
    _TECNICON,
    _TEST,
    _DEBUGGING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_delphos(
        KC_F13,          KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_MUTE,
        KC_F14,          KC_F15,              KC_F16,              KC_F17,
        KC_PRINT_SCREEN, KC_F18,              KC_F19,              TO(_TECNICON)
    ),
    [_TECNICON] = LAYOUT_delphos(
        _______, _______, _______, _______, KC_MUTE,
        _______, _______, _______, _______,
        _______, _______, TO(_DEFAULT), TO(_TEST)
    ),
    [_TEST] = LAYOUT_delphos(
        _______, _______, _______, _______, KC_MUTE,
        _______, _______, _______, _______,
        _______, _______, TO(_TECNICON), MO(_DEBUGGING)
    ),
    [_DEBUGGING] = LAYOUT_delphos(
        
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, MO(_DEBUGGING)
    ),
};

// Encoder básico
#ifdef ENCODER_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [_DEFAULT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_TECNICON] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_TEST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_DEBUGGING] = { ENCODER_CCW_CW(KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP) },
    };
#endif

#ifdef OLED_ENABLE
    static void render_logo(void) {
        static const char PROGMEM qmk_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
            0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
        };

        oled_write_P(qmk_logo, false);
    }

    bool oled_task_user(void) {
        render_logo();
        return false;
    }

#endif