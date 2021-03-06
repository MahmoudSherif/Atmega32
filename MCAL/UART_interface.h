/*
 * UART_interface.h
 *
 *  Created on: 8 Mar 2019
 *      Author: Laptop Market
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#define CLK 8000000

#define UART_8N1_MODE	0
#define UART_9N1_MODE	1
#define UART_8E1_MODE	2
#define UART_8O1_MODE	3

#define UART_MODE UART_8N1_MODE

#define INTP_ENABLE
#define INTP_DISABLE

#define UART_TX_INTP
#define UART_RX_INTP


#define UART_2400_BAUD_RATE		2400
#define UART_4800_BAUD_RATE		4800
#define UART_9600_BAUD_RATE		9600
#define UART_14400_BAUD_RATE	14400
#define UART_19200_BAUD_RATE	19200
#define UART_28800_BAUD_RATE	28800
#define UART_38400_BAUD_RATE	38400
#define UART_57600_BAUD_RATE	57600
#define UART_76800_BAUD_RATE	76800
#define UART_115200_BAUD_RATE	115200
#define UART_230400_BAUD_RATE	230400
#define UART_250000_BAUD_RATE	250000
#define UART_500000_BAUD_RATE	500000
#define UART_1000000_BAUD_RATE	1000000


#define UART_BAUD_RATE	UART_9600_BAUD_RATE

#define UART_NORMAL_SPEED	2
#define UART_DOUBLE_SPEED	1

#define UART_SPEED	UART_NORMAL_SPEED


#define UART_ASYNCH_MODE	0
#define UART_SYNCH_MODE		1

#define UART_SYNCH_ASYNCH_MODE	UART_ASYNCH_MODE

#define UART_INTP_DISABLE 0
#define UART_INTP_ENABLE  1

#define UART_INTP_MODE   UART_INTP_DISABLE

void UART_Init(void);
void UART_SEND(u8 COPY_u8Data);
void UART_Receive(u8* COPY_u8Data);
void UART_vidBuffer(u8* COPY_u8Arr,u8 COPY_u8Size);
void intToString(int num,char* str,u8 size);



#endif /* UART_INTERFACE_H_ */
