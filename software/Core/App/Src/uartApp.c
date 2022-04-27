/*
 * uartApp.c
 *
 *  Created on: Apr 27, 2022
 *      Author: keremcankatirci
 */

#include "uartApp.h"
#include "stdlib.h"
struct uartDataStr uartData;


void uartDataStorage(uint8_t *rxTempBuffer){

	uartData.rxBuffer[uartData.rxIndex] = rxTempBuffer[0];

	if(uartData.rxBuffer[uartData.rxIndex] == '\n'){	/* bir data gelmiş demektir. buffer'da okunması gereken data var. */
		uartData.newDataFlag = 1;
		getUartMessage(&uartData);
	}
	uartData.rxIndex++;

	if(uartData.rxIndex == (rxBufferSize-1))
		uartData.rxIndex = 0;
}

char getUartMessage(struct uartDataStr *uartData){

	if(uartData->newDataFlag == 1){

		uint8_t newDataLineCounter = 0;
		uartData->newDataLine = (char*) calloc(uartData->rxIndex+1, sizeof(char));

		for(uint8_t i = uartData->rxIndexOld; i < uartData->rxIndex; i++){
			uartData->newDataLine[newDataLineCounter++] = (char) uartData->rxBuffer[i];
		}
		uartData->rxIndex = 0;
		uartData->newData = 0;

		free(uartData->newDataLine);
	}

	return *uartData->newDataLine;

}


















