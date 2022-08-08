/*
 * utn.c
 *
 *  Created on: 20 jul 2022
 *      Author: Nico
 */


/*
 * utn.c
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"

#define TRUE 1
#define FALSE 0

int utn_getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos){

	char buffer[64];
	int auxNumeroIngresado;
	int codigoError;
	codigoError = -1;


	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			maximoDeReintentos--;
			printf("%s", mensaje);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer)-1] = '\0';
			if (utn_esNumerico(buffer)) {
				auxNumeroIngresado = atoi(buffer);
				if(auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) {
					*pNumeroIngresado = auxNumeroIngresado;
					codigoError = 0;
					break;

				}else{
					printf("%s", mensajeError);
				}
//				fflush(stdin);
			} else{
				printf("%s", mensajeError);
			}


		}while(maximoDeReintentos > 0);
	}

	return codigoError;
}



int utn_getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, float maximo, float minimo, int maximoDeReintentos){

	float auxNumeroIngresado;
	char buffer[250];
	int retorno;

	retorno = -1;

	if(pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos>= 0){
		do{
			printf("%s", mensaje);

			maximoDeReintentos--;
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer)-1] = '\0';

			if (utn_esNumerico(buffer)) {
				auxNumeroIngresado = atof(buffer);
			}

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

			if(sizeof(buffer) >= minimo && sizeof(buffer) <= maximo){
						*pCaracterIngresado = buffer;
						retorno = 0;
						break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}



int utn_getString(char * stringAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int lenMinima, int lenMaxima) {
	int codigoError;
	char buffer[255];

	codigoError = -1;
	if(stringAIngresar != NULL && mensaje != NULL && mensajeError != NULL && maximoReintentos >= 0 && lenMaxima > 0 && lenMinima > 0) {

		do {
			maximoReintentos--;
			printf("%s", mensaje);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer)-1] = '\0';
			if (utn_tieneSoloLetras(buffer) && strlen(buffer) >= lenMinima && strlen(buffer) <= lenMaxima) {
				strcpy(stringAIngresar, buffer);
				codigoError = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}
		} while(maximoReintentos > 0);


	}



	return codigoError;
}


int utn_getStringConEspeciales(char * stringAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int lenMinima, int lenMaxima) {
	int codigoError;
	char buffer[255];

	codigoError = -1;
	if(stringAIngresar != NULL && mensaje != NULL && mensajeError != NULL && maximoReintentos >= 0 && lenMaxima > 0 && lenMinima > 0) {

		do {
			maximoReintentos--;
			printf("%s", mensaje);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer)-1] = '\0';
			if (strlen(buffer) >= lenMinima && strlen(buffer) <= lenMaxima) {
				strcpy(stringAIngresar, buffer);
				codigoError = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}
		} while(maximoReintentos > 0);


	}



	return codigoError;
}


int utn_getStringConNumero(char * stringAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int lenMinima, int lenMaxima) {
	int codigoError;
	char buffer[255];

	codigoError = -1;
	if(stringAIngresar != NULL && mensaje != NULL && mensajeError != NULL && maximoReintentos >= 0 && lenMaxima > 0 && lenMinima > 0) {

		do {
			maximoReintentos--;
			printf("%s", mensaje);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer)-1] = '\0';
			if (utn_tieneLetrasYNumeros(buffer) && strlen(buffer) >= lenMinima && strlen(buffer) <= lenMaxima) {
				strcpy(stringAIngresar, buffer);
				codigoError = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}
		} while(maximoReintentos > 0);


	}



	return codigoError;
}



int utn_getTelefono(char * telefonoAIngresar, char * mensaje, char * mensajeError, int maximoReintentos, int len) {
	int codigoError;
	char buffer[len+1];


	codigoError = -1;
	if (telefonoAIngresar != NULL && mensaje != NULL && mensajeError != NULL && maximoReintentos > 0 && len > 0) {
		do {
			maximoReintentos--;
			printf("%s", mensaje);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer)] = '\0';

			if (utn_esNumerico(buffer)) {
				strncpy(telefonoAIngresar, buffer, len);
				codigoError = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}

		} while(maximoReintentos > 0);
	}

	return codigoError;
}


int utn_getDocumento(int * numeroDocumento, char * mensaje, char * mensajeError, int maximoReintentos ) {
	int codigoError;
	char buffer[50];
	int auxNumeroDocumento;

	codigoError = -1;
	if (numeroDocumento != NULL && mensaje != NULL && mensajeError!= NULL && maximoReintentos > 0) {
		do {
			maximoReintentos--;
			printf("%s", mensaje);
			fgets(buffer, sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';

			if (utn_esNumerico(buffer) && strlen(buffer) == 8) {
//				strncpy(numeroDocumento, buffer, len+1);
				auxNumeroDocumento = atoi(buffer);
				* numeroDocumento = auxNumeroDocumento;
				codigoError = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}

		} while(maximoReintentos > 0);
	}


	return codigoError;
}



int utn_getMail(char * mailAIngresar, char * mensaje, char * mensajeError, int maximoReintentos) {
	int codigoError;
	char buffer[250];
	int qtyArroba;
	int qtyGuionMedio;
	int qtyGuionBajo;
	int qtyPunto;
	int i;

	qtyArroba = 0;
	qtyGuionBajo = 0;
	qtyGuionMedio = 0;
	qtyPunto = 0;
	i = 0;
	codigoError = -1;
	if (mailAIngresar != NULL && mensaje != NULL && mensajeError != NULL && maximoReintentos > 0) {
		do {
			maximoReintentos--;
			printf("%s", mensaje);
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer)-1] = '\0';

			while(buffer[i] != '\0') {
				switch (buffer[i]) {
					case '@':
						qtyArroba++;
						break;
					case '_':
						qtyGuionBajo++;
						break;
					case '-':
						qtyGuionMedio++;
						break;
					case '.':
						qtyPunto++;
						break;

				}
				i++;
			}


			if (qtyArroba == 1 && qtyPunto == 1 && qtyGuionBajo >= 0 && qtyGuionMedio >= 0) {
				strncpy(mailAIngresar, buffer, sizeof(buffer));
				codigoError = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}


		} while(maximoReintentos > 0);
	}

	return codigoError;
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



int utn_contarPositivos(int arr[], int * cantidadPositivos, int longitudArray) {
	int contador;
	int codigoError;
	contador = 0;
	codigoError = -1;

	if(arr != NULL && cantidadPositivos != NULL && longitudArray > 1) {
		for(int i = 0; i < longitudArray; i++) {
			if(arr[i] > 0) {
				contador++;
			}
		}
		codigoError = 0;
	}

	if(codigoError == 0) {
		* cantidadPositivos = contador;
	}

	return codigoError;
}

int utn_contarNegativos(int arr[], int * cantidadNegativos, int longitudArray) {
	int contador;
	int codigoError;
	contador = 0;
	codigoError = -1;

	if(arr != NULL && cantidadNegativos != NULL && longitudArray > 1) {
		for(int i = 0; i < longitudArray; i++) {
			if(arr[i] < 0) {
				contador++;
			}
		}
		codigoError = 0;
	}

	if(codigoError == 0) {
		* cantidadNegativos = contador;
	}

	return codigoError;
}


int utn_inicializarArrayDeEnteros(int arr[], int len, int valorInicial) {
	int codigoError;
	codigoError = -1;

	if (len > 0) {
		for(int i = 0; i < len ; i++) {
			arr[i] = valorInicial;
		}
		codigoError = 0;
	}

	return codigoError;
}


int utn_inicializarArrayDeFloats(float arr[], int len, float valorInicial) {
	int codigoError;
	codigoError = -1;

	if (len > 0) {
		for(int i = 0; i < len ; i++) {
			arr[i] = valorInicial;
		}
		codigoError = 0;
	}

	return codigoError;
}





int utn_sumarEnterosParesDelArray(int arr[], int len, int * resultadoSuma) {
	int codigoError;
	int resultado;

	resultado = 0;
	codigoError = -1;
	if (arr != NULL  && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i] % 2 == 0) {
				resultado += arr[i];
			}
		}
		* resultadoSuma = resultado;
		codigoError = 0;
	}


	return codigoError;
}



int utn_calcularEnteroMayorImpar(int arr[], int len, int * mayorImpar) {
	int codigoError;
	int mayor;

	mayor = arr[0];
	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i] >= mayor) {
				mayor = arr[i];
			}
		}

		* mayorImpar = mayor;
		codigoError = 0;
	}


	return codigoError;
}


int utn_imprimirEnterosArray(int arr[], int len) {
	int codigoError;

	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			printf("\n%d", arr[i]);
		}
		codigoError = 0;
	}


	return codigoError;
}



int utn_imprimirEnterosParesArray(int arr[], int len) {
	int codigoError;

	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (arr[i] % 2 == 0) {
				printf("\n%d", arr[i]);
			}
		}
		codigoError = 0;
	}

	return codigoError;
}



int utn_imprimirEnterosDePosicionesImparesArray(int arr[],int len) {
	int codigoError;

	codigoError = -1;
	if (arr != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if (i % 2 != 0) {
				printf("\n%d", arr[i]);
			}
		}
		codigoError = 0;
	}

	return codigoError;
}


int utn_cargarEnteroEnIndiceAleatorio(int arr[], int len, int valor , int indice) {
	int codigoError;

	codigoError = -1;

	if (arr != NULL && len > 0 && indice > -1) {
		if (arr[indice] > -1) {
			arr[indice] = valor;
			codigoError = 0;
		}

	}

	return codigoError;

}



int utn_cargarFlotanteEnIndiceAleatorio(float arr[], int len, float valor , int indice) {
	int codigoError;

	codigoError = -1;

	if (arr != NULL && len > 0 && indice > -1) {
		if (arr[indice] > -1) {
			arr[indice] = valor;
			codigoError = 0;
		}

	}

	return codigoError;

}


int utn_calcularMenorEntero(int arr[], int len, int * pMenor, char tipo) {
	int codigoError;
	int menor;
	int bandera;

	codigoError = -1;
	menor = arr[0];
	bandera = FALSE;

	if (arr != NULL && len > 0 && pMenor != NULL) {
		for(int i = 0; i < len; i++) {
			switch (tipo) {
				case '+':
					if (arr[i] >= 0 && arr[i] <= menor) {
						menor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '-':
					if (arr[i] < 0 && arr[i] <= menor) {
						menor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '=':
					if (arr[i] <= menor) {
						menor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				default:
					puts("\nTipo operador inválido, solo + - =");
					break;
			}
		}
		if (bandera) {
			*pMenor = menor;
			codigoError = 0;
		}
	}

	return codigoError;
}



int utn_calcularMayorEntero(int arr[], int len, int * pMayor, char tipo) {
	int codigoError;
	int mayor;
	int bandera;

	codigoError = -1;
	mayor = arr[0];
	bandera = FALSE;

	if (arr != NULL && len > 0 && pMayor != NULL) {
		for(int i = 0; i < len; i++) {
			switch (tipo) {
				case '+':
					if (arr[i] >= 0 && arr[i] >= mayor) {
						mayor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '-':
					if (arr[i] < 0 && arr[i] >= mayor) {
						mayor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				case '=':
					if (arr[i] >= mayor) {
						mayor = arr[i];
						if (!bandera) {
							bandera = TRUE;
						}
					}
					break;
				default:
					puts("\nTipo operador inválido, solo + - =");
					break;
			}
		}
		if (bandera) {
			*pMayor = mayor;
			codigoError = 0;
		}
	}

	return codigoError;
}



int utn_ordenarArrayMenorAMayor(int arr[], int len) {
	int codigoError;
	int estaOrdenado;
	int aux;

	codigoError = -1;


	if (arr != NULL && len > 0) {

		do{
			estaOrdenado = TRUE;
			len--;
			for(int i = 0; i < len; i++) {
				if (arr[i] > arr[i+1]){
					aux = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = aux;
					estaOrdenado = FALSE;
				}
			}
		} while(!estaOrdenado);
		codigoError = 0;
	}


	return codigoError;
}



int utn_ordenarArrayMayorAMenor(int arr[], int len) {
	int codigoError;
	int estaOrdenado;
	int aux;

	codigoError = -1;


	if (arr != NULL && len > 0) {

		do{
			estaOrdenado = TRUE;
			len--;
			for(int i = 0; i < len; i++) {
				if (arr[i] < arr[i+1]){
					aux = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = aux;
					estaOrdenado = FALSE;
				}
			}
		} while(!estaOrdenado);
		codigoError = 0;
	}


	return codigoError;
}



int utn_imprimirString(char arr[]) {
	int codigoError;
	int i;

	i = 0;
	codigoError = -1;
	if (arr != NULL) {
		while(arr[i] != '\0') {
			printf("%c", arr[i]);
			i++;
		}
		codigoError = 0;
	}


	return codigoError;
}


int utn_tieneSoloLetras(char arr[]) {
	int hasLetters;
	int i;

	i = 0;
	hasLetters = TRUE;
	if (arr != NULL) {
		while(arr[i] != '\0') {
			if(!((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))) {
				hasLetters = FALSE;
				break;
			}
			i++;
		}
	}

	return hasLetters;
}


int utn_tieneLetrasYNumeros(char arr[]) {
	int hasLettersAndNumber;
	int i;

	i = 0;
	hasLettersAndNumber = TRUE;
	if (arr != NULL) {
		while(arr[i] != '\0') {
			if(utn_tieneCaracteresEspeciales(arr)) {
				hasLettersAndNumber = FALSE;
				break;
			}
			i++;
		}
	}

	return hasLettersAndNumber;
}


int utn_tieneCaracteresEspeciales(char arr[]){
   int i;
   int tieneCaracterEspecial = FALSE;
   for (i = 0; i < strlen(arr); ++i){
      if(arr[i] == '!' || arr[i] == '@' || arr[i] == '#' || arr[i] == '$'
      || arr[i] == '%' || arr[i] == '^' || arr[i] == '&' || arr[i] == '*'
      || arr[i] == '(' || arr[i] == ')' || arr[i] == '-' || arr[i] == '{'
      || arr[i] == '}' || arr[i] == '[' || arr[i] == ']' || arr[i] == ':'
      || arr[i] == ';' || arr[i] == '"' || arr[i] == '\'' || arr[i] == '<'
      || arr[i] == '>' || arr[i] == '.' || arr[i] == '/' || arr[i] == '?'
      || arr[i] == '~' || arr[i] == '`' ){
         printf("String is not allowed\n");
         tieneCaracterEspecial = TRUE;
         break;
      }
   }

   return tieneCaracterEspecial;
}



//int utn_ftoa(float numero, char* arr) {
//	int codigoError;
//
//	codigoError = -1;
//
//	if (numero > 0 && arr != NULL) {
//
//	}
//
//	return codigoError;
//}



int utn_esNumerico(char arr[]){
	int hasNumbers;
	int i;
	int contadorPunto;

	contadorPunto = 0;
	i = 0;
	hasNumbers = TRUE;

	if (arr != NULL) {
		while(arr[i] != '\0') {
			if (arr[i] < '0' || arr[i] > '9') {
				if (arr[i] == '.' && arr[0] != '.') {
					contadorPunto++;
				}
				hasNumbers = FALSE;
				break;
			}
			i++;
		}
		if (contadorPunto == 1) {
			hasNumbers = TRUE;
		}

	}

	return hasNumbers;
}



int utn_convertirAMayuscula(char * string) {
	int codigoError;

	codigoError = -1;
	if (string != NULL) {
		for(int i = 0; i < strlen(string); i++) {
			string[i] = toupper(string[i]);
		}
	}

	return codigoError;
}



int utn_resizeIntArray(int** arr, int* len, int nuevaLen) {
	int codigoError;
	int* pArrTemp = NULL;

	codigoError = -1;
	if (arr != NULL && len != NULL && nuevaLen > 0) {
		pArrTemp = (int*) realloc(*arr, sizeof(int) * nuevaLen);

		if (pArrTemp != NULL) {
			*len = nuevaLen;
			*arr = pArrTemp;
			codigoError = 0;
		}
	}

	return codigoError;

}



int utn_resizeCharArray(char** arr, int* len, int nuevaLen) {
	int codigoError;
	char *pArrTemp = NULL;

	codigoError = -1;
	if (arr != NULL && len != NULL && nuevaLen > 0) {
		pArrTemp = (char*)realloc(*arr, sizeof(char) * nuevaLen);

		if (pArrTemp != NULL) {
			*len = nuevaLen;
			*arr = pArrTemp;
			codigoError = 0;
		}
	}

	return codigoError;
}



//int utn_resizeFloatArray(float** arr, int* len, int nuevaLen) {
//	int codigoError;
//	float pArrTemp;
//
//	codigoError = -1;
//	pArrTemp = NULL;
//
//	if (arr != NULL && len != NULL && nuevaLen > 0) {
//		pArrTemp = (float*) realloc(*arr, sizeof(float) * nuevaLen);
//
//		if (pArrTemp != NULL) {
//			*len = nuevaLen;
//			*arr = pArrTemp;
//			codigoError = 0;
//		}
//	}
//
//	return codigoError;
//}



int utn_removeIntFromArr(int *arr, int len, int numeroABorrar) {
	int codigoError;

	codigoError = -1;

	if (arr != NULL && len > 0 && numeroABorrar > 0) {
		for(int i = 0; i < len; i++) {
			printf("%d\n", *(arr+i));
		}
	}

	return codigoError;
}



int* utn_newEntero(int size) {
	int* espacioMemoriaInt;
	int* aux;

	if (size > 0) {
		aux = (int*) malloc(sizeof(int) * size);

		if (aux != NULL) {
			for(int i = 0; i < size; i++) {
				utn_getInt(aux+i, "\nIngrese un número: ", "\nSólo se permiten números entre el 1 y el 1000.\n", 1000, 1, 3);

			}
			espacioMemoriaInt = aux;
		}
	} else {
		printf("\nNo se ha podido asignar el espacio en memoria.\n");
	}

	return espacioMemoriaInt;
}




void utn_imprimirpEntero(int* pEntero, int len) {

	if (pEntero != NULL) {
		for(int i = 0; i < len; i++) {
			printf("%d\n", *(pEntero + i));
		}
	}
}



int utn_diasDeLaSemanaToStr(int dia) {
	int codigoError;

	codigoError = -1;
	if (dia > -1) {
		switch (dia) {
			case 0:
				puts("Domingo");
				break;
			case 1:
				puts("Lunes");
				break;
			case 2:
				puts("Martes");
				break;
			case 3:
				puts("Miercoles");
				break;
			case 4:
				puts("Jueves");
				break;
			case 5:
				puts("Viernes");
				break;
			case 6:
				puts("Sabado");
				break;
			default:
				break;
		}

		codigoError = 0;
	}

	return codigoError;
}



