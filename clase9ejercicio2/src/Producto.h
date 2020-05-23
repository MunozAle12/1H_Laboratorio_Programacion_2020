/*
 * Producto.h
 *
 *  Created on: 23 abr. 2020
 *      Author: Usuario
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define NOMBRE_LEN 50
#define DESC_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	char descripcion[DESC_LEN];
	float precio;
}Producto;

void imprimirProducto(Producto* producto);

#endif /* PRODUCTO_H_ */
