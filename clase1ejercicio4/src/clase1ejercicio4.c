/*
 ============================================================================
 Name        : Clase1Programa4.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 - Pedir el ingreso de 5 numeros.
 - Mostrar el promedio de los numeros ingresados.
 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>

/* Utilizo la directiva #define para indicarle al procesador que cuando
 * aparezca en el código una palabra deberá ser reemplazada por un valor.
 * Esto beneficia a que la compilación sea más rápida al no tener el
 * compilador que realizar el tratamiento y verificaciones propias de variables.
 * Otra ventaja radica en no estar escribiendo lo mismo en múltiples lugares,
 * evitando así el error conocido como "hardcodeo".
 *
 */
#define CANTIDAD_NUMEROS 5

int main(void)
{
	setbuf(stdout, NULL);
	int i;	//variable que utilizo para el control de iteraciones.
	int numeroIngresado;	//La utilizo para guardar los numeros que se ingresan.
	int acumulador=0;	//La utilizo para guardar la suma acumulada de los numeros que se ingresan. SIEMPRE INICIALIZAR LOS ACUMULADORES.
	float promedio;		//La utilizo para guardar el promedio de los numeros ingresados.

	for(i=0; i<CANTIDAD_NUMEROS; i++)
	{
		printf("Ingrese %d° numero: ",i+1);
		scanf("%d",&numeroIngresado);
		acumulador=acumulador+numeroIngresado;
	}
	promedio=(float)acumulador/CANTIDAD_NUMEROS;
	printf("El promedio de los numeros ingresados es %.2f",promedio);

	return EXIT_SUCCESS;
}
