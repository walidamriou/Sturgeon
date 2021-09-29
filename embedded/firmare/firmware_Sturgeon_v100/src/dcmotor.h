/**
 * @file dcmotor.h
 * @brief header file of dc motor with feedback controller 
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 09/29/2021
 * 
 * 
 * We have used 12V 1.2W 2200 RPM DC Brushless Motor from Kinte Electronic 
 */

#ifndef DCMOTOR_H_INCLUDED
#define DCMOTOR_H_INCLUDED

// includes
#include "global.h"

// defines
#define motor_attack_start 10 // the duty cycle of the motor attack signal in the start 
#define motor_attack_stop  0  // the duty cycle of the motor attack signal to stop the motor

#define motor_speed_1900_RPM_period 5220 
#define motor_speed_1750_period 5640 
#define motor_speed_1500_period 6550 
#define motor_speed_1000_RPM_period 10180 

#define dcmotor_control_pin 9
#define dcmotor_speed_pin 2

#define motor_attack_pwm_frequency 490 // hz

// variable defines

extern uint32_t dcmotor_speed_pulse_width,dcmotor_speed_space_width;
extern uint32_t dcmotor_speed_period;
extern uint8_t motor_attack_signal_PWM_duty_cycle;
extern uint32_t motor_speed_period_for_set_speed;

// function prototyping  
void dcmotor_control_start();
void dcmotor_speed_read();
void dcmotor_control();
void dcmotor_stop();
void dcmotor_setspeed(uint8_t speed_level);

#endif