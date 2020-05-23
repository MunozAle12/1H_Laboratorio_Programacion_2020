/*
Ejercicio 1:
Definir un nuevo tipo de dato que represente un producto.
El producto tiene un nombre, una descripcion y un precio.
Hacer un programa que le pida al usuario los datos del producto
y los cargue en una variable del tipo Producto definida en la
funcion main.
Imprmir los campos de la variable producto para chequear que
esten cargadas correctamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "producto.h"

int main(void)
{
	setbuf(stdout, NULL);
	//TIPO	NOMBRE_VARIABLE
	Producto producto;

	if(	   utn_getNombre(producto.nombre, NOMBRE_LEN, "Ingrese nombre: \n", "Ingreso NO VÁLIDO\n", 2)==0
		&& utn_getNombre(producto.descripcion, DESC_LEN, "Ingrese descripcion: \n", "Ingreso NO VÁLIDO\n", 2)==0
		&& utn_getNumeroFlotante(&producto.precio, "Ingrese precio: \n", "Ingreso NO VÁLIDO\n", 0.0, 1000000.90, 2)==0 )
	{
		printf("NOMBRE - DESCRIPCIÓN - PRECIO\n");
		printf("%s  -  %s  -  %f\n", producto.nombre, producto.descripcion, producto.precio);
	}
	return EXIT_SUCCESS;
}
