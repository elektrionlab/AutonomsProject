/*
 * uartApp.c
 *
 *  Created on: Apr 27, 2022
 *      Author: keremcankatirci
 */

#include "uartApp.h"

struct uartConfig{
	uint32_t BaudRate;
	uint32_t WordLength;
	uint32_t Parity;
	uint32_t StopBits;
}uartConfig;

struct uartDataStr{
	uint8_t	rxBuffer[rxBufferSize];
	uint8_t	rxIndex;
	uint8_t newDataFlag;
}uartData;


void uartDataStorage(uint8_t *rxTempBuffer){

	uartData.rxBuffer[uartData.rxIndex] = rxTempBuffer[0];

	if(uartData.rxBuffer[uartData.rxIndex] == '\n'){	/* bir data gelmiş demektir. buffer'da okunması gereken data var. */
		uartData.newDataFlag = 1;
	}
	uartData.rxIndex++; /* ring buffer gibi */

	if(uartData.rxIndex == (rxBufferSize-1))
		uartData.rxIndex = 0;
}

