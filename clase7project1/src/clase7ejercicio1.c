/*
 ============================================================================
 Name        : clase7ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Ejercicio:

	- Escribir la funcion calcularMayor().
	- La funcion debe recibir dos numeros enteros y devolver por referencia el numero mayor.
	- La funcion debe retornar un 1 si encontro un mayor, o un 0
	  si ambos numeros son iguales.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TRUE 1
#define FALSE 0
#define RANGO_MIN -32768
#define RANGO_MAX 32767
#define REINTENTOS 2

int main(void)
{
	setbuf(stdout,NULL);
	int resultado;
	int numero1 = 0;
	int numero2 = 0;
	int respuesta;

	// Pedir dos numeros al usuario con utn_getNumber() y guardarlos en num1 y num 2
	if(!utn_getNumero(&numero1, "Ingrese un número: ", "\nINGRESO INVALIDO. ", RANGO_MIN, RANGO_MAX, REINTENTOS))
	{
		printf("El 1er número es: %d\n\n", numero1);
	}
	else
	{
		printf("SE ACABARON SUS REINTENTOS.\n\n");
	}
	if(!utn_getNumero(&numero2, "Ingrese un número: ", "\nINGRESO INVALIDO. ", RANGO_MIN, RANGO_MAX, REINTENTOS))
	{
		printf("El 2do número es: %d\n\n", numero2);
	}
	else
	{
		printf("SE ACABARON SUS REINTENTOS.\n\n");
	}
	printf("______________________________\n\n");
	//Invoco a la funcion calcularMayor()
	respuesta = utn_calcularMayor(&resultado, numero1, numero2);
	if(respuesta == FALSE)
	{
		printf("Los números son iguales\n");
	}
	else
	{
		if(respuesta == TRUE)
		{
			printf("El mayor es: %d\n", resultado);
		}
		else
		{
			printf("ERROR. EL PUNTERO A resultado ES NULL.\n");
		}
	}
	return EXIT_SUCCESS;
}
