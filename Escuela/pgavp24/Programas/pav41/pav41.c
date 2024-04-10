#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
/*****************
Alan David Jiménez Rodríguez
6 de abril
Manejo de Listas ligadas,
Estructuras Dinámicas, Apuntadores
********************/

// Librerías
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

// Definir el plano del nodo que conforma la lista
struct dato {
    int ikey;
    char cInicial;
};

//-------------------------------
struct nodo {
    struct dato inf;
    struct nodo *next;
};

// Procedimientos / Funciones

//-------------------------------
int aleatorio(int iMenor, int iMayor) {
    int iDato;
    iDato = rand() / (RAND_MAX + 1.0) * (iMayor - iMenor + 1);
    return iMenor + iDato;
}

//-------------------------------
struct dato leerDato() {
    struct dato temporal;
    printf("Dame la clave ?:");
    scanf("%i", &temporal.ikey);
    printf("Dame una letra [a..z] ?:");
    temporal.cInicial = getch();
    printf("%c\n", temporal.cInicial);

    return temporal;
}

//-------------------------------
void mostrarDato(struct dato tem) {
    printf("Id: %3i , %c \n", tem.ikey, tem.cInicial);
}

//-------------------------------
struct nodo *altasInicio(struct nodo *head) {
    // Variables
    struct dato infoT;
    struct nodo *temporal;
    struct nodo *actual;

    // Leer datos
    infoT = leerDato();
    // Crear nodo
    temporal = (struct nodo *) malloc(sizeof(struct nodo));
    // Poner información en el nodo
    temporal->inf = infoT;
    temporal->next = NULL;
    printf("Información en el nodo \n");

    // Acomodar al inicio de la lista
    actual = head;
    if (actual != NULL) {
        temporal->next = actual;
    }

    printf("Fin altas inicio\n");
    // Regresar
    return temporal;
}

//-------------------------------
void mostrarLista(struct nodo *head) {
    struct nodo *mostrar;
    mostrar = head;
    printf("\nEl contenido de la lista es:\n");
    while (mostrar != NULL) {
        printf("%4i  %c\n", mostrar->inf.ikey, mostrar->inf.cInicial);
        mostrar = mostrar->next;
    }

    printf("- - - - - - - - - - - - - -\n");
}

//--------------------------------
struct nodo *altasFinal(struct nodo *head) {
    // Variables
    struct dato infoT;
    struct nodo *temporal;
    struct nodo *actual;
    // leer datos
    infoT = leerDato();
    // Crear nodo
    temporal = (struct nodo *) malloc(sizeof(struct nodo));
    // poner información en el nodo
    temporal->inf = infoT;
    temporal->next = NULL;

    // acomodar nodo al final de la lista

    if (head == NULL) {
        head = temporal;
    } else {
        actual = head;
        while (actual->next != NULL) {
            actual = actual->next;
        }
        // Al estar en la última posición
        actual->next = temporal;
    }
    return head;
}

//--------------------------------
struct nodo *altaInicioAle(struct nodo *head) {
    // Variables
    struct dato infoT;
    struct nodo *temporal;
    struct nodo *actual;
    // generar datos
    infoT.ikey = aleatorio(1, 100);
    infoT.cInicial = aleatorio(97, 122);
    // crear nodo
    temporal = (struct nodo *) malloc(sizeof(struct nodo));
    // Poner información en el nodo
    temporal->inf = infoT;
    temporal->next = NULL;
    // Acomodar al inicio de la lista
    actual = head;
    if (actual != NULL) {
        temporal->next = actual;
    }
    return temporal;
}

//--------------------------------
struct nodo *bajaFinal(struct nodo *head) {
    struct nodo *actual;
    struct nodo *anterior;

    actual = head;
    anterior = head;
    if (actual != NULL) {
        printf("Lista no vacía \n");
        if (actual->next != NULL) {
            // Encontrar al ultimo de la lista
            while (actual->next != NULL) {
                anterior = actual;
                actual = actual->next;
            } // Fin while

            anterior->next = NULL;
        } else {
            // Un solo nodo en la lista
            head = NULL;
            // Mostrar información
        }
        // Se va a borrar actual
        // mostrar información
        mostrarDato(actual->inf);
        // liberar espacio
        free(actual);
        printf("Eliminación exitosa!!!");
    }
    return head;
}

//--------------------------------
struct nodo *bajaInicio(struct nodo *head) {
    struct nodo *actual;

