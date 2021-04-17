/*

 * UART_app.c
 *
 *  Created on: 8 Mar 2019
 *      Author: Laptop Market
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "SPI_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"
#include "AVR_SPI_REG.h"

#define SPI_PORT	DIO_enuPORTB
#define MOSI DIO_enuPIN4
#define MISO DIO_enuPIN5
#define SS DIO_enuPIN6
#define CLK DIO_enuPIN7

void main(void)
{
	DIO_u8SetPinDirection(SPI_PORT,MISO,DIO_enuOutput);
	DIO_u8SetPinDirection(SPI_PORT,MOSI,DIO_enuInput);
	DIO_u8SetPinDirection(SPI_PORT,CLK,DIO_enuInput);
	DIO_u8SetPinDirection(SPI_PORT,SS,DIO_enuInput);

	DIO_u8SetPinDirection(DIO_enuPORTC,DIO_enuPIN0,DIO_enuOutput);

//	DIO_u8SetPinValue(SPI_PORT,SS,DIO_enuLow);

	SPI_vidInit();
	u8 LOC_u8DATA='A';
	u8 LOC_u8RecData;

	while(1)
	{
		SPI_vidTRANSFERE(LOC_u8DATA,&LOC_u8RecData);
		if(LOC_u8RecData=='A')
		{
			DIO_u8SetPinValue(DIO_enuPORTC,DIO_enuPIN0,DIO_enuHigh);
		}else
			DIO_u8SetPinValue(DIO_enuPORTC,DIO_enuPIN0,DIO_enuLow);
	}
	return;

}


