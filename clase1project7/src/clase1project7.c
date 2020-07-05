/*
 ============================================================================
 Name        : clase1project5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Agregar al programa adjunto la funcionalidad resaltada con un (*):

	- Limpie la pantalla
	- Solicite dos valores numéricos al usuario distintos de cero *
	- Asigne a las variables numero1 y numero2 los valores obtenidos
	- Realice la resta de dichas variables
	- Muestre el resultado por pantalla
	- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
	- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	setbuf(stdout,NULL);
	int a;
	int b;
	int resultado;

	system("cls");
	do
	{
	printf("\nIngrese 1 numero distinto de cero: ");
	scanf("%d",&a);

	printf("\nIngrese 2 numero distinto de cero: ");
	scanf("%d",&b);
	}while(a == 0 || b == 0);

	resultado = a - b;

	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",resultado);
	if(resultado > 0)
	{
        printf("\nResultado positivo\n");
	}
	else if(resultado < 0)
	{
        printf("\nResultado negativo\n");
	}
	printf("______________________________________\n\n\n\n");

	return EXIT_SUCCESS;
}
