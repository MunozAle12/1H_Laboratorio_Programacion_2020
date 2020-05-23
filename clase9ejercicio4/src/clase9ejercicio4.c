/*
 ============================================================================
 Name        : clase9ejercicio4.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 4:
 Tomar el "Ejercicio 3" y realizar una función que reciba el array,
 un indice, y le permita al usuario cargar los datos en el item de
 la posición especificada por el indice.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"

#define PRODUCT_LEN 100

int main(void)
{
	setbuf(stdout,NULL);
	//TIPO	NOMBRE_VARIABLE
	Producto producto[PRODUCT_LEN];

	if(!prod_inicializarArrayProducto(producto,PRODUCT_LEN))
	{
		printf("Array inicializado OK.\n");
	}
	else
	{
		printf("ERROR.\n");
	}
	prod_imprimirProducto(producto,PRODUCT_LEN);

	if(prod_cargarArrayProducto(producto,PRODUCT_LEN,2))
	{
		prod_imprimirProducto(producto,PRODUCT_LEN);
	}
	else
	{
		if(!prod_cargarArrayProducto(producto,PRODUCT_LEN,2))
		{
			printf("ERROR EN LA CARGA DE ALGÚN CAMPO.\n");
		}
		else
		{
			printf("ERROR.\n");
		}
	}
	return EXIT_SUCCESS;
}
