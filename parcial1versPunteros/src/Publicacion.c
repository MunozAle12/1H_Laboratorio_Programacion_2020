/*
 * contrataciones.c
 *
 *  Created on: 28 abr. 2020
 *      Author: Usuario
 */

#include "Publicacion.h"
#include "utn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char ESTADOS_TIPOS[2][8] = {"PAUSADA","ACTIVA"};

/**
 * \brief Busca y reserva un espacio en memoria de manera din�mica para guardar los datos de un nuevo aviso
 * \param void No recibe paramatros
 * \return Retorna la direcci�n de memoria donde comieza el puntero, NULL si no se encontr� espacio en memoria
 *
 */
Publicacion* pub_reservarMemoriaDinamicaParaNuevoAviso(void)
{
	Publicacion* pAvisoNuevo;
	pAvisoNuevo = (Publicacion*)malloc(sizeof(Publicacion));
	if(pAvisoNuevo != NULL)
	{
		pAvisoNuevo->rubro = 0;
		pAvisoNuevo->txtAviso[0] = '\0';
		pAvisoNuevo->idPublicacion = 0;
		pAvisoNuevo->estado = 0;
		pAvisoNuevo->idCliente = 0;
	}
	return pAvisoNuevo;
}

/**
 * \brief Inicializa el puntero a array del tipo publicacion*
 * \param array Puntero a espacio de memoria donde comienza el array del tipo publicacion* a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \return Retorna 0 si se inicializ� con �XITO el array y -1 si ERROR
 *
 */
int pub_initArrayPunteros(Publicacion* array[],int limite)
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
 * \brief Busca e imprime publicaciones de un cliente en array de punteros del tipo Publicacion*
 * \param array Puntero a espacio de memoria donde comienza el array de punteros a ser actualizado
 * \param limite Tama�o del array de publicaciones
 * \param valorBuscado Valor del ID de cliente a ser buscado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirAvisosDeCliente(Publicacion* array[],int limite,int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->idCliente == valorBuscado)
			{
				respuesta = 0;
				pub_imprimirPublicacion(array[i]);
			}
		}
	}
	return respuesta;
}
/**
 * \brief Imprime los datos de una publicacion
 * \param pElemento Puntero al espacio de memoria donde comienza la publicacion que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirPublicacion(Publicacion* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL)
	{
		retorno = 0;
		printf("\nID Publicacion: %d - Rubro: %d - Aviso: %s - Estado: %s - IdCliente: %d\n", pElemento->idPublicacion,
																							pElemento->rubro,
																							pElemento->txtAviso,
																							ESTADOS_TIPOS[pElemento->estado],
																							pElemento->idCliente);
	}
	return retorno;
}
/**
 * \brief Da de baja la/s posicion/es del array de punteros donde se encuentra un ID de cliente buscado
 * \param array Puntero a espacio de memoria donde empieza el array a ser actualizado
 * \param limite Tama�o del array de publicaciones
 * \param valorBuscado Valor del ID de cliente a ser buscado
 * \return Retorna -1 si hubo ERROR, 0 si el cliente no tiene avisos, 1 si se pudo dar de baja avisos de cliente.
 *
 */
