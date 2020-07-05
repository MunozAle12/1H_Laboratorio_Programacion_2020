/*
 ============================================================================
 Name        : clase4ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	ENUNCIADO:

	Desarrollar una biblioteca "utn.h" que posea funciones "getInt()",
	"getFloat()" y "getChar()" para solicitar y validar el ingreso de datos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);
	int edad;
	float peso;
	char letra;
	int respuesta;

	respuesta = utn_getNumero(&edad, "Ingrese edad: ", "\nLa edad debe ser de 0 a 150. ", 0, 150, 3);
	if(!respuesta)
	{
		printf("La edad es: %d\n\n", edad);
	}
	else
	{
		printf("ERROR. SE ACABARON SUS REINTENTOS.\n");
	}

	respuesta = utn_getNumeroFlotante(&peso, "Ingrese peso: ", "\nEl peso debe ser de 0 a 500. ", 0, 500, 2);
	if(!respuesta)
	{
		printf("El peso es: %f\n\n", peso);
	}
	else
	{
		printf("ERROR. SE ACABARON SUS REINTENTOS.\n");
	}

	respuesta = utn_getCaracter(&letra, "Ingrese letra [A - J]: ", "\nLa letra debe ser de A a J. ", 'A', 'J', 1);
	if(!respuesta)
	{
		printf("El letra es: %c\n\n", letra);
	}
	else
	{
		printf("ERROR. SE ACABARON SUS REINTENTOS.\n");
	}
	return EXIT_SUCCESS;
}
