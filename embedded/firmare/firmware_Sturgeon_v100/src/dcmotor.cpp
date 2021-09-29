/**
 * @file dcmotor.cpp
 * @brief code file of dc motor with feedback controller 
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 09/29/2021
 * 
 */

#include "dcmotor.h"


// variable defines
uint32_t dcmotor_speed_pulse_width,dcmotor_speed_space_width = 0;
uint32_t dcmotor_speed_period = 0;

uint8_t motor_attack_signal_PWM_duty_cycle=motor_attack_start;

uint32_t motor_speed_period_for_set_speed=connectivity_motor_speed_level_1;

void dcmotor_control_start(){
  #ifdef dcmotor_debug_text
  Serial.println("DC motor start");
  #endif
  analogWrite(dcmotor_control_pin, motor_attack_signal_PWM_duty_cycle); 
  delay(500); // wait 0.5s
}
void dcmotor_speed_read(){
  dcmotor_speed_pulse_width = pulseIn(dcmotor_speed_pin,HIGH);
  dcmotor_speed_space_width = pulseIn(dcmotor_speed_pin,LOW);
  dcmotor_speed_period = dcmotor_speed_pulse_width+dcmotor_speed_space_width; 
}
void dcmotor_control(){
  if(dcmotor_speed_period>motor_speed_period_for_set_speed){ // current speed < set speed 
    motor_attack_signal_PWM_duty_cycle++;
    if(motor_attack_signal_PWM_duty_cycle>250){
      motor_attack_signal_PWM_duty_cycle = 250;
    }
  }
  if(dcmotor_speed_period<motor_speed_period_for_set_speed){ // current speed > set speed 
    motor_attack_signal_PWM_duty_cycle--;
      if(motor_attack_signal_PWM_duty_cycle<10){
      motor_attack_signal_PWM_duty_cycle = 10;
    }
  }
  #ifdef dcmotor_debug_text
  Serial.println(motor_attack_signal_PWM_duty_cycle);
  #endif
  analogWrite(dcmotor_control_pin, motor_attack_signal_PWM_duty_cycle); 
}

void dcmotor_stop(){

}

void dcmotor_setspeed(uint8_t speed_level){
  if(speed_level==1){
    motor_speed_period_for_set_speed=motor_speed_1000_RPM_period;  }
  else if(speed_level==2){
    motor_speed_period_for_set_speed=motor_speed_1500_period;
  }
  else if(speed_level==3){
    motor_speed_period_for_set_speed=motor_speed_1750_period;
  }
  else if(speed_level==4){
    motor_speed_period_for_set_speed=motor_speed_1900_RPM_period;
  }
  Serial.println(motor_speed_period_for_set_speed);

  
}