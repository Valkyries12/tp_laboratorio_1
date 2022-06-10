/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

#define TRUE 1
#define FALSE 0




Passenger* Passenger_new() {
	Passenger* pasajero;
	Passenger* auxPasajero;

	pasajero = NULL;
	auxPasajero = NULL;

	auxPasajero = (Passenger*) malloc(sizeof(Passenger));
	if (auxPasajero != NULL) {
		pasajero = auxPasajero;
	}

	return pasajero;

}


Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr) {
	Passenger* pPasajero;
//	Passenger* auxPasajero;

	pPasajero = NULL;
//	auxPasajero = NULL;
	//TODO -> una vez creado y pasado a pasajero . Auxpasajero hay que borrarlo con free?
	//Si libero esa direccion no me borra pasajero al ser las dos iguales?
	if (idStr != NULL && nombreStr && apellidoStr != NULL && precioStr != NULL  && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL) {
		pPasajero = Passenger_new(); //creo un nuevo pasajero en memoria
		if (pPasajero != NULL) {

			if (Passenger_setId(pPasajero, atoi(idStr)) == 0 &&
				Passenger_setNombre(pPasajero, nombreStr) == 0 &&
				Passenger_setApellido(pPasajero, apellidoStr) == 0 &&
				Passenger_setPrecio(pPasajero, atof(precioStr)) == 0 &&
				Passenger_setTipoPasajero(pPasajero, Passenger_tipoPasajeroToInt(tipoPasajeroStr)) == 0 &&
				Passenger_setCodigoVuelo(pPasajero, codigoVueloStr) == 0 &&
				Passenger_setEstadoVuelo(pPasajero, Passenger_estadoVueloToInt(estadoVueloStr)) == 0
				) {
				//TODO cambiar a algo mas coherente porque para que hacer setters con retorno si no lo uso
				puts("\nSe ha cargado el pasajero\n");
//				pasajero = auxPasajero;

			} else {
//				free(auxPasajero);
				pPasajero = NULL;
				printf("\nNo se ha podido crear al pasajero con id: %s.\n", idStr);
			}
		}
	}

	return pPasajero;
}


void Passenger_delete(Passenger* this) {
	free(this);
}

