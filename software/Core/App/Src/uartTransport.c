/*
 * uartTransport.c
 *
 *  Created on: Apr 27, 2022
 *      Author: keremcankatirci
 */

#include "uartTransport.h"

uint8_t rxTempBuffer[5];

void uartReceiveIT(){
	HAL_UART_Receive_IT(&huart2, rxTempBuffer, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	if(huart == &huart2){
		uartDataStorage(rxTempBuffer);
		uartReceiveIT();
	}

}





