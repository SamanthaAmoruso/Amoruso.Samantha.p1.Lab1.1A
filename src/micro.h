
#ifndef MICRO_H_
#define MICRO_H_

typedef struct{
int id;
int idEmpresa;
int idTipo;
int capacidad; // (cantidad pasajeros entre 1 y 50)
int isEmpty;

}eMicro;

#endif /* MICRO_H_ */

int menu();

int inicializarMicros(eMicro listaDeMicros[], int tam);

int buscarLibre(eMicro listaDeMicros[], int tam);

int buscarPasajero(eMicro listaDeMicros[], int tam, int identificador);

int altamicro(eMicro listaDeMicros[], int tam, int* identificador);

int sonLetras(char cadena[]);

void mostrarMicro(eMicro unMicro,eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa);

int mostrarMicros(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[],int tamEmpresa);

int bajaMicro(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa);

int ordenarMicros(eMicro listaDeMicros[],int tam, int orden);

int menuOrdenar();

int encontrarMicroPorId(eMicro listaDeMicros[], int tam, int id);

int modificarPasajero(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa);



