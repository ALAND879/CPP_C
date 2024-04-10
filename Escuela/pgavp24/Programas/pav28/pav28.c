/*****************
Alan David Jiménez Rodríguez
2 de marzo
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
void mostrarDato(struct dato temp)
{
	printf("Clave: %3i, Letra: %c\n", temp.ikey, temp.cinicial);
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
struct nodo *bajasFinal(struct nodo *head)
{
	struct nodo *actual;
	struct nodo *anterior;

	actual = head;
	anterior = head;

	if (actual != NULL)
	{
		printf("Lista no vacía\n");
		if (actual->next != NULL)
		{
			while (actual->next != NULL)
			{
				anterior = actual;
				actual = actual->next;
			}
			anterior->next = NULL;
		}
		else
		{
			printf("Solo hay un nodo en la lista\n");

			head = NULL;
			// Mostrar información
		}
		// Se va a borrar actual  y mostrar info, se va a liberar memoria
		mostrarDato(actual->inf);
		free(actual);
		printf("Eliminación Exitosa!!");
	}
	return head;
}
//--------------------------------
struct nodo *bajasInicio(struct nodo *head)
{
	struct nodo *actual;
	actual = head;
	if (actual != NULL)
	{
		printf("Lista no vacía\n");
		head = actual->next;
		mostrarDato(actual->inf);
		free(actual);
		printf("Eliminación Exitosa!!");
	}
	else
	{
		printf("Lista vacía\n");
	}
	return head;
}
//--------------------------------
struct nodo *buscarClave(struct nodo *head, int iclave)
{
	struct nodo *actual;
	actual = head;
	while (actual->next != NULL && actual->inf.ikey != iclave)
	{
		actual = actual->next;
	}
	if (actual->inf.ikey == iclave)
	{
		return actual;
		// printf("Se detuvo en la clave\n");
		// mostrarDato(actual->inf);
	}
	else
	{
		return NULL;
	}
}
//--------------------------------
struct nodo *buscarLetra(struct nodo *head, char clebusca)
{
	struct nodo *actual;
	actual = head;
	while (actual->next != NULL && actual->inf.cinicial != clebusca)
	{
		actual = actual->next;
	}
	if (actual->inf.cinicial == clebusca)
	{
		return actual;
	}
	else
	{
		return NULL;
	}
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
	printf("6.... Bajas al final de la lista\n");
	printf("7.... Bajas al inicio de la lista\n");
	printf("8.... Buscar por clave\n");
	printf("9.... Buscar por letra\n");
	printf("0.... Salir\n");
	printf("\tOpcion ?: ");
	scanf("%i", &iop);
	return iop;
}
//--------------------------------
// Inicio del programa
int main()
{
	// Elementos de una lista ligada
	struct nodo *head;
	struct nodo *pos; // posicion en la lista del nodo encontrado
	head = NULL;	  // La lista no tiene elementos
	srand(time(0));	  // Inicializar semilla de numeros aleatorios
	int iopcion;
	int iLote;	 // Tamanio del lote
	int ii;		 // contador
	int iClave;	 // Busqueda por clave
	char cLetra; // Busqueda por letra

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
			head = bajasFinal(head);
			break;

		case 7:
			head = bajasInicio(head);
			break;

		case 8:
			printf("Dame la clave a buscar ?: ");
			scanf("%i", &iClave);
			pos = buscarClave(head, iClave);
			if (pos == NULL)
			{
				printf("Clave no encontrada\n");
			}
			else
			{
				printf("Clave encontrada\n");
				mostrarDato(pos->inf);
			}

		case 9:
			printf("Dame la letra a buscar ?: ");
			scanf(" %c", &cLetra);
			pos = buscarLetra(head, cLetra);
			if (pos == NULL)
			{
				printf("Letra no encontrada\n");
			}
			else
			{
				printf("Letra encontrada\n");
				mostrarDato(pos->inf);
			}
			break;

		default:
			printf("Opcion incorrecta\n");
			break;
		} // Fin del switch

	} while (iopcion != 0);
	// Fin del programa
	puts("Fin del programa pav28 v3");
	return 0;
} // Fin del main