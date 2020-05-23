/*
 ============================================================================
 Name        : clase7ejercicio6.c
 Author      : Ale Mu�oz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 6:
 Dado el texto almacenado en el array de char "texto". Realizar una funcion que reciba
 un array de char y su longitud, y devuelva por referencia la cantidad de palabras
 encontradas y probarla con dicho texto.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarPalabras(char cadena[], int len, int* pPalabras)
{
	int retorno = -1;
	int i;
	int contadorPalabras = 0;

	if(cadena != NULL && len > 0 && pPalabras != NULL)
	{
		for(i=0; i<len && cadena[i]!='\0'; i++)
		{
			if(cadena[i] == ' ')
			{
				contadorPalabras++;
			}
		}
		*pPalabras = contadorPalabras;
		retorno = 0;
	}
	return retorno;
}

int main(void)
{
	int palabras;
	char texto[]="Las medidas de aislamiento que los diferentes paises adoptaron para frenar el avance del coronavirus continuan produciendo cambios bruscos en el medio ambiente gracias a la reduccion de la contaminacion y la baja de circulacion de personas. En este escenario, los animales silvestres en distintas partes del mundo se estan animando a ocupar espacios antes impensados debido a la alta presencia del ser humano. Tal es el caso de los lobos marinos de Mar del Plata, que fueron vistos deambulando por el puerto casi con total libertad.";

	if(contarPalabras(texto, sizeof(texto), &palabras)==0)
	{
		printf("El texto contiene: %d palabras\n", palabras);
	}

	return EXIT_SUCCESS;
}
