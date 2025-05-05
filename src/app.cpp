/*********************************************************************************
 * 
 *                       ELECTRONICA II UTN - FRRO                                *
 * 
 * *******************************************************************************/

//===================[File header]================================================
// File:                app.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Mayo 2025
// Info:                Proyect template for PCB Electrónica II

//====================[Use & storage]============================================
// PCB:                 NodeMCU 
// Plataforma:          ESP32S3
// Use:                 Template
// Folder:              PCB_ledTTL
// Proyect name:        PCB_ledTTL

//====================[ToDo]=====================================================     
//        
//
//
//====================[Bugs]=====================================================     
//     
//                   
//
//====================[Commits]==================================================     
//
// Last commit:
//
//===================[End file header]===========================================


//--Includes
#include "app.h"

uint16_t led_delay=200;

//--Functions
void App_loop(void){
    blink_led(led_delay,LED1_PIN);
}