/*
 * aerolineas.c
 *
 *  Created on: 15 abr 2022
 *      Author: Nicolás Caruso
 */
#include <stdio.h>
#include <stdlib.h>
#include "aerolineas.h"
#include "utn.h"

void imprimirInformeDeCostos(char * nombreAerolinea, float precio, float precioConDescuento, float precioConInteres, float precioBTC, float precioUnitario) {
	printf("\nPrecio %s: $%.2f", nombreAerolinea, precio);
	printf("\na) Precio con tarjeta de débito: $%.2f", precioConDescuento);
	printf("\nb) Precio con tarjeta de crédito: $%.2f", precioConInteres);
	printf("\nc) Precio pagado con Bitcoins: %.8f BTC", precioBTC);
	printf("\nd) Mostrar precio unitario: $%.2f \n\n", precioUnitario);
}


void imprimirMenu(float kilometros, float precioAerolinea, float precioLatam) {

	printf("\n1. Ingresar kilómetros  (km= %.2f)", kilometros);
	printf("\n2. Ingresar precios de vuelos (aerolíneas= %.2f  latam= %.2f)", precioAerolinea, precioLatam);
	printf("\n3. Calcular todos los costos.");
	printf("\n4. Informar resultados.");
	printf("\n5. Carga forzada de datos.");
	printf("\n6. Salir.");
}



int hacerCargaForzada() {
	int codigoError;
	float kilometros;
	float precioAerolinea;
	float precioLatam;
	float precioDebitoAerolinea;
	float precioDebitoLatam;
	float precioCreditoAerolinea;
	float precioCreditoLatam;
	float precioBTCaerolinea;
	float precioBTCLatam;
	float precioUnitarioAerolinea;
	float precioUnitarioLatam;
	float diferenciaDePrecios;

	precioAerolinea = 162965;
	precioLatam = 159339;
	kilometros = 7090;
	codigoError = -1;
	if ( utn_hacerDescuento(precioAerolinea, 10, &precioDebitoAerolinea) != -1 &&
		 utn_hacerDescuento(precioLatam, 10, &precioDebitoLatam) != -1 &&
		 utn_sumarInteres(precioAerolinea, 25, &precioCreditoAerolinea) != -1 &&
		 utn_sumarInteres(precioLatam, 25, &precioCreditoLatam) != -1 &&
		 utn_calcularPrecio(precioAerolinea, 2607609.47, &precioBTCaerolinea) != -1 &&
		 utn_calcularPrecio(precioLatam, 2607609.47, &precioBTCLatam) != -1 &&
		 utn_calcularPrecio(kilometros, precioAerolinea, &precioUnitarioAerolinea) != -1 &&
		 utn_calcularPrecio(kilometros, precioLatam, &precioUnitarioLatam) != -1 &&
		 utn_restarNumeroFlotante(precioAerolinea, precioLatam, &diferenciaDePrecios) != -1
		)
	{
		printf("\nKMs ingresados: %.2f km \n", kilometros);
		//aerolineas
		imprimirInformeDeCostos("Aerolineas", precioAerolinea, precioDebitoAerolinea, precioCreditoAerolinea, precioBTCaerolinea, precioUnitarioAerolinea);

		//latam
		imprimirInformeDeCostos("Latam", precioLatam, precioDebitoLatam, precioCreditoLatam, precioBTCLatam, precioUnitarioLatam);
		codigoError = 0;
	}


	return codigoError;
}
