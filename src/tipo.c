/*
 * tipo.c
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int listarTipos(eTipo listaDeTipos[], int tamTipo)
{
	int todoOk = 0;

	if (listaDeTipos != NULL && tamTipo > 0)
	{
		printf("   *** Lista de los Status  ***\n");
		printf("  Id    Descripcion\n");
		printf("-----------------------\n");
		for (int i = 0; i < tamTipo; i++)
		{
			printf("   %4d    %10s\n", listaDeTipos[i].idTipo , listaDeTipos[i].descripcion);
		}
		printf("\n\n");

		todoOk = 1;
	} //fin if
	return todoOk;
}


int CargardescripTipo(eTipo listaDeTipos[], int tam, int id,char descripcion[])
{
	int todoOk = 0;

	if (listaDeTipos != NULL && tam > 0 && id >= 5001 && id <= 5004 && descripcion != NULL)
	{
		for (int i = 0; i < tam; i++)
		{

			if (listaDeTipos[i].idTipo == id)
			{
				strcpy(descripcion, listaDeTipos[i].descripcion);
				break;
			}

		} //fin for

		todoOk = 1;

	} //fin if
	return todoOk;
}
