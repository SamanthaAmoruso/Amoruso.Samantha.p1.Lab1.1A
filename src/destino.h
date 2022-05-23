/*
 * destino.h
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct{
int idDestino; //empieza en 20 mil
char descripcion[25];
float precio;
int isEmpty;

}eDestino;

int listarDestinos(eDestino listaDeDestinos[], int tam);
/**
 * @fn funcion que muestra todos los destinos
 * @brief Muestra un listado de los destinos
 *
 * @param El array de los destinos
 * @param Un entero, el tamaño del array de destinos
 * @return 1 si salio ok, 0 para el error
 *
 */

int CargardescripDestino(eDestino listaDeDestinos[], int tam, int id,char descripcion[]);
/**
 * @fn cargamos la descripcion del destino
 * @brief Carga en una cadena de caracteres el nombre del destino que se pasa por id
 *
 * @param El array de destinos
 * @param Un entero, el tamaño del array de destinos
 * @param un Id para validar que el id exista
 * @param un char, para hacer strcpy al nombre del destino y almacenarlo en la funcion
 * @return 1 si salio ok, 0 para el error
 *
 */

#endif /* DESTINO_H_ */
