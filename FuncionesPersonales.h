#ifndef FUNCIONESPERSONALES_H_INCLUDED
#define FUNCIONESPERSONALES_H_INCLUDED

struct Empleado
{
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty;
}Employee;

int menu();
int suma(int,int);
int resta(int,int);
int division(int,int);
int multiplicacion(int,int);
int factorial(int);
int getInt(int*);
int getFloat(float*);
int getChar(char*);
int getString(char input[]);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
int getSringLetras(char input[]);
int initEmployees(Employee* list[], int len);
int addEmployee(Employee* list[], int len,int id,
                char name[],char lastName[],
                float salary, int sector);
int findEmployeeById(Employee* list, int len,int id);


#endif // FUNCIONESPERSONALES_H_INCLUDED
