#ifndef FUNCIONESPERSONALES_H_INCLUDED
#define FUNCIONESPERSONALES_H_INCLUDED

int menu();
int suma(int,int);
int resta(int,int);
int division(int,int);
int multiplicacion(int,int);
int factorial(int);
int getInt(char* mensaje);
float getFloat(char* mensaje)
int validar_getEntero(  int* pEntero, char* msg,
                        char msgErr[],int min, int max,
                        int reintentos);


#endif // FUNCIONESPERSONALES_H_INCLUDED
