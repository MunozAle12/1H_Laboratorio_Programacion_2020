/*
 * utn.h
 *
 *  Created on: 25 abr. 2020
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

void printArray(int* pArray, int len);
int ordenarArrayInt(int* pArray, int len);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_H_ */
