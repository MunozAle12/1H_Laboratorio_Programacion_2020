/*
 * Alumno.c
 *
 *  Created on: 22 abr. 2020
 *      Author: Usuario
 */

#include "Alumno.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Inicializa el array de alumnos
 *
 * \param pArray Es el puntero al espacio de memoria donde comienza el array de alumnos
 * \param longitud Es el valor que define el tamaño del array a imprimir.
 * \return Retorna -1 si hubo ERROR, 0 si pudo inicializar con ÉXITO.
 *
 */
int alumno_inicializarArrayAlumnos(Alumno* pArray, int longitud)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && longitud > 0)
	{
		retorno = 0;
		for(i = 0; i < longitud; i++)
		{
			pArray[i].isEmpty = 1;
		}
	}
	return retorno;
}

/**
 * \brief Imprime el array de alumnos.
 *
 * \param pArray Es el puntero al espacio de memoria donde comienza el array de alumnos.
 * \param limite Es el valor que define el tamaño del array.
 * \return Retorna -1 si hubo ERROR, 0 si pudo imprimir con ÉXITO.
 *
 */
int alumno_imprimirArrayAlumnos(Alumno* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		retorno = 0;
		for(i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == 0 )
			{
				printf("\nNombre: %s - Legajo: %d - Altura: %f", pArray[i].nombre, pArray[i].legajo, pArray[i].altura);

			}
		}
	}
	return retorno;
}
