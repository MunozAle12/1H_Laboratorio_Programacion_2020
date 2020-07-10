/*
 * utn.c
 *
 *  Created on: 25 abr. 2020
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Función que pide y valida el ingreso de un numero entero, retornando el resultado por referencia.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la función.
 * \param mensaje Mensaje a ser mostrado para pedir el ingreso de numero.
 * \param mensajeError Mensaje a ser mostrado en caso de ingresar un numero no valido.
 * \param minimo Valor minimo del rango permitido.
 * \param maximo Valor maximo del rango permitido.
 * \param reintentos Cantidad de reintentos en caso de ingresar un numero no valido.
 * \return Retorna 0 si se ingresó un numero valido, -1 si no.
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				reintentos--;
				printf("%s",mensajeError);
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Función que imprime los elementos del array.
 *
 * \param pArray Puntero al espacio de memoria donde comienza el array.
 * \param len Tamaño del array.
 * \return No retorna nada.
 *
 */
void printArray(int* pArray, int len)
{
	int i;

	for(i=0; i<len; i++)
	{
		printf("[DEBUG] INDEX: %d - VALUE: %d\n", i, pArray[i]);
	}
}
/**
 * \brief Función que ordena los elementos del array de forma descendente.
 *
 * \param pArray Puntero al espacio de memoria donde comienza el array.
 * \param len Tamaño del array a ordenar.
 * \return Retorna 0 si se ordenó el array, -1 si hubo error.
 *
 */
int ordenarArrayInt(int* pArray, int len)
{
	int retorno = -1;
	int i;
	int flagSwap;
	int buffer;
	int contadorIteraciones = 0;
	int limiteComparacion;
	if(pArray != NULL && len > 0)
	{
		retorno = 0;
		limiteComparacion = len - 1;
		do
		{
			flagSwap = 0;
			for(i=0; i<limiteComparacion; i++)
			{
				contadorIteraciones++;
				if(pArray[i] < pArray[i+1])	//Descendente
				{
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
					flagSwap = 1;
				}
			}
			limiteComparacion--;
		}while(flagSwap);
		retorno = contadorIteraciones;
	}
	return retorno;
}
/*
void intSwap(int* pNumeroA, int* pNumeroB)
{
	int buffer;

	buffer = *pNumeroA;
	*pNumeroA = *p
}
*/
