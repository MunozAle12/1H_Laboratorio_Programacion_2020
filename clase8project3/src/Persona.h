/*
 * Persona.h
 *
 *  Created on: 28 jul. 2020
 *      Author: Usuario
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#define SIZE 64 //Valor que define la longitud del array para nombre y apellido.
#define TRUE 1 //Valor que define el estado del flag isEmpty.
#define FALSE 0 //Valor que define el estado del flag isEmpty.

struct persona
{
	char nombre[SIZE];
	char apellido[SIZE];
	int legajo;
	int isEmpty;
}typedef Persona;

int pers_inicializarArrayPersonas(Persona* arrayPersonas, int len);
int pers_buscarIndiceLibreArrayPersonas(Persona* arrayPersonas, int len);
int pers_buscarLegajo(Persona* arrayPersonas, int len, int valorBuscado);
int pers_imprimirAgenda(Persona* arrayPersonas, int cantidadPersonas);
int pers_ordenarAgendaPorApellido(Persona* arrayPersonas, int longitud);

#endif /* AGENDA_H_ */
