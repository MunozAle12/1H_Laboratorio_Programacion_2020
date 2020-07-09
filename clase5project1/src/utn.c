/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>

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
 * \brief Función que imprime los elementos del array recibido.
 *
 * \param arrayInt[] Espacio de memoria donde comienza el array.
 * \param len Tamaño del array recibido.
 * \return No retorna nada.
 *
 */
void utn_imprimirArrayInt(int arrayInt[], int len)
{
	int i;
	//Recorro de forma secuncial para imprimir
				//len = largo, longitud
	for(i=0; i<len; i++)
	{
		printf("Indice: %d - Elemento %d: - Valor: %d\n", i, i+1, arrayInt[i]);
	}
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
 * \brief Función que calcula el promedio de edades, para luego devolver el resultado por valor.
 *
 * \param arrayEdades[] Espacio de memoria donde comienza el array recibido.
 * \param len Tamaño del array recibido.
 * \return Retorna el resultado de la función.
 *
 */
float utn_promediarArrayInt(int arrayEdades[], int len)
{
	int i;
	float promedio;
	int acumulador = 0;
	int contadorEdadesIngresadas = 0;

	for(i=0; i<len; i++)
	{
		if(arrayEdades[i] > -1)
		{
			contadorEdadesIngresadas++;
			acumulador = acumulador + arrayEdades[i];
		}
	}
	promedio = (float)acumulador / contadorEdadesIngresadas;
	return promedio;
}

/**
 * \brief Función que imprime los elementos del array recibido.
 *
 * \param arrayFloat[] Espacio de memoria donde comienza el array.
 * \param len Tamaño del array recibido.
 * \return No retorna nada.
 *
 */
/*
void utn_imprimirArrayFloat(float arrayFloat[], int len)
{
	int i;
	//Recorro de forma secuncial para imprimir
	for(i=0; i<len; i++)
	{
		printf("Indice: %d - Elemento %d: - Valor: %f\n", i, i+1, arrayFloat[i]);
	}
}
*/

/**
 * \brief Función que imprime los elementos del array recibido.
 *
 * \param arrayChar[] Espacio de memoria donde comienza el array.
 * \param len Tamaño del array recibido.
 * \return No retorna nada.
 *
 */
/*
void utn_imprimirArrayChar(char arrayChar[], int len)
{
	int i;
	//Recorro de forma secuncial para imprimir
	for(i=0; i<len; i++)
	{
		printf("Indice: %d - Elemento %d: - Valor: %c\n", i, i+1, arrayChar[i]);
	}
}
*/

/**
 * \brief Función que valida y calcula el promedio de los elementos del array recibido, para luego devolver el resultado por referencia.
 *
 * \param pResultado Puntero al espacio de memoria donde se va a guardar el resultado de la función.
 * \param len Tamaño del array recibido.
 * \return Retorna 0 si se pudo calcular el promedio, -1 si no.
 *
 */
/*
int utn_promediarArrayFloat(float* pResultado, float arrayFloat[], int len)
{
	int i;
	float resultadoPromedio;
	int retorno = -1;
	float acumulador = 0;

	if(pResultado != NULL && arrayFloat != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			acumulador = acumulador + arrayFloat[i];
		}
		retorno = 0;
		resultadoPromedio = acumulador / len;
		*pResultado = resultadoPromedio;
	}
	return retorno;
}
*/
