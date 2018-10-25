#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"
#include "listados.h"
#define CANTCLIENTES 100
#define CANTVENTAS 1000

int main()
{

int salir = 99;
int opcion=0;
int aux;
int j,k;
int contador;
int idClienteBuscado;
int idVentasBuscado;
char opcionesMenu[500]={"\n1. Alta de cliente \n2. Modificacion de cliente\n3. Baja de Clientes\n4. Alta de Venta por Id Cliente\n5. Modificacion de Venta\n6. Cobranza de venta\n7. Listado de clientes con ventas a cobrar\n"};
strcat(opcionesMenu,"8. Listado Clientes por Apellido\n9. Listado de ventas por Id cliente\n10.e) Clientes que compro mas afiches \n11.b) Cliente con mas ventas cobradas\n");
strcat(opcionesMenu,"12.a) Cliente con mas ventas a cobrar\n13.g) Clientes con ventas menor a 1000\n99. Salir\n");

cliente eClientes[CANTCLIENTES];
ventas eVentas[CANTVENTAS];
clientes_init(eClientes,CANTCLIENTES);
ventas_init(eVentas,CANTVENTAS);

clientes_filler(eClientes, CANTCLIENTES,"LEONEL", "GIMENZ", "2223331" );
clientes_filler(eClientes, CANTCLIENTES,"JOSE", "ORTIZ", "553" );
clientes_filler(eClientes, CANTCLIENTES,"MARCELA", "RAMIREZ", "299981" );

ventas_filler(eVentas,CANTVENTAS, 1,22, "archivo 1", "CABA", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 1,23, "archivo 11", "CABA", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 1,9, "archivo abc", "GBA", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 2,7, "archivo d", "GBA", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 2,3, "archivo vacio", "INTERIOR", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 2,3, "archivo vacio", "INTERIOR", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 3,3, "archivo vacio", "INTERIOR", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 3,3, "archivo vacio", "INTERIOR", "a cobrar");
ventas_filler(eVentas,CANTVENTAS, 3,3, "archivo vacio", "INTERIOR", "a cobrar");

    do
    {
    printf(opcionesMenu);
    utn_getInt(&opcion,5,"\nIngrese Opcion menu : ", "Error Opcion Menu");
    switch (opcion)
    {
        case 1:
        aux=clientes_alta(eClientes,CANTCLIENTES);
        printf("\nEl Id generado es %d \n",aux);
        break;

        case 2:
        clientes_modificar(eClientes,CANTCLIENTES);
        break;

        case 3:
        utn_getInt(&idClienteBuscado,5,"\nIngrese Id a dar de Baja :","Error Id ingresado");
        if(clientes_baja(eClientes,CANTCLIENTES,idClienteBuscado)==0)
        {
           baja_ventas(eVentas,CANTVENTAS,idClienteBuscado);
        }
        break;

        case 4:
        utn_getInt(&idClienteBuscado,5,"\nIngrese Id del Cliente para la venta :","Error Id ingresado");
        if (clientes_getElementById(eClientes,CANTCLIENTES,idClienteBuscado)!=NULL)
        {
            ventas_alta(eVentas,CANTVENTAS,idClienteBuscado);
        }
        else
        {
            printf("Id Cliente no encontrado\n");
        }
        break;

        case 5:
        ventas_listado(eVentas,CANTVENTAS);
        utn_getInt(&idVentasBuscado,5,"\nIngrese Id Venta a Modificar : ","Error al ingresar id venta");
        ventas_modificacion(eVentas,CANTVENTAS,idVentasBuscado);
        break;

        case 6:
        ventas_listado(eVentas,CANTVENTAS);
        utn_getInt(&idVentasBuscado,5,"\nIngrese Id Venta a Cobrar : ","Error al ingresar id venta");
        if (clientes_existeId(eClientes,CANTCLIENTES,eVentas[idVentasBuscado].idCliente) == 0 &&
            ventas_existeId(eVentas,CANTVENTAS,idVentasBuscado)== 0)
        {
            clientes_mostrarDatos(eClientes, CANTCLIENTES, eVentas[idVentasBuscado].idCliente);
            utn_getInt(&aux,3,"\nPara confirmar Pulse 3 :","Error Opcion Cobrar\n");
            if (aux==3)
            {
                ventas_cobrar(eVentas,CANTVENTAS, idVentasBuscado);
            }
        }
        break;

        case 7:
        for(j=0;j<CANTCLIENTES;j++)
        {
            contador=0;
            if (eClientes[j].isEmpty ==0)
            {
                printf("Nombre Cliente : %s , %s \n",eClientes[j].nombre,eClientes[j].apellido);
                printf("CUIT : %s ",eClientes[j].cuit);
                printf(" Id : %d \n",eClientes[j].id);
                for ( k=0;k<CANTVENTAS;k++)
                {
                    if (eVentas[k].idCliente==eClientes[j].id && eVentas[k].isEmpty==0 && strncmp(eVentas[k].estado,"a cobrar",strlen("a cobrar"))==0)
                    {
                        contador++;
                    }
                }
                printf("Cantidad de ventas a cobrar = %d \n", contador);
            }
        }
        break;

        case 8:
        listados_clientes_ordenarPorApellido(eClientes, CANTCLIENTES);
        break;

        case 9:
        listados_ventasPorIdCliente(eClientes,CANTCLIENTES, eVentas, CANTVENTAS);
        break;

        case 10:
        listados_clientesPorCantidadAfiches(eClientes,CANTCLIENTES, eVentas,CANTVENTAS);
        break;

        case 11:
        informes_clientesConMasVentasCob(eClientes,CANTCLIENTES, eVentas, CANTVENTAS,1);
        break;

        case 12:
        informes_clientesConMasVentasCob(eClientes,CANTCLIENTES, eVentas, CANTVENTAS,2);
        break;

        case 13:
        informes_clientesMenosVentas(eClientes,CANTCLIENTES,eVentas, CANTVENTAS, 1000);
        break;


        case 99:
        system("clear");
        printf("Exit");
        break;

        default:
        printf("\nOpcion Incorrecta!!\n");
        system("clear");
    }
    }while (opcion !=salir );

    return 0;
}


