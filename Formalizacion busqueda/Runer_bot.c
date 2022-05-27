#include <stdio.h>
#include "Runer_bot.h"


tEstado* crearEstado (int **estado){
    int i, j;
    tEstado *nuevo;
    nuevo = (tEstado*)malloc(sizeof(tEstado));

    for (i=0; i<N; i++){
        for (i=0; j<N; j++){
            nuevo->tablero[i][j] = estado[i][j];
            if (estado[i][j]==1){
                nuevo->posx[RATON] = i;
                nuevo->posy[RATON] = j;
            }
            if (estado[i][j]==2){
                nuevo->posx[ROBOT] = i;
                nuevo->posy[ROBOT] = j;
            }
        }
    }

    return nuevo;
}

tEstado* crearEstadoInicial(){

    return crearestado(tableroInicial);
}

int esValido(tEstado* estado, int op){
    switch (OP)
    {
    case ARRIBA:
        if(estado->posy[ROBOT] > 0 && estado->tablero[estado->posx[ROBOT]][estado->posy[ROBOT]-1] == 0 
        && !(estado->posx[RATON]-1 == estado->posx[ROBOT] && estado->posy[RATON]-1 == estado->posy[ROBOT]-1)){
            return 1;
        }
        break;
    
    case ABAJO:
        if(estado->posy[ROBOT] < N && estado->tablero[estado->posx[ROBOT]][estado->posy[ROBOT]+1] == 0 
        && !(estado->posx[RATON]-1 == estado->posx[ROBOT] && estado->posy[RATON]-1 == estado->posy[ROBOT]+1)){
            return 1;
        }
        break;

    case IZQ:
        if(estado->posx[ROBOT] > 0 && estado->tablero[estado->posx[ROBOT]-1][estado->posy[ROBOT]] == 0 
        && !(estado->posx[RATON]+1 == estado->posx[ROBOT]-1 && estado->posy[RATON]+1 == estado->posy[ROBOT])){
            return 1;
        }
        break;

    case DER:
        if(estado->posx[ROBOT] < N && estado->tablero[estado->posx[ROBOT]+1][estado->posy[ROBOT]] == 0 
        && !(estado->posx[RATON]+1 == estado->posx[ROBOT]+1 && estado->posy[RATON]+1 == estado->posy[ROBOT])){
            return 1;
        }
        break;
    }
    return 0;
}

tEstado* aplicaOperador(tEstado* estado, int op){
    tEstado* nuevo = (tEstado*)malloc(sizeof(tEstado));
    memcpy(nuevo,estado,sizeof(tEstado));

    switch (op)
    {
    case ARRIBA:
        nuevo->posx[ROBOT] = estado->posx[ROBOT];
        nuevo->posy[ROBOT] = estado->posx[ROBOT]-1;
        nuevo->posx[RATON] = estado->posx[RATON]-1;
        nuevo->posy[RATON] = estado->posx[RATON]-1;
        nuevo->tablero[nuevo->posx[ROBOT]][nuevo->posy[ROBOT]] = ROBOT;
        nuevo->tablero[estado->posx[ROBOT]][estado->posy[ROBOT]] = 0;
        nuevo->tablero[nuevo->posx[RATON]][nuevo->posy[RATON]] = RATON;
        nuevo->tablero[estado->posx[RATON]][estado->posy[RATON]] = 0;

        break;
    
    case ABAJO:
        
        
        break;

    case IZQ:
        
        break;

    case DER:
        
        break;
    }
    return nuevo;
}