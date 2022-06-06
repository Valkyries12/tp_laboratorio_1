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


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr) {
	Passenger* pasajero;
	Passenger* auxPasajero;

	pasajero = NULL;
	auxPasajero = NULL;
	//TODO -> una vez creado y pasado a pasajero . Auxpasajero hay que borrarlo con free?
	//Si libero esa direccion no me borra pasajero al ser las dos iguales?
	if (idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL) {
		auxPasajero = Passenger_new(); //creo un nuevo pasajero en memoria
		if (auxPasajero != NULL) {

			if (Passenger_setId(auxPasajero, idStr) == 0 &&
				Passenger_setNombre(auxPasajero, nombreStr) == 0 &&
				Passenger_setTipoPasajero(auxPasajero, tipoPasajeroStr) == 0) {

				pasajero = auxPasajero;
			} else {
				free(auxPasajero);
				puts("\nNo se ha podido crear al pasajero.\n");
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

	codigoError = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombre != NULL && utn_tieneSoloLetras(nombre)) {
		strcpy(this->nombre, nombre);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && apellido != NULL && utn_tieneSoloLetras(apellido)) {
		strcpy(this->apellido, apellido);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && codigoVuelo != NULL && utn_tieneSoloLetras(codigoVuelo)) {
		strcpy(this->codigoVuelo, codigoVuelo);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && tipoPasajero > -1) {
		this->tipoPasajero = tipoPasajero;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getPrecio(Passenger* this,float* precio);
