/*
 * MTasks.h
 *
 *  Created on: 18 oct. 2019
 *      Author: pabli
 */

#ifndef MTASKS_H_
#define MTASKS_H_

#define NEW_TEMP_INTERRUPT 10

void vEncenderApagarHeater(void* pvParameters);

void vNewTemperature(void* pvParameters);
uint32_t ulTempInterruptHandler( void );


#endif /* MTASKS_H_ */
