/**********
Nombre: Alan David
Fecha: 20 enero 2024
Genera números aleatorios
El siguiente codigo genera e imprime 50 números aleatorios del 1 al 6
*****/

//librerias:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Procedimiento/ Funciones
//-------------------------
int aleatorio(int imenor, int imayor){
	int idato;
	idato= rand() / ( RAND_MAX + 1.0 ) * ( imayor - imenor +  1 );
	return imenor + idato;
}

//inicio del programa
int main()
{
	//Declaracion de variables
	int itotal = 50;
	int itirada  = 1;
	
	//Semilla a partir de que número genera "rand()"
	//Se genera la misma secuencia
	//srand(1000);
	
	srand(time(0));
	
	//Datos de entrada
	//Proceso
	
	//Datos de salida
	printf("RAND_MAX: %d \n", RAND_MAX);
	 	for ( itirada ; itirada <= itotal ; itirada++ ){
			printf("Tirada %2i del dado: %d \n", itirada, aleatorio (1,6));
		 }//Fin de la iteración

	//Fin del programa
	puts("Fin del programa V10");
	return 0;
	
}//Fin del main
