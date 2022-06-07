/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

#define TRUE 1
#define FALSE 0




Passenger* Passenger_new() {
	Passenger* pasajero;
	Passenger* auxPasajero;

	pasajero = NULL;
	auxPasajero = NULL;

	auxPasajero = (Passenger*) malloc(sizeof(Passenger));
	if (auxPasajero != NULL) {
		pasajero = auxPasajero;
	}

	return pasajero;

}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr) {
	Passenger* pasajero;
//	Passenger* auxPasajero;

	pasajero = NULL;
//	auxPasajero = NULL;
	//TODO -> una vez creado y pasado a pasajero . Auxpasajero hay que borrarlo con free?
	//Si libero esa direccion no me borra pasajero al ser las dos iguales?
	if (idStr != NULL && nombreStr && apellidoStr != NULL && precioStr != NULL  && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL) {
		pasajero = Passenger_new(); //creo un nuevo pasajero en memoria
		if (pasajero != NULL) {

			if (Passenger_setId(pasajero, atoi(idStr)) == 0 &&
				Passenger_setNombre(pasajero, nombreStr) == 0 &&
				Passenger_setApellido(pasajero, apellidoStr) == 0 &&
				Passenger_setPrecio(pasajero, atof(precioStr)) == 0 &&
				Passenger_setTipoPasajero(pasajero, Passenger_tipoPasajeroToInt(tipoPasajeroStr)) == 0 &&
				Passenger_setCodigoVuelo(pasajero, codigoVueloStr) == 0 &&
				Passenger_setEstadoVuelo(pasajero, Passenger_estadoVueloToInt(estadoVueloStr)) == 0
				) {
				//TODO cambiar a algo mas coherente porque para que hacer setters con retorno si no lo uso
				puts("\nSe ha cargado el pasajero\n");
//				pasajero = auxPasajero;

			} else {
//				free(auxPasajero);
				printf("\nNo se ha podido crear al pasajero con id: %s.\n", idStr);
			}
		}
	}

	return pasajero;
}


void Passenger_delete(Passenger* this) {
	free(this);
}

