/*
 ============================================================================
 Name        : clase2ejercicio1.c
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
	int bufferInt; //Lo utilizo para guardar el n�mero que ingresa el usuario.
	int maximo;
	int minimo;
	int flag = TRUE;	/* <-- Utilizo flag (bandera) para intercalarla en el codigo
	 	 	 	 	 	 *     y condicionar que una parte del mismo se ejecute una sola vez.
						 */
	do
	{
		printf("INGRESE N�MERO (\"888\" FINALIZA EL INGRESO): ");
		scanf("%d",&bufferInt);
		if(flag == TRUE)
		{
			minimo = bufferInt;	//Tomo el primer n�mero ingresado como m�nimo.
			maximo = bufferInt;	//Tomo el primer n�mero ingresado como m�ximo.
			flag = FALSE;
		}
		else
		{
			if(bufferInt < minimo && bufferInt != 888)
			{
				maximo = bufferInt;
			}
			if(bufferInt > maximo && bufferInt != 888)
			{
				minimo = bufferInt;
			}
		}
	}while(bufferInt != 888);
	printf("\n___________________________________________________\n");
	printf("\nEl valor minimo es: %d y el valor maximo es: %d", minimo, maximo);
	return EXIT_SUCCESS;
}
