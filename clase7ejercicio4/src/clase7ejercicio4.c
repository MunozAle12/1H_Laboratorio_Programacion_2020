/*
 ============================================================================
 Name        : clase7ejercicio4.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 4:
 Completar la funcion getFloat() para que devuelva un numero
 float ingresado por el usuario
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int validarFloat(char* cadena)
{
	int retorno=-1;
	int i=0;
	int contadorPuntos=0;

	if(cadena!=NULL)
	{
		retorno=1;
		for(;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-' || cadena[i]=='+' || cadena[i]=='.'))
			{
				if(cadena[i]=='.')
				{
					contadorPuntos++;
				}
				continue;
			}
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				if(cadena[i]=='.')
				{
					contadorPuntos++;
					if(contadorPuntos>1)
					{
						retorno=0;
						break;
					}
					continue;
				}
				retorno=0;
				break;
			}
		}
		if(contadorPuntos==0)
		{
			retorno=0;
		}
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[128];

	if(pResultado!=NULL)
	{
		fgets(buffer,128,stdin);
		if(validarFloat(buffer)==1)
		{
			*pResultado=atof(buffer);
			retorno=1;
		}
		retorno=0;
	}
	return retorno;
}

int main(void)
{
	setbuf(stdout,NULL);
	float precio;
	printf("Ingrese un precio: \n");
	if(getFloat(&precio))
	{
		printf("El precio es valido: %f\n",precio);
	}
	else
	{
		if(!getFloat(&precio))
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