int pub_DarBajaAvisosArrayPunteros(Publicacion* array[],int limite,int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		respuesta = 0;
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->idCliente == valorBuscado )
			{
				respuesta = 1;
				array[i] = NULL;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Busca primer posicion disponible del array de punteros del tipo publicacion*
 * \param array Puntero a espacio de memoria donde comienza el array de punteros
 * \param limite Tama�o del array a ser analizado
 * \return Retorna el indice de la posicion disponible, -1 si hubo ERROR
 *
 */
int pub_getEmptyIndexArrayPunteros(Publicacion* array[],int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0; i<limite; i++)
		{
			if(array[i] == 0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Da de alta una publicaci�n en una posicion del array de punteros del tipo publicacion*
 * \param array Puntero al espacio de memoria donde comienza el array de punteros a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \param indice Posici�n del array a ser actualizada
 * \param idPublicacion Identificador a ser asignado a la publicaci�n
 * \param idCliente Identificador del cliente correspondiente a ser asignado a la publicaci�n
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_DarAltaAvisoArrayPunteros(Publicacion* array[],int limite,int indice,int* idPublicacion,int idCliente)
{
	int respuesta = -2;
	Publicacion auxiliarAviso;
	Publicacion* pAuxiliarAviso;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		respuesta = -1;
		if(	!utn_getNumero(&auxiliarAviso.rubro,"Ingrese n�mero de rubro: \n","\nINGRESO NO V�LIDO. ",0,1000,2) &&
			!utn_getTexto(auxiliarAviso.txtAviso,TXT_AVISO_LEN,"Ingrese aviso (64 caracteres): \n", "\nINGRESO NO V�LIDO. ",2) )
		{
			respuesta = 0;
			auxiliarAviso.idCliente = idCliente;
			auxiliarAviso.idPublicacion = *idPublicacion;
			auxiliarAviso.estado = ESTADO_ACTIVO;
			pAuxiliarAviso = pub_reservarMemoriaDinamicaParaNuevoAviso();
			if(pAuxiliarAviso != NULL)
			{
				respuesta = 1;
				*pAuxiliarAviso = auxiliarAviso;
				array[indice] = pAuxiliarAviso;
				(*idPublicacion)++;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Da de alta una publicacion en una posicion del array de punteros del tipo Publicacion* en modo DEBUG
 * \param array Puntero a espacio de memoria donde comienza el array de punteros a ser actualizado
 * \param limite Tama�o del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \param idPublicacion Puntero a espacio de memoria donde se encuentra el ID de pubicacion a ser asignado
 * \param rubro Rubro a ser asignado
 * \param txtAviso Puntero a espacio de memoria donde se encuentra el texto de aviso a ser asignado
 * \param idCliente Id de cliente a ser asignado
 * \param estado Estado a ser asignado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_DarAltaAvisoArrayPunterosDebug(Publicacion* array[],int limite,int indice,int* idPublicacion,int rubro,char* txtAviso,int idCliente,int estado)
{
	int respuesta = -1;
	Publicacion auxiliarAviso;
	Publicacion* pAuxiliarAviso;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		respuesta = 0;
		auxiliarAviso.rubro = rubro;
		strncpy(auxiliarAviso.txtAviso,txtAviso,TXT_AVISO_LEN);
		auxiliarAviso.idPublicacion = *idPublicacion;
		auxiliarAviso.estado = estado;
		auxiliarAviso.idCliente = idCliente;
		pAuxiliarAviso = pub_reservarMemoriaDinamicaParaNuevoAviso();
		if(pAuxiliarAviso != NULL)
		{
			respuesta = 1;
			*pAuxiliarAviso = auxiliarAviso;
			array[indice] = pAuxiliarAviso;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}
/**
 * \brief Busca un ID de publicacion en array de punteros y devuelve la posicion en la que se encuentra
 * \param array Puntero a espacio de memoria donde comienza el array de punteros del tipo Publicacion*
 * \param limite Tama�o del array a ser analizado
 * \param valorBuscado Valor del ID de publicacion a ser buscado
 * \return Retorna el indice donde se encuentra el valor buscado, -1 si no lo encuentra o ERROR
 *
 */
int pub_buscarIdAvisoArrayAvisos(Publicacion* array[],int limite,int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->idPublicacion == valorBuscado )
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Cambia el estado de una publicacion del array
 * \param pElemento Puntero al elemento a ser actualizado
 * \return Retorna -1 (ERROR), 0 si la publicacion ya estaba pausada, 1 si cambio el estado a pausado.
 *
 */
int pub_cambiarEstadoDeAviso(Publicacion* pElemento)
{
	int respuesta = -1;
	if(pElemento != NULL)
	{
		switch(pElemento->estado)
		{
			case ESTADO_ACTIVO:
				pElemento->estado = ESTADO_PAUSA;
				respuesta = 1;
				break;
			case ESTADO_PAUSA:
				pElemento->estado = ESTADO_ACTIVO;
				respuesta = 1;
				break;
		}
	}
	return respuesta;
}
/**
 * \brief Busca y calcula la cantidad total de avisos de un cliente
 * \param array Array de publicaciones
 * \param limite Tama�o del array
 * \param valorBuscado Valor del ID de cliente a ser buscado
 * \return Retorna -1 si no encuentra el valor buscado. Si encuentra el valor buscado, retorna la cantidad de avisos.
 *
 */
int pub_calcularAvisosDeCliente(Publicacion* array[],int limite,int valorBuscado)
{
	int respuesta = -1;
	int i;
	int publicacionesTotal = 0;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->idCliente == valorBuscado )
			{
				publicacionesTotal++;
			}
		}
		respuesta = publicacionesTotal;
	}
	return respuesta;
}
/**
 * \brief Busca un rubro de publicacion en un array y devuelve la posicion en que se encuentra
 * \param array Array de publicacion
 * \param limite Tama�o del array
 * \param valorBuscado Valor del rubro a ser buscado
 * \return Retorna (-1) si no encuentra el valor buscado o Error. Si encuentra el valor buscado, retorna el indice donde se encuentra
 *
 */
int pub_buscarRubro(Publicacion* array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado > 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->rubro == valorBuscado )
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/**
 * \brief Busca y calcula la cantidad de avisos ACTIVOS de un cliente
 * \param array Puntero al espacio de memoria donde comienza el array de punteros del tipo Publicaciones*
 * \param limite Tama�o del array a analizar
 * \param valorBuscado Valor del ID de cliente a ser buscado
 * \return Retorna la cantidad de avisos ACTIVOS de cliente, -1 si no encuentra avisos de cliente o ERROR
 *
 */
int pub_calcularAvisosDeClientePorEstado(Publicacion* array[],int limite,int valorBuscado,int estadoBuscado)
{
	int respuesta = -1;
	int i;
	int publicacionesActivas = 0;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->idCliente == valorBuscado &&
				array[i]->estado == estadoBuscado )
			{
				publicacionesActivas++;
			}
		}
		respuesta = publicacionesActivas;
	}
	return respuesta;
}
/**
 * \brief Busca e imprime publicaciones de un rubro
 * \param array Puntero a espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array de publicaciones
 * \param valorBuscado Valor del rubro a ser buscado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirAvisosDeRubro(Publicacion* array[],int limite,int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->rubro == valorBuscado)
			{
				respuesta = 0;
				pub_imprimirPublicacion(array[i]);
			}
		}
	}
	return respuesta;
}
/**
 *
 *
 */
int pub_listarRubrosPorEstado(Publicacion* pArray[],int limite,int pListaRubros[],int estadoBuscado)
{
	int respuesta = -1;
	int i;
	int j;
	int indiceLibre = 0;
	int flagExisteRubro;
	if(pArray != NULL && limite > 0 && pListaRubros != NULL)
	{
		for(i=0; i<limite; i++)
		{
			flagExisteRubro = 0;
			if( pArray[i] != 0 &&
				pArray[i]->estado == estadoBuscado)
			{
				for(j=0; j<=indiceLibre; j++)
				{
					if(pArray[i]->rubro == pListaRubros[j])
					{
						flagExisteRubro = 1;
						break;
					}
				}
				if(flagExisteRubro == 0)
				{
					respuesta = 0;
					pListaRubros[indiceLibre] = pArray[i]->rubro;
					indiceLibre++;
				}
			}
		}
	}
	return respuesta;
}
/**
 * \brief Busca y calcula la cantidad total de avisos ACTIVOS de un rubro
 * \param array Array de publicaciones
 * \param limite Tama�o del array
 * \param valorBuscado Valor del rubro a ser buscado
 * \return Retorna -1 si no encuentra el valor buscado. Si encuentra el valor buscado, retorna la cantidad de avisos ACTIVOS.
 *
 */
int pub_calcularAvisosDeRubroPorEstado(Publicacion* array[],int limite,int valorBuscado,int estadoBuscado)
{
	int respuesta = -1;
	int i;
	int cantidadAvisos = 0;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->rubro == valorBuscado &&
				array[i]->estado == estadoBuscado )
			{
				cantidadAvisos++;
			}
		}
		respuesta = cantidadAvisos;
	}
	return respuesta;
}









