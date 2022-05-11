/*
 * micro.c
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VACIO 0
#define OCUPADO 1
#include "tipo.h"
#include "destino.h"
#include "fecha.h"
#include "empresa.h"
#include "micro.h"
#include "viaje.h"

int inicializarMicros(eMicro listaDeMicros[], int tam)
{
   int retorno = 0;
   if(listaDeMicros != NULL && tam > 0)
   {
	   for(int i= 0; i < tam; i++)
	   {
		   listaDeMicros[i].isEmpty = VACIO;
		   retorno = 1;
	   }// fin del for

   }// fin del if

   return retorno;
}// fin de inicializar aviones

int menu ()
{
    int opcion;

    printf(" 1.Alta de un pasajero\n");
    printf(" 2.Modificacion de un pasajero\n");
    printf(" 3.Baja de un pasajero\n");
    printf(" 4.Listar micros\n");
    printf(" 5.Listar Empresas\n");
    printf(" 6.Listar Tipos\n");
    printf(" 7.Listar Destinos\n");
    printf(" 8.Alta viaje\n");
    printf(" 9.Listar viajes\n");
    printf(" 10.Salir del menu\n");
    printf("-----------------------------------------\n");

    printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

return opcion;
}// fin del menu

int menuOrdenar ()
{
    int opcion;

    printf("1) Listado de micros ordenados ascendente por empresa y capacidad \n");
	printf("2) Listado de micros ordenados descendente por empresa y capacidad\n");
    printf("3).Salir del menu\n");
    printf("-----------------------------------------\n");

    printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

return opcion;
}// fin del menu

int menuModificaciones()
{
    int opcion;

    printf(" 1.Modificar tipo\n");
    printf(" 2.Modificar capacidad\n");
    printf(" 3.Salir\n");
    printf("-----------------------------------------\n");

    printf("\n Elija una opcion: ");
	scanf("%d", &opcion);

return opcion;
}

int buscarLibre(eMicro listaDeMicros[], int tam)
{
	int lugarLibre =-1;
	if(listaDeMicros != NULL && tam > 0)
	{
		for(int i=0; i < tam; i++)
		{
			if(listaDeMicros[i].isEmpty == VACIO)
			{
				lugarLibre = i;
				break;
			}// fin del if

		}// fin del for

	}// fin del if

return lugarLibre;
}// fin de buscar libre

int buscarPasajero(eMicro listaDeMicros[], int tam, int identificador)
{
	int indice = -1;
	if (listaDeMicros != NULL && tam > 0)
	{
	   for (int i=0; i< tam; i++)
	   {
		   if (listaDeMicros[i].id && listaDeMicros[i].isEmpty)
		   {
			   indice = i;
			   break;
		   }// fin del if

	   }// fin del for

	}// fin del if
 return indice;
} // fin de buscaPasajero


int altamicro(eMicro listaDeMicros[], int tam, int* identificador)
{
	int todoOk = -1;
    int libre;
    int aux=0;

    libre = buscarLibre(listaDeMicros, tam);

    if(listaDeMicros != NULL && tam > 0 && libre > -1)
    {
    	for(int i = 0; i<tam; i++)
    	{
			if(listaDeMicros[i].isEmpty == VACIO)
			{
					printf("ingrese el tipo de micro: 5001.Comun 5002.CocheCama 5003.Doble 50004.Vip\n");
				    fflush(stdin);
				    scanf("%d",&aux);
				    while(aux < 5001 || aux > 5004 )
				    {
						printf("error,ingrese el tipo de micro: 5001.Comun 5002.CocheCama 5003.Doble 50004.Vip\n");
						fflush(stdin);
						scanf("%d",&aux);
				    }
					listaDeMicros[i].idTipo = aux;

				    printf("ingrese la empresa con la que desea viajar 1001.Plusmar 1002.Flecha Bus 1003.Tas 1004.El Rapido: \n");
					fflush(stdin);
					scanf("%d",&aux);
					while(aux < 1001 || aux > 1004 )
					{
						printf("error, ingrese la empresa con la que desea viajar 1001.Plusmar 1002.Flecha Bus 1003.Tas 1004.El Rapido: \n");
						fflush(stdin);
						scanf("%d",&aux);
					}
					listaDeMicros[i].idEmpresa = aux;

					printf("ingrese la capacidad que tendra el micro\n");
					fflush(stdin);
					scanf("%d",&aux);
                    while (aux < 0 || aux > 50 )
                    {
                    	printf("reingrese, debe tener entre 1 a 50 espacios: \n");
                    	scanf("%d",&aux);
                    }
                    listaDeMicros[i].capacidad = aux;

				listaDeMicros[libre].id = *identificador;
				(*identificador) ++;

				listaDeMicros[i].isEmpty = OCUPADO;
				printf("\ningresaste correctamente al pasajero\n\n");
				todoOk = 0;
				break;

			}// fin del if del vacio

		}// fin del for

    }// fin del if del null
    else
    {
    	printf("\nUsted llego al limite de micros que puede ingresar \n");
    }

return todoOk;
}// fin de cargar pasajeros

int sonLetras(char cadena[])
{
    int todoOk= -1;
    int longitud = strlen(cadena);

      for(int i= 0; i < longitud; i++)
      {
          if((cadena[i] > 64 && cadena[i] < 91) || (cadena[i] > 96 && cadena[i] < 123))
          {
              todoOk= 1;
          }// fin del if

      }// fin del for

// devuelve 1 si son letras, devuelve -1 si son numeros

return todoOk;
}// fin de la funcion sonLetras

void mostrarMicro(eMicro unMicro,eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa)
{
    char descripTipo[20];
    char DescripcionEmpresa[20];

    CargardescripTipo(listaDeTipos, tamTipo, unMicro.idTipo ,descripTipo);
    CargarDescripEmpresa(listaDeEmpresas, tamEmpresa, unMicro.idEmpresa , DescripcionEmpresa);

    printf(" %d %12s %10s  %10d", unMicro.id, DescripcionEmpresa, descripTipo, unMicro.capacidad);

    printf("\n");
}

int mostrarMicros(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa)
{
	int retorno = -1;

	if(listaDeMicros != NULL && tam > 0 && listaDeTipos !=NULL && tamTipo > 0 && listaDeEmpresas !=NULL && tamEmpresa >0)
	{
		 printf("-------------------------- LISTA DE MICROS ------------------\n");
	     printf("ID   ----    idEmpresa  -----   idTipo   ------  capacidad \n");
	     printf("----------------------------------------------------------------\n");

		for(int i=0; i<tam; i++)
		 {
			if(listaDeMicros[i].isEmpty == OCUPADO)
			{
				mostrarMicro(listaDeMicros[i],listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
				retorno = 1;
			}// fin del if

		 }// fin del for

	}// fin del if del NULL
	else
	{
		printf("no se puede mostrar la lista\n");
	}

return retorno;
} // fin de mostrar Pasajeros

int bajaMicro(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa)
{
	int todoOk = -1;
	int auxiliarBaja =0;
	if(listaDeMicros != NULL && tam > 0)
	{
		mostrarMicros(listaDeMicros,tam, listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
		printf("Ingrese el ID del micro que desea dar de baja: ");
		scanf("%d", &auxiliarBaja);
		if (auxiliarBaja > tam)
		{
		  printf("el id supera el tamaño maximo, ingrese nuevamente\n ");
		}

		if (auxiliarBaja <= tam)
		{
			 for(int i = 0 ; i < tam; i++)
			 {
				if(listaDeMicros[i].isEmpty != VACIO && listaDeMicros[i].id == auxiliarBaja)
				{
					listaDeMicros[i].isEmpty= VACIO;
					printf("se dio de baja con exito su micro\n");
					todoOk = 0;
				}// fin del if

			 }// fin del for

		} // if inventado

	}// fin if NULL

return todoOk;
}// fin de baja del avion

int ordenarMicros(eMicro listaDeMicros[],int tam, int orden)
{
    int todoOk = 0;
    eMicro auxiliar;

    if(listaDeMicros !=NULL && tam > 0)
    {
    	if (orden == 1) // ascendente
    	{
    		for (int i = 0; i < tam - 1; i++)
    		{
    			for (int j = i + 1; j < tam; j++)
				{
					if (listaDeMicros[i].idEmpresa > listaDeMicros[j].idEmpresa  || (listaDeMicros[i].idEmpresa >= listaDeMicros[j].idEmpresa
							&& (listaDeMicros[i].capacidad > listaDeMicros[j].capacidad)))
					{
						   auxiliar = listaDeMicros[i];
						   listaDeMicros[i] = listaDeMicros[j];
						   listaDeMicros[j] = auxiliar;
						   todoOk = 1;
					}// fin del if

				}// fin del segundo for

    		}// fin del primer for

    	}// fin del orden 1

    	if (orden == 0) // descendente
    	{
    		for(int i= 0; i < tam -1; i++)
			{
				for(int j= i+1; j < tam; j++)
				{
					if(listaDeMicros[i].idEmpresa < listaDeMicros[j].idEmpresa || (listaDeMicros[i].idEmpresa >= listaDeMicros[j].idEmpresa
							 && (listaDeMicros[i].capacidad < listaDeMicros[j].capacidad)))
					{
						auxiliar = listaDeMicros[i];
					    listaDeMicros[i] = listaDeMicros[j];
					    listaDeMicros[j] = auxiliar;
					   todoOk = 0;
					}// fin del if

				}// segundo for

    		  }// primer for

		}// fin del orden 0

    }// fin del if que pone !=NULL

return todoOk;
}// fin de la funcion ordenar

int encontrarMicroPorId(eMicro listaDeMicros[], int tam, int id)
{
    int indice = -1;
    if(listaDeMicros != NULL && tam > 0)
    {
        for(int i= 0; i < tam; i++)
        {
            if(listaDeMicros[i].id == id && listaDeMicros[i].isEmpty == OCUPADO)
            {
                indice = i;
                break;
            }//fin if

        }//fin for

    }//fin if NULL

return indice;
}//fin findPassengersByid

int modificarPasajero(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa)
{
	   int modificacion;
	   int indice = -1;
 	   int verificacion;
 	   char cadena[100];
       int auxiliarModif = 0;
       int indexEncontrado;
       char salirr;

      if (listaDeMicros != NULL && tam > 0 && listaDeTipos !=NULL && tamTipo > 0)
      {
		  mostrarMicros(listaDeMicros, tam,listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
		  printf("ingrese el id del pasajero que desea modificar: \n");
		  scanf("%d", &auxiliarModif);

		  indexEncontrado = encontrarMicroPorId(listaDeMicros, tam, auxiliarModif);

			  if (indexEncontrado >= 0 && indexEncontrado < tam && listaDeMicros[indexEncontrado].isEmpty == OCUPADO)
			  {
				  do
				  {
					  modificacion = menuModificaciones();

					  switch(modificacion)
					  {
					      case 1:
					    	  printf("ingrese el tipo de micro: 5001.Comun 5002.CocheCama 5003.Doble 50004.Vip\n");
							  fflush(stdin);
							  gets(cadena);
							  verificacion = sonLetras(cadena);
							  while (verificacion == 1)
							  {
								  printf("error,ingrese el tipo de micro: 5001.Comun 5002.CocheCama 5003.Doble 50004.Vip\n");
								  fflush(stdin);
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDeMicros[indexEncontrado].isEmpty!= VACIO && listaDeMicros[indexEncontrado].id == auxiliarModif)
							  {
								  listaDeMicros[indexEncontrado].idTipo = atoi(cadena);
								  indice = 1;
							  }

					  		printf("asi quedo editado su micro:\n ");
					  		mostrarMicros(listaDeMicros, tam,listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
					  	break;

					      case 2:
							  printf("Ingrese la nueva capacidad: \n");
							  fflush(stdin);
							  gets(cadena);
							  verificacion = sonLetras(cadena);

							  while (verificacion == 1 || strlen(cadena) > 50)
							  {
								  printf("no ingresaste numeros, reingrese capacidad del micro: \n");
								  fflush(stdin);
								  gets(cadena);
								  verificacion = sonLetras(cadena);
							  }
							  if(listaDeMicros[indexEncontrado].isEmpty!= VACIO && listaDeMicros[indexEncontrado].id == auxiliarModif)
							  {
								  listaDeMicros[indexEncontrado].capacidad = atoi(cadena);
								  indice = 1;
							  }
							  printf("asi quedo editado su micro:\n ");
							  mostrarMicros(listaDeMicros, tam,listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
						  break;

					      case 3:
					    	  printf("si desea Salir escribe S sino N: \n");
							  fflush(stdin);
							  scanf("%c", &salirr);
						  break;

					  default:
						  printf("opcion invalida, pruebe una opcion del 1 al 7\n");
						  break;
					  }// fin del switch


				  }while(salirr != 's');

			  }// fin del if
			  else
			  {
				  printf("no se encontro la ID\n");
			  }

      }//fin if null

return indice;
} //fin de modificar pasajero

