/*
 ============================================================================
 Name        : tp_2.c
 Author      : Nicol�s Caruso
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
	char opcionTipoPasajero[][20] = {"PRIMERA_CLASE", "EJECUTIVO", "PREMIUM"};
	char opcionEstadoVuelo[][20] = {"ACTIVO", "DEMORADO", "CANCELADO"};
	int codigoError;
	int opcionMenu;
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int estadoVuelo;
	int tipoPasajero;

	puts("=== INICIO DEL PROGRAMA === \n\n");

	inicializarPasajeros(pasajeros, MAXIMO_PASAJEROS);

	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Alta de pasajero \n2- Modificar pasajero \n3- Baja de pasajero \n4- INFORMAR \n5- Salir \n\nIngrese una opci�n: ", "\nOpci�n inv�lida. Reintente\n", 5, 1, 3);
		if (codigoError == 0) {
			switch (opcionMenu) {
				case 1:
					puts("=== Alta de pasajero ===");
					codigoError = utn_getString(nombre, "\nIngrese nombre del pasajero: ", "\nHa sucedido un error al ingresar el nombre\n", 3, 4);
					if (codigoError == 0) {
						codigoError = utn_getString(apellido, "\nIngrese apellido del pasajero: ", "\nHa sucedido un error al ingresar el apellido\n", 3, 4);
					}
					if (codigoError == 0) {
						codigoError = utn_getFloat(&precio, "\nIngrese precio del pasaje: ", "\nHa sucedido un error al ingresar el precio\n", 750000, 2500, 3);
					}
					if (codigoError == 0) {
						codigoError = utn_getString(codigoVuelo, "\nIngrese c�digo de vuelo: ", "\nHa sucedido un error con el c�digo de vuelo\n", 3, 6);
					}
					if (codigoError == 0) {
						codigoError = utn_getInt(&estadoVuelo, "\nIngrese el estado de vuelo 0-> activo, 1-> demorado, 2-> cancelado: ", "\nHa ocurrido un error con el estado de vuelo\n", 2, 0, 3);
					}
					if (codigoError == 0) {
						codigoError = utn_getInt(&tipoPasajero, "\nIngrese el tipo de pasajero 0-> primera clase, 1-> ejecutivo, 2-> premium: ", "\nHa ocurrido un error con el tipo de pasajero", 2, 0, 3);
					}
					if (codigoError == 0) {
						id = incrementarId();
						agregarPasajero(pasajeros, MAXIMO_PASAJEROS, id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
					}
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

						imprimirPasajero(pasajeros[0]);
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