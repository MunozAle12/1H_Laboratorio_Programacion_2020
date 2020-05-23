/*
 ============================================================================
 Name        : extrasEjercicio5.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Escribir el programa necesario para calcular y mostrar el cuadrado de un
 número. El numero ingresado debe ser mayor que cero, en caso de error que
 aparezca el mensaje "ERROR, el numero debe ser mayor que cero".
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int bufferInt;
	int resultadoPotencia;

	printf("Ingrese un número: \n");
	scanf("%d",&bufferInt);
	if(bufferInt<=0)
	{
		printf("ERROR, el numero debe ser mayor que cero.\n");
	}
	else
	{
		resultadoPotencia= bufferInt*bufferInt;
		printf("El resultado del cuadrado del numero ingresado es: %d\n",resultadoPotencia);
	}

	return EXIT_SUCCESS;
}
