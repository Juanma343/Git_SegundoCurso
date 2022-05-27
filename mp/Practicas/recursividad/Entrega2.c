#include <stdio.h>
#include <string.h>
#include <math.h>

//problema 5

int parejas(int* A, int n){
    return parejas_rec(0, A, n);
}

int parejas_rec (int i, int* A, int n){

    if (i + 3 >= n){
        return 0;
    }
    else{
        if(A[i] + A[i+1] == A[i+2] + A[i+3]){
            return 1;
        }
        else{
            return parejas_rec(++i, A, n);
        }
    }
}

//funcion imprimir vector;

char* ImprimirVec(int* a, int n){
    char* b = (char*) malloc(n*sizeof(char));
    char* aux = (char*) malloc(n*sizeof(char));
    int i = 0;
    while (i < n){
        sprintf(aux, "%d", a[i]);
        strcat(b, aux);
        strcat(b, " ");
        i++;
    }
    return b;
}

//main
int main(){
    int a[6] = {4, 0, 2, 4, 3, 3};
    int b[7] = {9, 3, 5, 7, 8, 2, 3};
    int resultado = parejas(a, 6);
    printf("Vectores del producto:\n%s\n%s\nResultado: %i\n", ImprimirVec(a, 6), ImprimirVec(b, 7), resultado);
    return 0;
}