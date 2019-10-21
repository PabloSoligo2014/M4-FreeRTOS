/*
 * MTasks.c
 *
 *  Created on: 21 oct. 2019
 *      Author: pabli
 */


#include "FreeRTOS.h"
#include "task.h"
#include "MTasks.h"
#include "DebugIO.h"
#include "Globals.h"

void vManageHeaters(void *parameters){
	//while(1)
	char* msg = parameters;

	portCHAR msgEnc[50] = "Heater Encedido ";
	portCHAR msgApa[50] = "Heater Apagado ";

	strcat(msgEnc, msg);
	strcat(msgEnc, "\n");


	strcat(msgApa, msg);
	strcat(msgApa, "\n");
	float temp;
	BaseType_t qr;
	for(;;){

		qr = xQueueReceive(xPrQueue, &temp, pdMS_TO_TICKS(5000));

		if(qr==errQUEUE_EMPTY ){
			vPrintString("Cola vacia no hay temperaturas");
		}else{
			if(temp<0){
				vPrintString(msgEnc);
			}else if (temp>25){
				vPrintString(msgApa);
			}else{
				vPrintString("Sin novedades");
			}
		}


		vTaskDelay(pdMS_TO_TICKS(10000));



	}

}

//



