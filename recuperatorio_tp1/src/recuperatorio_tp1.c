/*
 ============================================================================
 Name        : recuperatorio_tp1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "aerolineas.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout, NULL);
	int codigoError;
	int opcionMenu;
	float kilometros;
	float precioAerolinea;
	float precioLatam;
	float precioDebitoAerolinea;
	float precioDebitoLatam;
	float precioCreditoAeroline;
	float precioCreditoLatam;
	float precioBTCAerolinea;
	float precioBTCLatam;
	float precioUnitarioAerolinea;
	float precioUnitarioLatam;
	float diferenciaDePrecios;
	int estaCalculado;

	kilometros = 0;
	precioAerolinea = 0;
	precioLatam = 0;
	estaCalculado = FALSE;


	puts("=== INICIO DEL PROGRAMA ===\n");

	do {
		imprimirMenu(kilometros, precioAerolinea, precioLatam);
		codigoError = utn_getInt(&opcionMenu, "\n\nPor favor ingresa una opción: ", "\nOpción inválida. Reintente.\n", 6, 1, 3);

		switch (opcionMenu) {
			case 1:
				puts("\n=== INGRESO DE KILOMETRAJE\n");
				codigoError = utn_getFloat(&kilometros, "Ingrese kilómetros: ", "\nError. Sólo se permiten valores entre 300 50000.\n", 50000, 300, 3);
				utn_imprimirMensajes(codigoError, "\nSe han ingresado los kilómetros satisfactoriamente.\n", "\nHa ocurrido un error al ingresar los kilómetros.\n");
				break;
			case 2:
				if (kilometros > 0) {
					puts("\n=== INGRESO DE PRECIOS ===\n");
					codigoError = -1;
					if (utn_getFloat(&precioAerolinea, "\nIngrese el precio de aerolineas: ", "\nError. Sólo números entre 4500 y 250000.\n", 250000, 4500, 3) != -1 &&
						utn_getFloat(&precioLatam, "\nIngrese el precio de Latam: ", "\nError. Sólo números entre 4500 y 250000.\n", 250000, 4500, 3) != -1	)
					{
						codigoError = 0;
					}

					utn_imprimirMensajes(codigoError, "\nPrecios ingresados satisfactoriamente.\n", "\nHa ocurrido un error al ingresar los precios.\n");
				} else {
					puts("\nDebe ingresar el kilometraje antes del precio.\n");
				}
				break;
			case 3:
				if (kilometros > 0 && precioAerolinea > 0 && precioLatam > 0) {
					puts("\nCalculando costos...\n");
					codigoError = -1;
					if ( utn_hacerDescuento(precioAerolinea, 10, &precioDebitoAerolinea) != -1 &&
						 utn_hacerDescuento(precioLatam, 10, &precioDebitoLatam) != -1 &&
						 utn_sumarInteres(precioAerolinea, 25, &precioCreditoAeroline) != -1 &&
						 utn_sumarInteres(precioLatam, 25, &precioCreditoLatam) != -1 &&
						 utn_calcularPrecio(precioAerolinea, 2607609.47, &precioBTCAerolinea) != -1 &&
						 utn_calcularPrecio(precioLatam, 2607609.47, &precioBTCLatam) != -1 &&
						 utn_calcularPrecio(kilometros, precioAerolinea, &precioUnitarioAerolinea) != -1 &&
						 utn_calcularPrecio(kilometros, precioLatam, &precioUnitarioLatam) != -1 &&
						 utn_restarNumeroFlotante(precioAerolinea, precioLatam, &diferenciaDePrecios) != -1
						)
					{
						estaCalculado = TRUE;
						codigoError = 0;
					}

					utn_imprimirMensajes(codigoError, "\nSe han calculado los costos satisfactoriamente.\n", "\nHa ocurrido un error al calcular los costos.\n");
				} else {
					puts("\nDebe tener cargado los precios y el kilometraje antes de calcular costos.\n");
				}
				break;
			case 4:
				if (estaCalculado) {
					puts("=== INFORMES ===");
					printf("\nKMs ingresados: %.2f km \n", kilometros);
					//aerolineas
					imprimirInformeDeCostos("Aerolineas", precioAerolinea, precioDebitoAerolinea, precioCreditoAeroline, precioBTCAerolinea, precioUnitarioAerolinea);

					//latam
					imprimirInformeDeCostos("Latam", precioLatam, precioDebitoLatam, precioCreditoLatam, precioBTCLatam, precioUnitarioLatam);

					// diferencia de precios
					printf("La diferencia de precio es: %.2f \n\n", diferenciaDePrecios);
				} else {
					puts("\nNo se puede hacer un informe sin antes calcular costos.\n");
				}
				break;
			case 5:
				puts("\n=== CARGA FORZADA ===\n");

				codigoError = hacerCargaForzada();
				utn_imprimirMensajes(codigoError, "\nSe ha realizado carga forzada satisfactoriamente.\n", "\nHa ocurrido un error al realizar la carga forzada.\n");
				break;
			default:
				break;
		}

	} while(opcionMenu != 6);

	puts("\n\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
