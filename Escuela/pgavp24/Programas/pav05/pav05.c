/**
Nombre: Alan David Jiménez Rodríguez
27 enero
**/

//Librerias
#include <stdio.h>

//inicio del programa
int main(){
	
//Declaración de variable
	int valor1;
	float factor;
	char inicial;
	
//Proceso
	
	// Tamaño de variables
	printf("Int size: %i \n\n", sizeof(int));
	printf("Float size: %i \n\n", sizeof(float));
	printf("Char size: %i \n\n", sizeof(char));
	
	printf("\n-----------------------------------------------------------------------------------------------\n\n");
	
	// Direccion de los tipos de datos
	printf("Direccion de valor 1: %i \n\n", &valor1);
	printf("Direccion de factor: %i \n\n", &factor);
	printf("Direccion de inicial: %i \n\n", &inicial);
	
	printf("\n-----------------------------------------------------------------------------------------------\n\n");
	
	// valor1 inicial e inicializado
	printf("valor1 contiene: %i \n", valor1 );
	valor1 = 25;
	printf("Valor1 contiene: %i \n\n", valor1 );
	
	// factor inicial e inicializado
	printf("factor contiene: %f \n", factor);
	factor = 134.6775;
	printf("factor contiene: %f \n\n", factor);
	
	// inicial inicial e inicializado
	printf("inicial contiene: %c \n", inicial);
	inicial = 'A';
	printf("inicial contiene: %c identico %i\n\n", inicial, inicial);
	
	
	printf("\n-----------------------------------------------------------------------------------------------\n\n");
	
	//Mostrar la direccion y contenido de la direccion 
	printf("La direccion del valor1 es: %i y el contenido de esta direccion es: %i \n\n", &valor1, *(&valor1) );
	printf("La direccion del factor es: %i y el contenido de esta direccion es: %f \n\n", &factor, *(&factor) );
	printf("La direccion de inicial es: %i y el contenido de esta direccion es: %c \n\n", &inicial, *(&inicial) );
		
	printf("\n-----------------------------------------------------------------------------------------------\n\n");
	
	// Variables apuntador
	
	int *ptr1;  //variable apuntador a un entero
		ptr1 = &valor1; //asignarle valor - inicializar
		printf("El contenido del valor1 es: %i , la direccion de valor1 es: %i y la direccion de ptr1 es: %i \n\n", *ptr1, ptr1, &ptr1);
		
	float *ptr2; //variable apuntador a un real
		ptr2 = &factor; //asignarle valor - inicializar
		printf("El contenido del factor es: %f , la direccion de factor es: %i y la direccion de ptr2 es: %i \n\n", *ptr2, ptr2, &ptr2);
	
	char *ptr3; //variable apuntador a un char
		ptr3 = &inicial; //asignarle valor - inicializar
		printf("El contenido de incial es: %c , la direccion de la inicial es: %i y la direccion de ptr3 es: %i \n\n", *ptr3, ptr3, &ptr3);
	
	printf("\n-----------------------------------------------------------------------------------------------\n\n");
	
	// Ejercicio
	
	int izz = 99;
	int *pia;
	int **ppib;
	int ***pppic;
	
	pia = &izz;
	ppib = &pia;
	pppic = &ppib;
	
	printf("%i, Valor de izz es: %i \n", &izz, izz);
	
	printf("%i, El valor de *pia es: %d \n",&pia, *pia);
	
	printf("%i, El valor de **ppib es: %d \n",&ppib, **ppib);
	
	printf("%i, El valor de ***pppic es: %d \n",&pppic, ***pppic);
	
	
	
	printf("\n-----------------------------------------------------------------------------------------------\n\n");
	
	//Fin del programa
	puts("Fin del programa version 15");
	printf("\n-----------------------------------------------------------------------------------------------\n\n");
	
	return 0;
	
}//Fin del main
