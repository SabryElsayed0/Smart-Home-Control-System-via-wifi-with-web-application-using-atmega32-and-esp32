/******************************************************************************
 *
 * Module: APPLICATION
 *
 * Description: Source file of APPLICATION
 *
 *******************************************************************************/
/***********************************************************************************************/
#include "APP.h"

//for  door control as opened or closed
static volatile u16 angle=0;

/*************************************************Door Control*******************************************/
void DOOR1(u8 value)
{
	//Door opened 
	if(value == '1')
	{
		angle=180;
	}
	//Door closed
	else
	{
		angle=0;

	}
	OCR1B=((u32)angle*1000)/180+999;
}
/**********************************Television Control*************************************************/
void Television(u8 value)
{
	//Television on
	if(value == '1')
	{
		DIO_WritePin2(4,PC,HIGH);

	}
	//Television off
	else
	{
		DIO_WritePin2(4,PC,LOW);

	}
}
/****************************************Living_Room_Light Control****************************************************/
void Living_Room_Light(u8 value)
{
	//Living_Room_Light on
	if(value == '1')
	{
		DIO_WritePin2(0,PC,HIGH);

	}
	//Living_Room_Light off
	else
	{
		DIO_WritePin2(0,PC,LOW);

	}
}
/*******************************************Kitchen_Light Control****************************************/
void Kitchen_Light(u8 value)
{
	if(value == '1')
	{
		DIO_WritePin2(1,PC,HIGH);

	}
	else
	{
		DIO_WritePin2(1,PC,LOW);

	}
}
/**************************************Air_Conditioner Control***************************************/

void Air_Conditioner(u8 value)
{
	if(value == '1')
	{
		DIO_WritePin2(3,PC,HIGH);

	}
	else
	{
		DIO_WritePin2(3,PC,LOW);

	}
}
/*********************************RGB_Lighting Control***********************************************/
void RGB_Lighting(u8 red,u8 blue ,u8 green)
{
	
	if(red == '1')
	{
	     Set_Color2(RED);
	}
	else
	{
		clear_Color2(RED);
	}
	
	if(blue == '1')
	{
		Set_Color2(BLUE);
	}
	else
	{
		clear_Color2(BLUE);
	}
	
	if(green == '1')
	{
		Set_Color2(GREEN);
	}
	else
	{
	    clear_Color2(GREEN);
	}
}
/*********************************************************************************************************/
