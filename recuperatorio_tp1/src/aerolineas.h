/*
 * aerolineas.h
 *
 *  Created on: 15 abr 2022
 *      Author: Nicol�s Caruso
 */

#ifndef AEROLINEAS_H_
#define AEROLINEAS_H_

/// @brief Imprime el informe de los costos
///
/// @param nombreAerolinea -> nombre de la aerolinea
/// @param precio -> tarifa del vuelo
/// @param precioConDescuento -> precio total pagado con debito
/// @param precioConInteres -> precio total pagado con credito
/// @param precioBTC -> precio total pagado en BTC
/// @param precioUnitario -> valor por kilometro
/// @return no retorna nada
void imprimirInformeDeCostos(char * nombreAerolinea, float precio, float precioConDescuento, float precioConInteres, float precioBTC, float precioUnitario);


/// @brief Imprime el men�
///
/// @param kilometros -> km actuales
/// @param precioAerolinea -> precio final de aerolinea
/// @param precioLatam -> precio final latam
/// @return no retorna nada
void imprimirMenu(float kilometros, float precioAerolinea, float precioLatam);



/// @brief Realiza la carga forzada
///
/// @return en caaso de exito (0), en caso de error (-1)
int hacerCargaForzada(void);

#endif /* AEROLINEAS_H_ */
