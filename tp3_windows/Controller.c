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
			puts("\nSe han traido los datos con éxito.\n");
		} else {
			puts("\nNo se han podido traer los datos.\n");
		}
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
    return 1;
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
    return 1;
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
	Passenger_imprimirSortMenu(pArrayListPassenger);
    return 1;
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

