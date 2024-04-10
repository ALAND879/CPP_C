/*

Alan David Jimenez Rodríguez
pav10.c
3 de febrero de 2024

*/

//Librerias
#include <stdio.h>

//inicio del programa
int main(){
	
	//Declaracion de variables
	int lista[]= {20, 30, 35, 36, 39};
	int ii;
	
	//proceso
	printf("El contenido del arreglo es: \n");
	for (ii = 0; ii<5; ii++){
		printf("Valor numero: %2i -- El valor es: %3i \n", ii+1, lista[ii]);
	}	
	
	printf("\n\nEl contenido del arreglo usando el concepto de apuntador:\n");
	for(ii = 0; ii <5; ii++){
		printf("Valor numero: %2i -- El valor es: %3i \n", ii+1, *(lista + ii) );
	}
	
	printf("\nvalor lista[2] : %i\n", *(lista + 2) );
	
	printf("\nvalor lista[0] : %i\n", *(lista) );
	
	/*
	operaciones no validas con el apuntador de un arreglo
	Liesta = NULL
	Lista = &variable
	Lista++
	Lista--
	*/
	
	printf("\n");
	//Fin del programa
	puts("Fin del programa V5");
	return 0;
	
}//Fin del main
