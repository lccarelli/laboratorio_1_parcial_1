#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "marca.h"

#define OK 0
#define noOK 1
#define ERROR -1

void harcodearMarca(eMarca marcas[], int tam, int cantidad){
	int cont = 0;
	eMarca listaAux[]=
	{
			{1000, "Wirpool"},{1001, "Sony"},{1002, "Liliana"},{1003, "Gafa"},{1004, "Philips"}
	};

	if(cantidad <= tam && cantidad < 11){
		for(int i=0; i<cantidad; i++){
			marcas[i] = listaAux[i];
			cont++;
		};
	};
};


int mostrarMarca(eMarca* e){
	int result;

	if(e != NULL){
		printf("|MARCA\n");
		printf("|%s	\n", e->descripcion);
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int mostrarListMarca(eMarca marcas[], int len){
	int i, result;

	if(marcas != NULL && len > 0){
		printf ("\n***Lista MARCAS***\n\n");
		for(i=0;i<len;i++){
				mostrarMarca(&marcas[i]);
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};
