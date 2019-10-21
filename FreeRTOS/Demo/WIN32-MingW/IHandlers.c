/*
 * IHandlers.c
 *
 *  Created on: 21 oct. 2019
 *      Author: pabli
 */

#include "FreeRTOS.h"
#include "IHandlers.h"
#include "SimulatedInterrupt.h"
#include "DebugIO.h"
#include "Globals.h"
#include "queue.h"
uint32_t ulTempInteHandler(void){
	//Tratamiento de interrupcion
	float temp;
	vPrintString("Interrupcion de temperatura manejada\n");


	temp = (rand()%75)-25.0;
	xQueueSendToBackFromISR(xPrQueue, &temp, NULL);


	return NEW_TEMP_INTERRUPT;

}



