/*
 * Timer_Services.c
 *
 *  Created on: Apr 26, 2023
 *      Author: youssef
 */

#include "Timer_Services.h"

//;)


void PWM_Timer0_Init()
{
	Timer0_Init(TIMER0_FASTPWM_MODE , TIMER0_SCALER_64 , OCO_DISCONNECTED);
}

void PWM_Timer0_Duty(uint16 duty)
{
	// This is Software PWM (OC0 Disconnected)
	if(duty <= 100)
	{
		uint16 Ton = (duty * 256) / 100;
		if(Ton > 1)
		{
			OCR0 = Ton;
		}
		else
		{
			OCR0 = 0;
		}
	}
}


