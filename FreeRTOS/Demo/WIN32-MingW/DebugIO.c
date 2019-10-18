/*
 * DebugIO.c
 *
 *  Created on: 18 oct. 2019
 *      Author: pabli
 */

#include <FreeRTOS.h>
#include "DebugIO.h"
#include <task.h>
#include <stdio.h>

void vPrintString(const portCHAR *pcString){
	taskENTER_CRITICAL();
	{

		printf( "%s", pcString );
		fflush( stdout );
		//Serial.println(pcString);
	}
	taskEXIT_CRITICAL();
}

