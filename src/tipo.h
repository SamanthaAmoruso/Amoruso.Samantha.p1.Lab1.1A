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

int CargardescripTipo(eTipo listaDeTipos[], int tam, int id,char descripcion[]);

#endif /* TIPO_H_ */
