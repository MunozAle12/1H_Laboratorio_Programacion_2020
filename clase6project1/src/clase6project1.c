/*
 ============================================================================
 Name        : clase6ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	OBJETIVO:

	- Manipulación de cadenas de caracteres.
	- Inicializar cadenas de caracteres.
	- Copiar cadenas de caracteres con función strcpy() (Insegura).
	- Copiar cadenas de caracteres con función strncpy() (Segura).
	- Obtener la longitud de un string (strnlen()) (Segura).
	- Concatenar strings (strncat()) (Segura).
	- Funciones sprintf() (Insegura) y snprintf() (Segura).
	- Funciones estáticas (static).
	- Convertir una cadena de caracteres en un numero entero (función atoi()).
	- Desarrollamos la función esNumerica().
	- Desarrollamos la función myGets().
	- Leer datos de manera segura (función fgets()).
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
	char saludo[11] = "Hola"; //<-- Inicialización sin especificar el tamaño de la cadena
	//char menu[ ][3] = {"Archivo","Nuevo","Abrir"};
	int i;
	int longitudAuxiliar;

/* strcpy: Modo inseguro de copiar cadena. No hay límite de copia de la cadena origen a la cadena destino,
 * facilitando el desbordamiento de búfer.
 */
	printf("\n---COPIA EN MODO INSEGURO---\n");
	strcpy(nombre, "Juan");
	for(i = 0; i < sizeof(nombre); i++) //sizeof = Calcula tamaño en bytes del operando.
	{
		printf("\nINDEX: %d - VALUE: %c - %d", i, nombre[i], (int)nombre[i]);
	}

/* La función strncpy() Copia no más de n caracteres (caracteres posteriores al carácter '\0' no son copiados)
 * de la cadena apuntada por s2 (segundo parametro) a la cadena apuntada por s1 (primer parametro).
 * La cadena s1 debe ser lo suficientemente grande para evitar desbordamiento de búfer, copiando hasta n
 * caracteres (contando el caracter '\0') de la cadena s2 a la cadena s1.
 * El tercer argumento debe ser al menos mayor en uno que la longitud de la cadena s1, para que el caracter nulo pueda ser agregado.
 */
	printf("\n\n---COPIA EN MODO SEGURO---\n");
	strncpy(auxiliar, nombre, sizeof(auxiliar));

/* strnlen() calcula el tamaño en bytes de una cadena, sin incluir el caracter de terminación '\0'.
 * Escanea cada caracter hasta llegar al '\0' o hasta el maximo de longitud, nunca va más allá.
 * Retorna un número que representa la longitud de la cadena en bytes.
 */
	longitudAuxiliar = strnlen(auxiliar,30);
	for(i = 0; i < longitudAuxiliar; i++)
	{
		printf("\nINDEX: %d - VALUE: %c - %d", i, auxiliar[i], (int)auxiliar[i]);
	}

/* La función strncat() añade la cadena apuntada por s2 al final de la cadena apuntada por s1.
 * El carácter inicial de s2 sobrescribe el carácter '\0' al final de s1. El carácter nulo siempre es añadido al resultado.
 * La cadena destino debe ser lo suficientemente grande para contener el contenido de la misma, más la cadena origen, más el caracter '\0'.
 * El tercer parametro representa el número máximo de caracteres que se agregarán a la cadena destino.
 *
 */
	printf("\n\n---CONCATENO CADENA 'saludo' A CADENA 'amigo' (MODO SEGURO)---\n");
	strncat(saludo, " amigo", sizeof(saludo));
	printf("\n%s", saludo);

/* Esta función envía datos la cadena apuntada en el primer argumento, bajo el control de la cadena apuntada
 * por formato que especifica cómo los argumentos posteriores son convertidos. Un carácter nulo es escrito
 * al final de los caracteres escritos; no es contado como parte de la suma retornada. Si el formato termina
 * mientras quedan argumentos, los argumentos restantes son evaluados (como siempre) pero ignorados.
 * La función sprintf retorna el número de caracteres escritos al array, sin contar el carácter nulo al final.
 *
 */
	//printf("\n\n---COPIO 'nombre' Y 'apellido' EN VARIABLE 'buffer' (MODO INSEGURO)---\n");
	//sprintf(buffer, "%s %s", nombre, apellido);
	//printf("\n%s", buffer);

/* La función snprintf() formatea y almacena n cantidad de cadenas y valores en el búfer apuntado.
 * A diferencia de sprintf, la adición del segundo argumento indica el número máximo de caracteres
 * (incluido al final del carácter nulo) que se escribirán en el búfer, evitando el buffer overflow.
 */
	printf("\n\n---COPIO 'nombre' Y 'apellido' EN VARIABLE 'buffer' (MODO SEGURO)---\n");
	snprintf(buffer, sizeof(buffer), "%s %s", nombre, apellido);
	printf("\n%s", buffer);

	printf("\n______________________________\n");
	printf("\nTAMAÑO VARIABLE: Nombre mide %d ----- auxiliar mide %d",(int)sizeof(nombre), (int)sizeof(auxiliar));
	printf("\nTAMAÑO CADENA: Nombre mide %d ----- auxiliar mide %d", (int)strnlen(nombre, sizeof(nombre)), (int)strnlen(auxiliar, sizeof(auxiliar)));


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
