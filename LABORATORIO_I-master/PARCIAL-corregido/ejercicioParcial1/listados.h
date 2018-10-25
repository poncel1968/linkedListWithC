#ifndef LISTADOS
#define LISTADOS

int listados_clientes_ordenarPorApellido(cliente* array, int limite);
int listados_ventasPorIdCliente(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVentas);
int listados_clientesPorCantidadAfiches(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVentas);
int listados_clientesPorCantidadAfiches(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVentas);
int informes_clientesConMasVentasCob(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVentas, int cobradaOno);
int informes_clientesMenosVentas(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVenta, int cantidad);

#endif
