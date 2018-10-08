#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


typedef struct
{
    int codigoCliente;
    char apellido[51];
    char nombre[51];
    char domicilio[51];
    char telefono[51];
    int isEmpty;

}eCliente;

void inicializarCliente(eCliente* lista,int len);
int primerEspacioCliente(eCliente* lista, int len);
void addCliente(eCliente* lista, int len,int *altaBanderaCliente);
int findCliente(eCliente* lista, int len,int codigo);
int menuClientes();
void bajaCliente(eCliente* lista,int len);
void modificarCliente(eCliente* lista,int len);
void imprimirListaClientes(eCliente* lista,int len);

#endif CLIENTES_H_INCLUDED
