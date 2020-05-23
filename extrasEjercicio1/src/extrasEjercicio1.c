/*
 ============================================================================
 Name        : extrasEjercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Escribir un programa que realice las siguientes acciones:
 - Limpie la pantalla
 - Asigne a 2 variables numero1 y numero2 valores distintos de cero
 - Efectúe el producto de dichas variables
 - Muestre el resultado por pantalla
 - Obtenga el cuadrado de numero1 y lo muestre por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numero1;
	int numero2;
	int resultadoProducto;
	int resultadoPotencia;

	do
	{
		printf("Ingrese un numero: \n");
		scanf("%d", &numero1);
		printf("Ingrese un numero: \n");
		scanf("%d", &numero2);
	}while(numero1==0 || numero2 ==0);

	resultadoProducto= numero1 * numero2;
	printf("El resultado del producto es: %d\n", resultadoProducto);

	resultadoPotencia= numero1 * numero1;
	printf("El resultado del cuadrado del primer numero es: %d\n", resultadoPotencia);

	return EXIT_SUCCESS;
}
