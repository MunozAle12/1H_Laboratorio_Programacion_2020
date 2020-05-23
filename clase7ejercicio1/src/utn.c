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
static int myGets(char* cadena,int longitud);

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno=-1;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief getInt busca y verifica si lo que se ingresó es un número.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[4096];

    if(myGets(bufferString,sizeof(bufferString))==0 && esNumerica(bufferString))
    {
    	retorno=0;
    	*pResultado=atoi(bufferString);
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
static int esNumerica(char* cadena)
{
	int retorno=1;
	int i=0;

	if(cadena[0]=='-')
	{
		i=1;
	}

	for(;cadena[i]!='\0';i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int myGets(char* cadena,int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[strlen(cadena)-1]='\0';

	return 0;
}


int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int retorno=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferFloat);
			if(bufferFloat>=minimo && bufferFloat<=maximo)
			{
				*pResultado=bufferFloat;
				retorno=0;
				break;
			}
			else
			{
				reintentos--;
				printf("%s",mensajeError);
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	char bufferChar;
	int retorno=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);
			if(bufferChar>=minimo && bufferChar<=maximo)
			{
				*pResultado=bufferChar;
				retorno=0;
				break;
			}
			else
			{
				reintentos--;
				printf("%s",mensajeError);
			}
		}while(reintentos>=0);
	}
	return retorno;
}

void utn_imprimirArrayInt(int arrayInt[],int len)
{
	int i;
	//Recorro de forma secuncial para imprimir
				//len = largo, longitud
	for(i=0;i<len;i++)
	{
		printf("/%d/",arrayInt[i]);
	}
}

void utn_imprimirArrayFloat(float arrayFloat[],int len)
{
	int i;

	//Recorro de forma secuncial para imprimir
	for(i=0;i<len;i++)
	{
		printf("/%f/",arrayFloat[i]);
	}
}

void utn_imprimirArrayChar(char arrayChar[],int len)
{
	int i;

	//Recorro de forma secuncial para imprimir
	for(i=0;i<len;i++)
	{
		printf("/%c/",arrayChar[i]);
	}
}

float utn_promediarArrayInt(int arrayInt[],int len)
{
	int i;
	float resultado;
	int acumulador=0;

	for(i=0;i<len;i++)
	{
		acumulador=acumulador+arrayInt[i];
	}
	resultado=(float)acumulador/len;

	return resultado;
}

int utn_promediarArrayIntV2(float* pPromedioEdad,int arrayInt[],int len)
{
	int i;
	float resultadoPromedio;
	int retorno=-1;
	int acumulador=0;

	if(pPromedioEdad!=NULL && arrayInt!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			acumulador=acumulador+arrayInt[i];
		}
		resultadoPromedio=(float)acumulador/len;
		*pPromedioEdad=resultadoPromedio;
		retorno=0;
	}
	return retorno;
}

int utn_promediarArrayFloatV2(float* pPromedioEdad,float arrayFloat[],int len)
{
	int i;
	float resultadoPromedio;
	int retorno=-1;
	float acumulador=0;

	if(pPromedioEdad!=NULL && arrayFloat!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			acumulador=acumulador+arrayFloat[i];
		}
		resultadoPromedio=acumulador/len;
		*pPromedioEdad=resultadoPromedio;
		retorno=0;
	}
	return retorno;
}
