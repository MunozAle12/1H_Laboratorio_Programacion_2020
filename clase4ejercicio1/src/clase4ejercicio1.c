/*
 ============================================================================
 Name        : clase4ejercicio1.c
 Author      : Ale Muñoz
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
	int edad;
	float peso;
	char letra;
	int respuesta;

	respuesta=utn_getNumero(&edad,"Ingrese edad: \n","La edad debe ser de 0 a 150.\n",0,150,3);
	if(respuesta==0)
	{
		printf("La edad es: %d\n",edad);
	}
	else
	{
		printf("ERROR.\n");
	}

	respuesta=utn_getNumeroFlotante(&peso,"Ingrese peso: \n","El peso debe ser de 0 a 500.\n",0,500,2);
	if(respuesta==0)
	{
		printf("El peso es: %f\n",peso);
	}
	else
	{
		printf("ERROR.\n");
	}

	respuesta=utn_getCaracter(&letra,"Ingrese letra: \n","La letra debe ser de A a J.\n",'A','J',1);
	if(respuesta==0)
	{
		printf("El letra es: %c\n",letra);
	}
	else
	{
		printf("ERROR.\n");
	}
	return EXIT_SUCCESS;
}
