/*
 * asociado.c
 *
 *  Created on: 5 may 2022
 *      Author: Nicolás Caruso
 */

#include "pasajero.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0

int inicializarPasajeros(Pasajero arr[], int len) {
	int codigoError;

	codigoError = -1;
	if(arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			arr[i].isEmpty = 1;
		}
		codigoError = 0;
	}

	return codigoError;
}



int buscarEspacioLibre(Pasajero arr[], int len) {
	int indice;

	indice = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].isEmpty == TRUE) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}



int buscarPasajeroPorId(Pasajero arr[], int id, int len) {
	int indice;

	indice = -1;
	if (arr != NULL && id > 0 && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].id == id && arr[i].isEmpty == 0) {
				indice = i;
				break;
			} else {
				printf("\nNo se ha encontrado el pasajero nº%d\n", id);
				break;
			}
		}
	}

	return indice;
}



int agregarPasajero(Pasajero arr[], int len, int id, char * nombre, char * apellido, float precio, int tipoPasajero, char * codigoVuelo, int estadoVuelo ) {
	int codigoError;
	int indice;
//	int numeroDocumento;
//	int edad;
	printf("Dentro de agregar pasajero");
	codigoError = -1;
	if (arr != NULL && len > 0 && id > 0 && nombre != NULL && apellido != NULL && precio > 0 && tipoPasajero >= 0 && codigoVuelo != NULL && estadoVuelo >= 0) {
		indice = buscarEspacioLibre(arr, len);
		printf("\nindice es: %d", indice);
		if (indice != -1) {
//			printf("\nEntre a la asignacion");
//			printf("\nid: %d, nombre: %s, apellido: %s, precio: %.2f, tipo pasajero: %d, codigo vuelo: %s, estado vuelo: %d", id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
			arr[indice].id = id;
			strncpy(arr[indice].nombre, nombre, strlen(nombre));
			strncpy(arr[indice].apellido, apellido, strlen(apellido));
			arr[indice].precio = precio;
			arr[indice].tipoPasajero = tipoPasajero;
			strncpy(arr[indice].codigoVuelo, codigoVuelo, strlen(codigoVuelo));
			arr[indice].estadoVuelo = estadoVuelo;
			arr[indice].isEmpty = FALSE;
			codigoError = 0;
		} else {
			puts("\n\nNo se pueden agregar más pasajeros");
		}
	}


	return codigoError;
}




int eliminarPasajero(Pasajero arr[], int id, int len) {
	int codigoError;
	int indice;

	codigoError = -1;
	if (arr != NULL && id > 0 && len > 0) {
		indice = buscarPasajeroPorId(arr, id, len);
		if (indice != -1) {
			arr[indice].isEmpty = TRUE;
			codigoError = 0;
		}
	}

	return codigoError;
}



int modificarPasajero(Pasajero arr[], int id, int opcionMenu, int len) {
	int codigoError;
	int indice;
//	int tipoPasajero;
//	char nuevoNombre[50];
//	char nuevoApellido[50];

	//PROBAR USANDO AUXILIARES Y ASIGNARLOS A LA PROPIEDAD DE LA ESTRUCTURA
	codigoError = -1;
	if (arr != NULL && id > 0 && opcionMenu > 0 && len > 0) {
		indice = buscarPasajeroPorId(arr, id, len);
		if (indice != -1) {
			switch (opcionMenu) {
				case 1:
					codigoError = utn_getString(arr[indice].nombre, "\nIngrese nuevo nombre: ", "\nHa sucedido un error al modificar el nombre\n", 3, 4);
//					if (codigoError == 0) {
//						strncpy(arr[indice].nombre, nuevoNombre, sizeof(nuevoNombre));
//						puts("\nNombre modificado con éxito\n");
//					}
					break;
				case 2:
					codigoError = utn_getString(arr[indice].apellido, "\nIngrese nuevo apellido: ", "\nHa sucedido un error al modificar el apellido\n", 3, 4);
//					if (codigoError == 0) {
//						strncpy(arr[indice].apellido, nuevoApellido, sizeof(nuevoApellido));
//						puts("\nApellido modificado con éxito\n");
//					}
					break;
				case 3:
					codigoError = utn_getFloat(&arr[indice].precio, "\nIngrese el nuevo precio: ", "\nHa sucedido un error al modificar el precio\n", 578800, 2500, 3);
					break;
				case 4:
					codigoError = utn_getInt(&arr[indice].tipoPasajero, "\nIngrese el tipo de pasajero [PRIMERA_CLASE (0), EJECUTIVO (1), PREMIUM (2)]: ", "\nHa ocurrido un error al modificar el tipo de pasajero\n", 2, 0, 3);
					break;
				case 5:
					codigoError = utn_getString(arr[indice].codigoVuelo, "\nIngrese el nuevo código de vuelo: ", "\nHa sucedido un error al modificar el código de vuelo\n", 3, 6);
					break;
				default:
					break;
			}
		} else {
			puts("\nID del pasajero inexistente\n");
		}
	}

	return codigoError;
}


int hayAlgoCargado(Pasajero arr[], int len) {
	int hayAlgo;

	hayAlgo = FALSE;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i].isEmpty == FALSE) {
				hayAlgo = TRUE;
				break;
			}
		}
	}

	return hayAlgo;
}


int existePasajero(Pasajero arr[], int len, int id) {
	int existe;
	int indice;

	existe = FALSE;
	if (arr != NULL && len > 0 && id > 0) {
		indice = buscarPasajeroPorId(arr, id, len);
		if (indice != -1) {
			existe = TRUE;
		}
	}

	return existe;
}


int incrementarId(void) {
	static int id = 150;
	id++;

	return id;
}



void imprimirPasajero(Pasajero pasajero) {
	if (pasajero.isEmpty == FALSE) {
		printf("|%6d", pasajero.id);
		printf("|%20s", pasajero.nombre);
		printf("|%20s", pasajero.apellido);
		printf("|%20f", pasajero.precio);
		printf("|%10s", pasajero.codigoVuelo);
		printf("|%10d", pasajero.tipoPasajero);
		printf("|%10d|", pasajero.estadoVuelo);
	}
}


