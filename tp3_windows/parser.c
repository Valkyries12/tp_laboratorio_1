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
		Passenger* pasajero;
		char idStr[10];
		char nombreStr[50];
		char apellidoStr[50];
		char precioStr[50];
		char tipoPasajeroStr[50];
		char codigoVueloStr[10];
		char estadoVueloStr[50];

		codigoError = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
		do {
			codigoError = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
//			printf("\n idStr es: %s, nombreStr es: %s, apellidoStr es: %s, precioStr es: %s, tipoPasajeroStr es: %s, codigoVueloStr es: %s, estadoVueloStr es: %s\n", idStr,nombreStr,apellidoStr,precioStr,tipoPasajeroStr,codigoVueloStr,estadoVueloStr);
			if (codigoError == 7) {
				pasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr, estadoVueloStr);

				if (pasajero != NULL) {
					ll_add(pArrayListPassenger, pasajero);
				} else {
					printf("id del no cargado es: %s", idStr);
					puts("\nNo se ha podido agregar al pasajero.\n");
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
