/*
 * utn.c
 *
 *  Created on: 20 jul. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena);

/**
 * \brief utn_getNumero Funci�n que solicita el ingreso de un n�mero y luego de verificarlo devuelve un resultado.
 *
 * \param pResultado Puntero al espacio de memoria donde se guardar� el n�mero verificado.
 * \param mensaje Mensaje a ser mostrado.
 * \param mensajeError Mensaje a ser mostrado en caso de ingresar un caracter no v�lido.
 * \param minimo Valor minimo del rango aceptado.
 * \param maximo Valor maximo del rango aceptado.
 * \param reintentos Cantidad de reintentos para ingresar un dato v�lido.
 * \return Retorna 0 si se obtuvo un n�mero v�lido, retorna -1 si no.
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
 * \brief getInt Funci�n que busca y verifica si se ingres� un n�mero entero.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la funci�n.
 * \return Retorna 0 si se pudo encontrar un n�mero v�lido, retorna -1 si no.
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(!myGets(bufferString, sizeof(bufferString)) && esNumerica(bufferString))
        {
        	retorno = 0;
        	*pResultado = atoi(bufferString);
        }
    }
    return retorno;
}
/**
 * \brief myGets Funci�n que guarda una lectura del archivo stdin hasta que encuentra un '\0'
 *               o hasta que haya copiado en 'cadena' un m�ximo de 'longitud - 1'.
 *
 * \param pCadena Puntero a espacio de memoria donde se guardar� la cadena de caracteres
 *                que se ingres� por teclado.
 * \param longitud Define el tama�o de pCadena.
 * \return Retorna 0 si se obtiene una cadena, -1 si no.
 *
 */
static int myGets(char* pCadena, int longitud)
{
	int retorno = -1;
	if(pCadena != NULL && longitud > 0)
	{
		retorno = 0;
		fflush(stdin);
		fgets(pCadena, longitud, stdin);
		pCadena[strlen(pCadena) - 1] = '\0';
	}
	return retorno;
}
/**
 * \brief esNumerica Funci�n que verifica si los elementos de la cadena son numericos.
 *
 * \param pCadena Puntero al espacio de memoria donde guarda la cadena de caracteres a ser analizada.
 * \return Retorna 1 si la cadena de caracteres es numerica, 0 si no, -1 si hubo error.
 *
 */
static int esNumerica(char* pCadena)
{
	int retorno = -1;
	int i = 0;
	if(pCadena != NULL)
	{
		retorno = 1;
		if(pCadena[0] == '-' || pCadena[0] == '+')
		{
			i = 1;
		}
		for( ; pCadena[i] != '\0' ; i++)
		{
			if(pCadena[i] > '9' || pCadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief borrarImpares Funci�n que analiza cada elemento del array y convierte su valor en 0 si es impar.
 *
 * \param arrayInt Espacio de memoria donde comienza arrayInt[].
 * \param Define el tama�o de arrayInt[].
 * \return Retorna -1 si hubo error, 1 si pudo convertir de impar a cero, 0 si no hab�a valor para convertir.
 *
 */
int borrarImpares(int arrayInt[], int len)
{
	int retorno = -1;
	int i;
	int flagImpar = 0;

	if(arrayInt != NULL && len > 0)
	{
		//reemplazo impares a cero
		for(i = 0; i < len; i++)
		{
			if((arrayInt[i]%2) != 0)
			{
				arrayInt[i] = 0;
				if(!flagImpar)
				{
					flagImpar = 1;
				}
			}
		}
		retorno = flagImpar;
	}
	return retorno;
}
/**
 * \brief imprimirNumeros Funci�n que muestra por pantalla el valor de cada posici�n del array.
 *
 * \param arrayInt[] Puntero a espacio de memoria donde empieza el array.
 * \param len Define el tama�o de arrayInt.
 * \return Retorna 0 si se pudo imprimir, -1 si hubo error.
 *
 */
int imprimirNumeros(int arrayInt[], int len)
{
	int retorno = -1;
	int i;

	if(arrayInt != NULL && len > 0)
	{
		retorno = 0;
		for(i = 0; i < len; i++)
		{
			printf("\nPosicion #%d: %d\n", i, arrayInt[i]);
		}
	}
	return retorno;
}
/**
 * \brief ordenarArrayInt Funci�n que ordena los valores de cada �ndice de forma ascendente.
 *
 * \param pArrayInt Puntero al espacio de memoria donde se guarda el array a ser analizado.
 * \param len Define el tama�o del array a ser analizado.
 * \return Retorna 0 si se pudo ordenar el array, -1 si no se pudo.
 *
 */
int ordenarArrayInt(int* pArrayInt, int len)
{
	int retorno = -1;
	int i;
	int flagSwap;	//Bandera que indica, 1 si se hizo al menos un swap, 0 si no.
	int bufferAux;	//Variable auxiliar utilizada para guardar el valor a salvar para hacer swap.
	int limiteComparacion;	//Variable utilizada para indicar el l�mite de comparaci�n de valores de �ndices.

	if(pArrayInt != NULL && len > 0)
	{
		retorno = 0;
		limiteComparacion = len - 1;
		do
		{
			flagSwap = 0;
			for(i = 0; i < limiteComparacion; i++)
			{
				while(pArrayInt[i] > pArrayInt[i+1]) //Ascendente
				{
					bufferAux = pArrayInt[i];
					pArrayInt[i] = pArrayInt[i+1];
					pArrayInt[i+1] = bufferAux;
					flagSwap = 1;
				}
			}
			limiteComparacion--;
		}while(flagSwap);
	}
	return retorno;
}
