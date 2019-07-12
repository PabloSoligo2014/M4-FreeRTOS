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

void ThermalTlmyGenerator(void *pvParameters)
{

	const TickType_t xDelay = 5000 / portTICK_PERIOD_MS;

	(void)pvParameters;
	while(1){
		printf("Generando telemetria de subsistema termico\r\n");
		vTaskDelay( xDelay );

	}
}
