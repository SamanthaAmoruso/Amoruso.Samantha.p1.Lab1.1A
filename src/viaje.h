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


int agregarViaje(eViaje listaDeViajes[], int tamListaViajes, eMicro listaDeMicros[], int tamM,
eTipo listaDeTipos[], int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF,
eDestino listaDeDestinos[], int tamD, int* idViaje);

void mostrarViaje(eViaje unViaje,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);

void mostrarViajes(eViaje listaDeViajes[], int tamListaViajes, eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
		eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);


void CargarDescripcionDestino(eDestino listaDeDestinos[], int tamDestinos, int identificador, char descripcion[], float* precio);

void mostrarPorDestino(eViaje listaDeViajes[], int tamListaViajes ,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
		eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);

void mostrarFechaNoviembre(eViaje listaDeViajes[], int tamListaViajes ,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD);

void MostrarViajesMismoAnio(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD);

void MostrarViajesMismoDestino(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD);
