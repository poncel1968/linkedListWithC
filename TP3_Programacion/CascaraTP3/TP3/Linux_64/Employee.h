#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);



Employee* Employee_new();
void Employee_delete();
Employee* Employee_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo);

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);

#endif // EMPLOYEE_H_INCLUDED
