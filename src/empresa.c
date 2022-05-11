/*
 * empresa.c
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"

int listarEmpresas(eEmpresa listaDeEmpresas[], int tam)
{

	int todoOk = 0;
	if (listaDeEmpresas != NULL && tam > 0)
	{
		printf("   *** Lista de las Empresas  ***\n");
		printf("  Id    Descripcion\n");
		printf("-----------------------\n");
		for (int i = 0; i < tam; i++)
		{
			printf("   %4d    %10s\n", listaDeEmpresas[i].id, listaDeEmpresas[i].descripcion);
		}
		printf("\n\n");

		todoOk = 1;
	} //fin if

return todoOk;
}


int CargarDescripEmpresa(eEmpresa listaDeEmpresas[], int tam, int id,char descripcion[])
{
	int todoOk = 0;

	if (listaDeEmpresas != NULL && tam > 0 && id >= 1001 && id <= 1004 && descripcion != NULL)
	{
		for (int i = 0; i < tam; i++)
		{

			if (listaDeEmpresas[i].id == id)
			{
				strcpy(descripcion, listaDeEmpresas[i].descripcion);
				break;
			}

		} //fin for

		todoOk = 1;

	} //fin if
	return todoOk;
}

