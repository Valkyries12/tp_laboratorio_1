#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int codigoError;
	codigoError = -1;
	if (path != NULL && pArrayListPassenger != NULL)  {
		FILE* pArchivo;
		pArchivo = fopen(path, "r");
		codigoError = parser_PassengerFromText(pArchivo, pArrayListPassenger);

		if (codigoError != -1) {
			//si falla al guardar el ultimo id limpio lista
			if (Passenger_guardarUltimoId("ultimoID.txt", pArrayListPassenger) == -1) {
				ll_clear(pArrayListPassenger);
			}
		}
		codigoError = fclose(pArchivo);
	}


    return codigoError;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int codigoError;

	codigoError = -1;
	if (path != NULL && pArrayListPassenger != NULL) {

		pArchivo = fopen("data.bin", "rb");
		codigoError = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);

		if (codigoError != -1) {
			//si falla al guardar el ultimo id limpio lista
			if (Passenger_guardarUltimoId("ultimoID.txt", pArrayListPassenger) == -1) {
				ll_clear(pArrayListPassenger);
			}
		}
		codigoError = fclose(pArchivo);
	}

    return codigoError;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int codigoError;

	codigoError = -1;
	if (pArrayListPassenger != NULL) {
		codigoError = Passenger_agregarPasajero(pArrayListPassenger);
	}

    return codigoError;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int codigoError;

	codigoError = 1;
	if (pArrayListPassenger != NULL) {

		codigoError = Passenger_editarPasajero(pArrayListPassenger);
	}

    return codigoError;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int codigoError;

	codigoError = -1;
	if (pArrayListPassenger != NULL) {

		codigoError = Passenger_borrarPasajero(pArrayListPassenger);

	}

    return codigoError;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int codigoError;

	codigoError = -1;
	if (pArrayListPassenger != NULL) {
		int len;
		len = ll_len(pArrayListPassenger);
//		printf("len es: %d", len);
		Passenger_imprimirCabecera();
		for(int i = 0; i < len; i++) {
			Passenger_imprimirPasajero(ll_get(pArrayListPassenger, i));
		}

		codigoError = 0;
	}

    return codigoError;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int codigoError;

	codigoError = -1;
	if (pArrayListPassenger != NULL) {
		codigoError = Passenger_imprimirSortMenu(pArrayListPassenger);

	}
    return codigoError;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int codigoError;
	FILE* pArchivo;

	codigoError = -1;
	if (path != NULL && pArrayListPassenger != NULL) {
		pArchivo = fopen(path, "w");
		if (pArchivo != NULL) {
			codigoError = Passenger_guardarComoTexto(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
		}
	}
    return codigoError;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int codigoError;

	codigoError = -1;
	if (path != NULL && pArrayListPassenger != NULL) {
		pArchivo = fopen(path, "wb");

		if (pArchivo != NULL) {
			codigoError = Passenger_guardarComoBinario(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
		}
	}

    return codigoError;
}

