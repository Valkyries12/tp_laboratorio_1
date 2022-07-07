/*
 ============================================================================
 Name        : rrecuperatorio_tp2.c
 Author      : Nicolás Caruso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pasajero.h"
#include "arrayPasajero.h"
#include "utn.h"

#define TRUE 1
#define FALSE 0
#define MAXIMO_PASAJEROS 2000


int main(void) {
	setbuf(stdout, NULL);
	Pasajero pasajeros[MAXIMO_PASAJEROS];
	int codigoError;
	int opcionMenu;
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int estadoVuelo;
	int tipoPasajero;
	int indice;
	float totalPrecios;
	float promedio;
	int cantidadSuperanPromedio;

	puts("=== INICIO DEL PROGRAMA === \n\n");

	inicializarPasajeros(pasajeros, MAXIMO_PASAJEROS);

	do {
		puts("=== MENÚ PRINCIPAL ===");
		codigoError = utn_getInt(&opcionMenu, "\n1- Alta de pasajero \n2- Modificar pasajero \n3- Baja de pasajero \n4- INFORMAR \n5- Carga forzada. \n6- Salir \n\nIngrese una opción: ", "\nOpción inválida. Reintente\n", 6, 1, 3);
		if (codigoError == 0) {
			switch (opcionMenu) {
				case 1:
					puts("=== Alta de pasajero ===");
					codigoError = -1;

					if ( utn_getString(nombre, "\nIngrese nombre del pasajero: ", "\nNombre inválido. Debe tener entre 4 y 50 caracteres.\n", 3, 4, 50) != -1 &&
						 utn_getString(apellido, "\nIngrese apellido del pasajero: ", "\nApellido inválido. Debe tener entre 4 y 50 caracteres.\n", 3, 4, 50) != -1 &&
						 utn_getFloat(&precio, "\nIngrese precio del pasaje: ", "\nPrecio inválido. Debe contener solo números entre 2500 y 750000.\n", 750000, 2500, 3) != -1 &&
						 getCodigoVuelo(codigoVuelo, "\nIngrese código de vuelo: ", "\nCódigo de vuelo inválido. Debe tener 6 caracteres alfanumericos.\n", 3, 6, 6) != -1 &&
						 utn_getInt(&estadoVuelo, "\nIngrese el estado de vuelo 0-> activo, 1-> demorado, 2-> cancelado: ", "\nOpción inválida. Debe estar entre 0 y 2.\n", 2, 0, 3) != -1 &&
						 utn_getInt(&tipoPasajero, "\nIngrese el tipo de pasajero 0-> primera clase, 1-> ejecutivo, 2-> premium: ", "\nOpción inválida. Debe estar entre 0 y 2.\n", 2, 0, 3) != -1
						)
					{
						id = incrementarId();
						codigoError = agregarPasajero(pasajeros, MAXIMO_PASAJEROS, id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);
					}

					utn_imprimirMensajes(codigoError, "\nSe han agregado los datos satisfactoriamente.\n", "\nHubo un error al agregar los datos.\n");
					break;
				case 2:

					if (hayAlgoCargado(pasajeros, MAXIMO_PASAJEROS)) {
						puts("=== Modificar pasajero ===");

						codigoError = utn_getInt(&id, "\n\nIngrese el ID del pasajero a modificar: ", "\nOpción inválida. Reintente.\n", 15000, 150, 3);
						if (codigoError == 0 && existePasajero(pasajeros, MAXIMO_PASAJEROS, id)) {
							indice = buscarPasajeroPorId(pasajeros, id, MAXIMO_PASAJEROS);
							if (indice != -1) {
								do {
									imprimirCabecera();
									imprimirPasajero(pasajeros[indice]);
									codigoError = utn_getInt(&opcionMenu, "\n1- Modificar nombre. \n2- Modificar apellido. \n3- Modificar precio. \n4- Modificar tipo de pasajero. \n5- Modificar código de vuelo. \n6- Atras. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 6, 1, 3);

									if (codigoError == 0 && opcionMenu != 6) {
										codigoError = modificarPasajero(pasajeros, id, opcionMenu, MAXIMO_PASAJEROS);
										utn_imprimirMensajes(codigoError, "\nSe han modificado los datos satisfactoriamente.\n", "\nHa ocurrido un error al modificar los datos.");
									}
								} while(opcionMenu != 6 && codigoError == 0);
								opcionMenu = 0;
							}

						}
					} else {
						puts("Debe haber al menos un pasajero cargado.");
					}
					break;
				case 3:

					if (hayAlgoCargado(pasajeros, MAXIMO_PASAJEROS)) {
						puts("=== Eliminar pasajero ===");

						codigoError = utn_getInt(&id, "\nIngrese el ID del pasajero a eliminar: ", "\nID incorrecto. Reintente.\n", 15000, 150, 3);
						if (codigoError == 0 && existePasajero(pasajeros, MAXIMO_PASAJEROS, id)) {

							indice = buscarPasajeroPorId(pasajeros, id, MAXIMO_PASAJEROS);
							do {
								imprimirCabecera();
								imprimirPasajero(pasajeros[indice]);
								codigoError = utn_getInt(&opcionMenu, "\n1. Borrar pasajero. \n2. Atras. \n\nIngrese una opcion: ", "\nOpción inválida. Reintente.\n", 2, 1, 3);
								switch (opcionMenu) {
									case 1:
										codigoError = eliminarPasajero(pasajeros, id, MAXIMO_PASAJEROS);
										utn_imprimirMensajes(codigoError, "\nSe ha eliminado el pasajero satisfactoriamente.\n", "\nHa ocurrido un error al eliminar el pasajero.\n");
										opcionMenu = 2;
										break;
									default:
										break;
								}
							} while(opcionMenu != 2);



						} else {
							puts("\nPasajero inexistente.\n");
						}
					} else {
						puts("Debe haber al menos un pasajero cargado");
					}
					break;
				case 4:

					if (hayAlgoCargado(pasajeros, MAXIMO_PASAJEROS)) {
						puts("=== INFORME ===");

						do{
							codigoError = utn_getInt(&opcionMenu, "\n1- Listado pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero. \n2- Total y promedio de los precios de los pasajes y cuantos pasajeros superan el promedio. \n3- Listado de los pasajeros por Código de vuelo y estados de vuelos ACTIVO. \n4- Atras. \n\nIngrese una opción: ", "\nOpción incorrecta. Reintente.\n", 4, 1, 3);
							if (codigoError == 0) {
								switch (opcionMenu) {
									case 1:
										do {
											codigoError = utn_getInt(&opcionMenu, "\n1- Ordenar de forma ascendente. \n2- Ordenar de forma descendente. \n3- Atras. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 3, 1, 3);
											if (codigoError == 0) {
												switch (opcionMenu) {
													case 1:
														codigoError = ordenarPasajeros(pasajeros, MAXIMO_PASAJEROS, 1);
														utn_imprimirMensajes(codigoError, "\nSe han ordenado los pasajeros satisfactoriamente.\n", "\nHa ocurrido un error al ordenar los pasajeros.\n");
														imprimirCabecera();
														imprimirPasajeros(pasajeros, MAXIMO_PASAJEROS);
														break;
													case 2:
														codigoError = ordenarPasajeros(pasajeros, MAXIMO_PASAJEROS, 2);
														utn_imprimirMensajes(codigoError, "\nSe han ordenado los pasajeros satisfactoriamente.\n", "\nHa ocurrido un error al ordenar los pasajeros.\n");
														imprimirCabecera();
														imprimirPasajeros(pasajeros, MAXIMO_PASAJEROS);
														break;
													default:
														break;
												}
											}
										} while(opcionMenu != 3 && codigoError == 0);

										break;
									case 2:
										codigoError = calcularTotalDeTodosLosPasajes(pasajeros, &totalPrecios, MAXIMO_PASAJEROS);
										if (codigoError == 0) {
											codigoError = calcularPromedioDePasajes(pasajeros, &promedio, totalPrecios, MAXIMO_PASAJEROS);


											if (codigoError == 0) {
												codigoError = calcularCuantosSuperanPromedio(pasajeros, promedio, &cantidadSuperanPromedio, MAXIMO_PASAJEROS);
											}
										}

										utn_imprimirMensajes(codigoError, "\nSe han hecho los cálculos satisfactoriamente.\n", "\nHa sucedido un error al realizar los cálculos.\n");

										if (codigoError == 0) {
											imprimirCalculosDePasajeros(totalPrecios, promedio, cantidadSuperanPromedio);
										}
										break;

									case 3:
										do {
											codigoError = utn_getInt(&opcionMenu, "\n1- Ordenar de forma ascendente. \n2- Ordenar de forma descendente. \n3- Atras. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 3, 1, 3);
											if (codigoError == 0) {
												switch (opcionMenu) {
													case 1:
														codigoError = ordenarPasajerosPorCodigo(pasajeros, MAXIMO_PASAJEROS, 1);
														utn_imprimirMensajes(codigoError, "\nSe han ordenado los pasajeros satisfactoriamente.\n", "\nHa ocurrido un error al ordenar los pasajeros.\n");
														imprimirCabecera();
														imprimirPasajerosPorEstado(pasajeros, MAXIMO_PASAJEROS, 0);
														break;
													case 2:
														codigoError = ordenarPasajerosPorCodigo(pasajeros, MAXIMO_PASAJEROS, 2);
														utn_imprimirMensajes(codigoError, "\nSe han ordenado los pasajeros satisfactoriamente.\n", "\nHa ocurrido un error al ordenar los pasajeros.\n");
														imprimirCabecera();
														imprimirPasajerosPorEstado(pasajeros, MAXIMO_PASAJEROS, 0);
														break;
													default:
														break;
												}
											}
										} while(opcionMenu != 3 && codigoError == 0);
										break;
									default:
										break;
								}
							}
						} while(opcionMenu != 4 && codigoError == 0);


//						imprimirPasajero(pasajeros[0]);
					} else {
						puts("Debe haber al menos un pasajero cargado");
					}
					break;
				case 5:

					puts("\n === Carga forzada ===");
					if (!hayAlgoCargado(pasajeros, MAXIMO_PASAJEROS)) {
						codigoError = hacerCargaForzada(pasajeros, MAXIMO_PASAJEROS);
						utn_imprimirMensajes(codigoError, "\nSe ha realizado una carga forzada satisfactoriamente.\n", "\nHa sucedido un error al realizar la carga forzada\n");
					} else {
						puts("\nPara realizar la cargar forzada es necesario que no haya pasajeros cargados.\n");
					}


					break;
				default:
					break;
			}
		}

	} while(opcionMenu != 6);



	puts("\n\nSaliendo...");

	puts("\n\n=== FIN DEL PROGRAMA ===");
	return EXIT_SUCCESS;
}
