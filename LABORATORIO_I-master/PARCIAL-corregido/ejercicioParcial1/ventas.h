#ifndef VENTAS
#define VENTAS


typedef struct
{
    int idCliente;
    int cantAfiches;
    char nombreArchivo[100];
    char zona[100];
    int idVenta;
    int isEmpty;
    char estado[50];
}ventas;

int ventas_alta(ventas* array,int limite,int idCliente);
int ventas_menu(char* opcionesMenu,ventas* array, int limite);
int ventas_init(ventas* array,int limite);
int baja_ventas(ventas* array,int limite, int idCliente);
int ventas_modificacion(ventas* array,int limite,int idVenta);
int ventas_listado(ventas* array, int limite);
int ventas_existeId(ventas* array, int limite, int idBuscar);
ventas* ventas_getElementById(ventas* array,int limite,int idBuscado);
int ventas_cobrar(ventas* array,int limite, int idVenta);
int ventas_filler(ventas* array,int limite, int idCliente,int cantAfiches, char* nombreArchivo, char* zona, char* estado);
int ventas_buscarLugarVacio(ventas* array, int limitearray);

#endif
