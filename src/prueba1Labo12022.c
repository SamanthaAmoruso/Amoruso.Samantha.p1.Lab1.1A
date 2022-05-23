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
#define tam_Fechas 20
#define tam_micro 1000
#define tam_empresa 4
#define tam_viaje 1000
#define tam_chofer 5
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
#include "chofer.h"

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

	eChofer listaDeChoferes [tam_chofer] =
	{
			{1, "Lucrecia", 'f'},
			{2, "CarloMagno", 'm'},
			{3, "Sebastian", 'm'},
			{4, "Estela", 'f'},
			{5, "Jessica", 'f'}
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
	int banderaHarcodeo = 0;
	int banderaHarcodeo2 = 0;
	int pId = 1;
	int pId2 = 1;

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
				if (banderaHarcodeo == 0)
				{
					altamicro(listaDeMicros, tam_micro, &identificador);
					bandera=1;
				}
				else
				{
					printf("no podes de dar alta a los micros ya que decidiste que sean harcodeados\n");
				}
			break;

			case 2:
				if(bandera == 1 || banderaHarcodeo == 1)
				{
					modificarMicros(listaDeMicros, tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas, tam_empresa, listaDeChoferes, tam_chofer);
				}
				else
				{
					printf("no se puede realizar la baja si no hay micros\n");
				}
			break;

			case 3:
				if( bandera == 1 || banderaHarcodeo == 1)
				{
					bajaMicro(listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas, tam_empresa, listaDeChoferes, tam_chofer);
				}
				else
				{
					printf("no se puede realizar la baja si no hay micros\n");
				}

			break;

			case 4:
				if (bandera == 1 || banderaHarcodeo == 1)
				{
					switch(menuOrdenar())
					{
						case 1:
							printf("muestra los MICROS sin ordenar\n");
							mostrarMicros(listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa,
																		listaDeChoferes, tam_chofer);
							ordenarMicros(listaDeMicros,tam_micro,listaDeEmpresas,tam_empresa, 1);
							printf("muestra los micros ordenados asc\n");
							mostrarMicros(listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa,
											listaDeChoferes, tam_chofer);
						break;

						case 2:
							printf("muestra los MICROS sin ordenar\n");
							mostrarMicros(listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa,
																listaDeChoferes, tam_chofer);
							ordenarMicros(listaDeMicros,tam_micro,listaDeEmpresas,tam_empresa, 0);
							printf("muestra los micros ordenados desc\n");
							mostrarMicros(listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,tam_empresa,
																listaDeChoferes, tam_chofer);
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
				if(bandera == 1 || banderaHarcodeo == 1)
				{
				  agregarViaje(listaDeViajes,tam_viaje,listaDeMicros,tam_micro,listaDeTipos,tam_tipo,listaDeEmpresas,
				  tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino,listaDeChoferes, tam_chofer, &identificador2);

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
				else if (banderaHarcodeo == 1 && banderaHarcodeo2 == 1 )
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
				if(bandera == 1 || banderaHarcodeo == 1)
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
							mostrarPorEmpresa(listaDeMicros,tam_micro, listaDeTipos, tam_tipo, listaDeEmpresas, tam_empresa, listaDeChoferes, tam_chofer);
						break;

						case 5:
							mostrarPorTipo(listaDeMicros,tam_micro, listaDeTipos, tam_tipo, listaDeEmpresas, tam_empresa, listaDeChoferes, tam_chofer);
						break;

						case 6:
							if(bandera2 == 1 || banderaHarcodeo2 == 1)
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
							if(bandera2 == 1 || banderaHarcodeo2 == 1)
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
							if(bandera2 ==1 || banderaHarcodeo2 == 1)
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
							if(bandera2 == 1 || banderaHarcodeo2 == 1)
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
							if(bandera2 == 1 || banderaHarcodeo2 == 1)
							{
								mostrarViajesDeUnMicro(listaDeViajes, tam_viaje ,listaDeMicros, tam_micro,listaDeTipos, tam_tipo,
								listaDeEmpresas, tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino , listaDeChoferes, tam_chofer);
							}
							else
							{
								printf("Para mostrar los viajes de un micro tiene que haber micros\n");
							}
						break;

						case 12:
							if(bandera2 == 1 || banderaHarcodeo2 == 1)
							{
								mostrarSumaDelPrecioDeUnMicro(listaDeViajes, tam_viaje ,listaDeMicros, tam_micro,listaDeTipos, tam_tipo,
								listaDeEmpresas, tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino , listaDeChoferes, tam_chofer);
							}
							else
							{
								printf("Para mostrar la suma del precio de este micro tiene que estar viajando a algun lado\n");
							}
						break;

						case 13:
							if(bandera2 == 1 || banderaHarcodeo2 == 1)
							{
							    MostrarViajesMismaFecha(listaDeViajes, tam_viaje ,listaDeMicros, tam_micro,listaDeTipos, tam_tipo,
								listaDeEmpresas, tam_empresa,listaDeFechas,tam_Fechas, listaDeDestinos, tam_Destino);
							}
							else
							{
								printf("Para encontrar un viaje con la misma fecha primero tiene que haber un viaje\n");
							}
						break;

						case 14:
							printf("Si desea seguir probando informes escribe S sino N: \n");
							fflush(stdin);
							scanf("%c", &salir);
						break;

						default:
							printf("error, elija una opcion del 1 al 14\n");
						break;

					}//fin switch
				}
				else
				{
					printf("Tiene que ingresar micros para poder hacer algun ordenamiento o informe \n");
				}
			break;

			case 11:
				if(bandera == 0)
				{
					harcodearMicros(listaDeMicros, tam_micro , 5, &pId);

					banderaHarcodeo = 1;
					printf("Se harcodeo correctamente los micros\n\n");
				}
				else
				{
					printf("No se pueden harcodear micros porque ya los ingreso manualmente\n");
				}
			break;

			case 12:
				if(bandera2 == 0)
				{
					harcodearViajes(listaDeViajes, tam_viaje, 5, &pId2);
					banderaHarcodeo2 = 1;
					printf("Se harcodeo correctamente los viajes\n\n");
				}
				else
				{
					printf("No se pueden harcodear Viajes porque ya los ingreso manualmente\n");
				}
			break;

			case 13:
				printf("Si desea seguir escribe S sino N: \n");
				fflush(stdin);
				scanf("%c", &seguir);
			break;

			default:
				printf("ingrese una opcion del 1 al 13\n");
			break;

		}//fin switch

	}while(seguir != 'n'); // fin while

return 0;
}//fin main
