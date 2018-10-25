#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int static isValidNombre(char * nombre);

int isValidNombre(char * nombre)
{

    return 1;
}

cliente* cliente_newCliente(void)
{
    return (cliente*)malloc(sizeof(cliente));
}

int cliente_setNombre (cliente* aux, char* nombre )
{
   int retorno=-1;
   if (aux != NULL && isValidNombre(nombre))
   {
        strncpy (aux->nombre,nombre,sizeof(aux->nombre));
        retorno=0;
   }
    return retorno;
}

int cliente_setApellido (cliente* aux, char* apellido)
{
   int retorno=-1;
   if (aux != NULL && isValidNombre(apellido))
   {
        strncpy (aux->nombre,apellido,sizeof(aux->apellido));
        retorno=0;
   }
    return retorno;
}
int cliente_setId (cliente* aux,int id)
{
    aux->id=id;
    return 0;
}

int cliente_isEmpty (cliente* aux[],int limite)
{
    int retorno = -1;
    int i;
    if (aux != NULL)
    {
        for (i=0;i<limite;i++)
        {
            if (aux[i]==NULL)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int cliente_getNombre(cliente* aux, char* nombre)
{
    int retorno=-1;

    if (aux != NULL && nombre != NULL)
    {
        strncpy(nombre,aux->nombre,sizeof(aux->nombre));
        retorno=0;
    }
    return retorno;
}

int cliente_init(cliente* aux[],int limite )
{
    int retorno =-1;

    if (aux !=NULL)
    {
        int i;
        for(i=0;i<limite;i++)
        {
            aux[i]=NULL;
        }
        retorno=0;
    }

    return retorno;
}

// modificar para que devuelva un puntero a cliente

int cliente_getById(cliente* array[], int limite, int id)
{
    int i;
    int retorno = -1;
    cliente* aux;
    for(i=0;i<limite;i++)
    {
        aux = array[i];
        if (aux != NULL && aux->id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int cliente_deleteCliente(cliente* this)
{
    int retorno=-1;
    if (this != NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}

cliente* cliente_newClienteParametros(char* nombre, char*apellido, int id, int isEmpty)
{
    cliente* aux;
    aux = cliente_newCliente();
    if (aux !=NULL)
    {
        if (cliente_setNombre(aux,nombre)==-1 || cliente_setId(aux,id)==-1 || cliente_setApellido(aux,apellido)==-1)
        {
            cliente_deleteCliente(aux);
        }
    }

    return aux;

}
