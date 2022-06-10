#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int codigoError;

	codigoError = -1;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		Passenger* pPasajero;
		char idStr[10];
		char nombreStr[50];
		char apellidoStr[50];
		char precioStr[50];
		char tipoPasajeroStr[50];
		char codigoVueloStr[10];
		char estadoVueloStr[50];
//		int len;
//		int auxId;

	//	len = ll_len(pArrayListPassenger);

		codigoError = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
		do {
			codigoError = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
//			printf("\n idStr es: %s, nombreStr es: %s, apellidoStr es: %s, precioStr es: %s, tipoPasajeroStr es: %s, codigoVueloStr es: %s, estadoVueloStr es: %s\n", idStr,nombreStr,apellidoStr,precioStr,tipoPasajeroStr,codigoVueloStr,estadoVueloStr);
			if (codigoError == 7) {

				//si ya hay algo cargado en la lista me hace que los id traidos sean consecutivos y coherentes con los que tengo
//				if (len > 0) {
//					auxId = atoi(idStr) + len;
//					itoa(auxId, idStr, 10);
//				}
				pPasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr, estadoVueloStr);

				if (pPasajero != NULL) {

					if (ll_add(pArrayListPassenger, pPasajero) != -1) {
						//TODO guardar ultimo id en archivo aca?
					} else {
						free(pPasajero);
					}
//					printf("\ndir de pasajero 1 y 2 es: %p  %p\n", pasajero[]);
				}
			}

		} while(!feof(pFile));
		codigoError = 0;
	}


    return codigoError;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
