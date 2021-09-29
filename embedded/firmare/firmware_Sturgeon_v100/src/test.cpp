/**
 * @file test.cpp
 * @brief code file of testing library
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 07/28/2021
 * 
 */

#include "test.h"

void sturgeon_serial_config(){
    Serial.begin(sturgeon_serial_speed);
}