/*
 * utn.c
 *
 *  Created on: 9 jul. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * \brief Función que solicita y valida el ingreso de un número al usuario.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la función.
 * \param mensaje Mensaje que pide el ingreso de un número.
 * \param mensajeError Mensaje que se muestra al ingresarse un número no valido.
 * \param minimo valor mínimo del rango.
 * \param maximo valor máximo del rango.
 * \param reintentos Cantidad de reintentos que tiene el usuario en caso de ingresar un número no valido.
 * \return Retorna 0 si se obtuvo un numero valido, -1 si no.
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
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
 * \brief Función que valida y calcula el promedio de edades, para luego devolver el resultado por referencia.
 *
 * \param pPromedioEdad Puntero al espacio de memoria donde se va a guardar el resultado de la función.
 * \param len Tamaño del array recibido.
 * \return Retorna 0 si se pudo calcular el promedio, -1 si no.
 *
 */
int utn_promediarArrayIntV2(float* pPromedioEdad, int arrayEdades[], int len)
{
	int retorno = -1;
	int i;
	float promedio;
	int acumulador = 0;
	int contadorEdadesIngresadas = 0;

	if(pPromedioEdad != NULL && arrayEdades != NULL && len > 0)
	{
		retorno = 0;
		for(i=0; i<len; i++)
		{
			if(arrayEdades[i] > -1)
			{
				contadorEdadesIngresadas++;
				acumulador = acumulador + arrayEdades[i];
			}
		}
		promedio = (float)acumulador / contadorEdadesIngresadas;
		*pPromedioEdad = promedio;
	}
	return retorno;
}

/**
 *
 *
 */
int utn_buscarMinMaxArrayInt(int* arrayInt, int len, int* menor, int* mayor)
{
	int retorno = -1;
	int indiceArray;
	int numeroMin;
	int numeroMax;

	if(arrayInt != NULL && len > 0 && menor != NULL && mayor != NULL)
	{
		retorno = 0;
		for(indiceArray = 0; indiceArray < len; indiceArray++)
		{
			if(indiceArray == 0)
			{
				numeroMin = arrayInt[indiceArray];
				numeroMax = arrayInt[indiceArray];
			}
			else if(arrayInt[indiceArray] < numeroMin)
			{
				numeroMin = arrayInt[indiceArray];
			}
			else if(arrayInt[indiceArray] > numeroMax)
			{
				numeroMax = arrayInt[indiceArray];
			}
		}
		*menor = numeroMin;
		*mayor = numeroMax;
	}
	return retorno;
}
