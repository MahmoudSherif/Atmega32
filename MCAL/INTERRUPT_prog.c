/*
 * INTERRUPT_prog.c
 *
 *  Created on: 2 Feb 2019
 *      Author: Mahmoud Sherif
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"
#include "AVR_INTP_REG.h"
#include "INTERRUPT_interface.h"

static void (*Intp0Func)(void);
static void (*Intp1Func)(void);
static void (*Intp2Func)(void);

#if INTP0_STATE==INTP_ENABLE

/* ISR of INT0 + Telling compiler not to remove it at linking time as it is not called by SW */
void __vector_1(void) __attribute__((signal,used));

void __vector_1(void)
{
	Intp0Func();
}

#endif

#if INTP1_STATE==INTP_ENABLE

/* ISR of INT1 + Telling compiler not to remove it at linking time as it is not called by SW */
void __vector_2(void) __attribute__((signal,used));

void __vector_2(void)
{
	Intp1Func();
}

#endif


#if INTP2_STATE==INTP_ENABLE

/* ISR of INT1 + Telling compiler not to remove it at linking time as it is not called by SW */
void __vector_3(void) __attribute__((signal,used));

void __vector_3(void)
{
	Intp2Func();
}

#endif

void INTP_vidInit()
{
	//Initializing interrupt 0
	#if INTP0_STATE==INTP_ENABLE
	//enabling the interrupt
	SET_BIT(GICR,GICR_INT0);
	//the event type
	switch(INTP0_EVENT_TYPE)
	{
		case INTP_FALLING_EGDE:
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case INTP_RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case INTP_ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		break;
		case INTP_LOW_LEVEL:
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		break;
	}

	#endif

	#if INTP1_STATE==INTP_ENABLE
		//enabling the interrupt
	SET_BIT(GICR,GICR_INT1);
	//the event type
	switch(INTP1_EVENT_TYPE)
		{
			case INTP_FALLING_EGDE:
			CLEAR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
			case INTP_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
			case INTP_ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLEAR_BIT(MCUCR,MCUCR_ISC11);
			break;
			case INTP_LOW_LEVEL:
			CLEAR_BIT(MCUCR,MCUCR_ISC10);
			CLEAR_BIT(MCUCR,MCUCR_ISC11);
			break;
		}
	#endif

	#if	INTP2_STATE==INTP_ENABLE

	SET_BIT(GICR,GICR_INT2);
	switch(INTP2_EVENT_TYPE)
	{
		case INTP_FALLING_EGDE:
		CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
		case INTP_RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_ISC2);

	}

	#endif

	SET_BIT(SREG,SREG_GIE);  // it's better to be the last one to be configured to avoid miss behavior (maybe flag was one before for any reason )

}
//INTP0
void INTP_vidIntp0Enable()
{
	SET_BIT(GICR,GICR_INT0);
	return;
}
void INTP_vidIntp0Disable()
{
	CLEAR_BIT(GICR,GICR_INT0);
	return;
}

//INTP1
void INTP_vidIntp1Enable()
{
	SET_BIT(GICR,GICR_INT1);
	return;
}
void INTP_vidIntp1Disable()
{
	CLEAR_BIT(GICR,GICR_INT1);
	return;
}
//INTP2
void INTP_vidIntp2Enable()
{
	SET_BIT(GICR,GICR_INT2);
	return;
}

void INTP_vidIntp2Disable()
{
	CLEAR_BIT(GICR,GICR_INT2);
	return;
}

void INTP_vidIntp0EventType(u8 COPY_u8Event)
{
	//the event type
	switch(COPY_u8Event)
	{
		case INTP_FALLING_EGDE:
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case INTP_RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case INTP_ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		break;
		case INTP_LOW_LEVEL:
		CLEAR_BIT(MCUCR,MCUCR_ISC00);
		CLEAR_BIT(MCUCR,MCUCR_ISC01);
		break;
	}
	return;
}


//Interrupt 1 event type

void INTP_vidIntp1EventType(u8 COPY_u8EventType)
{
	//the event type
	switch(COPY_u8EventType)
		{
			case INTP_FALLING_EGDE:
			CLEAR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
			case INTP_RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
			case INTP_ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLEAR_BIT(MCUCR,MCUCR_ISC11);
			break;
			case INTP_LOW_LEVEL:
			CLEAR_BIT(MCUCR,MCUCR_ISC10);
			CLEAR_BIT(MCUCR,MCUCR_ISC11);
			break;
		}
	return;
}

// Interrupt 2 Event type

void INTP_vidIntp2EventType(u8 COPY_u8EventType)
{
	switch(COPY_u8EventType)
	{
		case INTP_FALLING_EGDE:
		CLEAR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
		case INTP_RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_ISC2);

	}
	return;
}

//Enable Global Interrupt

void INTP_vidEnableGlobalInterrupt()
{
	SET_BIT(SREG,SREG_GIE);
}

//Disable Global Interrupt

void INTP_vidDisbleGlobalInterrupt()
{
	CLEAR_BIT(SREG,SREG_GIE);
}

//setter function for intp0
void INTP_vidSetINTP0_func( void(*ptrFunc)() )
{
	Intp0Func=ptrFunc;
}

//setter function for intp1
void INTP_vidSetINTP1_func( void(*ptrFunc)() )
{
	Intp1Func=ptrFunc;
}

//setter function for intp2
void INTP_vidSetINTP2_func( void(*ptrFunc)() )
{
	Intp2Func=ptrFunc;
}