#include "display.h"


int buttonState = 0; 

void setup() {
  // Display config
  display_config();

  // test display 
  display_init();
}

void loop (){
  buttonState = digitalRead(display_b1_pin); // check button 
  // If the user press button (detect HIGH to LOW - falling edge)
  if ( lastbuttonState == HIGH && buttonState==LOW){ 
    display_leds_update();
   }
   lastbuttonState = digitalRead(display_b1_pin);
  delay(50);
}
