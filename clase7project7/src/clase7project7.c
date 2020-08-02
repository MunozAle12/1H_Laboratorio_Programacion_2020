/*
 ============================================================================
 Name        : clase7project7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	OBJETIVO:

	Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:
	- Nombre
	- Apellido
	- Legajo (NO SE PUEDE REPETIR)

	El programa deber� contar con un men� de opciones para hacer altas, bajas y modificaciones (ABM) de la agenda;
	tambi�n deber� mostrar un listado ordenado por apellido.

	ASPECTOS A DESTACAR:

	- Manipulaci�n y chequeos de cadenas de caracteres.
	- Array paralelos.
	- Bajas l�gicas.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define SIZE 64
#define QTY_PERSONAS 200

int main(void)
{
	setbuf(stdout, NULL);
	char arrayNombres[QTY_PERSONAS][SIZE];
	char arrayApellidos[QTY_PERSONAS][SIZE];
	int arrayLegajos[QTY_PERSONAS];
	int opcion;
	int indiceLugarLibre;
	int auxiliarIndice;
	char auxiliarNombre[SIZE];
	char auxiliarApellido[SIZE];
	int auxiliarLegajo;

	if(!utn_inicializarArrayInt(arrayLegajos, QTY_PERSONAS, -1))
	{
		printf("SE INICIALIZ� ARRAY DE LEGAJOS CON �XITO.\n\n");
	}
	else
	{
		printf("ERROR AL INICIALIZAR ARRAY DE LEGAJOS.\n\n");
	}
	do
	{
		if(!utn_getNumero(&opcion, "1) Agregar persona a la agenda\n"
								   "2) Eliminar persona de la agenda\n"
								   "3) Modificar datos de persona\n"
								   "4) Mostrar agenda\n"
								   "5) Ordenar agenda por apellido\n"
								   "6) Salir\n"
								   "Elija una opci�n: ", "\n\nOPCI�N INV�LIDA.\n", 1, 6, 2))
		{
			switch(opcion)
			{
				case 1:
					printf("\n_____ AGREGAR PERSONA A LA AGENDA _____\n\n");
					indiceLugarLibre = utn_buscarPrimeraOcurrencia(arrayLegajos, QTY_PERSONAS, -1);
					if(indiceLugarLibre > -1)
					{
						if(!utn_getNombre(auxiliarNombre, SIZE, "Ingrese nombre: ", "\n\nINGRESO INV�LIDO. ", 2))
						{
							if(!utn_getNombre(auxiliarApellido, SIZE, "Ingrese apellido: ", "\n\nINGRESO INV�LIDO. ", 2))
							{
								if(!utn_getNumero(&auxiliarLegajo, "Ingrese n�mero de legajo: ", "\n\nINGRESO INVALIDO. ", 0, 4096, 2))
								{
									if(utn_buscarPrimeraOcurrencia(arrayLegajos, QTY_PERSONAS, auxiliarLegajo) == -1)
									{
										strncpy(arrayNombres[indiceLugarLibre], auxiliarNombre, SIZE);
										strncpy(arrayApellidos[indiceLugarLibre], auxiliarApellido, SIZE);
										arrayLegajos[indiceLugarLibre] = auxiliarLegajo;
										printf("\nSE AGREG� LA PERSONA A LA AGENDA CON �XITO.\n");
									}
									else
									{
										printf("\nYA EXISTE EL N�MERO DE LEGAJO INGRESADO.\n");
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
					if(!utn_getNumero(&auxiliarLegajo, "Ingrese n�mero de legajo: ", "\n\nINGRESO INV�LIDO. ", 0, 4096, 2))
					{
						auxiliarIndice = utn_buscarPrimeraOcurrencia(arrayLegajos, QTY_PERSONAS, auxiliarLegajo);
						if(auxiliarIndice != -1)
						{
							arrayLegajos[auxiliarIndice] = -1;
							printf("\nSE ELIMIN� LA PERSONA DE LA AGENDA CON �XITO.\n");
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
					if(!utn_getNumero(&auxiliarLegajo, "Ingrese n�mero de legajo: ", "\n\nINGRESO INV�LIDO. ", 0, 4096, 2))
					{
						auxiliarIndice = utn_buscarPrimeraOcurrencia(arrayLegajos, QTY_PERSONAS, auxiliarLegajo);
						if(auxiliarIndice != -1)
						{
							if(!utn_getNombre(auxiliarNombre, SIZE, "Ingrese nombre: ", "\n\nINGRESO INV�LIDO. ", 2))
							{
								if(!utn_getNombre(auxiliarApellido, SIZE, "Ingrese apellido: ", "\n\nINGRESO INV�LIDO. ", 2))
								{
									if(!utn_getNumero(&auxiliarLegajo, "Ingrese n�mero de legajo: ", "\n\nINGRESO INVALIDO. ", 0, 4096, 2))
									{
										if(utn_buscarPrimeraOcurrencia(arrayLegajos, QTY_PERSONAS, auxiliarLegajo) == -1)
										{
											strncpy(arrayNombres[auxiliarIndice], auxiliarNombre, SIZE);
											strncpy(arrayApellidos[auxiliarIndice], auxiliarApellido, SIZE);
											arrayLegajos[auxiliarIndice] = auxiliarLegajo;
											printf("\nSE MODIFIC� LA PERSONA DE LA AGENDA CON �XITO.\n");
										}
										else
										{
											printf("\nYA EXISTE EL N�MERO DE LEGAJO INGRESADO.\n");
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
					if(utn_imprimirAgenda(arrayNombres, arrayApellidos, arrayLegajos, QTY_PERSONAS) == -1)
					{
						printf("ERROR AL MOSTRAR AGENDA.\n");
					}
					printf("______________________________\n\n");
					break;
				case 5:
					printf("\n_____ ORDENAR AGENDA POR APELLIDO _____\n\n");
					if(utn_ordenarAgendaPorApellido(arrayNombres, arrayApellidos, arrayLegajos, QTY_PERSONAS) == -1)
					{
						printf("ERROR AL ORDENAR AGENDA.\n");
					}
					else
					{
						printf("LA AGENDA FUE ORDENADA CON �XITO.\n");
					}
					printf("______________________________\n\n");
					break;
			}
		}
	}while(opcion != 6);
	return EXIT_SUCCESS;
}
