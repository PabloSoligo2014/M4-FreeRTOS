/*
 * AddTask.h
 *
 *  Created on: 12 jul. 2019
 *      Author: demo
 */

#ifndef ADDTASK_H_
#define ADDTASK_H_
#include "FreeRTOS.h"


#define mainINTERRUPT_NUMBER 3
void vPrintString(const portCHAR*);
void TaskBlinkLed(void* pvParameters);
void vNewTelemetryInterrupt(void* pvParameters);

void vNewTelemetryReceived(void* parameters);

uint32_t ulExampleInterruptHandler( void );

#endif /* ADDTASK_H_ */
