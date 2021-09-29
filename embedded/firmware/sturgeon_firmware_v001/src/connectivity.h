/**
 * @file connectivity.h
 * @brief header file of connectivity
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 09/29/2021
 * 
 * 
 */

#ifndef CONNECTIVITY_H_INCLUDED
#define CONNECTIVITY_H_INCLUDED

// includes
#include "global.h"

// defines
#define connectivity_motor_start 10
#define connectivity_motor_speed_level_1 20
#define connectivity_motor_speed_level_2 30
#define connectivity_motor_speed_level_3 40
#define connectivity_motor_speed_level_4 50
#define connectivity_motor_stop 60

// variable defines

// function prototyping 
void connectivity_config(); 
void connectivity_send(int data_send);
void connectivity_receive();
#endif