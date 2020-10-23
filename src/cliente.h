
#ifndef CLIENTE_H_INCLUDE
#define CLIENTE_H_INCLUDE

typedef struct{
	int id;
	char nombre[21];
	char apellido[21];
	int isEmpty;
}eCliente;


#endif /* CLIENTE_H_ */
/**
 * @brief -> 	harcodearCliente //Llena la esctrutura cliente de datos
 * @param ->	list		// eCliente* puntero a la estructura cliente
 * @param -> 	tam			// int tamaño del array
 * @param -> 	cantidad	// int cantidad de datos a ingresar
 * @return ->	void		// No retorna
**/
void harcodearCliente(eCliente* list, int tam, int cantidad);
/**
 * @brief -> 	mostrarCliente //Muestra un cliente
 * @param ->	e			// eCliente* puntero a la estructura cliente, posicion dentro del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int mostrarCliente(eCliente* e);
/**
 * @brief -> 	mostrarListCliente //Muestra lista de clientes
 * @param ->	list		// eCliente* se le pasa el array completo
 * @param ->	len			// int tamaño del array
 * @return ->	void		// Retorna OK -> 0, NO-OK-> 1
**/
int mostrarListCliente(eCliente* list, int len);
