#include <stdio.h>

#define N 7
#define RATON 1
#define ROBOT 2
#define ARRIBA 1
#define ABAJO 2
#define IZQ 3
#define DER 4

#ifndef _tEstructura_
#define _tEstructura_

typedef struct 
{
    int tablero[N][N];
    int posx[3];
    int posy[3];
}tEstado;

#endif

#ifndef _tableroInicial_
#define _tableroInicial_

int tableroInicial [N][N] = {
    {0,0,0,0,0,0,0},
    {0,-1,0,0,0,0,0},
    {0,-1,1,0,0,0,0},
    {0,0,0,-1,0,0,0},
    {0,0,0,0,0,0,0},
    {-1,0,-1,0,0,-1,0},
    {-1,-1,2,0,0,-1,0}
}

#endif

tEstado* crearEstado (int **estado);
tEstado* crearEstadoInicial();
int esValido(tEstado* estado, int op);
tEstado* aplicaOperador (tEstado* estado, int op);
int testObjetivo(tEstado* actual);