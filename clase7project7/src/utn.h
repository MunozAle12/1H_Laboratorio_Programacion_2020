/*
 * utn.h
 *
 *  Created on: 20 jul. 2020
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_
#define SIZE 64

int utn_inicializarArrayInt(int arrayInt[], int len, int valor);
int utn_buscarPrimeraOcurrencia(int arrayInt[], int len, int valor);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_imprimirAgenda(char listaNombres[][SIZE], char listaApellidos[][SIZE], int arrayLegajos[], int cantidadPersonas);
int utn_ordenarAgendaPorApellido(char listaNombres[][SIZE], char listaApellidos[][SIZE], int listaLegajos[], int cantidadPersonas);

#endif /* UTN_H_ */
