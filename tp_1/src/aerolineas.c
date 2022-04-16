/*
 * aerolineas.c
 *
 *  Created on: 15 abr 2022
 *      Author: Nicolás Caruso
 */
#include <stdio.h>
#include <stdlib.h>
#include "aerolineas.h"

void imprimirInformeDeCostos(char * nombreAerolinea, float precio, float precioConDescuento, float precioConInteres, float precioBTC, float precioUnitario) {
	printf("\nPrecio %s: $%.2f", nombreAerolinea, precio);
	printf("\na) Precio con tarjeta de débito: $%.2f", precioConDescuento);
	printf("\nb) Precio con tarjeta de crédito: $%.2f", precioConInteres);
	printf("\nc) Precio pagado con Bitcoins: %.8f BTC", precioBTC);
	printf("\nd) Mostrar precio unitario: $%.2f \n\n", precioUnitario);
}



