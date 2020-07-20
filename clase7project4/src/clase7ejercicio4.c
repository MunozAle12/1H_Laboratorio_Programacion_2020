/*
 ============================================================================
 Name        : clase7ejercicio4.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	Ejercicio 4:

	Completar la función getFloat() para que devuelva un número
	float válido ingresado por el usuario
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Verifica si la cadena ingresada es válida como número flotante.
 *
 * \param cadena Es la cadena de caracteres a ser analizada.
 * \return Retorna 1 (vardadero) si la cadena es un número flotante, 0 (falso) si no lo es, -1 si es.
 *
 */
static int validarFloat(char* cadena)
{
	int retorno = -1;
	int i;
	int contadorPuntos = 0;

	if(cadena != NULL)
	{
		retorno = 1;
		for(i = 0 ; cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+' || cadena[i] == '.'))
			{
				if(cadena[i] == '.')
				{
					contadorPuntos++;
				}
				continue;
			}
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.')
			{
				retorno = 0;
				break;
			}
			if(cadena[i] == '.')
			{
				contadorPuntos++;
				if(contadorPuntos > 1)
				{
					retorno = 0;
					break;
				}
			}
		}
		if(contadorPuntos == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Lee del archivo stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 		  un máximo de 'longitud - 1' caracteres. Luego verifica si lo que se ingresó es un número.
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * \return Retorna 1 (EXITO) si se obtiene un numero flotante válido, 0 si no, -1 si el puntero a pResultado es NULL.
 *
 */
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];
	int respuesta;

	if(pResultado != NULL)
	{
		retorno = 0;
		fflush(stdin);
		fgets(buffer, 4096, stdin);
		buffer[strnlen(buffer,4096)-1] = '\0';
		respuesta = validarFloat(buffer);
		if(respuesta)
		{
			retorno = 1;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}

int main(void)
{
	setbuf(stdout, NULL);
	float precio;
	int respuesta;

	printf("Ingrese un precio: \n");
	respuesta = getFloat(&precio);
	if(respuesta)
	{
		printf("El precio es válido: %f\n", precio);
	}
	else
	{
		if(!respuesta)
		{
			printf("Valor incorrecto\n");
		}
		else
		{
			printf("ERROR.\n");
		}
	}
	return EXIT_SUCCESS;
}
