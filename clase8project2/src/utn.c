/*
 * utn.c
 *
 *  Created on: 26 jul. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena, int longitud);
static int getInt(int* pResultado);

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 		  un máximo de 'longitud - 1' caracteres.
 *
 * \param cadena Es el puntero al espacio de memoria donde se guardará la cadena obtenida.
 * \param longitud Es el valor que define el tamaño de cadena.
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				retorno = 0;
				strncpy(cadena, bufferString, longitud);
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado.
 *
 * \param pResultado Es el puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de Error a ser mostrado.
 * \param minimo Es el numero maximo a ser aceptado.
 * \param maximo Es el minimo minimo a ser aceptado.
 * \return Retorna 0 si se obtuvo el numero y -1 si no.
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(	!getInt(&bufferInt) &&
				bufferInt >= minimo &&
				bufferInt <= maximo )
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Busca y verifica si se ingresó un número entero para luego guardar su resultado por referencia.
 *
 * \param pResultado Es el puntero al espacio de memoria donde se dejara el resultado de la función.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero, -1 (ERROR) si no.
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[50];
    if(pResultado != NULL)
    {
		if( !myGets(bufferString, sizeof(bufferString)) &&
			esNumerica(bufferString, sizeof(bufferString)) )
		{
			retorno = 0;
			*pResultado = atoi(bufferString);
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es válida como numerica, luego la retorna por referencia.
 *
 * \param cadena Es el puntero al espacio de memoria donde empieza la cadena de caracteres a ser analizada.
 * \param longitud Es el valor que representa a la longitud en bytes de la cadena.
 * \return Retorna -1 si hubo error, 1 (vardadero) si la cadena es numerica o 0 (falso) si no lo es.
 *
 */
static int esNumerica(char* cadena, int longitud)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && longitud > 0)
	{
		retorno = 1;
		for(i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
