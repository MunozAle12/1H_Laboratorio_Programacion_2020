/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int* pResultado);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);

/**
 * \brief Solicita y valida el ingreso de un numero al usuario, para luego devolver el resultado por referencia.
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la función.
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

    if(myGets(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString))
    {
    	retorno = 0;
    	*pResultado = atoi(bufferString);
    }
    return retorno;
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
	int retorno = 1;
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}
	for( ; cadena[i]!='\0'; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
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
	fflush(stdin);
	fgets(cadena, longitud, stdin);
	cadena[strlen(cadena)-1] = '\0';

	return 0;
}

/*
 * \brief Función que recibe dos numeros enteros y calcula el mayor de ellos.
 *
 * \param pResultado Puntero a espacio de memoria donde se guardará el resultado de la función.
 * \param primerNumero Primer numero entero a comparar.
 * \param segundoNumero Segundo numero entero a comparar.
 * \return Retona 0 si se encontró un número mayor, 1 si son iguales, -1 si hay error.
 *
 */
int utn_calcularMayor(int* pResultado, int primerNumero, int segundoNumero)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		if(primerNumero == segundoNumero)
		{
			retorno = 0;
		}
		else
		{
			retorno = 1;
			if(primerNumero > segundoNumero)
			{
				*pResultado = primerNumero;
			}
			else
			{
				*pResultado = segundoNumero;
			}
		}
	}
	return retorno;
}
