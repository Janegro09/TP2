#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "arrayEmployee.h"

/** \brief	Para indicar que todas las posiciones del array estàn vacias,
 * 			esta funcion pone la bandera (isEmpty) en TRUE en todas las posiciones del array
 * 	\param 	list Employee* Pointer to array of employees
 * 	\param 	len int Array length
 * 	\return	int Return (-1) if Error [Invalid length or NULL pointer] - 0 if ok
 */
int initEmployees(Employee* list, int len)
{
	for (int i=0;i<len;i++)
	{
		list[i].isEmpty=1;
	}
	return 0;
}

/**\brief	Agrega en un array de empleados existente los valores recibidos como
 * 			parametros en la primer posiciòn libre
 *\param 	list employee*
 *\param 	len int
 *\param 	id int
 *\param 	name[] char
 *\param 	lastName[] char
 *\param 	salary float
 *\param 	sector int
 *\return 	int Return (-1) si la longitud es invalida o si el puntero es Null sin espacios libres - 0 si està OK
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno=-1;
	Employee aux;
	aux.id=id;
	aux.isEmpty=0;
	strncpy(aux.name,name,50);
	strncpy(aux.lastName,lastName,50);
	aux.salary=salary;
	aux.sector=sector;

	for (int i=0;i<len;i++)
	{
		if(list[i].isEmpty!=0)
		{
			retorno=0;
			list[i]=aux;
			break;
		}
	}
	return retorno;
}

/** \brief	busca un empleado recibiendo como parametro de busqueda su id
 * \param	list Employee*
 * \param	len int
 * \param	id int
 * \return 	retorna la posiciòn del indice del empleado o (-1) si fue un puntero NULL
 * 			o si la longitud fue invalida o si el empleado nose encontrò
 */
int findEmployeeById(Employee* list, int len, int id)
{
	return -1;
}

/** \brief	Elimina de manera logica (isEmpty Flag en 1) un empleado recibiendo como parametro su Id
 * \param	list Employee*
 * \param	len int
 * \param 	id int
 * \return 	int Return (-1) id Error
 */
int removeEmployee(Employee* list, int len, int id)
{
	return -1;
}

/**	\brief 	Ordena el array de empleados por apellido y sector de manera ascendente o descendente
 * \param 	list Employee
 * \param	len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int sortEmployees(Employee* list, int len, int order)
{
	return 0;
}

/** \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int
 */
int printEmployees(Employee* list, int lenght)
{
	printf("%-6s%-30s%-30s%-10s%-3s\n","id","nombre","apellido","salario","sector");
	if(list[0].isEmpty==0)
	{
		for(int i=0;i<lenght;i++)
		{
			if(list[i].isEmpty==0)
			{
				printf("%-6d%-30s%-30s%-10.2f%-3d\n",list[i].id, list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	} else {
		printf("No se han ingresado empleados\n");
	}
	return 0;
}
