/*
 ============================================================================
 Name        : clase5ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	EJERICIO:

	- Pedir al usuario 5 edades. Guardar valores en array.
	- Imprimir las 5 edades

	EJERCICIO:

	Hacer una función que calcule el promedio de los valores
	del array que recibe y me devuelva el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define EDADES_SIZE 5 //SIZE = tamaño

int main(void)
{
	setbuf(stdout,NULL);
	int edades[EDADES_SIZE];
	int auxiliarEdad;
	float promedioEdad;
	int i;

//Recorro de forma secuencial para inicializar el vector
	for(i=0; i<EDADES_SIZE; i++)
	{
/*Inicializo el array con un valor entero negativo para luego validar
  si se cargó en el índice del vector de manera correcta.*/
		edades[i] = -1;
	}
//Recorro de forma secuencial para solicitar y guardar las edades
	for(i=0; i<EDADES_SIZE; i++)
	{
		if(utn_getNumero(&auxiliarEdad, "Ingrese edad: ", "\n\nLa edad debe ser de 0 a 150. \n", 0, 150, 2) == 0)
		{
			edades[i] = auxiliarEdad;
		}
		else
		{
			printf("\nERROR. INGRESO INVÁLIDO EN EL ÍNDICE %d\n", i);
		}
	}
	printf("\n_______________________________________________________\n");
	utn_imprimirArrayInt(edades,EDADES_SIZE);
	printf("\n_______________________________________________________\n");
	if(utn_promediarArrayIntV2(&promedioEdad,edades,EDADES_SIZE) == 0)
	{
		printf("\nPASAJE DEL RESULTADO POR REFERENCIA:\n");
		printf("\nEl promedio de edades ingresadas es: %.2f", promedioEdad);
	}
	else
	{
		printf("\nERROR. LOS PARÁMETROS NO SON VÁLIDOS\n");
	}
	printf("\n_______________________________________________________\n");
	utn_promediarArrayInt(edades,EDADES_SIZE);
	printf("\nPASAJE DEL RESULTADO POR VALOR:\n");
	printf("\nEl promedio de edades ingresadas es: %.2f", promedioEdad);

	return EXIT_SUCCESS;
}
