/*
 ============================================================================
 Name        : clase6ejercicio1.c
 Author      : Ale Mu�oz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	OBJETIVO:

	- Manipulaci�n de cadenas de caracteres.
	- Inicializar cadenas de caracteres.
	- Copiar cadenas de caracteres con funci�n strcpy() (Insegura).
	- Copiar cadenas de caracteres con funci�n strncpy() (Segura).
	- Obtener la longitud de un string (strnlen()) (Segura).
	- Concatenar strings (strncat()) (Segura).
	- Funciones sprintf() (Insegura) y snprintf() (Segura).
	- Funciones est�ticas (static).
	- Convertir una cadena de caracteres en un numero entero (funci�n atoi()).
	- Desarrollamos la funci�n esNumerica().
	- Desarrollamos la funci�n myGets().
	- Leer datos de manera segura (funci�n fgets()).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	int auxiliarInt;
	char nombre[11] = "Pablo";
	char apellido[11] = {'P','e','r','e','z','\0'};
	char auxiliar[30] = "";
	char buffer[128] = "\0";
	char saludo[11] = "Hola"; //<-- Inicializaci�n sin especificar el tama�o de la cadena
	//char menu[ ][3] = {"Archivo","Nuevo","Abrir"};
	int i;
	int longitudAuxiliar;

/* strcpy: Modo inseguro de copiar cadena. No hay l�mite de copia de la cadena origen a la cadena destino,
 * facilitando el desbordamiento de b�fer.
 */
	printf("\n---COPIA EN MODO INSEGURO---\n");
	strcpy(nombre, "Juan");
	for(i = 0; i < sizeof(nombre); i++) //sizeof = Calcula tama�o en bytes del operando.
	{
		printf("\nINDEX: %d - VALUE: %c - %d", i, nombre[i], (int)nombre[i]);
	}

/* La funci�n strncpy() Copia no m�s de n caracteres (caracteres posteriores al car�cter '\0' no son copiados)
 * de la cadena apuntada por s2 (segundo parametro) a la cadena apuntada por s1 (primer parametro).
 * La cadena s1 debe ser lo suficientemente grande para evitar desbordamiento de b�fer, copiando hasta n
 * caracteres (contando el caracter '\0') de la cadena s2 a la cadena s1.
 * El tercer argumento debe ser al menos mayor en uno que la longitud de la cadena s1, para que el caracter nulo pueda ser agregado.
 */
	printf("\n\n---COPIA EN MODO SEGURO---\n");
	strncpy(auxiliar, nombre, sizeof(auxiliar));

/* strnlen() calcula el tama�o en bytes de una cadena, sin incluir el caracter de terminaci�n '\0'.
 * Escanea cada caracter hasta llegar al '\0' o hasta el maximo de longitud, nunca va m�s all�.
 * Retorna un n�mero que representa la longitud de la cadena en bytes.
 */
	longitudAuxiliar = strnlen(auxiliar,30);
	for(i = 0; i < longitudAuxiliar; i++)
	{
		printf("\nINDEX: %d - VALUE: %c - %d", i, auxiliar[i], (int)auxiliar[i]);
	}

/* La funci�n strncat() a�ade la cadena apuntada por s2 al final de la cadena apuntada por s1.
 * El car�cter inicial de s2 sobrescribe el car�cter '\0' al final de s1. El car�cter nulo siempre es a�adido al resultado.
 * La cadena destino debe ser lo suficientemente grande para contener el contenido de la misma, m�s la cadena origen, m�s el caracter '\0'.
 * El tercer parametro representa el n�mero m�ximo de caracteres que se agregar�n a la cadena destino.
 *
 */
	printf("\n\n---CONCATENO CADENA 'saludo' A CADENA 'amigo' (MODO SEGURO)---\n");
	strncat(saludo, " amigo", sizeof(saludo));
	printf("\n%s", saludo);

/* Esta funci�n env�a datos la cadena apuntada en el primer argumento, bajo el control de la cadena apuntada
 * por formato que especifica c�mo los argumentos posteriores son convertidos. Un car�cter nulo es escrito
 * al final de los caracteres escritos; no es contado como parte de la suma retornada. Si el formato termina
 * mientras quedan argumentos, los argumentos restantes son evaluados (como siempre) pero ignorados.
 * La funci�n sprintf retorna el n�mero de caracteres escritos al array, sin contar el car�cter nulo al final.
 *
 */
	//printf("\n\n---COPIO 'nombre' Y 'apellido' EN VARIABLE 'buffer' (MODO INSEGURO)---\n");
	//sprintf(buffer, "%s %s", nombre, apellido);
	//printf("\n%s", buffer);

/* La funci�n snprintf() formatea y almacena n cantidad de cadenas y valores en el b�fer apuntado.
 * A diferencia de sprintf, la adici�n del segundo argumento indica el n�mero m�ximo de caracteres
 * (incluido al final del car�cter nulo) que se escribir�n en el b�fer, evitando el buffer overflow.
 */
	printf("\n\n---COPIO 'nombre' Y 'apellido' EN VARIABLE 'buffer' (MODO SEGURO)---\n");
	snprintf(buffer, sizeof(buffer), "%s %s", nombre, apellido);
	printf("\n%s", buffer);

	printf("\n______________________________\n");
	printf("\nTAMA�O VARIABLE: Nombre mide %d ----- auxiliar mide %d",(int)sizeof(nombre), (int)sizeof(auxiliar));
	printf("\nTAMA�O CADENA: Nombre mide %d ----- auxiliar mide %d", (int)strnlen(nombre, sizeof(nombre)), (int)strnlen(auxiliar, sizeof(auxiliar)));


	printf("\n______________________________\n");
	while(1)
	{
		if(utn_getNumero(&auxiliarInt, "NUMERO?: ", "\nERROR. ", -2, 10, 2) == 0)
		{
			printf("\nEl numero es  %d\n", auxiliarInt);
		}
		else
			break;
	}

	return EXIT_SUCCESS;
}
