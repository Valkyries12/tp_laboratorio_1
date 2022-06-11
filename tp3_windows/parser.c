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


		if (ll_len(pArrayListPassenger) > 0) {
			ll_clear(pArrayListPassenger);
		}
		codigoError = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
		do {
			codigoError = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
//			printf("\n idStr es: %s, nombreStr es: %s, apellidoStr es: %s, precioStr es: %s, tipoPasajeroStr es: %s, codigoVueloStr es: %s, estadoVueloStr es: %s\n", idStr,nombreStr,apellidoStr,precioStr,tipoPasajeroStr,codigoVueloStr,estadoVueloStr);
			if (codigoError == 7) {

				pPasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr, estadoVueloStr);

				if (pPasajero != NULL) {

					if (ll_add(pArrayListPassenger, pPasajero) == -1) {
						free(pPasajero);
					}
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
	int codigoError;

	codigoError = -1;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		Passenger* pPasajero;

		if (ll_len(pArrayListPassenger) > 0) {
			ll_clear(pArrayListPassenger);
		}

		do {
			pPasajero = Passenger_new();

			if (pPasajero != NULL && fread(pPasajero, sizeof(Passenger), 1, pFile) == 1) {//fread devuelve 1 si leyo una fila

				if (ll_add(pArrayListPassenger, pPasajero) == -1) {
					free(pPasajero);
				}
			}


		} while(!feof(pFile));
		codigoError = 0;
	}


	return codigoError;
}
