/*
 * tipo.h
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int idTipo; //arranca en 5 mil
	char descripcion[20];
	int isEmpty;
}eTipo;

int listarTipos(eTipo listaDeTipos[], int tamTipo);
/**
 * @fn funcion que lista todos los tipos
 * @brief Muestra un listado de los tipos
 *
 * @param El array de los tipos
 * @param Un entero, el tamaño del array de tipos
 * @return 1 si salio ok, 0 para el error
 *
 */

int CargardescripTipo(eTipo listaDeTipos[], int tam, int id,char descripcion[]);
/**
 * @fn cargamos la descripcion del tipo
 * @brief Carga en una cadena de caracteres el nombre del tipo que se pasa por id
 *
 * @param El array de tipos
 * @param Un entero, el tamaño del array de tipos
 * @return 1 si salio ok, 0 para el error
 *
 */

#endif /* TIPO_H_ */
