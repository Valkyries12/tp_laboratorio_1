#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

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

    setbuf(stdout, NULL);

    puts("=== INICIO DEL PROGRAMA ===\n\n");

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	codigoError = utn_getInt(&optionMenu, "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). \n3. Alta de pasajero. \n4. Modificar datos de pasajero. \n5. Baja de pasajero. \n6. Listar pasajeros. \n7. Ordenar pasajeros. \n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n10. Salir. \n\nIngrese una opción: ", "\nError. Sólo se permite números del 1 al 10.\n", 10, 1, 3);
        switch(optionMenu)
        {
            case 1:
                codigoError = controller_loadFromText("data.csv",listaPasajeros);
                utn_imprimirMensajes(codigoError, "\nSe han traido los datos con éxito.\n", "\nNo se han podido traer los datos.\n");
                break;
            case 3:
				codigoError = controller_addPassenger(listaPasajeros);
				utn_imprimirMensajes(codigoError, "\nSe creado un nuevo pasajero.\n", "\nNo se ha podido crear un nuevo pasajero.\n");
				break;
            case 4:
				codigoError = controller_editPassenger(listaPasajeros);
				utn_imprimirMensajes(codigoError, "\nSe ha modificado el pasajero con éxito.\n", "\nNo se ha podido modificar al pasajero.\n");
				break;
            case 5:
				codigoError = controller_removePassenger(listaPasajeros);
            	utn_imprimirMensajes(codigoError, "\nSe ha eliminado el pasajero con éxito.\n", "\nNo se ha podido eliminar al pasajero.\n");
				break;
            case 6:
            	codigoError = controller_ListPassenger(listaPasajeros);
            	utn_imprimirMensajes(codigoError, "\nSe ha listado con éxito.\n", "\nNo se ha podido listar.\n");
            	break;
            case 7:
            	codigoError = controller_sortPassenger(listaPasajeros);
            	utn_imprimirMensajes(codigoError, "\nOrdenamiento realizado con éxito. Imprima desde opción 6.\n", "\nNo se ha podido realizar el ordenamiento.\n");
            	break;
        }
    }while(optionMenu != 10 && codigoError == 0);

    if (codigoError != 0) {
    	puts("\nOops ha ocurrido un error =(.\n");
    }
    puts("Saliendo...");


    puts("\n\n=== FIN DEL PROGRAMA ===");
    return 0;
}

