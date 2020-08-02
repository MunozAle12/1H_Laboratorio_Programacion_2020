/*
 ============================================================================
 Name        : clase8.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	OBJETIVO:

	Construir una estructura del tipo 'Alumno' e indentificar los miembros para la misma.

	ASPECTOS A DESTACAR:

	- Estructuras
	- Palabra clave typedef
	- Entidades
	- Biblioteca de Entidades
	- Array de Estructuras
	- Función para imprimir un Array de Alumnos
	- Determinar lugares libres de un Array (isEmpty)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"

#define QTY_ALUMNOS 1000

int main(void)
{
/**
 * 	DATOS QUE REPRESENTAN A UNA PERSONA:
 * 	int edad;
 * 	float altura;
 * 	char nombre[64];
 * 	char apellido[64];
 * 	char sexo;
 *
 * 	DATOS QUE REPRESENTAN A n PERSONAS:
 * 	int edad[QTY_ALUMNOS];
 * 	float altura[QTY_ALUMNOS];
 * 	char nombre[QTY_ALUMNOS][64];
 * 	char apellido[QTY_ALUMNOS][64];
 * 	char sexo[QTY_ALUMNOS];
 *
 *	Las estructuras de datos son una agrupación o estructuración de una serie de variables de distintos tipos que pueden ser fácilmente utilizadas e identificadas.
 *	Las estructuras de datos permiten almacenar de manera ordenada una serie de valores dados en una misma variable.
 *	Cada valor que deseamos guardar para cada campo, accedemos a ellos generalmente por medio de una única variable.
 *	Las estructuras de datos nos permiten definir y mantener organizados los datos contenidos en una serie de posiciones en memoria.
 *	Las estructuras de datos nos facilita el manejo de código que cuentan con gran cantidad y tipos de datos.
 *
 */
	setbuf(stdout, NULL);
	Alumno auxiliarAlumno;
	Alumno arrayAlumnos[QTY_ALUMNOS];

	if(!alumno_inicializarArrayAlumnos(arrayAlumnos,QTY_ALUMNOS))
	{
		printf("SE INICIALIZÓ ARRAY DE ALUMNOS CON ÉXITO.\n");
	}
	else
	{
		printf("ERROR AL INICIALIZAR ARRAY DE ALUMNOS.\n");
	}

	auxiliarAlumno.altura = 2.04; //Para acceder y guardar datos en los campos que se encuentran dentro de una estructura utilizo el operador punto.
	auxiliarAlumno.legajo = 25;
	strcpy(auxiliarAlumno.nombre,"JUAN");
	auxiliarAlumno.isEmpty = 0; //Cambio el estado del flag isEmpty en 0 (FALSE) indicando que la posición de memoria que quiero guardar un alumno está ocupada.
	arrayAlumnos[2] = auxiliarAlumno; //Asigno en el índice 2 del array de alumnos los datos cargados en el auxiliar.

	if(alumno_imprimirArrayAlumnos(arrayAlumnos,QTY_ALUMNOS) == -1)
	{
		printf("ERROR AL IMPRIMIR ARRAY DE ALUMNOS.\n");
	}

	return EXIT_SUCCESS;
}
