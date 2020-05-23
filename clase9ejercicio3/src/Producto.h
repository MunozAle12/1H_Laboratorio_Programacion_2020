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
	int isEmpty;	//Variable que la utilizo como 'flag' para determinar si un elemento del array está en uso. 1 si está vacío, 0 si está ocupado.
}Producto;

int prod_inicializarArrayProducto(Producto* producto,int sizeProducto);
int prod_imprimirProducto(Producto* producto,int sizeProducto);

#endif /* PRODUCTO_H_ */
