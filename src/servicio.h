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
/**
 * @brief -> 	harcodearServicios //Llena la esctrutura servicio de datos
 * @param ->	list		// eServicio* puntero a la estructura servicio
 * @param -> 	tam			// int tamaño del array
 * @param -> 	cantidad	// int cantidad de datos a ingresar
 * @return ->	void		// No retorna
**/
void harcodearServicios(eServicio* list, int tam, int cantidad);
/**
 * @brief -> 	mostrarServicio //Muestra un servicio
 * @param ->	e			// eServicio* puntero a la estructura servicio, posicion dentro del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int mostrarServicio(eServicio* e);
/**
 * @brief -> 	mostrarListServicio //Muestra lista de servicio
 * @param ->	list		// eServicio* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int mostrarListServicio(eServicio* list, int len);
