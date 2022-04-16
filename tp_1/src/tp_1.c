/*
 ============================================================================
 Name        : tp_1.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "operaciones_aritmeticas.h"
#include "aerolineas.h"


#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");

	int menuOpcion;
	int kilometrosIngresados;
	int respuesta;
	int pHayError;
	int tienePrecio;
	int tieneKilometro;
	int estaCalculado;

	float precioAerolineas;
	float precioLatam;
	float precioAerolineasConDescuento;
	float precioAerolineasConInteres;
	float precioAerolineasEnBitcoin;
	float precioUnitarioAerolineas;

	float precioLatamConDescuento;
	float precioLatamConInteres;
	float precioLatamEnBitcoin;
	float precioUnitarioLatam;
	float diferenciaDePrecios;


	tienePrecio = FALSE;
	tieneKilometro = FALSE;
	estaCalculado = FALSE;


	do {
		respuesta = utn_getInt(&menuOpcion, "\n 1. Ingresar kilómetros\n 2. Ingresar precios de vuelos\n 3. Calcular todos los costos\n 4. Informar resultados\n 5. Carga forzada de datos\n 6. Salir \n\nPor favor ingrese una opción: ", "\nOpción inválida. Por favor elija una opción\n", 6, 1, 3);
		if (respuesta == 0){
			switch (menuOpcion) {
				case 1:
					puts("\n=== Ingreso de kilometraje ===\n");
					respuesta = utn_getInt(&kilometrosIngresados, "\n Ingrese kilometros: ", "\n Hubo un error en el ingreso de kilometros. Por favor revisar \n", 20000, 350, 3);
					utn_verificarSiHayError(respuesta, &pHayError);
					utn_imprimirMensajes(pHayError, "\n Se han registrado los kilometros \n", "\n Oops ha ocurrido un error =( \n");
					if (pHayError == 0) {
						tieneKilometro = TRUE;
					}
					break;
				case 2:
					if (tieneKilometro) {
						puts("\n=== Precio de vuelos === \n");

						respuesta = utn_getFloat(&precioAerolineas, "\nPrecio vuelo Aerolineas: ", "\nHa ocurrido un error al asignar el precio", 279500.45, 5099.27 , 2);
						utn_verificarSiHayError(respuesta, &pHayError);
						if (pHayError == 0) {
							respuesta = utn_getFloat(&precioLatam, "\nPrecio vuelo Latam: ", "\nHa ocurrido un error al asignar el precio", 279500.45, 5099.27, 2);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						utn_imprimirMensajes(pHayError, "\nPrecio asignado con éxito\n", "\n\n Oops ha ocurrido un error =( \n");
						if (pHayError == 0) {
							tienePrecio = TRUE;
						}

					} else {
						puts("\n No puede consultar precios sin haber asignado un kilometraje \n");
					}

					break;
				case 3:
					if (tieneKilometro && tienePrecio) {
						puts("\nCalculando costos...  \n");
						///costos de aerolineas
						respuesta = utn_hacerDescuento(precioAerolineas, 10, &precioAerolineasConDescuento);
						utn_verificarSiHayError(respuesta, &pHayError);

						if (pHayError == 0) {
							respuesta = utn_sumarInteres(precioAerolineas, 25, &precioAerolineasConInteres);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularAPrecioBitcoin(precioAerolineas, 4613709.90, &precioAerolineasEnBitcoin);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularPrecioPorKilometro(kilometrosIngresados, precioAerolineas, &precioUnitarioAerolineas);
							utn_verificarSiHayError(respuesta, &pHayError);
						}

						//costos latam
						if (pHayError == 0) {
							respuesta = utn_hacerDescuento(precioLatam, 10, &precioLatamConDescuento);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_sumarInteres(precioLatam, 25, &precioLatamConInteres);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularAPrecioBitcoin(precioLatam, 4613709.90, &precioLatamEnBitcoin);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularPrecioPorKilometro(kilometrosIngresados, precioLatam, &precioUnitarioLatam);
							utn_verificarSiHayError(respuesta, &pHayError);
						}

						utn_imprimirMensajes(pHayError, "\nCostos calculados con éxito\n", "\n\n Oops ha ocurrido un error =( \n");

						///diferencia de precios
						if (pHayError == 0) {
							respuesta = restarNumeroFlotante(precioAerolineas, precioLatam, &diferenciaDePrecios);
							utn_verificarSiHayError(respuesta, &pHayError);
							estaCalculado = TRUE;
						}

					} else {
						puts("\n No puede calcular costos sin haber asignado un vuelo \n");
					}

					break;
				case 4:
					if (estaCalculado) {
						puts("\n=== Informe de resultados === \n");
						printf("\nKMs ingresados: %d km \n", kilometrosIngresados);
						//aerolineas
						imprimirInformeDeCostos("Aerolineas", precioAerolineas, precioAerolineasConDescuento, precioAerolineasConInteres, precioAerolineasEnBitcoin, precioUnitarioAerolineas);

						//latam
						imprimirInformeDeCostos("Latam", precioLatam, precioLatamConDescuento, precioLatamConInteres, precioLatamEnBitcoin, precioUnitarioLatam);

						// diferencia de precios
						printf("La diferencia de precio es: %.2f \n\n", diferenciaDePrecios);
					} else {
						puts("\n No puede informar resultados sin haber calculado antes \n");
					}

					break;
				case 5:
					if (tienePrecio) {
						puts("\n No se puede realizar la carga forzada teniendo un vuelo asignado \n");
					} else {
						puts("\n=== Carga forzada de datos === \n");
						kilometrosIngresados = 7090;
						precioAerolineas = 162965;
						precioLatam = 159339;
						///costos de aerolineas
						respuesta = utn_hacerDescuento(precioAerolineas, 10, &precioAerolineasConDescuento);
						utn_verificarSiHayError(respuesta, &pHayError);

						if (pHayError == 0) {
							respuesta = utn_sumarInteres(precioAerolineas, 25, &precioAerolineasConInteres);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularAPrecioBitcoin(precioAerolineas, 4613709.90, &precioAerolineasEnBitcoin);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularPrecioPorKilometro(kilometrosIngresados, precioAerolineas, &precioUnitarioAerolineas);
							utn_verificarSiHayError(respuesta, &pHayError);
						}

						//costos latam
						if (pHayError == 0) {
							respuesta = utn_hacerDescuento(precioLatam, 10, &precioLatamConDescuento);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_sumarInteres(precioLatam, 25, &precioLatamConInteres);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularAPrecioBitcoin(precioLatam, 4613709.90, &precioLatamEnBitcoin);
							utn_verificarSiHayError(respuesta, &pHayError);
						}
						if (pHayError == 0) {
							respuesta = utn_calcularPrecioPorKilometro(kilometrosIngresados, precioLatam, &precioUnitarioLatam);
							utn_verificarSiHayError(respuesta, &pHayError);
						}

						utn_imprimirMensajes(pHayError, "\nCarga realizada con éxito\n", "\n\n Oops ha ocurrido un error =( \n");

						///diferencia de precios
						if (pHayError == 0) {
							respuesta = restarNumeroFlotante(precioAerolineas, precioLatam, &diferenciaDePrecios);
							utn_verificarSiHayError(respuesta, &pHayError);

							printf("\nKMs ingresados: %d km \n", kilometrosIngresados);
							//aerolineas
							imprimirInformeDeCostos("Aerolineas", precioAerolineas, precioAerolineasConDescuento, precioAerolineasConInteres, precioAerolineasEnBitcoin, precioUnitarioAerolineas);

							//latam
							imprimirInformeDeCostos("Latam", precioLatam, precioLatamConDescuento, precioLatamConInteres, precioLatamEnBitcoin, precioUnitarioLatam);

							// diferencia de precios
							printf("La diferencia de precio es: %.2f \n\n", diferenciaDePrecios);
						}



					}

					break;
				case 6:
					puts("\nSaliendo.... \n");
					break;
				default:
					break;
			}
		} else {
			puts("\n Se ha roto el sistema");
		}
	}
	while(menuOpcion != 6);





	puts("\n === FIN DEL PROGRAMA ===\n");
	return EXIT_SUCCESS;
}
