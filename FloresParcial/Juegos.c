#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "Juegos.h"

int MenuJuegos(){
    int opcionElegida;
    printf ("*******Menu Juegos******\n");
    printf ("\n1- Ingrese uno para dar de alta un juego");
    printf ("\n2- Ingrese dos para modificar los datos de un juego");
    printf ("\n3- Ingrese tres para dar de baja un juego");
    printf ("\n4- Ingrese cuatro para listar los juego");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcionElegida);
    return opcionElegida;
}

void inicializarJuego(eJuegos* lista,int len){
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



int addJuego(eJuegos* lista, int len,int* altaBanderaJuego)
{
    int r,retorno = -1;
    int importeJuego,validar;
    char descripcion[51];
    r = primerEspacioligre(lista,len);
    if (r != -1){
        do{
        printf("Ingrese la descripcion: ");
        getString(descripcion);
        validar = strlen(descripcion);
        }while(validar>51 || validar <0);
        do{
            printf("Ingrese el importe del juego: ");
            getInt(&importeJuego);
        }while(importeJuego<0);
        strcpy(lista[r].descripcion,descripcion);
        lista[r].importe = importeJuego;
        lista[r].isEmpty = 1;
        lista[r].codigoJuego = r;
        retorno = 0;
        *altaBanderaJuego = 1;
    }
    else{
        printf("No hay espacio disponible");
    }
    return retorno;
}

void modificarJuego(eJuegos* lista,int len){
    int auxCodigoJuego,validar,auxImporteJuego,validarJuego,opcionElegida;
    char auxDescripcion[51];
    printf("Ingrese el codigo del libro que desea modificar del registro");
    getInt(&auxCodigoJuego);
    validarJuego = findJuego(lista,len,auxCodigoJuego);
    if (validarJuego == -1){
        printf("No se ha encontrado el codigo ingresado");
    }
    else {
        printf("1-Modificar descripcion");
        printf("\n2-Modificar importe");
        printf ("\n\nIngrese el numero: ");
        getInt(&opcionElegida);
        switch (opcionElegida){
            case 1:
                do{
                printf("Ingrese la nueva descripcion");
                getString(auxDescripcion);
                validar = strlen(auxDescripcion);
                }while(validar>51 || validar <0);
            break;
            case 2:
            do{
            printf("Ingrese el nuevo importe");
            getInt(&auxImporteJuego);
            }while(auxImporteJuego<0);
            lista[validarJuego].importe = auxImporteJuego;
            break;
            default:
            printf("Error al seleccion una opcion");
            break;
        }

    }
}

void ordenarJuegos(eJuegos* lista, int len)
{
 eJuegos AuxLista;
 int i,j;
        for (i=0;i<len;i++){
            if (lista[i].isEmpty == 1){
                for(j=i+1;j<len;j++){
                   if (lista[j].isEmpty == 1){
                        if(lista[i].importe > lista[j].importe)
                        {
                            AuxLista = lista[i];
                            lista[i] = lista[j];
                            lista[j] = AuxLista;
                        }
                    }
                }
            }
        }
        for (i=0;i<len;i++){
            if (lista[i].isEmpty == 1){
                for(j=i+1;j<len;j++){
                   if (lista[j].isEmpty == 1){
                        if((lista[i].importe == lista[j].importe)&& strcmp(lista[i].descripcion,lista[j].descripcion)>1) {
                            AuxLista = lista[i];
                            lista[i] = lista[j];
                            lista[j] = AuxLista;
                        }
                   }
                }
            }
        }
}

void BajaJuego(eJuegos* lista, int len){
    int juegoIdEncontrado;
    int auxCodigoJuego;
    printf("Ingrese el codigo del libro que desea eliminar del registro");
    getInt(&auxCodigoJuego);
    juegoIdEncontrado = findJuego(lista,len,auxCodigoJuego);
    if (juegoIdEncontrado == -1){
        printf("Ese codigo no se encuentra en el registro");
    }
    else{
    lista[juegoIdEncontrado].isEmpty = 0;
    }
}

void imprimirListaJuegos(eJuegos* lista,int len){
    int i;
    ordenarJuegos(lista,len);
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 1){
            printf ("\n La descripcion es: %s",lista[i].descripcion);
            printf ("\n El importe es: %d",lista[i].importe);
            printf ("\n El codigo es: %d\n\n",lista[i].codigoJuego);
        }
    }
}
