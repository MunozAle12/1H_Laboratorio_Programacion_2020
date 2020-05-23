/*
 ============================================================================
 Name        : clase9ejercicio2.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Ejercicio 2.
 Tomar el programa del ejercicio anterior y agregarle lo siguiente:
 1) Una vez que el usuario ingreso los datos, preguntarle si
 quiere aplicar un descuento del 25% al precio del producto.
 Si acepta, calcular el nuevo precio.
 2) Hacer una funcion que reciba la variable producto definida
 y que imprima sus valores.
 NOTA: Pude pasarse la variable producto por referencia o por
 valor. ¿Cual es la diferencia?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"

int main(void)
{
	setbuf(stdout, NULL);
	//TIPO	NOMBRE_VARIABLE
	Producto producto;
	char respuesta[2];	//Variable donde guardo la respuesta del usuario.

	if(	   utn_getNombre(producto.nombre, NOMBRE_LEN, "Ingrese nombre: \n", "Ingreso NO VÁLIDO\n", 2)==0
		&& utn_getNombre(producto.descripcion, DESC_LEN, "Ingrese descripcion: \n","Ingreso NO VÁLIDO\n", 2)==0
		&& utn_getNumeroFlotante(&producto.precio, "Ingrese precio: \n", "Ingreso NO VÁLIDO\n", 0.0, 1000000.90 , 2)==0	)
	{
		imprimirProducto(&producto);
	}

	if(utn_getNombre(respuesta, 2, "Quiere descuento? [s/n]: \n", "Ingreso NO VÁLIDO\n", 2)==0)
	{
		if(strncmp(respuesta, "s", 2)==0)
		{
			printf("APLICÓ DESCUENTO!\n");
			producto.precio = producto.precio * 0.75 ;
			imprimirProducto(&producto);
		}
	}
	return EXIT_SUCCESS;
}
