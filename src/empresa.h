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
/**
 * @fn muestra todos las empresas harcodeados
 * @brief Muestra un listado de los empresas
 *
 * @param El array de los empresas
 * @param Un entero, el tamaño del array de empresas
 * @return 1 si salio ok, 0 para el error
 *
 */

int CargarDescripEmpresa(eEmpresa listaDeEmpresas[], int tam, int id,char descripcion[]);
/**
 * @fn cargamos la descripcion de las empresas
 * @brief Carga en una cadena de caracteres el nombre de las empresas que se pasa por id
 *
 * @param El array de empresas
 * @param Un entero, el tamaño del array de empresas
 * @param un int id, donde validamos que el id equivalga a la empresas que cargamos
 * @param un char, donde almacenamos con un strcpy la carga de la empresas
 * @return 1 si salio ok, 0 para el error
 *
 */

int validarEmpresas(int id, eEmpresa empresas[], int tam);
/**
 * @fn valida empresas
 * @brief Muestra un listado de las empresas y buscamos que existan
 *
 * @param El array de los empresas
 * @param Un entero, el tamaño del array de empresas
 * @return 1 si salio ok, 0 para el error
 *
 */
