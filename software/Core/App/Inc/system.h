/*
 * system.h
 *
 *  Created on: Apr 28, 2022
 *      Author: keremcankatirci
 */

#ifndef APP_INC_SYSTEM_H_
#define APP_INC_SYSTEM_H_

#include "main.h"

struct System{
	char *uartMessageData;
	uint32_t ledOnTime;
	uint32_t ledOffTime;
	uint32_t ledOldOnTime;
	uint32_t ledOldOffTime;
	uint8_t	echoType;
	uint8_t systemState;

	uint32_t BaudRate;
	uint32_t WordLength;
	uint32_t Parity;
	uint32_t StopBits;
};

void UserSystemInit(void);
#endif /* APP_INC_SYSTEM_H_ */
