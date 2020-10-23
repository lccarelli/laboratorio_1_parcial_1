/*
 ============================================================================
 Name        : Parcial_1.c
 Author      : robot
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "marca.h"
#include "servicio.h"
#include "electro.h"
#include "reparacion.h"
#include "cliente.h"
#include "informes.h"

#define SELECTION_1 1
#define SELECTION_2 2
#define SELECTION_3 3
#define SELECTION_4 4
#define SELECTION_5 5
#define SELECTION_6 6
#define SELECTION_7 7
#define SELECTION_8 8
#define SELECTION_9 9
#define TAM_ELECTRO 1000
#define TAM_REPARACION 1000
#define OK 0
#define noOK -1

int main(void) {
	setbuf(stdout, NULL);

	int option, answer, auxIndexElectro, idElectro, flagAddElectro = noOK, idToModify, indexElectro, auxIndexRep, idRep, flagAddRep=noOK;
	char seguir = 'n';

	eElectro electros[TAM_ELECTRO];
	eReparacion Reparaciones[TAM_REPARACION];
	eMarca marcas[5];
	eServicio servicios[4];
	eCliente clientes[5];

	harcodearMarca(marcas, 5, 5);
	harcodearServicios(servicios, 4, 4);
	harcodearCliente(clientes, 5, 5);

	if (initElectro(electros, TAM_ELECTRO) == 0) {
		printf("init electro\n");
	};

	if (initReparacion(Reparaciones, TAM_REPARACION) == 0) {
		printf("init reparaciones\n");
	};



	do {
		__fpurge(stdin);
		answer = utn_getNumero(
				&option,
				"****** MENU DE OPCIONES: *******\n "
				"Seleccione opción: "
				"\n\t1: ALTA ELECTRODOMESTICO "
				"\n\t2: MODIFICAR ELECTRODOMESTICO"
				"\n\t3: BAJA ELECTRODOMESTICO "
				"\n\t4: LISTAR ELECTRODOMESTICOS "
				"\n\t5: LISTAR MARCAS "
				"\n\t6: LISTAR SERVICIOS "
				"\n\t7: ALTA REPARACION "
				"\n\t8: LISTAR REPARACION "
				"\n\t9: INFORMES (2PARTE PARCIAL) "
				"\n\t10: 'Salir'\n",
				"No es una opción válida \n", 1, 9, 2);

		if (!answer) {

			switch (option) {

			case SELECTION_1:
				//ALTA ELECTRO
				do {

					auxIndexElectro = findEmptyElectro(electros, TAM_ELECTRO);

					if (auxIndexElectro >= 0) {
						addElectro(electros, TAM_ELECTRO, &idElectro, auxIndexElectro);

						printf("Quiere agregar un electro más?, ingrese -> (s)");
						__fpurge(stdin);
						scanf("%c", &seguir);
						flagAddElectro = OK;

					} else {
						printf("No hay más espacio para guardar");
					};

				} while (seguir == 's');

				break;

			case SELECTION_2:
				//MODIFICAR ELECTRODOMESTICO
				if (flagAddElectro == OK) {

					printListElectroConId(electros, TAM_ELECTRO);

					if (utn_getNumero(&idToModify, "Ingrese el Id a modificar", "ERROR", 0, idElectro, 2) == 0) {
						indexElectro = buscarElectro(electros, TAM_ELECTRO, idToModify);

						if(idToModify >= 0 && modificarElectro(electros, TAM_ELECTRO, indexElectro) == 0){
							printf("Modificacion exitosa.\n");
						} else {
							printf("Hubo un error con la modificacion.\n");
						};
					};

				} else {
					printf("Tiene que dar de alta algun electro para ultizar esta opción");
				};


				break;

			case SELECTION_3:
				//BAJA LOGICA DEL ELECTRODOMESTICO
				if (flagAddElectro == OK) {
					printListElectroConId(electros, TAM_ELECTRO);
					if (utn_getNumero(&idToModify, "Ingrese el Id a dar de baja",
							"ERROR", 0, idElectro, 2) == 0) {

						indexElectro = buscarElectro(electros, TAM_ELECTRO, idToModify);
						//printf("Esta seguro que desea dar de BAJA ? -> \n");
						//printEmployee(employees[index]);

						if (darBajaElectro(electros, TAM_ELECTRO, indexElectro) == 0) {
							printf("Se genero baja lógica del registro.\n");
						} else {
							printf("No se pudo generar la baja");
						};
					};

				} else {
					printf(
							"Tiene que dar de alta algun electro para ultizar esta opción");
				}
				;
				break;


				break;
			case SELECTION_4:
				//LISTAR ELECTRODOMESTICOS
				if(flagAddElectro == OK){
					listadoElectro(electros, TAM_ELECTRO);
					printListElectro(electros, TAM_ELECTRO);
				} else {
					printf("No hay electro a mostrar");
				};
				break;

			case SELECTION_5:
				//LISTAR MARCAS
				mostrarListMarca(marcas, 5);
				break;
			case SELECTION_6:
				//LISTAR SERVICIOS
				mostrarListServicio(servicios, 4);
				break;
			case SELECTION_7:
				//ALTA REPARACION

				do {

					auxIndexRep = findEmptyReparacion(Reparaciones, TAM_REPARACION);

					if (auxIndexRep >= 0) {
						addReparacion(Reparaciones, TAM_ELECTRO, &idRep, auxIndexRep, clientes, electros, TAM_ELECTRO);

						printf("Quiere agregar una reparacion más?, ingrese -> (s)");
						__fpurge(stdin);
						scanf("%c", &seguir);
						flagAddRep = OK;

					} else {
						printf("No hay más espacio para guardar");
					};

				} while (seguir == 's');

				break;

				break;
			case SELECTION_8:
				//LISTAR REPARACION

				if(flagAddRep == OK){
					printListReparacion(Reparaciones, TAM_REPARACION);
				}else{
					printf("No hay reparaciones para mostrar");
				};
				break;
			case SELECTION_9:
				//LISTAR REPARACION

				if(flagAddRep == OK && flagAddElectro == OK){

					printf("1- Mostrar Electrodomésticos del año(nodelo) 2020\n");
					mostrarElectroModelo(electros, 2020, TAM_ELECTRO);
					printf("2- Mostrar Electrodomésticos de una marca seleccionada\n");
					mostrarElectroMarcar(electros, TAM_ELECTRO);
					printf("3- Mostrar todos las reparaciones efectuadas al Electrodoméstico seleccionado\n");
					reparacionesPorElectro(Reparaciones, TAM_REPARACION);
					printf("4- Listar los Electrodomésticos que no tuvieron reparaciones\n");
					electroSinRep(Reparaciones, electros, TAM_ELECTRO, TAM_REPARACION);
					printf("5- Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado\n");
					importeTotalReparacionesPorElectro(Reparaciones, TAM_REPARACION, electros, servicios, TAM_ELECTRO, 4);
					printf("6- Mostrar el servicio más pedido\n");
					servicioMasPedido(Reparaciones, TAM_REPARACION);
					printf("7- Mostrar la recaudación en una fecha en particular\n");
					recaudacionPorFecha(Reparaciones, TAM_REPARACION);
				}else{
					printf("No hay reparaciones para mostrar");
				};
				break;

			}
		};

	} while (option != 10);

	printf("Saliste!");
	return EXIT_SUCCESS;
}
