/*
 ============================================================================
 Name        : classroomEjercicio2.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Remplazar los '?' al siguiente programa, para lograr la siguiente funcionalidad:
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
 ============================================================================
*/
//	system("cls");	--> FUNCION PARA LIMPIAR PANTALLA.
//	setbuf(stdout, NULL);	-->	FUNCION PARA IMPRIMIR EN WINDOWS.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	setbuf(stdout, NULL);
	int a;
	int b;
	int producto;
	int cuadrado;
	int resta;

	system("cls");	//antes --> system("?");

	do{
	printf("Ingrese 1° numero: \n");
	scanf("%d", &a);	//antes --> scanf("%?", &a);
		if(a==0)
		{
			printf("______________________________________\n");
            printf("Ingrese numero mayor a 0\n");
		}
	}while(a==0);	//antes --> }while(?==0);

	do{
	printf("Ingrese 2° numero: \n");
	scanf("%d", &b);
		if(b==0)
		{
		printf("______________________________________\n");
		printf("Ingrese numero mayor a 0 \n");
		}
    }while(b==0);

	producto = a * b;
	cuadrado = a * a;
	resta = a - b;

	printf("El 1° numero es: %d\nEl 2° numero es: %d\nEl producto es: %d\nEl cuadrado del 1° es: %d \nLa resta es: %d\n", a, b, producto, cuadrado, resta);

	return 0;
}
