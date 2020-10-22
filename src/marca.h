/*
 * marca.h
 *
 *  Created on: 14 oct. 2020
 *      Author: lau
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id; //comienza en 1000
	char descripcion[20];
}eMarca;

#endif /* MARCA_H_ */

void harcodearMarca(eMarca marcas[], int tam, int cantidad);
int mostrarMarca(eMarca* e);
int mostrarListMarca(eMarca marcas[], int len);