int Passenger_setId(Passenger* this,int id) {
	int codigoError;
//	printf("this es: %p, id es: %d",this,id);
//	puts("\nDentro de setId\n");
	codigoError = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getId(Passenger* this,int* id) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setNombre(Passenger* this,char* nombre) {
	int codigoError;
//	puts("\nDentro de setNombre\n");

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getNombre(Passenger* this,char* nombre) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setApellido(Passenger* this,char* apellido) {
	int codigoError;
//	puts("\nDentro de setApellido\n");

	codigoError = -1;
	if (this != NULL && apellido != NULL) {
		strcpy(this->apellido, apellido);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getApellido(Passenger* this,char* apellido) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo) {
	int codigoError;
//	printf("\nDentro de setCodigoVuelo, codigoVuelo es: %s\n", codigoVuelo);

	codigoError = -1;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(this->codigoVuelo, codigoVuelo);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero) {
	int codigoError;
//	puts("\nDentro de setTipoPasajero\n");

	codigoError = -1;
	if (this != NULL && tipoPasajero > -1) {
		this->tipoPasajero = tipoPasajero;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setPrecio(Passenger* this,float precio) {
	int codigoError;
//	puts("\nDentro de setPrecio\n");

	codigoError = -1;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getPrecio(Passenger* this,float* precio) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo) {
	int codigoError;
//	printf("\nDentro de setEstadoVuelo, estado de vuelo es: %d\n", estadoVuelo);

	codigoError = -1;
	if (this != NULL && estadoVuelo > -1) {
		this->estadoVuelo = estadoVuelo;
		codigoError = 0;
	}

	return codigoError;
}


int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->estadoVuelo;
		codigoError = 0;
	}

	return codigoError;
}


int Passenger_tipoPasajeroToInt(char* tipoPasajeroStr) {
	int tipoPasajeroInt;

	tipoPasajeroInt = -1;
	if (tipoPasajeroStr != NULL) {
		if (strcmp(tipoPasajeroStr, "FirstClass") == 0) {
			tipoPasajeroInt = 0;
		} else {
			if (strcmp(tipoPasajeroStr, "ExecutiveClass") == 0) {
				tipoPasajeroInt = 1;
			} else {
				tipoPasajeroInt = 2;
			}
		}

	}

	return tipoPasajeroInt;
}


int Passenger_TipoPasajeroToStr(int tipoPasajeroInt, char* tipoPasajeroStr) {
	int codigoError;

	codigoError = -1;
	if (tipoPasajeroInt > -1 && tipoPasajeroStr != NULL) {

		switch (tipoPasajeroInt) {
			case 0:
				strcpy(tipoPasajeroStr, "FirstClass");
				break;
			case 1:
				strcpy(tipoPasajeroStr, "ExecutiveClass");
				break;
			case 2:
				strcpy(tipoPasajeroStr, "EconomyClass");
				break;
			default:
				break;
		}
		codigoError = 0;
	}

	return codigoError;
}




int Passenger_estadoVueloToInt(char* estadoVueloStr) {
	int estadoVueloInt;

	estadoVueloInt = -1;
	if (estadoVueloStr != NULL) {
		if (strcmp(estadoVueloStr, "En Horario") == 0) {
			estadoVueloInt = 0;
		} else {
			if (strcmp(estadoVueloStr, "Aterrizado") == 0) {
				estadoVueloInt = 1;
			} else {
				estadoVueloInt = 2;
			}
		}

	}

	return estadoVueloInt;
}


int Passenger_estadoVueloToStr(int estadoVueloInt, char* estadoVueloStr) {
	int codigoError;

	codigoError = -1;

	if (estadoVueloInt > -1 && estadoVueloStr != NULL) {

		switch (estadoVueloInt) {
			case 0:
				strcpy(estadoVueloStr, "En Horario");
				break;
			case 1:
				strcpy(estadoVueloStr, "Aterrizado");
				break;
			case 2:
				strcpy(estadoVueloStr, "En Vuelo");
				break;
			default:
				break;
		}
		codigoError = 0;
	}

	return codigoError;
}


void Passenger_imprimirPasajero(Passenger* pPasajero) {
	//TODO hacer imprimir pasajero con getters y ponerlo dentro del controller
	if (pPasajero != NULL) {
		int id;
		char nombre[50];
		char apellido[50];
		float precio;
		int tipoPasajero;
		char tipoPasajeroStr[20];
		char codigoVuelo[10];
		int estadoVuelo;
		char estadoVueloStr[20];

		if (Passenger_getId(pPasajero, &id) == 0 &&
			Passenger_getNombre(pPasajero, nombre) == 0 &&
			Passenger_getApellido(pPasajero, apellido) == 0 &&
			Passenger_getPrecio(pPasajero, &precio) == 0 &&
			Passenger_getTipoPasajero(pPasajero, &tipoPasajero) == 0 &&
			Passenger_getCodigoVuelo(pPasajero, codigoVuelo) == 0 &&
			Passenger_getEstadoVuelo(pPasajero, &estadoVuelo) == 0)
		{

			Passenger_estadoVueloToStr(estadoVuelo, estadoVueloStr);
			Passenger_TipoPasajeroToStr(tipoPasajero, tipoPasajeroStr);

			printf("|%6d", id);
			printf("|%20s", nombre);
			printf("|%20s", apellido);
			printf("|%20.2f", precio);
			printf("|%15s", tipoPasajeroStr);
			printf("|%20s", codigoVuelo);
			printf("|%15s|\n", estadoVueloStr);

		}


	}
}


void Passenger_imprimirCabecera(void) {
	printf("|%6s", "ID");
	printf("|%20s", "NOMBRE");
	printf("|%20s", "APELLIDO");
	printf("|%20s", "PRECIO");
	printf("|%15s", "TIPO PASAJERO");
	printf("|%20s", "CÓDIGO VUELO");
	printf("|%15s|\n", "ESTADO VUELO");
}

