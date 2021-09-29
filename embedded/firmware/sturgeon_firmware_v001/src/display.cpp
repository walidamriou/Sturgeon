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

void display_config(){
    HAL_display_pin_config(display_l1_pin, 1); // config led1 pin output
    HAL_display_pin_config(display_l2_pin, 1); // config led2 pin output
    HAL_display_pin_config(display_l3_pin, 1); // config led3 pin output
    HAL_display_pin_config(display_l4_pin, 1); // config led4 pin output
    HAL_display_pin_config(display_b1_pin, 0);  // config button 1 pin input
    sturgeon_serial_config();
}
void display_init(){
    // on all
    HAL_display_leds_update(1,1,1,1);
    HAL_display_buzzer(display_buzzer_pin, display_buzzer_frequency,display_buzzer_init_time); 
    delay (display_init_leds_ON_all_time); 
    // off all
    HAL_display_leds_update(0,0,0,0);
    delay(display_init_leds_OFF_all_time);
    // ON the led 1
    #ifdef display_debug_text
    Serial.println("Display: ON LED 1"); 
    #endif
    HAL_display_leds_update(1,0,0,0);
    display_leds_status = 1;
    connectivity_send(10);
}

void display_button(uint8_t gpio,void (*callback_function)(void)){
  static int lastbuttonState = LOW;
  static int buttonState = digitalRead(gpio); // check button 
  // If the user press button (detect HIGH to LOW - falling edge)
  if ( lastbuttonState == HIGH && buttonState==LOW){ 
    display_leds_update();
   }
   lastbuttonState = digitalRead(display_b1_pin);
  delay(200);
}

void display_leds_update(){
    display_leds_status++; 
    if(display_leds_status>4) {display_leds_status=1;}
    // ON led 1
    if (display_leds_status==1){ 
        #ifdef display_debug_text
        Serial.println("Display: ON LED 1"); 
        #endif
        HAL_display_leds_update(1,0,0,0);
        display_leds_status = 1;
        connectivity_send(10);
        #ifdef display_debug_text
        Serial.print("Buzzer: ON in ");
        Serial.print(display_buzzer_frequency);
        Serial.print("Hz , for ");
        Serial.print(display_buzzer_button_press);
        Serial.println("ms .");
        #endif
        HAL_display_buzzer(display_buzzer_pin, display_buzzer_frequency,display_buzzer_button_press);
    }
   // ON led 2
   else if (display_leds_status==2) {
       #ifdef display_debug_text
       Serial.println ("Display: ON LED 2"); 
       #endif
       HAL_display_leds_update(0,1,0,0);
       display_leds_status = 2;
       connectivity_send(20);
       #ifdef display_debug_text
       Serial.print("Buzzer: ON in ");
       Serial.print(display_buzzer_frequency);
       Serial.print("Hz , for ");
       Serial.print(display_buzzer_button_press);
       Serial.println("ms .");
       #endif
       HAL_display_buzzer(display_buzzer_pin, display_buzzer_frequency,display_buzzer_button_press);
    }
   // ON led 3
   else if (display_leds_status==3) {
        #ifdef display_debug_text
        Serial.println ("Display: ON LED 3") ; 
        #endif
        HAL_display_leds_update(0,0,1,0);
        display_leds_status = 3;    
        connectivity_send(30);    
        #ifdef display_debug_text
        Serial.print("Buzzer: ON in ");
        Serial.print(display_buzzer_frequency);
        Serial.print("Hz , for ");
        Serial.print(display_buzzer_button_press);
        Serial.println("ms .");
        #endif
        HAL_display_buzzer(display_buzzer_pin, display_buzzer_frequency,display_buzzer_button_press);
    }
   // ON led 4
   else if (display_leds_status==4) {
        #ifdef display_debug_text
        Serial.println ("Display: ON LED 4") ; 
        #endif
        HAL_display_leds_update(0,0,0,1);
        display_leds_status = 4;
        connectivity_send(40);
        #ifdef display_debug_text
        Serial.print("Buzzer: ON in ");
        Serial.print(display_buzzer_frequency);
        Serial.print("Hz , for ");
        Serial.print(display_buzzer_button_press);
        Serial.println("ms .");
        #endif
        HAL_display_buzzer(display_buzzer_pin, display_buzzer_frequency,display_buzzer_button_press);
    }
}

void HAL_display_leds_update(uint8_t l1,uint8_t l2,uint8_t l3,uint8_t l4){
    digitalWrite(display_l1_pin,l1); 
    digitalWrite(display_l2_pin,l2); 
    digitalWrite(display_l3_pin,l3); 
    digitalWrite(display_l4_pin,l4);  
}

void HAL_display_buzzer(uint8_t gpio,uint16_t frequency,uint16_t run_time_ms){
        tone(gpio,frequency,run_time_ms);
}

void HAL_display_pin_config(uint8_t gpio,uint8_t direction){
        pinMode(gpio,direction);
}