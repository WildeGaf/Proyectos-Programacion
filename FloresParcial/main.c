#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "Clientes.h"
#include "Juegos.h"
#define CANTJ 20
#define CANTC 100


int main()
{
    eCliente listaC[100];
    eJuegos listaJ[20];
    int respuesta;
    int altaBanderaCliente = 0, altaBanderaJuego = 0;
    int opcionElegida;
    inicializarJuego(listaJ,CANTJ);
    inicializarCliente(listaC,CANTC);
    do{
        system("cls");
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
            system("cls");
            opcionElegida = menuClientes();
            switch (opcionElegida){
                case 1:
                    addCliente(listaC,CANTC,&altaBanderaCliente);
                    break;
                case 2:
                    modificarCliente(listaC,CANTC);
                    break;
                case 3:
                    bajaCliente(listaC,CANTC);
                    break;
                case 4:
                    imprimirListaClientes(listaC,CANTC);
                    break;
                }
        }
        if (respuesta == 4){
            printf("Ha salido del programa");
        }
    }while(respuesta != 4);

    return 0;
}
