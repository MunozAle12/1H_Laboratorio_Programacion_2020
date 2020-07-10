/*
 * utn.h
 *
 *  Created on: 9 jul. 2020
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_promediarArrayIntV2(float* pPromedioEdad, int arrayEdades[], int len);
int utn_buscarMinMaxArrayInt(int* arrayInt, int len, int* menor, int* mayor);

#endif /* UTN_H_ */
