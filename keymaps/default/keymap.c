#include QMK_KEYBOARD_H
#include "config.h"
#include "quantum.h"
#include "keymap_brazilian_abnt2.h"
#include "sendstring_brazilian_abnt2.h"

// Camadas do teclado
enum layer_names {
    _DEFAULT,
    _TECNICON,
    _DEBUGGING
};

// Custom keycodes
enum custom_keycodes {
    ARDUINO_IDE = SAFE_RANGE,
    BAMBU_LAB,
    FUSION,       
    OBSIDIAN,
    SPOTIFY,
    VS_CODE,
    COLAR_AVANCADO,  // Sem cedilha para evitar problemas de compilação
    REGUA_VIRTUAL,
    COLOR_PICKER,
    PRINT,
    SOUND_MIXER,
};

// Display OLED
#ifdef OLED_ENABLE
    // bool oled_task_user() {
    //     oled_set_cursor(0, 1);
    //     oled_write("Olá Mundo", false);
    //     return false;
    // }
#endif

// Rotary Encoder
#ifdef ENCODER_ENABLE
    #if defined(ENCODER_MAP_ENABLE)
        const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
            [_DEFAULT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
            [_TECNICON] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
            [_DEBUGGING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        };
    #endif
#endif

// Layers do teclado
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_delphos(
        SPOTIFY,         FUSION,        BAMBU_LAB,      OBSIDIAN,
        COLAR_AVANCADO,  VS_CODE,       ARDUINO_IDE,    REGUA_VIRTUAL,
        PRINT,           COLOR_PICKER,  SOUND_MIXER,    TG(_TECNICON)
    ),

    [_TECNICON] = LAYOUT_delphos(
        _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,
        _______,    _______,    TG(_DEFAULT),    TG(_DEBUGGING)
    ),
    
    [_DEBUGGING] = LAYOUT_delphos(
        TG(_DEFAULT),    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,         XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,         XXXXXXX,    TG(_TECNICON),    QK_BOOT
    ),
};

// Processa os custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {  // Executa apenas no pressionar da tecla
        switch (keycode) {
            case ARDUINO_IDE:
                SEND_STRING("arduino" SS_TAP(X_ENTER));
                return false;
            case SPOTIFY:
                SEND_STRING("spotify" SS_TAP(X_ENTER));
                return false;
            case COLAR_AVANCADO:
                SEND_STRING(SS_LCTL("v"));  // Corrigido de SS_LCTRL para SS_LCTL
                return false;
            default:
                break;
        }
    }
    return true;
}
