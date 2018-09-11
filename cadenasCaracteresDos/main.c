#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char nombre[31],apellido[31],apeNom[62];
    printf("Nombre: ");
    fgets(nombre,sizeof(nombre)-2,stdin);
    strlwr(nombre);
    nombre[0] = tolower(nombre[0]);
    printf("Apellido: ");
    fgets(apellido,sizeof(apellido)-2,stdin);
    strlwr(apellido);
    apellido[0] = toupper(apellido[0]);
    strcpy(apeNom,apellido); // Concatena desde el inicio
    strcat(apeNom," "); // concatena antes de '\0' sirve para agregar un string a otro
    strcat(apeNom,nombre);
    printf("Su nombre es: %s",apeNom);
return 0;
}

/*
 strlwr(nombre); Sirve para pasar a miniscula, toda la cadena;
 strupr(nombre); Sirve para pasar todo a mayuscula;
 #include<ctype.h>
 nombre[0] = tolower(nombre[0]); Pasa la primera letra a minuscula;
 nombre[0] = toupper(nombre[0]); Pasa la primera letra a mayuscula;
 */
