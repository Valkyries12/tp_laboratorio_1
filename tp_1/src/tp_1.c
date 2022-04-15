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
	int respuesta;

	do {
		respuesta = utn_getInt(&menuOpcion, "\n 1. Ingresar kilómetros\n 2. Ingresar precios de vuelos\n 3. Calcular todos los costos\n 4. Informar resultados\n 5. Carga forzada de datos\n 6. Salir \n\nPor favor ingrese una opción: ", "\nOpción inválida. Por favor elija una opción\n", 6, 1, 3);
		if (respuesta == 0){
			switch (menuOpcion) {
				case 1:
					puts("\n=== Ingreso de kilometraje ===\n");
					break;
				case 2:
					puts("\n=== Precio de vuelos === \n");
					break;
				case 3:
					puts("\nCalculando costos...  \n");
					break;
				case 4:
					puts("\n=== Informe de resultados === \n");
					break;
				case 5:
					puts("\n=== Carga forzada de datos === \n");
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
