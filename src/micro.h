
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

int buscarMicro(eMicro listaDeMicros[], int tam, int identificador);

int altamicro(eMicro listaDeMicros[], int tam, int* identificador);

int sonLetras(char cadena[]);

void mostrarMicro(eMicro unMicro,eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa);

int mostrarMicros(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[], int tamTipo,eEmpresa listaDeEmpresas[],int tamEmpresa);

int bajaMicro(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa);

int ordenarMicros(eMicro listaDeMicros[],int tam,eEmpresa listaDeEmpresas[], int tamEmpresa, int orden);

int menuOrdenar();

int encontrarMicroPorId(eMicro listaDeMicros[], int tam, int id);

int modificarMicro(eMicro listaDeMicros[], int tam, eTipo listaDeTipos[],int tamTipo, eEmpresa listaDeEmpresas[], int tamEmpresa);

void mostrarPorTipo(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa);

void mostrarPorEmpresa(eMicro listaDeMicros[],int tam,eTipo listaDeTipos[],int tamTipo,eEmpresa listaDeEmpresas[], int tamEmpresa);

int menuInformes();

void empresasConMasMicros(eMicro listaDeMicros[],int tam, eEmpresa listaDeEmpresas[], int tamEmpresa);

int porcentajeMicrosVip(eMicro listaDeMicros[], int tamMicro, eTipo listaDeTipos[], int tamTipo,
						eEmpresa listaDeEmpresas[], int tamEmpresa);

int empresaConMenosMicros(eMicro listaDeMicros[], int tam, eEmpresa listaDeEmpresas[],int tamEmpresa);

//---------------------------------

int empresaConMasCapacidad(eMicro listaDeMicros[], int tam, eEmpresa listaDeEmpresas[],int tamEmpresa);




