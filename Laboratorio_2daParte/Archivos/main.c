#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* pArchivo = fopen("data.csv","r");
    FILE* pArchivoBkp = fopen("dataBkp.csv","w");
    char buffer[4096];
    char bufferId[5];
    char bufferNombre[32];
    char bufferApellido[32];
    char bufferIsEmpty[32];

    if (pArchivo != NULL)
    {
        fscanf(pArchivo,"%s\n",buffer);
        printf(buffer);

        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferIsEmpty);
            ///fprintf(pArchivoBkp,buffer);
            printf("\n%s- %s- %s- %s",bufferId,bufferNombre,bufferApellido,bufferIsEmpty);

        }

        fclose(pArchivo);
        fclose(pArchivoBkp);
    }

    else
    {
        printf("\nError no existe");
    }



    return 0;
}
