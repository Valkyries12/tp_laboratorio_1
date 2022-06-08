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
                controller_loadFromText("data.csv",listaPasajeros);
                break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
            	break;
        }
    }while(optionMenu != 10 && codigoError == 0);


    puts("\n\n=== FIN DEL PROGRAMA ===");
    return 0;
}

