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
				Passenger_setTipoPasajero(pasajero, tipoPasajeroToInt(tipoPasajeroStr)) == 0 &&
				Passenger_setCodigoVuelo(pasajero, codigoVueloStr) == 0 &&
				Passenger_setEstadoVuelo(pasajero, estadoVueloToInt(estadoVueloStr)) == 0
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


int tipoPasajeroToInt(char* tipoPasajeroStr) {
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



int estadoVueloToInt(char* estadoVueloStr) {
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


void Passenger_imprimirPasajero(Passenger pasajero) {
	//TODO hacer imprimir pasajero con getters y ponerlo dentro del controller
	if (pasajero != NULL) {
		printf("|%6d", pasajero.id);
		printf("|%20s", pasajero.nombre);
		printf("|%20s", pasajero.apellido);
		printf("|%20f", pasajero.precio);
		printf("|%15s", pasajero.codigoVuelo);
		printf("|%20s", pasajero.tipoPasajero);
		printf("|%15s|\n", pasajero.estadoVuelo);
	}
}
