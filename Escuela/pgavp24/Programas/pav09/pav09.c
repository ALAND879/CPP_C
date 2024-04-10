/*

Alan david jimenez rodríguez
3 febrero
Intercambio de apuntadores
apuntador colgante
*/

//Librerias
#include <stdio.h>

//inicio del programa
int main(){
	
	//Declaraciom de variables
	int ix, iy;
	
	//Punteros
	int *p1, *p2, *p3; //puntero colgante
	int *p4;
	
	//datos de entrada
	printf("Dame el valor de x: ");
	scanf("%i", &ix);
	
	printf("Dame el valor de y: ");
	scanf("%i", &iy);
	
	
	printf("x en %i, contiene %i\n", &ix, ix);
	
	printf("y en %i, contiene %i\n", &iy,iy);
	
	printf("p1 en %i\n", &p1);
	printf("p2 en %i\n", &p2);
	printf("p3 en %i\n", &p3);
	
	//asignacion de direcciones
	p1 = &ix;
	p2 = &iy;
	printf("p1 contiene %i su valor es %i\n", p1, *p1);
	printf("p2 contiene %i su valor es %i\n", p2, *p2);
	
	p3 = p1;
	p1 = p2;
	p2 = p3;
	
	printf("Los contenidos intercambiados son: \n");
	printf("p1 contiene %i su valor es %i\n", p1, *p1);
	printf("p2 contiene %i su valor es %i\n", p2, *p2);
	printf("x en %i, contiene %i\n", &ix, ix);
	printf("y en %i, contiene %i\n", &iy,iy);
	
	printf("puntero colgante: \n");
	//	*p4 = 100;
	//printf("p4 direccion %i contiene %i\n", &p4, p4);
	/*
	Al utilizar un apuntador 
	1) Declarar el apuntador 
	2)Declarar la variable a la que va a apuntar
	3)Apnte el puntero a la variable
	*/
	//Fin del programa
	puts("Fin del programa V9");
	return 0;
	
}//Fin del main
