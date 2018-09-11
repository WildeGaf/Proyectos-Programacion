#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[30];
    printf("Nombre: ");
    fflush(stdin);
    //fgets(nombre,31,stdin);
    //fgets(cadena,cantidad,stdin);
    //gets(nombre); Por temas de seguridad no se utiliza. Se debe usar el fgets(cadena,cantidad,stdin)
    //scanf ("%[^\n]",nombre); no se usa & ya que un string no es nativo, esto es igual a &nombre[0];
    printf("%s",nombre);

    // strcpy(nombre,"Gonzalo Flores");
    // printf("%s",nombre);
    return 0;
}


/*
char letra = Toma solo una letra, un espacio en la memoria;
char palabra[10] = "hola";
se usa \0 para indicar que se finaliza el array h o l a \0
#include <string.h>
strcpy(destino,origen); El origen puede ser una variable, una constante o literal "".
El destino debe ser una variable;

%c Se usa para un caracter
%s Se usa para un string

*/
