/*****************
Alan David Jiménez Rodríguez
9 de marzo
Segundo Examen Parcial
********************/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

struct infopiloto
{
	int ilugar;
	int inumeropiloto;
	char cnombre[30];
	char cequipo[50];
	float ftiempoQuialiUno;
	float ftiempoQuialiDos;
	float ftiempoQuialiTres;
	int iVueltas;
};

struct qualifying
{
	struct infopiloto datosPiloto;
	struct qualifying *proximopiloto;
};

struct infopiloto pedirInfoPiloto()
{
	struct infopiloto miPilototemp;
	printf("Dame el lugar:");
	scanf("%i", &miPilototemp.ilugar);
	printf("Dame el numero del piloto:");
	scanf("%i", &miPilototemp.inumeropiloto);
	printf("Dame el nombre del piloto:");
	scanf(" %[^\n]", miPilototemp.cnombre);
	printf("Dame el equipo del piloto:");
	scanf(" %[^\n]", &miPilototemp.cequipo);
	printf("Dame el tiempo de la Q1:");
	scanf("%f", &miPilototemp.ftiempoQuialiUno);
	printf("Dame el tiempo de la Q2:");
	scanf("%f", &miPilototemp.ftiempoQuialiDos);
	printf("Dame el tiempo de la Q3:");
	scanf("%f", &miPilototemp.ftiempoQuialiTres);
	printf("Dame el numero de vueltas:");
	scanf("%i", &miPilototemp.iVueltas);

	return miPilototemp;
}

struct qualifying *agregarPiloto(struct qualifying *iniciolista)
{
	// Variables
	struct infopiloto datosTemporales;
	struct qualifying *usot;
	struct qualifying *usado;

	// Leer datos
	datosTemporales = pedirInfoPiloto();
	// Crear nodo
	usot = (struct qualifying *)malloc(sizeof(struct qualifying));
	// Poner informacion en el nodo
	usot->datosPiloto = datosTemporales;
	usot->proximopiloto = NULL;
	printf("Informacion en el nodo \n");

	// Acomodar al inicio de la lista
	usado = iniciolista;
	if (usado != NULL)
	{
		usot->proximopiloto = usado;
	}

	printf("Fin altas inicio\n");
	// Regresar
	return usot;
}

void Podio(struct qualifying *inicioLista)
{
	struct qualifying *lugarPodio;
	lugarPodio = inicioLista;
	printf("\nEl Podio es:\n");
	while (lugarPodio != NULL)
	{
		printf("Lugar: %i Numero del Piloto: %i Nombre: %s Equipo: %s Q1: %f Q2: %f Q3: %f Vueltas:%i\n", lugarPodio->datosPiloto.ilugar, lugarPodio->datosPiloto.inumeropiloto, lugarPodio->datosPiloto.cnombre, lugarPodio->datosPiloto.cequipo, lugarPodio->datosPiloto.ftiempoQuialiUno, lugarPodio->datosPiloto.ftiempoQuialiDos, lugarPodio->datosPiloto.ftiempoQuialiTres, lugarPodio->datosPiloto.iVueltas);
		lugarPodio = lugarPodio->proximopiloto;
	}

	printf("- - - - - - - - - - - - - -\n");
}

int administracion()
{
	int inumero;

	printf("0.... Salir\n");
	printf("1.... Altas de pilotos\n");
	printf("2.... Mostrar información\n");
	printf("3.... Buscar por numero de piloto\n");

	printf("Ingresa una opción : ");
	scanf("%i", &inumero);
	return inumero;
}

void busquedaPodio(struct infopiloto temp)
{
	printf("Lugar: %i Numero del Piloto: %i Nombre: %s Equipo: %s Q1: %f Q2: %f Q3: %f Vueltas:%i\n", temp.ilugar, temp.inumeropiloto, temp.cnombre, temp.cequipo, temp.ftiempoQuialiUno, temp.ftiempoQuialiDos, temp.ftiempoQuialiTres, temp.iVueltas);
}

struct qualifying *buscarPorNumeroPiloto(struct qualifying *iniciolista, int inumeroPiloto)
{
	struct qualifying *actual;
	actual = iniciolista;
	while (actual->proximopiloto != NULL && actual->datosPiloto.inumeropiloto != inumeroPiloto)
	{
		actual = actual->proximopiloto;
	}
	if (actual->datosPiloto.inumeropiloto == inumeroPiloto)
	{
		return actual;
	}
	else
	{
		return NULL;
	}
}

// Inicio del programa
int main()
{
	struct qualifying *iniciolista = NULL;
	struct qualifying *lugar = NULL;
	int iseleccion;
	int inumeroPiloto;

	do
	{
		iseleccion = administracion();

		switch (iseleccion)
		{
		case 0:
			break;

		case 1:
			iniciolista = agregarPiloto(iniciolista);
			break;

		case 2:
			Podio(iniciolista);
			break;

		case 3:
			printf("Ingresa el numero de piloto que quieres buscar: ");
			scanf("%i", &inumeroPiloto);
			lugar = buscarPorNumeroPiloto(iniciolista, inumeroPiloto);
			if (lugar == NULL)
			{
				printf("Clave no encontrada\n");
			}
			else
			{
				printf("Clave encontrada\n");
				busquedaPodio(lugar->datosPiloto);
			}
			break;

		default:
			printf("Opcion incorrecta\n");
			break;
		} // Fin del switch

	} while (iseleccion != 0);
	// Fin del programa
	puts("Fin del programa (Examen 2do parcial)\n");
	return 0;
} // Fin del main