/*
 * Venta.c
 *
 *  Created on: 9 ago 2022
 *      Author: Nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"
#include "LinkedList.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0

Venta* new_venta() {
	Venta* pVenta;
	Venta* auxPVenta;

	auxPVenta = (Venta*) malloc(sizeof(Venta));
	if (auxPVenta != NULL) {
		pVenta = auxPVenta;
	}

	return pVenta;
}


Venta* new_ventaParametros(char* strId, char* strNombre, char* strDia, char* strHorario, char* strSala, char* strCantidadEntradas, char* strMonto) {
	//Entidad a crear para llenar con datos del archivo
	Venta* this;
	Venta* auxThis;

	this = NULL;
	auxThis = NULL;

	if (strId != NULL && strNombre != NULL && strDia != NULL && strHorario != NULL && strSala != NULL && strCantidadEntradas != NULL && strMonto != NULL) {

		auxThis = new_venta();
		if (auxThis != NULL) {
			this = auxThis;

			if (
				setId(this, atoi(strId)) == -1 ||
				setNombre(this, strNombre) == -1 ||
				setDia(this, atoi(strDia)) == -1 ||
				setHorario(this, strHorario) == -1 ||
				setSala(this, atoi(strSala)) == -1 ||
				setCantidadEntradas(this, atoi(strCantidadEntradas)) == -1 ||
				setMonto(this, atof(strMonto)) == -1
//				setCantidadEntradas(this, atoi(strCantidad_entradas)) == -1 ||  En caso de ser int
//				setMonto(this, atof(strMonto)) == -1       En caso de ser flotante el campo
			) {

				puts("\nNo se puedo crear la venta.\n");
				this = NULL;
			}
		}
	}


	return this;
}


int setId(Venta* this, int id) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		codigoError = 0;
	}

	return codigoError;
}

int getId(Venta* this, int* id) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*id = this->id;
		codigoError = 0;
	}

	return codigoError;
}


int setNombre(Venta* this, char* nombre) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		codigoError = 0;
	}

	return codigoError;
}


int getNombre(Venta* this, char* nombre) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		codigoError = 0;
	}

	return codigoError;
}


int setDia(Venta* this, int dia) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && dia > 0) {
		this->dia = dia;
		codigoError = 0;
	}

	return codigoError;
}

int getDia(Venta* this, int* dia) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*dia = this->dia;
		codigoError = 0;
	}

	return codigoError;
}


int setHorario(Venta* this, char* horario) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && horario != NULL) {
		strcpy(this->horario, horario);
		codigoError = 0;
	}

	return codigoError;
}


int getHorario(Venta* this, char* horario) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && horario != NULL) {
		strcpy(horario, this->horario);
		codigoError = 0;
	}

	return codigoError;
}


int setSala(Venta* this, int sala) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && sala > 0) {
		this->sala = sala;
		codigoError = 0;
	}

	return codigoError;
}

int getSala(Venta* this, int* sala) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*sala = this->sala;
		codigoError = 0;
	}

	return codigoError;
}


int setCantidadEntradas(Venta* this, int cantidadEntradas) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && cantidadEntradas > 0) {
		this->cantidadEntradas = cantidadEntradas;
		codigoError = 0;
	}

	return codigoError;
}

int getCantidadEntradas(Venta* this, int* cantidadEntradas) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*cantidadEntradas = this->cantidadEntradas;
		codigoError = 0;
	}

	return codigoError;
}


int setMonto(Venta* this, float monto) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && monto > -1) {
		this->monto = monto;
		codigoError = 0;
	}

	return codigoError;
}

int getMonto(Venta* this, float* monto) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*monto = this->monto;
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


int imprimirVenta(void* pEntidad) {
	int codigoError;
	int id;
	char nombre[100];
	int dia;
	char horario[50];
	int sala;
	int cantidadEntradas;
	float monto;
	Venta* pVenta;
	char diasDeLaSemana[7][50] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};


	codigoError = -1;
	if (pEntidad != NULL) {
		pVenta = (Venta*) pEntidad;

		if (
				getId(pVenta, &id) != -1 &&
				getNombre(pVenta, nombre) != -1 &&
				getDia(pVenta, &dia) != -1 &&
				getHorario(pVenta, horario) != -1 &&
				getSala(pVenta, &sala) != -1 &&
				getCantidadEntradas(pVenta, &cantidadEntradas) != -1 &&
				getMonto(pVenta, &monto) != -1
			) {

				printf("%10d", id);
				printf("%50s", nombre);
				printf("%20s", diasDeLaSemana[dia]);
				printf("%20s", horario);
				printf("%10d", sala);
				printf("%12d", cantidadEntradas);
				if (monto > 0) {
					printf("%12.2f", monto);
				}

				printf("\n");
				codigoError = 0;
			}
	}


	return codigoError;
}


int venta_guardarComoTexto(FILE* pFile, LinkedList* pArrayListVentas) {
	int codigoError;
	int len;
	Venta* pVenta;
	int id;
	char nombre[100];
	int dia;
	char horario[10];
	int sala;
	int cantidadEntradas;
	float monto;


	codigoError = -1;
	if (pArrayListVentas != NULL && pFile != NULL) {
		len = ll_len(pArrayListVentas);
		fprintf(pFile, "id,nombre,dia,horario,sala,cantidad_entradas,monto\n");

		for (int i = 0; i < len; i++) {
			pVenta = (Venta*) ll_get(pArrayListVentas, i);

			if (pVenta != NULL &&
				getId(pVenta, &id) != -1 &&
				getNombre(pVenta, nombre) != -1 &&
				getDia(pVenta, &dia) != -1 &&
				getHorario(pVenta, horario) != -1 &&
				getSala(pVenta, &sala) != -1 &&
				getCantidadEntradas(pVenta, &cantidadEntradas) != -1 &&
				getMonto(pVenta, &monto) != -1
			) {
					fprintf(pFile, "%d,%s,%d,%s,%d,%d,%.2f\n", id, nombre, dia, horario, sala, cantidadEntradas, monto);
					codigoError = 0;

			}
		}
	}

	return codigoError;
}

int calcularMonto(void* pEntidad) {
	int codigoError;
	Venta* pVenta;
	int dia;
	int cantidadEntradas;
	float monto;

	codigoError = -1;
	if (pEntidad != NULL) {
		pVenta = (Venta*) pEntidad;

		if (getDia(pVenta, &dia) != -1 && getCantidadEntradas(pVenta, &cantidadEntradas) != -1) {
			switch (dia) {
				case 1:
				case 2:
				case 3:
					monto = cantidadEntradas * 240;
					codigoError = setMonto(pVenta, monto);
					break;
				case 0:
				case 4:
				case 5:
				case 6:
					monto = cantidadEntradas * 350;
					codigoError = setMonto(pVenta, monto);
					break;
				default:
					break;
			}

			if (cantidadEntradas > 3) {
				monto = monto * 0.90;
				codigoError = setMonto(pVenta, monto);
			}
		}


	}

	return codigoError;
}


int verificarEntradasPorSala(void* pEntidad, int criterio) {
	int resultado;
	Venta* pVenta;
	int sala;
	int cantidadEntradas;

	resultado = 0;
	if (pEntidad != NULL) {
		pVenta = (Venta*) pEntidad;

		if (getSala(pVenta, &sala) != -1 && sala == criterio && getCantidadEntradas(pVenta, &cantidadEntradas) != -1) {
			resultado = cantidadEntradas;
		}
	}

	return resultado;
}


int calcularMontoTotal(void* pEntidad, int criterio) {
	int resultado;
	Venta* pVenta;
	int sala;
	float monto;

	resultado = 0;
	if (pEntidad != NULL) {
		pVenta = (Venta*) pEntidad;

		if (getSala(pVenta, &sala) != -1 && sala == criterio && getMonto(pVenta, &monto) != -1) {
			resultado = (int) monto;
		}
	}

	return resultado;
}

