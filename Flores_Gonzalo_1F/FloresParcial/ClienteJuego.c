#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClienteJuego.h"

void inicializarJuego(eJuegos* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

void inicializarCliente(eCliente* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

int primerEspacioligre(eJuegos* lista, int len){
int i,retorno;
retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
return retorno;
}

int primerEspacioCliente(eCliente* lista, int len){
int i,retorno;
retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
return retorno;
}

int addJuego(eJuegos* lista, int len,
                char descripcion[],int importe)
{
    int r,retorno = -1;
    r = primerEspacioligre(lista,len);
    if (r != -1){
        strcpy(lista[r].descripcion,descripcion);
        lista[r].codigoJuego = r;
        lista[r].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int addCliente(eCliente* lista, int len,
                char nombre[],char apellido[],
                char domicilio[],char telefono[])
{
    int r,retorno = -1;
    r = primerEspacioCliente(lista,len);
    if (r != -1){
        strcpy(lista[r].nombre,nombre);
        strcpy(lista[r].apellido,apellido);
        strcpy(lista[r].domicilio,domicilio);
        strcpy(lista[r].telefono,telefono);
        lista[r].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int findJuego(eJuegos* lista, int len,int codigo)
{
    int retorno = -1;
    int i;
    for (i=0;i<len;i++){
        if(lista[i].codigoJuego == codigo){
            retorno = i;
            break;
        }
    }
return retorno;
}

int findCliente(eCliente* lista, int len,int codigo)
{
    int retorno = -1;
    int i;
    for (i=0;i<len;i++){
        if(lista[i].codigoCliente == codigo){
            retorno = i;
            break;
        }
    }
return retorno;
}

/*
int sortEmployees(Employee* lista, int len, int order)
{
 Employee AuxLista;
 int i,j,retorno;
 retorno = -1;
    if(lista != NULL && len>0){
        for (i=0;i<len;i++){
            for(j=i+1;j<len;j++){
                if (order == 1)
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName)>0)
                    {
                        AuxLista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = AuxLista;
                        retorno = 0;
                    }
                    else{
                        if (strcmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                                  if (lista[i].sector > lista[i].sector)
                                  {
                                        AuxLista = lista[i];
                                        lista[i] = lista[j];
                                        lista[j] = AuxLista;
                                        retorno = 0;
                                  }
                        }
                    }
                }
                else
                {
                   if(strcmp(lista[i].lastName,lista[j].lastName)<0)
                   {
                        AuxLista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = AuxLista;
                        retorno = 0;
                   }
                    else
                    {
                        if(strcmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                            if (lista[i].sector < lista[j].sector)
                            {
                                AuxLista = lista[i];
                                lista[i] = lista[j];
                                lista[j] = AuxLista;
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
return retorno;
}
*/

void BajaJuego(eJuegos* lista, int len, int id){
    int juegoIdEncontrado;
    juegoIdEncontrado = findJuego(lista,len,id);
    if (juegoIdEncontrado == -1){
        printf("Ese codigo no se encuentra en el registro");
    }
    else{
    lista[juegoIdEncontrado].isEmpty = 0;
    }
}

void imprimirListaJuegos(eJuegos* lista,int len){
    int i,bandera=0;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 1){
            printf ("\n La descripcion es: %s",lista[i].descripcion);
            printf ("\n El importe es: %d",lista[i].importe);
            printf ("\n El codigo es: %d",lista[i].codigoJuego);
            bandera = 1;
            break;
        }
    }
    if (bandera != 1){
        printf("El codigo ingresado no es valido");
    }
}
