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

/**
 * @brief -> 	validarSerie //BValida si el numero de de serie existe
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @param ->	serie			// int id buscado
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int validarSerie(eElectro* list, int tamElectro, int serie);
/**
 * @brief -> 	initElectro //INicializa el array
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int initElectro(eElectro* list, int len);
/**
 * @brief -> 	findEmptyElectro //Busca lugar vacio
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int findEmptyElectro(eElectro* list, int len);
/**
 * @brief -> 	addElectro //Agrega un nuevo electro
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @param ->	id			// int* puntero donde se va a guardar el ID dado de alta
 * @parama ->	index		// int posicion del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int addElectro(eElectro* list, int len, int* id, int index);
/**
 * @brief -> 	printElectro //Muestra un electro
 * @param ->	e			// eElectro* puntero a la posicion dentro del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int printElectro(eElectro* e);
/**
 * @brief -> 	printListElectro //Muestra lista de electro
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int printListElectro(eElectro* list, int len);
/**
 * @brief -> 	buscarElectro //Busca el index del elemento
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @param ->	id			// int id buscado
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int buscarElectro(eElectro* list, int len, int id);
/**
 * @brief -> 	modificarElectro //Modifica caracteristica del electro
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @parama ->	index		// int posicion del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int modificarElectro(eElectro* list, int len, int index);
/**
 * @brief -> 	darBajaElectro //Baja logica del electro
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @parama ->	index		// int posicion del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int darBajaElectro(eElectro* list, int len, int index);
/**
 * @brief -> 	listadoElectro //Reporte ordenado por modelo y serie
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int listadoElectro(eElectro* list, int len);
/**
 * @brief -> 	printElectroConID //Muestra lista de electro con ID
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int printElectroConID(eElectro* e);
/**
 * @brief -> 	printListElectroConId //Muestra lista de electro con ID
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int printListElectroConId(eElectro* list, int len);
