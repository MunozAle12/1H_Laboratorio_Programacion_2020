/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
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

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
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
 * \brief Función que solicita y valida el ingreso de un número decimal al usuario.
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
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
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
 * \brief Función que solicita y valida el ingreso de un caracter al usuario.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la función.
 * \param mensaje Mensaje que pide el ingreso de un caracter.
 * \param mensajeError Mensaje que se muestra al ingresarse un caracter no valido.
 * \param minimo valor mínimo del rango.
 * \param maximo valor máximo del rango.
 * \param reintentos Cantidad de reintentos que tiene el usuario en caso de ingresar un caracter no valido.
 * \return Retorna 0 si se obtuvo un caracter valido, -1 si no.
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	char bufferChar;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
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
 * \brief Genera un número aleatorio.
 *
 * \param desde Número aleatorio mínimo.
 * \param desde Número aleatorio máximo.
 * \param iniciar Indica si se trata del primer número solicitado, 1 indica que si.
 * \return Retorna el número aleatorio generado.
 *
 */
char utn_getNumeroAleatorio(int desde, int hasta, int iniciar)
{
	if(iniciar)
	{
		srand(time(NULL));
	}
	return desde + (rand() % (hasta + 1 - desde));
}
