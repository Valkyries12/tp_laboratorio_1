#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

#define FALSE 0
#define TRUE 1

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int optionMenu = 0;
    int codigoError;
    int cantidadPasajeros;
    int isSaved;

    isSaved = FALSE;

    setbuf(stdout, NULL);

    puts("=== INICIO DEL PROGRAMA ===\n\n");

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	cantidadPasajeros = ll_len(listaPasajeros);
    	codigoError = utn_getInt(&optionMenu, "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). \n3. Alta de pasajero. \n4. Modificar datos de pasajero. \n5. Baja de pasajero. \n6. Listar pasajeros. \n7. Ordenar pasajeros. \n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario). \n10. Salir. \n\nIngrese una opción: ", "\nError. Sólo se permite números del 1 al 10.\n", 10, 1, 3);
        switch(optionMenu)
        {
            case 1:
                codigoError = controller_loadFromText("data.csv",listaPasajeros);
                utn_imprimirMensajes(codigoError, "\nSe han traido los datos con éxito.\n", "\nNo se han podido traer los datos.\n");
                break;
            case 2:
				codigoError = controller_loadFromBinary("data.bin",listaPasajeros);
				utn_imprimirMensajes(codigoError, "\nSe han traido los datos con éxito.\n", "\nNo se han podido traer los datos.\n");
				break;
            case 3:
            	if (cantidadPasajeros == 0) {
            		puts("\nPrimero debes traer los datos del archivo.\n");
            	} else {
    				codigoError = controller_addPassenger(listaPasajeros);
    				utn_imprimirMensajes(codigoError, "\nSe creado un nuevo pasajero.\n", "\nNo se ha podido crear un nuevo pasajero.\n");
            	}

				break;
            case 4:
            	if (cantidadPasajeros == 0) {
            		puts("\nNo existen pasajeros. Primero debes traer los datos del archivo.\n");
            	} else {
            		codigoError = controller_editPassenger(listaPasajeros);
            		utn_imprimirMensajes(codigoError, "\nSe ha modificado el pasajero con éxito.\n", "\nNo se ha podido modificar al pasajero.\n");
            	}

				break;
            case 5:
            	if (cantidadPasajeros == 0) {
            		puts("\nNo existen pasajeros. Primero debes traer los datos del archivo.\n");
            	} else {
            		codigoError = controller_removePassenger(listaPasajeros);
            		utn_imprimirMensajes(codigoError, "\nSe ha eliminado el pasajero con éxito.\n", "\nNo se ha podido eliminar al pasajero.\n");
            	}

				break;
            case 6:
            	if (cantidadPasajeros == 0) {
            	    puts("\nNo existen pasajeros. Primero debes traer los datos del archivo.\n");
            	} else {
            		codigoError = controller_ListPassenger(listaPasajeros);
            		utn_imprimirMensajes(codigoError, "\nSe ha listado con éxito.\n", "\nNo se ha podido listar.\n");
            	}

            	break;
            case 7:
            	if (cantidadPasajeros == 0) {
            	    puts("\nNo existen pasajeros. Primero debes traer los datos del archivo.\n");
            	} else {
            		codigoError = controller_sortPassenger(listaPasajeros);
            		utn_imprimirMensajes(codigoError, "\nOrdenamiento realizado con éxito. Imprima desde opción 6.\n", "\nNo se ha podido realizar el ordenamiento.\n");
            	}

            	break;
            case 8:
            	if (cantidadPasajeros == 0) {
            	    puts("\nNo se puede guardar la lista vacia. Primero debes traer los datos del archivo.\n");
            	} else {
            		codigoError = controller_saveAsText("data.csv", listaPasajeros);
            		utn_imprimirMensajes(codigoError, "\nGuardado en csv realizado con éxito.\n", "\nNo se ha podido realizar el guardado csv.\n");
            		if (codigoError != -1) {
            			isSaved = TRUE;
            		}
            	}

				break;
            case 9:
            	if (cantidadPasajeros == 0) {
            	    puts("\nNo se puede guardar la lista vacia. Primero debes traer los datos del archivo.\n");
            	} else {
            		codigoError = controller_saveAsBinary("data.bin", listaPasajeros);
            		utn_imprimirMensajes(codigoError, "\nGuardado en bin realizado con éxito.\n", "\nNo se ha podido realizar el guardado bin.\n");
            		if (codigoError != -1) {
						isSaved = TRUE;
					}
            	}

				break;
            case 10:
            	if (isSaved == FALSE) {
            		puts("\nNo se puede salir sin guardar el archivo.\n");
            	} else {
            		ll_deleteLinkedList(listaPasajeros);
            	}
        }
    }while(!(optionMenu == 10 && isSaved == TRUE));

    if (codigoError != 0) {
    	puts("\nOops ha ocurrido un error fatal =(.\n");
    }
    puts("Saliendo...");


    puts("\n\n=== FIN DEL PROGRAMA ===");
    return 0;
}

