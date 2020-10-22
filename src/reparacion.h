/*
 * reparacion.h
 *
 *  Created on: 14 oct. 2020
 *      Author: lau
 */

#ifndef REPARACION_H_
#define REPARACION_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id; //automático
	int serie; //valida con electro
	int idServicio; // valida servicio
	eFecha fecha; // (validar dia, mes y año)
}eReparacion;

#endif /* REPARACION_H_ */

int initReparacion(eReparacion* list, int len);
int findEmptyReparacion(eReparacion* list, int len);
int addReparacion(eReparacion* list, int len, int* id, int index);
int printReparacion(eReparacion* e);
int printListReparacion(eReparacion* list, int len);
