/*
 ============================================================================
 Name        : clase9ejercicio3.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 3.
 Utilizando la biblioteca "Producto.h" de los ejercicios anteriores,
 definir un array de 100 productos.
 Realizar una funcion que inicialice el array indicando que los items
 no estan cargados con informacion valida.
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

	return EXIT_SUCCESS;
}
