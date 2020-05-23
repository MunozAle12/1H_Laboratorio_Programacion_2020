/*
 ============================================================================
 Name        : clase4.c
 Author      : Ale Mu�oz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);
	float resultado;
	int numero1;
	int numero2;
	int respuesta;

	printf("\nNumero 1?: ");
	scanf("%d",&numero1);
	printf("\nNumero 2?: ");
	scanf("%d",&numero2);

	/* Paso como parametro la direcci�n de memoria de la variable resultado.
	 * A esto se lo llama "pasaje por referencia".
	 */
	respuesta=dividir(&resultado,numero1,numero2);
	if(respuesta==0)
	{
		printf("El resultado es: %f\n",resultado);
	}
	else
	{
		printf("No es posible dividir por cero.\n");
	}
	return EXIT_SUCCESS;
}
