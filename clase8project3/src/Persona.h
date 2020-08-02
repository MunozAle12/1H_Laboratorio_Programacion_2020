/*
 * Persona.h
 *
 *  Created on: 28 jul. 2020
 *      Author: Usuario
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#define NOMBRE_LEN 64

struct persona
{
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	int legajo;
	int isEmpty;
}typedef Persona;

int pers_inicializarArrayPersonas(Persona* arrayPersonas, int len);
int pers_buscarIndiceLibreArrayPersonas(Persona* arrayPersonas, int len);
int pers_buscarLegajo(Persona* arrayPersonas, int len, int valorBuscado);
int pers_imprimirAgenda(Persona* arrayPersonas, int cantidadPersonas);
int pers_ordenarAgendaPorApellido(Persona* arrayPersonas, int longitud);

#endif /* AGENDA_H_ */
