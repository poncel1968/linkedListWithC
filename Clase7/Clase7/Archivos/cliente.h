#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[64];
    char apellido[64];
    int id;
    int isEmpty;
}cliente;

cliente* cliente_newCliente(void);
int cliente_setNombre (cliente* aux,char* nombre);
int cliente_setId (cliente* aux,int id);
int cliente_isEmpty (cliente* aux[],int limite);
int cliente_getNombre(cliente* thi, char* nombre);
int cliente_setApellido (cliente* aux, char* apellido);
int cliente_init(cliente* aux[],int limite );
int cliente_deleteCliente(cliente* this);
cliente* cliente_newClienteParametros(char* nombre, char*apellido, int id, int isEmpty);

#endif // CLIENTE_H_INCLUDED
