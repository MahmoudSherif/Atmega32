/*
 * AVR_DIO_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Laptop Market
 */

#ifndef AVR_DIO_REG_H_
#define AVR_DIO_REG_H_

//A group

#define PORTA (*(volatile u8*)(0x3B))     //OUTPUT FOR A group
#define DDRA (*(volatile u8*)(0x3A))		 //Configuration for A group
#define PINA (*(volatile u8*)(0x39))		 //INPUT FOR A group

//B group

#define PORTB (*(volatile u8*)(0x38))		//OUTPUT FOR B group
#define DDRB (*(volatile u8*)(0x37))			//Configuration for B group
#define PINB (*(volatile u8*)(0x36))			//INPUT FOR B group

//C group

#define PORTC (*(volatile u8*)(0x35))		//OUTPUT FOR C group
#define DDRC (*(volatile u8*)(0x34))			//Configuration for C group
#define PINC (*(volatile u8*)(0x33))			//INPUT FOR C group

//D group

#define PORTD (*(volatile u8*)(0x32))		//OUTPUT FOR D group
#define DDRD (*(volatile u8*)(0x31))			//Configuration for D group
#define PIND (*(volatile u8*)(0x30))			//INPUT FOR D group


#endif /* AVR_DIO_REG_H_ */
