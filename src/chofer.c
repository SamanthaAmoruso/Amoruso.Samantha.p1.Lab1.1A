/*
 * chofer.c
 *
 *  Created on: 21 may. 2022
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chofer.h"

int mostrarChoferes(eChofer listaDeChoferes[], int tamChofer)
{
    int todoOk = 0;
    if(listaDeChoferes != NULL && tamChofer > 0)
    {

        printf("------Choferes-------\n");
        printf(" Id     Nombres    sexo\n");
        for(int i=0; i<tamChofer; i++)
        {
            printf("   %d       %10s    %c\n", listaDeChoferes[i].id, listaDeChoferes[i].nombre, listaDeChoferes[i].sexo);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarChofer(int id, eChofer listaDeChoferes[], int tamChofer)
{
    int todoOk = 0;
    if(listaDeChoferes != NULL && tamChofer > 0)
    {
        for(int i=0; i<tamChofer; i++)
        {
            if(listaDeChoferes[i].id == id)
            {
                todoOk = 1;
                break;
            }//fin if

        }//fin for

    }//fin if null

return todoOk;
}//fin validar chofer

int cargarNombreChofer(eChofer listaDeChoferes[], int tamChofer, int idChofer, char nombre[])
{
    int todoOk = 0;
    int bandera = 1;
    if(listaDeChoferes != NULL && tamChofer > 0 && nombre != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tamChofer; i++)
        {
            if(listaDeChoferes[i].id == idChofer)
            {
                strcpy(nombre, listaDeChoferes[i].nombre);
                bandera = 0;
                break;
            }
        }//fin for

        if(bandera)
        {
            todoOk = -1;
        }

    }//fin if null

return todoOk;
}//fin cargarnombre
