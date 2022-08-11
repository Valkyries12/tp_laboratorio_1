/*
 * Venta.h
 *
 *  Created on: 9 ago 2022
 *      Author: Nico
 */

#ifndef VENTA_H_
#define VENTA_H_

#include "LinkedList.h"


typedef struct {
	int id;
	char nombre[50];
	int dia;
	char horario[50];
	int sala;
	int cantidadEntradas;
	float monto;
}Venta;



Venta* new_venta();

Venta* new_ventaParametros(char* strId, char* strNombre, char* strDia, char* strHorario, char* strSala, char* strCantidadEntradas, char* strMonto);


int setId(Venta* this, int id);
int getId(Venta* this, int* id);

int setNombre(Venta* this, char* nombre);
int getNombre(Venta* this, char* nombre);

int setDia(Venta* this, int dia);
int getDia(Venta* this, int* dia);

int setHorario(Venta* this, char* horario);
int getHorario(Venta* this, char* horario);

int setSala(Venta* this, int sala);
int getSala(Venta* this, int* sala);

int setCantidadEntradas(Venta* this, int cantidadEntradas);
int getCantidadEntradas(Venta* this, int* cantidadEntradas);

int setMonto(Venta* this, float monto);
int getMonto(Venta* this, float* monto);

int imprimirVenta(void* pEntidad);

int venta_guardarComoTexto(FILE* pFile, LinkedList* pArrayListVentas);

int calcularMonto(void* pEntidad);

int verificarEntradasPorSala(void* pEntidad, int criterio);

int calcularMontoTotal(void* pEntidad, int criterio);
#endif /* VENTA_H_ */
