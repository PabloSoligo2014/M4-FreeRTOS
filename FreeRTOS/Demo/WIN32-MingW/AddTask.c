/*
 * AddTask.c
 *
 *  Created on: 12 jul. 2019
 *      Author: demo
 */


#include "AddTask.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <conio.h>
#include "queue.h"
#include "Globals.h"

void ThermalTlmyGenerator(void *pvParameters)
{

	const TickType_t xDelay = 5000 / portTICK_PERIOD_MS;
	tPrMessage msg;
	(void)pvParameters;
	while(1){
		strcpy(msg.ucData, "Mensaje de test");

		if( xQueueSend( xPrQueue, ( void * ) &msg, ( TickType_t ) 10 ) != pdPASS ){
			/* Failed to post the message, even after 10 ticks. */
			printf("Fallo al encolar\r\n");


		}
		vTaskDelay( xDelay );

	}
}


void deQueue(void *pvParameters)
{
	const TickType_t xDelay = 5000 / portTICK_PERIOD_MS;
	tPrMessage msg;
	(void)pvParameters;
	while(1){
		if( xQueueReceive( xPrQueue, &msg, ( TickType_t ) 10 ) ){
			printf("%s", (portCHAR*)msg.ucData);
			fflush(stdout);
		}
		vTaskDelay( xDelay );
	}
}
