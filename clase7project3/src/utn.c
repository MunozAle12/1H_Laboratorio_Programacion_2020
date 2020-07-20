/*
 * utn.c
 *
 *  Created on: 27 abr. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado.
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
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
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}
/**
 * \brief getInt busca y verifica si lo que se ingresó es un número.
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no.
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL)
    {
        if(myGets(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString))
        {
        	retorno = 0;
        	*pResultado = atoi(bufferString);
        }
    }
    return retorno;
}
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 *
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida.
 * \param longitud Define el tamaño de cadena.
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
static int myGets(char* cadena, int longitud)
{
	int respuesta = -1;
	if(cadena != NULL && longitud > 0)
	{
		respuesta = 0;
		fflush(stdin);
		fgets(cadena, longitud, stdin);
		cadena[strlen(cadena)-1] = '\0';
	}
	return respuesta;
}
/**
 * \brief Verifica si la cadena ingresada es numerica.
 *
 * \param cadena Cadena de caracteres a ser analizada.
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es.
 *
 */
static int esNumerica(char* cadena)
{
	int retorno = -1;
	int i = 0;
	if(cadena != NULL)
	{
		retorno = 1;
		if(cadena[0] == '-' || cadena[0] == '+')
		{
			i = 1;
		}

		for( ; cadena[i] != '\0'; i++)
		{
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es válida como número flotante.
 *
 * \param cadena Cadena de caracteres a ser analizada.
 * \return Retorna 1 (vardadero) si la cadena es un número flotante, 0 (falso) si no lo es, -1 si es.
 *
 */
int validarFlotante(char* cadena)
{
	int retorno = -1;
	int i = 0;
	int contadorPuntos = 0;

	if(cadena != NULL)
	{
		retorno = 1;
		for( ; cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+' || cadena[i] == '.'))
			{
				if(cadena[i] == '.')
				{
					contadorPuntos++;
				}
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.')
				{
					contadorPuntos++;
					if(contadorPuntos > 1)
					{
						retorno = 0;
						break;
					}
					continue;
				}
				retorno = 0;
				break;
			}
		}
		if(contadorPuntos == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}
