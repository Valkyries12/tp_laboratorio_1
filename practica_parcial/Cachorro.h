/*
 * Cachorro.h
 *
 *  Created on: 8 ago 2022
 *      Author: Nico
 */

#ifndef CACHORRO_H_
#define CACHORRO_H_

#include "LinkedList.h"


typedef struct {
	int id;
	char nombre[50];
	int dias;
	char raza[50];
	char reservado[50];
	char genero[50];
}Cachorro;



Cachorro* new_cachorro();

Cachorro* new_cachorroParametros(char* strId, char* strNombre, char* strDias, char* strRaza, char* strReservado, char* strGenero);
#endif /* CACHORRO_H_ */


int setId(Cachorro* this, int id);
int getId(Cachorro* this, int* id);

int setNombre(Cachorro* this, char* nombre);
int getNombre(Cachorro* this, char* nombre);

int setDias(Cachorro* this, int dias);
int getDias(Cachorro* this, int* dias);

int setRaza(Cachorro* this, char* raza);
int getRaza(Cachorro* this, char* raza);

int setReservado(Cachorro* this, char* reservado);
int getReservado(Cachorro* this, char* reservado);

int setGenero(Cachorro* this, char* genero);
int getGenero(Cachorro* this, char* genero);

int imprimirCachorro(void* pEntidad);

int cachorro_guardarComoTexto(FILE* pFile, LinkedList* pArrayListCachorros);

int cachorro_esMayor45Dias(void* pEntidad);

int cachorro_esHembra(void* pEntidad);

int cachorro_esCallejero(void* pEntidad);
