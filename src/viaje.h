/*
 * viaje.h
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */

#ifndef VIAJE_H_
#define VIAJE_H_
#include "fecha.h"
#include "tipo.h"
#include "destino.h"
#include "empresa.h"
#include "micro.h"

typedef struct{

	int id;
	int idMicro; //(debe existir) Validar
	int idDestino; // (debe existir) Validar
	eFecha fecha; //(Validar día, mes y año)
	int isEmpty;
}eViaje;


#endif /* VIAJE_H_ */

int inicializarViajes(eViaje listaDeViajes[], int tam);
/**
 * @fn esta funcion inicializa al viaje
 * @brief al inicializarlo ya sabemos que tenemos un viaje en lista
 *
 * @param el array de lista de viaje
 * @param  el tamaño del array de viaje
 * @return 1 si inicializo y 0 si no se pudo
 */

int buscarViajeLibre(eViaje listaDeViajes[], int tamListaViajes);
/**
 * @fn esta funcion hace la busqueda de un lugar libre para ingresar viaje
 * @brief busca si hay espacios libres para ingresar mas viajes
 *
 * @param el array de lista de viajes
 * @param  el tamaño del array de viajes
 * @return i si encuentra libres y -1 si hubo error
 */


int agregarViaje(eViaje listaDeViajes[], int tamListaViajes, eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD,
eChofer listaDeChoferes[], int tamChofer, int* idViaje);
/**
 * @fn esta funcion hace cargar a los micros
 * @brief muestra una lista con los micros que se cargaron
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el identificador de los micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 * @param un puntero id que se suma por cada viaje hecho
 * @return -1 para el error, 0 todoOK
 */

void mostrarViaje(eViaje unViaje,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);
/**
 * @fn mostrar un viaje
 * @brief muestra la lista de un viaje
 *
 * @param el array de lista del micro
 * @param  el tamaño del array del micro
 * @param el array de lista del viaje
 * @param  el tamaño del array del viaje
 * @param el array de lista de empresa
 * @param el tamaño del array de empresa
 * @param el array de lista de tipo
 * @param el tamaño del array de tipo
 * @param el array de lista de fecha
 * @param el tamaño del array de fecha
 * @param el array de lista de destino
 * @param el tamaño del array de destino
 */

void mostrarViajes(eViaje listaDeViajes[], int tamListaViajes, eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
		eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);
/**
 * @fn mostrar viajes
 * @brief muestra la lista de los viajes
 *
 * @param el array de lista del micros
 * @param  el tamaño del array del micros
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 */


void CargarDescripcionDestino(eDestino listaDeDestinos[], int tamDestinos, int identificador, char descripcion[], float* precio);
/**
 * @fn cargamos la descripcion del destino
 * @brief Carga en una cadena de caracteres el nombre del destino que se pasa por id
 *
 * @param El array de destinos
 * @param Un entero, el tamaño del array de destinos
 * @param un id donde validamos que exista
 * @param un char, descripcion, donde hacemos un strcpy
 * @param un puntero flotante, para guardar el valor del precio
 */

void mostrarPorDestino(eViaje listaDeViajes[], int tamListaViajes ,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
		eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);
/**
 * @fn esta funcion muestra X destino segun el usuario
 * @brief Pide al usuario un tipo de destino, muestra un listado de los viajes de ese destino.
 *
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 */


void mostrarFechaNoviembre(eViaje listaDeViajes[], int tamListaViajes ,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);
/**
 * @fn esta funcion muestra todos los viajes que se hicieron en el mes de noviembre
 * @brief Pide al usuario que ingrese una fecha , si esta fecha es 11 (noviembre) los guarda e imprime
 *
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 */

void MostrarViajesMismoAnio(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD);
/**
 * @fn esta funcion muestra todos los viajes que se hicieron en el mismo anio
 * @brief Pide al usuario que ingrese un anio , si hay viajes en el anio elegido los muestra
 *
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 */

void MostrarViajesMismoDestino(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD);
/**
 * @fn esta funcion muestra todos los viajes que viajan al mismo destino
 * @brief Pide al usuario que ingrese un destino , si hay viajes que vayan a ese destino, los muestra
 *
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 */

int harcodearViajes(eViaje listaDeViajes[],int tamViaje, int cant, int* pId);
/**
 * @fn funcion que harcodea 5 viajes
 * @brief esta funcion harcodea automaticamente 5 viajes
 *
 * @param el array de lista de viajes
 * @param  el tamaño del array de viajes
 * @param un int la cantidad de viajes que se mostraran harcodeados
 * @param un puntero id
 * @return 1 si mostro la lista y -1 si hubo error
 */

int mostrarViajesDeUnMicro(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
		eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
		int tamF, eDestino listaDeDestinos[], int tamD, eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn esta funcion muestra todos los viajes que puede hacer x micro
 * @brief Pide al usuario que ingrese un micro , si hay viajes con ese micro los muestra
 *
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 * @return 1 si esta ok, 0 para el error
 */


int mostrarSumaDelPrecioDeUnMicro(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
		eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
		int tamF, eDestino listaDeDestinos[], int tamD, eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn esta funcion muestra la suma del precio de un micro
 * @brief Pide al usuario que ingrese un micro , si hay viajes con ese micro muestra su precio
 *
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 * @return 1 si esta ok, 0 para el error
 */

void MostrarViajesMismaFecha(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD);
/**
 * @fn esta funcion muestra la viajes en la misma fecha
 * @brief Pide al usuario que ingrese dia mes y anio , si hay viajes su misma fecha los muestra
 *
 * @param el array de lista del viajes
 * @param  el tamaño del array del viajes
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de fechas
 * @param el tamaño del array de fechas
 * @param el array de lista de destinos
 * @param el tamaño del array de destinos
 * @return 1 si esta ok, 0 para el error
 */

