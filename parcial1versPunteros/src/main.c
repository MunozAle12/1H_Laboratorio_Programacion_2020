/*
 ============================================================================
 Name        : parcial1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Desarrollar en ANSI C:
 Una empresa requiere un sistema que le permita gestionar publicidad en sitios web,
 dicha publicidad podra ser visualizada en páginas web de terceros en forma de
 banners.

 Menú de la aplicacion:

 1) Alta de cliente: Se da de alta un cliente con nombre, apellido y cuit. Se generará
    un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.
 2) Modificar datos de cliente : Se ingresa el ID de cliente y se permitirá cambiar el
    nombre,el apellido y el cuit.
 3) Baja de cliente : Se ingresa el ID del cliente y se listarán todas las publicaciones de
    dicho cliente. Luego se preguntará si se quiere confirmar la eliminación, la cual
    implicará la eliminación de todas las publicaciones y del cliente.
 4) Publicar: Permitirá crear un nuevo aviso. Primero imprime por pantalla la lista de
    clientes, luego se pedirán los siguientes datos: ID de cliente, número de rubro, texto
    del aviso (64 caracteres). Se generará automáticamente un identificador numérico
    para el aviso y se imprimirá en pantalla.
 5) Pausar publicación: Se pedirá el ID de la publicación y se imprimirá la información
    del cliente al que pertenece, luego se pedirá confirmación para cambiarse de estado y
    se cambiará al estado "pausada".
 6) Reanudar publicación: Se pedirá el ID de la publicación y se imprimirá la
    información del cliente al que pertenece, luego se pedirá confirmación para cambiarse
    de estado y se cambiará al estado "activa".
 7) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con
    la cantidad de avisos activos que posee.
 8) Imprimir publicaciones: Se imprimirá una lista de publicaciones con todos sus
    datos junto con el cuit del cliente correspondiente. se deberá indicar si está activa o no
    con la palabras “ACTIVA” o “PAUSADA”.
 9) Informar clientes:
    a) Cliente con más avisos activos.
    b) Cliente con más avisos pausados.
    c) Cliente con más avisos.
 10) Informar publicaciones:
     a) Cantidad de publicaciones de un rubro: Se ingresará el número de rubro y se imprimirá
        la cantidad de publicaciones activas de dicho rubro.
     b) Rubro con más publicaciones activas.
     c) Rubro con menos publicaciones activas.

 Nota 0: El sistema soportará una capacidad máxima de 100 clientes y 1000
         publicaciones
 Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones
         (Alta, Baja, Modificar, etc.). Los informes deberán estar en una biblioteca aparte.
 Nota 2: El código deberá tener comentarios con la documentación de cada una de las
         funciones y respetar las reglas de estilo de la cátedra.
 ============================================================================
*/
#include "Cliente.h"
#include "Publicacion.h"
#include "Informes.h"
#include "utn.h"

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PUBLICACIONES 1000

