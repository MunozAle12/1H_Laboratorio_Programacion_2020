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
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al elemento del array que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimir(Cliente* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL)
	{
		retorno = 0;
		printf("ID: %d - Nombre: %s - Apellido: %s - CUIT: %s\n",pElemento->idCliente, pElemento->nombre,pElemento->apellido,pElemento->cuit);
	}
	return retorno;
}
/**
 * \brief Imprime el array de clientes
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
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
				respuesta = 0;
				printf("ID: %d - Nombre: %s - Apellido: %s - CUIT: %s\n",array[i]->idCliente,array[i]->nombre,array[i]->apellido,array[i]->cuit);
			}
		}
	}
	return respuesta;
}
/**
 * \brief Inicializa el array de clientes
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
/*
int cli_inicializarArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0; i<limite; i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}
*/
/**
 * \brief Busca la primer posicion disponible del array
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \return Retorna el indice de la posicion vacia, -1 (ERROR)
 *
 */
/*
int cli_getEmptyIndex(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
*/
/**
 * \brief Da de alta un cliente en una posicion del array
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
/*
int cli_DarAltaCliente(Cliente* array,int limite,int indice,int* idCliente)
{
	int respuesta = -1;
	Cliente auxiliar;
	if(array != NULL && limite > 0 && indice < limite && idCliente != NULL)
	{
		if(	!utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "Ingrese nombre: \n", "\nNOMBRE NO VALIDO. ",2) &&
			!utn_getApellido(auxiliar.apellido,APELLIDO_LEN,"Ingrese apellido: \n","\nAPELLIDO NO VALIDO. ",2) &&
			!utn_getCuit(auxiliar.cuit, CUIT_LEN, "Ingrese CUIT: \n", "\nCUIT NO VALIDO. ",2) &&
			cli_buscarCuit(array,limite,auxiliar.cuit) == -1) //Se verifica que el cliente no exista
		{
			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
			array[indice].idCliente = *idCliente;
			*idCliente = *idCliente + 1;
		}
	}
	return respuesta;
}
*/
/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array de clientes
 * \param indice Posici�n a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
/*
int cli_modificarCliente(Cliente* array,int limite,int indice)
{
	int respuesta = -1;
	Cliente auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	!utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "Modifique nombre: \n", "\nNOMBRE NO VALIDO. ",2) &&
			!utn_getApellido(auxiliar.apellido,APELLIDO_LEN,"Modifique apellido: \n","\nAPELLIDO NO VALIDO. ",2) &&
			!utn_getCuit(auxiliar.cuit, CUIT_LEN, "Modifique CUIT: \n", "\nCUIT NO VALIDO. ",2) &&
			cli_buscarCuit(array,limite,auxiliar.cuit) == -1)	//Se verifica que el cliente no exista
		{
			respuesta = 0;
			auxiliar.idCliente = array[indice].idCliente;
			auxiliar.isEmpty = 0;
			array[indice] = auxiliar;
		}
	}
	return respuesta;
}
*/
/**
 * \brief Busca y verifica si existe o no un ID en un array
 * \param array Array de clientes a ser analizado
 * \param limite Tama�o del array de clientes
 * \param valorBuscado valor del ID a ser buscado
 * \return Return Retorna el indice donde se encuentra el valor buscado, (-1) si no encuentra el valor buscado
 *
 */
