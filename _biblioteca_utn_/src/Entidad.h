/*
 * Entidad.h
 *
 *  Created on: 29 abr. 2020
 *      Author: Usuario
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#define CHAR1_LEN
#define CHAR2_LEN

typedef struct
{
	char arrayChar1[CHAR1_LEN];
	char arrayChar2[CHAR2_LEN];
	float varFloat1;
	int varInt1;
	int varInt2;
}Entidad;

int ent_inicializarArray(Entidad* array,int limite);
int ent_imprimir(Entidad* pElemento);
int ent_imprimirArray(Entidad* array,int limite);
int ent_altaArray(Entidad* array,int limite,int indice,int* id);
int ent_modificarArray(Entidad* array,int limite,int indice);
int ent_bajaArray(Entidad* array,int limite,int indice);
int ent_buscarId(Entidad array[],int limite,int valorBuscado);
int ent_getEmptyIndex(Entidad* array,int limite);
int ent_ordenarAscendente(Entidad* array,int limite);

#endif /* ENTIDAD_H_ */
