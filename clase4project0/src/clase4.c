/*
 ============================================================================
 Name        : clase4.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	ENUNCIADO:

	Crear una biblioteca con el nombre "utn.h", en la cual se va a desarrollar una
	función que permita relizar la operación dividir para obtener el cociente y
	retornar su resultado por referencia.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	float resultado;
	int numero1;
	int numero2;
	int respuesta;

	printf("Numero 1?: ");
	scanf("%d",&numero1);
	printf("Numero 2?: ");
	scanf("%d",&numero2);

	/* Paso como parametro la dirección de memoria de la variable resultado.
	 * A esto se lo llama "pasaje por referencia".
	 */
	respuesta = calcularCociente(&resultado,numero1,numero2);
	if(respuesta == 0) //<--Equivalente a: if(!respuesta)
	{
		printf("El resultado es: %f\n", resultado);
	}
	else
	{
		printf("No es posible dividir por cero.\n");
	}
	return EXIT_SUCCESS;
}
