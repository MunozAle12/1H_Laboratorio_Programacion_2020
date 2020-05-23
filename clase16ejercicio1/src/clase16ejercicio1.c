/*
 ============================================================================
 Name        : clase16ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 TEMAS:
 * Punteros a función
 * Memoria dinámica
 * Puntero a puntero
 * Desarrollo de la función resizeArray()
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * brief Inicializo un puntero a array de tipo int en un valor determinado
 * param pArray Puntero al espacio de memoria donde comienza el array a inicializar
 * param limite Tamaño del puntero al array a inicializar
 * param valor Valor con el que se va a inicializar cada posición del array
 * return Retorna -1 si ERROR, 0 si se inicilizó el puntero al array
 *
 */
int initArray(int* pArray,int limite,int valor)
{
	int respuesta = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		respuesta = 0;
		for(i = 0; i < limite; i++)
		{
			*(pArray + i) = valor;	// --> es equivalente a pArray[i] = valor;
		}							// Aplicando álgebra de punteros accedo en modo escritura a la posición
	}								// de memoria de cada elemento del puntero a array y escribo el valor.
	return respuesta;
}
/**
 * brief Imprime los elementos de un puntero a array de tipo int
 * param pArray Puntero al espacio de memoria donde comienza el array a imprimir
 * param limite Tamaño del array a imprimir
 * return Retorna -1 si ERROR, 0 si se logró imprimir el array
 *
 */
int imprimirArray(int* pArray,int limite)
{
	int respuesta = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		respuesta = 0;
		for(i = 0; i < limite; i++)
		{
			printf("%d\n",*(pArray + i)); //--> Aplicando álgebra de punteros accedo en modo lectura
		}									 // a la posición de memoria de cada elemento del puntero
	}										 // a array e imprimo el valor.
	return respuesta;
}
/**
 * brief Redimensiona el tamaño de la variable puntero del tipo int
 *
 */
int resizeArray(int** pArray,int* sizeActual,int sizeNuevo)
{
	int* pArrayTemp = NULL;
	int retorno = -1;
	if(pArray != NULL && sizeActual != NULL && sizeNuevo >= 0)
	{
		pArrayTemp = (int*)realloc(*pArray,sizeof(int) * sizeNuevo);
		if(pArrayTemp != NULL)
		{
			*sizeActual = sizeNuevo;
			*pArray = NULL;
			pArrayTemp = NULL;
			retorno = 0;
		}
	}
	return retorno;
}

int main(void)
{
	setbuf(stdout,NULL);
	int* pArrayEdades = NULL; //Declaro una variable puntero a array del tipo int llamado pArrayEdades y la inicializo con NULL.

	int sizeArrayEdades = 10; /*Declaro una variable del tipo int que me determina el tamaño inicial del puntero a array.
								Por cada variable puntero a array que declare, necesito declarar una variable que contenga como valores
								dinámicos el size de inicio de ese array.*/

	pArrayEdades = (int*)malloc(sizeof(int) * sizeArrayEdades); /*Realizo una reserva dinámica de memoria en el segmento Heap con
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  la función malloc. Ésta retorna un puntero del tipo void
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  a una longitud de bytes o un puntero nulo si no se pudo asignar.
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  A dicho puntero puedo asignarle cualquier tipo de la variable puntero
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  mediante el casteo.*/

	if(pArrayEdades != NULL) //Si se pudo asignar una reserva dinámica de memoria, relizo las siguentes acciones.
	{
		if(!initArray(pArrayEdades,sizeArrayEdades,0))	//Inicializo en '0' la variable puntero del tipo int 'pArrayEdades'.
		{
			printf("\n¡Init Ok!\n");
			imprimirArray(pArrayEdades,sizeArrayEdades); //Imprimo los valores de la variable puntero del tipo int 'pArrayEdades'.
		}
		if(!resizeArray(&pArrayEdades,&sizeArrayEdades,25)) //Modifico la longitud de la variable puntero del tipo int 'pArrayEdades'
		{
			printf("\n¡Resize Ok!\n");
			imprimirArray(pArrayEdades,sizeArrayEdades);
		}
	}
	free(pArrayEdades);	/*Libero la reserva dinámica de memoria con la función free. Ésto es necesario realizarlo
						  durante la ejecución del programa, no al terminar la ejecución del mismo.*/
	return EXIT_SUCCESS;
}
