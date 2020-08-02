/*
 * Alumno.h
 *
 *  Created on: 22 abr. 2020
 *      Author: Usuario
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define NOMBRE_LEN 64
typedef struct
{
	//Miembros o campos de la estructura
	int legajo;
	char nombre[NOMBRE_LEN];
	float altura;
	int isEmpty;
}Alumno; //<-- Entidad

int alumno_imprimirArrayAlumnos(Alumno* pArray, int limite);
int alumno_inicializarArrayAlumnos(Alumno* pArray, int limite);

#endif /* ALUMNO_H_ */
