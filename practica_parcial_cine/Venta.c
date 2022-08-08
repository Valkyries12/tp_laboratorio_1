/*
 * Venta.c
 *
 *  Created on: 21 jul 2022
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


Venta* new_ventaParametros(char strIdVenta[], char nombre_pelicula[], char strDia[], char horario[], char strSala[], char strCantidad_entradas[], char strMonto[]) {
	Venta* this;
	Venta* auxPVenta;

	this = NULL;

	if (strIdVenta != NULL && nombre_pelicula != NULL && strDia != NULL && horario != NULL && strSala != NULL && strCantidad_entradas != NULL && strMonto != NULL) {

		auxPVenta = new_venta();
		if (auxPVenta != NULL) {
			this = auxPVenta;

			if (
				setIdVenta(this, atoi(strIdVenta)) == -1 ||
				setNombrePelicula(this, nombre_pelicula) == -1 ||
				setDia(this, atoi(strDia)) == -1 ||
				setHorario(this, horario) == -1 ||
				setSala(this, atoi(strSala)) == -1 ||
				setCantidadEntradas(this, atoi(strCantidad_entradas)) == -1 ||
				setMonto(this, atof(strMonto)) == -1
			) {

				puts("\nNo se puedo crear la venta.\n");
				this = NULL;
			}
		}
	}


	return this;
}




int setIdVenta(Venta* this, int idVenta) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && idVenta > 0) {
		this->id_venta = idVenta;
		codigoError = 0;
	}

	return codigoError;
}

int getIdVenta(Venta* this, int* idVenta) {
	int codigoError;

	codigoError = -1;
	if (this != NULL) {
		*idVenta = this->id_venta;
		codigoError = 0;
	}

	return codigoError;
}


int setNombrePelicula(Venta* this, char* nombrePelicula) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombrePelicula != NULL) {
		strcpy(this->nombre_pelicula, nombrePelicula);
		codigoError = 0;
	}

	return codigoError;
}


int getNombrePelicula(Venta* this, char* nombrePelicula) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombrePelicula != NULL) {
		strcpy(nombrePelicula, this->nombre_pelicula);
		codigoError = 0;
	}

	return codigoError;
}


int setDia(Venta* this, int dia) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && dia > -1) {
		this->dia = dia;
		codigoError = 0;
	}

	return codigoError;
}


int getDia(Venta* this, int* pDia) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && pDia != NULL) {
		*pDia = this->dia;
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


int getHorario(Venta* this, char* pHorario) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && pHorario != NULL) {
		strcpy(pHorario, this->horario);
		codigoError = 0;
	}

	return codigoError;
}


int setSala(Venta* this, int sala) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && sala > -1) {
		this->sala = sala;
		codigoError = 0;
	}

	return codigoError;
}


int getSala(Venta* this, int* pSala) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && pSala != NULL) {
		*pSala = this->sala;
		codigoError = 0;
	}

	return codigoError;
}


int setCantidadEntradas(Venta* this, int cantidadEntradas) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && cantidadEntradas > -1) {
		this->cantidad_entradas = cantidadEntradas;
		codigoError = 0;
	}

	return codigoError;
}


int getCantidadEntradas(Venta* this, int* pCantidadEntradas) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && pCantidadEntradas != NULL) {
		*pCantidadEntradas = this->cantidad_entradas;
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


int getMonto(Venta* this, float* pMonto) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && pMonto != NULL) {
		*pMonto = this->monto;
		codigoError = 0;
	}

	return codigoError;
}



int imprimirVentas(LinkedList* pArrayListVentas) {
	int codigoError;
	int len;
	Venta* pVenta;

	codigoError = -1;
	if (pArrayListVentas != NULL) {
		len = ll_len(pArrayListVentas);

		for (int i = 0; i < len; i++) {
			pVenta = (Venta*) ll_get(pArrayListVentas, i);

			if (pVenta != NULL) {
				codigoError = imprimirVenta(pVenta);
			}

			if (codigoError != 0) {
				break;
			}
		}
	}

	return codigoError;
}


int imprimirVenta(Venta* pVenta) {
	int codigoError;
	int idVenta;
	char nombre_pelicula[100];
	int dia;
	char horario[50];
	int sala;
	int cantidad_entradas;
	float monto;
	char diasDeLaSemana[7][50] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

	codigoError = -1;
	if (pVenta != NULL &&
		getIdVenta(pVenta, &idVenta) != -1 &&
		getNombrePelicula(pVenta, nombre_pelicula) != -1 &&
		getDia(pVenta, &dia) != -1 &&
		getHorario(pVenta, horario) != -1 &&
		getSala(pVenta, &sala) != -1 &&
		getCantidadEntradas(pVenta, &cantidad_entradas) != -1 &&
		getMonto(pVenta, &monto) != -1

	) {

		printf("%10d", idVenta);
		printf("%50s", nombre_pelicula);
		printf("%20s", diasDeLaSemana[dia]);
		printf("%20s", horario);
		printf("%12d", sala);
		printf("%12d", cantidad_entradas);
		if (monto > 0) {
			printf("%20.2f", monto);
		}
		printf("\n");
		codigoError = 0;
	}

	return codigoError;
}



void venta_calcularCostos(void* venta) {
	int codigoError;
	float monto;
	float descuento;
	int dia;
	int cantidad_entradas;
	Venta* pVenta;

	codigoError = -1;
	if (venta != NULL) {

		pVenta = (Venta*) venta;
		if (getDia(pVenta, &dia) != -1 &&
			getCantidadEntradas(pVenta, &cantidad_entradas) != -1
		) {
			switch (dia) {
				case 1:
				case 2:
				case 3:
					monto = 240 * cantidad_entradas;
					if (cantidad_entradas > 2) {
						descuento = (monto * 10) / 100;
						monto = monto - descuento;
					}
					codigoError = setMonto(pVenta, monto);
					break;
				case 0:
				case 4:
				case 5:
				case 6:
					monto = 350 * cantidad_entradas;
					if (cantidad_entradas > 2) {
						descuento = (monto * 10) / 100;
						monto = monto - descuento;
					}
					codigoError = setMonto(pVenta, monto);
					break;
				default:
					break;
			}
		}


	}

//	return codigoError;
}




int venta_guardarComoTexto(FILE* pFile, LinkedList* pArrayListVentas) {
	int codigoError;
	int len;
	Venta* pVenta;
	int idVenta;
	char nombrePelicula[100];
	int dia;
	char horario[10];
	int sala;
	int cantidadEntradas;
	float monto;

	codigoError = -1;
	if (pArrayListVentas != NULL && pFile != NULL) {
		len = ll_len(pArrayListVentas);
		fprintf(pFile, "id_venta,Nombre_pelicula,dia,horario,sala,cantidad_entradas,monto\n");

		for (int i = 0; i < len; i++) {
			pVenta = (Venta*) ll_get(pArrayListVentas, i);

			if (pVenta != NULL &&
				ll_map(pArrayListVentas, venta_calcularCostos) &&
				getIdVenta(pVenta, &idVenta) != -1 &&
				getNombrePelicula(pVenta, nombrePelicula) != -1 &&
				getDia(pVenta, &dia) != -1 &&
				getHorario(pVenta, horario) != -1 &&
				getSala(pVenta, &sala) != -1 &&
				getCantidadEntradas(pVenta, &cantidadEntradas) != -1 &&
				getMonto(pVenta, &monto) != -1
			) {

					fprintf(pFile, "%d,%s,%d,%s,%d,%d,%.2f\n", idVenta, nombrePelicula, dia, horario, sala, cantidadEntradas, monto);
					codigoError = 0;

			}
		}
	}

	return codigoError;
}



int calcularEntradasVendidasPorSala(LinkedList* pArrayListVentas, int* cantidadEntradasVendidas, int sala) {
	int codigoError;
	int len;
	int salaActual;
	int cantidadEntrada;
	Venta* pVenta;

	codigoError = -1;
	if (pArrayListVentas != NULL && cantidadEntradasVendidas != NULL && sala > -1) {

		len = ll_len(pArrayListVentas);
		for (int i = 0; i < len; i++) {
			pVenta = (Venta*) ll_get(pArrayListVentas, i);
			if (pVenta != NULL && getSala(pVenta, &salaActual) != -1 && salaActual == sala) {
				codigoError = getCantidadEntradas(pVenta, &cantidadEntrada);
				*cantidadEntradasVendidas += cantidadEntrada;
			}
		}
	}

	return codigoError;
}



int imprimirInformes(int cantidadEntradasVendidas, float montoTotal, LinkedList* pArrayListPeliculas) {
	int codigoError;
	int len;
	Venta* pVenta;
	char nombrePelicula[50];

	codigoError = -1;
	if (cantidadEntradasVendidas > -1 && montoTotal > -1 && pArrayListPeliculas != NULL) {
		len = ll_len(pArrayListPeliculas);

		printf("Entradas vendidas: %d", cantidadEntradasVendidas);
		printf("\nMonto Total: %.2f $", montoTotal);
		printf("\n\n=== PELICULAS ===\n\n");

		for (int i = 0; i < len; i++) {
			pVenta = (Venta*) ll_get(pArrayListPeliculas, i);
			if (pVenta != NULL && getNombrePelicula(pVenta, nombrePelicula) != -1) {
				printf("%s\n", nombrePelicula);

			}
		}
		codigoError = 0;
	}

	return codigoError;
}



int calcularMontoTotalPorSala(LinkedList* pArrayListVenta, float* montoTotal, int sala) {
	int codigoError;
	int salaActual;
	int len;
	float montoActuall;
	Venta* pVenta;

	montoActuall = 0;
	codigoError = -1;
	if (pArrayListVenta != NULL && montoTotal != NULL && sala > -1) {

		len = ll_len(pArrayListVenta);
		for (int i = 0; i < len; i++) {
			pVenta = ll_get(pArrayListVenta, i);
			if (pVenta != NULL && getSala(pVenta, &salaActual) != -1 && salaActual == sala) {
				codigoError = getMonto(pVenta, &montoActuall);
				*montoTotal += montoActuall;
			}
		}
	}

	return codigoError;
}



int peliculasPorSala(LinkedList* pArrayListVenta, LinkedList* pArrayListPeliculas, int sala) {
	int codigoError;
	int salaActual;
	int len;
	Venta* pVenta;
	int yaPaso;
	char nombre[100];
	char nombreSegundaLista[100];
	int lenPelis;

	yaPaso = FALSE;
	codigoError = -1;
	if (pArrayListVenta != NULL && pArrayListPeliculas != NULL && sala > -1) {

		len = ll_len(pArrayListVenta);
		for (int i = 0; i < len; i++) {
			pVenta = (Venta*) ll_get(pArrayListVenta, i);
			if (pVenta != NULL && getSala(pVenta, &salaActual) != -1 && sala == salaActual) {

				if (yaPaso == FALSE && getNombrePelicula(pVenta, nombre) != -1 && ll_add(pArrayListPeliculas, pVenta) != -1) {
					yaPaso = TRUE;
				}

				lenPelis = ll_len(pArrayListPeliculas);
				//si no lo contiene lo agrego
				for (int i = 0; i < lenPelis; i++) {
					pVenta = (Venta*) ll_get(pArrayListPeliculas, i);
					if (getNombrePelicula(pVenta, nombreSegundaLista) != -1 && strcmp(nombre, nombreSegundaLista) == 0)
						ll_add(pArrayListPeliculas, pVenta);
				}
//				if (ll_contains(pArrayListPeliculas, pVenta) == 0) {
//					codigoError = ll_add(pArrayListPeliculas, pVenta);
//
//				}
			}
		}
	}

	return codigoError;
}

