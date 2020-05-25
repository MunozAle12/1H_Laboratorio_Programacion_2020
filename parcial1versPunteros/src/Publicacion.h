/*
 * cliente.h
 *
 *  Created on: 28 abr. 2020
 *      Author: Usuario
 */
#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define ESTADO_PAUSA 0
#define ESTADO_ACTIVO 1
#define TXT_AVISO_LEN 65

struct publicacion
{
	int rubro;
	char txtAviso[TXT_AVISO_LEN];
	int idCliente;
	int idPublicacion;
	int estado;
	int isEmpty;
}typedef Publicacion;

/*FUNCIONES VERSION PUNTEROS*/
Publicacion* pub_reservarMemoriaDinamicaParaNuevoAviso(void);
int pub_initArrayPunteros(Publicacion* array[],int limite);
int pub_getEmptyIndexArrayPunteros(Publicacion* array[],int limite);
int pub_DarAltaAvisoArrayPunteros(Publicacion* array[],int limite,int indice,int* idPublicacion,int idCliente);
int pub_DarAltaAvisoArrayPunterosDebug(Publicacion* array[],int limite,int indice,int* idPublicacion,int rubro,char* txtAviso,int idCliente,int estado);
int pub_imprimirAvisosArrayPunteros(Publicacion* array[],int limite);
int pub_buscarIdAvisoArrayAvisos(Publicacion* array[], int limite, int valorBuscado);

/*FUNCIONES VERSION ANTERIOR*/
int pub_imprimirPublicacion(Publicacion* pElemento);
int pub_imprimirAvisosDeCliente(Publicacion* array,int limite,int valorBuscado);
int pub_imprimirAvisosPorRubro(Publicacion* array,int limite,int valorBuscado);
int pub_inicializarArray(Publicacion* array,int limite);
int pub_getEmptyIndex(Publicacion* array,int limite);
int pub_DarAltaAviso(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente);
int pub_DarBajaAvisos(Publicacion* array,int limite,int valorBuscado);
int pub_cambiarEstadoDeAviso(Publicacion* pElemento);
int pub_buscarIdAviso(Publicacion array[], int limite, int valorBuscado);
int pub_calcularAvisosDeCliente(Publicacion* array, int limite, int valorBuscado);
int pub_calcularAvisosActivosDeCliente(Publicacion array[], int limite, int valorBuscado);
int pub_calcularAvisosPausadosDeCliente(Publicacion* array, int limite, int valorBuscado);
int pub_calcularAvisosActivosDeRubro(Publicacion* array,int limite,int valorBuscado);
int pub_buscarRubro(Publicacion array[], int limite, int valorBuscado);

int pub_altaArrayDebug(Publicacion* array,int limite,int indice,int* idPublicacion,int rubro,char* txtAviso,int idCliente,int estado);

#endif /* PUBLICACION_H_ */
