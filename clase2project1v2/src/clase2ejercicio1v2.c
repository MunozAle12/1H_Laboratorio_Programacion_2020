/*
 ============================================================================
 Name        : clase2ejercicio1a.c
 Author      : Ale Mu�oz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	EJERCICIO:

	- Pedir n�meros hasta que el usuario quiera. Cuando ingrese el n�mero 888,
	  se finaliza el ingreso.
	- Imprimir el resultado de m�ximo y m�nimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout,NULL);
	int minimo;
	int maximo;
	int bufferInt;
	int flag = TRUE;

	while(bufferInt != 888)
	{
		printf("INGRESE N�MERO (FINALIZA CON 888): ");
		scanf("%d",&bufferInt);

		if(flag == TRUE)
		{
			minimo = bufferInt;
			maximo = bufferInt;
			flag = FALSE;
		}
		else
		{
			if(bufferInt == 888)
			{
				break;
			}
			else
			{
				if(bufferInt < minimo)
				{
					minimo = bufferInt;
				}
				if(bufferInt > maximo)
				{
					maximo = bufferInt;
				}
			}
		}
	}
	printf("\n___________________________________________________\n");
	printf("\nEl minimo ingresado es %d y el maximo ingresado es %d", minimo, maximo);
	return EXIT_SUCCESS;
}
