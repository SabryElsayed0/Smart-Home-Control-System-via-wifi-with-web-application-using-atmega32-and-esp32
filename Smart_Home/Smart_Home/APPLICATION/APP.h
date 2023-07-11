 /******************************************************************************
 *
 * Module: APPLICATION
 *
 * Description: Header file of APPLICATION
 *
 *******************************************************************************/


#ifndef APP_H_
#define APP_H_
#include "DIO_interface.h"
#include "RGB.h"

//Door Controlling
void DOOR1(u8 value);

//Television Control
void Television(u8 value);

//Living_Room_Light Control
void Living_Room_Light(u8 value);

//Kitchen_Light Control
void Kitchen_Light(u8 value);

//Air_Conditioner Control
void Air_Conditioner(u8 value);

//RGB_Lighting Control
void RGB_Lighting(u8 red,u8 blue ,u8 green);
#endif /* APP_H_ */