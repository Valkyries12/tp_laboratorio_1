/*
 * operaciones_aritmeticas.h
 *
 *  Created on: 14 abr 2022
 *      Author: Nicolás Caruso
 */

#ifndef OPERACIONES_ARITMETICAS_H_
#define OPERACIONES_ARITMETICAS_H_

/// @brief recibe dos numeros flotante y devuelve el resultado
///
/// @param num1 -> operando a sumar
/// @param num2 -> operando a sumar
/// @return suma de numero flotantes
float sumarNumeroFlotante(float num1, float num2);


/// @brief resta dos numeros flotantes, valida y verifica. Devuelve el resultado
///
/// @param num1 -> operando a restar
/// @param num2 -> operando a restar
/// @param pResultado -> puntero al resultado, alli se pondra el resultado
/// @return devuelve (0) en caso de exito y (-1) en caso de error
int restarNumeroFlotante(float num1, float num2, float * pResultado);


#endif /* OPERACIONES_ARITMETICAS_H_ */
