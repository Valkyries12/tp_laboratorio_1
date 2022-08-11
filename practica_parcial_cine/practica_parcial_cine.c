/*
 ============================================================================
 Name        : practica_parcial_cine.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Controller.h"
#include "LinkedList.h"
#include <string.h>


#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu;
	int sala;
	int codigoError;
	char path[50];
	LinkedList* pArrayListVentas;

	pArrayListVentas = ll_newLinkedList();

	puts("\n=== INICIO DEL PROGRAMA ===\n");

	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Cargar archivo. \n2- Imprimir ventas. \n3- Generar archivos de montos. \n4- Informes.  \n5- Salir. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 5, 1, 3);
		if (codigoError == 0) {
			switch (opcionMenu) {
				case 1:
					puts("\n=== CARGAR ARCHIVO ===\n");
//					codigoError = utn_getStringConEspeciales(path, "\nIngrese el nombre del archivo: ", "\nError. Debe tener caracteres y una longitud entre 6 y 50.\n", 3, 6, 50);
					if (codigoError != -1) {
						codigoError = controller_loadFromText("DataParcialCine.csv", pArrayListVentas);
					}

					utn_imprimirMensajes(codigoError, "\nSe ha cargado el archivo con éxito.\n", "\nHa ocurrido un error al cargar el archivo o no se ha encontrado.\n");
					break;
				case 2:
					puts("\n=== IMPRIMIR VENTAS ===\n");
					if (ll_len(pArrayListVentas) > 0) {
						codigoError = controller_list(pArrayListVentas);
						utn_imprimirMensajes(codigoError, "\nSe han listado con éxito.\n", "\nHa ocurrido un error al listar.\n");
					} else {
						puts("\nPrimero se debe cargar el archivo.\n");
					}
					break;
				case 3:
					puts("\n=== GENERAR ARCHIVO DE MONTOS ===\n");
					if (ll_len(pArrayListVentas) > 0) {
						codigoError = controller_archivoConMontos("rchivoConMontos.csv", pArrayListVentas);
						utn_imprimirMensajes(codigoError, "\nSe ha generado el archivo con éxito.\n", "\nHa ocurrido un error al generar el archivo.\n");
					} else {
						puts("\nPrimero debes cargar el archivo.\n");
					}
					break;
				case 4:
					puts("\n=== INFORMES ===\n");
					if (ll_len(pArrayListVentas) > 0 && utn_getInt(&sala, "\nIngrese un número de sala: ", "\nOpción inválida. Reintente.\n", 10, 1, 3) != -1) {
							codigoError = controller_hacerInforme(pArrayListVentas, sala);
							utn_imprimirMensajes(codigoError, "\nSe ha generado el informe con éxito.\n", "\nHa ocurrido un error al generar el informe o la sala es inexistente.\n");

					} else {
						puts("\nPrimero debes cargar el archivo.\n");
					}
					break;
//				case 5:
//					puts("\n=== LISTAR CALLEJEROS ===\n");
//					if (ll_len(pArrayListCachorros) > 0) {
//							codigoError = controller_listCallejeros(pArrayListCachorros);
//							utn_imprimirMensajes(codigoError, "\nSe ha listado con éxito.\n", "\nHa ocurrido un error al listar.\n");
//
//					} else {
//						puts("\nPrimero debes cargar el archivo.\n");
//					}
//					break;
				case 5:
					puts("\nSaliendo...\n");
					break;
				default:
					break;
			}
		}

	} while (opcionMenu != 6);

	puts("\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
