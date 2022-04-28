/*
 * uartApp.c
 *
 *  Created on: Apr 27, 2022
 *      Author: keremcankatirci
 */

#include "uartApp.h"
#include "uartTransport.h"
#include "stdlib.h"
#include "string.h"
#include "system.h"

struct uartDataStr uartData;
extern struct System controlSystem;

void uartDataStorage(uint8_t *rxTempBuffer){

	uartData.rxBuffer[uartData.rxIndex] = rxTempBuffer[0];

	if(uartData.rxBuffer[uartData.rxIndex] == '\n'){	/* bir data gelmiş demektir. buffer'da okunması gereken data var. */
		uartData.newDataFlag = 1;
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

		/*if(controlSystem.echoType == 1)
			echoMessage(uartData);*/

		uartData->rxIndex = 0;
		uartData->newDataFlag = 0;
		uartData->echoFlag = 1;

		controlSystem.uartMessageData = uartData->newDataLine;

		free(uartData->newDataLine);

	}

	return *uartData->newDataLine;

}

void echoMessage(struct uartDataStr *uartData){
	if(uartData->echoFlag == 1){
		uartTransmitData((uint8_t*)uartData->newDataLine, strlen(uartData->newDataLine));
		uartData->echoFlag = 0;
	}
}















