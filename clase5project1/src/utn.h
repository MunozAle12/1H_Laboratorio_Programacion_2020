/*
 * utn.h
 *
 *  Created on: 7 abr. 2020
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
void utn_imprimirArrayInt(int arrayInt[], int len);
int utn_promediarArrayIntV2(float* pPromedioEdad, int arrayEdades[], int len); //Pasaje por referencia
float utn_promediarArrayInt(int arrayEdades[],int len);//Pasaje por valor

//void utn_imprimirArrayFloat(float arrayFloat[],int len);
//void utn_imprimirArrayChar(char arrayChar[],int len);
//int utn_promediarArrayFloat(float* pPromedioEdad,float arrayFloat[],int len); //Pasaje por referencia

#endif /* UTN_H_ */
