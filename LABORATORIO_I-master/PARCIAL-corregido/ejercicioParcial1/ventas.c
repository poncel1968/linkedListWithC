#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ventas.h"
#include"clientes.h"


static int getNextIdVenta();
/*
@brief : otorga un numero secuencial unico para id
@value : id
*/
static int getNextIdVenta()
{
    static int newId;
    return newId++;

}
/*
@brief : inicializa array de ventas a isEmpty=1
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful
*/
int ventas_init(ventas* array,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
    array[i].isEmpty = 1;
    }
return 0;
}
/*
@brief : alta de venta por id de cliente
@param : array de la estructura
@param : limite de la estructura
@param : id cliente a quien pertenece la venta
@value : 0 is successful
*/
int ventas_alta(ventas* array,int limite,int idCliente)
{
    int cantAfiches;
    char nombreArchivo[100];
    char zona[100];
    int i;
    int flag=0;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==1)
        {
            flag=1;
            break;
        }
    }
    if (flag==1 &&
    utn_getInt(&cantAfiches,5,"Ingrese Cantidad de Afiches :", "Error cantidad de Afiches")==0 &&
    utn_getString(nombreArchivo,100,"Ingrese nombre Archivo : ","Error")== 0 &&
    utn_getString(zona,100,"Ingrese zona : ","error")== 0)
    {

        strncpy(array[i].nombreArchivo,nombreArchivo,(strlen(nombreArchivo)));
        strncpy(array[i].zona,zona,(strlen(zona)));
        array[i].idVenta=getNextIdVenta();
        array[i].isEmpty=0;
        strncpy(array[i].estado,"a cobrar",strlen("a cobrar"));
        array[i].idCliente=idCliente;
        array[i].cantAfiches=cantAfiches;
        retorno=0;
    }
    else
    {
        printf("Error Alta venta");
    }

return retorno;

}
/*
@brief : baja de venta por id de cliente solo para baja de cliente
@param : array de la estructura
@param : limite de la estructura
@param : id cliente a quien pertenece la venta
@value : 0 is successful
*/
int baja_ventas(ventas* array,int limite, int idCliente)
{
    int retorno =-1;
    int i;
    for (i=0;i<limite;i++)
    {
        if(array[i].idCliente==idCliente)
        {
            array[i].isEmpty=1;
            retorno=0;
        }
    }
return retorno;
}
/*
@brief : modifcacion de venta por id de cliente
@param : array de la estructura
@param : limite de la estructura
@param : id de la venta
@value : 0 is successful
*/
int ventas_modificacion(ventas* array,int limite,int idVenta)
{
    int cantAfiches;
    char zona[100];
    int i;
    int flag=0;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(array[i].idVenta==idVenta)
        {
            flag=1;
            break;
        }
    }
    if (flag==1 &&
    strcmp(array[i].estado,"a cobrar")==0 &&
    utn_getInt(&cantAfiches,5,"Ingrese Nueva Cantidad de Afiches :", "Error cantidad de Afiches")==0 &&
    utn_getString(zona,100,"Ingrese Nueva zona : ","error")== 0)
    {
        strncpy(array[i].zona,zona,(strlen(zona)));
        array[i].cantAfiches=cantAfiches;
        retorno=0;
    }
    else
    {
        printf("Error en la Modificacion de la venta");
    }
return retorno;
}
/*
@brief : listado de ventas (isEmpty =0)
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful
*/
int ventas_listado(ventas* array, int limite)
{
    int i;
    for (i=0;i<limite;i++)
    {
        if (array[i].isEmpty==0)
        {
            printf("Id Venta : %d ",array[i].idVenta);
            printf("* Cantidad Afiches : %d",array[i].cantAfiches);
            printf("* Cliente : %d \n",array[i].idCliente);
            printf("* Estado : %s",array[i].estado);
            printf("* Archivo : %s",array[i].nombreArchivo);
            printf("* Zona : %s \n",array[i].zona);
        }
    }
return 0;
}
/*
@brief : busca un id de ventas
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful
*/
int ventas_existeId(ventas* array, int limite, int idBuscar)
{
    int retorno =-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if (array[i].idVenta == idBuscar)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
 /*
@brief : buscar un elemento por Id
@param : array de la estructura
@param : limite de la estructura
@param : id ventas a buscar
@value : el puntero al elemento o NULL
*/
ventas* ventas_getElementById(ventas* array,int limite,int idBuscado)
{
    ventas* retorno=NULL;
    int i;
    for(i=0;i<limite;i++)
    {
        if (array[i].idVenta==idBuscado)
        {
            retorno=array+i;
        }
    }

return retorno;
}

 /*
@brief : cambia el estado de una venta a "Cobrada"
@param : array de la estructura
@param : limite de la estructura
@param : id venta a buscar
@value : retorna 0 si fue exitosa
*/
int ventas_cobrar(ventas* array,int limite, int idVenta)
{
    int retorno=-1;
    ventas* pVenta=ventas_getElementById(array,limite,idVenta);
    if(pVenta!=NULL)
    {
        strncpy(pVenta->estado,"Cobrada",strlen("Cobrada"));
        printf("\nVenta cobrada\n");
        retorno=0;
    }
    else
    {
        printf("\nError al cobrar la venta");
    }
return retorno;
}
///3
 /*
@brief : alta forzada de ventas para pruebas
@param : array de la estructura
@param : limite de la estructura
@param :
@param :
@param :
@value : 0 is successful
*/
int ventas_filler(ventas* array,int limite, int idCliente,int cantAfiches, char* nombreArchivo, char* zona, char* estado)
{

    int retorno=-1;
    int i = ventas_buscarLugarVacio(array,limite);

    if ( i >= 0)
    {
        array[i].idCliente=idCliente;
        array[i].cantAfiches=cantAfiches;
        strncpy(array[i].nombreArchivo,nombreArchivo,strlen(nombreArchivo));
        strncpy(array[i].zona,zona,strlen(zona));
        strncpy(array[i].estado,estado,strlen(estado));
        array[i].isEmpty=0;
        array[i].idVenta=getNextIdVenta();
        retorno=0;

    }
    return retorno;
}

 /*
@brief : busca un elemento en array y verica isEmpty
@param : array de la estructura
@param : limite de la estructura
@param : id cliente a buscar
@value : devuelve indice de la estructura o -1 si no hay lugar
*/
int ventas_buscarLugarVacio(ventas* array, int limitearray)
{
    int retorno =-1;
    int i;
    for(i=0;i<limitearray;i++)
    {
        if(array[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
