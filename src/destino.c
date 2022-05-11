/*
 * destino.c
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

char destinos [4][15] = {"calafate", "Bariloche", "Iguazu" , "Mendoza" };
float preciosDestino[4] = {22250,103000,84400,95600};

void harcodearDestino(eDestino listaDeDestinos[], int tamanioListaDestino)
{
    int identificador = 20000;
    if(listaDeDestinos != NULL)
    {
       for(int i= 0; i < tamanioListaDestino; i++)
       {
           strcpy(listaDeDestinos[i].descripcion,destinos[i]);

           listaDeDestinos[i].idDestino = identificador;
           identificador ++;
           listaDeDestinos[i].isEmpty = 0;

       }
    }
}

void harcodearPrecioDestino(eDestino listaDeDestinos[], int tamanioListaDestino)
{
    if(listaDeDestinos != NULL)
    {
       for(int i= 0; i < tamanioListaDestino; i++)
       {
          listaDeDestinos[i].precio = preciosDestino[i];

           listaDeDestinos[i].isEmpty = 0;

       }
    }
}

void mostrarDestinos(eDestino listaDeDestinos[], int tamDestino )
{
	if (listaDeDestinos !=NULL && tamDestino > 0)
	{
		printf("---------- LISTA DE DESTINOS ----------\n");
		printf("idDestino-----  ciudad  ----- costo pasaje\n");
		for ( int i = 0; i <tamDestino; i++)
		{
			printf("%d  %s %15.2f",listaDeDestinos[i].idDestino, listaDeDestinos[i].descripcion, listaDeDestinos[i].precio);
			printf("\n");
		}
	}
}
