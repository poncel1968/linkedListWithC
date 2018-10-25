#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utn.h"
#define LIMITE_ARRAY 15

static int getNextId();

static int getNextId()
{
    static int newId;
    return newId++;

}

int usuario_filler(usuario* array, int limite, char* nombre, char* domicilio, char* telFijo )
{

    int retorno=-1;
    int i = usuario_buscarLugarVacio(array,limite);

    if ( i >= 0)
    {
        strncpy(array[i].nombre,nombre,strlen(nombre));
        strncpy(array[i].domicilio,domicilio,strlen(domicilio));
        strncpy(array[i].telFijo,telFijo,strlen(telFijo));
        array[i].isEmpty=0;
        array[i].id=getNextId();
        retorno=0;

    }
    return retorno;
}


int usuario_buscarLugarVacio(usuario* array, int limitearray)
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

int usuario_alta(usuario* nuevoUsuario,int limitearray)
{
    char nombre[100];
    char domicilio[200];
    char telFijo[15];
  //  char telMovil[15];
  //  char mail[100];
  //  char redSocial[100];
  //  int id;
  //  int isEmpty;
    int i;
    int flag=0;

    for(i=0;i<limitearray;i++)
    {
        if(nuevoUsuario[i].isEmpty==1)
        {
            flag=1;
            break;
        }
    }

    if (flag==1 && utn_getNombre(nombre,100,"Ingrese nombre  : ")== 0 &&
    utn_getString(domicilio,200,"Ingrese Domicilio :","Error Domicilio")==0
    && utn_getString(telFijo,15,"Ingrese Telefono : ","Error telefono")==0)
    {

        strncpy(nuevoUsuario[i].nombre,nombre,(strlen(nombre)));
        strncpy(nuevoUsuario[i].domicilio,domicilio,(strlen(domicilio)));
        strncpy(nuevoUsuario[i].telFijo,telFijo,(strlen(telFijo)));
        nuevoUsuario[i].id=getNextId();
        nuevoUsuario[i].isEmpty=0;
    }

return 0;

}

int usuario_init(usuario* nuevoUsuario,int limitearray)
{
    int i;
    for(i=0;i<limitearray;i++)
    {
    nuevoUsuario[i].isEmpty = 1;
    }
return 0;

}

int usuario_listar(usuario* usuario,int limitearray)
{

    int i;
        printf("LISTADO DE USUARIOS \n");
    for(i=0;i<limitearray;i++)
    {

        if (usuario[i].isEmpty == 0)
        {
            printf("Nombre : %s \n", usuario[i].nombre);
            printf("Domicilio : %s \n", usuario[i].domicilio);
            printf("Telefono : %s \n", usuario[i].telFijo);
            printf("Movil : %s \n", usuario[i].telMovil);
            printf("Mail : %s \n", usuario[i].mail);
            printf("Red Social : %s \n", usuario[i].redSocial);
            printf("Id Cliente : %d \n", usuario[i].id);
            printf("---\n");
        }
    }
    return 0;

}

int usuario_ordenarPorNombre(usuario* array, int limite)
{
 /*
    char nombre[100];
    char domicilio[200];
    char telFijo[15];
    char telMovil[15];
    char mail[100];
    char redSocial[100];
    int id;
    int isEmpty;
    */
int  j;
usuario aux;
int flag=1;

while (flag==1)
{
    flag=0;
    for (j = 1; j < limite; j++)
    {

    if (strcmp(array[j-1].nombre,array[j].nombre)>0 )
    {
        strncpy(aux.nombre,array[j].nombre,100);
        strncpy(aux.domicilio,array[j].domicilio,200);
        strncpy(aux.telFijo,array[j].telFijo,15);
        strncpy(aux.telMovil,array[j].telMovil,15);
        strncpy(aux.mail,array[j].mail,100);
        strncpy(aux.redSocial,array[j].redSocial,100);
        aux.id=array[j].id;
        aux.isEmpty=array[j].isEmpty;

        strncpy(array[j].nombre,array[j-1].nombre,100);
        strncpy(array[j].domicilio,array[j-1].domicilio,200);
        strncpy(array[j].telFijo,array[j-1].telFijo,15);
        strncpy(array[j].telMovil,array[j-1].telMovil,15);
        strncpy(array[j].mail,array[j-1].mail,100);
        strncpy(array[j].redSocial,array[j-1].redSocial,100);
        array[j].id=array[j-1].id;
        array[j].isEmpty=array[j-1].isEmpty;


        strncpy(array[j-1].nombre,aux.nombre,100);
        strncpy(array[j-1].domicilio,aux.domicilio,200);
        strncpy(array[j-1].telFijo,aux.telFijo,15);
        strncpy(array[j-1].telMovil,aux.telMovil,15);
        strncpy(array[j-1].mail,aux.mail,100);
        strncpy(array[j-1].redSocial,aux.redSocial,100);
        array[j-1].id=aux.id;
        array[j-1].isEmpty=aux.isEmpty;

        flag=1;
    }
    }
}
    return 0 ;
}

int usuario_menu(char* opcionesMenu,usuario* array, int limite)
{
    int salir = 99;
    int opcion=0;

    do
    {
    printf("OPCIONES DEL MENU PRINCIPAL");
    printf(opcionesMenu);
    utn_getInt(&opcion,5,"Ingrese Opcion Menu \n", "Error opcion ingresada \n");
    switch (opcion)
    {
        case 1:
        usuario_listar(array, limite);
        break;

        case 2:
        usuario_alta(array,limite);
        break;

        case 99:
        printf("Exit!");
        break;

        default:
        printf("\nOpcion Incorrecta!!\n");
        system("cls");
    }
    }while (opcion !=salir );

    return 0;
}

