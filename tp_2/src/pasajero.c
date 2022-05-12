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

char opcionTipoPasajero[][20] = {"PRIMERA_CLASE", "EJECUTIVO", "PREMIUM"};
char opcionEstadoVuelo[][20] = {"ACTIVO", "DEMORADO", "CANCELADO"};

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
	codigoError = -1;
	if (arr != NULL && len > 0 && id > 0 && nombre != NULL && apellido != NULL && precio > 0 && tipoPasajero >= 0 && codigoVuelo != NULL && estadoVuelo >= 0) {
		indice = buscarEspacioLibre(arr, len);
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
		printf("|%15s", pasajero.codigoVuelo);
		printf("|%20s", opcionTipoPasajero[pasajero.tipoPasajero]);
		printf("|%15s|\n", opcionEstadoVuelo[pasajero.estadoVuelo]);
	}
}


void imprimirCabecera(void) {

		printf("|%6s", "ID");
		printf("|%20s", "NOMBRE");
		printf("|%20s", "APELLIDO");
		printf("|%20s", "PRECIO");
		printf("|%15s", "CÓDIGO VUELO");
		printf("|%20s", "TIPO PASAJERO");
		printf("|%15s|\n\n", "ESTADO VUELO");

}



void imprimirPasajeros(Pasajero arr[], int len) {
	if (arr != NULL) {
		for(int i = 0; i < len; i++) {
			imprimirPasajero(arr[i]);
		}
	}
}




int ordenarPasajeros(Pasajero arr[], int len, int orden) {
	int codigoError;
	int estaOrdenado;

	Pasajero auxPasajero;


	codigoError = -1;
	if (arr != NULL && len > 0 && (orden == 0 || orden == 1)) {
		do {
			estaOrdenado = TRUE;
			len--;
			if (orden == 1) {
				//ordeno de forma ascendente
				for (int i = 0; i < len; i++) {

					if (strcmp(arr[i].apellido, arr[i + 1].apellido) > 0) {
						if (arr[i].tipoPasajero > arr[i + 1].tipoPasajero) {
							auxPasajero = arr[i];
							arr[i] = arr[i + 1];
							arr[i + 1] = auxPasajero;
							estaOrdenado = FALSE;
						}

					}
				}
			} //else {
//				//ordeno de forma descendente
//				for (int i = 0; i < len; i++) {
//
//					if (strcmp(arr[i].apellido, arr[i + 1].apellido) < 0) {
//						if (arr[i].tipoPasajero < arr[i + 1].tipoPasajero) {
//							auxPasajero = arr[i];
//							arr[i] = arr[i + 1];
//							arr[i + 1] = auxPasajero;
//							estaOrdenado = FALSE;
//						}
//
//					}
//				}
//			}

		} while (estaOrdenado == FALSE);
		codigoError = 0;
	}

	return codigoError;
}


int hacerCargaForzada(Pasajero arr[], int len) {
	int codigoError;
	int id;
	char nombres[][51] = {"Nicolas", "Andrea", "Carlos", "Lucas", "Maximiliano", "Hector", "Jesica", "Gabriel", "Horacio", "Oscar"};
	char apellidos[][51] = {"Caruso", "Bollati", "Vitola", "Calvo", "Biglia", "Thomas", "Paulovies", "Marino", "Bollati", "Chananpa"};
	float precios[] = {6500, 7200, 30255, 7900, 17456, 56789, 25400, 9800, 27890, 15600};
	int tipoPasajeros[] = {1, 2, 0, 0, 1, 2, 0, 1, 1, 2};
	char codigoVuelos[][10] = {"ARARAR", "QWEASD", "ASDQWE", "ZXCVBN", "QWERTY", "TYUGHJ", "TYUQWE", "ASDFGH", "UIOPJKL", "QWEASD"};
	int estadoVuelos[] = {0, 2, 1, 1, 1, 2, 0, 0, 2, 1};
	codigoError = -1;

	if (arr != NULL) {
		for(int i = 0; i < 10; i++) {
			id = incrementarId();
			codigoError = agregarPasajero(arr, len, id, nombres[i], apellidos[i], precios[i], tipoPasajeros[i], codigoVuelos[i], estadoVuelos[i]);
			if (codigoError == -1) {
				codigoError = -1;
				break;
			}
			codigoError = 0;
		}
	}

	return codigoError;
}




