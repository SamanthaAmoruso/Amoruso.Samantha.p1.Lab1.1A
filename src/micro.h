
#ifndef MICRO_H_
#define MICRO_H_
#include "chofer.h"

typedef struct{
int id;
int idEmpresa;
int idTipo;
int idChofer; // Ids del 1 al 5
int capacidad; // (cantidad pasajeros entre 1 y 50)
int isEmpty;

}eMicro;

#endif /* MICRO_H_ */

int menu();
/** @brief  Muestra el menu
 *
 * @return Devuelve un entero, el numero que se muestra en el menu
 */

int inicializarMicros(eMicro listaDeMicros[], int tam);
/**
 * @fn esta funcion inicializa el micro
 * @brief al inicializarlo ya sabemos que tenemos un micro en lista
 *
 * @param el array de lista de micro
 * @param  el tamaño del array de micro
 * @return 1 si inicializo y 0 si no se pudo
 */

int buscarLibre(eMicro listaDeMicros[], int tam);
/**
 * @fn esta funcion hace la busqueda de un lugar libre para ingresar micros
 * @brief busca si hay espacios libres para ingresar mas micros
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @return i si encuentra libres y -1 si hubo error
 */

int buscarMicro(eMicro listaDeMicros[], int tam, int identificador);
/**
 * @fn esta funcion hace la busqueda por id para saber si hay micros
 * @brief busca si el id de la estructura coincide
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el identificador del micro
 * @return i si encuentra libres y -1 si hubo error
 */

void mostrarMicro(eMicro unMicro,eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa,
		eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn mostrar un micro
 * @brief muestra la lista de un micro
 *
 * @param el array de lista del micro
 * @param  el tamaño del array del micro
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 * @return 1 si mostro la lista y 0 si hubo error
 */

int mostrarMicros(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa,
		eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn mostrar micros
 * @brief muestra una lista con los micros
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 * @return 1 si mostro la lista y 0 si hubo error
 */

int altamicro(eMicro listaDeMicros[], int tam, int* identificador);
/**
 * @fn esta funcion hace cargar a los micros
 * @brief muestra una lista con los micros que se cargaron
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el identificador de los micros
 * @return -1 para el error, 0 todoOK
 */

int sonLetras(char cadena[]);
/**
 * @fn la funcion son letras marca si ingreso letras
 * @brief te confirma si lo ingresado son letras o numeros
 *
 * @param el char de cadena
 * return -1 si son letras y 1 si son numeros
 */

int bajaMicro(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa,
			 eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn baja de un micro
 * @brief da de baja al id seleccionado del micro
 *
 * @param el array de lista de micro
 * @param  el tamaño del array de micro
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 * @return -1 el error, 0 todoOk
 */

int ordenarMicros(eMicro listaDeMicros[],int tam,eEmpresa listaDeEmpresas[], int tamEmpresa, int orden);
/**
 * @fn ordena a los micros alfabeticamente por tipo y por capacidad
 * @brief esta funcion ordena alfabeticamente a los micros segun lo solicitado.
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el orden asc o desc
 * @return 1 si mostro la lista y 0 si hubo error
 */

int menuOrdenar();
/** @brief  Muestra el menu del ordenamiento para asc y desc de mciros
 *
 * @return Devuelve un entero, el numero que se muestra en el menu de ordenamientos
 */

int encontrarMicroPorId(eMicro listaDeMicros[], int tam, int id);
/**
 * @fn encontrar micros por el id
 * @brief esta funcion recorre el array en busca del id del micro
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el id del micro
 * @return -1 para el error, 0 esta todook
 */

int modificarMicros(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[],int tamEmpresa,
					eChofer listaDeChoferes[], int tamChofer);
/**
 * @fn esta funcion modifica a los micros
 * @brief muestra una lista con los micros y busca el id del que sera modificado
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 * @return 1 si mostro la lista y -1 si hubo error
 */

void mostrarPorTipo(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa,
					eChofer listaDeChoferes[], int tamChofer);

/**
 * @fn esta funcion muestra X tipo segun el usuario
 * @brief Pide al usuario un tipo de de micro, muestra un listado de los micros de ese tipo.
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 */

void mostrarPorEmpresa(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa,
						eChofer listaDeChoferes[], int tamChofer);

/**
 * @fn esta funcion muestra X empresa segun el usuario
 * @brief Pide al usuario una empresa de de micro, muestra un listado de los micros de esa empresa.
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @param el array de lista de choferes
 * @param el tamaño del array de choferes
 */

int menuInformes();
/** @brief  Muestra el menu de los informes hechos
 *
 * @return Devuelve un entero, el numero que se muestra en el menu de los informes
 */

void empresasConMasMicros(eMicro listaDeMicros[],int tam, eEmpresa listaDeEmpresas[], int tamEmpresa);
/**
 * @fn funcion que muestra que empresa tiene mas micros
 * @brief Pide al usuario una empresa de de micro, muestra un listado de los micros de esa empresa.
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 */

int porcentajeMicrosVip(eMicro listaDeMicros[], int tamMicro, eTipo listaDeTipos[], int tamTipo,
						eEmpresa listaDeEmpresas[], int tamEmpresa);
/**
 * @fn muestra el micro con mas porcentaje en tener empresas vip
 * @brief esta funcion muestra el porcentaje que los micros que son vip.
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @param el array de lista de tipos
 * @param el tamaño del array de tipos
 * @return 1 si mostro la lista y -1 si hubo error
 */

int empresaConMenosMicros(eMicro listaDeMicros[], int tam, eEmpresa listaDeEmpresas[],int tamEmpresa);

/**
 * @fn funcion que calcula que empresa tiene menos micros
 * @brief esta funcion muestra la empresa que tiene menos micros
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @return 1 si mostro la lista y -1 si hubo error
 */


int empresaConMasCapacidad(eMicro listaDeMicros[], int tam, eEmpresa listaDeEmpresas[],int tamEmpresa);

/**
 * @fn funcion que calcula que empresa tiene mas capacidad
 * @brief esta funcion muestra la empresa que mas capacidad
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param el array de lista de empresas
 * @param el tamaño del array de empresas
 * @return 1 si mostro la lista y -1 si hubo error
 */


int harcodearMicros(eMicro listaDeMicros[],int tam, int cant, int* pId);
/**
 *
 * @brief esta funcion harcodea automaticamente 5 micros
 *
 * @param el array de lista de micros
 * @param  el tamaño del array de micros
 * @param un int la cantidad de micros que se mostraran harcodeados
 * @param un puntero id
 * @return 1 si mostro la lista y -1 si hubo error
 */


