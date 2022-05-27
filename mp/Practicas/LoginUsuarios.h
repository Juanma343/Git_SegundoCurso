#ifndef __LOGINUSUARIO__
#define __LOGINUSUARIO__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id_usuario;
    char Nomb_usuario[21];
    int Perfil_usuario;     //si es administrador es 0, si es profeso es 1
    char Usuario[6];
    char Contrasenna[9];
} usuario;


//pre: que el txt este en el en el directorio donde se alojan los archivos
//pos: Un vector de la estructura usuario cargada con la informacion del archivo
void cargarUsuarios(usuario* vUsuarios, int nUsuarios);

//pre: el vector de datos a alojar
//pos: al,acena en el archivo elejido 
void descargarUsuarios(usuario* vUsuarios, int nUsuarios);

//pre:
//poscaoncicion; pausa la ejecucion del codigo hasta que se inicie sesion algien correctamente 
void menuPrincipal();

//pre: se le da el vector de usuarios
//pos: muetra las diferentes opciones y las realiza
void gestionarUsuario(usuario*);


#endif