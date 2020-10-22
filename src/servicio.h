/*
 * servicio.h
 *
 *  Created on: 14 oct. 2020
 *      Author: lau
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id; //comienza en 20000
	char descripcion[25];
	float precio;
}eServicio;

#endif /* SERVICIO_H_ */

void harcodearServicios(eServicio servicios[], int tam, int cantidad);
int mostrarServicio(eServicio* e);
int mostrarListServicio(eServicio* list, int len);