int Passenger_setId(Passenger* this,int id) {
	int codigoError;
//	printf("this es: %p, id es: %d",this,id);
//	puts("\nDentro de setId\n");
	codigoError = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getId(Passenger* this,int* id) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setNombre(Passenger* this,char* nombre) {
	int codigoError;
//	puts("\nDentro de setNombre\n");

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getNombre(Passenger* this,char* nombre) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setApellido(Passenger* this,char* apellido) {
	int codigoError;
//	puts("\nDentro de setApellido\n");

	codigoError = -1;
	if (this != NULL && apellido != NULL) {
		strcpy(this->apellido, apellido);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getApellido(Passenger* this,char* apellido) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo) {
	int codigoError;
//	printf("\nDentro de setCodigoVuelo, codigoVuelo es: %s\n", codigoVuelo);

	codigoError = -1;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(this->codigoVuelo, codigoVuelo);
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero) {
	int codigoError;
//	puts("\nDentro de setTipoPasajero\n");

	codigoError = -1;
	if (this != NULL && tipoPasajero > -1) {
		this->tipoPasajero = tipoPasajero;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && tipoPasajero != NULL) {
		*tipoPasajero = this->tipoPasajero;
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setPrecio(Passenger* this,float precio) {
	int codigoError;
//	puts("\nDentro de setPrecio\n");

	codigoError = -1;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		codigoError = 0;
	}

	return codigoError;
}
int Passenger_getPrecio(Passenger* this,float* precio) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		codigoError = 0;
	}

	return codigoError;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo) {
	int codigoError;
//	printf("\nDentro de setEstadoVuelo, estado de vuelo es: %d\n", estadoVuelo);

	codigoError = -1;
	if (this != NULL && estadoVuelo > -1) {
		this->estadoVuelo = estadoVuelo;
		codigoError = 0;
	}

	return codigoError;
}


int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo) {
	int codigoError;

	codigoError = -1;
	if (this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->estadoVuelo;
		codigoError = 0;
	}

	return codigoError;
}


int Passenger_tipoPasajeroToInt(char* tipoPasajeroStr) {
	int tipoPasajeroInt;

	tipoPasajeroInt = -1;
	if (tipoPasajeroStr != NULL) {
		if (strcmp(tipoPasajeroStr, "FirstClass") == 0) {
			tipoPasajeroInt = 0;
		} else {
			if (strcmp(tipoPasajeroStr, "ExecutiveClass") == 0) {
				tipoPasajeroInt = 1;
			} else {
				tipoPasajeroInt = 2;
			}
		}

	}

	return tipoPasajeroInt;
}


int Passenger_tipoPasajeroToStr(int tipoPasajeroInt, char* tipoPasajeroStr) {
	int codigoError;

	codigoError = -1;
	if (tipoPasajeroInt > -1 && tipoPasajeroStr != NULL) {

		switch (tipoPasajeroInt) {
			case 0:
				strcpy(tipoPasajeroStr, "FirstClass");
				break;
			case 1:
				strcpy(tipoPasajeroStr, "ExecutiveClass");
				break;
			case 2:
				strcpy(tipoPasajeroStr, "EconomyClass");
				break;
			default:
				break;
		}
		codigoError = 0;
	}

	return codigoError;
}




int Passenger_estadoVueloToInt(char* estadoVueloStr) {
	int estadoVueloInt;

	estadoVueloInt = -1;
	if (estadoVueloStr != NULL) {
		if (strcmp(estadoVueloStr, "En Horario") == 0) {
			estadoVueloInt = 0;
		} else {
			if (strcmp(estadoVueloStr, "Aterrizado") == 0) {
				estadoVueloInt = 1;
			} else {
				estadoVueloInt = 2;
			}
		}

	}

	return estadoVueloInt;
}


int Passenger_estadoVueloToStr(int estadoVueloInt, char* estadoVueloStr) {
	int codigoError;

	codigoError = -1;

	if (estadoVueloInt > -1 && estadoVueloStr != NULL) {

		switch (estadoVueloInt) {
			case 0:
				strcpy(estadoVueloStr, "En Horario");
				break;
			case 1:
				strcpy(estadoVueloStr, "Aterrizado");
				break;
			case 2:
				strcpy(estadoVueloStr, "En Vuelo");
				break;
			default:
				break;
		}
		codigoError = 0;
	}

	return codigoError;
}


void Passenger_imprimirPasajero(Passenger* pPasajero) {
	if (pPasajero != NULL) {
		int id;
		char nombre[50];
		char apellido[50];
		float precio;
		int tipoPasajero;
		char tipoPasajeroStr[20];
		char codigoVuelo[10];
		int estadoVuelo;
		char estadoVueloStr[20];

		if (Passenger_getId(pPasajero, &id) == 0 &&
			Passenger_getNombre(pPasajero, nombre) == 0 &&
			Passenger_getApellido(pPasajero, apellido) == 0 &&
			Passenger_getPrecio(pPasajero, &precio) == 0 &&
			Passenger_getTipoPasajero(pPasajero, &tipoPasajero) == 0 &&
			Passenger_getCodigoVuelo(pPasajero, codigoVuelo) == 0 &&
			Passenger_getEstadoVuelo(pPasajero, &estadoVuelo) == 0)
		{

			Passenger_estadoVueloToStr(estadoVuelo, estadoVueloStr);
			Passenger_tipoPasajeroToStr(tipoPasajero, tipoPasajeroStr);

			printf("|%6d", id);
			printf("|%20s", nombre);
			printf("|%20s", apellido);
			printf("|%20.2f", precio);
			printf("|%15s", tipoPasajeroStr);
			printf("|%20s", codigoVuelo);
			printf("|%15s|\n", estadoVueloStr);

		}


	}
}


void Passenger_imprimirCabecera(void) {
	printf("|%6s", "ID");
	printf("|%20s", "NOMBRE");
	printf("|%20s", "APELLIDO");
	printf("|%20s", "PRECIO");
	printf("|%15s", "TIPO PASAJERO");
	printf("|%20s", "CÓDIGO VUELO");
	printf("|%15s|\n", "ESTADO VUELO");
}


int Passenger_imprimirSortMenu(LinkedList* pArrayListPassenger) {
	int opcionMenu;
	int codigoError;
	int orden;//le paso un puntero al submenu asc / desc y al recibir rta del criterio de orden asd(1), desc(0)

	codigoError = -1;
	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Ordenar por ID. \n2- Ordenar por nombre. \n3- Ordenar por apellido. \n4- Ordenar por precio. \n5- Atras. \n\nIngrese una opción: ", "\nOpción inválidad. Solo se aceptan números del 1 al 5.\n", 5, 1, 3);
		switch (opcionMenu) {
			case 1:
				//ordeno por ID
				Passenger_imprimirSortSubmenu(&orden);

				if (ll_sort(pArrayListPassenger, Passenger_comparararPorID, orden) != -1) {
					codigoError = 0;
					opcionMenu = 5;
				}
				break;
			case 2:
				//ordeno por nombre
				Passenger_imprimirSortSubmenu(&orden);

				if (ll_sort(pArrayListPassenger, Passenger_comparararPorNombre, orden) != -1) {
					codigoError = 0;
					opcionMenu = 5;
				}
				break;
			case 3:
				//ordeno por apellido
				Passenger_imprimirSortSubmenu(&orden);

				if (ll_sort(pArrayListPassenger, Passenger_comparararPorApellido, orden) != -1) {
					codigoError = 0;
					opcionMenu = 5;
				}
				break;
			case 4:
				//ordeno por precio
				Passenger_imprimirSortSubmenu(&orden);

				if (ll_sort(pArrayListPassenger, Passenger_comparararPorPrecio, orden) != -1) {
					codigoError = 0;
					opcionMenu = 5;
				}
				break;
			default:
				break;
		}
	} while(opcionMenu != 5 && codigoError == 0);

	return codigoError;
}


