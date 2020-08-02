/*
 * utn.c
 *
 *  Created on: 20 jul. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 64

static int getInt(int* pResultado, int longitud);
static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena);
static int getNombre(char* pResultado, int longitud);
static int esNombre(char* cadena, int longitud);

/**
 * \brief Inicializa array del tipo int con un valor conocido.
 *
 * \param arrayInt[] Es el puntero a espacio de memoria donde comienza el array a inicializar.
 * \param len Es el tamaño del array.
 * \param valor Es el valor del tipo entero con el que se va a inicializar el array.
 * \return Retorna -1 si hubo error, 0 si se inicializó con éxito.
 *
 */
int utn_inicializarArrayInt(int arrayInt[], int len, int valor)
{
	int respuesta = -1;
	int i;

	if(arrayInt != NULL && len > 0)
	{
		respuesta = 0;
		for(i = 0; i < len; i++)
		{
			arrayInt[i] = valor;
		}
	}
	return respuesta;
}

/**
 * \brief Busca un valor conocido en el array del tipo int y al encontrar la primer ocurrencia, retorna su índice.
 *
 * \param arrayInt[] Es el puntero a espacio de memoria donde comienza el array a analizar.
 * \param len Es el tamaño del array.
 * \param valor Es el valor del tipo entero con el que se va a buscar en el array.
 * \return Retorna -1 si hubo error o no hubo una ocurrencia.
 * 		   Retorna un valor mayor-igual a 0 si encontró el valor buscado.
 *
 */
