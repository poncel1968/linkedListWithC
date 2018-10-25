#include "informes.h"

typedef struct
{
    int idCliente;
    int cantAfiches;

}clienteMasVentaCob;



/*
@brief : cliente con mas ventas a cobrar
@param : array de la estructura clientes
@param : limite de la estructura clientes
@param : array de la estructura ventas
@param : limite de la estructura ventas
@value : 0 is successful
*/
int informes_clientesConMasVentasCob(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVentas)
{
///array auxiliar
clienteMasVentaCob auxiliar[limiteCliente];
clienteMasVentaCob;
cliente* pCliente;


int i,j,k=0;
int acumulador,flag=1;
for (i=0;i<limiteCliente;i++)
{
    acumulador=0;
    if (arrayClientes[i].isEmpty==0)
    {
       for(j=0;j<limiteVentas;j++)
        {
            if (arrayVentas[j].idCliente==arrayClientes[i].id && arrayVentas[j].isEmpty==0 && strncmp(arrayVentas[j].estado,"a cobrar",strlen("acobrar")))
            {
               acumulador=acumulador+arrayVentas[j].cantAfiches;
            }
        }
    auxiliar[k].idCliente=arrayClientes[i].id;
    auxiliar[k].cantAfiches=acumulador;
    k++;
    }
}

///ordenamiento del array auxiliar
while(flag==1)
{
    flag=0;
    for (i=1;i<=k;i++)
    {
        if (auxiliar[i-1].cantAfiches<auxiliar[i].cantAfiches)
        {
            aux.cantAfiches=auxiliar[i].cantAfiches;
            aux.idCliente=auxiliar[i].idCliente;

            auxiliar[i].cantAfiches=auxiliar[i-1].cantAfiches;
            auxiliar[i].idCliente=auxiliar[i-1].idCliente;

            auxiliar[i-1].cantAfiches=aux.cantAfiches;
            auxiliar[i-1].idCliente=aux.idCliente;

            flag=1;
        }
    }
}

        printf(" Cliente con mas ventas a cobrar: %s, %s - Id: %d \n",pCliente->apellido,pCliente->nombre,pCliente->id);
        printf("  Cantidad afiches : --> %d \n",auxiliar[i].cantAfiches);


return 0;
}

