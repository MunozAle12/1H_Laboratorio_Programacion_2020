#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Función que calcula la operación dividir entre dos enteros y retorna el cociente por referencia.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la operación.
 * \param operador1 Es el dividendo de la operación dividir.
 * \param operador2 Es el divisor de la operación dividir.
 * \return Retorna 0 si se encontró un resultado, -1 si no.
 *
 */
int calcularCociente(float* pResultado, int operador1, int operador2)
{
	int retorno = -1;
	float resultado;
	if(pResultado != NULL && operador2 != 0) //Valido los parámetros recibidos
											 //pResultado != NULL (lo utilizo SIEMPRE para validar la dirección de memoria de un puntero)
	{
		retorno = 0;
		resultado = (float)operador1 / operador2; //*pResultado = (float)operador1 / operador2;
		*pResultado = resultado;
	}
	return retorno;
}

