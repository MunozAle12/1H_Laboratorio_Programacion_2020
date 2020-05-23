/*
 ============================================================================
 Name        : extrasEjercicio7.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Diseñar un programa que calcule la longitud de la circunferencia y el área
 de un círculo de radio dado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416

int main(void)
{
	setbuf(stdout,NULL);
	float longitudCirc;
	float areaCirc;
	float bufferRadio;

	printf("Ingrese el radio del circulo: \n");
	scanf("%f", &bufferRadio);

	longitudCirc= 2 * bufferRadio * PI;
	areaCirc= PI * (bufferRadio * bufferRadio);

	printf("- La longitud de la circulferencia es %f \n- El área de del círculo es %f",longitudCirc,areaCirc);

	return EXIT_SUCCESS;
}
