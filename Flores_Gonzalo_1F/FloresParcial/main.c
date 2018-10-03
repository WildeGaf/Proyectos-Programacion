#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "clientejuego.h"
#define CANTJ 20
#define CANTC 100


int main()
{
    eCliente listaC[100];
    eJuegos listaJ[20];
    int respuesta,validarTelefono;
    int validarFindJuego,validarFindCliente,auxCodigoCliente;
    int espacioLibreJuego,espacioLibreCliente;
    char auxDescripcion[51],auxNombre[51],auxApellido[51],auxDomicilio[51],auxTelefono;
    int auxCodigoJuego,auxImporteJuego,au;
    int altaBanderaCliente = 0, altaBanderaJuego = 0;
    int opcionElegida;
    inicializarJuego(listaJ,CANTJ);
    inicializarCliente(listaC,CANTC);
    do{
        printf ("*******Menu Inicial******\n");
        printf ("1- Ingrese uno para acceder al menu de juegos");
        printf ("2- Ingrese dos para acceder al menu de clientes");
        printf ("3- Ingrese tres para salir");
        if (respuesta == 1){
                printf ("*******Menu Juegos******\n");
                printf ("1- Ingrese uno para dar de alta un juego");
                printf ("2- Ingrese dos para modificar los datos de un juego");
                printf ("3- Ingrese tres para dar de baja un juego");
                printf ("4- Ingrese cuatro para listar los juego");
                getInt(&opcionElegida);
            switch (opcionElegida){
            case 1:
                espacioLibreJuego = primerEspacioJuegos(listaJ,CANTJ);
                    if (espacioLibreJuego != -1){
                        printf("Ingrese la descripcion");
                        getSringLetras(auxDescripcion);
                        printf("Ingrese el importe del juego");
                        getInt(&auxImporteJuego);
                        addJuego(listaJ,CANTJ,auxDescripcion,auxImporteJuego);
                        altaBanderaJuego = 1;
                        break;
                    }
            case 2:
                printf("Ingrese el codigo del libro que desea modificar del registro");
                getInt(&auxCodigoJuego);
                validarFindJuego = findJuego(listaJ,CANTJ,auxCodigoJuego);
                if (validarFindJuego == -1){
                    printf("No se ha encontrado el codigo ingresado");
                }
                else{
                    printf("1-Modificar descripcion");
                    printf("2-Modificar importe");
                    getInt(&opcionElegida);
                    switch (opcionElegida){
                        case 1:
                            printf("Ingrese la nueva descripcion");
                            getStringLetras(auxDescripcion);
                            strcpy(listaJ[validarFindJuego].descripcion,auxDescripcion);
                            break;
                        case 2:
                            printf("Ingrese el nuevo importe");
                            getInt(&auxImporteJuego);
                            listaJ[validarFindJuego].importe = auxImporteJuego;
                            break;
                        default:
                            printf("Error al seleccion una opcion");
                }
                break;
            case 3:
                system("cls");
                printf("Ingrese el codigo del libro que desea eliminar del registro");
                getInt(&auxCodigoJuego);
                BajaJuego(listaJ,CANTJ,auxCodigoJuego);
                break;
            case 4:
                system("cls");
                imprimirListaJuegos(listaJ,CANTJ);
                break;
        }
        if (respuesta == 2){
            printf ("*******Menu Clientes******\n");
            printf ("1- Ingrese uno para dar de alta un cliente");
            printf ("2- Ingrese dos para modificar los datos de un cliente");
            printf ("3- Ingrese tres para dar de baja un cliente");
            printf ("4- Ingrese cuatro para listar los clientes");
            getInt(&opcionElegida);
        }
        switch (opcionElegida){
            case 1:
                espacioLibreCliente = primerEspacioCliente(listaC,CANTC);
                    if (espacioLibreCliente != -1)
                        printf("Ingrese el apellido del cliente");
                        getSringLetras(auxApellido);
                        printf("Ingrese el nombre del cliente");
                        getSringLetras(auxNombre);
                        printf("Ingrese el domicilio del cliente");
                        getSringLetras(auxDomicilio);
                        do{
                            printf("Ingrese el telefono del cliente");
                            getSringLetras(auxTelefono);
                            validarTelefono = esTelefono(auxTelefono);
                        }while(validarTelefono!=1);
                        addCliente(listaJ,CANTJ,auxCodigoJuego,auxDescripcion,auxImporteJuego);
                        altaBanderaCliente = 1;
                        break;
            }
            case 2:
                printf("Ingrese el codigo del cliente que desea modificar");
                getInt(&auxCodigoCliente);
                validarFindCliente = findCliente(listaC,CANTC,auxCodigoCliente);
                if (validarFindCliente == -1){
                    printf("No se ha encontrado el codigo ingresado");
                }
                else{
                    printf("1-Modificar Apellido");
                    printf("2-Modificar Nombre");
                    printf("3-Modificar Domicilio");
                    printf("4-Modificar Telefono");
                    getInt(&opcionElegida);
                    switch (opcionElegida){
                    case 1:
                        strcpy(listaC[validarFindCliente].apellido,auxApellido)


                    }
                }
                break;
            case 3:
                system("cls");
                printf("Ingrese el codigo del libro que desea eliminar del registro");
                getInt(&auxCodigoJuego);
                BajaJuego(listaJ,CANTJ,auxCodigoJuego);
                break;
            case 4:
                system("cls");
                imprimirListaJuegos(listaJ,CANTJ);
                break;
        }




    }while(respuesta != 3);

    return 0;
}
