/*
 ============================================================================
 Name        : clase7ejercicio6.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Ejercicio 6:

	Dado el texto almacenado en el array de char "texto". Realizar una funcion que reciba
	un array de char, su longitud, y devuelva por referencia la cantidad de palabras
	encontradas y probarla con dicho texto.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarPalabras(char cadena[], int len, int* pPalabras);

int main(void)
{
	int palabras;
	char texto[] = "Las medidas de aislamiento que los diferentes paises adoptaron para frenar el avance del coronavirus continuan produciendo cambios bruscos en el medio ambiente gracias a la reduccion de la contaminacion y la baja de circulacion de personas. En este escenario, los animales silvestres en distintas partes del mundo se estan animando a ocupar espacios antes impensados debido a la alta presencia del ser humano. Tal es el caso de los lobos marinos de Mar del Plata, que fueron vistos deambulando por el puerto casi con total libertad.";

	if(!contarPalabras(texto, sizeof(texto), &palabras))
	{
		printf("El texto contiene: %d palabras\n", palabras);
	}
	return EXIT_SUCCESS;
}

/**
 * \brief Cuenta el número de las palabras que contiene un array de char "texto" y retorna tu resultado por referencia.
 *
 * \param cadena[] Es el puntero al espacio de memoria donde comienza el array a analizar.
 * \param pPalabras Es el puntero al espacio de memoria donde se dejará el resultado de la función.
 * \return Retorna -1 si hubo error, 0 si obtuvo el número de palabras.
 *
 */
int contarPalabras(char cadena[], int len, int* pPalabras)
{
	int retorno = -1;
	int i;
	int contadorPalabras = 0;
	int largoCadena = strnlen(cadena, len) - 1; //<-- Obtengo el índice del cararcter anterior al '\0'

	if(cadena != NULL && len > 0 && pPalabras != NULL)
	{
		retorno = 0;
		for(i = 0; i < len && cadena[i] != '\0'; i++)
		{
			if(cadena[i] == ' ')
			{
				contadorPalabras++;
			}
			if(i == largoCadena)
			{
				contadorPalabras++;
			}
		}
		*pPalabras = contadorPalabras;
	}
	return retorno;
}
