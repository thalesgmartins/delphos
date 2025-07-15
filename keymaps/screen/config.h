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
// Display OLED
//
#ifndef OLED_ENABLE
    #define OLED_ENABLE
#endif

#ifndef OLED_DRIVER_ENABLE
    #define OLED_DRIVER_ENABLE
#endif

// Configurações do Display OLED
#define OLED_DISPLAY_128x64
#define OLED_TIMEOUT 0