/**
 * \brief Imprime el array de publicaciones
 * \param array Puntero al espacio de memoria donde comienza el array a ser actualizado
 * \param limite Tama�o del array a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
/*
int pub_imprimirAvisosArrayPunteros(Publicacion* array[],int limite)
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
				printf("Rubro: %d - Aviso: %s - ID Publicaci�n: %d - Estado: %s - ID Cliente: %d\n",array[i]->rubro,array[i]->txtAviso,array[i]->idPublicacion,ESTADOS_TIPOS[array[i]->estado],array[i]->idCliente);
			}
		}
	}
	return respuesta;
}
*/
/**
 * \brief Busca y calcula la cantidad total de avisos PAUSADOS de un cliente
 * \param array Array de publicaciones
 * \param limite Tama�o del array
 * \param valorBuscado Valor del ID de cliente a ser buscado
 * \return Retorna -1 si no encuentra el valor buscado. Si encuentra el valor buscado, retorna la cantidad de avisos PAUSADOS.
 *
 */
/*
int pub_calcularAvisosPausadosDeCliente(Publicacion* array[],int limite,int valorBuscado)
{
	int respuesta = -1;
	int i;
	int publicacionesPausadas = 0;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0; i<limite; i++)
		{
			if( array[i] != 0 &&
				array[i]->idCliente == valorBuscado &&
				array[i]->estado == ESTADO_PAUSA )
			{
				publicacionesPausadas++;
			}
		}
		respuesta = publicacionesPausadas;
	}
	return respuesta;
}
*/
