/*
 ============================================================================
 Name        : clase7ejercicio.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Ejercicio 3:

	Definir una funcion validarFloat() que reciba un array de chars en donde los
	caracteres representan un numero decimal. La funcion deberá devolver en su valor de retorno
	si la cadena recibida contiene o no un valor numerico en formato texto.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);
	char numero[8];
	int respuesta;

	// prueba 1
	numero[0] = '3';
	numero[1] = '.';
	numero[2] = '1';
	numero[3] = '4';
	numero[4] = '\0';
/*
	// prueba 2
	numero[0] = '2';
	numero[1] = '3';
	numero[2] = '5';
	numero[3] = '7';
	numero[4] = '\0';

	// prueba 3
	numero[0] = '2';
	numero[1] = '.';
	numero[2] = '5';
	numero[3] = '.';
	numero[4] = '9';
	numero[5] = '\0';

	// prueba 4
	numero[0] = 'h';
	numero[1] = 'o';
	numero[2] = 'l';
	numero[3] = 'a';
	numero[4] = '\0';
*/
	respuesta = validarFlotante(numero);
	if(respuesta)
	{
		printf("El array '%s' es valido, se puede convertir a float!\n", numero);
	}
	else
	{
		if(!respuesta)
		{
			printf("El array '%s' NO se puede convertir a float.\n", numero);
		}
		else
		{
			printf("ERROR.\n");
		}
	}
	return EXIT_SUCCESS;
}
