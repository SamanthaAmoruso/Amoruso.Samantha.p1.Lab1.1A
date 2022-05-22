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

int listarDestinos(eDestino listaDeDestinos[], int tam)
{
	int todoOk = 0;

	if (listaDeDestinos != NULL && tam > 0)
	{
		printf("   *** Lista de los Destinos  ***\n");
		printf("  Id    destino    precio\n");
		printf("-----------------------\n");
		for (int i = 0; i < tam; i++)
		{
			printf("   %4d    %10s %.2f\n", listaDeDestinos[i].idDestino , listaDeDestinos[i].descripcion, listaDeDestinos[i].precio);
		}
		printf("\n\n");

		todoOk = 1;
	} //fin if

return todoOk;
}

int CargardescripDestino(eDestino listaDeDestinos[], int tam, int id,char descripcion[])
{
	int todoOk = 0;

	if (listaDeDestinos != NULL && tam > 0 && id >= 5001 && id <= 5004 && descripcion != NULL)
	{
		for (int i = 0; i < tam; i++)
		{

			if (listaDeDestinos[i].idDestino == id)
			{
				strcpy(descripcion, listaDeDestinos[i].descripcion);
				break;
			}

		} //fin for

		todoOk = 1;

	} //fin if
	return todoOk;
}


