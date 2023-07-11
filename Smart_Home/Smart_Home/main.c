/**************************************************************************************************
 * Author      : Sabry Elsayed
/
 * Description : Main file for Smart Home Control System over Wi-Fi by a web application.
/ 
 ************************************************************************/
#define F_CPU 8000000
#include <Util/delay.h>
#include "MEMmap.h"
#include  "STDTYPES.h"
#include "UTILS.h"
#include "DIO_interface.h"
#include  "LCD.h"
#include "Timers.h"
#include "UART.h"
#include "RGB.h"
#include "APP.h"
//buffer for received data
u8 data[70]={0};

//for garbage data
u8 data2;



int main(void)
{
	u8 n=0;
	
	//initialization for DIO
	DIO_Init();
	
	//initialization for LCD
	LCD_Init();
	
	//initialization UART
	UART_Init();
	
	//initialization timer1 as Fast PWM and OCRA as top and prescaler 8
	Timer1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8);
	
	//initialize OCR1B pin
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	
	//initialize top for OCR1A and OCR1B
	OCR1A=19999;
	OCR1B=999;
	
	//for global interrupt enable
	sei();
	LCD_GoTo(0,0);
	LCD_WriteString("hello");
	LCD_Clear();
	/* Replace with your application code */
	while (1)
	{
		LCD_GoTo(1,1);
		LCD_WriteNumber(n);
		LCD_GoTo(0,0);
		
		//Receive data from esp32
		UART_RecieveString(data);
		
		//for garbage data
		data2=UART_Receive();
		
		//for door control as opened or closed
		DOOR1(data[6]);
		
		//for Television control as on or off
		Television(data[14]);
		
		//for Living_Room_Light control as on or off
		Living_Room_Light(data[22]);
		
		//for Kitchen_Light control as on or off
		Kitchen_Light(data[30]);
		
		//for Air_Conditioner control as on or off
		Air_Conditioner(data[38]);
		
		//for RGB_Lighting control
		RGB_Lighting(data[46],data[54],data[62]);
		
	}
}
