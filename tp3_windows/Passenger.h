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


/// @brief imprime el menu de sort
///
/// @param linkedList -> linkedlist de pasajeros
/// @return Retorna (0) en caso de exito, (-1) en caso de error
int Passenger_imprimirSortMenu(LinkedList* pArrayListPassenger);

/// @brief imprime el submenu que contiene las opciones desc, asc
///
/// @param orden -> puntero donde se guardara el criterio de ordenamiento. Desc(0), Asc(1)
void Passenger_imprimirSortSubmenu(int* orden);


/// @brief Compara 2 ID
///
/// @param pasajeroUno -> puntero generico del pasajero uno
/// @param pasajeroDos -> puntero generico del pasajero dos
/// @return Si es igual (0), si es asc (-1), si es desc (1)
int Passenger_comparararPorID(void* pasajeroUno, void* pasajeroDos);



/// @brief Compara 2 nombres
///
/// @param pasajeroUno -> puntero generico del pasajero uno
/// @param pasajeroDos -> puntero generico del pasajero dos
/// @return Si es igual (0), si es asc (-1), si es desc (1)
int Passenger_comparararPorNombre(void* pasajeroUno, void* pasajeroDos);



/// @brief Compara 2 apellidos
///
/// @param pasajeroUno -> puntero generico del pasajero uno
/// @param pasajeroDos -> puntero generico del pasajero dos
/// @return Si es igual (0), si es asc (-1), si es desc (1)
int Passenger_comparararPorApellido(void* pasajeroUno, void* pasajeroDos);



/// @brief Compara 2 precios
///
/// @param pasajeroUno -> puntero generico del pasajero uno
/// @param pasajeroDos -> puntero generico del pasajero dos
/// @return Si es igual (0), si es asc (-1), si es desc (1)
int Passenger_comparararPorPrecio(void* pasajeroUno, void* pasajeroDos);


/// @brief busca pasajero mediante un id
///
/// @param pArrayListPassenger -> lista de pasajeros
/// @param id -> id del pasajero a buscar
/// return en caso de exito devuelve el indice , en caso de error (-1)
int Passenger_buscarPorId(LinkedList* pArrayListPassenger, int id);


/// @brief borrar un pasajero de la ll
///
/// @param pArrayListPassenger -> lista de pasajeros
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_borrarPasajero(LinkedList* pArrayListPassenger);


/// @brief edita un pasajero de la ll
///
/// @param pArrayListPassenger -> lista de pasajeros
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_editarPasajero(LinkedList* pArrayListPassenger);



/// @brief agrega un pasajero a la ll
///
/// @param pArrayListPassenger -> lista de pasajeros
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_agregarPasajero(LinkedList* pArrayListPassenger);



/// @brief crea un archivo y guarda el ultimo ID
///
/// @param path -> nombre del archivo
/// @param pArrayListPassenger -> lista de pasajeros
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_guardarUltimoId(char* path, LinkedList* pArrayListPassenger);



/// @brief trae el ultimo ID guardado en el archivo especificado
///
/// @param path -> nombre del archivo
/// @param ultimoId -> puntero donde se guardara el ultimo id
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_traerUltimoId(char* path, int* ultimoId);


/// @brief actualizo el archivo guardando el ultimo ID
///
/// @param path -> nombre del archivo
/// @param pArrayListPassenger -> lista de pasajeros
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_actualizarUltimoId(char* path, LinkedList* pArrayListPassenger);



/// @brief guarda los datos en el csv
///
/// @param pFile -> puntero al archivo abierto
/// @param pArrayListPassenger -> lista de pasajeros
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_guardarComoTexto(FILE* pFile, LinkedList* pArrayListPassenger);



/// @brief guarda los datos en el .bin
///
/// @param pFile -> puntero al archivo abierto
/// @param pArrayListPassenger -> lista de pasajeros
/// return en caso de exito(0) , en caso de error (-1)
int Passenger_guardarComoBinario(FILE* pFile, LinkedList* pArrayListPassenger);


/// @brief Verifica la igualda del codigo de vuelo
///
/// @param pElement -> pasajero
/// @param codigoVuelo -> criterio a comparar
/// @return en caso de igualdad (TRUE), en caso contrario (FALSE)
int Passenger_verificarIgualdadCodigoVuelo(Passenger* pPasajero, char* codigoVuelo);


/// @brief Verifica la igualdad del tipoPasajero
///
/// @param pPasajero -> puntero de pasajero
/// @param tipoPasajero -> tipo pasajero a verificar
/// @return En caso de igualdad (1), en caso contrario (0)
int Passenger_verificarIgualdadTipoPasajero(Passenger* pPasajero, int tipoPasajero);



/// @brief Imprime la cantidad de pasajeros por cara tipoClase
///
/// @param firstClass -> cantidad de primera clase
/// @param executiveClass -> cantidad clase ejecutiva
/// @param economyClass -> cantidad clase economica
int Passenger_imprimirCantidadTipoPasajero(int firstClass, int executiveClass, int economyClass);



void Passenger_listarPasajeroConMillas(Passenger* pPasajero);



#endif /* PASSENGER_H_ */
