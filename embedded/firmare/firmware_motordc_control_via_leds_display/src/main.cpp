#include "display.h"


void setup() {
  // Display config
  display_config();

  // test display 
  display_init();
}

void loop (){
  display_button(display_b1_pin,&display_leds_update);
}
