/****************
Alan David Jiménez Rodríguez
17 de febrero
Uso del . en estructuras para manipular las variables que la conforman
Apuntadora una estructura
Al utilizar un apuntador a una estructura se usa el operador -> para manipular las variables que conforman a la estructura.
**************************/

//Librerias
#include <stdio.h>

//Inicio del programa
int main(){
	
	//definicion de  estructura
	struct articulo{
		char codigo[5];
		int cantidad;
		float costo;
	};
	
	//Declaracion de variables
	struct articulo emperador;  //VAriables de tipo struct
	struct articulo marias;
	
	struct articulo *pGalleta;  //apuntador de tipo struct
	
	printf("tam float: %i\n", sizeof(float));
	printf("tam char %i\n", sizeof(char));
	printf("tam int: %i \n", sizeof(int));
	printf("articulo tam: %i \n", sizeof(struct articulo));
	printf("%i emperador tam: %i \n", &emperador, sizeof(emperador));
	
	//Leer datos
	printf("Datos de galletas emperador: \n");
	printf("Codigo: ");
	scanf("%s", &emperador.codigo);
	printf("Cantidad: ");
	scanf("%i", &emperador.cantidad);
	printf("Costo: ");
	scanf("%f", &emperador.costo);
	
	//Mostrar datos
	printf("%6s, %3i, $%6.2f \n", emperador.codigo, emperador.cantidad, emperador.costo);
	
	printf("%i, pgalleta %i contiene %i\n", &pGalleta, pGalleta, *pGalleta);
	pGalleta = &emperador;
	printf("%i, pgalleta %i contiene %i\n", &pGalleta, pGalleta, *pGalleta);
	
	
	printf("\t------- articulo usando apuntador \n");
	printf("%6s, %3i, $%6.2f \n", pGalleta->codigo, pGalleta->cantidad, pGalleta->costo);
	
	
	printf("Actualización de informacion: \n");
	pGalleta->cantidad = 156;
	printf("Codigo: ");
	scanf("%s", &pGalleta->codigo);
	printf("Cantidad: ");
	scanf("%i", &pGalleta->cantidad);
	printf("Costo: ");
	scanf("%f", &pGalleta->costo);
	
	
	printf("\t------- articulo usando apuntador \n");
	printf("%6s, %3i, $%6.2f \n", pGalleta->codigo, pGalleta->cantidad, pGalleta->costo);
	
	printf("\t------- articulo\n");
	printf("%6s, %3i, $%6.2f \n", emperador.codigo, emperador.cantidad, emperador.costo);
	
	//Fin del programa 
	puts("Fin del programa v15");
	return 0;
	
}//Fin del main
