#include <stdio.h>
#include <stdlib.h>
/* brief Funci�n que calcula la operaci�n dividir entre dos enteros y retorna.
 * param pResultado Puntero a espacio de memoria donde se va a guardar el resultado de la operaci�n.
 * param operador1 Es el dividendo de la operaci�n dividir.
 * param operador2 Es el divisor de la operaci�n dividir.
 * return Retorna 0 si se encontr� un resultado, -1 si no.
 */
int dividir(float* pResultado,int operador1,int operador2)
{
	float resultado;
	int retorno=-1;

	if(pResultado!=NULL && operador2!=0) //pResultado!=NULL (lo utilizo SIEMPRE para validar la direcci�n de memoria de un puntero)
	{
		resultado=(float)operador1/operador2;
		*pResultado=resultado;
		retorno=0;
	}
	return retorno;
}
