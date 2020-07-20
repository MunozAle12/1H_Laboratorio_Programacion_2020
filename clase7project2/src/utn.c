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
static int getFloat(float* pResultado);
static int esNumericaFloat(char* cadena);

/**
 * \brief Solicita y valida el ingreso de un numero entero al usuario, luego devuelve el resultado por referencia.
 *
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de Error a ser mostrado.
 * \param minimo Es el numero máximo a ser aceptado.
 * \param maximo Es el minimo mínimo a ser aceptado.
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
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la función.
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

/**
 * \brief Solicita y valida el ingreso de un numero flotante al usuario, luego devuelve el resultado por referencia.
 *
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de Error a ser mostrado.
 * \param minimo Es el numero maximo a ser aceptado.
 * \param maximo Es el minimo minimo a ser aceptado.
 * \return Retorna 0 si se obtuvo el numero y -1 si no.
 *
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				reintentos--;
				printf("%s", mensajeError);
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
/**
 * \brief getInt busca y verifica si lo que se ingresó es un número.
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la función.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no.
 *
 */
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(myGets(bufferString, sizeof(bufferString)) == 0 && esNumericaFloat(bufferString))
        {
        	retorno = 0;
        	*pResultado = atof(bufferString);
        }
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
static int esNumericaFloat(char* cadena)
{
	int retorno = -1;
	int i = 0;
	int contadorPunto = 0;
	if(cadena != NULL)
	{
		retorno = 1;
		if(cadena[0] == '-' || cadena[0] == '+' || cadena[0] == '.')
		{
			i = 1;
			if(cadena[0] == '.')
			{
				contadorPunto++;
			}
		}
		for( ; cadena[i] != '\0'; i++)
		{
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.')
			{
				retorno = 0;
				break;
			}
			if(cadena[i] == '.')
			{
				contadorPunto++;
				continue;
			}
		}
		if(contadorPunto > 1)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Imprime los elementos del array recibido.
 *
 * \param arrayFloat[] Es el puntero al espacio de memoria donde comienza el array de numeros flotantes.
 * \param len Es el tamaño del array.
 * \return Retorna 0 si se pudo imprimir OK, -1 si hubo error.
 *
 */
int utn_imprimirArrayFloat(float arrayFloat[], int len)
{
	int retorno = -1;
	int i;
	if(arrayFloat != NULL && len > 0)
	{
		retorno = 0;
		//Recorro de forma secuncial para imprimir
		printf("\n______________________________\n\n");
		for(i = 0; i < len; i++)
		{
			printf("Índice %d: %.2f\n", i, arrayFloat[i]);
		}
		printf("\n______________________________\n");
	}
	return retorno;
}
