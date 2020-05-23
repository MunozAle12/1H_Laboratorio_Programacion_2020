/*
 ============================================================================
 Name        : clase3ejercicio1.c
 Author      : Ale Mu�oz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO:
 Programa que pida un numero al usuario, despu�s que pida una operaci�n (+ - / * ) y
 luego que pida otro numero. Seg�n la operaci�n ingresada, se llamar� a una funci�n
 que ejecute la operaci�n ingresada y luego mostrar al usuario el resultado.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/*	Las firmas o prototipos de funciones van antes del main.
 *
 */
int bufferInt(void);
int suma(int operador1,int operador2);
int resta(int operador1,int operador2);
int producto(int operador1,int operador2);
float division(int operador1,int operador2);

int main(void)
{
	setbuf(stdout,NULL);
    int num1;
    int num2;
    int resultado;
    char operacion;

    num1=bufferInt(); //Invocaci�n o llamada a la funci�n. En este caso no se le pasa ningun par�metro
    printf("Ingrese una operacion [+ - / *]: \n");
    fflush(stdin);
    scanf("%c",&operacion);
    num2=bufferInt(); //Invocaci�n o llamada a la funci�n

    switch(operacion)
    {
    	case '+':
    		resultado=suma(num1, num2); //Invocaci�n o llamada a la funci�n.
    		break;						//Le paso como parametros las variables num1 y num2.

    	case '-':
    		resultado=resta(num1, num2); //Invocaci�n o llamada a la funci�n.
    		break;						 //En este momento las variables se llaman "parametros actuales".

    	case '*':
    		resultado=producto(num1, num2); //Invocaci�n o llamada a la funci�n.
    		break;

    	case '/':
    		resultado=division(num1, num2); //Invocaci�n o llamada a la funci�n
    		break;
    }
    printf("El resultado es %d",resultado);
	return EXIT_SUCCESS;
}

int bufferInt()
{
	int numeroIngresado;

	printf("ingrese un numero: \n");
	fflush(stdin);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}

int suma(int operador1,int operador2)	//En este momento las variables se llaman "parametros formales".
{
	int resultado;

	resultado=operador1+operador2;

	return resultado;
}

int resta(int operador1,int operador2)
{
	int resultado;

	resultado=operador1-operador2;

	return resultado;
}

int producto(int operador1,int operador2)
{
	int resultado;

	resultado=operador1*operador2;

	return resultado;
}

float division(int operador1,int operador2)
{
	int resultado;

	if(operador2!=0)
	{
		resultado=(float)operador1/operador2;
	}
	else
	{
		printf("NO SE PUEDE DIVIDIR POR CERO.\n");
	}

	return resultado;
}
