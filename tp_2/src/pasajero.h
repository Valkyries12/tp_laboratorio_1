/*
 * pasajero.h
 *
 *  Created on: 10 may 2022
 *      Author: Nicolás Caruso
 */

#ifndef PASAJERO_H_
#define PASAJERO_H_
#define TRUE 1
#define FALSE 0

typedef struct {
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int isEmpty;
}Pasajero;


/// @brief  Inicializa cada pasajero del array. Setea isEmpty en TRUE
///
/// @param arr -> array de pasajeros
/// @param len -> longitud del array
/// @return Retorna (0) en caso de exito, (-1) en caso de error
int inicializarPasajeros(Pasajero arr[], int len);


/// @brief Busca el indice del primer pasajero encontrado que tenga la propiedad isEmpty en TRUE
///
/// @param arr -> array de asociados
/// @param len -> longitud del array
/// @return retorna el indice del asociado en caso de encontrarlo. Si no (-1)
int buscarEspacioLibre(Pasajero arr[], int len);


/// @brief Busca el indice del pasajero mediante un id
///
/// @param arr -> array de pasajeros
/// @param id -> id del pasajero
/// @param len -> longitud del array
/// @return -> En caso de encontrarlo devuelve el indice, en caso de no encontrarlo (-1)
int buscarPasajeroPorId(Pasajero arr[], int id, int len);


/// @brief Carga un pasajero al array en el primer indice disponible
///
/// @param arr -> array de pasajeros
/// @param len -> longitud del array
/// @param id -> id autoincremental
/// @param nombre -> nombre del pasajero
/// @param apellido -> apellido del pasajero
/// @param precio -> precio del vuelo
/// @param tipoPasajero -> PRIMERA_CLASE (1), EJECUTIVO (2), PREMIUM (3)
/// @param codigoVuelo -> valor alfanumerico
/// @return En caso de exito (0), en caso de error (-1)
int agregarPasajero(Pasajero arr[], int len, int id, char * nombre, char * apellido, float precio, int tipoPasajero, char * codigoVuelo );


/// @brief Elimina un pasajero del array
///
/// @param arr -> array de pasajeros
/// @param id -> id del pasajero a eliminar
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int eliminarPasajero(Pasajero arr[], int id, int len);


/// @brief Modifica nombre o apellido o precio o tipoPasajero o codigoVuelo del pasajero
///
/// @param arr -> array de pasajeros
/// @param id ->id del pasajero a modificar
/// @param opcionMenu -> opcion a modificar
/// @param len -> longitud del array
/// @return En caso de exito (0), en caso de error (-1)
int modificarPasajero(Pasajero arr[], int id, int opcionMenu, int len);


/// @brief Verifica si al menos hay 1 pasajero
///
/// @param arr -> array de pasajeros
/// @param len -> longitud del array
/// @return En caso de haber al menos un asociado TRUE (1), sino FALSE (0)
int hayAlgoCargado(Pasajero arr[], int len);


/// @brief Verifica si existe o no el pasajero en base al id proporcionado
///
/// @param arr -> array de pasajeros
/// @param len -> longitud del array
/// @param id -> id del pasajero a verificar su existencia
/// @return En caso de existir devuelve TRUE (1), en caso contraro FALSE (0)
int existePasajero(Pasajero arr[], int len, int id);


/// @brief Incrementa el id por un, lo hace autoincremental
///
int incrementarId(void);

#endif /* PASAJERO_H_ */