void Passenger_imprimirSortSubmenu(int* orden) {
	int opcionMenu;
	int codigoError;

	do {
		codigoError = utn_getInt(&opcionMenu, "\n1- Orden ascendente. \n2- Orden descendente. \n3- Atras. \n\nIngrese una opción: ", "\nOpción inválidad. Solo se aceptan números del 1 al 3.\n", 3, 1, 3);
		switch (opcionMenu) {
			case 1:
				*orden = 1;
				opcionMenu = 3;
				puts("\nOrdenando...\n");
				break;
			case 2:
				*orden = 0;
				opcionMenu = 3;
				puts("\nOrdenando...\n");
				break;
			default:
				break;
		}
	} while(opcionMenu != 3 && codigoError == 0);
}




int Passenger_comparararPorID(void* pasajeroUno, void* pasajeroDos) {
	int resultado;
	int idUno;
	int idDos;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;


	resultado = 0;
	if (pasajeroUno != NULL && pasajeroDos != NULL) {

		pPasajeroUno = (Passenger*) pasajeroUno;
		pPasajeroDos = (Passenger*) pasajeroDos;

		if (Passenger_getId(pPasajeroUno, &idUno) != -1 &&
			Passenger_getId(pPasajeroDos, &idDos) != -1)
		{
			//descendente
			if (idUno > idDos) {
				resultado = 1;
			}//ascendente
			else if(idUno < idDos) {
				resultado = -1;
			}
		}

	}

	return resultado;
}



int Passenger_comparararPorNombre(void* pasajeroUno, void* pasajeroDos) {
	int resultado;
	char nombreUno[50];
	char nombreDos[50];
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;


	resultado = 0;
	if (pasajeroUno != NULL && pasajeroDos != NULL) {

		pPasajeroUno = (Passenger*) pasajeroUno;
		pPasajeroDos = (Passenger*) pasajeroDos;

		if (Passenger_getNombre(pPasajeroUno, nombreUno) != -1 &&
			Passenger_getNombre(pPasajeroDos, nombreDos) != -1)
		{
			//descendente
			if (strcmp(nombreUno, nombreDos) > 0) {
				resultado = 1;
			}//ascendente
			else if(strcmp(nombreUno, nombreDos) < 0) {
				resultado = -1;
			}
		}

	}

	return resultado;
}


int Passenger_comparararPorApellido(void* pasajeroUno, void* pasajeroDos) {
	int resultado;
	char apellidoUno[50];
	char apellidoDos[50];
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;


	resultado = 0;
	if (pasajeroUno != NULL && pasajeroDos != NULL) {

		pPasajeroUno = (Passenger*) pasajeroUno;
		pPasajeroDos = (Passenger*) pasajeroDos;

		if (Passenger_getApellido(pPasajeroUno, apellidoUno) != -1 &&
			Passenger_getApellido(pPasajeroDos, apellidoDos) != -1)
		{
			//descendente
			if (strcmp(apellidoUno, apellidoDos) > 0) {
				resultado = 1;
			}//ascendente
			else if(strcmp(apellidoUno, apellidoDos) < 0) {
				resultado = -1;
			}
		}

	}

	return resultado;
}



