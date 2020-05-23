/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int retorno=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
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
		printf("Índice %d: %d\n",i,arrayInt[i]);
	}
}

void utn_imprimirArrayFloat(float arrayFloat[],int len)
{
	int i;

	//Recorro de forma secuncial para imprimir
	for(i=0;i<len;i++)
	{
		printf("Índice %d: %f\n",i,arrayFloat[i]);
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

int utn_promediarArrayFloatV2(float* pPromedioEdad, float arrayFloat[], int len)
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
