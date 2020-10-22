/*
 * utn.h
 *
 *  Created on: 28 sep. 2020
 *      Author: lau
 */

#ifndef UTN_H_INCLUDE
#define UTN_H_INCLUDE


#endif /* UTN_H_ */
/**
 * @brief ->	Input de un dato, devuelve un numero
 * @param ->	number // Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message // Es el mensaje a ser mostrado
 * @param ->	errorMessage // Es el mensaje de Error a ser mostrado
 * @param ->	min // Es el numero maximo a ser aceptado
 * @param ->	max // Es el minimo minimo a ser aceptado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getNumero(int* number, char* message, char* errorMessage, int min, int max, int retries);

int utn_getNumeroFlotante(float* number, char* message, char* errorMessage, float min, float max, int retries);
int utn_getString(char* string, int len,char* message, char* errorMessage, int retries);
