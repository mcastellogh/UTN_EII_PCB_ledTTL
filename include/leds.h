//=======================================================================
// File:                leds.h
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Mayo 2025
// Info:                Proyect template for PCB Electrónica II
//=======================================================================


#ifndef _leds_h_
#define _leds_h_

#include <Arduino.h>
#include "config.h"

enum led_states{
    LED_ON,
    LED_OFF,
    LED_WAIT_ON,
    LED_WAIT_OFF,
    LED_STOP
};

//--Prototypes
void welcome(void);
void blink_led(uint16_t led_delay, uint8_t led_pin);
void FSM_led_init(uint16_t time_on,uint16_t time_off);
void FSM_led(uint8_t led_pin);


#endif