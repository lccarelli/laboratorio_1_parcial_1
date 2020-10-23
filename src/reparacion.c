#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "reparacion.h"
#include "electro.h"
#include "cliente.h"
#define OK 0
#define noOK 1
#define ERROR -1
#define ID_SERVICIO "Ingrese idServicio: (20000) Garantia - (20001) Mantenimiento - (20002) Respuesto - (20003) Refaccion \n"


static int seleccionarCliente(int* idCliente, eCliente* list, int len);

int initReparacion(eReparacion* list, int len){
	int i, result;
	if(list != NULL && len > 0){
		for(i=0;i<len;i++){
			list[i].id = -1;
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int findEmptyReparacion(eReparacion* list, int len){
	int i, result;
	if(list != NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].id == -1){
				result = i;
				break;
			} else {
				result = noOK;
			};
		};
	} else {
		result = noOK;
	};
	return result;
};

int addReparacion(eReparacion* list, int len, int* id, int index, eCliente* listCliente, eElectro* listElectro, int tamElectro){
	int result;
	eReparacion buffer;

	if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL){


		if(
				utn_getNumero(&buffer.serie,"Ingrese serie", "Error -> ingreso  no váido\n",1,1000000, 2) == OK &&
				utn_getNumero(&buffer.idServicio, ID_SERVICIO, "Error -> debe ingresar id válido\n", 20000, 20003, 2) == OK &&
				utn_getNumero(&buffer.fecha.dia, "ingrese dia\n", "error", 1, 31, 2) == OK &&
				utn_getNumero(&buffer.fecha.mes, "ingrese mes\n", "error",1, 12, 2) == OK &&
				utn_getNumero(&buffer.fecha.anio, "ingrese anio\n","error", 2000, 2020, 2) == OK &&
				seleccionarCliente(&buffer.idCliente, listCliente, 5) == OK
		){

			if(validarSerie(listElectro, tamElectro, buffer.serie) == OK){
				printf("se valido numero de serie correcto.\n");
				buffer.id = *id;
				list[index] = buffer;
				(*id)++;
				result = OK;
				printf ("Electro guardado con exito --> \n");
				printReparacion(&buffer);
			}else{
				printf("No es un numero de serie válido.\n");
			};

		};
	} else {
		result = noOK;
	};

	return result;
};


static int seleccionarCliente(int* idCliente, eCliente* list, int len){
	int result;

	if(list !=NULL && len > 0){

		printf("Seleccione el id de cliente: \n");
		mostrarListCliente(list, len);
		if(utn_getNumero(idCliente, "ingrese el id cliente", "error", 0, 4, 2) == 0){
			result = OK;
		} else {
			result = noOK;
		};
	} else {
		result = noOK;
	};
	return result;
};

int printReparacion(eReparacion* e){
	int result;

	if(e != NULL && e->id != -1){
		printf("ID	|SERIE		|IDSERVICIO	|FECHA\n");
		printf("%d	|%d		|%d		|%d/%d/%d\n", e->id, e->serie, e->idServicio, e->fecha.dia, e->fecha.mes, e->fecha.anio);
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int printListReparacion(eReparacion* list, int len){
	int i, result;

	if(list != NULL && len > 0){
		printf ("\n***Lista Electros***\n\n");
		for(i=0;i<len;i++){
				printReparacion(&list[i]);
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};


