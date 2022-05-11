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


void harcodearPrecioDestino(eDestino listaDeDestinos[], int tamanioListaDestino);
/**
 * @fn harcodear precio destino
 * @brief muestra el precio de los destinos en avion
 *
 * @param el array de lista de destinos
 * @param  el tamaño del array de destinos
 *
 */

void harcodearDestino(eDestino listaDeDestinos[], int tamanioListaDestino);
/**
 * @fn harcodear destinos
 * @brief harcodea destinos del viaje en avion
 *
 * @param el array de lista de destinos
 * @param  el tamaño del array de destinos
 *
 */

void mostrarDestinos(eDestino listaDeDestinos[], int tamDestino);
/**
 * @fn mostrar destinos
 * @brief muestra destinos del viaje del avion
 *
 * @param el array de lista de destinos
 * @param  el tamaño del array de destinos
 *
 */


#endif /* DESTINO_H_ */
