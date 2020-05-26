/*
 * cliente.h
 *
 *  Created on: 28 abr. 2020
 *      Author: Usuario
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_LEN 64
#define APELLIDO_LEN 64
#define CUIT_LEN 32

struct cliente
{
	char nombre[NOMBRE_LEN];
	char apellido[APELLIDO_LEN];
	char cuit[CUIT_LEN];
	int idCliente;
}typedef Cliente;

Cliente* cli_reservarMemoriaDinamicaParaNuevoCliente(void);
int cli_initArrayPunteros(Cliente* array[],int limite);
int cli_getEmptyIndexArrayPunteros(Cliente* array[],int limite);
int cli_DarAltaClienteArrayPunteros(Cliente* array[],int limite,int indiceLibre,int* idCliente);
int cli_buscarIdClienteArrayPunteros(Cliente* array[],int limite,int valorBuscado);
int cli_modificarClienteArrayPunteros(Cliente* array[],int limite,int indice);

int cli_buscarCuitArrayPunteros(Cliente* array[],int limite,char* valorBuscado); //LATE
int cli_DarBajaClienteArrayPunteros(Cliente* array[],int limite,int indice); //LATE
int cli_imprimirClientesArrayPunteros(Cliente* array[],int limite); //LATE
int cli_imprimirCliente(Cliente* pElemento); //LATE

int cli_altaArrayPunterosClientesDebug(Cliente* array[],int limite,int indice,int* idCliente,char* nombre,char* apellido,char* cuit); //LATE

#endif /* CLIENTE_H_ */
