/*
 ============================================================================
 Name        : clase2ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 - Pedir numeros hasta que el usuario quiera (888)
 - Imprimir el resultado de maximo y minimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout, NULL);
	int bufferInt; //Lo utilizo para guardar el número que ingresa el usuario.
	int maximo;
	int minimo;
	int flag = TRUE;	/* <-- Utilizo flag (bandera) para intercalarla en el codigo
	 	 	 	 	 	 *     y condicionar que una parte del mismo se ejecute una sola vez.
						 */

	do
	{
		printf("INGRESE NUMERO (\"888\" FINALIZA EL INGRESO): ");
		scanf("%d",&bufferInt);
		if(flag==TRUE)
		{
			minimo=bufferInt;	//Tomo el primer número ingresado como mínimo.
			maximo=bufferInt;	//Tomo el primer número ingresado como máximo.
			flag=FALSE;
		}
		else
		{
			if(bufferInt==888)
			{
				break;
			}
			else
			{
                if(bufferInt>maximo)
                {
                    maximo=bufferInt;
                }
                if(bufferInt<minimo)
                {
                    minimo=bufferInt;
                }
			}
		}
	}while(TRUE);	//<--Ejecuto el contenido del búcle sin límite alguno o
					//   fuerzo la salida del mismo utilizando la sentencia "break".

	printf("\nEl valor minimo es: %d y el valor maximo es: %d",minimo,maximo);
	return EXIT_SUCCESS;
}
