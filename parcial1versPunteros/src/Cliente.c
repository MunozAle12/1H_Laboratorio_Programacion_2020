/*
 * cliente.c
 *
 *  Created on: 28 abr. 2020
 *      Author: Usuario
 */

#include "Cliente.h"
#include "utn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Busca y reserva un espacio en memoria de manera dinámica para guardar un nuevo cliente
 *
 * \param void No recibe paramatros
 * \return Retorna la dirección de memoria donde comieza el puntero, NULL si no se encontró espacio en memoria
 *
 */
Cliente* cli_reservarMemoriaDinamicaParaNuevoCliente(void)
{
	Cliente* pClienteNuevo = (Cliente*)malloc(sizeof(Cliente));
	if(pClienteNuevo != NULL)
	{
		pClienteNuevo->nombre[0] = '\0';
		pClienteNuevo->apellido[0] = '\0';
		pClienteNuevo->cuit[0] = '\0';
		pClienteNuevo->idCliente = 0;
	}
	return pClienteNuevo;
}

/**
 * \brief Inicializa el array de punteros a clientes
 *
 * \param array Puntero al espacio de memoria donde comienza el array del tipo Cliente* a ser actualizado
 * \param limite Tamaño del array a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_initArrayPunteros(Cliente** array, int limite) //--> Firma equivalente = int cli_initArrayPunteros(Cliente** array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0; i<limite; i++)
		{
			*(array+i) = NULL; //--> *(array+i) => array[i]
		}
	}
	return respuesta;
}

/**
 * \brief Busca la primer posicion disponible en array de punteros a clientes
 *
 * \param array Puntero al espacio de memoria donde comienza el array del tipo Cliente* a ser actualizado
 * \param limite Tamaño del array a ser actualizado
 * \return Retorna el indice de la posicion vacia, -1 si hubo ERROR
 *
 */
