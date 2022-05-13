/*
 * pasajero.h
 *
 *  Created on: 10 may 2022
 *      Author: Nicolás Caruso
 */

#ifndef PASAJERO_H_
#define PASAJERO_H_
#define TRUE 1
#define FALSE 0

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int isEmpty;
}Pasajero;



#endif /* PASAJERO_H_ */
