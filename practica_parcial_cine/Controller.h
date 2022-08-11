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
int controller_list(LinkedList* pArrayList);
int controller_sortPassenger(LinkedList* pArrayListVentas);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_saveAsBinary(char* path , LinkedList* pArrayListVentas);
int controller_hacerInforme(LinkedList* pArrayListVentas, int sala);

int controller_archivoConMontos(char* path, LinkedList* pArrayListVentas);
//int controller_menorDiasSaveAsText(char* path, LinkedList* pArrayListCachorros);
//int controller_archivoSinMachosSaveAsText(char* path, LinkedList* pArrayListCachorros);
//int controller_listCallejeros(LinkedList* pArrayListCachorros);


#endif /* CONTROLLER_H_ */
