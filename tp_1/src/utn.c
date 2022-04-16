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



int utn_getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, float maximo, float minimo, int maximoDeReintentos){

	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
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

int utn_getCaracter(char * pCaracterIngresado,char * mensaje,char * mensajeError,
		int maximo, int minimo, int maximoDeReintentos){

	char buffer;
	int retorno;
	retorno = -1;

	if(pCaracterIngresado != NULL && mensaje != NULL && mensajeError != NULL &&  maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &buffer);
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


int utn_hacerDescuento(float monto, int descuento, float * pValorFinal) {
	int codigoError;
	float auxPValorFinal;
	float resultado;
	codigoError = -1;

	if (pValorFinal != NULL && descuento > 0 && monto > 0) {
		resultado = (monto * descuento) / 100;
		resultado = monto - resultado;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}

	return codigoError;
}


int utn_sumarInteres(float monto, int interes, float * pValorFinal) {
	int codigoError;
	float auxPValorFinal;
	float resultado;
	codigoError = -1;

	if (pValorFinal != NULL && interes > 0 && monto > 0) {
		resultado = (monto * interes) / 100;
		resultado = monto + resultado;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}


	return codigoError;
}


void utn_verificarSiHayError(int respuesta, int * pHayError) {
	int auxRespuesta;
	auxRespuesta = respuesta;
	* pHayError = auxRespuesta;


}


void utn_imprimirMensajes(int  hayError, char * mensaje, char * mensajeError) {
	if (mensaje != NULL && mensajeError != NULL) {
		if (hayError == 0) {
			printf("%s", mensaje);
		} else {
			if (hayError == -1)
			printf("%s", mensajeError);
		}
	}

}


int utn_calcularAPrecioBitcoin(float monto, float precioBitcoin, float * pValorFinal) {
	int codigoError;
	float resultado;
	float auxPValorFinal;

	codigoError = -1;

	if ( pValorFinal != NULL && monto > 0 && precioBitcoin > 0) {
		resultado = monto / precioBitcoin;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}


	return codigoError;

}


int utn_calcularPrecioPorKilometro(int kilometro, float precio, float * pValorFinal) {
	int codigoError;
	float resultado;
	float auxPValorFinal;

	codigoError = -1;

	if (pValorFinal != NULL && kilometro > 349 && precio > 5099.26) {
		resultado = precio / kilometro;
		auxPValorFinal = resultado;
		* pValorFinal = auxPValorFinal;
		codigoError = 0;
	}


	return codigoError;
}


