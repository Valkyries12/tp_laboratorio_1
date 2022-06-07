/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;

}Passenger;



Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);


/// @brief convierte la cadena tipoPasajero a int de tipoPasajero
///
/// @param tipoPasajeroStr -> cadena con el tipo de pasajero
/// @return entero del tipo de pasajero
int Passenger_tipoPasajeroToInt(char* tipoPasajeroStr);


/// @brief convierte la cadena estadoVuelo a int de estadoVuelo
///
/// @param estadoVueloStr -> cadena con el estado de vuelo
/// @return entero del estado de vuelo
int Passenger_estadoVueloToInt(char* estadoVueloStr);


/// @brief convierte la cadena de tipoPasajero segun su codigo en entero
///
/// @param tipoPasajeroInt -> tipoPasajero entero
/// @param tipoPasajeroStr -> puntero donde se guardara la cadena del tipo de pasajero
/// @return Retorna (0) en caso de exito, (-1) en caso de error
int Passenger_tipoPasajeroToStr(int tipoPasajeroInt, char* tipoPasajeroStr);


/// @brief convierte la cadena de estadoVuelo segun su codigo en entero
///
/// @param estadoVueloInt -> estadoVuelo entero
/// @param estadoVueloStr -> puntero donde se guardara la cadena del estado de vuelo
/// @return Retorna (0) en caso de exito, (-1) en caso de error
int Passenger_estadoVueloToStr(int estadoVueloInt, char* estadoVueloStr);


/// @brief Imprime los datos del pasajero dado
///
/// @param pasajero -> puntero del pasajero
void Passenger_imprimirPasajero(Passenger* pPasajero);


/// @brief imprime la cabecera de la tabla
void Passenger_imprimirCabecera(void);




#endif /* PASSENGER_H_ */
