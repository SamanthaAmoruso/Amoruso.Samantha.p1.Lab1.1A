/*
 * empresa.h
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

typedef struct{
int id; //empieza en 1000
char descripcion[20];
int isEmpty;

}eEmpresa;

#endif /* EMPRESA_H_ */

int listarEmpresas(eEmpresa listaDeEmpresas[], int tam);

int CargarDescripEmpresa(eEmpresa listaDeEmpresas[], int tam, int id,char descripcion[]);
