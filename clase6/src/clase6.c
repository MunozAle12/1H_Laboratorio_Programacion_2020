/*
 ============================================================================
 Name        : clase6.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 - Pedir y validar el ingreso de numeros enteros y guardarlos en un array.
 - Imprimir elementos del array.
 - Ordenar los elementos del array de forma descendente.
 - Mostrar las iteraciones que se necesitaron para ordenar el array.
 - Imprimir elementos del array ordenado.
 - Ordenar los elementos del array ya ordenado de forma descendente.
 - Mostrar las iteraciones que se necesitaron para ordenar el array.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define SIZE 5
#define INTMIN -32768
#define INTMAX 32767

int main(void)
{
	setbuf(stdout,NULL);
	int arrayInt[SIZE];
	int bufferAux;
	int respuesta;
	int i;

	for(i=0;i<SIZE;i++)
	{
		if(utn_getNumero(&bufferAux,"Ingrese un numero: \n","DEBE INGRESAR UN NUMERO VÁLIDO\n",INTMIN,INTMAX,2)==0)
		{
			arrayInt[i]=bufferAux;
		}
		else
		{
			printf("SE LE ACABARON LOS REINTENTOS.\n\n");
		}
	}
	printf("---ARRAY DESORDENADO---\n");
	printArray(arrayInt,SIZE);
	respuesta=ordenarArrayInt(arrayInt,SIZE);
	if(respuesta>0)
	{
		printf("Iteraciones que se hicieron para ordenar: %d\n\n\n",respuesta);
	}

	printf("---ARRAY ORDENADO---\n");
	printArray(arrayInt,SIZE);
	respuesta=ordenarArrayInt(arrayInt,SIZE);
	if(respuesta>0)
	{
		printf("Iteraciones que se hicieron para ordenar: %d\n",respuesta);
	}

	return EXIT_SUCCESS;
}
