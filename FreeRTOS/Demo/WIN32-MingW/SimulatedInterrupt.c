/*
 * SimulatedInterrupt.c
 *
 *  Created on: 21 oct. 2019
 *      Author: pabli
 */

#include "FreeRTOS.h"
#include "task.h"
#include "DebugIO.h"
#include "SimulatedInterrupt.h"


void vSimulaterTemperatureInterruptTask(void* pvParameters){
	(void)pvParameters;
	//uint8_t temperature = rand()%256;
	unsigned long ms = (rand()%25000)+5000;
	const TickType_t xDelayMs = pdMS_TO_TICKS( ms );
	for( ;; ){
		vTaskDelay( xDelayMs );
		vPrintString( "Interrupcion artificialmente generada.\r\n" );
		vPortGenerateSimulatedInterrupt( NEW_TEMP_INTERRUPT );
	}
}

