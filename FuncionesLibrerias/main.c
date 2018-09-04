#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

int getNumero( int* pResultado, char mensaje[], char mensajeError[],int minimo, int maximo, int reintentos);

int main()
{

    int numero;
    if (getNumero(&numero,"NUMERO ?","Fuera de Rango",10,100,2)==0)
    {
        printf("El numero es %d", numero);
    }

}

