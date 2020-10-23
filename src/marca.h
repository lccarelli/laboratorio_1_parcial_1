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
/**
 * @brief -> 	harcodearMarca //Llena la esctrutura marca de datos
 * @param ->	list		// eMarca* puntero a la estructura marca
 * @param -> 	tam			// int tamaño del array
 * @param -> 	cantidad	// int cantidad de datos a ingresar
 * @return ->	void		// No retorna
**/
void harcodearMarca(eMarca marcas[], int tam, int cantidad);
/**
 * @brief -> 	mostrarMarca //Muestra una marca
 * @param ->	e			// eMarca* puntero a la estructura marca, posicion dentro del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int mostrarMarca(eMarca* e);
/**
 * @brief -> 	mostrarListMarca //Muestra lista de marca
 * @param ->	list		// eMarca* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int mostrarListMarca(eMarca marcas[], int len);
