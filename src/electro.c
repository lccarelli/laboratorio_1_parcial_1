#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "electro.h"

#define OK 0
#define noOK 1
#define ERROR -1
#define ID_MARCA "Ingrese idMarca: (1000) Wirpool (1001) Sony (1002)Liliana (1003) Gafa (1004)Philips\n"
#define MODIFY_MENU "Seleccione que campo quiere modificar: \n\t1) SERIE \n\t2) MODELO \n\t3) SALIR DE MODO EDICION \n"
#define SERIE 1
#define MODELO 2
#define BAJA -99

int validarSerie(eElectro* list, int tamElectro, int serie){
	int result;

	if(list!=NULL && tamElectro>0 && serie>0){
		for(int i=0; i<tamElectro; i++){
			if(list[i].serie == serie){
				result = OK;
			} else {
				result = noOK;
			};
		};
	} else {
		result = ERROR;
	};
	return result;
};

int initElectro(eElectro* list, int len){
	int i, result;
	if(list != NULL && len > 0){
		for(i=0;i<len;i++){
			list[i].isEmpty = 1;
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int findEmptyElectro(eElectro* list, int len){
	int i, result;
	if(list != NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == 1){
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

int addElectro(eElectro* list, int len, int* id, int index){
	int result;
	eElectro buffer;

	if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL){

		__fpurge(stdin);

		if(
				utn_getNumero(&buffer.serie, "Ingrese serie:(1 - 100000)\n", "Error -> ingreso un caracter no váido\n",1,100000, 2) == OK &&
				utn_getNumero(&buffer.idMarca, ID_MARCA, "Error -> debe ingresar id válido\n", 1000, 1004, 2) == OK &&
				utn_getNumero(&buffer.modelo, "ingrese el año de fabricacion\n", "error", 1900, 2020, 2) == OK
		){
			buffer.id = *id;
			buffer.isEmpty = 0;
			list[index] = buffer;
			(*id)++;
			result = OK;
			printf ("Electro guardado con exito --> \n");
			printElectro(&buffer);
		};
	} else {
		result = noOK;
	};

	return result;
};

int printElectro(eElectro* e){
	int result;

	if(e != NULL && e->isEmpty == 0){
		printf("|SERIE		|IDMARCA	|MODELO\n");
		printf("|%d		|%d		|%d		\n", e->serie, e->idMarca, e->modelo);
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};
int printElectroConID(eElectro* e){
	int result;

	if(e != NULL && e->isEmpty == 0){
		printf("ID	|SERIE		|IDMARCA	|MODELO\n");
		printf("%d	|%d		|%d		|%d		\n", e->id, e->serie, e->idMarca, e->modelo);
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int printListElectro(eElectro* list, int len){
	int i, result;

	if(list != NULL && len > 0){
		printf ("\n***Lista Electros***\n\n");
		for(i=0;i<len;i++){
				printElectro(&list[i]);
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int printListElectroConId(eElectro* list, int len){
	int i, result;

	if(list != NULL && len > 0){
		printf ("\n***Lista Electros***\n\n");
		for(i=0;i<len;i++){
				printElectroConID(&list[i]);
		};
		result = OK;
	} else {
		result = noOK;
	};
	return result;
};

int buscarElectro(eElectro* list, int len, int id){
	int i, result;

	if(list != NULL && len > 0 && id >= 0){
		result = 0;
		for(i=0;i<len;i++){
			if(list[i].id == id){
				result = i;
				printElectro(&list[result]);
				break;
			};
		};
	} else {
		result = noOK;
	};
	return result;
};

int modificarElectro(eElectro* list, int len, int index){
	int result, optionModify;
		eElectro buffer;

		if(list != NULL && len > 0 && index >=0 && list[index].isEmpty == 0){

			do {

				if((utn_getNumero(&optionModify, MODIFY_MENU, "error", 1, 3, 2)) == OK){

					switch(optionModify){

					case SERIE:
						if((utn_getNumero(&buffer.serie, "Ingrese NUEVO serie (1 - 100000): \n", "Error -> Ingrese un valor válido\n", 1, 100000, 2)) == OK){
							list[index].serie = buffer.serie;
							printf("Se modifico SERIE del registro -> \n");
							printElectro(&list[index]);
							result = OK;
						};
						break;

					case MODELO:
						if((utn_getNumero(&buffer.modelo, "Ingrese NUEVO modelo: \n", "Error -> Ingrese un valor válido\n", 1900, 2020, 2)) == OK){
							list[index].modelo = buffer.modelo;
							printf("Se modifico MODELO del registro -> \n");
							printElectro(&list[index]);
							result = OK;
						};
						break;

					};
				}

			} while(optionModify != 3);

		} else {
			result = noOK;
		};

		return result;
};

int darBajaElectro(eElectro* list, int len, int index){
	int result;

	if(list!=NULL && len>0 && index>=0 && list[index].isEmpty == 0){
		list[index].isEmpty = 1;
		printf("se dio la baja logica de ->");
		printElectro(&list[index]);
		result = OK;
	}else {result = noOK;};

	return result;
};

int listadoElectro(eElectro* list, int len){

	eElectro buffer, buffererie;
	int i, result;

	if(list != NULL && len > 0){

			for(i=0; i<len-1; i++){
				if(list[i].isEmpty || list[i+1].isEmpty){continue;};

				if(list[i].modelo>list[i+1].modelo){
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1] = buffer;
				};


		};
			for(i=0; i<len-1;i++){

				if(list[i].modelo == list[i+1].modelo){
					if(list[i].serie > list[i+1].serie){
						buffererie = list[i];
						list[i] = list[i+1];
						list[i+1] = buffererie;
					};
				};
			};

		result = OK;

	} else {
		result = noOK;
	};

	return result;
};


