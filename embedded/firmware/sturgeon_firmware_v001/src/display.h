/**
 * @file display.h
 * @brief header file of display manager
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 07/27/2021
 * 
 */

#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

// includes
#include "global.h"

// display I\O Config with microcontroller

#define display_l1_pin      13 // The LED1 of the display
#define display_l2_pin      12 // The LED2 of the display
#define display_l3_pin      11 // The LED3 of the display
#define display_l4_pin      10 // The LED4 of the display
#define display_b1_pin      2  // The button of the display
#define display_buzzer_pin  8  // The buzzer of the display

#define display_init_leds_ON_all_time  1000 // ms
#define display_init_leds_OFF_all_time 1000 // ms

#define display_buzzer_init_time 500 // ms 
#define display_buzzer_button_press 35 // ms
#define display_buzzer_frequency 4000 // hz

// variable define the status of the leds in the display (display leds software image)
extern uint8_t display_leds_status;
// variable for reading the pushbutton status
extern int lastbuttonState;

// function prototyping  
void display_config();
void display_init();
void display_button(uint8_t gpio,void (*callback_function)(void));
void display_leds_update();
void HAL_display_leds_update(uint8_t l1,uint8_t l2,uint8_t l3,uint8_t l4);
void HAL_display_buzzer(uint8_t gpio,uint16_t frequency,uint16_t run_time_ms);
void HAL_display_pin_config(uint8_t gpio,uint8_t direction);

#endif
