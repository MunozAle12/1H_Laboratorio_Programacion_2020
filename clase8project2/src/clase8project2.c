/*
 ============================================================================
 Name        : clase8project2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	OBJETIVO:

	Desarrollo y upgrade y testeo de las funciones:

	- getNumero()
	- getInt()
	- myGets()
	- esNumerica()
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);
	int edad;

	while(1)
	{
		if(!utn_getNumero(&edad, "Ingrese edad: ", "\n\nINGRESO INVÁLIDO. ", 0, 200, 2))
		{
			printf("\nLa edad es: %d", edad);
			printf("\n____________________\n");
		}
		else
		{
			printf("SE ACABARON SUS REINTENTOS.\n");
			break;
		}
	}
	return EXIT_SUCCESS;
}
