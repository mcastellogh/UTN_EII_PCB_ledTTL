//=======================================================================
// File:                config.h
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Mayo 2025
// Info:                Proyect template for PCB Electrónica II
//=======================================================================


#ifndef _config_h_
#define _config_h_

//--Includes
#include <Arduino.h>

//--Hardware PINS definitions
#define ONBOARD_LED_PIN             2
#define LED1_PIN                    38
#define LED2_PIN                    1
#define LED3_PIN                    2


//--Software constants
#define SERIAL_BAUDRATE             19200

//--Prototypes
void App_setup(void);
void App_loop(void);


#endif