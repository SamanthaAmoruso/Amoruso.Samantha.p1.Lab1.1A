/*
 ============================================================================
 Name        : prueba1Labo12022.c
 Author      : Sami
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define tam_Destino 4
#define tam_tipo 4
#define tam_Fechas 10
#define tam_micro 1000
#define tam_empresa 4
#define tam_viaje 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "tipo.h"
#include "destino.h"
#include "fecha.h"
#include "empresa.h"
#include "micro.h"
#include "viaje.h"

int main(void)
{
	setbuf(stdout,NULL);
	fflush(stdin);

	eMicro listaDeMicros[tam_micro];

	eTipo listaDeTipos[tam_tipo] =
	{
				{5001,"Comun"},
				{5002,"CocheCama"},
				{5003,"Doble" },
				{5004,"Vip"}
	};

	eFecha listaDeFechas[tam_Fechas];

	eEmpresa listaDeEmpresas [tam_empresa]=
	{
			{1001,"Plusmar"},
			{1002,"FlechaBus"},
			{1003,"Tas" },
			{1004,"El Rapido"}
	};


	eDestino listaDeDestinos [tam_Destino] =
	{
			{20000, "Calafate", 22500},
			{20001, "Bariloche", 103000},
			{20002,"Iguazu" , 84400},
			{20003,"Mendoza" , 95600}
	};

	eViaje listaDeViajes [tam_viaje];

	int devolucionInicializar=0;
	int devolucionInicializarViajes=0;
	char seguir;
	char salir;
	int identificador = 1;
	int identificador2 = 1;
	int bandera=0;
	int bandera2=0;

	devolucionInicializar = inicializarMicros(listaDeMicros, tam_micro);
	if(devolucionInicializar == 1)
	{
		printf("-----------------------------------------\n");
		printf("- - Sistema inicializado exitosamente - -\n");
		printf("-----------------------------------------\n");
	}// fin del if
	else
	{
		printf("-----------------------------------------\n");
		printf("- - El sistema no pudo inicializarse - - \n");
		printf("-----------------------------------------\n");
	}// fin del else

	devolucionInicializarViajes= inicializarViajes(listaDeViajes, tam_viaje);
	if(devolucionInicializarViajes == 1)
	{
		printf("-----------------------------------------\n");
		printf("- - Viajes inicializados exitosamente - -\n");
		printf("-----------------------------------------\n");
	}// fin del if
	else
	{
		printf("-----------------------------------------\n");
		printf("-Los Viajes no pudieron inicializarse - -\n");
		printf("-----------------------------------------\n");
	}// fin del else

	do{

		switch(menu())
		{
			case 1:
				altamicro(listaDeMicros, tam_micro, &identificador);
				bandera=1;
			break;

			case 2:
				if( bandera == 1)
				{
					modificarMicro(listaDeMicros, tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas, tam_empresa);
				}
				else
				{
					printf("no se puede realizar la baja si no hay micros\n");
				}
			break;

			case 3:
				if( bandera == 1)
				{
					bajaMicro(listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas, tam_empresa);
				}
				else
				{
					printf("no se puede realizar la baja si no hay micros\n");
				}

			break;

			case 4:
				if (bandera == 1)
				{
					switch(menuOrdenar())
					{
						case 1:
							printf("muestra los MICROS sin ordenar\n");
							mostrarMicros(listaDeMicros, tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa);
							ordenarMicros(listaDeMicros,tam_micro,listaDeEmpresas,tam_empresa, 1);
							printf("muestra los micros ordenados asc\n");
							mostrarMicros(listaDeMicros, tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa);
						break;

						case 2:
							printf("muestra los MICROS sin ordenar\n");
							mostrarMicros(listaDeMicros, tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa);
							ordenarMicros(listaDeMicros,tam_micro,listaDeEmpresas,tam_empresa, 0);
							printf("muestra los micros ordenados desc\n");
							mostrarMicros(listaDeMicros, tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa);
						break;

						case 3:
							printf("Si desea seguir escribe S sino N: \n");
							fflush(stdin);
							scanf("%c", &salir);
						break;

						default:
							printf("ingrese una opcion del 1 al 3\n");
						break;
					}//fin switch case 4

				}//fin if bandera
				else
				{
					printf("no se puede ordenar ya q no hay micros\n");
				}
			break;

			case 5:
				listarEmpresas(listaDeEmpresas,tam_empresa);
			break;

			case 6:
				listarTipos(listaDeTipos, tam_tipo);
			break;

			case 7:
				listarDestinos(listaDeDestinos, tam_Destino);
			break;

			case 8:
				if(bandera == 1)
				{
				  agregarViaje(listaDeViajes,tam_viaje,listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,
				  tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino, &identificador2);

				  bandera2 =1;
				}
				else
				{
					printf("No se pueden hacer viajes porque no ingresaste micros\n");
				}
			break;

			case 9:
				if(bandera == 1 && bandera2 == 1)
				{
					mostrarViajes(listaDeViajes,tam_viaje,listaDeMicros,tam_micro,listaDeTipos,tam_tipo,
					listaDeEmpresas,tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino);
				}
				else
				{
					printf("no ingresaste micros y/o viajes\n");
				}
			break;

			case 10:
				if(bandera == 1)
				{
					switch(menuInformes())
					{
						case 1:
							empresasConMasMicros(listaDeMicros,tam_micro, listaDeEmpresas,tam_empresa);
						break;

						case 2:
							porcentajeMicrosVip(listaDeMicros,tam_micro,listaDeTipos,tam_tipo, listaDeEmpresas,tam_empresa);
						break;

						case 3:
							empresaConMenosMicros(listaDeMicros,tam_micro, listaDeEmpresas,tam_empresa);
						break;

						case 4:
							mostrarPorEmpresa(listaDeMicros,tam_micro, listaDeTipos, tam_tipo, listaDeEmpresas, tam_empresa);
						break;

						case 5:
							mostrarPorTipo(listaDeMicros,tam_micro, listaDeTipos, tam_tipo, listaDeEmpresas, tam_empresa);
						break;

						case 6:
							if(bandera2 == 1)
							{
							mostrarPorDestino(listaDeViajes, tam_viaje ,listaDeMicros, tam_micro,listaDeTipos, tam_tipo,
									listaDeEmpresas, tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino);
							}
							else
							{
								printf("Para que usted elija los viajes por x destino, tienen que existir viajes\n");
							}
						break;

						case 7:
							if(bandera2 == 1)
							{
							mostrarFechaNoviembre(listaDeViajes, tam_viaje ,listaDeMicros, tam_micro,listaDeTipos, tam_tipo,
									listaDeEmpresas, tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino);
							}
							else
							{
								printf("Necesita haber ingresado viajes para ver si viajaron en noviembre\n");
							}
						break;

						case 8:
							empresaConMasCapacidad(listaDeMicros, tam_micro,listaDeEmpresas, tam_empresa);
						break;

						case 9:
							if(bandera2 ==1)
							{
							MostrarViajesMismoAnio(listaDeViajes, tam_viaje ,listaDeMicros, tam_micro,listaDeTipos, tam_tipo,
									listaDeEmpresas, tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino);
							}
							else
							{
								printf("Para saber que viajes fueron/son en el mismo año, tiene que haber viajes\n");
							}
						break;

						case 10:
							if(bandera2 == 1)
							{
							MostrarViajesMismoDestino(listaDeViajes, tam_viaje ,listaDeMicros, tam_micro,listaDeTipos, tam_tipo,
									listaDeEmpresas, tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino);
							}
							else
							{
								printf("para saber que viajes van al mismo destino tiene que haber viajes\n");
							}
						break;

						case 11:

						break;

						case 12:

						break;

						case 13:

						break;

						case 14:

						break;

						case 15:

						break;

						case 20:
							printf("Si desea seguir probando informes escribe S sino N: \n");
							fflush(stdin);
							scanf("%c", &salir);
						break;

						default:
							printf("error, elija una opcion del 1 al 20\n");
						break;

					}//fin switch
				}
				else
				{
					printf("Tiene que ingresar micros para poder hacer algun ordenamiento o informe \n");
				}
			break;

			case 11:
				printf("Si desea seguir escribe S sino N: \n");
				fflush(stdin);
				scanf("%c", &seguir);
			break;

			default:
				printf("ingrese una opcion del 1 al 11\n");
			break;

		}//fin switch

	}while(seguir != 'n'); // fin while

return 0;
}//fin main
