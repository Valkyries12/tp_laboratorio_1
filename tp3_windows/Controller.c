#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "utn.h"


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


int controller_hacerInforme(LinkedList* pArrayListPassenger) {
	int codigoError;
	int optionMenu;
	LinkedList* pFilteredByCodigoVuelo;
	FILE* pArchivo;
	int firstClass;
	int economyClass;
	int executiveClass;

	pFilteredByCodigoVuelo = ll_newLinkedList();
	codigoError = -1;
	if (pArrayListPassenger != NULL) {

		do {
			codigoError = utn_getInt(&optionMenu, "\n1- Pasajeros por clase. \n2- Generar archivo de vuelos. \n3- Calcular millas acumuladas. \n4- Salir. \n\nIngrese una opcion: ", "\nOpción inválida. Reintente.\n", 4, 1, 3);
			switch (optionMenu) {
				case 1:
					puts("\n=== PASAJEROS POR CLASE ===\n");// 0 primera, 1 ejecutiva y 2 economica son los tipos
					firstClass = ll_count(pArrayListPassenger, Passenger_verificarIgualdadTipoPasajero, 0);
					executiveClass = ll_count(pArrayListPassenger, Passenger_verificarIgualdadTipoPasajero, 1);
					economyClass = ll_count(pArrayListPassenger, Passenger_verificarIgualdadTipoPasajero, 2);
					codigoError = Passenger_imprimirCantidadTipoPasajero(firstClass, executiveClass, economyClass);
					utn_imprimirMensajes(codigoError, "\nSe han impreso la cantidad de tipo de pasajeros con éxito.\n", "\nHa ocurrido un error al imprimir.\n");
					break;
				case 2:
					puts("\n=== GENERAR ARCHIVOS DE VUELO ===\n");
					pFilteredByCodigoVuelo = ll_filter(pArrayListPassenger, Passenger_verificarIgualdadCodigoVuelo, "BA2491A");
					if (pFilteredByCodigoVuelo != NULL) {
						pArchivo = fopen("pasajerosFiltrados.csv", "w");

						if (pArchivo != NULL) {
							codigoError = Passenger_guardarComoTexto(pArchivo, pFilteredByCodigoVuelo);
							fclose(pArchivo);
						}

					}
					utn_imprimirMensajes(codigoError, "\nSe han guardado los datos con éxito.\n", "\nHa ocurrido un error al guardar datos.\n");
					break;
				case 3:
					puts("\n=== CALCULAR MILLAS ACUMULADAS ===\n");
					codigoError = ll_map(pArrayListPassenger, Passenger_listarPasajeroConMillas);
					utn_imprimirMensajes(codigoError, "\nSe han listado los datos con éxito.\n", "\nHa ocurrido un error al listar datos.\n");
					break;
				default:
					break;
			}

		} while (optionMenu != 4);
	}

	return codigoError;
}


