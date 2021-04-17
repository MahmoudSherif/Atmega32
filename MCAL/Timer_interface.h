/*
 * Timer_interface.h
 *
 *  Created on: 4 Mar 2019
 *      Author: Laptop Market
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

//Timers Enable/disable Macros

#define TIMER_DISABLE  0
#define TIMER_ENABLE  1

#define TIMER_TIMER0_STATE	TIMER_ENABLE
#define TIMER_TIMER1_STATE	TIMER_DISABLE
#define TIMER_TIMER2_STATE	TIMER_DISABLE

//Timer Interrupts Macros

#define TIMER_TIMER0_CTC_INTP	TIMER_ENABLE
#define TIMER_TIMER0_OVF_INTP	TIMER_DISABLE
#define TIMER_TIMER1_CTCA_INTP	TIMER_DISABLE
#define TIMER_TIMER1_CTCB_INTP	TIMER_DISABLE
#define TIMER_TIMER1_OVF_INTP	TIMER_DISABLE
#define TIMER_TIMER2_CTC_INTP	TIMER_DISABLE
#define TIMER_TIMER2_OVF_INTP	TIMER_DISABLE


//Output Compare Hardware pin Enable/Disable

#define TIMER_OC0	TIMER_DISABLE
#define TIMER_OC1A	TIMER_DISABLE
#define TIMER_OC1B	TIMER_DISABLE
#define TIMER_OC2	TIMER_DISABLE

//Output Compare Event Type

//OC0,Normal Mode
#define TIMER_OC0_CLEAR		0
#define TIMER_OC0_SET		1
#define TIMER_OC0_TOGGLE	2
#define TIMER_OC0_DISCONNECTED	3

//OC0,Fast PWM,Phase Correct PWM
#define TIMER_OC0_INVERTED	4
#define TIMER_OC0_NON_INVERTED	5

#define TIMER_OC0_EVENT_TYPE	TIMER_OC0_TOGGLE


//OC2,Normal Mode
#define TIMER_OC2_CLEAR		0
#define TIMER_OC2_SET		1
#define TIMER_OC2_TOGGLE	2
#define TIMER_OC2_DISCONNECTED	3

//OC0,Fast PWM,Phase Correct PWM
#define TIMER_OC2_INVERTED	4
#define TIMER_OC2_NON_INVERTED	5

//OC1

#define TIMER_TIMER1_NORMAL					0
#define TIMER_TIMER1_PHASE_CORRECT_8BIT		1
#define TIMER_TIMER1_PHASE_CORRECT_9BIT		2
#define TIMER_TIMER1_PHASE_CORRECT_10BIT	3
#define TIMER_TIMER1_CTC_OCR1A				4
#define TIMER_TIMER1_FAST_PWM_8BIT			5
#define TIMER_TIMER1_FAST_PWM_9BIT			6
#define TIMER_TIMER1_FAST_PWM_10BIT			7
#define TIMER_TIMER1_PHASE_FREQ_ICR1		8
#define TIMER_TIMER1_PHASE_FREQ_OCR1A		9
#define TIMER_TIMER1_PHASE_CORRECT_ICR1		10
#define TIMER_TIMER1_PHASE_CORRECT_OCR1A	11
#define TIMER_TIMER1_CTC_ICR1				12
//reserved
#define TIMER_TIMER1_FAST_PWM_ICR1			14
#define TIMER_TIMER1_FAST_PWM_OCR1A			15

#define TIMER_OC1_CLEAR		16
#define TIMER_OC1_SET		17
#define TIMER_OC1_TOGGLE	18
#define TIMER_OC1_DISCONNECTED	19

//Prescaler

#define TIMER_PRESCALER_STOPPED			 0
#define TIMER_PRESCALER1 				 1
#define TIMER_PRESCALER8				 2
#define TIMER_PRESCALER64				 3
#define TIMER_PRESCALER256 				 4
#define TIMER_PRESCALER1024				 5
#define TIMER_PRESCALER_COUNTER_FALLING  6
#define TIMER_PRESCALER_COUNTER_RISING   7


#define TIMER_TIMER0_PRESCALER		TIMER_PRESCALER_COUNTER_FALLING
#define TIMER_TIMER1_PRESCALER		TIMER_PRESCALER256
#define TIMER_TIMER2_PRESCALER		TIMER_PRESCALER256


//Choose Mode For TIMER0 And TIMER2

#define TIMER_NORMAL				0
#define TIMER_PHASE_CORRECT_PWM		1
#define TIMER_CTC					2
#define TIMER_FAST_PWM				3

#define TIMER_TIMER0_MODE	TIMER_CTC
#define TIMER_TIMER2_MODE	TIMER_NORMAL

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

#define TIMER_MODE 	 0
#define COUNTER_MODE 1

#define TIMER_COUNTER TIMER_MODE

#define COUNTER_FALLING_EDGE 0
#define COUNTER_RISING_EDGE 0

#define COUNTER_EDGE 	COUNTER_FALLING_EDGE



void __vector_4(void);		//TIMER2 COMP Timer/Counter2 Compare Match
void __vector_5(void);		//TIMER2 OVF Timer/Counter2 Overflow
void __vector_6(void);		//TIMER1 CAPT Timer/Counter1 Capture Event
void __vector_7(void);		//TIMER1 COMPA Timer/Counter1 Compare Match A
void __vector_8(void);		//TIMER1 COMPB Timer/Counter1 Compare Match B
void __vector_9(void);		//TIMER1 OVF Timer/Counter1 Overflow
void __vector_10(void);		//TIMER0 COMP Timer/Counter0 Compare Match
//void __vector_11(void);		//TIMER0 OVF Timer/Counter0 Overflow



void __vector_11(void) __attribute__((signal,used));	//TIMER0 OVF Timer/Counter0 Overflow




void Set_CTCMode(void);
void Set_NormalMode(void);

void TIMER_vidInit(void);
void TIMER0_CTC_vidSetCallBack(void (*COPY_pvidCallBack)(void ));


void TIMER0_OVF_vidSetCallBack( void (*COPY_pvidCallBack)(void ) );
u16 GetPrescaler(u8 COPY_u8TimerNo);
void TimerOVF(u16 DesiredTime,u8 COPY_u8Type,u8 COPY_u8TimerNo, u16* COPY_u16Overflows,u8* COPY_u8Preload);
void TIMER_SetDesiredTime(u16 COPY_u8DesiredTime,u8 COPY_u8TimerNum,u8 COPY_u8Type);
void TIMER_vidInit(void);

#endif /* TIMER_INTERFACE_H_ */
