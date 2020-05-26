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
}typedef Publicacion;

Publicacion* pub_reservarMemoriaDinamicaParaNuevoAviso(void);
int pub_initArrayPunteros(Publicacion* array[],int limite);

int pub_getEmptyIndexArrayPunteros(Publicacion* array[],int limite); //LATE
int pub_DarAltaAvisoArrayPunteros(Publicacion* array[],int limite,int indice,int* idPublicacion,int idCliente); //LATE
int pub_imprimirAvisosArrayPunteros(Publicacion* array[],int limite); //LATE
int pub_buscarIdAvisoArrayAvisos(Publicacion* array[], int limite, int valorBuscado); //LATE
int pub_cambiarEstadoDeAviso(Publicacion* pElemento); //LATE
int pub_calcularAvisosDeCliente(Publicacion* array[],int limite,int valorBuscado); //LATE
int pub_calcularAvisosActivosDeCliente(Publicacion* array[], int limite, int valorBuscado); //LATE
int pub_calcularAvisosPausadosDeCliente(Publicacion* array[], int limite, int valorBuscado); //LATE
int pub_imprimirAvisosDeCliente(Publicacion* array[],int limite,int valorBuscado); //LATE
int pub_listarRubrosPorEstado(Publicacion* pArray[],int limite,int pListaRubros[],int estadoBuscado); //LATE
int pub_calcularAvisosDeRubroPorEstado(Publicacion* array[],int limite,int valorBuscado,int estadoBuscado); //LATE
int pub_buscarRubro(Publicacion* array[], int limite, int valorBuscado); //LATE
int pub_imprimirAvisosDeRubro(Publicacion* array[],int limite,int valorBuscado); //LATE
int pub_imprimirPublicacion(Publicacion* pElemento); //LATE

int pub_DarAltaAvisoArrayPunterosDebug(Publicacion* array[],int limite,int indice,int* idPublicacion,int rubro,char* txtAviso,int idCliente,int estado); //LATE

#endif /* PUBLICACION_H_ */
