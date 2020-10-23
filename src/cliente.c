#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"

#define OK 0
#define noOK 1
#define ERROR -1

void harcodearCliente(eCliente* list, int tam, int cantidad){
	eCliente listaAux[]=
	{
			{0, "Juan", "Cortez"},
			{1, "Federico", "Marilungo"},
			{2, "Ana", "Pombo"},
			{3, "Daria", "Pombo"},
			{4, "Luke", "Carelli"}
	};

	if(cantidad <= tam && cantidad < 11){
		for(int i=0; i<cantidad; i++){
			list[i] = listaAux[i];
		};
	};
};

int mostrarCliente(eCliente* e){
	int result;

	if(e != NULL){
		printf("|IDCLIENTE	|NOMBRE	|APELLIDO \n");
		printf("|%d		|%s		|%s\n", e->id, e->nombre, e->apellido);
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int mostrarListCliente(eCliente* list, int len){
	int i, result;

	if(list != NULL && len > 0){
		printf ("\n***Lista CLIENTES***\n\n");
		for(i=0;i<len;i++){
				mostrarCliente(&list[i]);
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};
