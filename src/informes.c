#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "servicio.h"
#include "reparacion.h"
#include "electro.h"
#include "cliente.h"
#include "informes.h"
#include "marca.h"


#define OK 0
#define noOK 1
#define ERROR -1
#define ID_SERVICIO "Ingrese idServicio: (20000) Garantia - (20001) Mantenimiento - (20002) Respuesto - (20003) Refaccion \n"
#define ID_MARCA "Ingrese idMarca: (1000) Wirpool (1001) Sony (1002)Liliana (1003) Gafa (1004)Philips\n"

void mostrarElectroModelo(eElectro* list, int modelo, int len){

	int i;

	if(list !=NULL && modelo > 0 && len > 0){

		for(i=0; i<len; i++){
			if(list[i].modelo == modelo){
				printElectro(&list[i]);
			};
		};
	};

};

void mostrarElectroMarcar(eElectro* list, int len){

	int i, aux;

	if(list !=NULL && len > 0){

		if(utn_getNumero(&aux, ID_MARCA, "error", 1000, 1004, 2) == 0) {
			printf("*****LISTADO DE ELECTROS MARCA****");

			for(i=0; i<len; i++){
				if(list[i].idMarca == aux){
					printElectro(&list[i]);
				};
			};
		} else {
			printf("estas ingresando un dato inválido. \n");
		};


	};

};

void reparacionesPorElectro(eReparacion* list, int len){
	int i, serie;

	printf("Busque reparaciones: \n");
	utn_getNumero(&serie, "ingrese numero de serie: \n", "error", 0, 1000000, 2);

	for(i=0; i<len; i++){

		if(list[i].serie == serie){
			printReparacion(&list[i]);
		};
	}
};

void electroSinRep(eReparacion* listRep, eElectro* listElectro, int lenElec, int lenRep){

	int i, j, aux;

	for(i=0; i<lenRep; i++){
		aux = listRep[i].serie;
		for(j=0; j<lenElec; j++){
			if(listElectro[j].serie != aux){
				printReparacion(&listRep[i]);
			}

		}
	}

};

void importeTotalReparacionesPorElectro(eReparacion* listRep, int tamRep, eElectro* listElec, eServicio* listSer, int tamElectro, int tamServicio){

	int electro, i, aux, j, auxServicio, h;
	float auxSuma = 0;

	utn_getNumero(&electro, "ingrese serie: \n", "error", 0, 100000, 2);

	if(validarSerie(listElec, tamElectro, electro)==OK){

		for(i=0; i<tamRep; i++){
			aux = listRep[i].serie;
			for(j=0; j<tamElectro; j++){
				if(listElec[j].serie == aux){
					auxServicio = listRep[i].idServicio;
					for(h=0; h<tamServicio; h++){
						if(listSer[h].id == auxServicio){
							auxSuma = auxSuma + listSer[h].precio;
							printReparacion(&listRep[j]);
						};
					};
				};
			};
		};
		printf("La suma de los importes de los servicios de reparacion es -> %.2f", auxSuma);
	};

};

void servicioMasPedido(eReparacion* rep, int tamRep){
	int i, contGarantia=0, contMantenimiento=0, contRepuesto=0, contRefaccion=0;

	for(i=0; i<tamRep; i++){

		 switch(rep[i].idServicio){

		 case 2000:
			 contGarantia++;
			 break;
		 case 2001:
			 contMantenimiento++;
			 break;
		 case 2002:
			 contRepuesto++;
			 break;
		 case 2003:
			 contRefaccion++;
		 };
	};

	if(contGarantia>contMantenimiento && contGarantia>contRefaccion && contGarantia>contRepuesto){
		printf("el servicio mas pedido es Garantia");
	}else if(contMantenimiento>contGarantia && contMantenimiento>contRefaccion && contMantenimiento>contRepuesto){
		printf("el servicio mas pedido es Mantenimiento");
	}else if (contRefaccion>contGarantia && contRefaccion>contMantenimiento && contRefaccion>contRepuesto) {
		printf("el servicio mas pedido es Refaccion");
	}else if (contRepuesto>contGarantia && contRepuesto>contMantenimiento && contRepuesto>contRefaccion){
		printf("el servicio mas pedido es Repuesto");
	};
};

void recaudacionPorFecha(eReparacion* rep, int tamRep){

	int dia, mes, anio, i;
	float sumFecha=0;

	utn_getNumero(&dia, "ingrese dia", "error", 1, 31, 2);
	utn_getNumero(&mes, "ingrese mes", "error", 1, 12, 2);
	utn_getNumero(&anio, "ingrese año", "error", 2000, 2020, 2);

	for(i=0; i<tamRep; i++){

		if(rep[i].fecha.dia==dia && rep[i].fecha.mes==mes && rep[i].fecha.anio==anio){

			switch(rep[i].idServicio){

			case 2000:
				 sumFecha = sumFecha + 250;
				 break;
			 case 2001:
				 sumFecha = sumFecha + 500;
				 break;
			 case 2002:
				 sumFecha = sumFecha + 400;
				 break;
			 case 2003:
				 sumFecha = sumFecha + 600;
			 };
		};
	};

};