int Passenger_comparararPorPrecio(void* pasajeroUno, void* pasajeroDos) {
	int resultado;
	float precioUno;
	float precioDos;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;


	resultado = 0;
	if (pasajeroUno != NULL && pasajeroDos != NULL) {

		pPasajeroUno = (Passenger*) pasajeroUno;
		pPasajeroDos = (Passenger*) pasajeroDos;

		if (Passenger_getPrecio(pPasajeroUno, &precioUno) != -1 &&
			Passenger_getPrecio(pPasajeroDos, &precioDos) != -1)
		{
			//descendente
			if (precioUno > precioDos) {
				resultado = 1;
			}//ascendente
			else if(precioUno < precioDos) {
				resultado = -1;
			}
		}

	}

	return resultado;
}


int Passenger_buscarPorId(LinkedList* pArrayListPassenger, int id) {
	int indice;

	indice = -1;
	if (pArrayListPassenger != NULL && id > 0) {
		int auxId;
		int len;
		Passenger* pPasajero;
//TODO revisar
//		Passenger_traerUltimoId("ultimoID.txt", &len);
		len = ll_len(pArrayListPassenger);

		for(int i = 0; i < len; i++) {
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);//devuelve void* por eso casteo(unboxing)

			if (Passenger_getId(pPasajero, &auxId) != 1 && auxId == id) {
				indice = i;
				break;
			}
		}
	}

	return indice;
}


