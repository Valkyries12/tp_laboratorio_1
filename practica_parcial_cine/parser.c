/*
 * parser.c
 *
 *  Created on: 20 jul 2022
 *      Author: Nico
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"

/** \brief Parsea los datos los datos de las ventas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int parser_VentasFromText(FILE* pFile , LinkedList* pArrayListVentas)
{
	Venta* pVenta;

	int codigoError;
	char nombre_pelicula[100];
	char horario[50];
	char strIdVenta[10];
	char strDia[10];
	char strSala[10];
	char strCantidad_entradas[50];
//	char strMonto[10];

	codigoError = -1;
	if (pFile != NULL && pArrayListVentas != NULL) {
		//Lectura falsa para el header
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strIdVenta, nombre_pelicula, strDia, horario, strSala, strCantidad_entradas);
		do {
			codigoError = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strIdVenta, nombre_pelicula, strDia, horario, strSala, strCantidad_entradas);
			if (codigoError == 6 ) {
//				printf("\nstrIDVEnta es: %s, nombre peli es: %s, strDia es: %s, horario es: %s, strSala es: %s, strCantidad_entradas es: %s", strIdVenta, nombre_pelicula, strDia, horario, strSala, strCantidad_entradas);
				pVenta = new_ventaParametros(strIdVenta, nombre_pelicula, strDia, horario, strSala, strCantidad_entradas, "0.0");

				if (pVenta != NULL) {
					codigoError = ll_add(pArrayListVentas, pVenta);
				}

				if (codigoError == -1) {
					break;
				}
			}
		} while(!feof(pFile));


	}

	return codigoError;
}

/** \brief Parsea  los datos de las ventas desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int parser_VentasFromBinary(FILE* pFile , LinkedList* pArrayListVentas)
{

}
