/*
 * Fawzy.c
 *
 *  Created on: Feb 8, 2023
 *      Author: youssef
 */

#include "main.h"

int main()
{
	uint8 distance,dist_Left,dist_Right;

	DIO_uint8SetDirectionPIN(Ultrasonic_Port , Echo_Pin , PIN_INPUT);
	DIO_uint8SetValuePIN(Ultrasonic_Port , Echo_Pin , PIN_HIGH);
	DIO_uint8SetDirectionPIN(Ultrasonic_Port , Trigger_Pin , PIN_OUTPUT);

	Robot_Start();

	Robot_Move_Forward();

	/****************************************************************************/

	sei();	// enable the global interrupt

	/************	PWM Configurations	  ************/
	DIO_uint8SetDirectionPIN(Speed_Control_Port , Speed_Control_Left_Wheel , PIN_OUTPUT);
	DIO_uint8SetDirectionPIN(Speed_Control_Port , Speed_Control_Right_Wheel , PIN_OUTPUT);

	PWM_Timer0_Init(); // Software PWM (OC0 hardware pin Disconnected)
	Timer0_OC0_SetCallBack(func_OC_Timer0);
	Timer0_OVF_SetCallBack(func_OVF_Timer0);
	PWM_Timer0_Duty(60);	//start moving with about 60% its max speed

	DIO_uint8SetValuePIN(Speed_Control_Port , Speed_Control_Left_Wheel , PIN_HIGH);
	DIO_uint8SetValuePIN(Speed_Control_Port , Speed_Control_Right_Wheel , PIN_HIGH);

	Timer0_OV_InterruptEnable();
	Timer0_OC_InterruptEnable();

	/****************************************************************************/

	/************	Ultrasonic and Servo Configurations	  ************/
	DIO_uint8SetDirectionPIN(PORT_D , PIN_4 , PIN_OUTPUT);	// OC1B pin
	Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_NON_INVERTING);	// OCRB hardware pin used in Servo
	ULTRASONIC_Init();
	SERVO_Init();
	SERVO_Rotate_MIDDLE();

	while(1)
	{

		distance = ULTRASONIC_GetDistance(Ultrasonic_Port , Trigger_Pin);
		if(distance < STOP_DISTANCE)	// avoiding obstacles by stopping one motor wheel to turn left/right
		{
			Robot_Stop();
			PWM_Timer0_Duty(45); //Reducing speed of Robot when starting to turn (45% of max speed)

			SERVO_Rotate_MAX_RIGHT();
			_delay_ms(800);
			dist_Right=ULTRASONIC_GetDistance(Ultrasonic_Port , Trigger_Pin);

			SERVO_Rotate_MAX_LEFT();
			_delay_ms(800);
			dist_Left=ULTRASONIC_GetDistance(Ultrasonic_Port , Trigger_Pin);

			SERVO_Rotate_MIDDLE();
			_delay_ms(500);

			if(dist_Left >= dist_Right)
			{
				Robot_Turn_Left();
			}
			else
			{
				Robot_Turn_Right();
			}
		}
		PWM_Timer0_Duty(60);
	}

	return 0;
}

void func_OVF_Timer0()
{
	DIO_uint8SetValuePIN(Speed_Control_Port , Speed_Control_Left_Wheel , PIN_HIGH);
	DIO_uint8SetValuePIN(Speed_Control_Port , Speed_Control_Right_Wheel , PIN_HIGH);
}

void func_OC_Timer0()
{
	DIO_uint8SetValuePIN(Speed_Control_Port , Speed_Control_Left_Wheel , PIN_LOW);
	DIO_uint8SetValuePIN(Speed_Control_Port , Speed_Control_Right_Wheel , PIN_LOW);
}
void Robot_Start()
{
	/*	Control of Channel A	*/
	DIO_uint8SetDirectionPIN(PORT_A , PIN_0 , PIN_OUTPUT);	//IN1
	DIO_uint8SetDirectionPIN(PORT_A , PIN_1 , PIN_OUTPUT);	//IN2
	/*	Control of Channel B	*/
	DIO_uint8SetDirectionPIN(PORT_A , PIN_2 , PIN_OUTPUT);	//IN3
	DIO_uint8SetDirectionPIN(PORT_A , PIN_3 , PIN_OUTPUT);	//IN4
}
void Robot_Move_Forward()
{
	DIO_uint8SetValuePIN(PORT_A , PIN_0 , PIN_HIGH);
	DIO_uint8SetValuePIN(PORT_A , PIN_1 , PIN_LOW);
	DIO_uint8SetValuePIN(PORT_A , PIN_2 , PIN_LOW);
	DIO_uint8SetValuePIN(PORT_A , PIN_3 , PIN_HIGH);
}
void Robot_Stop()
{
	DIO_uint8SetValuePIN(PORT_A , PIN_0 , PIN_LOW);
	DIO_uint8SetValuePIN(PORT_A , PIN_1 , PIN_LOW);
	DIO_uint8SetValuePIN(PORT_A , PIN_2 , PIN_LOW);
	DIO_uint8SetValuePIN(PORT_A , PIN_3 , PIN_LOW);
}
void Robot_Turn_Right()
{
	DIO_uint8SetValuePIN(PORT_A , PIN_2 , PIN_LOW);
	DIO_uint8SetValuePIN(PORT_A , PIN_3 , PIN_HIGH);
	_delay_ms(800);
	DIO_uint8SetValuePIN(PORT_A , PIN_0 , PIN_HIGH);
	DIO_uint8SetValuePIN(PORT_A , PIN_1 , PIN_LOW);
}
void Robot_Turn_Left()
{
	DIO_uint8SetValuePIN(PORT_A , PIN_0 , PIN_HIGH);
	DIO_uint8SetValuePIN(PORT_A , PIN_1 , PIN_LOW);
	_delay_ms(500);
	DIO_uint8SetValuePIN(PORT_A , PIN_2 , PIN_LOW);
	DIO_uint8SetValuePIN(PORT_A , PIN_3 , PIN_HIGH);
}


