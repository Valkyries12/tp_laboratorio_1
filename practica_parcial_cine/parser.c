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

/** \brief Parsea los datos los datos de la entidad desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntidad LinkedList*
 * \return int
 *
 */
int parser_entidadFromText(FILE* pFile , LinkedList* pArrayList)
{
	Venta* this; //-> this representa a la entidad a crear
	//todos los campos son char porque los leo del archiivo y el constructor recibe char[]
	int codigoError;
	char strId[10];
	char strNombre[100];
	char strDia[10];
	char strHorario[50];
	char strSala[50];
	char strCantidadEntradas[50];
//	char strMonto[50];

	codigoError = -1;
	if (pFile != NULL && pArrayList != NULL) {

		//Lectura falsa para el header
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre, strDia, strHorario, strSala, strCantidadEntradas);
		do {
			codigoError = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre, strDia, strHorario, strSala, strCantidadEntradas);

			if (codigoError == 6 ) {
//				printf("\nstrIDVEnta es: %s, nombre peli es: %s, strDia es: %s, horario es: %s, strSala es: %s, strCantidad_entradas es: %s", strIdVenta, nombre_pelicula, strDia, horario, strSala, strCantidad_entradas);
				this = new_ventaParametros(strId, strNombre, strDia, strHorario, strSala, strCantidadEntradas, "0.0");

				if (this != NULL) {

					codigoError = ll_add(pArrayList, this);
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
