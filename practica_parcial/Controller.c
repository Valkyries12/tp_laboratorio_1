/*
 * Controller.c
 *
 *  Created on: 20 jul 2022
 *      Author: Nico
 */


#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Cachorro.h"


/** \brief Carga los datos de la entidad desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int codigoError;
	FILE* pFile;
	codigoError = -1;
	if (path != NULL && pArrayList != NULL) {

		pFile = fopen(path, "r");
		if (pFile != NULL) {
			codigoError = parser_entidadFromText(pFile, pArrayList);

		}

		fclose(pFile);
	}

	return codigoError;
}

/** \brief Carga los datos  desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListVentas)
{

}

/** \brief Alta de venta
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_addVenta(LinkedList* pArrayListVentas)
{

}

/** \brief Modificar datos de ventas
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_editVenta(LinkedList* pArrayListVentas)
{

}

/** \brief Baja de venta
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_removeVenta(LinkedList* pArrayListVentas)
{

}

/** \brief Listar
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_list(LinkedList* pArrayList)
{
	int codigoError;

	codigoError = -1;
	if (pArrayList != NULL) {
		codigoError = ll_map(pArrayList, imprimirCachorro);
	}

	return codigoError;
}



/** \brief Filtra por callejeros y los lista
 *
 * \param path char*
 * \param pArrayListCachorros LinkedList*
 * \return int
 *
 */
int controller_listCallejeros(LinkedList* pArrayListCachorros) {
	int codigoError;
	LinkedList* pArrayFilteredList;

	pArrayFilteredList = NULL;
	codigoError = -1;
	if (pArrayListCachorros != NULL) {
		pArrayFilteredList = ll_filter(pArrayListCachorros, cachorro_esCallejero);

		if (pArrayFilteredList != NULL) {
			codigoError = ll_map(pArrayFilteredList, imprimirCachorro);
		}

	}

	return codigoError;
}


/** \brief Ordenar ventas
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_sortVentas(LinkedList* pArrayListVentas)
{

}

/** \brief Guarda los datos de la entidad en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int codigoError;
	FILE* pFile;

	codigoError = -1;
	if (path != NULL && pArrayList != NULL) {
		pFile = fopen(path, "w");

		if (pFile != NULL) {
			codigoError = cachorro_guardarComoTexto(pFile, pArrayList);
		}

		fclose(pFile);
	}

	return codigoError;
}


/** \brief Guarda los datos de cachorros myores a 45 dis en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedListCachorros*
 * \return int
 *
 */
int controller_menorDiasSaveAsText(char* path , LinkedList* pArrayListCachorros)
{
	int codigoError;
	FILE* pFile;
	LinkedList* pArrayFilteredList;

	codigoError = -1;
	if (path != NULL && pArrayListCachorros != NULL) {

		pArrayFilteredList = ll_filter(pArrayListCachorros, cachorro_esMayor45Dias);
		pFile = fopen(path, "w");
		//TODO grega filter menores a 45 diaas
		if (pFile != NULL && pArrayFilteredList != NULL) {
			codigoError = cachorro_guardarComoTexto(pFile, pArrayFilteredList);
		}

		fclose(pFile);
	}

	return codigoError;
}


/** \brief Guarda los datos de cachorros hembra dis en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedListCachorros*
 * \return int
 *
 */
int controller_archivoSinMachosSaveAsText(char* path, LinkedList* pArrayListCachorros) {
	int codigoError;
	FILE* pFile;
	LinkedList* pArrayFilteredList;

	codigoError = -1;
	if (path != NULL && pArrayListCachorros != NULL) {

		pArrayFilteredList = ll_filter(pArrayListCachorros, cachorro_esHembra);
		pFile = fopen(path, "w");

		if (pFile != NULL && pArrayFilteredList != NULL) {
			codigoError = cachorro_guardarComoTexto(pFile, pArrayFilteredList);
		}

		fclose(pFile);
	}

	return codigoError;
}


/** \brief Guarda los datos de las ventas en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListVentas)
{

}





