#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "arrayEmployee.h"
#include "utn.h"
#include "tp2_utn.h"

static int obtenerIndice(Employee array[], int* indice);
static int existeId(Employee array[], int indice);


void alta(Employee array[])
{
	int resultadoGet;
	int indice;
	int retorno=-1;
	Employee bufferEmpleado;

	resultadoGet=utn_getEntero("Ingrese un id\n", "error al ingresar el id\n", 3, 1000,1, &bufferEmpleado.id);
	//valido id
	if(resultadoGet==0 && existeId(array, bufferEmpleado.id)==0)
	{
	//Valido nombre y apellido
		if(
			utn_getCadenaValida("Ingresá un nombre\n", "No ingresaste un nombre válido\n", 3,sizeof(bufferEmpleado.name), bufferEmpleado.name)==0 &&
			utn_getCadenaValida("Ingresá un apellido\n", "No ingresaste un apellido válido\n", 3,sizeof(bufferEmpleado.lastName), bufferEmpleado.lastName)==0
		){
	//valido salario
			resultadoGet=utn_getFloat("Ingresá el salario\n", "Salario incorrecto\n", 3, 500000, 25000, &bufferEmpleado.salary);
			if(resultadoGet==0)
			{
				resultadoGet=utn_getEntero("Ingresá el sector\n", "Error con el dato ingresado\n", 3, 100, 0, &bufferEmpleado.sector);
				if(resultadoGet==0)
				{
					obtenerIndice(array,&indice);
					array[indice]=bufferEmpleado;
					retorno=0;
				} else {
					printf("Error con el Id");
				}
			} else {
				printf("Error al ingresar el salario\n");
			}
		} else {
			printf("Error con el Nombre y/o Apellido ingresado\n");
		}
	} else {
		printf("Error con el ID ingresado\n");
	}
return retorno;
}

int existeId(Employee array[], int id)
{
	return 0;
}
int obtenerIndice(Employee array[], int* indice)
{
	indice=0;
	return 0;
}
void modificar()
{
	printf("Elegiste la opcion de modificar\n");
}
void baja()
{
	printf("Elegiste la opcion de baja\n");
}
void informar()
{
	printf("Elegiste la opcion de informar\n");
}
