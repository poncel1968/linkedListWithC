#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int getNumero( int* pResultado, char mensaje[], char mensajeError[],int minimo, int maximo, int reintentos)
{

    int datoConsola;
    int validacion;
    while(reintentos>0)
    {
        printf("Ingrese un mumero:");
        validacion=scanf("%d",&datoConsola);

        if (datoConsola < minimo || datoConsola > maximo || validacion==0 )
        {
            printf("\n%s", mensajeError);

        }
        else
        {
            *pResultado=datoConsola;
            return 0;

        }

    reintentos=reintentos-1;

    }

    return -1;
}
