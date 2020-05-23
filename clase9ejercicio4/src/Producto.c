/*
 * Producto.c
 *
 *  Created on: 23 abr. 2020
 *      Author: Usuario
 */
#include "Producto.h"
#include "utn.h"
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
			printf("[%d] %s - %s - %f\n\n",i,producto[i].nombre,producto[i].descripcion,producto[i].precio);
		}
	}
	return retorno;
}

int prod_cargarArrayProducto(Producto* producto,int sizeProducto,int indice)
{
	int retorno=-1;
	Producto auxProducto;

	if(producto!=NULL && sizeProducto>0 && indice<sizeProducto)
	{
		retorno=0;
		if(	   utn_getNombre(auxProducto.nombre, NOMBRE_LEN, "Ingrese nombre: \n", "Ingreso NO VÁLIDO\n", 2)==0
			&& utn_getNombre(auxProducto.descripcion, DESC_LEN, "Ingrese descripcion: \n", "Ingreso NO VÁLIDO\n", 2)==0
			&& utn_getNumeroFlotante(&auxProducto.precio, "Ingrese precio: \n", "Ingreso NO VÁLIDO\n", 0.0, 1000000.90, 2)==0 )
		{
			retorno=1;
			producto[indice]=auxProducto;
		}
	}
	return retorno;
}
