/*
 * Timer_prog.c
 *
 *  Created on: 4 Mar 2019
 *      Author: Laptop Market
 */

#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"
#include "AVR_INTP_REG.h"
#include "AVR_TIMER_REG.h"
#include "Timer_interface.h"

#define Null (void*)0


//Pointers used in Set call back functions
static void(*pvidCallBackPtr_Timer0CTC)(void);


//Interrupts Vectors

void __vector_10(void) __attribute__((signal,used));	//TIMER0 COMP Timer/Counter0 Compare Match



//Set CallBack Functions

/*
 * Timer0 Compare Match Function  Set Call back
 * the function paratmeter is a pointer to another function
 *	Output:void
 */


void TIMER0_CTC_vidSetCallBack( void (*COPY_pvidCallBack)(void ) )
{
	//check if ptr is Null so don't set it so as not to ruin the application that was working
	pvidCallBackPtr_Timer0CTC=COPY_pvidCallBack;
}

//TIMER0 COMP Timer/Counter0 Compare Match
void __vector_10(void)
{
	//don't accept Null as it is the reset funtion
	//pvidCallBackPtr_Timer0CTC();
	DIO_u8SetPinValue(DIO_enuPORTD,DIO_enuPIN3,DIO_enuHigh);
	DIO_u8SetPinValue(DIO_enuPORTB,DIO_enuPIN1,DIO_enuLow);
	//TCNT0=1;
}

/*
 *	Init Function for Timers
 *
 *
 */
void TIMER_vidInit(void)
{
	TCCR0=TIMER_TIMER0_PRESCALER;
	CLEAR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	SET_BIT(TIMSK,TIMSK_OCIE0);
	return;
}



