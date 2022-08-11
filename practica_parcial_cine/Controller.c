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
#include "Venta.h"

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
		codigoError = ll_map(pArrayList, imprimirVenta);
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
			codigoError = venta_guardarComoTexto(pFile, pArrayList);
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

int controller_archivoConMontos(char* path, LinkedList* pArrayListVentas) {
	int codigoError;
	FILE* pFile;

	codigoError = -1;
	if (path != NULL && pArrayListVentas != NULL) {
		pFile = fopen(path, "w");

		if (pFile != NULL) {
			codigoError = ll_map(pArrayListVentas, calcularMonto);
			codigoError = venta_guardarComoTexto(pFile, pArrayListVentas);
		}

		fclose(pFile);
	}

	return codigoError;
}



int controller_hacerInforme(LinkedList* pArrayListVentas, int sala) {
	int codigoError;
	int cantidadEntradasVendidas;
	int montoTotal;

	codigoError = -1;
	if (pArrayListVentas != NULL && sala > 0) {
		cantidadEntradasVendidas = ll_contador(pArrayListVentas, verificarEntradasPorSala, sala);
		montoTotal = (int) ll_contador(pArrayListVentas, calcularMontoTotal, sala);

		printf("\nLa cantidad de entradas vendidas es: %d", cantidadEntradasVendidas);
		printf("\nEl monto facturado es: %d", montoTotal);
		codigoError = 0;
	}

	return codigoError;
}


