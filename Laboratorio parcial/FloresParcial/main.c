#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "Clientes.h"
#include "Juegos.h"
#define CANTJ 20
#define CANTC 100
//#define CANTA 2000

int main()
{
    eCliente listaC[CANTC];
    eJuegos listaJ[CANTJ];
//  eAlquiler listaA[CANTA];
    int altaBanderaCliente = 0, altaBanderaJuego = 0;
    int opcionElegida,respuesta;
//    int r;
//    int auxCliente;
//    inicializarAlquiler(listaA,CANTA);
    inicializarJuego(listaJ,CANTJ);
    inicializarCliente(listaC,CANTC);
    do{
        respuesta = menuPrincipal();
        if (respuesta == 1){
            system("cls");
            opcionElegida=MenuJuegos();
            switch (opcionElegida){
            case 1:
                system("cls");
                addJuego(listaJ,CANTJ,&altaBanderaJuego);
                break;
            case 2:
                system("cls");
                if (altaBanderaJuego != 0){
                modificarJuego(listaJ,CANTJ);
                }
                else{
                    printf("Aun no se ingresaron datos");
                }
                break;
            case 3:
                system("cls");
                if (altaBanderaJuego != 0){
                    BajaJuego(listaJ,CANTJ);
                }else{
                    printf("Aun no se ingresaron datos");
                }
                break;
            case 4:
                system("cls");
                if (altaBanderaJuego != 0){
                    imprimirListaJuegos(listaJ,CANTJ);

                }else{
                    printf("Aun no se ingresaron datos");
                }
                system("pause");
                break;
            }
        }
        if (respuesta == 2){
            opcionElegida = menuClientes();
            switch (opcionElegida){
                case 1:
                    system("cls");
                    addCliente(listaC,CANTC,&altaBanderaCliente);
                break;
                case 2:
                    system("cls");
                    if (altaBanderaCliente != 0){
                        modificarCliente(listaC,CANTC);
                    }else{
                        printf("Aun no se ingresaron datos");
                    }
                break;
                case 3:
                    system("cls");
                    if (altaBanderaCliente != 0){
                        bajaCliente(listaC,CANTC);
                    }else{
                        printf("Aun no se ingresaron datos");
                    }

                break;
                case 4:
                    system("cls");
                    if (altaBanderaCliente != 0){
                        imprimirListaClientes(listaC,CANTC);
                    }else{
                        printf("Aun no se ingresaron datos");
                    }
                break;
            }
        }
    /* if (respuesta == 3){
            printf("Ingrese el codigo del cliente");
            getInt(&auxCliente);
            r = findCliente(listaC,CANTC,auxCliente);
            if (r != -1){
                verificarAlquiler(r,listaJ,CANTJ,listaA,CANTA);

            }else{
                printf ("No se ha encontrado el cliente");
            }
        }
        */
        if (respuesta == 4){
            system("cls");
            printf("Ha salido del programa");
        }
    }while(respuesta != 4);

    return 0;
}
