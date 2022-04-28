/*
 * system.c
 *
 *  Created on: Apr 28, 2022
 *      Author: keremcankatirci
 */


#include "system.h"

struct System controlSystem;

void UserSystemInit(void){
	controlSystem.ledOnTime = 300;
	controlSystem.ledOffTime = 700;
	controlSystem.echoType = 1;	// echo yapıyor


}
