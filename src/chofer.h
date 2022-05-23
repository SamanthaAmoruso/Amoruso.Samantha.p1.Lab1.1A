/*
 * chofer.h
 *
 *  Created on: 21 may. 2022
 *      Author: User
 */

#ifndef CHOFER_H_
#define CHOFER_H_

typedef struct
{
    int id;
    char nombre[25];
    char sexo;

}eChofer;

#endif /* CHOFER_H_ */

int mostrarChoferes(eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn muestra todos los choferes harcodeados
 * @brief Muestra un listado de los choferes
 *
 * @param El array de los choferes
 * @param Un entero, el tamaño del array de choferes
 * @return 1 si salio ok, 0 para el error
 *
 */

int validarChofer(int id, eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn valida choferes
 * @brief Muestra un listado de los choferes y buscamos que existan
 *
 * @param El array de los choferes
 * @param Un entero, el tamaño del array de choferes
 * @return 1 si salio ok, 0 para el error
 *
 */

int cargarNombreChofer(eChofer listaDeChoferes[], int tamChofer, int idChofer, char nombre[]);
/**
 * @fn cargamos la descripcion del chofer
 * @brief Carga en una cadena de caracteres el nombre del chofer que se pasa por id
 *
 * @param El array de choferes
 * @param Un entero, el tamaño del array de choferes
 * @param un int id, donde validamos que el id equivalga al nombre que cargamos
 * @param un char, donde almacenamos con un strcpy la carga del nombre
 * @return 1 si salio ok, 0 para el error
 *
 */
