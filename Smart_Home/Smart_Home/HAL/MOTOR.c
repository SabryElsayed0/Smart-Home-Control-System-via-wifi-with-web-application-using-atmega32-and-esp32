 /******************************************************************************
 *
 * Module: MOTOR
 *
 * Description: Source file of MOTOR driver for AVR
 *
 *******************************************************************************/
#include "MOTOR.h"

void MOTOR_CW(MOTOR_type motor)
{
	switch(motor)
	{
		case Ml:
		 DIO_WritePin( IN1_M1,HIGH);
		 DIO_WritePin(IN2_M1,LOW);
		 break;
		 case M2:
		 DIO_WritePin( IN1_M2,HIGH);
		 DIO_WritePin(IN2_M2,LOW);
		 break;
		 case M3:
		 DIO_WritePin( IN1_M3,HIGH);
		 DIO_WritePin(IN2_M3,LOW);
		 break;
		 case M4:
		 DIO_WritePin( IN1_M4,HIGH);
		 DIO_WritePin(IN2_M4,LOW);
		 break;
	
	}
	 
}
void MOTOR_CCW(MOTOR_type motor)
{
		 DIO_WritePin( IN1_M1,LOW);
		 DIO_WritePin(IN2_M1,HIGH);
}
void MOTOR_Stop(MOTOR_type motor)
{
	 DIO_WritePin( IN1_M1,LOW);
	 DIO_WritePin(IN2_M1,LOW);
}