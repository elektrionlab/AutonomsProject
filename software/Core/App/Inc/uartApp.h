/*
 * uartApp.h
 *
 *  Created on: Apr 27, 2022
 *      Author: keremcankatirci
 */

#ifndef APP_INC_UARTAPP_H_
#define APP_INC_UARTAPP_H_

#include "main.h"

#define rxBufferSize	20


struct uartConfig{
	uint32_t BaudRate;
	uint32_t WordLength;
	uint32_t Parity;
	uint32_t StopBits;
};

struct uartDataStr{
	uint8_t	rxBuffer[rxBufferSize];
	uint8_t	rxIndex;
	uint8_t rxIndexOld;
	uint8_t newDataFlag;

	char *newDataLine;		/* gelen verileri ayrıstırma icin kullanılacak degeskenler  */
};


char getUartMessage(struct uartDataStr *uartData);


void uartDataStorage(uint8_t *rxTempBuffer);




#endif /* APP_INC_UARTAPP_H_ */