    actual = head;
    if (actual != NULL) {
        // Al menos hay un elemento en la lista
        head = actual->next;
        mostrarDato(actual->inf);
        free(actual);

        printf("Baja exitosa\n");
    }

    return head;
}

//--------------------------------
struct nodo *buscarLista(struct nodo *head, int key) {
    struct nodo *actual;
    actual = head;

    while (actual->next != NULL && actual->inf.ikey != key) {
        actual = actual->next;
    }
    // printf("Se detuvo\n");
    // mostrarDato(actual->inf);
    if (actual->inf.ikey != key) {
        actual = NULL;
    }

    return actual;
}

//--------------------------------
struct nodo *altaOrdenada(struct nodo *primero) {
    // variables
    struct nodo *temporal;
    struct nodo *actual;
    struct nodo *anterior;

    struct dato info;
    printf("Altas ordenadas \n");
    // Crear nodo
    temporal = (struct nodo *) malloc(sizeof(struct nodo));

    // Obtener datos
    info = leerDato();

    // Asignar datos al nodo
    temporal->inf = info;
    temporal->next = NULL;

    // Acomodar el nodo

    // La lista esta vacía ?
    if (primero == NULL) // if-1
    {
        primero = temporal;
    } else {
        // Hay nodos en la lista
        // Recorrer la lista
        actual = primero;
        anterior = primero;

        while ((temporal->inf.ikey > actual->inf.ikey) && (actual->next != NULL)) {
            anterior = actual;
            actual = actual->next;
        } // fin-while

        // El temporal es menor al actual
        if (temporal->inf.ikey <= actual->inf.ikey) // If-2
        {
            if ((anterior == primero) && (temporal->inf.ikey <= primero->inf.ikey)) // if-3
            {

                temporal->next = primero;
                primero = temporal;
            } else {
                anterior->next = temporal;
                temporal->next = actual;

            } // fin if-3
        } else {
            // alta al final de la lista
            actual->next = temporal;

        } // fin if-2

    } // fin if-1

    return primero;
}

//--------------------------------
struct nodo *bajaClave(struct nodo *head) {
    // Declaración de variables
    int itKey;
    struct nodo *thead;
    struct nodo *anterior;
    struct nodo *baja;

    if (head != NULL) // if-1
    {

        // Dato entrada
        printf("Dame la clave a dar de baja ?: ");
        scanf("%i", &itKey);
        // Proceso
        thead = head;
        anterior = head;
        baja = NULL; // El elemento a dar de baja NO está en lista
        // Buscar la clave en la lista
        if (thead->next == NULL && thead->inf.ikey == itKey) // if-2
        {
            // hay un solo elemento en la lista y es el que se va a dar de baja
            baja = thead;
            head = NULL;
        } else {
            // buscar en la lista
            baja = thead;
            anterior = thead;

            while (baja->inf.ikey != itKey && baja->next != NULL) {
                anterior = baja;
                baja = baja->next;
            } // Fin de búsqueda

            if (baja->inf.ikey == itKey) // if-3
            {
                if (baja->next == NULL) // if-4
                {
                    // Es el último de la lista
                    anterior->next = NULL;
                } else {
                    // Es el primero de la lista y hay más datos
                    if (anterior == head) // if-5
                    {
                        head = baja->next;
                    } else {
                        // hay datos antes y después del nodo a dar de baja
                        anterior->next = baja->next;
                    } // fin if-5
                }      // Fin if-4
            } else {
                baja = NULL; // NO lo encontró
            }                 // if-3

        } // Fin if-2

        // Mostrar información del nodo y liberar espacio
        if (baja != NULL) // if-10
        {
            // Mostrar
            mostrarDato(baja->inf);
            // Liberar o destruir
            free(baja);
            printf("\nBaja confirmada\n");
        } else {
            printf("\nLa clave %i NO esta en la lista\n", itKey);
        } // Fin if-10
    } else {
        printf("\nNo se pueden realizar bajas, la lista esta vacía\n");
    } // Fin if-1
    return head;
}

//--------------------------------
struct nodo *selectionSort(struct nodo *head) {

    //Variables
    struct nodo *act;
    struct nodo *sig;
    struct nodo *men;
    struct dato tData;
    printf("Ordenamiento por selección");

    act = head;

