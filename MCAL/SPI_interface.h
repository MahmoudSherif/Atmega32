/*
 * SPI_interface.h
 *
 *  Created on: 15 Mar 2019
 *      Author: Laptop Market
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#define SPI_SLAVE 0
#define SPI_MASTER 1

#define SPI_STATE SPI_SLAVE

#define SPI_ENABLE
#define SPI_DISABLE

#define SPI_INTP  SPI_ENABLE

#define SPI SPI_ENABLE

#define SPI_2PRESCALER	0
#define SPI_4PRESCALER	1
#define SPI_8PRESCALER	2
#define SPI_16PRESCALER	3
#define SPI_32PRESCALER	4
#define SPI_64PRESCALER	5
#define SPI_128PRESCALER	6

#define SPI_PRESCALER  SPI_128PRESCALER


void SPI_vidInit(void);
void SPI_vidTRANSFERE(u8 COPY_u8SendingData,u8* COPY_u8RecData);
#endif /* SPI_INTERFACE_H_ */