int cli_getEmptyIndexArrayPunteros(Cliente* array[], int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			if(array[i] == NULL)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un cliente en una posicion del puntero a array del tipo Cliente*
 *
 * \param array Puntero al espacio de memoria donde comienza el puntero a array a ser actualizado
 * \param limite Tamaño del array a ser actualizado
 * \param indiceLibre Posicion a ser actualizada
 * \param idCliente Identificador a ser asignado al cliente
 * \return Retorna 1 si se realizó el alta de un cliente, 0 si no hay espacio en memoria, -1 si no se cargaron los campos de manera correcta, -2 si hubo ERROR
 *
 */
int cli_DarAltaClienteArrayPunteros(Cliente* array[], int limite, int indiceLibre, int* idCliente)
{
	int respuesta = -1;
	Cliente auxiliarCliente;
	Cliente* pAuxiliarCliente;
	if(array != NULL && limite > 0 && indiceLibre < limite && idCliente != NULL)
	{
		respuesta = -2;
		if(	!utn_getNombre(auxiliarCliente.nombre, NOMBRE_LEN, "Ingrese nombre: \n", "\nNOMBRE NO VALIDO. ",2) &&
			!utn_getApellido(auxiliarCliente.apellido,APELLIDO_LEN,"Ingrese apellido: \n","\nAPELLIDO NO VALIDO. ",2) &&
			!utn_getCuit(auxiliarCliente.cuit, CUIT_LEN, "Ingrese CUIT: \n", "\nCUIT NO VALIDO. ",2) &&
			cli_buscarCuitArrayPunteros(array,limite,auxiliarCliente.cuit) == -1 ) //Se verifica que el nuevo cliente no exista en array
		{
			respuesta = -3;
			auxiliarCliente.idCliente = *idCliente;
			pAuxiliarCliente = cli_reservarMemoriaDinamicaParaNuevoCliente(); //Si encuentra memoria dinámica para nuevo cliente,
			if(pAuxiliarCliente != NULL)									  //guardo dirección de memoria en pAuxiliarCliente.
			{
				respuesta = 0;
				*pAuxiliarCliente = auxiliarCliente;	//Copio los campos de auxiliarCliente en pAuxiliarCliente anteponiendo operador de indirección (*)
				array[indiceLibre] = pAuxiliarCliente;	//Copio los campos de pAuxiliarCliente en array[indiceLibre]
				(*idCliente)++;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Busca y verifica si existe o no un CUIT en un array
 * \param array Puntero al espacio de memoria donde comienza el array a ser analizado
 * \param limite Tamaño del array de clientes
 * \param valorBuscado valor del CUIT a ser buscado
 * \return Return Retorna el indice donde se encuentra el valor buscado, (-1) si no encuentra el valor buscado
 *
 */
int cli_buscarCuitArrayPunteros(Cliente* array[],int limite,char* valorBuscado)
{
    int retorno = -1;
    int i;
    if(array!= NULL && limite >= 0)
    {
        for(i=0; i<limite; i++)
        {
            if( array[i] != 0 &&
            	strncmp(array[i]->cuit,valorBuscado,CUIT_LEN) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Da de alta un cliente en una posicion del array de punteros del tipo Cliente* en modo DEBUG
 * \param array Puntero a espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tamaño del array de clientes
 * \param indice Posicion a ser actualizada
 * \param idCliente Puntero a espacio de memoria donde se encuentra el ID a ser asignado al cliente
 * \param nombre Puntero a espacio de memoria donde se encuentra el nombre a ser asignado
 * \param apellido Puntero a espacio de memoria donde se encuentra el apellido a ser asignado
 * \param cuit Puntero a espacio de memoria donde se encuentra el cuit a ser asignado
 * \return Retorna 0 (EXITO), -1 (ERROR)
 *
 */
int cli_altaArrayPunterosClientesDebug(Cliente* array[],int limite,int indice,int* idCliente,char* nombre,char* apellido,char* cuit)
{
	int respuesta = -1;
	Cliente auxiliarCliente;
	Cliente* pAuxiliarCliente;
	if(array != NULL && limite > 0 && indice < limite && idCliente != NULL)
	{
		respuesta = 0;
		strncpy(auxiliarCliente.nombre,nombre,NOMBRE_LEN);
		strncpy(auxiliarCliente.apellido,apellido,APELLIDO_LEN);
		strncpy(auxiliarCliente.cuit,cuit,CUIT_LEN);
		auxiliarCliente.idCliente = *idCliente;
		pAuxiliarCliente = cli_reservarMemoriaDinamicaParaNuevoCliente();
		if(pAuxiliarCliente != NULL)
		{
			respuesta = 1;
			*pAuxiliarCliente = auxiliarCliente;
			array[indice] = pAuxiliarCliente;
			(*idCliente)++;
		}
	}
	return respuesta;
}
/**
 * \brief Busca y verifica si existe o no un ID en el array de punteros
 *
 * \param array Puntero a espacio de memoria donde comienza el array de Clientes* a ser analizado
 * \param limite Tamaño del array de clientes
 * \param valorBuscado valor del ID de cliente a ser buscado
 * \return Return Retorna el indice donde se encuentra el valor buscado, -1 si no encuentra el valor buscado
 *
 */
int cli_buscarIdClienteArrayPunteros(Cliente* array[], int limite, int valorBuscado)
{
    int retorno = -1;
    int i;
    if(array!= NULL && limite >= 0)
    {
        for(i=0; i<limite; i++)
        {
            if( array[i] != 0 &&
            	array[i]->idCliente == valorBuscado)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Actualiza los datos de un cliente en una posicion del array de punteros a clientes
 *
 * \param array Puntero al espacio de memoria donde comienza el array de punteros a ser actualizado
 * \param limite Tamaño del array de clientes
 * \param indice Posición a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarClienteArrayPunteros(Cliente* array[], int limite, int indice)
{
	int respuesta = -1;
	Cliente auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = -2;
		if(	!utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "Modifique nombre: \n", "\nNOMBRE NO VALIDO. ",2) &&
			!utn_getApellido(auxiliar.apellido,APELLIDO_LEN,"Modifique apellido: \n","\nAPELLIDO NO VALIDO. ",2) &&
			!utn_getCuit(auxiliar.cuit, CUIT_LEN, "Modifique CUIT: \n", "\nCUIT NO VALIDO. ",2) &&
			cli_buscarCuitArrayPunteros(array,limite,auxiliar.cuit) == -1 )	//Se verifica que el cuit de cliente modificado no exista
		{
			respuesta = 0;
			auxiliar.idCliente = array[indice]->idCliente;
			*array[indice] = auxiliar;
		}
	}
	return respuesta;
}
/**
 * \brief Busca en el array de punteros a los clientes e imprime sus datos en pantalla
 * \param array Puntero al espacio de memoria donde comienza el array de punteros del tipo cliente* a ser actualizado
 * \param limite Tamaño del array a ser actualizado
 * \return Retorna -1 si no hay clientes a imprimir o ERROR, 0 si pudo imprimir al menos un cliente
 *
 */
int cli_imprimirClientesArrayPunteros(Cliente* array[],int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			if(array[i] != 0)
			{
				if(!cli_imprimirCliente(array[i]))
				{
					respuesta = 0;
				}
			}
		}
	}
	return respuesta;
}
/**
 * \brief Imprime los datos de un puntero a cliente
 * \param pElemento Puntero al elemento del array que se busca imprimir
 * \return Retorna -1 si hubo ERROR, 0 si pudo imprimir cliente
 *
 */
int cli_imprimirCliente(Cliente* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL)
	{
		retorno = 0;
		printf("ID: %d - Nombre: %s - Apellido: %s - CUIT: %s\n",pElemento->idCliente,
																 pElemento->nombre,
																 pElemento->apellido,
																 pElemento->cuit);
	}
	return retorno;
}










/**
 * \brief Da de baja a un cliente en una posicion del array
 * \param array Puntero a espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tamaño del array de clientes
 * \param indice Posición a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_DarBajaClienteArrayPunteros(Cliente* array[],int limite,int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		free(array[indice]);
		array[indice] = NULL;
	}
	return respuesta;
}

