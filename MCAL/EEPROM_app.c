/*
 * I2C_app.c
 *
 *  Created on: 16 Mar 2019
 *      Author: Laptop Market
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"
#include "AVR_I2C_REG.h"
#include "I2C_interface.h"
#include "EEPROM_interface.h"
#include "LCD_interface.h"

#define ERROR_PORT DIO_enuPORTD
#define ERROR_PIN DIO_enuPIN0

void main(void)
{

	DIO_u8SetPinDirection(ERROR_PORT,ERROR_PIN,DIO_enuOutput);
	DIO_u8SetPinDirection(ERROR_PORT,1,DIO_enuOutput);
	DIO_u8SetPinValue(ERROR_PORT,DIO_enuPIN0,DIO_enuLow);
	DIO_u8SetPinValue(ERROR_PORT,DIO_enuPIN1,DIO_enuLow);
//	DIO_u8SetPinDirection(DIO_enuPORTB,DIO_enuPIN6,DIO_enuOutput);
	DIO_u8SetPinDirection(DIO_enuPORTC,DIO_enuPIN1,DIO_enuOutput);
	DIO_u8SetPinDirection(DIO_enuPORTC,DIO_enuPIN0,DIO_enuOutput);
	DIO_u8SetPinDirection(DIO_enuPORTD,DIO_enuPIN7,DIO_enuOutput);

	LCD_vidInitialize();
	I2C_vidInit();
	u32 Data=0;
//	DIO_u8SetPinValue(DIO_enuPORTD,0,DIO_enuHigh);

	EEPROM_vidReadByte(826,&Data);
	u8* String;
	LCD_vidIntToString(Data,String);
	LCD_vidWriteString(String);
	if(Data==125)
	{
		DIO_u8SetPinValue(DIO_enuPORTD,7,DIO_enuHigh);
	}
	while(1){

	}
	return;
}
