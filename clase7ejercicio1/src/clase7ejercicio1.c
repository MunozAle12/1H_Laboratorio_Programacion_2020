/*
 ============================================================================
 Name        : clase7ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 1:
 Escribir la funcion calcularMayor(). La funcion debe recibir dos
 numeros int y devolver por referencia, el numero mayor.
 La funcion debe retornar un 1 si encontro un mayor, o un 0
 si ambos numeros son iguales.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int calcularMayor(int* pResultado,int primerNumero,int segundoNumero);

#define TRUE 0
#define FALSE 1
#define RANGO_MIN -32768
#define RANGO_MAX 32767
#define REINTENTOS 2

int main(void)
{
	setbuf(stdout,NULL);
	int resultado;
	int num1;
	int num2;
	int respuesta;

	// Pedir dos numeros al usuario con utn_getNumber() y guardarlos en num1 y num 2
	if(!utn_getNumero(&num1,"Ingrese un número: \n","ERROR.\n",RANGO_MIN,RANGO_MAX,REINTENTOS))
	{
		printf("El 1er numero es: %d\n",num1);
	}
	else
	{
		printf("ERROR.\n");
	}
	if(!utn_getNumero(&num2,"Ingrese un número: \n","ERROR.\n",RANGO_MIN,RANGO_MAX,REINTENTOS))
	{
		printf("El 2do numero es: %d\n",num2);
	}
	else
	{
		printf("ERROR.\n");
	}

	//Llamo a la funcion calcularMayor()
	respuesta=calcularMayor(&resultado,num1,num2);
	if(respuesta==1)
	{
		printf("Los numeros son iguales\n");
	}
	else
	{
		if(respuesta==0)
		{
			printf("El mayor es: %d\n",resultado);
		}
		else
		{
			printf("ERROR.\n");
		}
	}

return EXIT_SUCCESS;
}
/*
 * \brief Función que recibe dos numeros enteros y calcula el mayor de ellos.
 * \param pResultado Puntero a espacio de memoria donde se guardará el resultado de la función.
 * \param primerNumero Primer numero entero a comparar.
 * \param segundoNumero Segundo numero entero a comparar.
 * \return Retona 0 si se encontró un número mayor, 1 si son iguales, -1 si hay error.
 *
 */
int calcularMayor(int* pResultado,int primerNumero,int segundoNumero)
{
	int retorno=-1;

	if(pResultado!=NULL)
	{
		retorno=0;
		if(primerNumero==segundoNumero)
		{
			retorno=1;
		}
		else
		{
			if(primerNumero>segundoNumero)
			{
				*pResultado=primerNumero;
				retorno=0;
			}
			else
			{
					*pResultado=segundoNumero;
					retorno=0;
			}
		}
	}
	return retorno;
}
