/*
 * Cachorro.c
 *
 *  Created on: 8 ago 2022
 *      Author: Nico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"
#include "LinkedList.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0

Cachorro* new_cachorro() {
	Cachorro* pCachorro;
	Cachorro* auxPCachorro;

	auxPCachorro = (Cachorro*) malloc(sizeof(Cachorro));
	if (auxPCachorro != NULL) {
		pCachorro = auxPCachorro;
	}

	return pCachorro;
}


Cachorro* new_cachorroParametros(char strId[], char strNombre[], char strDias[], char strRaza[], char strReservado[], char strGenero[]) {
	//Entidad a crear para llenar con datos del archivo
	Cachorro* this;
	Cachorro* auxThis;

	this = NULL;
	auxThis = NULL;

	if (strId != NULL && strNombre != NULL && strDias != NULL && strRaza != NULL && strReservado != NULL && strGenero != NULL) {

		auxThis = new_cachorro();
		if (auxThis != NULL) {
			this = auxThis;

			if (
				setId(this, atoi(strId)) == -1 ||
				setNombre(this, strNombre) == -1 ||
				setDias(this, atoi(strDias)) == -1 ||
				setRaza(this, strRaza) == -1 ||
				setReservado(this, strReservado) == -1 ||
				setGenero(this, strGenero) == -1
//				setCantidadEntradas(this, atoi(strCantidad_entradas)) == -1 ||  En caso de ser int
//				setMonto(this, atof(strMonto)) == -1       En caso de ser flotante el campo
			) {

				puts("\nNo se puedo crear el cachorro.\n");
				this = NULL;
			}
		}
	}


	return this;
}


int setId(Cachorro* this, int id) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		codigoError = 0;
	}

	return codigoError;
}

int getId(Cachorro* this, int* id) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*id = this->id;
		codigoError = 0;
	}

	return codigoError;
}


int setNombre(Cachorro* this, char* nombre) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		codigoError = 0;
	}

	return codigoError;
}


int getNombre(Cachorro* this, char* nombre) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		codigoError = 0;
	}

	return codigoError;
}


int setDias(Cachorro* this, int dias) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && dias > 0) {
		this->dias = dias;
		codigoError = 0;
	}

	return codigoError;
}

int getDias(Cachorro* this, int* dias) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*dias = this->dias;
		codigoError = 0;
	}

	return codigoError;
}


int setRaza(Cachorro* this, char* raza) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && raza != NULL) {
		strcpy(this->raza, raza);
		codigoError = 0;
	}

	return codigoError;
}


int getRaza(Cachorro* this, char* raza) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && raza != NULL) {
		strcpy(raza, this->raza);
		codigoError = 0;
	}

	return codigoError;
}


int setReservado(Cachorro* this, char* reservado) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && reservado != NULL) {
		strcpy(this->reservado, reservado);
		codigoError = 0;
	}

	return codigoError;
}


int getReservado(Cachorro* this, char* reservado) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && reservado != NULL) {
		strcpy(reservado, this->reservado);
		codigoError = 0;
	}

	return codigoError;
}


int setGenero(Cachorro* this, char* genero) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && genero != NULL) {
		strcpy(this->genero, genero);
		codigoError = 0;
	}

	return codigoError;
}


int getGenero(Cachorro* this, char* genero) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && genero != NULL) {
		strcpy(genero, this->genero);
		codigoError = 0;
	}

	return codigoError;
}


int imprimirEntidades(LinkedList* pArrayList, int (*pFunc)(void* pEntidad)) {
	//Itera por una lista generica y llama a imprimir + entidad especifica por pFunc
	int codigoError;
	int len;
	void* pEntidad;

	codigoError = -1;
	if (pArrayList != NULL && pFunc != NULL) {
		len = ll_len(pArrayList);

		for (int i = 0; i < len; i++) {
			pEntidad =  ll_get(pArrayList, i);

			if (pEntidad != NULL) {
				codigoError = pFunc(pEntidad);
			}

			if (codigoError != 0) {
				break;
			}
		}
	}

	return codigoError;
}


int imprimirCachorro(void* pEntidad) {
	int codigoError;
	int id;
	char nombre[100];
	int dias;
	char raza[50];
	char reservado[50];
	char genero[50];
	Cachorro* pCachorro;


	codigoError = -1;
	if (pEntidad != NULL) {
		pCachorro = (Cachorro*) pEntidad;

		if (
				getId(pCachorro, &id) != -1 &&
				getNombre(pCachorro, nombre) != -1 &&
				getDias(pCachorro, &dias) != -1 &&
				getRaza(pCachorro, raza) != -1 &&
				getReservado(pCachorro, reservado) != -1 &&
				getGenero(pCachorro, genero) != -1
			) {

				printf("%10d", id);
				printf("%50s", nombre);
				printf("%20d", dias);
				printf("%20s", raza);
				printf("%10s", reservado);
				printf("%12s", genero);
				printf("\n");
				codigoError = 0;
			}
	}


	return codigoError;
}


int cachorro_guardarComoTexto(FILE* pFile, LinkedList* pArrayListCachorros) {
	int codigoError;
	int len;
	Cachorro* pCachorro;
	int id;
	char nombre[100];
	int dias;
	char raza[10];
	char reservado[50];
	char genero[50];


	codigoError = -1;
	if (pArrayListCachorros != NULL && pFile != NULL) {
		len = ll_len(pArrayListCachorros);
		fprintf(pFile, "id,nombre,dias,raza,reservado,genero\n");

		for (int i = 0; i < len; i++) {
			pCachorro = (Cachorro*) ll_get(pArrayListCachorros, i);

			if (pCachorro != NULL &&
				getId(pCachorro, &id) != -1 &&
				getNombre(pCachorro, nombre) != -1 &&
				getDias(pCachorro, &dias) != -1 &&
				getRaza(pCachorro, raza) != -1 &&
				getReservado(pCachorro, reservado) != -1 &&
				getGenero(pCachorro, genero) != -1
			) {
					fprintf(pFile, "%d,%s,%d,%s,%s,%s\n", id, nombre, dias, raza, reservado, genero);
					codigoError = 0;

			}
		}
	}

	return codigoError;
}



int cachorro_esMayor45Dias(void* pEntidad) {
	int esMayor;
	int dias;
	Cachorro* pCachorro;

	esMayor = FALSE;
	if (pEntidad != NULL) {
		pCachorro = (Cachorro*) pEntidad;

		if (getDias(pCachorro, &dias) != -1 && dias > 44) {
			esMayor = TRUE;
		}
	}

	return esMayor;
}


int cachorro_esHembra(void* pEntidad) {
	int esHembra;
	char genero[50];
	Cachorro* pCachorro;

	esHembra = FALSE;
	if (pEntidad != NULL) {
		pCachorro = (Cachorro*) pEntidad;

		if (getGenero(pCachorro, genero) != -1 && strcmp(genero, "H") == 0) {
			esHembra = TRUE;
		}
	}

	return esHembra;
}


int cachorro_esCallejero(void* pEntidad) {
	int esCallejero;
	char raza[50];
	Cachorro* pCachorro;

	esCallejero = FALSE;
	if (pEntidad != NULL) {
		pCachorro = (Cachorro*) pEntidad;

		if (getRaza(pCachorro, raza) != -1 && strcmp(raza, "Callejero") == 0) {
			esCallejero = TRUE;
		}
	}

	return esCallejero;
}



