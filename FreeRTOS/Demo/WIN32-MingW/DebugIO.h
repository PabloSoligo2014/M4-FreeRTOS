/*
 * DebugIO.h
 *
 *  Created on: 18 oct. 2019
 *      Author: pabli
 */

#ifndef DEBUGIO_H_
#define DEBUGIO_H_
#include <stdarg.h>
#include "portable.h"

void vPrintString(const portCHAR *pcString);
void vSecurePrintf(const portCHAR *format, ...);


#endif /* DEBUGIO_H_ */
