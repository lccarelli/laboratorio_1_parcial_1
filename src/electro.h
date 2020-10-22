/*
 * electrodomestico.h
 *
 *  Created on: 14 oct. 2020
 *      Author: lau
 */

#ifndef ELECTRO_H_
#define ELECTRO_H_


typedef struct{
	int id;
	int serie;
	int idMarca; //valida con marca
	int modelo; //año de fabricacion
	int isEmpty;
}eElectro;

#endif /* ELECTRO_H_ */

int validarSerie(eElectro* list, int tamElectro, int serie);
int initElectro(eElectro* list, int len);
int findEmptyElectro(eElectro* list, int len);
int addElectro(eElectro* list, int len, int* id, int index);
int printElectro(eElectro* e);
int printListElectro(eElectro* list, int len);
int buscarElectro(eElectro* list, int len, int id);
int modificarElectro(eElectro* list, int len, int index);
int darBajaElectro(eElectro* list, int len, int index);
int listadoElectro(eElectro* list, int len);
int printElectroConID(eElectro* e);
int printListElectroConId(eElectro* list, int len);
