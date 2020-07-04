/*
 ============================================================================
 Name        : Clase1Programa2.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 - Declaración de variables tipo 'int', 'float', 'char'.
 - Identificación de sus modificadores de formatos.
 - Mostrar mensajes por pantalla con variables definidas en una sola linea.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) //Punto de entrada de la aplicacion
{
	// En este punto arranca la aplicacion
/*
 En JS imprimo mensajes por pantalla de diferentes maneras:
	- console.log("hola");
	- alert("hola");
	- document.write("hola");

 Maneras de declarar variables en C:
	TIPO NOMBRE;
	TIPO NOMBRE = VALOR; <--Inicialización de la variable
*/
	int j;
	j = 27;
	float pi = 3.14;
	char letra = 'A';
	int k = 33;

	printf("Precio: %d pesos\n",j);
	//si modifico %f y pongo %.2f, muestra dos decimales cuando compila
	printf("Letra: %c\n\n",letra);

	printf("Letra: %c - Precio: %f pesos - lalala: %d\n",letra,pi,k);
	//si modifico %f y pongo %.2f, muestra dos decimales cuando compila
	return EXIT_SUCCESS;
}
