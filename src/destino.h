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
int CargardescripDestino(eDestino listaDeDestinos[], int tam, int id,char descripcion[]);


#endif /* DESTINO_H_ */
