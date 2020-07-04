/*
 ============================================================================
 Name        : clase3ejercicio1.c
 Author      : Ale Mu�oz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	EJERCICIO:

	Programa que pida un n�mero al usuario, despu�s que pida una operaci�n (+ - / * ) y
	luego que pida otro n�mero. Seg�n la operaci�n ingresada, se llamar� a una funci�n
	que ejecute la operaci�n ingresada y luego mostrar al usuario el resultado.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

//Las firmas o prototipos de funciones van antes del main.

int solicitarNumeroEntero(void);
int calcularSuma(int operador1, int operador2);
int calcularResta(int operador1, int operador2);
int calcularProducto(int operador1, int operador2);
float calcularCociente(int operador1, int operador2);

int main(void)
{
	setbuf(stdout,NULL);
    int num1;
    int num2;
    int resultado;
    char operacion;

    num1 = solicitarNumeroEntero(); //Invocaci�n o llamada a la funci�n. En este caso no se le pasa ningun par�metro.
    printf("Ingrese una operaci�n [+ - / *]: ");
    fflush(stdin); //Esta funci�n se usa para vaciar el b�fer de salida de la secuencia, en �ste caso el archivo stdin.
    scanf("%c",&operacion);
    num2 = solicitarNumeroEntero(); //Invocaci�n o llamada a la funci�n

    switch(operacion)
    {
    	case '+':
    		resultado = calcularSuma(num1, num2); //Invocaci�n o llamada a la funci�n.
    		break;								  //Paso como parametros las variables num1 y num2.
    	case '-':
    		resultado = calcularResta(num1, num2); //Invocaci�n o llamada a la funci�n.
    		break;						 		   //En este momento las variables se llaman "par�metros actuales".
    	case '*':
    		resultado = calcularProducto(num1, num2); //Invocaci�n o llamada a la funci�n.
    		break;
    	case '/':
    		resultado = calcularCociente(num1, num2); //Invocaci�n o llamada a la funci�n
    		break;
    }
    printf("\n_________________________\n");
    printf("\nEl resultado es %d", resultado);
	return EXIT_SUCCESS;
}

/**
 * \brief Solicita un n�mero entero y retorna el mismo.
 *
 * \param No recibe par�metros.
 * \return Retorna el n�mero entero solicitado.
 *
 */
int solicitarNumeroEntero()
{
	int numeroIngresado;

	printf("Ingrese un numero: ");
	fflush(stdin);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}

/**
 * \brief Calcula la adici�n entre dos n�meros enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operaci�n.
 *
 */
int calcularSuma(int operador1, int operador2)	//En este momento las variables se llaman "parametros formales".
{
	int resultado;

	resultado = operador1 + operador2;

	return resultado;
}

/**
 * \brief Calcula la sustraci�n entre dos n�meros enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operaci�n.
 *
 */
int calcularResta(int operador1, int operador2)
{
	int resultado;

	resultado = operador1 - operador2;

	return resultado;
}

/**
 * \brief Calcula el producto entre dos n�meros enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operaci�n.
 *
 */
int calcularProducto(int operador1, int operador2)
{
	int resultado;

	resultado = operador1 * operador2;

	return resultado;
}

/**
 * \brief Obtiene el cociente de la divisi�n entre dos n�meros enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operaci�n.
 *
 */
float calcularCociente(int operador1, int operador2)
{
	int resultado;

	if(operador2 != 0)
	{
		resultado = (float)operador1 / operador2;
	}
	else
	{
		printf("\nERROR. NO SE PUEDE DIVIDIR POR CERO.\n");
	}

	return resultado;
}
