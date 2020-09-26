/*
 ============================================================================
 Name        : TP2.c
 Author      : Javier Sosa
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "arrayEmployee.h"
#include "utn.h"
#include "tp2_utn.h"

#define SIZE_ARRAY 1000
#define BARRA_SEPARADORA "*********************************************"

int main(void) {
	Employee arrayEmpleados[SIZE_ARRAY];
	Employee arrayEmpleadosAux;
	int opcion;
	int resultadoGetEntero;
	int resultadoOperacion;
	do {
		resultadoGetEntero=utn_getEntero("Bienvenido, ingresá una opción\n1) Alta\n2) Modificacion\n3) Baja\n4) Informar\n5) Salir\n", "Error - opción invalida\n", 3, 5, 1, &opcion);
		switch(opcion)
		{
			case 1:
				printf(BARRA_SEPARADORA);
				resultadoOperacion=alta(arrayEmpleados);
				if(resultadoOperacion==0)
				{
					printf("Alta realizada Correctamente\n");
				} else {
					printf("No se pudo realizar el Alta\n");
				}
				break;
			case 2:
				printf(BARRA_SEPARADORA);
				modificar();
				break;
			case 3:
				printf(BARRA_SEPARADORA);
				baja();
				break;
			case 4:
				printf(BARRA_SEPARADORA);
				informar();
				break;
		}
	}while (opcion != 5 && resultadoGetEntero ==0);

	return EXIT_SUCCESS;
}
