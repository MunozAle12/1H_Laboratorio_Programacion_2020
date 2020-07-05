#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Funci�n que calcula la operaci�n dividir entre dos enteros y retorna el cociente por referencia.
 *
 * \param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la operaci�n.
 * \param operador1 Es el dividendo de la operaci�n dividir.
 * \param operador2 Es el divisor de la operaci�n dividir.
 * \return Retorna 0 si se encontr� un resultado, -1 si no.
 *
 */
int calcularCociente(float* pResultado, int operador1, int operador2)
{
	int retorno = -1;
	float resultado;
	if(pResultado != NULL && operador2 != 0) //Valido los par�metros recibidos
											 //pResultado != NULL (lo utilizo SIEMPRE para validar la direcci�n de memoria de un puntero)
	{
		retorno = 0;
		resultado = (float)operador1 / operador2; //*pResultado = (float)operador1 / operador2;
		*pResultado = resultado;
	}
	return retorno;
}

