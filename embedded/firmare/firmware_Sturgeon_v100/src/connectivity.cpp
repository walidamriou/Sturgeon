/**
 * @file connectivity.cpp
 * @brief code file of connectivity
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 09/29/2021
 * 
 */

#include "connectivity.h"

void connectivity_config(){
    Serial.begin(sturgeon_serial_speed);
}

void connectivity_send(int data_send){
    Serial.write(data_send);
}

void connectivity_receive(){
if(Serial.available()) {
    int data_rcvd = Serial.read();   // read one byte from serial buffer and save to data_rcvd
    Serial.println(data_rcvd);
    if(data_rcvd == 10){
        dcmotor_setspeed(1);
    }
    if(data_rcvd == 20){
        dcmotor_setspeed(2);
    }
    if(data_rcvd == 30){
        dcmotor_setspeed(3);  
    }  
    if(data_rcvd == 40){
        dcmotor_setspeed(4);

    }

}
}