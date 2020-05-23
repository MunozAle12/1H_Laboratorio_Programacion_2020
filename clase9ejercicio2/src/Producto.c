/*
 * Producto.c
 *
 *  Created on: 23 abr. 2020
 *      Author: Usuario
 */
#include "Producto.h"
#include <stdlib.h>
#include <stdio.h>


void imprimirProducto(Producto* producto)
{
	printf("NOMBRE - DESCRIPCIÓN - PRECIO\n");
	printf("%s - %s - %f\n\n", producto->nombre, producto->descripcion, producto->precio);
}
