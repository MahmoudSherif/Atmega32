/*
 * AVR_TIMER_REG.h
 *
 *  Created on: 4 Mar 2019
 *      Author: Laptop Market
 */

#ifndef AVR_TIMER_REG_H_
#define AVR_TIMER_REG_H_

#define TIMSK (*(volatile u8*)(0x59))
#define TIFR (*(volatile u8*)(0x58))

#define TCCR0 (*(volatile u8*)(0x53))

#define TCNT0 (*(volatile u8*)(0x52))

#define OCR0 (*(volatile u8*)(0x5C))

#define TCCR1A (*(volatile u8*)(0x4F))

#define TCCR1B (*(volatile u8*)(0x4E))

#define TCNT1 (*(volatile u16*)(0x4C))

#define OCR1A (*(volatile u16*)(0x4A))

#define OCR1B (*(volatile u16*)(0x48))

#define ICR1 (*(volatile u16*)(0x46))

//Timer2
// TCCR2 FOC2 WGM20 COM21 COM20 WGM21 CS22 CS21 CS20
#define TCCR2 (*(volatile u16*)(0x45))

#define TCCR2_CS20 (u8)0	//Clock Source or Prescaler
#define TCCR2_CS21 (u8)1
#define TCCR2_CS22 (u8)2
#define TCCR2_WGM21 (u8)3	//	Wavegeneration Mode
#define TCCR2_COM20 (u8)4	//CTC Mode
#define TCCR2_COM21 (u8)5
#define TCCR2_WGM20 (u8)6
#define TCCR2_FOC2 (u8)7	//Force Compare

#define TCNT2 (*(volatile u8*)(0x44))

//for register TCCR1A

#define TCCR1A_WGM10 (u8)0			//Waveform Generation Mode
#define TCCR1A_WGM11 (u8)1
#define TCCR1A_FOC1B (u8)2			//Force Output Compare for Channel B
#define TCCR1A_FOC1A (u8)3			//Force Output Compare for Channel A
#define TCCR1A_COM1B0 (u8)4			//Compare Output Mode for Channel B
#define TCCR1A_COM1B1 (u8)5
#define TCCR1A_COM1A0 (u8)6			//Compare Output Mode for Channel A
#define TCCR1A_COM1A1 (u8)7

// TCCR1B ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10
#define TCCR1B_CS10 (u8)0		//Clock Select
#define TCCR1B_CS11 (u8)1
#define TCCR1B_CS12 (u8)2
#define TCCR1B_WGM12 (u8)3		//Waveform Generation Mode
#define TCCR1B_WGM13 (u8)4
#define TCCR1B_ICES1 (u8)6		//Input Capture Edge Select
#define TCCR1B_ICNC1 (u8)7		//Input Capture Noise Canceler


// TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0

#define TIMSK_TOIE0 (u8)0		//Timer0 Interrupt Enable
#define TIMSK_OCIE0 (u8)1		//Output Compare Interrupt Enable for timer0
#define TIMSK_TOIE1 (u8)2		//Timer/Counter1, Overflow Interrupt Enable
#define TIMSK_OCIE1B (u8)3		//Timer/Counter1, Output Compare B Match Interrupt Enable
#define TIMSK_OCIE1A (u8)4		//Timer/Counter1, Output Compare A Match Interrupt Enable
#define TIMSK_TICIE1 (u8)5		//Timer/Counter1, Input Capture Interrupt Enable
#define TIMSK_TOIE2 (u8)6		//Timer2 Interrupt Enable
#define TIMSK_OCIE2 (u8)7		//Output Compare Interrupt Enable for timer2

//for register TCCR0
#define TCCR0_CS00 (u8)0		//Clock Select
#define TCCR0_CS01 (u8)1
#define TCCR0_CS02 (u8)2
#define TCCR0_WGM01 (u8)3		//Timer0 Waveform Generation mode select
#define TCCR0_COM00 (u8)4		//Compare Match Output Mode
#define TCCR0_COM01 (u8)5
#define TCCR0_WGM00 (u8)6		//Waveform Generation Mode select for timer0
#define TCCR0_FOC0 (u8)7		//Force Output Compare


//OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0
//for register TIFR

#define TIFR_TOV0 (u8)0			//Output Compare Flag 0
#define TIFR_OCF0 (u8)1			//Timer/Counter0 Overflow Flag
#define TIFR_TOV1 (u8)2			//Timer/Counter1, Overflow Flag
#define TIFR_OCF1B (u8)3		//Timer/Counter1, Output Compare B Match Flag
#define TIFR_OCF1A (u8)4		//Timer/Counter1, Output Compare A Match Flag
#define TIFR_ICF1 (u8)5			//Timer/Counter1, Input Capture Flag
#define TIFR_TOV2 (u8)6			//Timer/Counter2 Overflow flag
#define TIFR_OCF2 (u8)7			//Output Compare Flag 2

//for register SFIOR
#define SFIOR_PSR10 (u8)0		//Prescaler Reset Timer/Counter1 and Timer/Counter0
#define SFIOR_PSR2 (u8)1		//Prescaler Reset Timer/Counter2




#endif /* AVR_TIMER_REG_H_ */
