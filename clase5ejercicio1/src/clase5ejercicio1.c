/*
 ============================================================================
 Name        : clase5ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERICIO:
 - Pedir al usuario 5 edades
 - Imprimir las 5 edades
 EJERCICIO:
 Hacer una funcion que calcule el promedio de los valores
 del array que recibe y me devuelva el promedio.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDADES_SIZE 5 //SIZE = tamaño

int main(void)
{
	setbuf(stdout, NULL);
	int edades[EDADES_SIZE];
	int edad;
	float promedioEdad;
	int i;

	//Recorro de forma secuencial para guardar los valores
	for(i=0;i<EDADES_SIZE;i++)
	{
		if(utn_getNumero(&edad,"Ingrese edad: \n","La edad debe ser de 0 a 150.\n",0,150,2)==0)
		{
			edades[i]=edad;
		}
		else
		{
			printf("ERROR.\n");
		}
	}
	utn_imprimirArrayInt(edades,EDADES_SIZE);
	utn_promediarArrayIntV2(&promedioEdad,edades,EDADES_SIZE);
	printf("\nEl promedio de edades es: %f",promedioEdad);

	return EXIT_SUCCESS;
}
