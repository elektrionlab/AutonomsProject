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

void uartTransmitData(uint8_t *data, uint16_t size){
	HAL_UART_Transmit(&huart2, data, size, 100);
}




