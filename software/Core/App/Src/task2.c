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

extern struct System controlSystem;

void task2(){ // dataların parse edilmesi ve ilgili ayarların yapılması

	if(!strcmp(controlSystem.uartMessageData, "stop\r\n\0")){



		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
	}

	else
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

}


