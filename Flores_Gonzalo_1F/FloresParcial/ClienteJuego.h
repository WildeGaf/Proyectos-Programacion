#ifndef CLIENTEJUEGO_H_INCLUDED


typedef struct
{
    int codigoJuego;
    char descripcion[51];
    int importe[51];
    int isEmpty;
}eJuegos;

typedef struct
{
    char codigoAlquiler[51];
    char codigoJuego[51];
    char codigoCliente[51];
    char fecha[51];
    int isEmpty;

}eAlquiler;

typedef struct
{
    char codigoCliente[51];
    char apellido[51];
    char nombre[51];
    char domicilio[51];
    char telefono[51];
    int isEmpty;
    eJuegos juegos;
    eAlquiler alquiler;

}eCliente;



void inicializarJuego(eJuegos* lista,int len);
void inicializarCliente(eCliente* lista,int len);
int primerEspacioligre(eJuegos* lista, int len);
int addJuego(eJuegos* lista, int len,
                char descripcion[],int importe);
int findJuego(eJuegos* lista, int len,int id);
void BajaJuego(eJuegos* lista, int len, int id);
int addCliente(eCliente* lista, int len,
                char nombre[],char apellido[],
                char domicilio[],char telefono[]);
int primerEspacioCliente(eCliente* lista, int len);
int findCliente(eCliente* lista, int len,int codigo);
//int sortEmployees(Employee* lista, int len, int order);

#endif CLIENTEJUEGO_H_INCLUDED
