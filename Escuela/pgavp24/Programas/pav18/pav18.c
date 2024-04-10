/******
Alan David Jiménez Rodríguez
17 de febrero

***************/

//librerias
#include <stdio.h>

//DEfinir struct
struct pedido{
	int cantidad;
	float costo;
	struct pedido *next;
};

//Inicio del programa

int main(){
	
	//declaracion de variables
	struct pedido edgar, alexis, oscar;
	
	//Datos de entrada
	edgar.cantidad = 12;
	edgar.costo = 120;
	edgar.next = NULL;
	
	alexis.cantidad = 4;
	alexis.costo = 80;
	alexis.next = NULL;
	
	oscar.cantidad = 6;
	oscar.costo = 95;
	oscar.next = NULL;
	
	printf("Edgar:\n");
	printf("%3i, $%5.2f, Total: $%7.2f \n", edgar.cantidad, edgar.costo, edgar.cantidad*edgar.costo);
	
	printf("Incorporacion del cheff:\n ");
	struct pedido *cheff;
	cheff = NULL;
	
	//Proceso
	cheff = &edgar;
	edgar.next	= &alexis;
	alexis.next = &oscar;
	
	while (cheff != NULL ){
		printf("%3i, $%5.1f, Total: $%7.1f \n", cheff->cantidad, cheff->costo, cheff->cantidad*cheff->costo);
		cheff = cheff->next;
	}
	
	//Fin del programa
	puts("Fin del programa v8\n");
	return 0;
	
}
