#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "arrayEmployee.h"
#include "utn.h"
#include "tp2_utn.h"

/*static int obtenerIndice(Employee array[], int* indice);*/
static int existeId(Employee array[], int indice, int* posicion);

int alta(Employee array[], int size_array)
{
	int posicion;
	int resultadoGet;
	//int indice;
	int retorno=-1;
	Employee bufferEmpleado;

	resultadoGet=utn_getEntero("Ingrese un id\n", "error al ingresar el id\n", 3, 1000,1, &bufferEmpleado.id);
	//valido id
	if(resultadoGet==0 && existeId(array, bufferEmpleado.id,&posicion)!=0)
	{
	//Valido nombre y apellido
		if(
			utn_getCadenaValida("Ingresá un nombre\n", "No ingresaste un nombre válido\n", 3,sizeof(bufferEmpleado.name), bufferEmpleado.name)==0 &&
			utn_getCadenaValida("Ingresá un apellido\n", "No ingresaste un apellido válido\n", 3,sizeof(bufferEmpleado.lastName), bufferEmpleado.lastName)==0
		){
	//valido salario
			resultadoGet=utn_getFloat("Ingresá el salario\n", "Salario incorrecto\n", 3, MAX_SALARIO, MIN_SALARIO, &bufferEmpleado.salary);
			if(resultadoGet==0)
			{
				resultadoGet=utn_getEntero("Ingresá el sector\n", "Error con el dato ingresado\n", 3, MAX_ID, MIN_ID, &bufferEmpleado.sector);
				if(resultadoGet==0)
				{
					retorno=addEmployee(array, size_array, bufferEmpleado.id, bufferEmpleado.name, bufferEmpleado.lastName, bufferEmpleado.salary, bufferEmpleado.sector);
				} else {
					printf("Error con el sector ingresado\n");
				}
			} else {
				printf("Error con el salario ingresado\n");
			}
		} else {
			printf("Error con el Nombre y/o Apellido ingresado\n");
		}
	} else {
		printf("Error con el ID ingresado o ya existente\n");
	}
return retorno;
}


int existeId(Employee array[], int id, int* posicion)
{
	int retorno=-1;
	for(int i=0;array[i].isEmpty ==0;i++)
	{
		if(array[i].id==id)
		{
			retorno=0;
			*posicion=i;
			break;
		}
	}
	return retorno;
}
/* int obtenerIndice(Employee array[], int* indice)
{
	printf("Hola");
	*indice=0;
	return 0;
}*/
int modificar(Employee array[])
{
	int retorno;
	int posicion;
	int opcion;
	int idEmpleado;
	int resultadoGet;
	Employee bufferEmpleado;

	resultadoGet=utn_getEntero("Ingresá un Id valido\n", "Error id ingresado incorrrectamente\n", 3, ID_MAXIMO, ID_MINIMO, &idEmpleado);
	if(resultadoGet==0 && existeId(array,idEmpleado,&posicion)==0)
	{
		bufferEmpleado=array[posicion];
		do
		{
			resultadoGet=utn_getEntero("Elegiste la opcion de modificar,elegí una opción a modificar\n1) Nombre\n2) Apellido\n3) Salario\n4) Sector\n5) Cancelar\n", "Opcion incorrecta", 3, 5, 1, &opcion);
			if(resultadoGet==0)
			{
				switch (opcion)
				{
				case 1:
					resultadoGet=utn_getCadenaValida("Ingrese el nuevo nombre\n", "Error con el nombre ingresado\n", 3, SIZE_NAME, bufferEmpleado.name);
					break;
				case 2:
					resultadoGet=utn_getCadenaValida("Ingrese el nuevo apellido\n", "Error con el apellido ingresado\n", 3, SIZE_LASTNAME, bufferEmpleado.lastName);
					break;
				case 3:
					resultadoGet=utn_getFloat("Ingrese el nuevo salario\n", "Error con el salario ingresado\n", 3, MAX_SALARIO, MIN_SALARIO, &bufferEmpleado.salary);
					break;
				case 4:
					resultadoGet=utn_getEntero("Ingrese el nuevo sector\n", "Error con el salario ingresado\n", 3, MAX_SALARIO, MIN_SALARIO, &bufferEmpleado.sector);
					break;
				default:
					break;
				}

				if(resultadoGet==0)
				{
					retorno=0;
					array[posicion]=bufferEmpleado;
				}else{
					printf("No se pudo realizar la modificacion\n");
					resultadoGet=0;
				}
			}
		}while (opcion!=5 && resultadoGet!=0);
	} else {
		printf("Empleado no encontrado con ese Id\n");
	}
	return retorno;
}

void baja()
{
	printf("Elegiste la opcion de baja\n");
}
void informar(Employee array[])
{
	printf("Nombre y Apellido: %s %s\n",array[0].name, array[0].lastName);
	printf("Elegiste la opcion de informar\n");
}
