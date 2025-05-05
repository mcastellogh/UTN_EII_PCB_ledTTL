//=======================================================================
// File:                leds.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Mayo 2025
// Info:                Proyect template for PCB Electrónica II
//=======================================================================

#include "leds.h"


//--Local variables



//--Do welcome by flashing leds
void welcome(void){
  for(int i=0;i<10;i++){
      digitalWrite(LED1_PIN,HIGH);
      delay(80);
      digitalWrite(LED1_PIN,LOW);
      delay(80);
      digitalWrite(LED2_PIN,HIGH);
      delay(80);
      digitalWrite(LED2_PIN,LOW);
      delay(80);
      digitalWrite(LED3_PIN,HIGH);
      delay(80);
      digitalWrite(LED3_PIN,LOW);
      delay(80);
  }
  delay(500);
}

//--Blink led by delay
void blink_led(uint16_t led_delay, uint8_t led_pin){
  digitalWrite(led_pin,HIGH);
  delay(led_delay);
  digitalWrite(led_pin,LOW);
  delay(led_delay);
}