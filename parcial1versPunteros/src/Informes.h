/*
 * Informes.h
 *
 *  Created on: 7 may. 2020
 *      Author: Usuario
 */
#ifndef INFORMES_H_
#define INFORMES_H_

int info_informarClientesConAvisosActivos(Cliente* arrayClientes[],int limiteClientes,Publicacion* arrayPublicaciones[],int limitePublicaciones);
int info_informarAvisosConCuit(Publicacion* arrayPublicaciones[],int limitePublicaciones,Cliente* arrayClientes[],int limiteClientes);
int info_informarClienteConAvisosMax(Publicacion* arrayPublicaciones[],int limitePublicaciones,Cliente* arrayClientes[],int limiteClientes);
int info_informarClientesConAvisosActivosMax(Publicacion* arrayPublicaciones[],int limitePublicaciones,Cliente* arrayClientes[],int limiteClientes);
int info_informarClientesConAvisosPausadosMax(Publicacion* arrayPublicaciones[],int limitePublicaciones,Cliente* arrayClientes[],int limiteClientes);
int info_informarAvisosActivosDeRubro(Publicacion* array[],int limite,int rubroBuscado);
int info_informarRubroConMasAvisosActivos(Publicacion* array[],int limite);
int info_informarRubroConMenosAvisosActivos(Publicacion* array[],int limite);

/*FUNCIONES VERSION ANTERIOR*/
int info_imprimirClienteConCantidadAvisos(Cliente* pElemento,int* totalActivos);
int info_imprimirAvisoConCuit(Publicacion* pElementoAviso,Cliente* pElementoCliente);

#endif /* INFORMES_H_ */
