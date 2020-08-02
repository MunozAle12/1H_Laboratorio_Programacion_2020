/*
 * Persona.c
 *
 *  Created on: 28 jul. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

/**
 * \brief Inicializa array del tipo Personas con un valor conocido.
 *
 * \param arrayPersonas[] Es el puntero a espacio de memoria donde comienza el array a inicializar.
 * \param len Es el tamaño del array.
 * \return Retorna -1 si hubo error, 0 si se inicializó con éxito.
 *
 */
int pers_inicializarArrayPersonas(Persona* arrayPersonas, int len)
{
	int respuesta = -1;
	int i;

	if(arrayPersonas != NULL && len > 0)
	{
		respuesta = 0;
		for(i = 0; i < len; i++)
		{
			arrayPersonas[i].isEmpty = TRUE;
		}
	}
	return respuesta;
}

/**
 * \brief Busca un valor conocido en el array del tipo Personas y al encontrar la primer ocurrencia, retorna su índice.
 *
 * \param arrayPersonas Es el puntero a espacio de memoria donde comienza el array a analizar.
 * \param len Es el tamaño del array.
 * \return Retorna -1 si hubo error o no hubo una ocurrencia.
 * 		   Retorna un valor mayor-igual a 0 si encontró el valor buscado.
 *
 */
int pers_buscarIndiceLibreArrayPersonas(Persona* arrayPersonas, int len)
{
	int respuesta = -1;
	int i;

	if(arrayPersonas != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(arrayPersonas[i].isEmpty == TRUE)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Busca un valor conocido en el array del tipo int y al encontrar la primer ocurrencia, retorna su índice.
 *
 * \param arrayPersonas Es el puntero a espacio de memoria donde comienza el array a analizar.
 * \param len Es el tamaño del array.
 * \param valorBuscado Es el valor del tipo entero que se va a buscar en el array.
 * \return Retorna -1 si hubo error o no hubo una ocurrencia.
 * 		   Retorna un valor mayor-igual a 0 si encontró el valor buscado.
 *
 */
int pers_buscarLegajo(Persona* arrayPersonas, int len, int valorBuscado)
{
	int respuesta = -1;
	int i;

	if(arrayPersonas != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if( arrayPersonas[i].isEmpty != TRUE &&
				arrayPersonas[i].legajo == valorBuscado )
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Muestra por pantalla los datos guardados de las personas en la agenda.
 *
 * \param arrayPersonas Es el puntero a espacio de memoria donde empieza el array.
 * \param longitud Es el valor que define el tamaño de arrayPersonas.
 * \return Retorna 0 si se pudo imprimir, -1 si hubo error.
 *
 */
int pers_imprimirAgenda(Persona* arrayPersonas, int longitud)
{
	int retorno = -1;
	int i;

	if(arrayPersonas != NULL && longitud > 0)
	{
		retorno = 0;
		for(i = 0; i < longitud; i++)
		{
			if(arrayPersonas[i].isEmpty != TRUE)
			{
				printf("  %d  -  %s  -  %s\n", arrayPersonas[i].legajo, arrayPersonas[i].nombre, arrayPersonas[i].apellido);
			}
		}
	}
	return retorno;
}

/**
 * \brief Ordena la agenda por apellido de forma ascendente (de A-Z).
 *
 * \param arrayPersonas Puntero al espacio de memoria donde empieza el array a ser analizado.
 * \param longitud Es el valor que representa la longitud del array.
 * \return Retorna -1 si hubo error, 0 si se ordeno la agenda con éxito.
 *
 */
int pers_ordenarAgendaPorApellido(Persona* arrayPersonas, int longitud)
{
	int retorno = -1;
	int i, j;
	int flagSwap;	//Bandera que indica, 1 si se hizo al menos un swap, 0 si no.
	Persona auxiliarPersona;	//Variable auxiliar utilizada para guardar el valor a salvar para hacer el swap.
	int limiteComparacion;	//Variable utilizada para indicar el límite de comparación de valores de índices.

	if(arrayPersonas != NULL && longitud > 0)
	{
		retorno = 0;
		limiteComparacion = longitud - 1;
		do
		{
			flagSwap = FALSE;
			for(i = 0; i < limiteComparacion; i++)
			{
				if(arrayPersonas[i].isEmpty == TRUE)
				{
					continue;
				}
				for(j = i + 1; j < limiteComparacion; j++)
				{
					if(arrayPersonas[j].isEmpty == TRUE)
					{
						continue;
					}
					if(strncmp(arrayPersonas[i].apellido, arrayPersonas[j].apellido, SIZE) > 0) //Ascendente (A - Z)
					{
						auxiliarPersona = arrayPersonas[i];
						arrayPersonas[i] = arrayPersonas[j];
						arrayPersonas[j] = auxiliarPersona;
						flagSwap = TRUE;
					}
				}
			}
			limiteComparacion--;
		}while(flagSwap);
	}
	return retorno;
}
