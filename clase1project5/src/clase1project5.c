/*
 ============================================================================
 Name        : clase1project3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Escribir  un programa que realice las siguientes acciones:
	1. Limpiar la pantalla
	2. Asignar a 2 variables, numero1 y numero2, valores distintos de cero
	3. Calcular el producto de dichas variables
	4. Mostrar el resultado por pantalla
	5. Obtener el cuadrado de numero1 y lo muestro par pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	setbuf(stdout,NULL);
	int a;
	int b;
	int producto;
	int cuadrado;

	system("cls"); //system("?");
/* system("cls"): Función que, al invocarla, borra la consola o la pantalla de salida.
 * 				  Se declara en el archivo de encabezado "stdlib.h".
 */
	do{
		printf("\nIngrese 1\247 numero: ");
		scanf("%d",&a); //scanf("%?",&a);
		printf("______________________________________\n");
		if(a==0)
		{
			printf("\nIngrese numero mayor a 0\n");
			printf("______________________________________\n");
		}
    }while(a==0); //while(?==0);

	do{
		printf("\nIngrese 2\247 numero: ");
		scanf("%d",&b);
		printf("______________________________________\n");
		if(b==0)
		{
		printf("\nIngrese numero mayor a 0\n");
		printf("______________________________________\n");
		}
    }while(b==0);

	producto=a*b;
	cuadrado=a*a;

	printf("\nEl valor 1\247: %d\nEl valor 2\247: %d\n\nEl producto es: %d\n\nEl cuadrado del 1\247 valor %d es: %d \n",a,b,producto,a,cuadrado);
	printf("______________________________________\n\n\n\n");

	return EXIT_SUCCESS;;
}
