/*
 ============================================================================
 Name        : clase6prueba.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	setbuf(stdout, NULL);
	char saludo1[10] = "hola";
	char saludo2[10] = {'H','O','L','A','\0'};
	char saludo3[] = "hola";
//	char menu[10][3] = {"Archivo","Nuevo","Abrir"};
	char texto1[20];
	char texto2[20];
	char password[20];
	char texto3[20];
	char textoAux[20];
	char texto4[20];
	int qtyCaracteres;

	printf("%s\n", saludo1);
	printf("\n%s\n", saludo2);
	printf("\n%s\n\n", saludo3);
//	printf("\n%s\n", menu);

/**
 * \brief scanf Lee, interpreta y guarda dato.
 * \param1 Lee e interpreta, dependiendo del indicador de formato, el tipo de dato ingresado.
 * \param2 Dirección de memoria en donde comienza el array en el cual se va a guardar el dato ingresado.
 * \return
 * \IMPORTANTE: No se puede ingresar texto separado por espacio ya que la función
 * 				corta el ingreso al detectar un espacio en blanco.
 */
	printf("Ingrese texto: \n");
	fflush(stdin);
	scanf("%s", texto1);
	printf("El texto es %s\n", texto1);
/**
 * \brief gets Permite leer cadena de caracteres que ingresan por teclado y guardar dicha cadena en un array.
 * \param Dirección de memoria en donde comienza el array en el cual se va a guardar el dato ingresado.
 * \return
 * \IMPORTANTE:
 */
	printf("Ingrese texto: \n");
	fflush(stdin);
	gets(texto2);
	printf("El texto es %s\n", texto2);
/**
 * \brief strcmp Función que compara cadena de caracteres.
 * \param1 Dirección de memoria donde comienza el otro array a comparar.
 * \param2 Dirección de memoria donde comienza uno de los array a comparar.
 * \return Retorna una valor entero. Sí es <0, el param1 es menor que param2.
 * 		   Sí es 0 param1 y param 2 son iguales. Sí >0 param1 es mayor que param2.
 * \IMPORTANTE: La función diferencia las mayúsculas de las minusculas. La función
 *				no brinda seguridad a los desbordes de memoria.
 */
	printf("Ingrese el password: \n");
	gets(password);

	if(strcmp(password,"1234")==0)
	{
		printf("Password correcto\n");
	}
	else
	{
		printf("Password incorrecto\n");
	}
/**
 * \brief	strcpy Función que copia una cadena de caracteres desde un array de origen a un array de destino.
 * \param1	Dirección de memoria del array donde se va a guardar la cadena de caracteres.
 * \param2	Dirección de memoria del array que contiene la cadena de caracteres a ser copiada.
 * \return
 * \IMPORTANTE:	La función no brinda seguridad a los desbordes de memoria.
 */
	printf("Ingrese una palabra: \n");
	gets(texto3);
	strcpy(textoAux,texto3);
	printf("El texto origen es: %s ---- El texto destino es: %s\n",texto3,textoAux);
/**
 * \brief	strlen Función que obtiene la cantidad de caracteres que contiene un array.
 * \param1	Dirección de memoria del array que contiene cadena de caracteres.
 * \return	Retorna la longitud de la cadena de caracteres del array.
 * \IMPORTANTE:
 */
	printf("Ingrese una palabra: \n");
	gets(texto4);
	qtyCaracteres = strlen(texto4);
	printf("La cantidad de caracteres ingresados es: %d",qtyCaracteres);
/**
 * \brief	strncpy Función que copia una cadena de caracteres desde un array de origen a un array de destino.
 * \param1	Dirección de memoria del array donde se va a guardar la cadena de caracteres.
 * \param2	Dirección de memoria del array que contiene la cadena de caracteres a ser copiada.
 * \param3	Le indico el sizeof del array de destino. Esto le pone un límite a la copia para evitar desbordamineto de memoria.
 * \return
 * \IMPORTANTE:	Es la versión segura de la función strcpy. Evita los desbordes de memoria.
 */

/**
 * \brief	strlen Función que obtiene la cantidad de caracteres que contiene un array.
 * \param1	Dirección de memoria del array que contiene cadena de caracteres.
 * \param3	Le indico el sizeof del array que contiene cadena de caracteres.
 * 			Esto le pone un límite a la búsqueda del '\0'.
 * \return
 * \IMPORTANTE:	Es la versión segura de la función strlen. Evita los desbordes de memoria.
 */
	strnlen();

/**
 * \brief	strncat Función que concatena o anexa el final del texto de un array al comienzo de otro array de caracteres.
 * \param1	Dirección de memoria del array a ser concatenado.
 * \param2	Dirección de memoria del array que se quiere concatenar al final del texto de param1.
 * \param3	Le indico el sizeof del array de param1 para evitar el desborde de memoria.
 * \return
 * \IMPORTANTE:	Es la versión segura de la función strlen. Evita los desbordes de memoria.
 */
	strncat();

/**
 * \brief	snprintf guarda un mensaje en un string.
 * \param1	Direccion de memoria del array donde voy a guardar el mensaje.
 * \param2	Le indico el sizeof del array de param1 para evitar el desborde de memoria.
 * \param3	Mensaje que quiero guardar en el string indicado en el param1.
 * \return
 * \IMPORTANTE:
 */
	snprintf();
	//sprintf

	return EXIT_SUCCESS;
}
