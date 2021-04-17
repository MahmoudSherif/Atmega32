/*

 * UART_prog.c
 *
 *  Created on: 8 Mar 2019
 *      Author: Laptop Market
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_I2C_REG.h"
#include "AVR_INTP_REG.h"
#include "DIO_interface.h"
#include "EEPROM_interface.h"
#include "I2C_interface.h"
#include "LCD_interface.h"

#define EEPROM_FIXED_ADD 0b1010

#define ERROR_PORT DIO_enuPORTD
#define ERROR_PIN DIO_enuPIN0

#define CLK 8000000
#define Null (void*)0


void EEPROM_vidWriteByte(u16 COPY_u16ByteAddress ,u8 COPY_u8DataToWrite)
{
	u8 LOC_u8BlockNB = COPY_u16ByteAddress /255;
	u8 LOC_u8ByteNB =	COPY_u16ByteAddress % 255 ;
	//1010EblockNb
	u8 LOC_u8SLA= (EEPROM_FIXED_ADD <<3) | LOC_u8BlockNB;
	u8 LOC_u8State;
	do{
		I2C_vidSendStartCondition();
		I2C_vidGetStatus(&LOC_u8State);
		if(LOC_u8State==TW_START)
		{
			DIO_u8SetPinValue(ERROR_PORT,ERROR_PIN,DIO_enuHigh);
		}
		I2C_vidSendSlaveAddress(LOC_u8SLA,I2C_WRITE_OP);
		I2C_vidGetStatus(&LOC_u8State);
		if(LOC_u8State == TW_MT_SLA_ACK)
			DIO_u8SetPinValue(DIO_enuPORTD,0,DIO_enuHigh);
	}while(LOC_u8State == TW_MT_SLA_ACK);
	DIO_u8SetPinValue(ERROR_PORT,ERROR_PIN,DIO_enuHigh);
	I2C_vidWriteData(LOC_u8ByteNB);
	I2C_vidGetStatus(&LOC_u8State);
	if(LOC_u8State==TW_MT_DATA_ACK)
	{
		DIO_u8SetPinValue(ERROR_PORT,ERROR_PIN,DIO_enuHigh);
	}
	I2C_vidWriteData(COPY_u8DataToWrite);
	I2C_vidGetStatus(&LOC_u8State);
	if(LOC_u8State==TW_MT_DATA_ACK)
	{
		DIO_u8SetPinValue(ERROR_PORT,ERROR_PIN,DIO_enuHigh);
	}
	I2C_vidSendStopCondition();

	return;
}


void EEPROM_vidReadByte(u16 COPY_u16ByteAddress ,u8* COPY_pu8Data)
{
//	DIO_u8SetPinValue(DIO_enuPORTD,0,DIO_enuHigh);

	u8 LOC_u8BlockNB = COPY_u16ByteAddress /255;
	u8 LOC_u8ByteNB =	COPY_u16ByteAddress % 255 ;
	//1010EblockNb
	u8 LOC_u8SLA= (EEPROM_FIXED_ADD <<3) | LOC_u8BlockNB;
	u8 LOC_u8State;

	do{
//		Send Start condition
		I2C_vidSendStartCondition();
		I2C_vidGetStatus(&LOC_u8State);
		if(LOC_u8State!=TW_START)
		{
				DIO_u8SetPinValue(ERROR_PORT,0,DIO_enuHigh);
		}
		//send the slave address and write operation to write the byteNB you want to read
		I2C_vidSendSlaveAddress(LOC_u8SLA,I2C_WRITE_OP);
		I2C_vidGetStatus(&LOC_u8State);

	}while(LOC_u8State!=TW_MT_SLA_ACK);


	I2C_vidWriteData(LOC_u8ByteNB);
	I2C_vidGetStatus(&LOC_u8State);
	if(LOC_u8State!=TW_MT_DATA_ACK)
	{
		DIO_u8SetPinValue(ERROR_PORT,1,DIO_enuHigh);
	}

	//repeated start
	I2C_vidSendStartCondition();
	I2C_vidGetStatus(&LOC_u8State);
	if(LOC_u8State!=TW_REP_START)
	{
//		DIO_u8SetPinValue(ERROR_PORT,ERROR_PIN,DIO_enuHigh);
	}
	I2C_vidSendSlaveAddress(LOC_u8SLA,I2C_READ_OP);
	I2C_vidGetStatus(&LOC_u8State);
	if(LOC_u8State!=TW_MT_SLA_ACK)
	{
//		DIO_u8SetPinValue(ERROR_PORT,ERROR_PIN,DIO_enuHigh);
	}
	I2C_vidReadNotAck(COPY_pu8Data);
	I2C_vidGetStatus(&LOC_u8State);
	if(LOC_u8State!=TW_MR_DATA_NOT_ACK)
	{
//		DIO_u8SetPinValue(ERROR_PORT,ERROR_PIN,DIO_enuHigh);
	}
	I2C_vidSendStopCondition();
	LCD_vidWriteString("DONEEE");

//
//	u8 LOC_u8State;
//	I2C_vidSendStartCondition();
//	I2C_vidGetStatus(&LOC_u8State);
//
//	if(LOC_u8State != TW_START )
//	{
//		DIO_u8SetPinValue(DIO_enuPORTD,0,1);
//	}
//	I2C_vidWriteData((u8)(0xA0 | ((COPY_u16ByteAddress & 0x0700) >> 7)));
//	I2C_vidGetStatus(&LOC_u8State);
//
//	if(LOC_u8State !=TW_MT_SLA_ACK )
//	{
//		DIO_u8SetPinValue(DIO_enuPORTD,0,1);
//		LCD_vidWriteData(LOC_u8State+70);
//	}
//	I2C_vidWriteData((u8)COPY_u16ByteAddress);
//	I2C_vidGetStatus(&LOC_u8State);
//
//	if(LOC_u8State != TW_MT_SLA_ACK)
//	{
////		DIO_u8SetPinValue(DIO_enuPORTD,0,1);
//		LCD_vidWriteData(LOC_u8State+70);
//	}
//	I2C_vidSendStartCondition();
//	I2C_vidGetStatus(&LOC_u8State);
//		if(LOC_u8State != TW_START)
//		{
//			LCD_vidWriteData(LOC_u8State+70);
//
//		}
//		I2C_vidWriteData((u8)(0xA0 | ((COPY_u16ByteAddress & 0x0700) >> 7) | 1));
//		I2C_vidGetStatus(&LOC_u8State);
//
//	if(LOC_u8State!= TW_MR_SLA_NOT_ACK)
//	{
//
//	}
//	I2C_vidReadNotAck(COPY_pu8Data);
//	I2C_vidGetStatus(&LOC_u8State);
//
//	if(LOC_u8State != TW_MR_DATA_NOT_ACK)
//	{
//		LCD_vidWriteData(LOC_u8State+70);
//
//	}
//	I2C_vidSendStopCondition();

}
