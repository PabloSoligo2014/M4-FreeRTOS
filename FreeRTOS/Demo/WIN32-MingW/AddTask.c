/*
 * AddTask.c
 *
 *  Created on: 12 jul. 2019
 *      Author: demo
 */


#include "AddTask.h"

#include "task.h"
#include <stdio.h>
#include <conio.h>
#include "queue.h"
//#include "Globals.h"

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