int cli_buscarIdCliente(Cliente array[],int limite,int valorBuscado)
{
    int retorno = -1;
    int i;
    if(array!= NULL && limite >= 0)
    {
        for(i=0; i<limite; i++)
        {
            if( array[i].isEmpty == 0 &&
            	array[i].idCliente == valorBuscado)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Busca y verifica si existe o no un CUIT en un array
 * \param array Puntero al espacio de memoria donde comienza el array a ser analizado
 * \param limite Tama�o del array de clientes
 * \param valorBuscado valor del CUIT a ser buscado
 * \return Return Retorna el indice donde se encuentra el valor buscado, (-1) si no encuentra el valor buscado
 *
 */
/*
int cli_buscarCuit(Cliente* array,int limite,char* valorBuscado)
{
    int retorno = -1;
    int i;
    if(array!= NULL && limite >= 0)
    {
        for(i=0; i<limite; i++)
        {
            if( array[i].isEmpty == 0 &&
            	strncmp(array[i].cuit,valorBuscado,CUIT_LEN) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
*/
/**
 * \brief Da de baja a un cliente en una posicion del array
 * \param array Puntero a espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array de clientes
 * \param indice Posici�n a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_bajaCliente(Cliente* array,int limite,int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice].isEmpty = 1;
	}
	return respuesta;
}
/**
 * \brief Da de alta un cliente en una posicion del array modo DEBUG
 * \param array Puntero a espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array de clientes
 * \param indice Posicion a ser actualizada
 * \param idCliente Puntero a espacio de memoria donde se encuentra el ID a ser asignado
 * \param nombre Puntero a espacio de memoria donde se encuentra el ID a ser asignado
 * \param apellido Puntero a espacio de memoria donde se encuentra el apellido a ser asignado
 * \param cuit Puntero a espacio de memoria donde se encuentra el cuit a ser asignado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArrayDebug(Cliente* array,int limite,int indice,int* idCliente,char* nombre,char* apellido,char* cuit)
{
	int respuesta = -1;
	if(array!=NULL && limite>0 && indice<limite && nombre!=NULL && apellido!=NULL && cuit!=NULL)
	{
		respuesta = 0;
		strncpy(array[indice].nombre,nombre,NOMBRE_LEN);
		strncpy(array[indice].apellido,apellido,APELLIDO_LEN);
		strncpy(array[indice].cuit,cuit,CUIT_LEN);
		array[indice].idCliente = *idCliente;
		array[indice].isEmpty = 0;
		(*idCliente)++;
	}
	return respuesta;
}

/*****FUNCIONES VERSION PUNTEROS*****/
/**
 * \brief Busca y reserva un espacio en memoria de manera din�mica para guardar los datos de un nuevo cliente
 * \param void No recibe paramatros
 * \return Retorna la direcci�n de memoria donde comieza el puntero, NULL si no se encontr� espacio en memoria
 *
 */
Cliente* cli_reservarMemoriaDinamicaParaNuevoCliente(void)
{
	Cliente* pClienteNuevo;
	pClienteNuevo = (Cliente*)malloc(sizeof(Cliente));
	if(pClienteNuevo != NULL)
	{
		pClienteNuevo->nombre[0] = '\0';
		pClienteNuevo->apellido[0] = '\0';
		pClienteNuevo->cuit[0] = '\0';
		pClienteNuevo->idCliente = 0;
		pClienteNuevo->isEmpty = 0;
	}
	return pClienteNuevo;
}
/**
 * \brief Inicializa el puntero a array del tipo cliente*
 * \param array Puntero al espacio de memoria donde comienza el array del tipo clientes* a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_initArrayPunteros(Cliente* array[],int limite)
//int cli_initArrayPunteros(Cliente** array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0; i<limite; i++)
		{
			array[i] = NULL;
		}
	}
	return respuesta;
}
/**
 * \brief Busca la primer posicion disponible del puntero a array del tipo cliente*
 * \param array Puntero al espacio de memoria donde comienza el array del tipo cliente* a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \return Retorna el indice de la posicion vacia, -1 (ERROR)
 *
 */
int cli_getEmptyIndexArrayPunteros(Cliente* array[],int limite)
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
 * \brief Da de alta un cliente en una posicion del array
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 1 si se realiz� el alta de un cliente, 0 y -1 (ERROR)
 *
 */
int cli_DarAltaClienteArrayPunteros(Cliente* array[],int limite,int indiceLibre,int* idCliente)
{
	int respuesta = -2;
	Cliente auxiliarCliente;
	Cliente* pAuxiliarCliente;
	if(array != NULL && limite > 0 && indiceLibre < limite && idCliente != NULL)
	{
		respuesta = -1;
		if(	!utn_getNombre(auxiliarCliente.nombre, NOMBRE_LEN, "Ingrese nombre: \n", "\nNOMBRE NO VALIDO. ",2) &&
			!utn_getApellido(auxiliarCliente.apellido,APELLIDO_LEN,"Ingrese apellido: \n","\nAPELLIDO NO VALIDO. ",2) &&
			!utn_getCuit(auxiliarCliente.cuit, CUIT_LEN, "Ingrese CUIT: \n", "\nCUIT NO VALIDO. ",2) )
			//cli_buscarCuit(array,limite,auxiliar.cuit) == -1 ) //Se verifica que el cliente no exista
		{
			respuesta = 0;
			auxiliarCliente.idCliente = *idCliente;
			pAuxiliarCliente = cli_reservarMemoriaDinamicaParaNuevoCliente();
			if(pAuxiliarCliente != NULL)
			{
				respuesta = 1;
				*pAuxiliarCliente = auxiliarCliente;
				array[indiceLibre] = pAuxiliarCliente;
				(*idCliente)++;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Busca y verifica si existe o no un CUIT en un array
 * \param array Puntero al espacio de memoria donde comienza el array a ser analizado
 * \param limite Tama�o del array de clientes
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
 * \brief Busca y verifica si existe o no un ID en un array
 * \param array Array de clientes a ser analizado
 * \param limite Tama�o del array de clientes
 * \param valorBuscado valor del ID a ser buscado
 * \return Return Retorna el indice donde se encuentra el valor buscado, (-1) si no encuentra el valor buscado
 *
 */
int cli_buscarIdClienteArrayPunteros(Cliente* array[],int limite,int valorBuscado)
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
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array de clientes
 * \param indice Posici�n a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarClienteArrayPunteros(Cliente* array[],int limite,int indice)
{
	int respuesta = -1;
	Cliente auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
		if(	!utn_getNombre(auxiliar.nombre, NOMBRE_LEN, "Modifique nombre: \n", "\nNOMBRE NO VALIDO. ",2) &&
			!utn_getApellido(auxiliar.apellido,APELLIDO_LEN,"Modifique apellido: \n","\nAPELLIDO NO VALIDO. ",2) &&
			!utn_getCuit(auxiliar.cuit, CUIT_LEN, "Modifique CUIT: \n", "\nCUIT NO VALIDO. ",2) )
			//cli_buscarCuit(array,limite,auxiliar.cuit) == -1)	//Se verifica que el cliente no exista
		{
			respuesta = 0;
			auxiliar.idCliente = array[indice]->idCliente;
			*array[indice] = auxiliar;
		}
	}
	return respuesta;
}
/**
 * \brief Da de baja a un cliente en una posicion del array
 * \param array Puntero a espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array de clientes
 * \param indice Posici�n a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_DarBajaClienteArrayPunteros(Cliente* array[],int limite,int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice] = NULL;
	}
	return respuesta;
}
/**
 * \brief Da de alta un cliente en una posicion del array modo DEBUG
 * \param array Puntero a espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array de clientes
 * \param indice Posicion a ser actualizada
 * \param idCliente Puntero a espacio de memoria donde se encuentra el ID a ser asignado
 * \param nombre Puntero a espacio de memoria donde se encuentra el ID a ser asignado
 * \param apellido Puntero a espacio de memoria donde se encuentra el apellido a ser asignado
 * \param cuit Puntero a espacio de memoria donde se encuentra el cuit a ser asignado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
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
		auxiliarCliente.isEmpty = 0;
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
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al elemento del array que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirCliente(Cliente* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL)
	{
		retorno = 0;
		printf("ID: %d - Nombre: %s - Apellido: %s - CUIT: %s\n",pElemento->idCliente, pElemento->nombre,pElemento->apellido,pElemento->cuit);
	}
	return retorno;
}
