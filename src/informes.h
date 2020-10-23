
#ifndef INFORMES_H_
#define INFORMES_H_

#endif /* INFORMES_H_ */

/**
 * @brief -> 	mostrarElectroModelo //Muestra lista de electro con un modelo en particular
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	modelo		// int año de fabrica
 * @param ->	len			// int tamaño del array
**/
void mostrarElectroModelo(eElectro* list, int modelo, int len);
/**
 * @brief -> 	mostrarElectroMarcar //Muestra lista de electro con un marca en particular
 * @param ->	list		// eElectro* se le pasa el array completo
 * @param ->	len			// int tamaño del array
**/
void mostrarElectroMarcar(eElectro* list, int len);
/**
 * @brief -> 	reparacionesPorElectro //MUestra las reparaciones por electro
 * @param ->	list		// eReparacion* se le pasa el array completo
 * @param ->	len			// int tamaño del array
**/
void reparacionesPorElectro(eReparacion* list, int len);
/**
 * @brief -> 	electroSinRep //Muestra electros sin reparaciones
 * @param ->	listRep		// eReparacion* se le pasa el array completo
 * @param ->	listElectro	// eElectro se le pasa el array completo
 * @param ->	lenElec			// int tamaño del array electro
 * @param ->	lenRep			// int tamaño del array Reparaciones
**/
void electroSinRep(eReparacion* listRep, eElectro* listElectro, int lenElec, int lenRep);
void importeTotalReparacionesPorElectro(eReparacion* listRep, int tamRep, eElectro* listElec, eServicio* listSer, int tamElectro, int tamServicio);
void servicioMasPedido(eReparacion* rep, int tamRep);
void recaudacionPorFecha(eReparacion* rep, int tamRep);
