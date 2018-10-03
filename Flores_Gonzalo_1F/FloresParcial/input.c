#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************ENTRADA DE DATOS*****************/


void getInt(int* puntero)
{
    int numero;
    scanf("%d",&numero);
    *puntero = numero;
}

void getFloat(float* puntero)
{
    float numero;
    scanf ("%f",&numero);
    *puntero = numero;
}

void getChar(char* mensaje)
{
    char letra;
    fflush(stdin);
    scanf("%c",&letra);
    *mensaje = letra;

}

int getString(char* input){
scanf("%s",input);
return 0;
}

/**************VALIDACION DE DATOS*****************/

int esNumerico(char str[]){
    int i=0;
    while(str[i] != '\0' ){
        if(str[i]<'0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z')){
            return 0;}
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[]){
    int i=0;
     while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9'))
        return 0;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i = 0;
    int contadorGuiones = 0;
    while (str[i] != '\0'){
        if ((str[i] != ' ') && (str[i] != '-') &&
            (str[i] < '0' || str[i] > '9')){
            return 0;}
        if (str[i] == '-'){
            contadorGuiones++;
        }
        i++;
    }
    if (contadorGuiones==1){
        return 1;
    }
    return 0;
}

int getSringLetras(char input[]){
    char aux[256];
    getString(aux);
    if (esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
