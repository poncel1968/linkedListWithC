#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char usuario[9];
    char clave[9];
    char aux[]="admin\n";
    int comparacion;

    printf("ingrese usuario \n");
    fgets(usuario,9,stdin);
    printf("ingrese clave \n");
    __fpurge(stdin);
    fgets(clave,9,stdin);

    comparacion=strcmp(usuario, aux);
    printf("comparacion :  %d \n",comparacion);

    if (strcmp(usuario, aux)==0)
    {
        printf("Ingreso");
    }
    else
    {
        printf("No ingreso");

    }


    /*
    char nombre[10];
    char apellido[10];
    char localidad[10];

    int tamanio;

    tamanio=sizeof(nombre);
    printf("El tamaño de la variable antes de inicializar es %d \n",tamanio);

    printf("Ingrese un nombre \n");
    scanf("%s",nombre);
    printf("El nombre ingresado es : %s  \n",nombre);

    tamanio=sizeof(nombre);
    printf("El tamaño de la variable despues de inicializar es %d \n",tamanio);


    fgets(apellido,10,stdin);
    __fpurge(stdin);
    fgets(nombre,10,stdin);
    __fpurge(stdin);
    fgets(localidad,10,stdin);

    printf("El apellido es %s \n",apellido);
    printf("El nombre es %s \n",nombre);
    printf("La localidad es %s \n",localidad);

    */




    return 0;
}
