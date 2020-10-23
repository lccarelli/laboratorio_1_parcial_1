#include "cliente.h"
#include "electro.h"

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
	int idServicio;// valida servicio
	eFecha fecha; // (validar dia, mes y año)
	int idCliente;
}eReparacion;

#endif /* REPARACION_H_ */

/**
 * @brief -> 	initReparacion //INicializa el array
 * @param ->	list		// eReparacion* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int initReparacion(eReparacion* list, int len);
/**
 * @brief -> 	findEmptyReparacion //Busca lugar vacio
 * @param ->	list		// eReparacion* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int findEmptyReparacion(eReparacion* list, int len);
/**
 * @brief -> 	addReparacion //Agrega una reparacion
 * @param ->	list		// eReparacion* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @param ->	id			// int* puntero donde se va a guardar el ID dado de alta
 * @param ->	index		// int posicion del array
 * @param ->	listCliente	// eCliente* puntero del listado de clientes
 * @param ->	listElectro	// eElectro* puntero del listado de clientes
 * @param ->	tamElectro	// int tamaño de electro
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int addReparacion(eReparacion* list, int len, int* id, int index, eCliente* listCliente, eElectro* listElectro, int tamElectro);
/**
 * @brief -> 	printReparacion //Muestra una reparacion
 * @param ->	e			// eReparacion* puntero a la posicion dentro del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int printReparacion(eReparacion* e);
/**
 * @brief -> 	printListReparacion //Muestra lista de reparaciones
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int printListReparacion(eReparacion* list, int len);

