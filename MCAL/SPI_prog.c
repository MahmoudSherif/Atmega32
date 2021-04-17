/*

 * UART_prog.c
 *
 *  Created on: 8 Mar 2019
 *      Author: Laptop Market
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "SPI_interface.h"
#include "AVR_INTP_REG.h"
#include "AVR_SPI_REG.h"

#define Null (void*)0

void SPI_vidInit(void)
{
#if SPI_STATE== SPI_MASTER
	switch (SPI_PRESCALER) {
	case SPI_2PRESCALER:
		 CLEAR_BIT(SPCR,SPCR_SPR0);
		 CLEAR_BIT(SPCR,SPCR_SPR0);
		 SET_BIT(SPSR,SPSR_SPI2X);
		break;
	case SPI_4PRESCALER:
		 CLEAR_BIT(SPCR,SPCR_SPR0);
		 CLEAR_BIT(SPCR,SPCR_SPR0);
		 CLEAR_BIT(SPSR,SPSR_SPI2X);
		break;
	case SPI_8PRESCALER:
		 SET_BIT(SPCR,SPCR_SPR0);
		 CLEAR_BIT(SPCR,SPCR_SPR0);
		 SET_BIT(SPSR,SPSR_SPI2X);
		break;
	case SPI_16PRESCALER:
		 SET_BIT(SPCR,SPCR_SPR0);
		 CLEAR_BIT(SPCR,SPCR_SPR0);
		 CLEAR_BIT(SPSR,SPSR_SPI2X);
		break;
	case SPI_32PRESCALER:
		 CLEAR_BIT(SPCR,SPCR_SPR0);
		 SET_BIT(SPCR,SPCR_SPR0);
		 SET_BIT(SPSR,SPSR_SPI2X);
		break;
	case SPI_64PRESCALER:
		 SET_BIT(SPCR,SPCR_SPR0);
		 SET_BIT(SPCR,SPCR_SPR0);
		 SET_BIT(SPSR,SPSR_SPI2X);
		break;
	case SPI_128PRESCALER:
		 SET_BIT(SPCR,SPCR_SPR0);
		 SET_BIT(SPCR,SPCR_SPR0);
		 CLEAR_BIT(SPSR,SPSR_SPI2X);
		break;
	default:
		break;
	}

	//Setting as a master
	SET_BIT(SPCR,SPCR_MSTR);
#elif SPI_STATE== SPI_SLAVE
	CLEAR_BIT(SPCR,SPCR_MSTR);
#endif

	//setting data order
	SET_BIT(SPCR,SPCR_DORD);
	//setting polarity
	CLEAR_BIT(SPCR,SPCR_CPOL);
	//setting phase
	CLEAR_BIT(SPCR,SPCR_CPHA);
	//Enabling the peripheral
	SET_BIT(SPCR,SPCR_SPE);

	return;
}

void SPI_vidTRANSFERE(u8 COPY_u8SendingData,u8* COPY_u8RecData)
{
	SPDR=COPY_u8SendingData;
	while(SPSR_SPIF==0);
	*COPY_u8RecData=SPDR;

	return;
}

