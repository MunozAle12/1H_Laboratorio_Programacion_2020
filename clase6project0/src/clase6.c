/*
 ============================================================================
 Name        : clase6.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	EJERCICIO:

	- Solicitar y validar el ingreso de numeros enteros. Guardarlos en un array.
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
	int auxiliarInt;
	int respuesta;
	int i;
	for(i=0; i<SIZE; i++)
	{
		arrayInt[i] = 0;
	}
	for(i=0;i<SIZE;i++)
	{
		if(utn_getNumero(&auxiliarInt, "Ingrese número: ", "\n\nINGRESO INVÁLIDO. ", INTMIN, INTMAX, 2) == 0)
		{
			arrayInt[i] = auxiliarInt;
		}
		else
		{
			printf("\nERROR. INGRESO INVÁLIDO EN EL ÍNDICE %d\n", i);
		}
	}
	printf("\n---ARRAY DESORDENADO---\n\n");
	printArray(arrayInt,SIZE);
	respuesta = ordenarArrayInt(arrayInt,SIZE);
	if(respuesta > 0)
	{
		printf("Iteraciones que se hicieron para ordenar: %d\n\n", respuesta);
	}
	printf("\n---ARRAY ORDENADO---\n\n");
	printArray(arrayInt,SIZE);
	respuesta = ordenarArrayInt(arrayInt,SIZE);
	if(respuesta > 0)
	{
		printf("Iteraciones que se hicieron para ordenar: %d\n", respuesta);
	}
	return EXIT_SUCCESS;
}
