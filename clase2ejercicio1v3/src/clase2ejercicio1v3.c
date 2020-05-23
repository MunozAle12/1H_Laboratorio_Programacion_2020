/*
 ============================================================================
 Name        : clase2ejercicio1b.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
- Pedir numeros hasta que el usuario quiera (888)
- Imprimir el resultado de maximo y minimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout, NULL);
	int minimo;
	int maximo;
	int bufferInt;
	int flag=TRUE;

	while(bufferInt!=888)
	{
		printf("Ingrese numero (finaliza con 888): ");
		scanf("%d",&bufferInt);

		if(flag==1)
		{
			minimo=bufferInt;
			maximo=bufferInt;
			flag=FALSE;
		}
		else
		{
			if(bufferInt<minimo && bufferInt!=888)
			{
				minimo=bufferInt;
			}
			if(bufferInt>maximo && bufferInt!=888)
			{
				maximo=bufferInt;
			}
		}
	}
	printf("El minimo ingresado es %d y el maximo ingresado es %d",minimo,maximo);
	return EXIT_SUCCESS;
}
