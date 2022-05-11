/*
 * viaje.c
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */
#include "viaje.h"
#include "tipo.h"
#include "destino.h"
#include "empresa.h"
#include "micro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define VACIO 0
#define OCUPADO 1

int inicializarViajes(eViaje listaDeViajes[], int tam)
{
   int retorno = 0;
   if(listaDeViajes != NULL && tam > 0)
   {
	   for(int i= 0; i < tam; i++)
	   {
		   listaDeViajes[i].isEmpty = VACIO;
		   retorno = 1;
	   }// fin del for

   }// fin del if

   return retorno;
}// fin de inicializar aviones

int buscarViajeLibre(eViaje listaDeViajes[], int tamListaViajes)
{
	int lugarLibre =-1;

	if(listaDeViajes != NULL && tamListaViajes > 0)
	{
		for(int i=0; i < tamListaViajes; i++)
		{
			if(listaDeViajes[i].isEmpty == VACIO)
			{
				lugarLibre = i;
				break;
			}// fin del if

		}// fin del for

	}// fin del if

return lugarLibre;
}// fin de buscar avion libre

int agregarViaje(eViaje listaDeViajes[], int tamListaViajes, eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD, int* idViaje)
{
	int todoOk=-1;
	int mimicro=0;
	int miDestino=0;
	int dia=0;
	int mes=0;
	int anio=0;
	int validacionFecha=0;
	int viajeLibre=0;
	eFecha auxFecha;

	viajeLibre = buscarViajeLibre(listaDeViajes, tamListaViajes);

	if (listaDeViajes!= NULL && tamListaViajes > 0 && listaDeMicros !=NULL && tamM > 0 && listaDeTipos!= NULL && tamTipo > 0
	  && listaDeEmpresas!=NULL && tamEmpresa > 0 && listaDeFechas!=NULL && tamF > 0 && listaDeDestinos !=NULL && tamD > 0 && viajeLibre > -1)
	{

		printf("ingrese el id del viaje al que quiere subirse\n");
		mostrarMicros(listaDeMicros,tamListaViajes, listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
		scanf("%d", &mimicro);
		while (listaDeViajes[viajeLibre].idMicro != mimicro && listaDeViajes[viajeLibre].isEmpty == VACIO)
		{
			printf("error ingrese un id de viaje exsistente\n");
			mostrarMicros(listaDeMicros,tamListaViajes, listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
			scanf("%d", &mimicro);
		}

		printf("ingrese el id del destino al que viaja \n");
		mostrarDestinos(listaDeDestinos, tamD);
		scanf("%d",&miDestino);
		while(miDestino < 20000 || miDestino > 20003)
		{
			printf("error, ingrese el id del destino al que viaja \n");
			mostrarDestinos(listaDeDestinos, tamD);
			scanf("%d",&miDestino);
		}

		printf("en que fecha quiere viajar? dd/mm/aaaa\n");
		scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
		validacionFecha=validarFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio);
		while (validacionFecha == 0)
		{
			printf("error,Ingrese una fecha valida dd/mm/aaaa\n");
			scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
			validacionFecha=validarFecha(dia,mes,anio);
		}

		listaDeViajes[viajeLibre].idMicro =mimicro;
		listaDeViajes[viajeLibre].idDestino=miDestino;
		listaDeViajes[viajeLibre].fecha.dia=auxFecha.dia;
		listaDeViajes[viajeLibre].fecha.mes=auxFecha.mes;
		listaDeViajes[viajeLibre].fecha.anio=auxFecha.anio;
		listaDeViajes[viajeLibre].id=*idViaje;
		(*idViaje)++;
		listaDeViajes[viajeLibre].isEmpty = OCUPADO;
		printf("\ningresaste correctamente el viaje\n\n");
		todoOk=0;

	}//fin del if
	else
	{
		printf("no hay viajes disponibles\n");
	}

return todoOk;
}//fin de la funcion agregar vuelos

int inicializarViajess(eViaje listaDeViajes[], int tamListaViajes)
{
   int retorno = 0;
   if(listaDeViajes != NULL && tamListaViajes > 0)
   {
	   for(int i= 0; i < tamListaViajes; i++)
	   {
		   listaDeViajes[i].isEmpty = VACIO;
		   retorno = 1;
	   }// fin del for

   }// fin del if

   return retorno;
}// fin de inicializar aviones

void CargarDescripcionDestino(eDestino listaDeDestinos[], int tamDestinos, int identificador, char descripcion[])
{
	if (listaDeDestinos !=NULL && tamDestinos > 0 && identificador > 0)
	{
		for(int i = 0; i< tamDestinos; i++)
		{
			if(listaDeDestinos[i].idDestino == identificador)
			{
				strcpy(descripcion,listaDeDestinos[i].descripcion);
				break;
			}

		}//fin for
	}//fin if null
}//fin void cargar

void mostrarViaje(eViaje unViaje,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD)

{
	char DescripcionDestino[20];

	CargarDescripcionDestino(listaDeDestinos, tamD, unViaje.idDestino, DescripcionDestino);

	printf(" %d %3d %d %s %5d %d %d ",unViaje.id, unViaje.idMicro, unViaje.idDestino,
			DescripcionDestino,unViaje.fecha.dia, unViaje.fecha.mes, unViaje.fecha.anio);

	printf("\n");

}// fin de mostrar vuelo

void mostrarViajes(eViaje listaDeViajes[], int tamListaViajes, eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
		eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD)
{
	int flag = 1;

	    if (listaDeViajes!= NULL && tamListaViajes > 0 && listaDeTipos !=NULL && tamTipo > 0 && listaDeDestinos!= NULL &&
	    		tamD > 0 && listaDeMicros!=NULL && tamM > 0 && listaDeFechas!=NULL && tamF > 0)
	    {

			printf("--------------- VUELOS INGRESADOS ------------------\n");
			printf("Id idAvion avion  precio  destino   fecha   \n");
			for(int i=0; i< tamListaViajes; i++)
			{
				if(listaDeViajes[i].isEmpty != VACIO)
				{
					mostrarViaje(listaDeViajes[i],listaDeMicros,tamM,listaDeTipos, tamTipo, listaDeEmpresas,tamEmpresa,
							listaDeFechas, tamF,listaDeDestinos, tamD);
				   flag = 0;
				}//fin if

			}//fin for
			if(flag == 1)
			{
				printf("No hay viajes ingresados\n");
			}

	    }//fin if null

}//fin mostrar vuelos


