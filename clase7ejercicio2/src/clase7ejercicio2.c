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
 Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia del mes.
 Hacer un programa con un menu de dos opciones:
 1. Imprimir array
 2. Cargar array
 Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 Ambas opciones deben volver al menu principal.
 Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define DIAS 31

int main(void)
{
	setbuf(stdout,NULL);
	float temperatura[DIAS]={0};
	int opcion;
	int dia;

	do
	{
		if(!utn_getNumero(&opcion,"Ingrese una opcion: \n1. Mostrar registros de temperaturas máximas \n2. Cargar una temperatura máxima registrada \n3. Salir\n","NO ES UNA OPCIÓN VALIDA\n",1,3,2))
		{
			switch(opcion)
			{
				case 1:
					utn_imprimirArrayFloat(temperatura,DIAS);
				break;
				case 2:
					if(!utn_getNumero(&dia,"Ingrese un número de día: \n","NO ES UN NÚMERO VALIDO.\n",1,31,2))
					{
						utn_getNumeroFlotante(&temperatura[dia-1],"Ingrese la temperatura máxima:\n","NO ES UNA TEMPERATURA VALIDA.\n",-32768.00,32767.00,2);
					}
				break;
			}
		}
		else
		{
			printf("SE TERMINARON SUS REINTENTOS.\n");
			break;
		}
	}while(opcion!=3);
	return EXIT_SUCCESS;
}
