/*
 * servo.h
 *
 *  Created on: Apr 26, 2023
 *      Author: youssef
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "../MCAL/DIO_INTERFACE.h"
#include "../MCAL/Timers.h"


void SERVO_Init(void);

void SERVO_SetAngle(uint8 angle);

void SERVO_Rotate_MAX_LEFT(void);	// 0 degree
void SERVO_Rotate_MAX_RIGHT(void);	// 180 degree
void SERVO_Rotate_MIDDLE(void);	// 90 degree

#endif /* SERVO_H_ */
