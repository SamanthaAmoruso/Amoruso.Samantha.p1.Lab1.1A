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

    printf(" 1.Alta de un micro\n");
    printf(" 2.Modificacion de un micro\n");
    printf(" 3.Baja de un micro\n");
    printf(" 4.Listar micros asc o desc\n");
    printf(" 5.Listar Empresas\n");
    printf(" 6.Listar Tipos\n");
    printf(" 7.Listar Destinos\n");
    printf(" 8.Alta viaje\n");
    printf(" 9.Listar viajes\n");
    printf(" 10.Menu de muchos informes\n");
    printf(" 11.Salir del menu\n");
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
}//fin del menu de modificaciones

int menuInformes()
{
    int opcion;

    printf(" 1.Informe de la empresa con mayor cantidad de micros\n");
    printf(" 2.Informe del porcentaje de empresas con micros vip\n");
    printf(" 3.Informe de la empresa con menor cantidad de micros\n");
    printf(" 4.Mostrar la empresa elegida x el usuario \n");
    printf(" 5.Mostrar el tipo elegido x el usuario \n");
    printf(" 6.Mostrar el destino elegido x el usuario\n");
    printf(" 7.Mostrar viajes con fecha de noviembre\n");
    printf(" 8.Mostrar la/las empresa/s con mas capacidad\n");
    printf(" 9.Mostrar todos los viajes que estan en X año\n");
    printf(" 10.Mostrar todos los viajes que fueron a X destino\n");
    printf(" 11. \n");
    printf(" 12. \n");
    printf(" 13. \n");
    printf(" 14. \n");
    printf(" 15. \n");
    printf(" 20.Salir\n");
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

int buscarMicro(eMicro listaDeMicros[], int tam, int identificador)
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
					printf("ingrese el tipo de micro: 5001.Comun 5002.CocheCama 5003.Doble 5004.Vip\n");
				    fflush(stdin);
				    scanf("%d",&aux);
				    while(aux < 5001 || aux > 5004 )
				    {
						printf("error,ingrese el tipo de micro: 5001.Comun 5002.CocheCama 5003.Doble 5004.Vip\n");
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
				printf("\ningresaste correctamente el micro\n\n");
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

int ordenarMicros(eMicro listaDeMicros[],int tam,eEmpresa listaDeEmpresas[], int tamEmpresa, int orden)
{
    int todoOk = 0;
    eMicro auxiliar;
    char EmpresaI[25];
	char EmpresaJ[25];

    if(listaDeMicros !=NULL && tam > 0)
    {
		for (int i = 0; i < tam - 1; i++)
		{
			for (int j = i + 1; j < tam; j++)
			{
				CargarDescripEmpresa(listaDeEmpresas, tamEmpresa, listaDeMicros[i].idEmpresa , EmpresaI);
				CargarDescripEmpresa(listaDeEmpresas, tamEmpresa, listaDeMicros[i].idEmpresa , EmpresaJ);

				if(  (strcmp(EmpresaI, EmpresaJ) == 0 && listaDeMicros[i].capacidad > listaDeMicros[j].capacidad) ||
	                    (strcmp(EmpresaI, EmpresaJ) >= 0 && orden == 1)  )
				{
					   auxiliar = listaDeMicros[i];
					   listaDeMicros[i] = listaDeMicros[j];
					   listaDeMicros[j] = auxiliar;
					   todoOk = 1;
				}
				else if(  (strcmp(EmpresaI, EmpresaJ) == 0 && listaDeMicros[i].capacidad > listaDeMicros[j].capacidad) ||
	                    (strcmp(EmpresaI, EmpresaJ) >= 0 && orden == 0)  )
				{
					auxiliar = listaDeMicros[i];
					listaDeMicros[i] = listaDeMicros[j];
					listaDeMicros[i] = auxiliar;
					todoOk = 0;
				}//descendente

				} // fin del segundo for

    		}// fin del primer for

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

int modificarMicro(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa)
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
		  printf("ingrese el id del micro que desea modificar: \n");
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

void mostrarPorTipo(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa)
{
    int opcion;

    printf("De que tipo de micro desea el listado?  5001.Comun 5002.CocheCama 5003.Doble 50004.Vip\n");
    scanf("%d", &opcion);
    while(opcion < 5001 || opcion > 5004)
    {
        printf("De que tipo de micro desea el listado?  5001.Comun 5002.CocheCama 5003.Doble 50004.Vip\n");
        scanf("%d", &opcion);
    }
    printf("ID   ----    idEmpresa  -----   idTipo   ------  capacidad \n");
    if(listaDeMicros != NULL && tam > 0 )
    {
        for(int i= 0; i < tam; i++)
        {
            if(listaDeMicros[i].idTipo == opcion)
            {
				mostrarMicro(listaDeMicros[i],listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
            }
            else if(listaDeMicros[i].idTipo != opcion)
            {
            	printf("No hay tipos de este tipo para mostrar\n");
            	break;
            }
        }//fin for

    }//fin if null

}//fin void

void mostrarPorEmpresa(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa)
{
    int opcion;

    printf("De que tipo de empresa desea el listado?  1001.Plusmar 1002.Flecha Bus 1003.Tas 1004.El Rapido\n");
    scanf("%d", &opcion);
    while(opcion < 1001 || opcion > 1004)
    {
        printf("De que tipo de empresa desea el listado?  1001.Plusmar 1002.Flecha Bus 1003.Tas 1004.El Rapido\n");
        scanf("%d", &opcion);
    }
    printf("ID   ----    idEmpresa  -----   idTipo   ------  capacidad \n");
    if(listaDeMicros != NULL && tam > 0 )
    {
        for(int i= 0; i < tam; i++)
        {
            if(listaDeMicros[i].idEmpresa == opcion)
            {
				mostrarMicro(listaDeMicros[i],listaDeTipos,tamTipo,listaDeEmpresas,tamEmpresa);
            }
            else if(listaDeMicros[i].idEmpresa != opcion)
			{
				printf("No hay este tipo de empresa para mostrar\n");
				break;
			}
        }//fin for

    }//fin if null

}//fin void

void empresasConMasMicros(eMicro listaDeMicros[],int tam, eEmpresa listaDeEmpresas[], int tamEmpresa)
{
		int ContadorPlusmar=0;
		int contadorFlechaBus=0;
		int contadorTas=0;
		int contadorElRapido=0;

	if(listaDeMicros!= NULL && tam > 0 && listaDeEmpresas !=NULL && tamEmpresa > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			switch(listaDeMicros[i].idEmpresa)
			{
				case 1001:
					ContadorPlusmar++;
				break;

				case 1002:
					contadorFlechaBus++;
				break;

				case 1003:
					contadorTas++;
				break;

				case 1004:
					contadorElRapido++;
				break;
			}// fin del swtich

		}// fin del for

		if(ContadorPlusmar == 0)
		{
			printf("no se ingresaron micros con la empresa Plusmar\n");
		}
		else if(ContadorPlusmar > contadorFlechaBus && ContadorPlusmar > contadorTas && ContadorPlusmar > contadorElRapido)
		{
			printf("la empresa con mas micros es Plusmar\n");
		}

		if(contadorFlechaBus > ContadorPlusmar && contadorFlechaBus > contadorTas && contadorFlechaBus > contadorElRapido)
		{
			printf("la empresa con mas micros es Flecha Bus\n");
		}
		else if(contadorFlechaBus == 0)
		{
			printf("no se ingresaron micros con la empresa Flecha Bus\n");
		}

		if(contadorTas > ContadorPlusmar && contadorTas > contadorFlechaBus && contadorTas > contadorElRapido)
		{
			printf("la empresa con mas micros es Tan\n");
		}
		else if(contadorTas == 0)
		{
			printf("no se ingresaron micros con la empresa Tan\n");
		}

		if (contadorElRapido > ContadorPlusmar && contadorElRapido > contadorFlechaBus && contadorElRapido > contadorTas)
		{
			printf("la empresa con mas micros es El rapido\n");
		}
		else if(contadorElRapido == 0)
		{
			printf("no se ingresaron micros con la empresa El Rapido\n");
		}

	}// fin if null

}// fin funcion


int porcentajeMicrosVip(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[], int tamTipo,
						eEmpresa listaDeEmpresas[], int tamEmpresa)
{
    int todoOk = 0;
    int idEmpresa;
    int contadorVip = 0;
    int contMicros = 0;
    int flag = 1;
    float porcentaje = 0;
    char descripcion[20];

    if(listaDeMicros != NULL && tam >0 && listaDeEmpresas != NULL && tamEmpresa >0 && listaDeTipos != NULL && tamTipo >0)
    {
        listarEmpresas(listaDeEmpresas, tamEmpresa);
        printf("ingrese id empresa: \n");
        scanf("%d",&idEmpresa);
        while(!validarEmpresas(idEmpresa, listaDeEmpresas, tamEmpresa));

        while(!CargarDescripEmpresa(listaDeEmpresas, tamEmpresa, idEmpresa, descripcion));

        for(int i=0; i<tam; i++)
        {
            if(listaDeMicros[i].isEmpty == OCUPADO && listaDeMicros[i].idEmpresa == idEmpresa)
            {
                contMicros++;

                if(listaDeMicros[i].idTipo == 5004)
                {
                	contadorVip++;
                }
                flag = 0;
            }//fin if

        }//fin for
        if(!flag)
        {
        	printf("\n La empresa %s tiene %d micros\n Del total de micros %d son Vip\n", descripcion, contMicros, contadorVip);
			porcentaje = (float) (contadorVip * 100) / contMicros;
			printf(" Del total de micros de la empresa el %.2f porciento son de tipo Vip\n", porcentaje);
        }
        else
        {
			printf("No hay micros de tipo Vip en la empresa %s \n", descripcion);
        }

        todoOk = 1;

    }//fin if null

return todoOk;
}//fin de la funcion de las empresas con micros vip

int empresaConMenosMicros(eMicro listaDeMicros[], int tam, eEmpresa listaDeEmpresas[],int tamEmpresa)
{
    int todoOk =0;
    int cantMicros[tamEmpresa];
    int acumMicros;
    int menorCantidad;
    int flag;

    for(int i=0; i<tamEmpresa; i++)
    {
        cantMicros[i] = 0;
    }

    if(listaDeMicros != NULL && tam > 0 && listaDeEmpresas != NULL && tamEmpresa > 0)
    {
        for(int i=0; i<tamEmpresa; i++)
        {
            flag =0;
            acumMicros = 0;
            for(int j=0; j < tam; j++)
            {
                if(listaDeMicros[j].isEmpty == OCUPADO && listaDeMicros[j].idEmpresa == listaDeEmpresas[i].id)
                {
                    flag = 1;
                    acumMicros++;
                }
            }//fin for

            if(flag!=0)
            {
               cantMicros[i] = acumMicros;
               printf("cantidad de micros que tiene cada empresa: \n %d  %s\n", cantMicros[i], listaDeEmpresas[i].descripcion);
            }

        }//fin for

        for(int i=0; i<tamEmpresa; i++)
        {
            if(i==0 || cantMicros[i] < menorCantidad)
            {
                menorCantidad = cantMicros[i];
            }
        }//fin for

        printf("\nla/s empresa/s con menos micros o sin ningun micro es/son: \n");
        for(int i=0; i<tamEmpresa; i++)
        {
            if(cantMicros[i] == menorCantidad)
            {
                printf("%d %s\n\n", cantMicros[i] ,listaDeEmpresas[i].descripcion);
            }
        }//fin for

        todoOk=1;
    }//fin if null

return todoOk;
}//fin de la funcion

int empresaConMasCapacidad(eMicro listaDeMicros[], int tam, eEmpresa listaDeEmpresas[],int tamEmpresa)
{
    int todoOk =0;
    int capacidad[tamEmpresa];
    int bandera;
    int banderaCapacidad=0;
    int acumCapacidad;
    int mayorCapacidad=0;

    for(int i=0; i<tamEmpresa; i++)
    {
    	capacidad[i] = 0;
    }

    if(listaDeMicros != NULL && tam > 0 && listaDeEmpresas != NULL && tamEmpresa > 0)
    {
        for(int i=0; i<tamEmpresa; i++)
        {
        	bandera = 0;
            acumCapacidad = 0;
            for(int j=0; j < tam; j++)
            {
                if(listaDeMicros[j].isEmpty == OCUPADO && (listaDeMicros[j].idEmpresa == listaDeEmpresas[i].id))
                {
                	bandera = 1;
                    acumCapacidad += listaDeMicros[j].capacidad;
                }//fin if

            }//fin for j

            if(bandera!=0)
            {
            	capacidad[i] = acumCapacidad;
            }//fin if bandera

        }//fin for i
        banderaCapacidad=0;

        for(int i=0; i<tamEmpresa; i++)
        {
            if(banderaCapacidad==0 || (capacidad[i] > mayorCapacidad))
            {
            	banderaCapacidad=1;
                mayorCapacidad = capacidad[i];
            }//fin if

        }//fin for

        for(int i=0; i<tamEmpresa; i++)
        {
            if(capacidad[i] == mayorCapacidad)
            {
                printf("La empresa con mas capacidad es: %s con una capacidad de: %d\n\n", listaDeEmpresas[i].descripcion, capacidad[i]);
            }//fin if

        }//fin for

    todoOk=1;
    }//fin if null

return todoOk;
}//fin de la funcion



