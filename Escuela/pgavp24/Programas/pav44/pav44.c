#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
#pragma ide diagnostic ignored "cert-err34-c"

/*
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   *   # Nombre: Alan David Jiménez Rodríguez                                *
   *   # Fecha: 6 de abril de 2024                                           *
   *   # Programa: Lista doblemente enlazada con inserción en orden de datos *
   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

//--------Librerías---------------------------
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <windows.h>

//---------Estructura de la lista y nodo-------
struct dato{
    int iKey;
    char cLetra;
};

struct nodo{
    struct dato Datos;
    struct nodo *siguiente;
    struct nodo *anterior;
};

//--------Menú----------------------------------
int menu(int opc){
    printf("\n\n\tMenú de opciones\n");
    printf("0.- Salir\n");
    printf("1.- Insertar en Orden\n");
    printf("2.- Mostar Lista\n");
    printf("Ingresa una opción: ");
    scanf("%i", &opc);
    return opc;
}

//----------Pedir datos al usr------------------
struct dato pedirDatos(){
    struct dato Datos;
    printf("Ingresa un numero: ");
    scanf("%d", &Datos.iKey);
    printf("Ingresa la letra: ");
    scanf("%s", &Datos.cLetra);
    return Datos;
}

//----------Alta Ordenada-----------------------
struct nodo *altaOrdenada(struct nodo *inicio){
    struct nodo *posActual; //Nodo posActual para no perder el inicio
    struct dato info_nueva = pedirDatos(); //Pedir datos al usuario
    struct nodo *insertar; //Nodo a insertar

    insertar = (struct nodo *)malloc(sizeof(struct nodo)); //Reservar memoria para el nodo posActual

    //Asignar los datos al nodo posActual
    insertar->Datos = info_nueva;

    // Colocación del nodo

    //Si la lista está vacía
    if (inicio == NULL){
        insertar->siguiente = NULL;
        insertar->anterior = NULL;
        inicio = insertar;

    }else{ //La lista tiene por lo menos un elemento
        posActual = inicio;

        while (insertar->Datos.iKey > posActual->Datos.iKey && posActual -> siguiente != NULL){
            posActual = posActual -> siguiente;
        } // avanzar hasta la posición a insertar

        if(posActual -> anterior == NULL && insertar->Datos.iKey <= posActual->Datos.iKey){ // datos al inicio
            insertar -> siguiente = posActual;
            posActual -> anterior = insertar;
            insertar -> anterior = NULL;
            inicio = insertar;
        }
        else if(posActual ->siguiente == NULL && insertar->Datos.iKey >= posActual->Datos.iKey){ // datos al final
            posActual -> siguiente = insertar;
            insertar -> anterior = posActual;
            insertar -> siguiente = NULL;
        }
        else{ // datos en medio
        insertar -> siguiente = posActual;
        insertar -> anterior = posActual -> anterior;
        posActual ->anterior -> siguiente = insertar;
        posActual -> anterior = insertar;
        }
    }

    return inicio;
}

//----------Mostrar Lista-----------------------
void mostrarLista(struct nodo *inicio){
    struct nodo *mostrar;
    mostrar = inicio;

    if(mostrar == NULL){
        printf("Lista vacía\n");
    }else{
        SetConsoleOutputCP(437); // Cambiar a CP437 para mostrar los caracteres especiales
        printf("%c-----------%c\n", 201, 187);
        printf("| Key | Let |\n");
        printf("%c-----------%c\n", 204, 185);
    while(mostrar != NULL){
        printf("| %3i | %3c |\n", mostrar->Datos.iKey, mostrar->Datos.cLetra);
        mostrar = mostrar -> siguiente;
    }
    printf("%c-----------%c\n", 200, 188);
    SetConsoleOutputCP(65001); // Cambiar de nuevo a UTF-8 para mostrar acentos
    }
}


// Inicio del programa
int main(){
    //Variables
    struct nodo *inicio = NULL;
    int opc = 1;

    //Poner consola en español para ver acentos
    SetConsoleOutputCP(65001);

    while(opc != 0){
        opc = menu(opc);
            switch(opc){

                case 0:
                    printf("Saliendo del programa\n");
                    break;

                case 1:
                    printf("Insertar en Orden\n");
                    inicio = altaOrdenada(inicio);
                    break;

                case 2:
                    printf("Mostrar Lista\n");
                    mostrarLista(inicio);
                    break;

                default:
                    printf("Opción no válida\n");
                    break;
            }
    }

    puts("Fin del programa PAV44 V3.0\n");
    return 0;
}//Fin del programa

#pragma clang diagnostic pop