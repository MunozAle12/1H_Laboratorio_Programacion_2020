/*
 ============================================================================
 Name        : clase7ejercicio5.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Ejercicio 5:

	a) Realizar un programa que pida el ingreso de 5 numeros int al usuario
	   y los almacene en un array.
	b) Luego ejecutar la funcion borrarImpares() pasandole el array y que
	   deberá reemplazar los numeros que son impares por un cero.
	c) Luego imprimir el array para chequear el funcionamiento.
	d) Ordenar el array de menor a mayor y volver a imprimirlo.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define SIZE_ARRAYINT 5
#define RANGOMIN -32768
#define RANGOMAX 32767
#define REINTENTOS 2

int main(void)
{
	setbuf(stdout, NULL);
	int arrayInt[SIZE_ARRAYINT] = {0};
	int bufferAux;
	int i;
	int respuesta;

	// Ingreso de numeros
	for(i = 0; i < SIZE_ARRAYINT; i++)
	{
		if(!utn_getNumero(&bufferAux, "Ingrese un número: ", "\n\nINGRESO VALIDO. ", RANGOMIN, RANGOMAX, REINTENTOS))
		{
			arrayInt[i] = bufferAux;
		}
		else
		{
			printf("SE ACABARON SUS REINTENTOS.\n");
		}
	}
	printf("\n______________________________\n");
	// borrar impares
	respuesta = borrarImpares(arrayInt, SIZE_ARRAYINT);
	if(imprimirNumeros(arrayInt, SIZE_ARRAYINT) == -1)
	{
		printf("ERROR.\n");
	}
	if(respuesta)
	{
		printf("\nSE INGRESARON NÚMEROS IMPARES.\n");
	}
	else
	{
		if(!respuesta)
		{
			printf("\nNO SE INGRESARON NÚMEROS IMPARES.\n");
		}
		else
		{
			printf("\nERROR.\n");
		}
	}
	printf("\n______________________________\n");
	// ordenar
	respuesta = ordenarArrayInt(arrayInt, SIZE_ARRAYINT);
	{
		if(!respuesta)
		{
			// imprimir
			respuesta = imprimirNumeros(arrayInt, SIZE_ARRAYINT);
		}
		else
		{
			printf("ERROR.\n");
		}
	}
	return EXIT_SUCCESS;
}
