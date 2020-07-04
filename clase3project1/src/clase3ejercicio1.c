/*
 ============================================================================
 Name        : clase3ejercicio1.c
 Author      : Ale Muñoz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
	EJERCICIO:

	Programa que pida un número al usuario, después que pida una operación (+ - / * ) y
	luego que pida otro número. Según la operación ingresada, se llamará a una función
	que ejecute la operación ingresada y luego mostrar al usuario el resultado.
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

    num1 = solicitarNumeroEntero(); //Invocación o llamada a la función. En este caso no se le pasa ningun parámetro.
    printf("Ingrese una operación [+ - / *]: ");
    fflush(stdin); //Esta función se usa para vaciar el búfer de salida de la secuencia, en éste caso el archivo stdin.
    scanf("%c",&operacion);
    num2 = solicitarNumeroEntero(); //Invocación o llamada a la función

    switch(operacion)
    {
    	case '+':
    		resultado = calcularSuma(num1, num2); //Invocación o llamada a la función.
    		break;								  //Paso como parametros las variables num1 y num2.
    	case '-':
    		resultado = calcularResta(num1, num2); //Invocación o llamada a la función.
    		break;						 		   //En este momento las variables se llaman "parámetros actuales".
    	case '*':
    		resultado = calcularProducto(num1, num2); //Invocación o llamada a la función.
    		break;
    	case '/':
    		resultado = calcularCociente(num1, num2); //Invocación o llamada a la función
    		break;
    }
    printf("\n_________________________\n");
    printf("\nEl resultado es %d", resultado);
	return EXIT_SUCCESS;
}

/**
 * \brief Solicita un número entero y retorna el mismo.
 *
 * \param No recibe parámetros.
 * \return Retorna el número entero solicitado.
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
 * \brief Calcula la adición entre dos números enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operación.
 *
 */
int calcularSuma(int operador1, int operador2)	//En este momento las variables se llaman "parametros formales".
{
	int resultado;

	resultado = operador1 + operador2;

	return resultado;
}

/**
 * \brief Calcula la sustración entre dos números enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operación.
 *
 */
int calcularResta(int operador1, int operador2)
{
	int resultado;

	resultado = operador1 - operador2;

	return resultado;
}

/**
 * \brief Calcula el producto entre dos números enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operación.
 *
 */
int calcularProducto(int operador1, int operador2)
{
	int resultado;

	resultado = operador1 * operador2;

	return resultado;
}

/**
 * \brief Obtiene el cociente de la división entre dos números enteros y retorna su resultado.
 *
 * \param operador1 Representa el primer operador de valor entero.
 * \param operador2 Representa el segundo operador de valor entero.
 * \return Retorna el resultado de la operación.
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
