/*
Alan David Jiménez Rodríguez
27 enero 2024
El programa pensara un número del 1 al 100 , se requiere que el usuario adivine el número, empleando el menor número de intentos 
*/

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//procedimientos // Funciones
int creanum(int minimo, int maximo){
	int numero;
	numero = (rand() / (RAND_MAX + 1.0) *  (maximo - minimo + 1) );
	return numero + minimo;
}

//inicio del programa
int main(){
	
	//Declaracion de variables
	int ipiensa;
	int irespuesta;
	int iintentos;
	
	//Generacion de semilla
	srand(time(0));
	
	//Datos de entrada
	
	//Proceso
		//Generar un  numero del 1 al 100
	ipiensa = creanum (1,100);
	  //printf("ipiensa %i \n", ipiensa);
	printf("Yo he pensado en un numero del 1 al 100\n");
	printf("Intenta adivinarlo \n");
	printf("En que numero pense? ");
	
	scanf("%i", &irespuesta);
	iintentos = 1;
	
	while(irespuesta != ipiensa && irespuesta != 0 ){
		
		system("cls");
		if (irespuesta < ipiensa){
			printf("Tu numero es menor\n");
		}//Fin if
		else{
			printf("Tu numero es mayor\n");
		}//FIn else
		
		printf("No  he pensado en ese numero.\n ¿En que numero pense? ");
		scanf("%i", &irespuesta);
		iintentos ++;
		
	}// Fin del while
	
	//Datos de salida
	if  (irespuesta == 0){
		system("cls");
		printf("Lo siento el numero que pense es %i\n", ipiensa);
	}//Fin if
	else{
		system("cls");
		printf("Felicidades tu adivinaste\n");
	}//Fin else
	
	printf("Tu numero de intentos fue %i \n", iintentos);
	
	//Fin del programa
	puts("Fin del programa V6");
	return 0;
	
}//Fin del main
