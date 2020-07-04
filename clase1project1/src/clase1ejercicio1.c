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
	printf("Ingrese numero: ");	//JS--> prompt("Ingrese numero:");
	scanf("%d",&numero); // parametros de scanf("Especificador de formato", direccion de memoria de la variable);
	printf("Ingresaste: %d",numero); //printf("Cadena de caracteres. Puede contener especificador de formato incrustados que se reemplazan por valores",Argumento adicional);

	return EXIT_SUCCESS;
}
