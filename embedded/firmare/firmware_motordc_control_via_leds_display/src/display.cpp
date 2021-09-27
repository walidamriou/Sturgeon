/**
 * @file display.cpp
 * @brief code file of display manager
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 07/27/2021
 * 
 */

#include "display.h"
uint8_t display_leds_status=0;
int lastbuttonState = LOW;

void display_config(){
    pinMode(display_l1_pin, OUTPUT); // config led1 pin output
    pinMode(display_l2_pin, OUTPUT); // config led2 pin output
    pinMode(display_l3_pin, OUTPUT); // config led3 pin output
    pinMode(display_l4_pin, OUTPUT); // config led4 pin output
    pinMode(display_b1_pin, INPUT);  // config button 1 pin input
}
void display_init(){
    // on all
    HAL_display_leds_update(1,1,1,1);
    tone(display_buzzer_pin, 4000,500); // test buzzer
    delay (1000); // 1s 
    
    // off all
    HAL_display_leds_update(0,0,0,0);

    delay(1000);

    // ON the led 1
    HAL_display_leds_update(1,0,0,0);
    display_leds_status=1;
}
void display_leds_update(){
    display_leds_status++; 
    if(display_leds_status>4) {display_leds_status=1;}

 
 if (display_leds_status==1) 
 { 

     HAL_display_leds_update(1,0,0,0);
     display_leds_status = 1;

 Serial.println ("display_l1_pin est allumée") ; 
  tone(display_buzzer_pin, 4000,display_buzzer_button_press);
  //1
   }
   if (display_leds_status==2) {
HAL_display_leds_update(0,1,0,0);
display_leds_status = 2;
 Serial.println ("display_l1_pin est allumée") ; 
  tone(display_buzzer_pin, 4000,display_buzzer_button_press);
  //1
   }
 
 if (display_leds_status==3) {
 HAL_display_leds_update(0,0,1,0);
 display_leds_status = 3;

 Serial.println ("display_l3_pin est allumée") ; 
  tone(display_buzzer_pin, 4000,display_buzzer_button_press);
  //1
  }
   if (display_leds_status==4) {
 HAL_display_leds_update(0,0,0,1);
 display_leds_status = 4;

 Serial.println ("display_l1_pin est allumée") ; 
  tone(display_buzzer_pin, 4000,display_buzzer_button_press);
  //1
   }
}

void HAL_display_leds_update(uint8_t l1,uint8_t l2,uint8_t l3,uint8_t l4){
    digitalWrite(display_l1_pin,l1); 
    digitalWrite(display_l2_pin,l2); 
    digitalWrite(display_l3_pin,l3); 
    digitalWrite(display_l4_pin,l4);  
}
