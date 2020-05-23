/*
 * Producto.c
 *
 *  Created on: 23 abr. 2020
 *      Author: Usuario
 */
#include "Producto.h"
#include <stdlib.h>
#include <stdio.h>

int prod_inicializarArrayProducto(Producto* producto,int sizeProducto)
{
	int retorno=-1;
	int i;

	if(producto!=NULL && sizeProducto>0)
	{
		retorno=0;
		for(i=0;i<sizeProducto;i++)	//Itero el array producto
		{
			producto[i].isEmpty=1;	//cargo en el campo isEmpty de cada posicion del array producto.
		}
	}
	return retorno;
}

int prod_imprimirProducto(Producto* producto,int sizeProducto)
{
	int retorno=-1;
	int i;

	if(producto!=NULL && sizeProducto>0)
	{
		retorno=0;
		for(i=0;i<sizeProducto;i++)
		{
			printf("NOMBRE - DESCRIPCIÓN - PRECIO\n");
			printf("%s - %s - %f\n\n",producto->nombre,producto->descripcion,producto->precio);
		}
	}
	return retorno;
}
