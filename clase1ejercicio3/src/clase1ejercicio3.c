/*
 ============================================================================
 Name        : Clase1Programa3.c
 Author      : Ale Mu�oz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 - Pedir el ingreso de dos numeros.
 - Realizar suma, resta, multiplicacion y division de los numeros ingresados.
 - Mostrar resultados de las operaciones por pantalla.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	int suma;
	int resta;
	int producto;
	float division;

	printf("Ingrese primer numero: \n");
	scanf("%d",&numero1);
	printf("Ingrese segundo numero: \n");
	scanf("%d",&numero2);

	suma=numero1+numero2;
	printf("\nResultado suma: %d\n",suma);

	resta=numero1-numero2;
	printf("Resultado resta: %d\n",resta);

	producto=numero1*numero2;
	printf("Resultado producto: %d\n",producto);

	if(numero2==0)
	{
		printf("NO SE PUEDE DIVIDIR POR CERO.\n");
	}
	else
	{
		/* El "casting" o "cast" es un recurso que se utiliza para hacer una conversi�n
		 * expl�cita de un tipo de dato a otro, a criterio del programador siempre
		 * y cuando los tipos de datos sean compatibles. �sto se hace poniendo delante
		 * de la expresi�n o variable a convertir:
		 * (tipo_de_dato)nombre_de_variable
		 *
		 */
		division=(float)numero1/numero2;	//Casteo para que el resultado de la operaci�n sea de tipo flotante.
		printf("Resultado division: %.2f",division);
	}
	return EXIT_SUCCESS;
}
