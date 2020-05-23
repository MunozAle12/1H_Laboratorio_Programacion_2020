/*
 ============================================================================
 Name        : classroomEjercicio3.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Agregar al programa adjunto la funcionalidad resaltada con un (*)

- Limpie la pantalla
- Solicite dos valores numéricos al usuario distintos de cero *
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor que cero *
- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

	int a;
	int b;
	int resultado;

	setbuf(stdout, NULL);
	system("cls");

	do{
		printf("Ingrese 1° numero: \n");
		scanf("%d", &a);
		if(a==0)
		{
			printf("El numero debe ser distinto de 0. \n");
			printf("_________________________________ \n");
		}
	}while(a==0);

	do{
		printf("Ingrese 2° numero: \n");
		scanf("%d", &b);
		if(b==0)
		{
			printf("El numero debe ser distinto de 0. \n");
			printf("_________________________________ \n");
		}
	}while(b==0);

	resultado = a - b;

	printf("______________________________________\n");
	printf("El resultado es: %d \n",resultado);
	if(resultado>0)
	{
        printf("Resultado positivo \n");
	}
	if(resultado<0)
	{
        printf("Resultado negativo \n");
	}
	printf("______________________________________\n");

	return 0;
}
