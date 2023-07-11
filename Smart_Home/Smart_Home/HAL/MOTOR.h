 /******************************************************************************
 *
 * Module: MOTOR
 *
 * Description: header file of MOTOR driver for AVR
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_
#include "DIO_interface.h"
/************************pin configuration************/
#define IN1_M1  PINC0
#define IN2_M1  PINC1
#define IN1_M2  PINC2
#define IN2_M2  PINC3
#define IN1_M3  PINC4
#define IN2_M3  PINC5
#define IN1_M4   PINC6
#define IN2_M4  PINC7
/********************************************************/
typedef enum{
	Ml,
	M2,
	M3,
	M4
	}MOTOR_type;
void MOTOR_CW(MOTOR_type motor);

void MOTOR_CCW(MOTOR_type motor);
void MOTOR_Stop(MOTOR_type motor);  




#endif /* MOTOR_H_ */