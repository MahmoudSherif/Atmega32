/*

 * UART_prog.c
 *
 *  Created on: 8 Mar 2019
 *      Author: Laptop Market
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_UART_REG.h"
#include "UART_interface.h"
#include "AVR_INTP_REG.h"
#include <stdlib.h>
#include <string.h>


#define F_CPU 8000000
#define Null (void*)0
/*
 * Uart init function
 *	input void and output void
 *
 */

volatile static u8 Buffer_Size=0;
volatile static u8* Buffer=Null;

//udre is free
void __vector_14(void) __attribute__((signal,used));
void __vector_15(void) __attribute__((signal,used));

void __vector_15(void)
{
	static u8 size=1;
	if(size<Buffer_Size)
	{
		UDR=Buffer[size];
		size++;
	}else
	{
		size=1;
	}
}


void UART_Init(void)
{

	u8 LOC_u8UCSRC_REG=0;
	UBRRL=51;
	//UBRRL=(unsigned char)(((F_CPU)/(16*BaudRate))-1);
	//Writing to UCSRC
	SET_BIT(LOC_u8UCSRC_REG,UCSRC_URSEL);
	//Asynchronous Mode
	CLEAR_BIT(LOC_u8UCSRC_REG,UCSRC_UMSEL);
	//None Parity Mode
	CLEAR_BIT(LOC_u8UCSRC_REG,UCSRC_UPM1);
	CLEAR_BIT(LOC_u8UCSRC_REG,UCSRC_UPM0);

	//1 stop bit
	CLEAR_BIT(LOC_u8UCSRC_REG,UCSRC_USBS);
	//8 bit mode
	SET_BIT(LOC_u8UCSRC_REG,UCSRC_UCSZ0);
	SET_BIT(LOC_u8UCSRC_REG,UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB,UCSRB_UCSZ2);
	
	
	UCSRC=LOC_u8UCSRC_REG;
	

	//disabling Interrupts
	#if UART_INTP_MODE == UART_INTP_ENABLE
	//SET_BIT(UCSRB,UCSRB_UDRIE);
	SET_BIT(UCSRB,UCSRB_TXCIE);
	SET_BIT(SREG,SREG_GIE);
	#endif
	//Enabling peripheral
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);
	return;
}

/*
 * UART SEND function
 *input DATA and output void
 */
void UART_SEND(u8 COPY_u8Data)
{
	while( ( GET_BIT(UCSRA,UCSRA_UDRE) )==0);
	UDR=COPY_u8Data;
	return;
}

/*
 * UART Receive function
 *input pointer to DATA and output void
 */
void UART_Receive(u8* COPY_u8Data)
{
	while( ( GET_BIT(UCSRA,UCSRA_RXC) )==0);
	(*COPY_u8Data)=UDR;
	return;
}


/*
 * send multi byte
 * 	input u16 arr and size and output void
 *
 */


void UART_vidBuffer(u8* COPY_u8Arr,u8 COPY_u8Size)
{
	for(u8 i=0;i<COPY_u8Size && COPY_u8Arr[i]!='\0' ;i++)
	{
		while( ( GET_BIT(UCSRA,UCSRA_UDRE) )==0);
		UDR=COPY_u8Arr[i];
	}
	return;
}

/*
 * int to string
 * input int num and string str ,size of the string
 * 
 */

void intToString(int num,char* str,u8 size)
{
	int temp=num;
	int count=0;
	while(temp)
	{
		temp/=10;
		count++;
	}
	for(int i=count; i>=0;i--)
	{
		str[i]=num%10 +'0';
		num/=10;
	}
	if(count<=size-1)
	{
		str[count+1]='\0';
	}
	return;
}