/*
 * Entidad.c
 *
 *  Created on: 29 abr. 2020
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entidad.h"
#include "utn.h"

/**
 * \brief Inicializa el array del una entidad.
 * \param array Array de la entidad a ser actualizada.
 * \param limite Limite del array de la entidad.
 * \return Retorna 0 (EXITO) si se inicializó el array, -1 (ERROR) si no.
 *
 */
int ent_inicializarArray(Entidad* array,int limite)
{
	int retorno=-1;
	int i;
	if(array!=NULL && limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)//Recorro cada elemento del array indicando con un 1 que está vacío (isEmpty).
		{
			array[i].varInt2=1;
		}
	}
	return retorno;
}
/**
 * \brief Imprime los campos de un elemento de una entidad específica.
 * \param pElemento Puntero al elemento que se busca imprimir.
 * \return Retorna 0 (EXITO) si se pudo imprimir el elemento, -1 (ERROR) si no.
 *
 */
int ent_imprimir(Entidad* pElemento)
{
	int retorno=-1;
	if(pElemento!=NULL && strlen[pElemento]>0)
	{
		retorno=0;
		printf("ID: %d - %s - %s - %.2f",pElemento->varInt1,pElemento->arrayChar1,pElemento->arrayChar2,pElemento->varFloat1);
	}
	return retorno;
}
/**
 * \brief Imprime el array de una entidad.
 * \param array Array de la entidad a ser actualizada.
 * \param limite Limite del array de la entidad.
 * \return Retorna 0 (EXITO) si se pudo imprimir el elemento, -1 (ERROR) si no.
 *
 */
int ent_imprimirArray(Entidad* array,int limite)
{
	int retorno=-1;
	int i;
	if(array!=NULL && limite>0)
	{
		retorno=0;
		for(i=0;i<limite;i++)//Recorro cada elemento del array de la entidad
		{
			if(array[i].varInt2!= 1)//Si el elemento del array está ocupado (isEmpty), lo imprimo.
			{
				printf("\nID: %d - %s - %s - %.2f",array[i].varInt1,array[i].arrayChar1,array[i].arrayChar2,array[i].varFloat1);
			}
		}
	}
	return retorno;
}
/**
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int ent_altaArray(Entidad* array,int limite,int indice,int* id)
{
	int retorno=-1;
	Entidad auxiliar;//Creo una variable auxiliar para validar y cargar cada campo de la entidad.
	if(array!=NULL && limite>0 && indice<limite && id!=NULL)
	{
		//Solicito y valido el ingreso de los datos que se cargarán en cada campo de la entidad.
		if(	utn_getNombre(auxiliar.arrayChar1,CHAR1_LEN,"Ingrese dato 1: \n","Dato no valido\n",2)==0 &&
			utn_getDni(auxiliar.arrayChar2,CHAR2_LEN,"Ingrese dato 2: \n","Dato no valido\n",2)==0 &&
			utn_getNumeroFlotante(&auxiliar.varFloat1,"Ingrese dato 3: \n","Dato no valido\n",0,5,2)==0 )
		{
			//Si se cargaron bien los datos, copio lo que se guardo en la variable auxiliar en el indice a dar de alta.
			retorno = 0;
			array[indice] = auxiliar;
			array[indice].varInt2 = 0;//Indico con un 0 que el indice no está vacío (isEmpty=FALSE).
			array[indice].varInt1 = *id;//Le asigno el número de ID que me pasaron como parametro al campo ID del elemento de la entidad.
			*id = *id + 1;//Incremento el ID en 1 para la próxima alta.
		}
	}
	return retorno;
}
/**
 * \brief Actualiza los datos (campos) en una posicion del array de la entidad.
 * \param array Array de la entidad a ser actualizada.
 * \param limite Limite del array de la entidad.
 * \param indice Posicion del array a ser actualizada.
 * \return Retorna 0 (EXITO) y -1 (ERROR).
 *
 */
int ent_modificarArray(Entidad* array,int limite,int indice)
{
	int retorno=-1;
	Entidad auxiliar;
	if(array!=NULL && limite>0 && indice<limite)
	{
		//Solicito y valido el ingreso de los datos que se cargarán en cada campo de la entidad.
		if(	utn_getNombre(auxiliar.arrayChar1, CHAR1_LEN, "Ingrese dato 1: \n","Dato no valido\n",2)==0 &&
			utn_getDni(auxiliar.arrayChar2, CHAR2_LEN, "Ingrese dato 2: \n", "Dato no valido\n",2)==0 &&
			utn_getNumeroFlotante(&auxiliar.varFloat1,"Ingrese dato 3: \n","Dato no valido\n",0,5,2)==0 )
		{
			retorno=0;
			array[indice]=auxiliar;
			array[indice].varInt2=0;//Indico con un 0 que el indice no está vacío (isEmpty=FALSE).
		}
	}
	return retorno;
}
/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int ent_bajaArray(Entidad* array,int limite,int indice)
{
	int retorno=-1;
	if(array!=NULL && limite>0 && indice<limite)
	{
		retorno=0;
		array[indice].varInt2=1;//Indico que la posición del array de la entidad está vacio (isEmpty=TRUE).
	}
	return retorno;
}
/**
 * \brief Busca un ID en el array de una entidad y devuelve la posicion en que se encuentra.
 * \param array[] Array de la entidad a ser analizada.
 * \param limite Tamaño del array de la entidad a ser analizada.
 * \param valorBuscado Valor del ID a ser buscado.
 * \return Retorna el indice si encuentra el valor buscado, -1 si no.
 *
 */
int ent_buscarId(Entidad array[],int limite,int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
        	//Recorro cada elemento del array buscando que la posicion analizada no esté vacia y que el ID coincida con el valor buscado.
            if(array[i].varInt2==0 && array[i].varInt1==valorBuscado)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Buscar la primer posicion vacia del array de la entidad.
 * \param array Array de la entidad a ser analizada.
 * \param limite Limite del array de la entidad.
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int ent_getEmptyIndex(Entidad* array,int limite)
{
	int retorno=-1;
	int i;
	if(array!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			//Recorro cada posición del array de la entidad buscando que esté vacía (isEmpty=TRUE)
			if(array[i].varInt2==1)
			{
				retorno=i;//Cambio el valor de retorno por el indice de la posicion vacia.
				break;//Rompo iteracion.
			}
		}
	}
	return retorno;
}
/**
 * \brief Ordenar el array de la entidad alfabeticamente.
 * \param array Array de la entidad a ser analizada.
 * \param limite Limite del array de la entidad.
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int ent_ordenarAscendente(Entidad* array,int limite)
{
	int retorno=-1;
	int i;
	int flagSwap;
	Entidad auxiliar;
	if(array!=NULL && limite>0)
	{
		retorno=0;
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				if(	array[i].varInt2 == 0 &&//Corroboro que la posicion a comparar no esté vacia
					array[i+1].varInt2 == 0 &&//Corroboro que la posicion a comparar no esté vacia
					strncmp(array[i].arrayChar1,array[i+1].arrayChar1,CHAR1_LEN)>0 )//Ordeno de A-Z o Menor a Mayor.
				{
					auxiliar = array[i];
					array[i]= array[i+1];
					array[i+1] = auxiliar;
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return retorno;
}
