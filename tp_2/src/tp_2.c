/*
 ============================================================================
 Name        : tp_2.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pasajero.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0
#define MAXIMO_PASAJEROS 2000


int main(void) {
	setbuf(stdout, NULL);
	Pasajero pasajeros[MAXIMO_PASAJEROS];
	char tipoPasajero[][20] = {"primera clase", "ejecutivo", "premium"};
	int codigoError;
	int opcionMenu;

	puts("=== INICIO DEL PROGRAMA === \n\n");

	inicializarPasajeros(pasajeros, MAXIMO_PASAJEROS);

	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Alta de pasajero \n2- Modificar pasajero \n3- Baja de pasajero \n4- INFORMAR \n5- Salir \n\nIngrese una opción: ", "\nOpción inválida. Reintente\n", 5, 1, 3);
		if (codigoError == 0) {
			switch (opcionMenu) {
				case 1:
					puts("=== Alta de pasajero ===");
					break;
				case 2:

					if (hayAlgoCargado(pasajeros, MAXIMO_PASAJEROS)) {
						puts("=== Modificar pasajero ===");
					} else {
						puts("Debe haber al menos un pasajero cargado");
					}
					break;
				case 3:

					if (hayAlgoCargado(pasajeros, MAXIMO_PASAJEROS)) {
						puts("=== Eliminar pasajero ===");
					} else {
						puts("Debe haber al menos un pasajero cargado");
					}
					break;
				case 4:

					if (hayAlgoCargado(pasajeros, MAXIMO_PASAJEROS)) {
						puts("=== INFORME ===");
					} else {
						puts("Debe haber al menos un pasajero cargado");
					}
					break;
				default:
					break;
			}
		}

	} while(opcionMenu != 5 && codigoError == 0);

	if (codigoError != 0) {
		puts("\nERROR FATAL");
	}

	puts("\n\nSaliendo...");

	puts("\n\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
