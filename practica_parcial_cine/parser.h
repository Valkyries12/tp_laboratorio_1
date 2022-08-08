/*
 * parser.h
 *
 *  Created on: 20 jul 2022
 *      Author: Nico
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"

int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListVentas);
int parser_VentasFromBinary(FILE* pFile , LinkedList* pArrayListVentas);


#endif /* PARSER_H_ */
