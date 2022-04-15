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
	int respuestaAerolineas;
	int respuestaLatam;
	int tienePrecio;
	int tieneKilometro;
	float precioAerolineas;
	float precioLatam;

	tienePrecio = FALSE;
	tieneKilometro = FALSE;

	do {
		respuesta = utn_getInt(&menuOpcion, "\n 1. Ingresar kilómetros\n 2. Ingresar precios de vuelos\n 3. Calcular todos los costos\n 4. Informar resultados\n 5. Carga forzada de datos\n 6. Salir \n\nPor favor ingrese una opción: ", "\nOpción inválida. Por favor elija una opción\n", 6, 1, 3);
		if (respuesta == 0){
			switch (menuOpcion) {
				case 1:
					puts("\n=== Ingreso de kilometraje ===\n");
					respuesta = utn_getInt(&kilometrosIngresados, "\n Ingrese kilometros: ", "\n Hubo un error en el ingreso de kilometros. Por favor revisar \n", 20000, 350, 3);
					if (respuesta == 0) {
						printf("\n Se han registrado %d kilometros \n", kilometrosIngresados);
						tieneKilometro = TRUE;
					}
					break;
				case 2:
					if (tieneKilometro) {
						puts("\n=== Precio de vuelos === \n");
						respuestaAerolineas = utn_getFloat(&precioAerolineas, "\nPrecio vuelo Aerolineas: ", "Ha ocurrido un error al asignar el precio", 279500.45, 5099.27 , 2);
						respuestaLatam = utn_getFloat(&precioLatam, "\nPrecio vuelo Latam: ", "Ha ocurrido un error al asignar el precio", 279500.45, 5099.27, 2);

						if (respuestaAerolineas == 0 && respuestaLatam == 0) {
							tienePrecio = TRUE;
							printf("\nPrecio asignado con éxito\n");
						} else {
							printf("\n\n Oops ha ocurrido un error =( \n");
						}

					} else {
						puts("\n No puede consultar precios sin haber asignado un kilometraje \n");
					}

					break;
				case 3:
					if (tieneKilometro && tienePrecio) {
						puts("\nCalculando costos...  \n");
					} else {
						puts("\n No puede calcular costos sin haber asignado un vuelo \n");
					}

					break;
				case 4:
					if (tieneKilometro && tienePrecio) {
						puts("\n=== Informe de resultados === \n");
					} else {
						puts("\n No puede informar resultados sin haber asignado un vuelo \n");
					}

					break;
				case 5:
					if (tienePrecio) {
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