int utn_buscarPrimeraOcurrencia(int arrayInt[], int len, int valor)
{
	int respuesta = -1;
	int i;

	if(arrayInt != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(arrayInt[i] == valor)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief utn_getNumero Función que solicita el ingreso de un número y luego de verificarlo devuelve un resultado.
 *
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
			printf("%s", mensaje);
			if(!getInt(&buffer, sizeof(buffer)) && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}
/**
 * \brief getInt Función que busca y verifica si se ingresó un número entero.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la función.
 * \return Retorna 0 si se pudo encontrar un número válido, retorna -1 si no.
 *
 */
static int getInt(int* pResultado, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(pResultado != NULL && longitud > 0)
    {
        if(!myGets(bufferString, sizeof(bufferString)) && esNumerica(bufferString))
        {
        	retorno = 0;
        	*pResultado = atoi(bufferString);
        }
    }
    return retorno;
}
/**
 * \brief myGets Función que guarda una lectura del archivo stdin hasta que encuentra un '\0'
 *               o hasta que haya copiado en 'cadena' un máximo de 'longitud - 1'.
 *
 * \param pCadena Puntero a espacio de memoria donde se guardará la cadena de caracteres
 *                que se ingresó por teclado.
 * \param longitud Define el tamaño de pCadena.
 * \return Retorna 0 si se obtiene una cadena, -1 si no.
 *
 */
static int myGets(char* pCadena, int longitud)
{
	int retorno = -1;
	if(pCadena != NULL && longitud > 0)
	{
		retorno = 0;
		fflush(stdin);
		fgets(pCadena, longitud, stdin);
		pCadena[strlen(pCadena) - 1] = '\0';
	}
	return retorno;
}
/**
 * \brief esNumerica Función que verifica si los elementos de la cadena son numericos.
 *
 * \param pCadena Puntero al espacio de memoria donde guarda la cadena de caracteres a ser analizada.
 * \return Retorna 1 si la cadena de caracteres es numerica, 0 si no, -1 si hubo error.
 *
 */
static int esNumerica(char* pCadena)
{
	int retorno = -1;
	int i = 0;
	if(pCadena != NULL)
	{
		retorno = 1;
		if(pCadena[0] == '-' || pCadena[0] == '+')
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
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	if(pResultado != NULL && longitud > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(!getNombre(bufferString, sizeof(bufferString)) && strnlen(bufferString, sizeof(bufferString)) < longitud )
			{
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 *
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL && longitud > 0)
    {
    	if(!myGets(buffer, sizeof(buffer)) && esNombre(buffer, sizeof(buffer)))
    	{
    		strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena, int longitud)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && longitud > 0)
	{
		for(i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * TENER EN CUENTA:
 * Cuando recibimos un array con un solo subíndice como el argumento de una función, los corchetes
 * del arreglo están vacíos en la lista de parámetros de la función.
 * El primer subíndice de un array con múltiples subíndices tampoco es necesario,
 * pero todos los subíndices subsiguientes sí lo son. El compilador utiliza estos subíndices para determinar
 * las posiciones en memoria de los elementos correspondientes a array con múltiples subíndices.
 * Todos los elementos de un array se almacenan en memoria de manera consecutiva, independientemente
 * del número de subíndices. En un array con dos subíndices, la primera fila se almacena en memoria, seguida por la segunda.
 *
 */

/**
 * \brief imprimirNumeros Función que muestra por pantalla el valor de cada posición del array.
 *
 * \param arrayInt[] Puntero a espacio de memoria donde empieza el array.
 * \param len Define el tamaño de arrayInt.
 * \return Retorna 0 si se pudo imprimir, -1 si hubo error.
 *
 */
int utn_imprimirAgenda(char listaNombres[][SIZE], char listaApellidos[][SIZE], int arrayLegajos[], int cantidadPersonas)
{
	int retorno = -1;
	int i;

	if(listaNombres != NULL && listaApellidos != NULL && arrayLegajos != NULL && cantidadPersonas > 0)
	{
		retorno = 0;
		for(i = 0; i < cantidadPersonas; i++)
		{
			if(arrayLegajos[i] != -1)
			{
				printf("  %d  -  %s  -  %s\n", arrayLegajos[i], listaNombres[i], listaApellidos[i]);
			}
		}
	}
	return retorno;
}

/**
 * \brief Ordena la agenda por apellido de forma ascendente (de A-Z).
 *
 * \param listaNombres Puntero al espacio de memoria donde empieza el vector a ser analizado.
 * \param listaApellidos Puntero al espacio de memoria donde empieza el vector a ser analizado.
 * \param listaLegajos Puntero al espacio de memoria donde empieza el array a ser analizado.
 * \param cantidadPersonas Es el valor que representa la cantidad máxima de personas que tiene la agenda.
 * \return Retorna -1 si hubo error, 0 si se ordeno la agenda con éxito.
 *
 */
int utn_ordenarAgendaPorApellido(char listaNombres[][SIZE], char listaApellidos[][SIZE], int listaLegajos[], int cantidadPersonas)
{
	int retorno = -1;
	int i, j;
	int flagSwap;	//Bandera que indica, 1 si se hizo al menos un swap, 0 si no.
	char auxiliarNombre[SIZE];	//Variable auxiliar utilizada para guardar el valor a salvar para hacer swap.
	char auxiliarApellido[SIZE];
	int auxiliarLegajo;
	int limiteComparacion;	//Variable utilizada para indicar el límite de comparación de valores de índices.

	if(listaNombres != NULL && listaApellidos != NULL && listaLegajos != NULL && cantidadPersonas > 0)
	{
		retorno = 0;
		limiteComparacion = cantidadPersonas - 1;
		do
		{
			flagSwap = 0;
			for(i = 0; i < limiteComparacion; i++)
			{
				if(listaLegajos[i] == -1)
				{
					continue;
				}
				for(j = i + 1; j < limiteComparacion; j++)
				{
					if(listaLegajos[j] == -1)
					{
						continue;
					}
					if(strncmp(listaApellidos[i], listaApellidos[j], SIZE) > 0) //Ascendente (A - Z)
					{
						strncpy(auxiliarNombre, listaNombres[i], SIZE);
						strncpy(listaNombres[i], listaNombres[j], SIZE);
						strncpy(listaNombres[j], auxiliarNombre, SIZE);

						strncpy(auxiliarApellido, listaApellidos[i], SIZE);
						strncpy(listaApellidos[i], listaApellidos[j], SIZE);
						strncpy(listaApellidos[j], auxiliarApellido, SIZE);

						auxiliarLegajo = listaLegajos[i];
						listaLegajos[i] = listaLegajos[j];
						listaLegajos[j] = auxiliarLegajo;

						flagSwap = 1;
					}
				}
			}
			limiteComparacion--;
		}while(flagSwap);
	}
	return retorno;
}
