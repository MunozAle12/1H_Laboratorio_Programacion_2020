/*
 ============================================================================
 Name        : clase7ejercicio5.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 5:
 a) Realizar un programa que pida el ingreso de 5 numeros int al usuario
    y los almacene en un array.
 b) Luego ejecutar la funcion borrarImpares() pasandole el array y que
    deberá reemplazar los numeros que son impares por un cero.
 c) Luego imprimir el array para chequear el funcionamiento.
 d) Ordenar el array de menor a mayor y volver a imprimirlo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZEARRAYINT 5
#define RANGOMIN -32768
#define RANGOMAX 32767
#define REINTENTOS 2

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena);
int borrarImpares(int arrayInt[], int len);
int imprimirNumeros(int arrayInt[], int len);
int ordenarArrayInt(int* pArrayInt, int len);
/**
 * \brief borrarImpares Función que analiza cada elemento del array y convierte su valor en 0 si es impar.
 * \param arrayInt Espacio de memoria donde comienza arrayInt[].
 * \param Define el tamaño de arrayInt[].
 * \return Retorna 0 si pudo convertir, -1 si no pudo convertir.
 *
 */
int borrarImpares(int arrayInt[], int len)
{
	int retorno = -1;
	int i;

	if(arrayInt != NULL && len > 0)
	{
		//reemplazo impares a cero
		for(i=0; i<len; i++)
		{
			if((arrayInt[i]%2) != 0)
			{
				arrayInt[i] = 0;
				retorno = 0;
			}
		}
	}
	return retorno;
}
/**
 * \brief imprimirNumeros Función que muestra por pantalla el valor de cada posición del array.
 * \param arrayInt[] Puntero a espacio de memoria donde empieza el array.
 * \param len Define el tamaño de arrayInt.
 * \return Retorna 0 si está todo bien, -1 si está todo mal.
 *
 */
int imprimirNumeros(int arrayInt[], int len)
{
	int retorno = -1;
	int i;

	if(arrayInt != NULL && len > 0)
	{
		retorno = 0;
		for(i=0; i<len; i++)
		{
			printf("\nPosicion #%d: %d\n", i, arrayInt[i]);
		}
	}
	return retorno;
}
/**
 * \brief ordenarArrayInt Función que ordena los valores de cada índice de forma ascendente.
 * \param pArrayInt Puntero al espacio de memoria donde se guarda el array a ser analizado.
 * \param len Define el tamaño del array a ser analizado.
 * \return Retorna 0 si se pudo ordenar el array, -1 si no se pudo.
 *
 */
int ordenarArrayInt(int* pArrayInt, int len)
{
	int retorno = -1;
	int i;
	int flagSwap;	//Bandera que indica, 1 si se hizo al menos un swap, 0 si no.
	int bufferAux;	//Variable auxiliar utilizada para guardar el valor a salvar para hacer swap.
	int limiteComparacion;	//Variable utilizada para indicar el límite de comparación de valores de índices.

	if(pArrayInt != NULL && len > 0)
	{
		retorno = 0;
		limiteComparacion = len - 1;
		do
		{
			flagSwap = 0;
			for(i=0; i<limiteComparacion; i++)
			{
				while(pArrayInt[i] > pArrayInt[i+1]) //Ascendente
				{
					bufferAux = pArrayInt[i];
					pArrayInt[i] = pArrayInt[i+1];
					pArrayInt[i+1] = bufferAux;
					flagSwap = 1;
				}
			}
			limiteComparacion--;
		}while(flagSwap);
	}
	return retorno;
}

int main(void)
{
	setbuf(stdout, NULL);
	int bufferArrayInt[SIZEARRAYINT];
	int bufferAux;
	int i;
	int respuesta;

	// Ingreso de numeros
	for(i=0; i<SIZEARRAYINT; i++)
	{
		if(utn_getNumero(&bufferAux,"Ingrese un número: \n","INGRESE UN NUMERO VALIDO\n", RANGOMIN, RANGOMAX, REINTENTOS) == 0)
		{
			bufferArrayInt[i] = bufferAux;
		}
		else
		{
			printf("ERROR.\n");
		}
	}
	// borrar impares
	respuesta = borrarImpares(bufferArrayInt, SIZEARRAYINT);
	if(respuesta == 0)
	{
		// imprimir
		respuesta = imprimirNumeros(bufferArrayInt, SIZEARRAYINT);
	}
	else
	{
		// imprimir
		printf("\nNO SE INGRESARON NUMEROS IMPARES\n");
		respuesta = imprimirNumeros(bufferArrayInt, SIZEARRAYINT);
	}

	// ordenar
	respuesta = ordenarArrayInt(bufferArrayInt, SIZEARRAYINT);
	{
		if(respuesta == 0)
		{
			// imprimir
			respuesta = imprimirNumeros(bufferArrayInt, SIZEARRAYINT);
		}
		else
		{
			// imprimir
			printf("\nSE INGRESARON NUMEROS ORDENADOS\n");
			respuesta = imprimirNumeros(bufferArrayInt, SIZEARRAYINT);
		}
	}

	return EXIT_SUCCESS;
}
/**
 * \brief utn_getNumero Función que solicita el ingreso de un número y luego de verificarlo devuelve un resultado.
 * \param pResultado Puntero al espacio de memoria donde se guardará el número verificado.
 * \param mensaje Mensaje a ser mostrado.
 * \param mensajeError Mensaje a ser mostrado en caso de ingresar un caracter no válido.
 * \param minimo Valor minimo del rango aceptado.
 * \param maximo Valor maximo del rango aceptado.
 * \param reintentos Cantidad de reintentos para ingresar un dato válido.
 * \return Retorna 0 si se obtuvo un número válido, retorna -1 si no.
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}
/**
 * \brief getInt Función que busca y verifica si se ingresó un número entero.
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la función.
 * \return Retorna 0 si se pudo encontrar un número válido, retorna -1 si no.
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(myGets(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString))
    {
    	retorno = 0;
    	*pResultado = atoi(bufferString);
    }
    return retorno;
}
/**
 * \brief myGets Función que guarda una lectura del archivo stdin hasta que encuentra un '\0'
 *               o hasta que haya copiado en 'cadena' un máximo de 'longitud - 1'.
 * \param pCadena Puntero a espacio de memoria donde se guardará la cadena de caracteres
 *                que se ingresó por teclado.
 * \param longitud Define el tamaño de pCadena.
 * \return Retorna 0 si se obtiene una cadena, -1 si no.
 *
 */
static int myGets(char* pCadena, int longitud)
{
	fflush(stdin);
	fgets(pCadena, longitud, stdin);
	pCadena[strlen(pCadena) - 1] = '\0';

	return 0;
}
/**
 * \brief esNumerica Función que verifica si los elementos de la cadena son numericos.
 * \param pCadena Puntero al espacio de memoria donde guarda la cadena de caracteres a ser analizada.
 * \return Retorna 0 si la cadena de caracteres es numerica, 1 si no.
 *
 */
static int esNumerica(char* pCadena)
{
	int retorno = 1;
	int i = 0;

	if(pCadena[0] == '-')
	{
		i = 1;
	}

	for( ; pCadena[i] != '\0' ; i++)
	{
		if(pCadena[i] > '9' || pCadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