int Passenger_borrarPasajero(LinkedList* pArrayListPassenger) {
	int codigoError;


	codigoError = -1;
	if (pArrayListPassenger != NULL) {
		int len;
		int id;
		int indice;
		int opcionMenu;
		Passenger* pPasajero;
		len = ll_len(pArrayListPassenger);

		codigoError = utn_getInt(&id, "\nIngrese el ID del pasajero a eliminar: ", "\nError. ID inválido.\n", len, 1, 3);

		if (codigoError != -1) {
			indice = Passenger_buscarPorId(pArrayListPassenger, id);

			if (indice != 1) {
				//si encuentro el indice traigo el puntero de pasajero
				pPasajero = ll_get(pArrayListPassenger, indice);
				Passenger_imprimirCabecera();
				Passenger_imprimirPasajero(pPasajero);

				do{
					codigoError = utn_getInt(&opcionMenu, "\n1- Eliminar pasajero. \n2- Atras. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 2, 1, 3);
					switch (opcionMenu) {
						case 1:
							codigoError = ll_remove(pArrayListPassenger, indice);
//							if (ll_remove(pArrayListPassenger, indice) != -1) {
//								codigoError = Passenger_actualizarUltimoId("ultimoID.txt", pArrayListPassenger);
//							}
							break;
						default:
							break;
					}
				} while((opcionMenu > 2 || opcionMenu < 1) && codigoError == 0);

			} else {
				puts("\nID inexistente.\n");
			}
		}
	}

	return codigoError;

}


int Passenger_editarPasajero(LinkedList* pArrayListPassenger) {
	int codigoError;

	codigoError = -1;
	if (pArrayListPassenger != NULL) {
		int len;
		int id;
		int indice;
		int opcionMenu;
		char nuevoNombre[50];
		char nuevoApellido[50];
		float nuevoPrecio;
		int nuevoTipoPasajero;
		int nuevoEstadoVuelo;
		Passenger* pPasajero;
		len = ll_len(pArrayListPassenger);

		codigoError = utn_getInt(&id, "\nIngrese el ID del pasajero a editar: ", "\nError. ID inválido.\n", len, 1, 3);

		if (codigoError != -1) {
			indice = Passenger_buscarPorId(pArrayListPassenger, id);

			if (indice != 1) {
				//si encuentro el indice traigo el puntero de pasajero
				pPasajero = ll_get(pArrayListPassenger, indice);


				do{
					Passenger_imprimirCabecera();
					Passenger_imprimirPasajero(pPasajero);
					codigoError = utn_getInt(&opcionMenu, "\n1- Editar nombre del pasajero. \n2- Editar apellido del pasajero. \n3- Editar precio del ticket. \n4- Editar tipo de pasajero. \n5- Editar estado de vuelo. \n6- Atras. \n\nIngrese una opción: ", "\nOpción inválida. Reintente.\n", 6, 1, 3);
					switch (opcionMenu) {
						case 1:
							codigoError = utn_getString(nuevoNombre, "\nIngrese nuevo nombre: ", "\nError. Solo se permiten caracteres.\n", 3, 4, 15);
							if (codigoError != -1 && Passenger_setNombre(pPasajero, nuevoNombre) != -1) {
								opcionMenu = 6;
							}
							break;
						case 2:
							codigoError = utn_getString(nuevoApellido, "\nIngrese nuevo apellido: ", "\nError. Solo se permiten caracteres.\n", 3, 4, 15);
							if (codigoError != -1 && Passenger_setApellido(pPasajero, nuevoApellido) != -1) {
								opcionMenu = 6;
							}
							break;
						case 3:
							codigoError = utn_getFloat(&nuevoPrecio, "\nIngrese el nuevo precio: ", "\nError. Sólo esta permitido números.\n", 500000, 3500, 3);
							if (codigoError != -1 && Passenger_setPrecio(pPasajero, nuevoPrecio) != -1) {
								opcionMenu = 6;
							}
							break;
						case 4:
							codigoError = utn_getInt(&nuevoTipoPasajero, "\nIngrese nuevo tipo pasajero [0] FirstClass [1] ExecutiveClass [2] EconomyClass: ", "\nOpción inválida. Reintente.\n", 2, 0, 3);
							if (codigoError != -1 && Passenger_setTipoPasajero(pPasajero, nuevoTipoPasajero) != -1) {
								opcionMenu = 6;
							}
							break;
						case 5:
							codigoError = utn_getInt(&nuevoEstadoVuelo, "\nIngrese nuevo estado de vuelo [0] En Horario [1] Aterrizado [2] En vuelo: ", "\nOpción inválida. Reintente.\n", 2, 0, 3);
							if (codigoError != -1 && Passenger_setEstadoVuelo(pPasajero, nuevoEstadoVuelo) != -1) {
								opcionMenu = 6;
							}
							break;
						default:
							break;
					}
				} while(opcionMenu != 6 && codigoError == 0);

			} else {
				puts("\nID inexistente.\n");
			}
		}
	}

	return codigoError;

}



int Passenger_agregarPasajero(LinkedList* pArrayListPassenger) {
	int codigoError;

	codigoError = -1;
	if (pArrayListPassenger != NULL) {
		Passenger* auxpPasajero;
		Passenger* pPasajero;
		int id;
		int ultimoId;
		char auxId[10];
		char nombre[50];
		char apellido[50];
		float precio;
		char auxPrecio[50];
		int tipoPasajero;
		char auxTipoPasajero[50];
		char codigoVuelo[50];
		int estadoVuelo;
		char auxEstadoVuelo[50];


		if (Passenger_traerUltimoId("ultimoID.txt", &ultimoId) != -1) {

			id = ultimoId + 1;
		}


		if (utn_getString(nombre, "\nIngrese nombre del pasajero: ", "\nError. Solo se permiten entre 4 y 20 caracteres.\n", 3, 4, 20) == 0 &&
			utn_getString(apellido, "\nIngrese apellido del pasajero: ", "\nError. Solo se permiten entre 4 y 20 caracteres.\n", 3, 4, 20) == 0 &&
			utn_getFloat(&precio, "\nIngrese el precio del ticket: ", "\nError. Solo se permite números.\n", 500000, 3500, 3) == 0 &&
			utn_getInt(&tipoPasajero, "\nIngrese tipo pasajero [0] FirstClass [1] ExecutiveClass [2] EconomyClass: ", "\nOpción inválida. Reintente.\n", 2, 0, 3) == 0 &&
			utn_getStringConNumero(codigoVuelo, "\nIngrese el codigo de vuelo: ", "\nError. Debe tener 7 caracteres alfanumericos.\n", 3, 7, 7) == 0 &&
			utn_getInt(&estadoVuelo, "\nIngrese nuevo estado de vuelo [0] En Horario [1] Aterrizado [2] En vuelo: ", "\nOpción inválida. Reintente.\n", 2, 0, 3) == 0
		)
		{
			//TODO manejar los errores retornados

			Passenger_tipoPasajeroToStr(tipoPasajero, auxTipoPasajero);
			Passenger_estadoVueloToStr(estadoVuelo, auxEstadoVuelo);
			itoa(id, auxId, 10);//convierto el id int a string
			sprintf(auxPrecio, "%g", precio);//convierto el precio flotante a string
			auxpPasajero = Passenger_newParametros(auxId, nombre, apellido, auxPrecio , auxTipoPasajero, codigoVuelo, auxEstadoVuelo);

			if (auxpPasajero != NULL) {
				pPasajero = auxpPasajero;
				codigoError = ll_add(pArrayListPassenger, pPasajero);
				//un vez agregado el nuevo pasajero actualizo el ultimo id
				if (codigoError != -1) {
					codigoError = Passenger_actualizarUltimoId("ultimoID.txt", pArrayListPassenger);

				}


			}
		}



	}

	return codigoError;
}



int Passenger_guardarUltimoId(char* path, LinkedList* pArrayListPassenger) {
	int codigoError;
	FILE* pArchivo;
	int ultimoId;
	char ultimoIdStr[10];
	Passenger* pUltimoPasajero;

	codigoError = -1;
	if (path != NULL && pArrayListPassenger != NULL) {

		pUltimoPasajero = ll_get(pArrayListPassenger, ll_len(pArrayListPassenger)-1);
		if (pUltimoPasajero != NULL && Passenger_getId(pUltimoPasajero, &ultimoId) != -1) {

			pArchivo = fopen(path, "w");
			fprintf(pArchivo, itoa(ultimoId, ultimoIdStr, 10));
			codigoError = fclose(pArchivo);

		}
	}

	return codigoError;
}



int Passenger_traerUltimoId(char* path, int* ultimoId) {
	int codigoError;
	FILE* pArchivo;
	char ultimoIdStr[10];
	int ultimoIdInt;

	codigoError = -1;
	if (path != NULL && ultimoId != NULL) {
		pArchivo = fopen(path, "r");

		if (pArchivo != NULL) {
			fgets(ultimoIdStr, sizeof(char)*10, pArchivo);
			ultimoIdInt = atoi(ultimoIdStr);
			*ultimoId = ultimoIdInt;

			codigoError = fclose(pArchivo);
		}

	}

	return codigoError;
}


int Passenger_actualizarUltimoId(char* path, LinkedList* pArrayListPassenger) {
	int codigoError;
	FILE* pArchivo;
	Passenger* pUltimoPasajero;
	int ultimoId;
	char ultimoIdStr[10];

	codigoError = -1;
	if (path != NULL && pArrayListPassenger != NULL) {
		pArchivo = fopen(path, "w");

		if (pArchivo != NULL) {
			pUltimoPasajero = ll_get(pArrayListPassenger, ll_len(pArrayListPassenger)-1);

			if (pUltimoPasajero != NULL && Passenger_getId(pUltimoPasajero, &ultimoId) != -1) {
				fprintf(pArchivo, itoa(ultimoId, ultimoIdStr, 10));
				codigoError = fclose(pArchivo);
			}
		}
	}

	return codigoError;
}



int Passenger_guardarComoTexto(FILE* pFile, LinkedList* pArrayListPassenger) {
	int codigoError;
	int len;
//	char idStr[10];
	int idInt;
	char nombre[50];
	char apellido[50];
//	char precioStr[50];
	float precio;
	char codigoVueloStr[50];
	char tipoPasajeroStr[50];
	int tipoPasajero;
	char estadoVueloStr[50];
	int estadoVuelo;
	Passenger* pPasajero;

	codigoError = -1;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		len = ll_len(pArrayListPassenger);
		fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");

		for(int i = 0; i < len; i++) {
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			if (Passenger_getId(pPasajero, &idInt) != -1 &&
				Passenger_getNombre(pPasajero, nombre) != -1 &&
				Passenger_getApellido(pPasajero, apellido) != -1 &&
				Passenger_getCodigoVuelo(pPasajero, codigoVueloStr) != -1 &&
				Passenger_getPrecio(pPasajero, &precio) != -1 &&
				Passenger_getCodigoVuelo(pPasajero, codigoVueloStr) != -1 &&
				Passenger_getTipoPasajero(pPasajero, &tipoPasajero) != -1 &&
				Passenger_getEstadoVuelo(pPasajero, &estadoVuelo) != -1 &&
				Passenger_estadoVueloToStr(estadoVuelo, estadoVueloStr) != -1 &&
				Passenger_tipoPasajeroToStr(tipoPasajero, tipoPasajeroStr) != -1
			)
			{
//				itoa(idInt, idStr, 10);
//				sprintf(precioStr, "%g", precio);//convierto el precio flotante a string

				fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", idInt, nombre, apellido, precio, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
				codigoError = 0;
			}

		}
	}

	return codigoError;
}




