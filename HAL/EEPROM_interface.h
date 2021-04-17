/*
 * SPI_interface.h
 *
 *  Created on: 15 Mar 2019
 *      Author: Laptop Market
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


u32 Power(u8 COPY_u8Num,u8 COPY_u8pow);

void EEPROM_vidWriteByte(u16 ByteAddress ,u8 u8DataToWrite);
void EEPROM_vidReadByte(u16 COPY_u16ByteAddress ,u8* COPY_pu8Data);

#endif /* EEPROM_INTERFACE_H_ */
