/*
 * utn.c
 *
 *  Created on: 22 abr. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena, int limite);
static int getFloat(float* pResultado);

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}
/**
 * \brief getInt Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if(pResultado != NULL && myGets(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString, sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;
	}
    return retorno;
}
/**
 * \brief 	Guarda la lectura destdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* pCadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096]; // *****************************

	if(pCadena != NULL && longitud > 0)
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
				strncpy(pCadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* pCadena, int limite)
{
	int retorno = -1; // ERROR
	int i;

	if(pCadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0; pCadena[i]!='\0' && i<limite; i++)
		{
			if(i == 0 && (pCadena[i] == '+' || pCadena[i] == '-'))
			{
				continue;
			}
			if(pCadena[i] < '0' || pCadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if( pResultado!=NULL &&
    	myGets(bufferString, sizeof(bufferString) == 0) &&
		esFlotante(bufferString, sizeof(bufferString)) )
    {
    	retorno = 0;
    	*pResultado = atof(bufferString);
    }
    return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante, 0 (falso) si no lo es o -1 (ERROR) si error.
 *
 */
static int esFlotante(char* pCadena, int limite)
{
	int retorno = -1;
	int i;
	int contadorPunto = 0;

	if(pCadena!=NULL && limite>0)
	{
		retorno = 1;
		for(i=0; pCadena[i]!='\0' && i<limite; i++)
		{
			if(i == 0 && (pCadena[i] == '+' || pCadena[i] == '-' || pCadena[i] == '.'))
			{
				if(pCadena[i] == '.')
				{
					contadorPunto++;
				}
				continue;
			}
			if(pCadena[i]<'0' || pCadena[i]>'9')
			{
				if(pCadena[i] == '.')
				{
					contadorPunto++;
					if(contadorPunto>1)
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
	}
	return retorno;
}
