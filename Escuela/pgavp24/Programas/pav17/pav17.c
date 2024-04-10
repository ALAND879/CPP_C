/*****************
Alan david Jimenez Rodríguez
17 de febrero
Asignacion dinamica
la memoria dinamica puede ser asignada por la funcion malloc(), una variable dinámica es anónima en el sentido de que no tiene nombre por lo tannto solo se puede hacer referencia a ella a traves de un apuntador.
El espacio que ocupa una variable dinamica puede ser devuelto al sistema por el llamado de la funicon free()
**********/

//librerias
#include <stdio.h>
#include <malloc.h>

//inicio del programa
int main(){
	
	//Declaracion de variables
	int ix;
	int *pIX;
	int iSize;
	
	printf("%i, ix: %i \n", &ix, ix );
	//*pIX = 50;
	printf("%i, pIX, \n", &pIX);
	
	//Asignacion de memoria
	iSize = sizeof(int);
	pIX = (int*) malloc(iSize);
	*pIX = 50;
	printf("%i, pIX apunta a %i, contiene %i \n", &pIX, pIX, *pIX);
	
	
	int *pIY;
	pIY = (int*) malloc(sizeof(int));
	*pIY = 70;
	
	printf("%i -- %i pIX %i\n", &pIX, pIX, *pIX);
	printf("%i -- %i pIX %i\n", &pIY, pIY, *pIY);
	
	pIX = pIY;
	
	printf("%i -- %i pIX %i\n", &pIX, pIX, *pIX);
	printf("%i -- %i pIX %i\n", &pIY, pIY, *pIY);
	
	//Liberar memoria de pIY
	printf("liberar memoria de pIY\n");
		free(pIY);
	
	printf("%i -- %i pIX %i\n", &pIX, pIX, *pIX);
	printf("%i -- %i pIX %i\n", &pIY, pIY, *pIY);
	
	
	//Fin del programa
	puts("Fin del programa V9");
	return 0;
	
}//Fin del main
