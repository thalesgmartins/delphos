#pragma once

//
// Rotary Encoder
//
#ifndef ENCODER_ENABLE
    #define ENCODER_ENABLE
#endif

// Configurações do Rotary Encoder
#define ENCODER_A_PINS { F6 }
#define ENCODER_B_PINS { B2 } 
#define ENCODER_RESOLUTION 4

//
// Botão do Rotary Encoder (Configurado como um DIP Switch)
//
#ifndef DIP_SWITCH_ENABLE
    #define DIP_SWITCH_ENABLE
#endif

#define DIP_SWITCH_PINS { F5 } // Configura os pinos em que os 'botões' estão conectados

//
// Display OLED
//
#ifndef OLED_ENABLE
    #define OLED_ENABLE
#endif

// Configurações do Display OLED
#define OLED_DISPLAY_128x64
