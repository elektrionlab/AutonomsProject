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

	getUartMessage(&uartData);
	dataParser();
	echoTask();

}

void echoTask(){
	if(controlSystem.echoType == 1){
		echoMessage(&uartData);
	}
}

void dataParser(){
	// dataların parse edilmesi ve ilgili ayarların yapılması
	if(!strcmp(controlSystem.uartMessageData, "stop\r\n\0")){
		controlSystem.echoType = 0;
		controlSystem.systemState = 0;
	}
	else if(!strcmp(controlSystem.uartMessageData, "start\r\n\0") || controlSystem.systemState == 1){
		controlSystem.echoType = 1;
		controlSystem.systemState = 1;

		int i = 0;
		char *p = strtok(controlSystem.uartMessageData, "=");

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
	else{
		// TODO:
	}
}
