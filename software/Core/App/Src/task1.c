/*
 * task1.c
 *
 *  Created on: Apr 29, 2022
 *      Author: keremcankatirci
 */


#include "task1.h"
#include "gpio.h"
#include "system.h"

extern struct System controlSystem;

void task1(uint32_t *timer){
	static int task1Timer = 0;
	task1Timer++;
	if(task1Timer == TASK1_TIME_MS){
		ledControl(&(*timer));
		task1Timer = 0;
	}
}


void ledControl(uint32_t *timer){

	controlSystem.newLedTime = *timer;

		if(controlSystem.ledState == 1){
			if((controlSystem.newLedTime - controlSystem.oldLedTime) >= controlSystem.ledOnTime){
				controlSystem.ledState = 0;
				HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
			}

		}
		else
		{
			if((controlSystem.newLedTime - controlSystem.oldLedTime) >= (controlSystem.ledOffTime + controlSystem.ledOnTime)){
				controlSystem.ledState = 1;
				controlSystem.oldLedTime = controlSystem.newLedTime;
				HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
			}
		}

}
