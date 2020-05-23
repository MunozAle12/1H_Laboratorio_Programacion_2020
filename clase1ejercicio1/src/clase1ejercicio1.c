/*
 ============================================================================
 Name        : Clase1Programa1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Pedir el ingreso de dato tipo 'int' y luego lo muestra por pantalla.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numero;
	//prompt("Ingrese numero:"); //JS
	printf("Ingrese numero: ");
//  scanf("Especificador de formato", direccion de memoria de la variable);
	scanf("%d",&numero);
	printf("Ingresaste: %d",numero);

	return EXIT_SUCCESS;
}
