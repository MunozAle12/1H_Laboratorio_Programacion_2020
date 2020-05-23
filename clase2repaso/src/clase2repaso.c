/*
 ============================================================================
 Name        : clase2repaso.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);
	int variableEntero=13;
	float variableFlotante=1.22;
	char variableCaracter='S';
	char varCaracterString[50]="TEST"; //variable que guarda cadena de caracteres

	printf("El entero es: %d \nEl float es %f \nEl char es %c \nEl texto es: %s\n\n",variableEntero,variableFlotante,variableCaracter,varCaracterString);	//funcion que imprime un archivo
	//fflush(stdin);	//limpia el archivo de entrada, se pone antes de scanf (WIN)
	//__fpurge(stdin); limpia el archivo de entrada, se pone antes de scanf (LINUX)
	//scanf("%c",&variableCaracter);	//Función que lee e imprime dato

	if(variableEntero==11)
	{
		printf("El entero es 11\n");
	}
	else if(variableEntero==12)
	{
		printf("El entero es 12\n");
	}
	else
	{
		printf("El entero no es 11 ni 12\n");
	}
/*	if((a>=14) || (b==8)) //puedo combinar logica en if
	{
		//sentencia
	}
	if((a>=14) && (b==8))
	{
		//sentencia
	}
*/
/*	int i;

	for(i=0;i<10;i++)
	{
		printf("%d\n",i);
	}
*/
/*	char respuesta;

	while(respuesta == 's' || == 'S')
	{
		//Sentencia
	}
*/
/*	char respuesta;

	do
	{

	}while(respuesta == 's' || respuesta == 'S');
*/
/*	int variableEntero;

	switch(variableEntero)
	{
	case 1:
		printf("Numero 1");
		break;
	case 2:
		printf("Numero 2");
		break;
	case 3:
	case 4:
		printf("Numero 3 y 4");
		break;
	}
	*/
	return EXIT_SUCCESS;
}
