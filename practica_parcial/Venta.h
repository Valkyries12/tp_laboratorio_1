/*
 * Venta.h
 *
 *  Created on: 20 jul 2022
 *      Author: Nico
 */

#include "LinkedList.h"

#ifndef VENTA_H_
#define VENTA_H_

typedef struct {
	int id_venta;
	char nombre_pelicula[100];
	int dia;
	char horario[10];
	int sala;
	int cantidad_entradas;
	float monto;
}Venta;



Venta* new_venta();

Venta* new_ventaParametros(char* strIdVenta, char* nombre_pelicula, char* strDia, char* horario, char* strSala, char* strCantidad_entradas, char* strMonto);


int setIdVenta(Venta* this, int idVenta);
int getIdVenta(Venta* this, int* idVenta);

int setNombrePelicula(Venta* this, char* nombrePelicula);
int getNombrePelicula(Venta* this, char* nombrePelicula);

int setDia(Venta* this, int dia);
int getDia(Venta* this, int* pDia);

int setHorario(Venta* this, char* horario);
int getHorario(Venta* this, char* pHorario);

int setSala(Venta* this, int sala);
int getSala(Venta* this, int* pSala);

int setCantidadEntradas(Venta* this, int cantidadEntradas);
int getCantidadEntradas(Venta* this, int* pCantidadEntradas);

int setMonto(Venta* this, float monto);
int getMonto(Venta* this, float* pMonto);


int imprimirVenta(Venta* pVenta);
int imprimirVentas(LinkedList* pArrayListVentas);



int venta_guardarComoTexto(FILE* pFile, LinkedList* pArrayListVentas);

void venta_calcularCostos(void* venta);

int calcularEntradasVendidasPorSala(LinkedList* pArrayListVentas, int* cantidadEntradasVendidas, int sala);

int imprimirInformes(int cantidadEntradasVendidas, float montoTotal, LinkedList* pArrayListPeliculas);

int calcularMontoTotalPorSala(LinkedList* pArrayListVenta, float* montoTotal, int sala);

int peliculasPorSala(LinkedList* pArrayListVenta, LinkedList* pArrayListPeliculas, int sala);


#endif /* VENTA_H_ */
