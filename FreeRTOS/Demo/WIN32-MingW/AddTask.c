/*
 * AddTask.c
 *
 *  Created on: 12 jul. 2019
 *      Author: demo
 */
#include "windows.h"

#include "AddTask.h"
#include "Globals.h"
#include "task.h"
#include <stdio.h>
#include <conio.h>
#include "queue.h"
#include "semphr.h"




void vNewTelemetryInterrupt(void* pvParameters){
	(void)pvParameters;
	//uint8_t temperature = rand()%256;
	unsigned long ms = (rand()%25000)+5000;
	const TickType_t xDelayMs = pdMS_TO_TICKS( ms );

	for( ;; ){
		vTaskDelay( xDelayMs );
		vPrintString( "Interrupcion artificialmente generada.\r\n" );
		vPortGenerateSimulatedInterrupt( mainINTERRUPT_NUMBER );

	}
}


uint32_t ulExampleInterruptHandler( void ) {

	vPrintString( "Interrupcion Trepeada!.\r\n" );
	BaseType_t xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR( xTlmySemaphore, &xHigherPriorityTaskWoken );
	portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
	vPrintString( "Semaforo enviado.\r\n" );
	return 1;
}

void vNewTelemetryReceived(void* parameters){
	(void)parameters;
	for(;;){
		//Espero infinitamente hasta que llegue telemetria
		xSemaphoreTake( xTlmySemaphore, portMAX_DELAY );
		vPrintString( "Interrupcion 3 procesada.\r\n" );

	}

}

void vPrintString(const portCHAR *pcString)
{
	taskENTER_CRITICAL();
	{

		printf( "%s", pcString );
		fflush( stdout );
		//Serial.println(pcString);
	}
	taskEXIT_CRITICAL();

}

void TaskBlinkLed(void* pvParameters){
	portCHAR msg[50];
	//uint32_t i;

	for(;;){

		sprintf(msg, "LED %s Encendido\n", (portCHAR*)pvParameters);
		vPrintString(msg);
		vTaskDelay( 1000 / portTICK_PERIOD_MS );
		//for(i=0;i<500000000;i++){}
		sprintf(msg, "LED %s Apagado\n", (portCHAR*)pvParameters);
		vPrintString(msg);
		//for(i=0;i<500000000;i++){}
		vTaskDelay( 1000 / portTICK_PERIOD_MS );
	}

}

