/*
 * DebugIO.c
 *
 *  Created on: 18 oct. 2019
 *      Author: pablo
 */

#include <FreeRTOS.h>
#include "DebugIO.h"
#include <task.h>
#include <stdio.h>
#include <stdarg.h>

void vPrintString(const portCHAR *pcString){
	taskENTER_CRITICAL();
	{

		printf( "%s", pcString );
		fflush( stdout );
		//Serial.println(pcString);
	}
	taskEXIT_CRITICAL();
}


void vSecurePrintf(const portCHAR *format, ...){

    va_list args;
    va_start(args, format);
	taskENTER_CRITICAL();
	{

        // Llamar a printf con los argumentos variables
        vprintf(format, args);
		fflush( stdout );
		//Serial.println(pcString);
	}
	taskEXIT_CRITICAL();
	va_end(args);
}

