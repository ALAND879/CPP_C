/*****************
Alan David Jimenez Rodríguez
pav30.c
Manejo de Listas ligadas,
Estructuras Dinamicas, Apuntadores
********************/
// Librerias
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

// Definir el plano del nodo que conforma la lista
struct dato
{
	int ikey;
	char cinicial;
};
struct nodo
{
	struct dato inf;
	struct nodo *next;
};
//--------------------------------
// Procedimientos / Funciones
//--------------------------------
//----------------------
int aleatorio(int imenor, int imayor)
{
	int idato;
	idato = rand() / (RAND_MAX + 1.0) * (imayor - imenor + 1);
	return imenor + idato;
}
//--------------------------------
struct dato leerDato()
{
	struct dato temporal;
	printf("Dame la clave ?:");
	scanf("%i", &temporal.ikey);
	printf("Dame una letra [a..z] ?:");
	temporal.cinicial = getch();
	printf("%c\n", temporal.cinicial);

	return temporal;
}
//-------------------------------
void mostrarDato(struct dato tem)
{
	printf("Id: %3i , %c \n", tem.ikey, tem.cinicial);
}
//-------------------------------
struct nodo *altasInicio(struct nodo *head)
{
	// Variables
	struct dato infot;
	struct nodo *temporal;
	struct nodo *actual;

	// Leer datos
	infot = leerDato();
	// Crear nodo
	temporal = (struct nodo *)malloc(sizeof(struct nodo));
	// Poner informacion en el nodo
	temporal->inf = infot;
	temporal->next = NULL;
	printf("informacion en el nodo \n");

	// Acomodar al inicio de la lista
	actual = head;
	if (actual != NULL)
	{
		temporal->next = actual;
	}

	printf("Fin altas inicio\n");
	// Regresar
	return temporal;
}
//-------------------------------
void mostrarLista(struct nodo *head)
{
	struct nodo *mostrar;
	mostrar = head;
	printf("\nEl contenido de la lista es:\n");
	while (mostrar != NULL)
	{
		printf("%4i  %c\n", mostrar->inf.ikey, mostrar->inf.cinicial);
		mostrar = mostrar->next;
	}

	printf("- - - - - - - - - - - - - -\n");
}
//--------------------------------
struct nodo *altasFinal(struct nodo *head)
{
	// Variables
	struct dato infot;
	struct nodo *temporal;
	struct nodo *actual;
	// leer datos
	infot = leerDato();
	// Crear nodo
	temporal = (struct nodo *)malloc(sizeof(struct nodo));
	// poner informacion en el nodo
	temporal->inf = infot;
	temporal->next = NULL;

	// acomodar nodo al final de la lista

	if (head == NULL)
	{
		head = temporal;
	}
	else
	{
		actual = head;
		while (actual->next != NULL)
		{
			actual = actual->next;
		}
		// Al estar en la ultima posicion
		actual->next = temporal;
	}
	return head;
}
//--------------------------------
struct nodo *altaInicioAle(struct nodo *head)
{
	// Variables
	struct dato infot;
	struct nodo *temporal;
	struct nodo *actual;
	// generar datos
	infot.ikey = aleatorio(1, 100);
	infot.cinicial = aleatorio(97, 122);
	// crear nodo
	temporal = (struct nodo *)malloc(sizeof(struct nodo));
	// Poner informacion en el nodo
	temporal->inf = infot;
	temporal->next = NULL;
	// Acomodar al inicio de la lista
	actual = head;
	if (actual != NULL)
	{
		temporal->next = actual;
	}
	return temporal;
}
//--------------------------------
struct nodo *bajaFinal(struct nodo *head)
{
	struct nodo *actual;
	struct nodo *anterior;

	actual = head;
	anterior = head;
	if (actual != NULL)
	{
		printf("Lista no vacia \n");
		if (actual->next != NULL)
		{
			// Encontrar al ultimo de la lista
			while (actual->next != NULL)
			{
				anterior = actual;
				actual = actual->next;
			} // Fin while

			anterior->next = NULL;
		}
		else
		{
			// Un solo nodo en la lista
			head = NULL;
			// Mostrar informacion
		}
		// Se va borrar actual
		// mostrar informacion
		mostrarDato(actual->inf);
		// liberar espacio
		free(actual);
		printf("Eliminacion exitosa!!!");
	}
	return head;
}
//--------------------------------
struct nodo *bajaInicio(struct nodo *head)
{
	struct nodo *actual;

	actual = head;
	if (actual != NULL)
	{
		// Almenos hay un elemento en la lista
		head = actual->next;
		mostrarDato(actual->inf);
		free(actual);

		printf("Baja exitosa\n");
	}

	return head;
}
//--------------------------------
struct nodo *buscarLista(struct nodo *head, int key)
{
	struct nodo *actual;
	actual = head;

