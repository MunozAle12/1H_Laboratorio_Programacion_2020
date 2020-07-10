/*
 ============================================================================
 Name        : clase6ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	int auxiliarInt;
/*	char nombre[11]="ZZZZZZZZZZ"; // '\0'
	char apellido[11]="PEREZ"; // '\0'
	char auxiliar[30]=""; // '\0'
	char buffer[256];
	int i;

	strcpy(nombre,"JUAN");
	for(i=0;i<sizeof(nombre);i++)
	{
		printf("\nINDEX: %d - VALUE: %c - %d", i, nombre[i],(int)nombre[i]);
	}
	strncpy(auxiliar,nombre,sizeof(auxiliar));
	snprintf(auxiliar, sizeof(auxiliar),"%s %s",nombre,apellido);
	printf("\n%s\n",auxiliar);
	printf("\nSIZE Nombre mide %d ----- auxiliar mide %d",(int)sizeof(nombre),(int)sizeof(auxiliar));
	printf("\nSTRLEN Nombre mide %d ----- auxiliar mide %d",(int)strnlen(nombre,sizeof(nombre)),(int)strnlen(auxiliar,sizeof(auxiliar)));
*/
	while(1)
	{
		if(utn_getNumero(&auxiliarInt, "NUMERO?: ", "\nERROR. ", -2, 10, 2) == 0)
		{
			printf("\nEl numero es  %d\n", auxiliarInt);
		}
	}

	return EXIT_SUCCESS;
}
