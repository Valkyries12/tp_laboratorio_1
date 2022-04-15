/*
 * utn.h
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */

#ifndef UTN_H_
#define UTN_H_


/// @brief Solicita un número al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pNumeroIngresado Puntero al resultado alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor mínimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief Solicita una letra al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pCaracterIngresado Puntero al resultado alli se dejara el caracter ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor mínimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getCaracter(int * pCaracterIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief Solicita usuario y contraseña,lo valida, verifica y devuelve un resultado
///
/// @param pIsLogged Puntero al resultado alli se dejará TRUE o FALSE si fue logeado o no
/// @param intentosMaximos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_loguear(int * pIsLogged, int intentosMaximos);



#endif /* UTN_H_ */
