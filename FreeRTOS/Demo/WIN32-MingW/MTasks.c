/*
 * MTasks.c
 *
 *  Created on: 18 oct. 2019
 *      Author: pabli
 */

#include "FreeRTOS.h"
#include "Task.h"
#include "queue.h"
#include "DebugIO.h"
#include "MTasks.h"

#include "Globals.h"





void vEncenderApagarHeater(void* pvParameters){
	(void)pvParameters;
	portCHAR msgEnc[50] = "Encender ";
	portCHAR msgApg[50] = "Apagar ";
	//uint64_t i;
	BaseType_t qr;

	float temperature;
	strcat(msgEnc, pvParameters);
	strcat(msgEnc, "\n");
	strcat(msgApg, pvParameters);
	strcat(msgApg, "\n");
	for(;;){
		qr = xQueueReceive(xPrQueue,  &temperature, pdMS_TO_TICKS(10000));

		if (qr==errQUEUE_EMPTY){
			vPrintString("Vencio plazo de espera de temperatura encolada\n");
		}else{
			if(temperature<0.0){
				vPrintString("Encender heater\n");
			}else if(temperature>21.0){
				vPrintString("Apagar heater\n");
			}else{
				vPrintString("Temperatura en valores medios\n");
			}

		}



	}

}

void vNewTemperature(void* pvParameters){
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

uint32_t ulTempInterruptHandler( void ) {
	vPrintString( "Interrupcion Trepeada!.\r\n" );
	float rant = rand()%75-25.0;
	BaseType_t xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;

	xQueueSendToBackFromISR(xPrQueue, &rant, &xHigherPriorityTaskWoken);


	portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
	return 1;
}



