#include "LoginUsuarios.h"

//esta es una estructura de apoyo la cual se utiliza en los usuarios para facilitar la rapidez a la hora de deccidir el numero nuevo en el sistema
//consiste en un vector de booleanos(como en c no hay de enteros), que guardan un uno si ese id esta en uso y un 0 si no lo esta
//de esta forma tenemos controlados el numeo de ids disponibles de foma mas sencill y visible
//ademas la estructura almacenara la menor id disponible lo que sumado a que este vector tiempre estara ordenado aumenta la eficuencia de la eleccion de entero
//esto para numero pequeños no es realmete un coste demasiado dispar al de este pero teneiendo pero esto creo que es lo realmente correcto para los casos generales sin ver el contezto de este proyecto
struct identificacion_usuario
{
    int numero[1000];
    int ultimo;
};

struct identificacion_usuario identificacion;


int iniciarSesion(char* s_usuario, char* s_contraseñnna, usuario* vUsuario, int nUsuario);
void dardeAltaUsuario(usuario*, int* nUsuario);
void dardeBajaUsuario(usuario*, int* nUsuario);
void modificarUsuario(usuario*, int* nUsuario);
void listaUsuarios(usuario*, int* nUsuario);
void siguenteid();
void descartarid(int n);

int iniciarSesion(char* s_usuario, char* s_contrasenna, usuario* vUsuario, int nUsuario){

    int i = 0;
    int salida = 0;

    do {

        if (strcmp(s_usuario, vUsuario[i].Usuario) == 0){
            if (strcmp(s_contrasenna, vUsuario[i].Contrasenna) == 0){
                salida = 1;
            }
        }

    } while (salida || i < nUsuario);

    return salida;
        
}

void dardeAltaUsuario(usuario* vUsuario, int* nUsuario){

    char* ci;   //cadena intermedia
    char ca;    //caracter administrador

    ci = (char *) malloc(100*sizeof(char));

    int control = 0;

    vUsuario = (usuario*)realloc(vUsuario, ++(*nUsuario) * sizeof(usuario));

    do{
        control = 0;
        printf("Datos del nuevo usuario:\n\nNombre:");
        scanf("%s", ci);
        if (ci[0] == '\0'){
            printf("Error, no ha escrito ningun nombre, intentelo de nuevo.");
            get();
            control = 1;
        }
        else if(strlen(ci)>6){
            printf("Error, el usuario es demasiado largo, intentelo de nuevo.");
            get();
            control = 1;
        }
        else {
            strcpy(vUsuario[*nUsuario].Usuario, ci);
        }
    }while(control);
    do{
        control = 0;
        printf("Contrase%ca;", 164);
        scanf("%s", ci);
        if (ci[0] == '\0'){
            printf("Error, no ha escrito ninguna contraseña, intentelo de nuevo.");
            get();
            control = 1;
        }
        else if(strlen(ci)>9){
            printf("Error, la contrase%ca es demasiado larga, intentelo de nuevo.", 164);
            get();
            control = 1;
        }
        else{
            strcpy(vUsuario[*nUsuario].Contrasenna, ci);
        }
    }while(control);
    do{
        control = 0;
        printf("Nombre del usuario:");
        scanf("%s", ci);
        if (ci[0] == '\0'){
            strcpy(vUsuario[*nUsuario].Nomb_usuario, "ANONIMO");
        }
        else if(strlen(ci>21)){
            printf("Error, el nombre es demasiado larga, introduce solo el primer apellido o utiliza abreviatura.");
            get();
            control = 1;
        }
        else{
            strcpy(vUsuario[*nUsuario].Nomb_usuario, ci);
        }
    }while(control);
    do{
        control = 0;
        printf("%csera un usuario administrador? (s/n)\n");
        scanf("%c", &ca);
        if (ca == 's' || ca == 'S'){
            vUsuario[*nUsuario].Perfil_usuario = 0;
        }
        else if(ca == 'n' || ca == 'N'){
            vUsuario[*nUsuario].Perfil_usuario = 1;
        }
        else {
            printf("Error, no es uno de los caracteres permitidos, intentelo de nuevo.");
            get();
            control = 1;
        }
    }while(control);
    
    if (identificacion.numero[0] > 0){
        vUsuario[*nUsuario].id_usuario = identificacion.ultimo;
        siguienteid();
    }
    
}


//da de baja un usuario

void dardeBajaUsuario(usuario* vUsuario, int* nUsuario){

    
}