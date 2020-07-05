/*
 ============================================================================
 Name        : clase4project2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	ENUNCIADO:

	Dise�ar un programa para jugar a adivinar un n�mero entre 0 y 100.
	El juego tiene que dar pistas de si el n�mero introducido por el jugador
	est� por encima o por debajo. El juego termina cuando se adivina el n�mero
	o se decide terminar de jugar ingresando un n�mero negativo. Permitir jugar
	tantas veces como lo desee el jugador y al salir mostrar su mejor puntuaci�n.
	Utilizar la biblioteca del ejercicio #001.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout,NULL);
	int numeroOculto;
	int numeroIngresado;
	int intentos;
	int nuevoRecord;
	int flagRecord = TRUE;
	char teclaIngresada;
	int respuesta;
	int jugar;

	do
	{
		jugar = TRUE;
		intentos = 1;
		numeroOculto = utn_getNumeroAleatorio(1,100,1);
		while(jugar)
		{
			respuesta = utn_getNumero(&numeroIngresado, "Ingrese un n�mero (0 - 99): ", "\n\nINGRESO INV�LIDO. ", 0, 99, 2);
			if(respuesta < 0)
			{
				printf("\nERROR. INGRESO INV�LIDO, SE ACABARON SUS REINTENTOS.\n");
				jugar = FALSE;
			}
			else if(numeroIngresado == numeroOculto)
			{
				if(flagRecord)
				{
					nuevoRecord = intentos;
					flagRecord = FALSE;
				}
				if(intentos < nuevoRecord)
				{
					nuevoRecord = intentos;
					printf("\n�NUEVO RECORD! LO HICISTE EN %d INTENTOS.\n", nuevoRecord);
				}
				else
				{
					printf("\n�GANASTE! LO HICISTE EN %d INTENTOS.\n", intentos);
				}
				jugar = FALSE;
			}
			else
			{
				intentos++;
				if(numeroIngresado < numeroOculto)
				{
					printf("\nEL N�MERO QUE INGRESASTE ES MENOR.\n");
				}
				else if(numeroIngresado > numeroOculto)
				{
					printf("\nEL N�MERO QUE INGRESASTE ES MAYOR.\n");
				}
			}
		}
		respuesta = utn_getCaracter(&teclaIngresada, "�Desea jugar otra vez? [s/n]: ", "\n\nINGRESO INV�LIDO. ", 'a','z',2);
		if((teclaIngresada != 's' && teclaIngresada != 'n') || respuesta < 0)
		{
			printf("\n\nERROR. INGRESO INV�LIDO.\n");
		}
	}while(teclaIngresada == 's');
	return EXIT_SUCCESS;
}
