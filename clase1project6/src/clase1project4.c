/*
 ============================================================================
 Name        : clase1project4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Escribir un programa que realice las siguientes acciones:
	- Solicite al usuario 10 números
	- Calcule cuántos son negativos y cuantos son positivos
	- Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define QTY_NUMEROS 10

int main(void)
{
	setbuf(stdout,NULL);
	int numero;
	int i;
	int contadorNegativos = 0;
	int contadorPositivos = 0;

	for(i=0; i<QTY_NUMEROS; i++)
	{
		printf("\nIngresar un número entero: ");
		scanf("%d",&numero);
		if(numero<0)
		{
			contadorNegativos++;
		}
		else if(numero>0)
		{
			contadorPositivos++;
		}
	}
	printf("\n_________________________________________________\n");
	printf("\nLa cantidad de números negativos ingresados son: %d", contadorNegativos);
	printf("\nLa cantidad de números positivos ingresados son: %d", contadorPositivos);

	return EXIT_SUCCESS;
}
