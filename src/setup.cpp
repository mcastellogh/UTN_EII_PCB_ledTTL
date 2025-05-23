//=======================================================================
// File:                setup.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Mayo 2025
// Info:                Proyect template for PCB Electrónica II
//=======================================================================

#include "setup.h"

//--Harcoded local variables
const char * device_name="device01";
const char * device_type="LedDriver";


void App_setup(void){
    Serial.begin(SERIAL_BAUDRATE);

    //--PINS
    pinMode(ONBOARD_LED_PIN,OUTPUT);
    pinMode(LED1_PIN,OUTPUT);
    pinMode(LED2_PIN,OUTPUT);
    pinMode(LED3_PIN,OUTPUT);

    welcome();
    FSM_led_init(30,700);

    //--Presentation
    Serial.printf("\r\nCátedra de Electrónica II UTN-FRRO\r\n");
    Serial.printf("Hello, I'm %s, and my name is %s\r\n",device_type,device_name);
    Serial.println("At the moment I only flash a led. I invite you to code me!");
}