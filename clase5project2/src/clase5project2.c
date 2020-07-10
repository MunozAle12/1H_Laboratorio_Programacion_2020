/*
 ============================================================================
 Name        : clase5project2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Objetivo:

	Solicitar al usuario 5 números, permitir listarlos por pantalla
	indicando el máximo, el mínimo y el promedio.
	Permitir Modificar el valor de cualquiera de los números cargados
	indicando el índice del mismo y su nuevo valor.

	Aspectos a destacar:

	-Utilización de array

	Version: 0.1 del 29 diciembre de 2015
	Autor: Mauricio Dávila
	Revisión: Ernesto Gigliotti
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define CANTIDAD 5 // constante con tamaño del array

int main()
{
	setbuf(stdout,NULL);
	int arrayDeNumeros[CANTIDAD];
	int numeroIngresado;
	int indiceArray;
	int numeroMax;
	int numeroMin;
	float promedioNumeros;
	int valorIngresado;
	int opcionMenu = 0;

	for(indiceArray = 0; indiceArray < CANTIDAD; indiceArray++)
	{
		arrayDeNumeros[indiceArray] = -1;
	}

	for(indiceArray = 0; indiceArray < CANTIDAD; indiceArray++)
	{
		if(utn_getNumero(&numeroIngresado, "Ingrese número [0 - 150]: ", "\n\nINGRESO INVÁLIDO. ", 0, 150, 2) == 0)
		{
			arrayDeNumeros[indiceArray] = numeroIngresado;
		}
		else
		{
			printf("\nERROR. INGRESO INVÁLIDO EN EL ÍNDICE %d\n", indiceArray);
		}
	}
	printf("\n____________________\n");

	while(opcionMenu != 3)
	{
		if(utn_getNumero(&opcionMenu, "\n1) Mostrar \n2) Modificar \n3) Salir\nElija una opción: ", "\n\nINGRESO INVÁLIDO.\n", 1, 3, 2) == 0)
		{
			switch(opcionMenu)
			{
				case 1:
					printf("\n____________________\n");
					printf("INDICE - VALOR\n");
					for(indiceArray = 0; indiceArray < CANTIDAD; indiceArray++)
					{
						printf("  %d    -   %d \n", indiceArray, arrayDeNumeros[indiceArray]);
					}
					if(utn_buscarMinMaxArrayInt(arrayDeNumeros,CANTIDAD,&numeroMin,&numeroMax) == 0)
					{
						if(utn_promediarArrayIntV2(&promedioNumeros,arrayDeNumeros,CANTIDAD) == 0)
						{
							printf("\nMENOR  -  MAYOR\n");
							printf("  %d   -   %d \n", numeroMin, numeroMax);
							printf("\nPROMEDIO: %.2f\n", promedioNumeros);
						}
					}
					printf("\n____________________\n");
					break;
				case 2:
					printf("\n____________________\n");
					if(utn_getNumero(&indiceArray, "\nIngrese el indice a modificar: ", "\n\nINGRESO INVÁLIDO. ", 0, 4, 2) == 0)
					{
						if(utn_getNumero(&valorIngresado, "\nIngrese el valor: ", "\n\nINGRESO INVÁLIDO. ", 0, 150, 2) == 0)
						{
							arrayDeNumeros[indiceArray] = valorIngresado;
						}
						else
						{
							printf("\nINGRESO INVÁLIDO. SE ACABARON SUS REINTENTOS.\n");
						}
					}
					else
					{
						printf("\nINGRESO INVÁLIDO. SE ACABARON SUS REINTENTOS.\n");
					}
					printf("\n____________________\n");
					break;
			} // fin switch
		}
		else
		{
			printf("\n\nINGRESO INVÁLIDO. SE ACABARON SUS REINTENTOS.\n");
		}
	} // fin while
	return EXIT_SUCCESS;
}
