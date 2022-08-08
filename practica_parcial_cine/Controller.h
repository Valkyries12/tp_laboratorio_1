/*
 * Controller.h
 *
 *  Created on: 20 jul 2022
 *      Author: Nico
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListVentas);
int controller_loadFromBinary(char* path , LinkedList* pArrayListVentas);
int controller_addPassenger(LinkedList* pArrayListVentas);
int controller_editPassenger(LinkedList* pArrayListVentas);
int controller_removePassenger(LinkedList* pArrayListVentas);
int controller_ListVentas(LinkedList* pArrayListVentas);
int controller_sortPassenger(LinkedList* pArrayListVentas);
int controller_saveAsText(char* path , LinkedList* pArrayListVentas);
int controller_saveAsBinary(char* path , LinkedList* pArrayListVentas);
int controller_hacerInforme(LinkedList* pArrayListVentas, int sala);




#endif /* CONTROLLER_H_ */
