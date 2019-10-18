/*
 * MTasks.c
 *
 *  Created on: 18 oct. 2019
 *      Author: pabli
 */

#include "FreeRTOS.h"
#include "Task.h"
#include "DebugIO.h"
#include "MTasks.h"


void vEncenderApagarHeater(void* pvParameters){
	(void)pvParameters;
	portCHAR msgEnc[50] = "Encender ";
	portCHAR msgApg[50] = "Apagar ";
	//uint64_t i;

	strcat(msgEnc, pvParameters);
	strcat(msgEnc, "\n");
	strcat(msgApg, pvParameters);
	strcat(msgApg, "\n");
	for(;;){
		vPrintString(msgEnc);
		vTaskDelay(pdMS_TO_TICKS(500));
		vPrintString(msgApg);
		vTaskDelay(pdMS_TO_TICKS(500));
	}

}


