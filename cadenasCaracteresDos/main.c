#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char nombre[31],apellido[31],apeNom[62];
    int cantidad;
    printf("Nombre: ");
    fgets(nombre,sizeof(nombre)-2,stdin);
    cantidad = strlen(nombre);
    nombre[cantidad] = cantidad-1;
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
 int  strcmp(cad1,cad2); Compara las cadenas, si son iguales va a devolver 0;
 si la cadena 1 es mayor a la cadena 2 va a devolver >0;
 si la cadena 2 es mayor a la cadena 1 va a devolver <0;
 Para que una cadena sea mayor a otra, Compara letra por letra, no importa la cantidad
 Compara los valores ascii con que un solo valor sea mayor ya es suficiente;
 #include<ctype.h>
 nombre[0] = tolower(nombre[0]); Pasa la primera letra a minuscula;
 nombre[0] = toupper(nombre[0]); Pasa la primera letra a mayuscula;
 */
