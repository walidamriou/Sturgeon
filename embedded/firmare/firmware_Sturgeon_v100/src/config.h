/**
 * @file config.h
 * @brief header file of config
 *
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 09/29/2021
 * 
 * 
 * 
 *  ____________                                 _________________________________                ___________________________________________
 * |            | <=== motor attack signal ==== |                                 |              |                                           |    
 * |    FAN     |                               |  Main board                     | <=========== |  Display board                            |         
 * |____________| ==== motor speed signal ====> | (Buck converter DC/DC with MCU) |              |  (MCU, 1x Button, 4x LEDs, and !x buzzer) |
 *                                              |_________________________________|              |___________________________________________|
 *
 *
 */

#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

//#define arduino_uno
#define arduino_mega

#endif