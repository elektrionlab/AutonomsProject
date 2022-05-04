/*
 * task2.c
 *
 *  Created on: Apr 28, 2022
 *      Author: keremcankatirci
 */

#include "task2.h"
#include "system.h"
#include "gpio.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

extern struct System controlSystem;
extern struct uartDataStr uartData;

char *parsedData[3];
int ledTime;

void task2(){
	static int task2Timer = 0;
	task2Timer++;
	if(task2Timer == TASK2_TIME_MS){
		getUartMessage(&uartData);
		dataParser();
		echoTask();
		task2Timer = 0;
	}
}

void echoTask(){
	if(controlSystem.echoType == 1){
		echoMessage(&uartData);
	}
}

void dataParser(){
	// dataların parse edilmesi ve ilgili ayarların yapılması
	if(!strcmp(controlSystem.uartMessageData, "stop\r\n\0") && controlSystem.systemState == 1){
		controlSystem.echoType = 0;
		controlSystem.systemState = 0;

		controlSystem.ledOldOnTime = controlSystem.ledOnTime;
		controlSystem.ledOldOffTime = controlSystem.ledOffTime;

		controlSystem.ledOnTime = LED_STOP_MODE_ON_TIME_MS;
		controlSystem.ledOffTime = LED_STOP_MODE_OFF_TIME_MS;
	}
	else if(!strcmp(controlSystem.uartMessageData, "start\r\n\0") || controlSystem.systemState == 1){
		if(controlSystem.systemState == 0){
			controlSystem.ledOnTime = controlSystem.ledOldOnTime;
			controlSystem.ledOffTime = controlSystem.ledOldOffTime;
		}
		controlSystem.echoType = 1;
		controlSystem.systemState = 1;

		char uartMessageTempData[strlen(controlSystem.uartMessageData)];

		strcpy(uartMessageTempData, controlSystem.uartMessageData);

		int i = 0;
		char *p = strtok(uartMessageTempData, "=");

		while(p != NULL){
			parsedData[i++] = p;
			p = strtok(NULL, "=");
		}

		if(!strcmp(parsedData[0], "ledon")){
			controlSystem.ledOnTime =  atoi(parsedData[1]);
		}
		else if(!strcmp(parsedData[0], "ledoff")){
			controlSystem.ledOffTime = atoi(parsedData[1]);
		}
	}
	else {
		// TODO:
	}
}
