#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "servicio.h"

#define OK 0
#define noOK 1
#define ERROR -1


void harcodearServicios(eServicio* list, int tam, int cantidad){
	eServicio listaAux[]=
	{
			{20000, "GARANTIA", 250},
			{20001, "MATENIMIENTO", 500},
			{20002, "REPUESTOS", 400},
			{20003, "REFACCION", 600}
	};

	if(cantidad <= tam && cantidad < 11){
		for(int i=0; i<cantidad; i++){
			list[i] = listaAux[i];
		};
	};
};

int mostrarServicio(eServicio* e){
	int result;

	if(e != NULL){
		printf("|SERVICIO		|PRECIO\n");
		printf("|%s			|%.2f\n", e->descripcion, e->precio);
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int mostrarListServicio(eServicio* list, int len){
	int i, result;

	if(list != NULL && len > 0){
		printf ("\n***Lista SERVICIOS***\n\n");
		for(i=0;i<len;i++){
				mostrarServicio(&list[i]);
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};
