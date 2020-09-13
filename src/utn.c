struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} typedef Employee;

/** \brief	Para indicar que todas las posiciones del array estàn vacias,
 * 			esta funcion pone la bandera (isEmpty) en TRUE en todas las posiciones del array
 * 	\param 	list Employee* Pointer to array of employees
 * 	\param 	len int Array length
 * 	\return	int Return (-1) if Error [Invalid length or NULL pointer] - 0 if ok
 */
int initEmployees(Employee* list, int len)
{
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
	return -1;
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
	return 0;
}
