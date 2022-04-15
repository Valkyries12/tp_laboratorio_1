/*
 * utn.c
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */


#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0

int utn_getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos){

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo){
						*pNumeroIngresado = auxNumeroIngresado;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}


int utn_getCaracter(int * pCaracterIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	int buffer;
	int retorno;
	retorno = -1;

	if(pCaracterIngresado != NULL && mensaje != NULL && mensajeError != NULL &&  maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%d", &buffer);
			maximoDeReintentos--;

			if(buffer >= minimo && buffer <= maximo){
						*pCaracterIngresado = buffer;
						retorno = 0;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}


int utn_loguear(int * pIsLogged, int intentosMaximos) {
	char usuario;
	char contrasenia;
	int auxIsLogged;
	int codigoError;
	int intentos;
	intentos = 0;
	codigoError = -1;

	if (pIsLogged != NULL && intentosMaximos > 1) {
		printf("\n === LOGIN ===");
		while(intentos < intentosMaximos) {
			if (*pIsLogged) {
					printf("\n Usted se encuentra logueado\n");
					intentos = intentosMaximos;
					codigoError = 0;
			} else {
				printf("\nIngrese usuario: ");
				fflush(stdin);
				scanf("%c", &usuario);

				printf("\nIngrese contrasenia: ");
				fflush(stdin);
				scanf("%c", &contrasenia);

			}

			if (usuario == 'q' && contrasenia == 'q') {
				auxIsLogged = TRUE;
				printf("\n Bienvenido al sistema \n\n");
				*pIsLogged = auxIsLogged;
				intentos = intentosMaximos;
				codigoError = 0;
			} else {
				auxIsLogged = FALSE;
				*pIsLogged = auxIsLogged;
				intentos++;
				printf("\n Datos incorrectos. \n");
			}
		}
	}


	return codigoError;

}

