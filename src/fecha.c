/*
 * fecha.c
 *
 *  Created on: 11 may. 2022
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"

int validarFecha( int dia, int mes, int anio)
{
    int todoOk = 0;
    if(anio > 2000 && anio < 2030 && mes > 0 && mes < 13)
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia > 0 && dia < 32)
            {
                todoOk= 1;
            }
        break;
        case 2:
            if(dia > 0 && dia < 30)
            {
                todoOk= 1;
            }
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia > 0 && dia < 31)
            {
                todoOk= 1;
            }
        break;
        }// fin switch

    }

    return todoOk;
}//fin de validacion fecha
