/*******
Alan David Jimenez Rodr�guez
24 de febrero
Manejo de listas ligadas
Estructuras dinamicas apuntadores
**********/

// Librerias
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
// dEFINIR EL PLANO DEL NODO que conforma la lista

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

// Procedimiento Funciones
int menuLista()
{
	int iopc;
	printf("\nLista ligada \n");
	printf("5.... Altas al final de la lista en lote\n");
	printf("4.... Altas al inicio de la lista en lote \n");
	printf("3.... Altas al final de la lista \n");
	printf("2.... Mostrar la lista\n");
	printf("1.... Altas al inicio de la lista \n");
	printf("0.... Salir \n");
	printf("\t opcion ?: ");
	scanf("%i", &iopc);
	return iopc;
}

struct dato leerDato()
{
	struct dato temporal;

	printf("Dame la clave ?:");
	scanf("%i", &temporal.ikey);

	printf("Dame una letra [a-z]?:  ");
	temporal.cinicial = getch();
	printf("%c\n", temporal.cinicial);

	return temporal;
}

struct nodo *altasInicio(struct nodo *head)
{

	// variables
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
	printf("informacion en el nodo\n");

	// Acomodar al inicio el nodo
	actual = head;

	if (actual != NULL)
	{
		temporal->next = actual;
	}

	printf("Fin altas inicio");

	// Regresar
	return temporal;
}

void mostrarLista(struct nodo *head)
{
	struct nodo *mostrar;
	mostrar = head;
	printf("El contenido de la lista es: \n");

	while (mostrar != NULL)
	{
		printf("%4i, %c \n", mostrar->inf.ikey, mostrar->inf.cinicial);
		mostrar = mostrar->next;
	}

	printf("-----------------------------------------------------------");
}

struct nodo *altasFinal(struct nodo *head)
{
	// variables
	struct dato infot;
	struct nodo *temporal;
	struct nodo *actual;

	// leer datos
	infot = leerDato();

	// Crear nodo
	temporal = (struct nodo *)malloc(sizeof(struct nodo));

	// Poner informacion en el nodo
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

int aleatorio(int imenor, int imayor)
{
	int idato;
	idato = rand() / (RAND_MAX + 1.0) * (imayor - imenor + 1);
	return imenor + idato;
}

struct nodo *altaInicioAleatorio(struct nodo *head)
{
	// variables
	struct dato infot;
	struct nodo *temporal;
	struct nodo *actual;

	// generar datos
	infot.ikey = aleatorio(1, 100);
	infot.cinicial = aleatorio(97, 122);

	// Crear nodo
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

	// Regresar
	return temporal;
}

struct nodo *altaFinalAleatorio(struct nodo *head)
{
	// variables
	struct dato infot;
	struct nodo *temporal;
	struct nodo *actual;

	// leer datos
	infot.ikey = aleatorio(1, 100);
	infot.cinicial = aleatorio(97, 122);

	// Crear nodo
	temporal = (struct nodo *)malloc(sizeof(struct nodo));

	// Poner informacion en el nodo
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

// INIcio del programa
int main()
{
	// Elementos de una lista ligada
	struct nodo *head;
	head = NULL;	// La lista no tiene elementos
	srand(time(0)); // Inicializar semilla de numeros aleatorios.
	int iopcion;
	int iLote; // tama�o del lote
	int ii;	   // contador

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
			printf("Ingresa el numero de repeticiones: ");
			scanf("%i", &iLote);
			for (ii = 0; ii < iLote; ii++)
			{
				head = altaInicioAleatorio(head);
			}
			break;

		case 5:
			printf("Ingresa el numero de repeticiones: ");
			scanf("%i", &iLote);
			for (ii = 0; ii < iLote; ii++)
			{
				head = altaFinalAleatorio(head);
			}
			break;

		default:
			printf("Opcion incorrecta");
			break;

		} // Fin del switch

	} while (iopcion != 0);

	// Fin del programa
	puts("Fin del programa pav 22 v1");
	return 0;
} // Fin del main
