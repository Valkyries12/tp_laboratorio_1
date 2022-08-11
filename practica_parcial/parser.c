/*
 * parser.c
 *
 *  Created on: 20 jul 2022
 *      Author: Nico
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorro.h"

/** \brief Parsea los datos los datos de los cachorros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCachorros LinkedList*
 * \return int
 *
 */
int parser_entidadFromText(FILE* pFile , LinkedList* pArrayListCachorros)
{
	Cachorro* this; //-> this representa a la entidad a crear
	//todos los campos son char porque los leo del archiivo y el constructor recibe char[]
	int codigoError;
	int camposLeidos;
	char strId[10];
	char strNombre[100];
	char strDias[10];
	char strRaza[50];
	char strReservado[50];
	char strGenero[50];

	codigoError = -1;
	if (pFile != NULL && pArrayListCachorros != NULL) {
		//Lectura falsa para el header
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre, strDias, strRaza, strReservado, strGenero);
		do {
			camposLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre, strDias, strRaza, strReservado, strGenero);
			if (camposLeidos == 6 ) {
//				printf("\nstrIDVEnta es: %s, nombre peli es: %s, strDia es: %s, horario es: %s, strSala es: %s, strCantidad_entradas es: %s", strIdVenta, nombre_pelicula, strDia, horario, strSala, strCantidad_entradas);
				this = new_cachorroParametros(strId, strNombre, strDias, strRaza, strReservado, strGenero);

				if (this != NULL) {
					codigoError = ll_add(pArrayListCachorros, this);
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
