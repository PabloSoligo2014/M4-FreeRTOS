/*
 * Globals.h
 *
 *  Created on: 4 sept. 2019
 *      Author: demo
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include "FreeRTOS.h"

typedef struct
{
    char ucData[ 128 ];
}tPrMessage;


QueueHandle_t xPrQueue;



#endif /* GLOBALS_H_ */
