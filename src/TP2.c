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
#include "utn.h"
#include "employee.h"

#define SIZE_CADENA 50

int main(void) {
	int resultado;
	char cadena[SIZE_CADENA];
	resultado=utn_getCadenaValida("Ingresa una cadena\n", "error cadena invalida\n", 3, SIZE_CADENA, cadena);
	//resultado= utn_getCadena(cadena, SIZE_CADENA);
	if(resultado==0)
	{
		printf("La cadena es:\n%s",cadena);
	} else {
		printf("No ingresaste una cadena valida");
	}
	return EXIT_SUCCESS;
}
