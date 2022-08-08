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


/** \brief Carga los datos de las ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListVentas)
{
	int codigoError;
	FILE* pFile;
	codigoError = -1;
	if (path != NULL && pArrayListVentas != NULL) {

		pFile = fopen(path, "r");
		//TODO ver si va != NULL o que carajo devuelve
		if (pFile != NULL) {
			codigoError = parser_VentasFromText(pFile, pArrayListVentas);

		}

		fclose(pFile);
	}

	return codigoError;
}

/** \brief Carga los datos de las ventas desde el archivo data.csv (modo binario).
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

/** \brief Listar ventas
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_ListVentas(LinkedList* pArrayListVentas)
{
	int codigoError;

	codigoError = -1;
	if (pArrayListVentas != NULL) {
		codigoError = imprimirVentas(pArrayListVentas);
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

/** \brief Guarda los datos de las ventas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListVentas)
{
	int codigoError;
	FILE* pFile;

	codigoError = -1;
	if (path != NULL && pArrayListVentas != NULL) {
		pFile = fopen(path, "w");

		if (pFile != NULL) {
			codigoError = venta_guardarComoTexto(pFile, pArrayListVentas);
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


int controller_hacerInforme(LinkedList* pArrayListVentas, int sala) {
	int codigoError;
	int cantidadEntradasVendidas;
	float montoTotal;
	LinkedList* pArrayListPeliculas;

	pArrayListPeliculas = ll_newLinkedList();
	cantidadEntradasVendidas = 0;
	montoTotal = 0;
	codigoError = -1;
	if (pArrayListVentas != NULL && sala > -1) {

		if (calcularEntradasVendidasPorSala(pArrayListVentas, &cantidadEntradasVendidas, sala) != -1 &&
			calcularMontoTotalPorSala(pArrayListVentas, &montoTotal, sala) != -1 &&
			peliculasPorSala(pArrayListVentas, pArrayListPeliculas, sala) != -1
		) {
			codigoError = imprimirInformes(cantidadEntradasVendidas, montoTotal, pArrayListPeliculas);
		}
	}

	return codigoError;
}


