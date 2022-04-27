/*
 * uartTransport.h
 *
 *  Created on: Apr 27, 2022
 *      Author: keremcankatirci
 */

#ifndef APP_INC_UARTTRANSPORT_H_
#define APP_INC_UARTTRANSPORT_H_

#include "main.h"
#include "usart.h"
#include "uartApp.h"


#define uartHandleTypeDef	huart2

extern UART_HandleTypeDef uartHandleTypeDef;

void uartTransmitData(uint8_t *data, uint16_t size);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void uartReceiveIT();


#endif /* APP_INC_UARTTRANSPORT_H_ */
