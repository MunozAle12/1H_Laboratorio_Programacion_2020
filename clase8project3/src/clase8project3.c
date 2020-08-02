/*
 ============================================================================
 Name        : clase8project3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	OBJETIVO:

	Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos
	(utilizar una estructura para representar a la persona):

	- Nombre
	- Apellido
	- Legajo (NO SE PUEDE REPETIR)

	El programa deberá contar con un menú de opciones para hacer altas, bajas y modificaciones (ABM) de la agenda;
	también deberá mostrar un listado ordenado por apellido.

	ASPECTOS A DESTACAR:
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "utn.h"
#define QTY_PERSONAS 200

int main(void)
{
	setbuf(stdout, NULL);
	Persona arrayPersonas[QTY_PERSONAS];
	int opcion;
	int indiceLugarLibre;
	int auxiliarIndice;
	char auxiliarNombre[SIZE];
	char auxiliarApellido[SIZE];
	int auxiliarLegajo;

	if(!pers_inicializarArrayPersonas(arrayPersonas, QTY_PERSONAS))
	{
		printf("SE INICIALIZÓ ARRAY DE PERSONAS CON ÉXITO.\n\n");
	}
	else
	{
		printf("ERROR AL INICIALIZAR ARRAY DE PERSONAS.\n\n");
	}
	do
	{
		if(!utn_getNumero(&opcion, "1) Agregar persona a la agenda\n"
								   "2) Eliminar persona de la agenda\n"
								   "3) Modificar datos de persona\n"
								   "4) Mostrar agenda\n"
								   "5) Ordenar agenda por apellido\n"
								   "6) Salir\n"
								   "Elija una opción: ", "\n\nOPCIÓN INVÁLIDA.\n", 1, 6, 2))
		{
			switch(opcion)
			{
				case 1:
					printf("\n_____ AGREGAR PERSONA A LA AGENDA _____\n\n");
					indiceLugarLibre = pers_buscarIndiceLibreArrayPersonas(arrayPersonas, QTY_PERSONAS);
					if(indiceLugarLibre > -1)
					{
						if(!utn_getNombre(auxiliarNombre, SIZE, "Ingrese nombre: ", "\n\nINGRESO INVÁLIDO. ", 2))
						{
							if(!utn_getNombre(auxiliarApellido, SIZE, "Ingrese apellido: ", "\n\nINGRESO INVÁLIDO. ", 2))
							{
								if(!utn_getNumero(&auxiliarLegajo, "Ingrese número de legajo: ", "\n\nINGRESO INVALIDO. ", 0, 4096, 2))
								{
									if(pers_buscarLegajo(arrayPersonas, QTY_PERSONAS, auxiliarLegajo) == -1)
									{
										strncpy(arrayPersonas[indiceLugarLibre].nombre, auxiliarNombre, SIZE);
										strncpy(arrayPersonas[indiceLugarLibre].apellido, auxiliarApellido, SIZE);
										arrayPersonas[indiceLugarLibre].legajo = auxiliarLegajo;
										arrayPersonas[indiceLugarLibre].isEmpty = 0;
										printf("\nSE AGREGÓ LA PERSONA A LA AGENDA CON ÉXITO.\n");
									}
									else
									{
										printf("\nYA EXISTE EL NÚMERO DE LEGAJO INGRESADO.\n");
									}
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
						}
						else
						{
							printf("SE ACABARON SUS REINTENTOS.\n");
						}
					}
					else
					{
						printf("\nNO HAY LUGAR DISPONIBLE PARA AGREGAR PERSONA.\n");
					}
					printf("______________________________\n\n");
					break;
				case 2:
					printf("\n_____ ELIMINAR PERSONA DE LA AGENDA _____\n\n");
					if(!utn_getNumero(&auxiliarLegajo, "Ingrese número de legajo: ", "\n\nINGRESO INVÁLIDO. ", 0, 4096, 2))
					{
						auxiliarIndice = pers_buscarLegajo(arrayPersonas, QTY_PERSONAS, auxiliarLegajo);
						if(auxiliarIndice != -1)
						{
							arrayPersonas[auxiliarIndice].isEmpty = TRUE;
							printf("\nSE ELIMINÓ LA PERSONA DE LA AGENDA CON ÉXITO.\n");
						}
						else
						{
							printf("\nNO EXISTE EL LEGAJO INGRESADO.\n");
						}
					}
					else
					{
						printf("SE ACABARON SUS REINTENTOS.\n");
					}
					printf("______________________________\n\n");
					break;
				case 3:
					printf("\n_____ MODIFICAR DATOS DE PERSONA _____\n\n");
					if(!utn_getNumero(&auxiliarLegajo, "Ingrese número de legajo: ", "\n\nINGRESO INVÁLIDO. ", 0, 4096, 2))
					{
						auxiliarIndice = pers_buscarLegajo(arrayPersonas, QTY_PERSONAS, auxiliarLegajo);
						if(auxiliarIndice != -1)
						{
							if(!utn_getNombre(auxiliarNombre, SIZE, "Ingrese nombre: ", "\n\nINGRESO INVÁLIDO. ", 2))
							{
								if(!utn_getNombre(auxiliarApellido, SIZE, "Ingrese apellido: ", "\n\nINGRESO INVÁLIDO. ", 2))
								{
									strncpy(arrayPersonas[auxiliarIndice].nombre, auxiliarNombre, SIZE);
									strncpy(arrayPersonas[auxiliarIndice].apellido, auxiliarApellido, SIZE);
									printf("\nSE MODIFICÓ LA PERSONA DE LA AGENDA CON ÉXITO.\n");
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
						}
						else
						{
							printf("\nNO EXISTE EL LEGAJO INGRESADO.\n");
						}
					}
					else
					{
						printf("SE ACABARON SUS REINTENTOS.\n");
					}
					printf("______________________________\n\n");
					break;
				case 4:
					printf("\n______________________________\n");
					printf("\nLEGAJO   -  NOMBRE  -  APELLIDO\n");
					if(pers_imprimirAgenda(arrayPersonas, QTY_PERSONAS) == -1)
					{
						printf("ERROR AL MOSTRAR AGENDA.\n");
					}
					printf("______________________________\n\n");
					break;
				case 5:
					printf("\n_____ ORDENAR AGENDA POR APELLIDO _____\n\n");
					if(pers_ordenarAgendaPorApellido(arrayPersonas, QTY_PERSONAS) == -1)
					{
						printf("ERROR AL ORDENAR AGENDA.\n");
					}
					else
					{
						printf("LA AGENDA FUE ORDENADA CON ÉXITO.\n");
					}
					printf("______________________________\n\n");
					break;
			}
		}
	}while(opcion != 6);
	return EXIT_SUCCESS;
}
