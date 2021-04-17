/*
 * FruitPack_App.c
 *
 *  Created on: 13 May 2019
 *      Author: Laptop Market
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_INTP_REG.h"
#include"AVR_DIO_REG.h"
#include "AVR_TIMER_REG.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "INTERRUPT_interface.h"
#include "Timer_interface.h"

#define Packs_Port 	DIO_enuPORTD
#define Packs_Motor DIO_enuPIN3

#define Fruit_Port 	DIO_enuPORTB
#define Fruit_Motor DIO_enuPIN1

void(*ptrfunc)(void);

void vidPackReach()
{
	DIO_u8SetPinValue(Packs_Port,Packs_Motor,DIO_enuLow);
	DIO_u8SetPinValue(Fruit_Port,Fruit_Motor,DIO_enuHigh);
	return;
}

void vidPackFilled()
{
	DIO_u8SetPinValue(DIO_enuPORTD,DIO_enuPIN3,DIO_enuHigh);
	DIO_u8SetPinValue(DIO_enuPORTB,DIO_enuPIN1,DIO_enuLow);
	return;
}

void main()
{
	u8 String;
	DIO_u8SetPinDirection(Packs_Port,Packs_Motor,DIO_enuOutput);
	DIO_u8SetPinDirection(Fruit_Port,Fruit_Motor,DIO_enuOutput);
	DIO_u8SetPortDirection(DIO_enuPORTA,0xFF);
	DIO_u8SetPinDirection(Fruit_Port,0,DIO_enuInput);
	DIO_u8SetPinDirection(Packs_Port,2,DIO_enuInput);

	//DIO_u8SetPinValue(Fruit_Port,0,1);
	DIO_u8SetPinValue(Packs_Port,Packs_Motor,1);

	INTP_vidInit();
	INTP_vidIntp0SetCallBack(vidPackReach);
	TIMER_vidInit();
	TIMER0_CTC_vidSetCallBack(vidPackFilled);
	LCD_vidInitialize();
	OCR0=4;
	TCNT0=0;
	while(1)
	{
		LCD_vidGoTo_XY(1,1);
		LCD_vidIntToString(TCNT0,&String);
		LCD_vidWriteString(&String);
		//LCD_vidWriteCommand(LCD_u8CLEAR_DISPLAY);
		if(TCNT0==0)
			{
				DIO_u8SetPinValue(DIO_enuPORTA,5,1);
				LCD_vidWriteCommand(LCD_u8CLEAR_DISPLAY);
			}
		else
			DIO_u8SetPinValue(DIO_enuPORTA,5,0);
	}
	return ;
}
