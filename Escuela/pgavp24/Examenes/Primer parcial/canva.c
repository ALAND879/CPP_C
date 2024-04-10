/*

Alan David Jimenez Rodríguez
3 de febrero de 2024
primer examen parcial

En UPAEP se ha liberado el LMS (Learning Management System) en CANVAS, el
tiempo de descarga de la página principal toma un tiempo de 575ms a 625ms, el
administrador requiere obtener la frecuencia de tiempos para una muestra de
20,000 descargas

Crear un programa en C que permita simular las 20,000 descargas mostrando
como resultado la frecuencia de los tiempos de descarga.
El programa se llamará canva, deberá entregar el programa canva.c y un reporte
en Word con la corrida del programa.

*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//procesos
int creanum(int minimo, int maximo){
	int numero;
	numero = (rand() / (RAND_MAX + 1.0) *  (maximo - minimo + 1) );
	return numero + minimo;
}


//inicio del programa
int main(){
	
	//DEclarar variables;
	int tiempos[51] = {};
	int simulacion;
	int iteracion;
	int total = 0;
	
	//declarar semillla
	srand(time(0));
	
	//Proceso
	for (iteracion = 1; iteracion <= 20000; iteracion++){
		simulacion = creanum(575, 625); //crea un numero de 575 a 625
		tiempos[simulacion-575] = (tiempos[simulacion-575]+1); //se añade al arreglo el numero que salio, es decir al aplicar simulacion-575 obtenemos la posicion del arreglo para guardar el valor
		//printf("%i\n", simulacion - 575 );  //Este es el lugar del arreglo donde se guardara
	}
		
	printf("\n Los puntajes obtenidos de cada ms son: \n");
	
	for(iteracion = 0; iteracion <=50; iteracion++){
		printf("El valor de %i ms aparecio %i veces\n", iteracion+575, tiempos[iteracion]); //se muestran en pantalla los resultados obtenidos, obteniendo los ms al aplicar la simualcion + 755
	}
	
//	for(iteracion = 0; iteracion <=50; iteracion++){
//		total = total + tiempos[iteracion];
//	}
	
	printf("El total  de pruebas fue de: %i \n", total);
	
	//Fin del programa
	puts("Fin del programa V6");
	return 0;
	
}//Fin del main
