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

		fclose(pArchivo);
	}


//	if (pArchivo != NULL) {
//
//	}
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
    return 1;
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
    return 1;
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
		printf("len es: %d", len);
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
	//TODO clonar la lista para ordenar ymostrar porque si la guardo en el csv se va a guardar ordenada
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
    return 1;
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
    return 1;
}

