#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"



int main()
{
    FILE* pArchivo = fopen("data.csv","r");
    cliente* pClientes[1500];
    cliente* pCliente;
    char buffer[4096];
    char bufferId[5];
    char bufferNombre[32];
    char bufferApellido[32];
    char bufferIsEmpty[32];
    int i=0;
    int bufferIdInt;

    if (pArchivo != NULL)
    {
        fscanf(pArchivo,"%s\n",buffer);
        printf(buffer);

        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferIsEmpty);
            printf("\n%s- %s- %s- %s",bufferId,bufferNombre,bufferApellido,bufferIsEmpty);
            bufferIdInt=atoi()
            pClientes[i] = cliente_newClienteParametros(bufferId, bufferApellido, bufferId, bufferIsEmpty);
            printf("%s", pClientes[i]->nombre);
            i++;

        }

        fclose(pArchivo);
    }

    else
    {
        printf("\nError no existe");
    }



    return 0;
}
