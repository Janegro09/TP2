#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

static int utn_calcularSuma(int operador1, int operador2, int* pResultado);
static int utn_calcularResta(int operador1, int operador2, int* pResultado);
static int utn_calcularMultiplicacion(int operador1,int operador2, int* pResultado);
static int utn_calcularDivision(int operador1, int operador2, float* pResultado);
static int utn_calcularFactorial(int operador, int* pResultado);
static int utn_validarCadena(char array[]);
static int utn_esLetra(char letra);

/**
 * \brief Solicita un entero al usuario y valida un rango max y min
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int maximo, valor maximo admitido
 * \param int minimo, valor minimo admitido
 * \return (1) Error / (0) Tomo el entero ok
 */

int utn_getEntero(char* pTexto, char* pTextoError, int reintentos, int maximo, int minimo, int* pOperador)
{

	int retorno=-1;
	int operadorBuffer;
	int resultadoScan;

	if(
		pTexto!=NULL &&
		pTextoError!=NULL &&
		minimo<maximo &&
		reintentos>=0
		)
		{
			do {
				printf("%s",pTexto);
				resultadoScan=scanf("%d",&operadorBuffer);
				__fpurge(stdin);
				if((resultadoScan==1) && operadorBuffer<=maximo && minimo<=operadorBuffer)
				{
					retorno=0;
					*pOperador=operadorBuffer;
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}

/**
 * \brief Solicita una cadena
 * \param char* cadena, es la cadena a procesar, puede tener letras, caracteres especiales, numeros.
 * \param int longitud, tamaño de la cadena
 */
int utn_getCadena (char* cadena, int longitud)
{
	__fpurge(stdin);
	fgets(cadena,longitud,stdin);

	cadena[strlen(cadena)-1]='\0';

	return 0;
}

/**
 * \brief Recibe un char
 * \param char letra, letra a verificar
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_esLetra(char letra)
{
	int retorno=-1;
	if(('a'<=letra && letra<='z')||('A'<=letra && letra<='Z'))
	{
		retorno=0;
	}
	return retorno;
}
/**
 * \brief Recibe una cadena de caracteres y confirma que no tenga numeros
 * \param array de char, a verificar
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_validarCadena(char array[])
{
	int retorno=0;
	int variable;
	int i;
	if(array!=NULL)
	{
		for (i=0;i<strlen(array)-1;i++)
		{
			if(utn_esLetra(array[i])!=0)
			{
				retorno=-1;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una cadena de caracteres al usuario y valida
 * \param char* pTexto, es el mensaje a ser mostrado al usuario
 * \param char* pTextoError, es el mensaje de error a ser mostrado al usuario
 * \param reintentos, cantidad de oportunidades para ingresar el dato
 * \param int maximo, tamaño maximo permitido para la cadena
 * \param int minimo, tamaño minimo permitido para la cadena
 * \param int cadena, puntero al espacio de memoria donde se dejarà la cadena obtenida
 * \return (-1) Error / (0) Tomo el entero ok
 */
int utn_getCadenaValida(char* pTexto, char* pTextoError, int reintentos, int sizeOperador, char* cadena)
{
	int retorno=-1;
	char operadorBuffer[sizeOperador];
	if(
		cadena!=NULL &&
		pTexto!=NULL &&
		pTextoError!=NULL &&
		sizeOperador>1 &&
		reintentos>0
		)
		{
			do {
				printf("%s",pTexto);
				fgets(operadorBuffer,sizeOperador,stdin);
				__fpurge(stdin);
				if(utn_validarCadena(operadorBuffer)==0)
				{
					retorno=0;
					strncpy(cadena,operadorBuffer,sizeOperador);
					break;
				} else {
					reintentos--;
					printf("%s",pTextoError);
				}

			}while(0<=reintentos);
		}
	return retorno;
}

/**
 * \brief Toma dos enteros, realiza la suma y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador, el segundo numero
 * \param int* pResultado, es el resultado de la suma
 * \return 0 siempre, no hay condiciones para sumar 2 numeros
 */
int utn_calcularSuma(int operador1, int operador2, int* pResultado){
	int suma;
	suma = operador1+operador2;
	*pResultado=suma;
	return 0;
}

/**
 * \brief Toma dos enteros, realiza la resta y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \param int* pResultado, es el resultado de la resta
 * \return 0 siempre, no hay condiciones para restar 2 numeros
 */
int utn_calcularResta(int operador1, int operador2, int* pResultado){
	int resta;
	resta = operador1-operador2;
	*pResultado=resta;
	return 0;
}

/**
 * \brief Toma dos enteros, realiza la Division y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \param int* pResultado, es el resultado de la division
 * \return o si se puede hacer la divison -1 si no se pudo
 */
int utn_calcularDivision(int operador1, int operador2, float* pResultado){
	float division;
	int retorno=-1;
	if(operador2 != 0)
	{
		division=(float)operador1/operador2;
		retorno=0;
	}
	*pResultado=division;
	return retorno;
}

/**
 * \brief Toma dos enteros, realiza la multiplicacion y lo imprime en pantalla
 * \param int operador1, el primer numero
 * \param int operador2, el segundo numero
 * \param int* pResultado, es el resultado de la multiplicacion
 * \return 0 siempre, no hay condiciones para la multiplicacion
 */
int utn_calcularMultiplicacion(int operador1, int operador2, int* pResultado){
	int multiplicacion;
	multiplicacion=operador1*operador2;
	*pResultado=multiplicacion;

	return 0;
}

/**
 * \brief Toma un entero, realiza el factorial de un numero
 * \param int operador, el primer numero
 * \param int* pResultado, donde se guarda el resultado del factorial
 * \return 0 si realizò el factorial y -1 si no se pudo hacer
 */
int utn_calcularFactorial(int operador, int* pResultado){
	int retorno=-1;
	int factorial=1;

	if(operador>=0)
	{
		for(int i=0;i<operador;i++)
		{
			factorial=factorial*(i+1);
		}
		retorno=0;
	} else {
		printf("No se puede realizar el factorial de un numero negativo\n");
	}
	*pResultado=factorial;

	return retorno;
}