int main(void)
{
	setbuf(stdout,NULL);
	Cliente* arrayPunterosClientes[CANTIDAD_CLIENTES];
	Publicacion* arrayPunterosAvisos[CANTIDAD_PUBLICACIONES];
	int opcion;
	int idCliente = 0;
	int idPublicacion = 0;
	int auxIdAviso;
	int auxIdCliente;
	int auxIndiceAviso;
	int auxIndiceCliente;
	int auxRubro;
	char respuesta;
	int retorno;

	if( !cli_initArrayPunteros(arrayPunterosClientes, CANTIDAD_CLIENTES) &&
		!pub_initArrayPunteros(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES))
	{
		printf("Array de clientes inicializado con éxito\n");
		printf("Array de publicaciones inicializado con éxito\n\n");

		cli_altaArrayPunterosClientesDebug(arrayPunterosClientes, CANTIDAD_CLIENTES, 0, &idCliente, "Facundo", "Veron", "30332455218");
		cli_altaArrayPunterosClientesDebug(arrayPunterosClientes, CANTIDAD_CLIENTES, 1, &idCliente, "Juliana", "Vilchez", "27232797219");
		cli_altaArrayPunterosClientesDebug(arrayPunterosClientes, CANTIDAD_CLIENTES, 2, &idCliente, "Diego", "Silva", "23299715032");
		cli_altaArrayPunterosClientesDebug(arrayPunterosClientes, CANTIDAD_CLIENTES, 3, &idCliente, "Hernan", "Llorente", "24347239906");
		cli_altaArrayPunterosClientesDebug(arrayPunterosClientes, CANTIDAD_CLIENTES, 4, &idCliente, "Paula", "Luro", "30325551291");
		cli_altaArrayPunterosClientesDebug(arrayPunterosClientes, CANTIDAD_CLIENTES, 5, &idCliente, "Silvana", "Galvan", "20273981014");

		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 0, &idPublicacion, 120, "Ofertas en Kevingston", 3, 1);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 1, &idPublicacion, 20, "Coca-Cola destapá felicidad", 3, 1);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 2, &idPublicacion, 80, "Quedate en casa", 3, 1);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 3, &idPublicacion, 110, "2x1 en McDonals", 2, 0);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 4, &idPublicacion, 80, "Vacuna contra la gripe para grupos de riesgo", 4, 1);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 5, &idPublicacion, 72, "Superfindesemana Coto: Los miercoles, 20% de descuento", 0, 1);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 6, &idPublicacion, 10, "Contratá Movistar Fibra", 2, 0);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 7, &idPublicacion, 10, "Contratá Fibertel", 1, 0);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 8, &idPublicacion, 10, "Contratá Claro: Conocé nuestros planes de teléfonos", 2, 1);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 9, &idPublicacion, 120, "Adidas Impossible is Nothing", 4, 1);
		pub_DarAltaAvisoArrayPunterosDebug(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, 10, &idPublicacion, 120, "Liquidacion otoño invierno en Zara", 3, 1);

		do
		{
			if(!utn_getNumero(&opcion, "\nIngrese una opción:\n"
									   "1) Alta de cliente\n"
									   "2) Modificar datos del cliente\n"
									   "3) Baja de cliente\n"
									   "4) Publicar\n"
									   "5) Pausar publicación\n"
									   "6) Reanudar publicación\n"
									   "7) Imprimir clientes\n"
									   "8) Imprimir publicaciones\n"
									   "9) Informar clientes\n"
									   "10) Informar publicaciones\n"
									   "11) Salir\n\n","OPCION NO VALIDA. ", 0, 11, 2))
			{
				switch(opcion)	//La sentencia ejecuta un caso dependiendo del valor de opcion
				{
					case 1:	//Alta de cliente
						auxIndiceCliente= cli_getEmptyIndexArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES);
						if(auxIndiceCliente != -1)
						{
							retorno = cli_DarAltaClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIndiceCliente,&idCliente);
							switch(retorno)
							{
								case 0:
									printf("\n¡El alta de cliente fue un éxito!\n");
									break;
								case -1:
									printf("\n¡No hay espacio en memoria!\n");
									break;
								case -2:
									printf("\n¡El alta de cliente falló!\n");
									break;
								case -3:
									printf("\n¡ERROR!\n");
									break;
							}
						}
						else
						{
							printf("\n¡No hay lugar disponible para otro cliente!\n");
						}
						break;
					case 2:	//Modificar datos del cliente
						if(!utn_getNumero(&auxIdCliente,"Ingrese ID de cliente a modificar: \n","\nINGRESO NO VALIDO. ",0,idCliente,2)) //Se solicita y valida ID cliente
						{
							auxIndiceCliente = cli_buscarIdClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIdCliente); //Se verifica existencia de cliente en array
							if(auxIndiceCliente != -1)
							{
								retorno = cli_modificarClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIndiceCliente);
								switch(retorno)
								{
									case 1:
										printf("\n¡El alta de cliente fue un éxito!\n");
										break;
									case 0:
										printf("\n¡La modificación de datos falló!\n");
										break;
									case -1:
										printf("\n¡ERROR!\n");
										break;
								}
							}
							else
							{
								printf("\n¡El cliente no existe!\n");
							}
						}
						else
						{
							printf("\n¡Agotó sus reintentos. Ingreso incorrecto!\n");
						}
						break;
					case 3:	//Baja de cliente
						if(!utn_getNumero(&auxIdCliente, "Ingrese ID de cliente a dar de baja: \n", "\nINGRESO NO VALIDO. ", 0, idCliente, 2))	//Se solicita y valida ID cliente
						{
							auxIndiceCliente = cli_buscarIdClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIdCliente);	//Se verifica existencia de cliente en array
							if(auxIndiceCliente != -1)
							{
								pub_imprimirAvisosDeCliente(arrayPunterosAvisos, CANTIDAD_PUBLICACIONES, auxIdCliente);
								if(!utn_getLetra(&respuesta, "\n¿Quiere confirmar la eliminación del cliente y sus publicaciones? [s/n]: \n", "\nINGRESO NO VÁLIDO. ", 2))
								{
									switch(respuesta)
									{
										case 's':
											if(!cli_DarBajaClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIndiceCliente))
											{
												retorno = pub_DarBajaAvisosArrayPunteros(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,auxIdCliente);
												switch(retorno)
												{
													case 1:
														printf("\n¡La baja del cliente y sus publicaciones fue un éxito!\n");
														break;
													case 0:
														printf("\n¡La baja del cliente fue un éxito. No tenía publicaciones!\n");
														break;
													case -1:
														printf("\n¡ERROR!\n");
														break;
												}
											}
											else
											{
												printf("\n¡La baja del cliente y sus publicaciones falló!\n");
											}
											break;
										case 'n':
											printf("\n¡La baja del cliente y sus publicaciones se canceló!\n");
											break;
										default:
											printf("\n¡Respuesta incorrecta!\n");
									}
								}
								else
								{
									printf("\n¡Agotó sus reintentos. Respuesta incorrecta!\n");
								}
							}
							else
							{
								printf("\n¡El cliente no existe!\n");
							}
						}
						else
						{
							printf("\n¡Agotó sus reintentos. Ingreso incorrecto!\n");
						}
						break;
					case 4: //Publicar
						auxIndiceAviso = pub_getEmptyIndexArrayPunteros(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES);
						if(auxIndiceAviso != -1)
						{
							if(!cli_imprimirClientesArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES))
							{
								if(!utn_getNumero(&auxIdCliente,"Ingrese ID de cliente: \n","\nINGRESO NO VALIDO. ",0,idCliente,2))	//Se solicita y valida ID cliente
								{
									if(cli_buscarIdClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIdCliente) != -1)	//Se verifica existencia de cliente
									{
										retorno = pub_DarAltaAvisoArrayPunteros(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,auxIndiceAviso,&idPublicacion,auxIdCliente);
										switch(retorno)
										{
											case 1:
												printf("\n¡Se publicó el aviso con éxito!\n");
												break;
											case 0:
												printf("\n¡No hay espacio en memoria!\n");
												break;
											case -1:
												printf("\n¡La publicación del aviso falló!\n");
												break;
											case -2:
												printf("\n¡ERROR!\n");
												break;
										}
									}
									else
									{
										printf("\n¡El cliente no existe!\n");
									}
								}
								else
								{
									printf("\n¡Agotó sus reintentos. Ingreso incorrecto!\n");
								}
							}
							else
							{
								printf("\n¡No hay clientes a mostrar!\n");
							}
						}
						else
						{
							printf("\n¡No hay lugar disponible para publicar un aviso!\n");
						}
						break;
					case 5: //Pausar publicación
						if(!utn_getNumero(&auxIdAviso,"Ingrese ID de publicación: \n","\nINGRESO NO VÁLIDO. ",0,idPublicacion,2))	//Se solicita y valida ID aviso
						{
							auxIndiceAviso = pub_buscarIdAvisoArrayAvisos(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,auxIdAviso);	//Se verifica existencia y ubicacion del aviso
							if(auxIndiceAviso != -1)
							{
								auxIdCliente = arrayPunterosAvisos[auxIndiceAviso]->idCliente;	//Conociendo la ubicacion del aviso puedo saber el ID del cliente
								auxIndiceCliente = cli_buscarIdClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIdCliente); //Busco ubicacion del cliente en array
								if(auxIndiceCliente != 1)
								{
									if(cli_imprimirCliente(arrayPunterosClientes[auxIndiceCliente]) == -1) //Imprimo información del cliente
									{
										printf("\n¡ERROR!\n");
									}
									if(!utn_getLetra(&respuesta,"\n¿Desea pausar la publicación? [s/n]: \n","\nINGRESO NO VÁLIDO. ",2))
									{
										switch(respuesta)
										{
											case 's':
												if(pub_cambiarEstadoDeAviso(arrayPunterosAvisos[auxIndiceAviso]))
												{
													printf("\n¡Se pausó la publicación!\n");
												}
												else
												{
													printf("\n¡ERROR!\n");
												}
												break;
											case 'n':
												printf("\n¡Se canceló el cambio de estado de publicación!\n");
												break;
											default:
												printf("\n¡Respuesta incorrecta!\n");
										}
									}
									else
									{
										printf("\n¡Agotó sus reintentos. Respuesta incorrecta!\n");
									}
								}
								else
								{
									printf("\nID Cliente no existe!\n");
								}
							}
							else
							{
								printf("\nID publicación no existe!\n");
							}
						}
						else
						{
							printf("\n¡Agotó sus reintentos. Ingreso incorrecto!\n");
						}
						break;
					case 6:	//Reanudar publicación
						if(!utn_getNumero(&auxIdAviso,"Ingrese ID de publicación: \n","\nINGRESO NO VÁLIDO. ",0,idPublicacion,2))	//Se solicita y valida ID de aviso
						{
							auxIndiceAviso = pub_buscarIdAvisoArrayAvisos(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,auxIdAviso);	//Se verifica existencia y ubicacion del aviso
							if(auxIndiceAviso != -1)
							{
								auxIdCliente = arrayPunterosAvisos[auxIndiceAviso]->idCliente;	//Conociendo la ubicacion del aviso puedo saber el ID del cliente
								auxIndiceCliente = cli_buscarIdClienteArrayPunteros(arrayPunterosClientes,CANTIDAD_CLIENTES,auxIdCliente);	//Busco ubicacion del cliente en array
								if(auxIndiceCliente != 1)
								{
									if(cli_imprimirCliente(arrayPunterosClientes[auxIndiceCliente]) == -1)	//Imprimo información del cliente
									{
										printf("\n¡ERROR!\n");
									}
									if(!utn_getLetra(&respuesta,"\n¿Desea reanudar la publicación? [s/n]: \n","\nINGRESO NO VÁLIDO. ",2))
									{
										switch(respuesta)
										{
											case 's':
												if(pub_cambiarEstadoDeAviso(arrayPunterosAvisos[auxIndiceAviso]))
												{
													printf("\n¡Se reanudó la publicación!\n");
												}
												else
												{
													printf("\n¡ERROR!\n");
												}
												break;
											case 'n':
												printf("\n¡Se canceló el cambio de estado de publicación!\n");
												break;
											default:
												printf("\n¡Respuesta incorrecta!\n");
										}
									}
									else
									{
										printf("\n¡Agotó sus reintentos. Respuesta incorrecta!\n");
									}
								}
								else
								{
									printf("\nID Cliente no existe!\n");
								}
							}
							else
							{
								printf("\nID publicación no existe!\n");
							}
						}
						else
						{
							printf("\n¡Agotó sus reintentos. Ingreso incorrecto!\n");
						}
						break;
					case 7:	//Imprimir clientes con la cantidad de avisos activos que poseen
						if(info_informarClientesConAvisosActivos(arrayPunterosClientes,CANTIDAD_CLIENTES,arrayPunterosAvisos,CANTIDAD_PUBLICACIONES) == -1)
						{
							printf("\n¡ERROR\n");
						}
						break;
					case 8:	//Imprimir publicaciones junto con el cuit del cliente correspondiente
						if(info_informarAvisosConCuit(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,arrayPunterosClientes,CANTIDAD_CLIENTES) == -1)
						{
							printf("\n¡ERROR!\n");
						}
						break;
					case 9:	//Informar clientes: Cliente con más avisos activos.
						if(info_informarClienteConAvisosMax(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,arrayPunterosClientes,CANTIDAD_CLIENTES) == -1)
						{
							printf("\n¡ERROR!\n");
						}
						//Cliente con más avisos pausados.
						if(info_informarClientesConAvisosActivosMax(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,arrayPunterosClientes,CANTIDAD_CLIENTES) == -1)
						{
							printf("\n¡ERROR!\n");
						}
						//Cliente con más avisos.
						if(info_informarClientesConAvisosPausadosMax(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,arrayPunterosClientes,CANTIDAD_CLIENTES) == -1)
						{
							printf("\n¡ERROR!\n");
						}
						break;
					case 10: //Informar publicaciones
						if(!utn_getNumero(&auxRubro,"Ingresar número de rubro: \n","\nINGRESO NO VALIDO. ",0,1000,2))	//Solicito y valido numero de rubro
						{
							respuesta = pub_buscarRubro(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,auxRubro);
							if(respuesta != -1)
							{
								if(info_informarAvisosActivosDeRubro(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES,auxRubro) == -1)
								{
									printf("\n¡ERROR!\n");
								}
								if(info_informarRubroConMasAvisosActivos(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES) == -1)
								{
									printf("\n¡ERROR!\n");
								}
								if(info_informarRubroConMenosAvisosActivos(arrayPunterosAvisos,CANTIDAD_PUBLICACIONES) == -1)
								{
									printf("\n¡ERROR!\n");
								}
							}
							else
							{
								printf("\n¡El rubro no existe!\n");
							}
						}
						break;
				}
			}
			else
			{
				printf("ERROR. \n");
			}
		}while(opcion != 11);	//Se termina la ejecucion del programa ingresando la opcion 11
	}
	return EXIT_SUCCESS;
}
