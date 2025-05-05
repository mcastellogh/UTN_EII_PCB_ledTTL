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

uint8_t FSM_led_state;
uint32_t FSM_led_crono;
uint16_t toff;
uint16_t ton;

void FSM_led_init(uint16_t time_on,uint16_t time_off){
    FSM_led_state=LED_OFF;
    FSM_led_crono = millis();
    ton=time_on;
    toff=time_off;
}

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

//--Blink led with configurable time on/off and FSM
void FSM_led(uint8_t led_pin){
  switch (FSM_led_state){
    case LED_ON:   
      digitalWrite(led_pin, HIGH);
      FSM_led_crono = millis();
      FSM_led_state = LED_WAIT_ON;
      break;
    case LED_OFF:  
      digitalWrite(led_pin, LOW);
      FSM_led_crono = millis();
      FSM_led_state = LED_WAIT_OFF;
      break;
    case LED_WAIT_OFF:
      if (millis() - FSM_led_crono >= toff){
        FSM_led_state = LED_ON;
      }
      break;
    case LED_WAIT_ON:
      if (millis() - FSM_led_crono >= ton){
        FSM_led_state = LED_OFF;
      }
      break;
    case LED_STOP:
      digitalWrite(led_pin, LOW);
      break;
    default:
      FSM_led_state = LED_OFF;
      break;
  }
}