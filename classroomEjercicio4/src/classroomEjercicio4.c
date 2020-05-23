/*
 ============================================================================
 Name        : classroomEjercicio4.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Escribir un programa que realice las siguientes acciones:

- Solicite al usuario 10 números
- Calcule cuántos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	int i = 1;
	int numeroIngresado;
	int contadorNegativos = 0;
	int contadorPositivos = 0;
	system("cls");


	for(i=1;i<11;i++)
	{
		do{
			printf("Ingrese el %d° numero. \n", i);
			scanf("%d", &numeroIngresado);
			if(numeroIngresado==0)
			{
				printf("El numero debe ser distinto de 0. \n");
				printf("_________________________________ \n");
			}
			else
			{
				if(numeroIngresado<0)
				{
					contadorNegativos++;
				}
				else
				{
					contadorPositivos++;
				}
			}
		}while(numeroIngresado==0);
	}
	printf("Se ingresaron %d numeros positivos y %d numeros negativos.", contadorPositivos, contadorNegativos);

	return EXIT_SUCCESS;
}
