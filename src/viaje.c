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
#include "chofer.h"
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
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD,
eChofer listaDeChoferes[], int tamChofer, int* idViaje)
{
	int todoOk=-1;
	int mimicro=0;
	int miDestino=0;
	int validacionFecha=0;
	int viajeLibre=0;
	eFecha auxFecha;

	viajeLibre = buscarViajeLibre(listaDeViajes, tamListaViajes);

	if (listaDeViajes!= NULL && tamListaViajes > 0 && listaDeMicros !=NULL && tamM > 0 && listaDeTipos!= NULL && tamTipo > 0
	  && listaDeEmpresas!=NULL && tamEmpresa > 0 && listaDeFechas!=NULL && tamF > 0 && listaDeDestinos !=NULL && tamD > 0 && viajeLibre > -1)
	{

		printf("ingrese el id del viaje al que quiere subirse\n");
  		mostrarMicros(listaDeMicros,tamM, listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa,listaDeChoferes, tamChofer);
		scanf("%d", &mimicro);
		while (listaDeMicros[viajeLibre].id != mimicro && listaDeViajes[viajeLibre].isEmpty == VACIO)
		{
			printf("error ingrese un id de viaje exsistente\n");
	  		mostrarMicros(listaDeMicros,tamM, listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa,listaDeChoferes, tamChofer);
			scanf("%d", &mimicro);
		}

		printf("ingrese el id del destino al que viaja \n");
		listarDestinos(listaDeDestinos, tamD);
		scanf("%d",&miDestino);
		while(miDestino < 20000 || miDestino > 20003)
		{
			printf("error, ingrese el id del destino al que viaja \n");
			listarDestinos(listaDeDestinos, tamD);
			scanf("%d",&miDestino);
		}

		printf("en que fecha quiere viajar? dd/mm/aaaa\n");
		scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
		validacionFecha=validarFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio);
		while (validacionFecha == 0)
		{
			printf("error,Ingrese una fecha valida dd/mm/aaaa\n");
			scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
			validacionFecha=validarFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio);
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

void CargarDescripcionDestino(eDestino listaDeDestinos[], int tamDestinos, int identificador, char descripcion[], float* precio)
{
	if (listaDeDestinos !=NULL && tamDestinos > 0 && identificador > 0 && precio > 0)
	{
		for(int i = 0; i< tamDestinos; i++)
		{
			if(listaDeDestinos[i].idDestino == identificador)
			{
				strcpy(descripcion,listaDeDestinos[i].descripcion);
				(*precio) = listaDeDestinos[i].precio;
				break;
			}

		}//fin for
	}//fin if null
}//fin void cargar

void mostrarViaje(eViaje unViaje, eMicro listaDeMicros[], int tamM, eTipo listaDeTipos[], int tamTipo,
eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD)

{
	char DescripcionDestino[20];
	float precio;

	CargarDescripcionDestino(listaDeDestinos, tamD, unViaje.idDestino, DescripcionDestino, &precio);


	printf(" %d %3d %4s %.2f %5d %d %d ",unViaje.id, unViaje.idMicro,
			DescripcionDestino, precio, unViaje.fecha.dia, unViaje.fecha.mes, unViaje.fecha.anio);

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
			printf("Id  idmicro    destino   precio   fecha   \n");
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

void mostrarPorDestino(eViaje listaDeViajes[], int tamListaViajes ,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
		eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD)
{
    int opcion;

    printf("De que tipo de destino desea el listado?  20000.Calafate 20001.Bariloche 20002.Iguazu 20003.Mendoza\n");
    scanf("%d", &opcion);
    while(opcion < 20000 || opcion > 20004)
    {
        printf("error, De que tipo de destino desea el listado?  20000.Calafate 20001.Bariloche 20002.Iguazu 20003.Mendoza\n");
        scanf("%d", &opcion);
    }
    printf("ID   --idmicro--    id destino ----  destino  --- -----fecha\n");
    if(listaDeDestinos != NULL && tamD > 0 )
    {
        for(int i= 0; i < tamD; i++)
        {
            if(listaDeDestinos[i].idDestino == opcion)
            {
            	mostrarViaje(listaDeViajes[i],listaDeMicros,tamM,listaDeTipos, tamTipo, listaDeEmpresas,tamEmpresa,
            								listaDeFechas, tamF,listaDeDestinos, tamD);
            }
            else if(listaDeDestinos[i].idDestino != opcion)
			{
				printf("No hay este tipo de destino para mostrar\n");
				break;
			}
        }//fin for

    }//fin if null

}//fin void

void mostrarFechaNoviembre(eViaje listaDeViajes[], int tamListaViajes ,eMicro listaDeMicros[], int tamM,eTipo listaDeTipos[], int tamTipo,
		eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[], int tamF, eDestino listaDeDestinos[], int tamD)
{
	int flag = 1;
	if(listaDeViajes!= NULL && tamListaViajes > 0 && listaDeTipos !=NULL && tamTipo > 0 && listaDeDestinos!= NULL
			&& tamD > 0 && listaDeMicros!=NULL && tamM > 0 && listaDeFechas!=NULL && tamF > 0)
	{

		printf("---------------viajes con fecha de noviembre ------------------\n");
		printf("Id idmicro  destino precio  fecha   \n");
		for(int i=0; i< tamF; i++)
		{
			if(listaDeViajes[i].fecha.mes == 11)
			{
				mostrarViaje(listaDeViajes[i],listaDeMicros,tamM,listaDeTipos, tamTipo, listaDeEmpresas,tamEmpresa,
											listaDeFechas, tamF,listaDeDestinos, tamD);
				flag = 0;

			}//fin if
			if(flag == 1)
			{
				printf("no hay viajes en noviembre\n");
				break;
			}
		}//fin for

	}//fin if null

}//fin void

void MostrarViajesMismoAnio(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD)
{
	eFecha auxFecha;

	printf("elija un año entre 2001 y 2029 para listar\n");
	scanf("%d", &auxFecha.anio);

	while (auxFecha.anio < 2001 || auxFecha.anio > 2029)
	{
		printf("error,Ingrese un año valido entre 2001 y 2029 aaaa\n");
		scanf("%d",&auxFecha.anio);
	}
	int bandera = 1;

	if(listaDeViajes!= NULL && tamViaje > 0 && listaDeTipos !=NULL && tamTipo > 0 && listaDeDestinos!= NULL
		&& tamD > 0 && listaDeMicros!=NULL && tamM > 0 && listaDeFechas!=NULL && tamF > 0)
	{

			printf("---------------viajes con el mismo año ------------------\n");
			printf("Id idmicro   destino   precio  fecha   \n");
			for(int i=0; i< tamF; i++)
			{
				if(listaDeViajes[i].fecha.anio == auxFecha.anio)
				{
					mostrarViaje(listaDeViajes[i],listaDeMicros,tamM,listaDeTipos, tamTipo, listaDeEmpresas,
							tamEmpresa, listaDeFechas, tamF,listaDeDestinos, tamD);
					bandera = 0;

				}//fin if
				if(bandera == 1)
				{
					printf("no hay viajes en ese año\n");
					break;
				}
			}//fin for

	}//fin if null

}//fin de la funcion void

void MostrarViajesMismoDestino(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD)
{
	int miDestino;
	int bandera = 1;

	if(listaDeViajes!= NULL && tamViaje > 0 && listaDeTipos !=NULL && tamTipo > 0 && listaDeDestinos!= NULL
			&& tamD > 0 && listaDeMicros!=NULL && tamM > 0 && listaDeFechas!=NULL && tamF > 0)
	{
		printf("ingrese el id del destino al que viaja \n");
		listarDestinos(listaDeDestinos, tamD);
		scanf("%d",&miDestino);
		while(miDestino < 20000 || miDestino > 20003)
		{
			printf("error, ingrese el id del destino al que viaja \n");
			listarDestinos(listaDeDestinos, tamD);
			scanf("%d",&miDestino);
			bandera = -1;
		}

		printf("---------------viajes con el mismo destino ------------------\n");
		printf("IdViaje idmicro   destino   precio  fecha   \n");
		for(int i=0; i< tamD; i++)
		{
			if(listaDeViajes[i].idDestino == miDestino && listaDeViajes[i].isEmpty == OCUPADO)
			{
				mostrarViaje(listaDeViajes[i],listaDeMicros,tamM,listaDeTipos, tamTipo, listaDeEmpresas,
						tamEmpresa, listaDeFechas, tamF,listaDeDestinos, tamD);
				bandera = 0;

			}//fin if
			if(bandera == -1)
			{
				printf("no hay viajes que vayan al destino del id%d\n", miDestino);
				break;
			}
		}//fin for

	}//fin if null

}//fin funcion void

int encontrarViajePorId(eViaje listaDeViajes[],int tamViaje, int id)
{
    int indice = -1;
    if(listaDeViajes != NULL && tamViaje > 0)
    {
        for(int i= 0; i < tamViaje; i++)
        {
            if(listaDeViajes[i].id == id && listaDeViajes[i].isEmpty == OCUPADO)
            {
                indice = i;
                break;
            }//fin if

        }//fin for

    }//fin if NULL

return indice;
}//fin findPassengersByid

int harcodearViajes(eViaje listaDeViajes[],int tamViaje, int cant, int* pId)
{
    int contador=-1;
    int viajes=0;

    if(listaDeViajes!=NULL && tamViaje > 0 && cant>=0 && cant<=tamViaje && pId!=NULL)
    {

    int idMicro[5]={1,2,3,4,5};

    int idDestino[5]={20000, 20001, 20002, 20003, 20002};

    int fechasDia[5]= {11,23,4,9,23};

    int fechasMes[5]= {11,3,4,9,3};

    int fechasAnio[5]= {2019,2023,2024,2020,2023};

    int idViaje[5]={1,2,3,4,5};

    contador=1;

	for(int i=0; i<cant; i++)
	{
		viajes= encontrarViajePorId(listaDeViajes, tamViaje ,idMicro[i]);

		if(viajes==-1)
		{
			viajes= buscarViajeLibre(listaDeViajes, tamViaje);
		}

		listaDeViajes[viajes].idMicro = idMicro[i];
		listaDeViajes[viajes].idDestino = idDestino[i];
		listaDeViajes[viajes].fecha.dia = fechasDia[i];
		listaDeViajes[viajes].fecha.mes = fechasMes[i];
		listaDeViajes[viajes].fecha.anio = fechasAnio[i];
		listaDeViajes[viajes].id = idViaje[i];
		listaDeViajes[viajes].isEmpty= OCUPADO;
		contador++;

	}//fin for

  }//fin if null

return contador;
}

int mostrarViajesDeUnMicro(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
		eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
		int tamF, eDestino listaDeDestinos[], int tamD, eChofer listaDeChoferes[], int tamChofer)
{
    int todoOk = 0;
    int indice;
    int id;

    if(listaDeMicros != NULL && tamM > 0)
    {
        mostrarMicros(listaDeMicros, tamM, listaDeTipos, tamTipo, listaDeEmpresas, tamEmpresa,
        		listaDeChoferes, tamChofer);
        printf("------- Seleccione Micros para mostrar los viajes ----------\n\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = encontrarMicroPorId(listaDeMicros, tamM, id);

        if(indice == -1)
        {
            printf("El id %d no existe\n", id);
        }
        else
        {
            for(int i=0; i<tamM; i++)
            {
                if(listaDeViajes[i].isEmpty == OCUPADO && (listaDeViajes[i].idMicro == listaDeMicros[indice].id))
                {
                	mostrarViaje(listaDeViajes[i],listaDeMicros,tamM,listaDeTipos, tamTipo, listaDeEmpresas,
                							tamEmpresa, listaDeFechas, tamF,listaDeDestinos, tamD);
                }
            }//fin for

        }//fin else

    }//fin if null

return todoOk;
}//fin de la funcion


int mostrarSumaDelPrecioDeUnMicro(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
		eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
		int tamF, eDestino listaDeDestinos[], int tamD, eChofer listaDeChoferes[], int tamChofer)
{
    int todoOk = 0;
    int indice;
    int id;
    int bandera=0;
    float precio=0;
    float acumPrecio=0;
    char descripcion[25];

    if(listaDeMicros != NULL && tamM > 0)
    {
        mostrarMicros(listaDeMicros, tamM, listaDeTipos, tamTipo, listaDeEmpresas, tamEmpresa,
                		listaDeChoferes, tamChofer);
        printf("-----Seleccione un Micro para mostrar su Precio----\n\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = encontrarMicroPorId(listaDeMicros, tamM, id);

        if(indice == -1)
        {
            printf("El id %d no existe\n", id);
        }
        else
        {
            for(int i=0; i<tamM; i++)
            {
                if(listaDeViajes[i].isEmpty == OCUPADO && (listaDeViajes[i].idMicro == listaDeMicros[indice].id))
                {
                	CargarDescripcionDestino(listaDeDestinos, tamD, listaDeViajes[i].idDestino , descripcion, &precio);
                    acumPrecio += precio;
                    bandera=1;
                }
            }//fin for
        }//fin else

        if(bandera!=0)
        {
            printf("el precio de este micro es: %.2f\n", acumPrecio);
        }
        else
        {
            printf("Ocurrio un error\n");
        }

    }//fin if null

return todoOk;
}//fin de la funcion


void MostrarViajesMismaFecha(eViaje listaDeViajes[],int tamViaje ,eMicro listaDeMicros[],int tamM,
	eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa, eFecha listaDeFechas[],
	int tamF, eDestino listaDeDestinos[], int tamD)
{
	eFecha auxFecha;
	int validacionFecha;

	printf("en que fecha quiere viajar? dd/mm/aaaa\n");
	scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);

	validacionFecha = validarFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio);
	while (validacionFecha == 0)
	{
		printf("error,Ingrese una fecha valida dd/mm/aaaa\n");
		scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
		validacionFecha=validarFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio);
	}
	int bandera = 1;

	if(listaDeViajes!= NULL && tamViaje > 0 && listaDeTipos !=NULL && tamTipo > 0 && listaDeDestinos!= NULL
		&& tamD > 0 && listaDeMicros!=NULL && tamM > 0 && listaDeFechas!=NULL && tamF > 0)
	{

			printf("---------viajes con la misma fecha --------------\n");
			printf("Id  idmicro   destino   precio  fecha   \n");
			for(int i=0; i< tamF; i++)
			{
				if(listaDeViajes[i].fecha.dia == auxFecha.dia &&  listaDeViajes[i].fecha.mes == auxFecha.mes
						&& listaDeViajes[i].fecha.anio == auxFecha.anio && listaDeViajes[i].isEmpty == OCUPADO)
				{
					mostrarViaje(listaDeViajes[i],listaDeMicros,tamM,listaDeTipos, tamTipo, listaDeEmpresas,
							tamEmpresa, listaDeFechas, tamF,listaDeDestinos, tamD);
					bandera = 0;

				}//fin if
				if(bandera == 1)
				{
					printf("no hay viajes en esta fecha\n");
					break;
				}
			}//fin for

	}//fin if null

}//fin de la funcion void
