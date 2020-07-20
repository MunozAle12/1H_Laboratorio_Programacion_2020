/*
 ============================================================================
 Name        : clase7ejercicio2.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Ejercicio 2:

	Crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
	Definir un array de numeros flotantes de 31 posiciones. Cada posicion corresponderá a un dia del mes.
	Hacer un programa con un menu de tres opciones:
		1. Imprimir array
		2. Cargar array
		3. Salir
	Al elegir la opcion 1 se imprimira el indice y el valor de cada posicion del array.
	Al elegir la opcion 2 solicitar al usuario que ingrese un numero de dia (1 a 31)
	y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
	Ambas opciones deben volver al menu principal.
	Al elegir la opción 3 se finalizará la ejecución del programa.
	Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define DIAS 31
#define MIN_TEMPERATURA -100.00
#define MAX_TEMPERATURA 100.00
#define REINTENTOS 2

int main(void)
{
	setbuf(stdout,NULL);
	float temperaturas[DIAS] = {0}; //<-- Inicializo el array con el valor '0'
	float auxiliarTemperatura;
	int opcion;
	int dia;

	do
	{
		if(!utn_getNumero(&opcion, "\n1. Mostrar registros de temperaturas máximas \n2. Cargar una temperatura máxima registrada \n3. Salir \nIngrese una opcion: ", "\n\nINGRESO INVALIDO. ", 1, 3, REINTENTOS))
		{
			switch(opcion)
			{
				case 1:
					utn_imprimirArrayFloat(temperaturas, DIAS);
					break;
				case 2:
					printf("\n______________________________\n");
					if(!utn_getNumero(&dia, "Ingrese un número de día: ", "\n\nINGRESO INVALIDO. ", 1, DIAS, REINTENTOS))
					{
						printf("\n______________________________\n");
						if(!utn_getNumeroFloat(&auxiliarTemperatura, "Ingrese la temperatura máxima: ", "\n\nNO ES UNA TEMPERATURA VALIDA. ", MIN_TEMPERATURA, MAX_TEMPERATURA, REINTENTOS))
						{
							temperaturas[dia-1] = auxiliarTemperatura;
							printf("SE GUARDÓ TEMPERATURA MÁXIMA CON ÉXITO.\n");
						}
						else
						{
							printf("SE ACABARON SUS REINTENTOS.\n");
						}
					}
					else
					{
						printf("SE ACABARON SUS REINTENTOS.\n");
					}
					printf("\n______________________________\n");
					break;
			}
		}
		else
		{
			printf("SE ACABARON SUS REINTENTOS.\n");
			break;
		}
	}while(opcion != 3);
	return EXIT_SUCCESS;
}