	while (actual->next != NULL && actual->inf.ikey != key)
	{
		actual = actual->next;
	}
	// printf("Se detuvo\n");
	// mostrarDato(actual->inf);
	if (actual->inf.ikey != key)
	{
		actual = NULL;
	}

	return actual;
}
//--------------------------------
struct nodo *altaOrdenada(struct nodo *primero)
{
	// variables
	struct nodo *temporal;
	struct nodo *actual;
	struct nodo *anterior;

	struct dato info;
	printf("Altas ordenadas \n");
	// Crear nodo
	temporal = (struct nodo *)malloc(sizeof(struct nodo));

	// Obtener datos
	info = leerDato();

	// Asignar datos al nodo
	temporal->inf = info;
	temporal->next = NULL;

	// Acomodar el nodo

	// La lista esta vacia ?
	if (primero == NULL) // if-1
	{
		primero = temporal;
	}
	else
	{
		// Hay nodos en la lista
		// Recorrer la lista
		actual = primero;
		anterior = primero;

		while ((temporal->inf.ikey > actual->inf.ikey) && (actual->next != NULL))
		{
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
			}
			else
			{
				anterior->next = temporal;
				temporal->next = actual;

			} // fin if-3
		}
		else
		{
			// alta al final de la lista
			actual->next = temporal;

		} // fin if-2

	} // fin if-1

	return primero;
}
//--------------------------------
struct nodo *bajaClave(struct nodo *head)
{
	// Declaracion de variables
	int itkey;
	struct nodo *thead;
	struct nodo *anterior;
	struct nodo *baja;

	if (head != NULL)
	{

		// Dato de entrada
		printf("Dame la clave a dar de baja?: ");
		scanf("%i", &itkey);

		// Proceso
		thead = head;
		anterior = head;
		baja = NULL; // El elemento a dar de baja no esta en la lista
		// Buscar la clave en la lista
		if (thead->next == NULL & thead->inf.ikey == itkey) // if-2
		{
			// Hay un solo elemento y es el que va a dar de baja
			baja = thead;
			head = NULL;
		}
		else
		{
			// Buscar en la lista

			baja = thead;
			anterior = thead;

			while (baja->inf.ikey != itkey && baja->next != NULL)
			{
				anterior = baja;
				baja = baja->next;
			} // Fin de busqueda

			if (baja->inf.ikey == itkey) // if-3
			{
				if (baja->next == NULL) // if-4
				{
					// Es el ultimo de la lista
					anterior->next = NULL;
				}
				else
				{

					// Es el primero de la lista y hay masa datos
					if (anterior == head)
					{ // if 5
						head = baja->next;
					}
					else
					{
						// Hay datos antes y depsues del nodo a dar de baja
						anterior->next = baja->next;
					} // fin if-5
				}	  // fin if-4
			}
			else
			{
				baja = NULL; // NO lo encontro
			}				 // if-3
		}					 // fin if-2

		if (baja != NULL)
		{ // if-10
			// Mostrar
			mostrarDato(baja->inf);
			// Liberar o destruir
			free(baja);
			printf("\nBaja confirmada\n");
		}
		else
		{
			printf("La clave %i NO esta en la lista\n", itkey);
		}
	}
	else
	{
		printf("\nNo se pueden realizar bajas, la lista esta vacia\n");
	} // fin if-1
	return head;
}
//--------------------------------
int menuLista()
{
	int iop;
	printf("\nLista Ligada (2 de marzo) \n");
	printf("1.... Altas al inicio de la lista\n");
	printf("2.... Mostar la lista\n");
	printf("3.... Altas al final de la lista\n");
	printf("4.... Altas en lote al inicio de la lista\n");
	printf("6.... Baja al final de la lista\n");
	printf("7.... Baja al inicio de la lista\n");
	printf("8.... Buscar por clave\n");
	printf("9.... Alta ordenada por clave\n");
	printf("11... Baja por clave\n");
	printf("0.... Salir\n");
	printf("\tOpción ?: ");
	scanf("%i", &iop);
	return iop;
}
//--------------------------------
// Inicio del programa
int main()
{
	// Elementos de una lista ligada
	struct nodo *head;
	struct nodo *pos; // posicion del nodo encotrado
	head = NULL;	  // La lista no tiene elementos
	srand(time(0));	  // Inicializar semilla de numeros aleatorios
	int iopcion;
	int iLote;	// Tamanio del lote
	int ii;		// contador
	int iclave; // Busqueda por clave
	do
	{

		// Datos de entrada
		iopcion = menuLista();
		// Proceso
		switch (iopcion)
		{
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
			for (ii = 1; ii <= iLote; ii++)
			{
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
			scanf("%i", &iclave);
			pos = buscarLista(head, iclave);
			if (pos == NULL)
			{
				printf("La clave no existe en la lista: ");
			}
			else
			{
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

		default:
			printf("Opcion incorrecta\n");
			break;
		} // Fin del switch

	} while (iopcion != 0);
	// Fin del programa
	puts("Fin del programa pav38 v1");
	return 0;
} // Fin del main