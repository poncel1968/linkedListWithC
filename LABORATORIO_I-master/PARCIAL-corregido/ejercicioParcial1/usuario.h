

typedef struct{
    char nombre[100];
    char domicilio[200];
    char telFijo[15];
    char telMovil[15];
    char mail[100];
    char redSocial[100];
    int id;
    int isEmpty;
}usuario;

int usuario_init(usuario* nuevoUsuario,int limitearray);
int usuario_alta(usuario* nuevoUsuario,int limitearray);
int usuario_listar(usuario* usuario,int limitearray);
int usuario_buscarLugarVacio(usuario* array, int limitearray);
int usuario_filler(usuario* array, int limite, char* nombre, char* domicilio, char* telFijo );
int usuario_ordenarPorNombre(usuario* array, int limite);
int usuario_menu(char* opcionesMenu,usuario* array, int limite);
