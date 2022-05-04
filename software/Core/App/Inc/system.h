/*
 * system.h
 *
 *  Created on: Apr 28, 2022
 *      Author: keremcankatirci
 */

#ifndef APP_INC_SYSTEM_H_
#define APP_INC_SYSTEM_H_

#include "main.h"


#include "task1.h"
#include "task2.h"

#define TASK1_TIME_MS 10
#define TASK2_TIME_MS 10

#define LED_STOP_MODE_ON_TIME_MS	1000
#define	LED_STOP_MODE_OFF_TIME_MS	1000



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

	uint32_t newLedTime;
	uint32_t oldLedTime;
	uint8_t ledState;
};

void UserSystemInit(void);
#endif /* APP_INC_SYSTEM_H_ */
