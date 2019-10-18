/*
 * MTasks.c
 *
 *  Created on: 18 oct. 2019
 *      Author: pabli
 */

#include "FreeRTOS.h"
#include "DebugIO.h"
#include "MTasks.h"


void vEncenderApagarHeater(void* pvParameters){
	(void)pvParameters;
	portCHAR msgEnc[] = "Encender Heater\n";
	portCHAR msgApg[] = "Apagar Heater\n";
	uint64_t i;

	for(;;){
		vPrintString(msgEnc);
		for(i=0;i<100000000;i++);
		vPrintString(msgApg);
		for(i=0;i<100000000;i++);
	}

}


