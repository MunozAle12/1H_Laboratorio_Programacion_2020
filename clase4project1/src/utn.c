/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Funci�n que solicita y valida el ingreso de un n�mero al usuario.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la funci�n.
 * \param mensaje Mensaje que pide el ingreso de un n�mero.
 * \param mensajeError Mensaje que se muestra al ingresarse un n�mero no valido.
 * \param minimo valor m�nimo del rango.
 * \param maximo valor m�ximo del rango.
 * \param reintentos Cantidad de reintentos que tiene el usuario en caso de ingresar un n�mero no valido.
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
 * \brief Funci�n que solicita y valida el ingreso de un n�mero decimal al usuario.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la funci�n.
 * \param mensaje Mensaje que pide el ingreso de un n�mero.
 * \param mensajeError Mensaje que se muestra al ingresarse un n�mero no valido.
 * \param minimo valor m�nimo del rango.
 * \param maximo valor m�ximo del rango.
 * \param reintentos Cantidad de reintentos que tiene el usuario en caso de ingresar un n�mero no valido.
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
 * \brief Funci�n que solicita y valida el ingreso de un caracter al usuario.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la funci�n.
 * \param mensaje Mensaje que pide el ingreso de un caracter.
 * \param mensajeError Mensaje que se muestra al ingresarse un caracter no valido.
 * \param minimo valor m�nimo del rango.
 * \param maximo valor m�ximo del rango.
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
