#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10


int main()
{
    int listadoDeNotas[CANTIDAD];
    int numeroIngresado;
    int i;
/*
    printf(" Tamaño : %d \n",sizeof(numeroIngresado));
    printf(" Tamaño : %d \n",sizeof(listadoDeNotas));
    printf("  direccion variable %d \n",&numeroIngresado);
    printf("  direccion array %d \n",&listadoDeNotas);
    for (i=0;i<10;i++)
    {
        printf(" direccion de cada elemento : %d \n", &listadoDeNotas[i]);
        printf(" contenido de cada elemento : %d \n", listadoDeNotas[i]);

    }

    */

    for(i=0;i<10;i++)
    {
        printf("Ingrese nota : ");
        scanf("%d",&numeroIngresado);

        listadoDeNotas[i]=numeroIngresado;

    }

    for(i=0;i<CANTIDAD;i++)
    {
        printf("La Nota es : %d \n",listadoDeNotas[i]);



    }

    return 0;
}