    while (act != NULL) { //w-1
        //printf("\nw1");
        men = act;
        sig = act->next;

        while (sig != NULL) { //inicio while 2
            //printf("\nw2");
            //Buscar al menor
            if (sig->inf.ikey < men->inf.ikey) {
                men = sig;
            }
            sig = sig->next;

        }//Fin del while 2
        if (men->inf.ikey < act->inf.ikey) {
            //Intercambio
            //printf("\nIntercambio");
            tData = act->inf;
            act->inf = men->inf;
            men->inf = tData;
        }
        act = act->next;
    }//Fin del while 1


    return head;
}

//--------------------------------
int contarLista(struct nodo *head) {
    struct nodo *actual;
    int contador = 0;

    actual = head;
    while (actual != NULL) {
        contador++;
        actual = actual->next;
    }

    return contador;
}

//--------------------------------
struct nodo *bubbleSort(struct nodo *head) {
    printf("\nOrdenamiento burbuja\n");

    //Variables
    int tam;
    struct dato tDato;
    struct nodo *act;
    struct nodo *sig;

    //Contar elementos de la lista
    tam = contarLista(head);
    //printf("%d", tam);

    for (int ii = 0; ii < tam - 1; ii++) {//for 1
        //printf("ii %i\n", ii);
        for (int jj = 1; jj < tam - ii; jj++) {//for 2
            //printf("jj %i\n", jj);
            if (jj == 1) {
                act = head;
            }
            sig = act->next;
            if (act->inf.ikey > sig->inf.ikey) {
                //Intercambio
                tDato = act->inf;
                act->inf = sig->inf;
                sig->inf = tDato;
            }
            act = act->next;
        }// fin for 2
    }//fin for 1

    return head;
}

//--------------------------------
int menuLista() {
    int iop;
    printf("\nLista Ligada (23 de marzo) \n");
    printf("1.... Altas al inicio de la lista\n");
    printf("2.... Mostar la lista\n");
    printf("3.... Altas al final de la lista\n");
    printf("4.... Altas en lote al inicio de la lista\n");
    printf("6.... Baja al final de la lista\n");
    printf("7.... Baja al inicio de la lista\n");
    printf("8.... Buscar por clave\n");
    printf("9.... Alta ordenada por clave\n");
    printf("11... Baja por clave\n");
    printf("12... Ordenamiento por selección\n");
    printf("13... Ordenamiento burbuja\n");
    printf("0.... Salir\n");
    printf("\tOpción ?: ");
    scanf("%i", &iop);
    return iop;
}

//--------------------------------
// Inicio del programa
int main() {
    //poner la consola en Español
    system("chcp 65001");

    // Elementos de una lista ligada
    struct nodo *head;
    struct nodo *pos; // posición del nodo encontrado
    head = NULL;      // La lista no tiene elementos
    srand(time(0));      // Inicializar semilla de números aleatorios
    int iOpc;
    int iLote;    // Tamaño del lote
    int ii;        // contador
    int iClave; // Búsqueda por clave
    do {

        // Datos de entrada
        iOpc = menuLista();
        // Proceso
        switch (iOpc) {
            case 0:
                break;
            case 1:
                head = altasInicio(head);
                break;
            case 2:
                mostrarLista(head);
                break;
            case 3:
                head = altasFinal(head);
                break;
            case 4:
                printf("Dame el numero de altas a generar ?: ");
                scanf("%i", &iLote);
                for (ii = 1; ii <= iLote; ii++) {
                    head = altaInicioAle(head);
                }
                printf("Fin de altas en lote\n");

                break;
            case 6:
                printf("\nBaja al final de la lista\n");
                head = bajaFinal(head);
                break;
            case 7:
                printf("\nBaja al inicio de la lista\n");
                head = bajaInicio(head);
                break;
            case 8:
                printf("Dame la clave a buscar ?: ");
                scanf("%i", &iClave);
                pos = buscarLista(head, iClave);
                if (pos == NULL) {
                    printf("La clave no existe en la lista: ");
                } else {
                    printf("La clave existe \n");
                    mostrarDato(pos->inf);
                }

                break;
            case 9:
                head = altaOrdenada(head);
                break;
            case 11:
                head = bajaClave(head);
                break;

            case 12:
                head = selectionSort(head);
                break;

            case 13:
                head = bubbleSort(head);
                break;

            default:
                printf("Opción incorrecta\n");
                break;
        } // Fin del switch

    } while (iOpc != 0);
    // Fin del programa
    puts("Fin del programa pav41 v1");
    return 0;
} // Fin del main

#pragma clang diagnostic pop