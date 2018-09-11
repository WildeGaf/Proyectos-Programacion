#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,edad[5],b;
    float salario[5];
    for (i=0;i<5;i++){
        b = 1;
        b = b + i;
        printf("Ingrese la edad del alumno nro %d: ",b);
        scanf("%d",&edad[i]);
        printf("Ingrese el salario de esa persona:");
        scanf("%f",&salario[i]);
    }
    for (i=0;i<5;i++){
        b = 1;
        b = b + i;
        printf("\nEl alumno %d tiene %d de edad y su salario es de %.2f",b,edad[i],salario[i]);
    }
    return 0;
}
