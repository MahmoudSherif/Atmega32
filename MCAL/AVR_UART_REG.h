/*
 * AVR_UART_REG.h
 *
 *  Created on: 8 Mar 2019
 *      Author: Laptop Market
 */

#ifndef AVR_UART_REG_H_
#define AVR_UART_REG_H_


#define UDR *((volatile u8*)(0x2C))
#define UCSRA *((volatile u8*)(0x2B))
#define UCSRB *((volatile u8*)(0x2A))

#define UBRRL *((volatile u8*)(0x29))

#define UBRRH *((volatile u8*)(0x40))
#define UCSRC *((volatile u8*)(0x40))




//for Register UCSRA
//RXC TXC UDRE FE DOR PE U2X MPCM

#define UCSRA_MPCM (u8)0		//Multi-processor Communication Mode
#define UCSRA_U2X (u8)1			//Double the USART Transmission Speed
#define UCSRA_PE (u8)2			//Parity Error
#define UCSRA_DOR (u8)3		    //Data OverRun
#define UCSRA_FE (u8)4			//Frame Error
#define UCSRA_UDRE (u8)5		//USART Data Register Empty
#define UCSRA_TXC (u8)6			//USART Transmit Complete
#define UCSRA_RXC (u8)7			//USART Receive Complete


//for Register UCSRB
//RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8

#define UCSRB_TXB8 (u8)0			//Transmit Data Bit 8
#define UCSRB_RXB8 (u8)1			//Receive Data Bit 8
#define UCSRB_UCSZ2 (u8)2			//Character Size
#define UCSRB_TXEN (u8)3		    //Transmitter Enable
#define UCSRB_RXEN (u8)4			//Receiver Enable
#define UCSRB_UDRIE (u8)5			//USART Data Register Empty Interrupt Enable
#define UCSRB_TXCIE (u8)6			//TX Complete Interrupt Enable
#define UCSRB_RXCIE (u8)7			//RX Complete Interrupt Enable


//for Register UCSRC
//URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL

#define UCSRC_UCPOL (u8)0			//Clock Polarity
#define UCSRC_UCSZ0 (u8)1			//Character Size
#define UCSRC_UCSZ1 (u8)2			//Character Size
#define UCSRC_USBS (u8)3		    //Stop Bit Select
#define UCSRC_UPM0 (u8)4			//Parity Mode
#define UCSRC_UPM1 (u8)5			//
#define UCSRC_UMSEL (u8)6			//USART Mode Select
#define UCSRC_URSEL (u8)7			//Register Select


#endif /* AVR_UART_REG_H_ */
