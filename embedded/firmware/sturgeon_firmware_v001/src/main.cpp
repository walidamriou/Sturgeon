#include "global.h"
#ifdef arduino_uno
#include "display.h"
#endif
#ifdef arduino_mega
#include "dcmotor.h"
#endif

void setup() {

  #ifdef arduino_uno
  // Display config
  display_config();
  // test display 
  display_init();
  #endif

  #ifdef arduino_mega
  connectivity_config();
  dcmotor_control_start();
  #endif
  
}

void loop (){
  #ifdef arduino_uno
  display_button(display_b1_pin,&display_leds_update);
  #endif
  #ifdef arduino_mega
  connectivity_receive();
  dcmotor_speed_read();
  dcmotor_control();
  #endif
}
