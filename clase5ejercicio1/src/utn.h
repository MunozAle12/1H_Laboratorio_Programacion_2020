/*
 * utn.h
 *
 *  Created on: 7 abr. 2020
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
void utn_imprimirArrayInt(int arrayInt[],int len);
void utn_imprimirArrayFloat(float arrayFloat[],int len);
void utn_imprimirArrayChar(char arrayChar[],int len);
float utn_promediarArrayInt(int arrayInt[],int len);//Pasaje por valor
int utn_promediarArrayIntV2(float* pPromedioEdad,int arrayInt[],int len); //Pasaje por referencia
int utn_promediarArrayFloat(float* pPromedioEdad,float arrayFloat[],int len); //Pasaje por referencia

#endif /* UTN_H_ */
