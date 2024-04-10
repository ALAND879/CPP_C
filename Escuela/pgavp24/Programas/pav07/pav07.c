/*
Nombre: Alan David Jiménez Rodríguez
Tarea - pav 07

Instrucciones:
Escribir un programa para crear problemas de suma para que sean resueltos.
Los problemas implicarán la suma de dos números.

Presentará 10 problemas
-deberá indicar al usuario si la respuesta es correcta en cada problema
-deberá dar la calificación final
-preguntar si desea realizar otra prueba
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Procedimiento / Funciones
int numeros_aleatorios(int minimo, int maximo) {
    int numero = (rand() / (RAND_MAX + 1.0) * (maximo - minimo + 1));
    return numero + minimo;
}

//Inicio del programa
int main() {

    //declaracion de variables
    int primer_numero;
    int segundo_numero;
    int respuesta;
    int respuesta_usuario;
    int aciertos = 0;
    int continuar = 2;
	int i = 0;
	
    //Semilla
    srand(time(0));

    //proceso
    // condición para saber si quiere hacer nuevamente la prueba
    do {
    	system("cls");
        //bucle para hacer 10 sumas
        while ( i < 10 ) {
        	   
            primer_numero = numeros_aleatorios(1, 99); //Se genera primer numero aleatorio en un rango de 1 a 99
            segundo_numero = numeros_aleatorios(1, 99); //Se genera segundo numero aleatorio en un rango de 1 a 99
            respuesta = primer_numero + segundo_numero; //Se genera la respuesta

            printf("\nRealiza la siguiente suma: %i + %i = ", primer_numero, segundo_numero);
            scanf("%i", &respuesta_usuario); //Pedimos la respuesta del usuario

            if (respuesta_usuario == respuesta) { //validamos si fue acierto o no para sumarlo en caso de ser necesario
                printf("Acertaste\n");
                aciertos++;
            } 
			else {		
                printf("Tu suma fue incorrecta\n");
            }
            
        i++; //Se agrega una iteracion al ciclo para repetir 10 veces
        } //fin del for
        
        i=0;  // Se reincian las iteracion por si se quiere empezar nuevamente
	  
		  
		printf("\nTu puntaje final fue de: %i\n", aciertos);
        printf("¿Quieres volver a intentarlo?\n 1.-Si\n 2.-No\n");
        scanf("%i", &continuar);

    } while (continuar == 1);

	puts("Fin del programa");
    return 0;
}//fin del main

