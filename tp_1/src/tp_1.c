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


#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout, NULL);
	puts("=== INICIO DEL PROGRAMA ===");

	int menuOpcion;
	int kilometrosIngresados;
	int respuesta;
	int tieneVuelo;

	tieneVuelo = FALSE;

	do {
		respuesta = utn_getInt(&menuOpcion, "\n 1. Ingresar kilómetros\n 2. Ingresar precios de vuelos\n 3. Calcular todos los costos\n 4. Informar resultados\n 5. Carga forzada de datos\n 6. Salir \n\nPor favor ingrese una opción: ", "\nOpción inválida. Por favor elija una opción\n", 6, 1, 3);
		if (respuesta == 0){
			switch (menuOpcion) {
				case 1:
					puts("\n=== Ingreso de kilometraje ===\n");
					respuesta = utn_getInt(&kilometrosIngresados, "\n Ingrese kilometros: ", "\n Hubo un error en el ingreso de kilometros. Por favor revisar \n", 20000, 350, 3);
					if (respuesta == 0) {
						printf("\n Se han registrado %d kilometros \n", kilometrosIngresados);
						tieneVuelo = TRUE;
					}
					break;
				case 2:
					if (tieneVuelo) {
						puts("\n=== Precio de vuelos === \n");
					} else {
						puts("\n No puede consultar precios sin haber asignado un vuelo \n");
					}

					break;
				case 3:
					if (tieneVuelo) {
						puts("\nCalculando costos...  \n");
					} else {
						puts("\n No puede calcular costos sin haber asignado un vuelo \n");
					}

					break;
				case 4:
					if (tieneVuelo) {
						puts("\n=== Informe de resultados === \n");
					} else {
						puts("\n No puede informar resultados sin haber asignado un vuelo \n");
					}

					break;
				case 5:
					if (tieneVuelo) {
						puts("\n No se puede realizar la carga forzada teniendo un vuelo asignado \n");
					} else {
						puts("\n=== Carga forzada de datos === \n");
					}

					break;
				case 6:
					puts("\nSaliendo.... \n");
					break;
				default:
					break;
			}
		} else {
			puts("serompio");
		}
	}
	while(menuOpcion != 6);





	puts("\n === FIN DEL PROGRAMA ===\n");
	return EXIT_SUCCESS;
}
