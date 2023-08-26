/*
 * main.h
 *
 *  Created on: Apr 11, 2023
 *      Author: youssef
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "PLATFORM/STD_TYPES.h"
#include "PLATFORM/STD_LIBRARY.h"
#include "PLATFORM/Mem_Map32.h"
#include "MCAL/DIO_INTERFACE.h"
#include "MCAL/Timers.h"
#include "util/delay.h"
#include "HAL/ultrasonic.h"
#include "HAL/servo.h"
#include "SERVICES/Timer_Services.h"

#define Ultrasonic_Port                 PORT_D
#define Echo_Pin		                PIN_6
#define Trigger_Pin                     PIN_0
#define STOP_DISTANCE                   35

#define Speed_Control_Port              PORT_B
#define Speed_Control_Left_Wheel        PIN_0
#define Speed_Control_Right_Wheel       PIN_1


void func_OVF_Timer0();
void func_OC_Timer0();

void Robot_Start();
void Robot_Move_Forward();
void Robot_Stop();
void Robot_Turn_Right();
void Robot_Turn_Left();


#endif /* MAIN_H_ */
