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

/// @brief Solicita un número flotante al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pNumeroIngresado Puntero al resultado alli se dejara el numero ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor mínimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, float maximo, float minimo, int maximoDeReintentos);

/// @brief Solicita una letra al usuario, lo valida, verifica y devuelve el resultado
///
/// @param pCaracterIngresado Puntero al resultado alli se dejara el caracter ingresado por el usuario
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje a ser mostrado en caso de error
/// @param maximo Valor maximo aceptado
/// @param minimo Valor mínimo aceptado
/// @param maximoDeReintentos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_getCaracter(char * pCaracterIngresado,char * mensaje,char * mensajeError, int maximo, int minimo, int maximoDeReintentos);

/// @brief Solicita usuario y contraseña,lo valida, verifica y devuelve un resultado
///
/// @param pIsLogged Puntero al resultado alli se dejará TRUE o FALSE si fue logeado o no
/// @param intentosMaximos Cantidad de reintentos en caso de error
/// @return En caso de exito (0), en caso de error (-1)
int utn_loguear(int * pIsLogged, int intentosMaximos);



/// @brief Hace un n% descuento, lo verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace el descuento
/// @param descuento -> porcentaje a descontar sobre el monto
/// @param pValorFinal -> Puntero al resultado, alli se dejará el monto final con el descuento correspondiente
/// @return En caso de exito (0), en caso de error (-1)
int utn_hacerDescuento(float monto, int descuento, float * pValorFinal);



/// @brief Agrega un n% de interes, lo verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace el descuento
/// @param interes -> porcentaje a agregar sobre el monto
/// @param pValorFinal -> Puntero al resultado, alli se dejará el monto final con el descuento correspondiente
/// @return En caso de exito (0), en caso de error (-1)
int utn_sumarInteres(float monto, int interes, float * pValorFinal);


/// @brief calcula el costo del pasaje en Bitcoin, verifica , valida y devuelve un resultado
///
/// @param monto -> monto necesario sobre el que se hace la conversion de divisas
/// @param precioBitcoin -> precio del bitcoin actual
/// @param pValorFinal -> putenro al resultado, alli se dejara la conversion final de divisas
/// @return En caso de exito (0), en caso de error (-1)
int utn_calcularAPrecioBitcoin(float monto, float precioBitcoin, float * pValorFinal);


/// @brief calcula el precio unitario del km, verifica y valida, devuelve un resultado
///
/// @param kilometro -> kilometros ingresados
/// @param precio -> precio total del vuelo
/// @param pValorFinal -> puntero al resultado, alli se dejara el precio unitario
int utn_calcularPrecioPorKilometro(int kilometro, float precio, float * pValorFinal);


/// @brief Verifica si la respuesta recibida es exitosa (0) o erratica(1)
///
/// @param respuesta -> respuesta 0 exitosa o 1 invalida
/// @param pHayError -> puntero al resultado, alli se dejara 1 si la respuesta es erratica o 0 si es exitosa
/// @return no retorna nada
void utn_verificarSiHayError(int respuesta, int * pHayError);


/// @brief Verifica si la respuesta es exitosa o no y en base a ello imprime un mensaje
///
/// @param hayError -> respuesta para verificacion (0) es exito y (-1) error
/// @param mensaje -> Es el mensaje a ser mostrado en caso de exito
/// @param mensajeError -> Es el mensaje a ser mostrado en caso de error
/// @return no retorna nada
void utn_imprimirMensajes(int hayError, char * mensaje, char * mensajeError);




#endif /* UTN_H_ */
