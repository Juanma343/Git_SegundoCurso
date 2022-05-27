#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 4

//problema 1

int iesimo_rec(int vec, int i){
    if (i == 0){
        return vec % 10;
    }
    else{
        vec /= 10;
        return iesimo_rec(vec, i);
    }
}


//problema 2

void MAXMIN(int* a, int* MAX, int* MIN, int tam){
    if (tam < 0){
        if (a[tam] < *MIN){
            *MIN = a[tam];
        }
        else if (a[tam] > *MAX){
            *MAX = a[tam];
        }
    tam--;
    MAXMIN(a, MAX, MIN, tam);
    }
}

//problema 3

int ProductoEscalar(int* a, int* b, int n){
    if (n -1 >= 0){
        return a[n-1] * b[n-1] + ProductoEscalar(a, b, --n);
    }
    else {
        return 0;
    }
}

//problema 4

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

//problema 6 (por exceso)

int sumapadresapo (int* A, int n){
    return sumapadresapo_rec (0, A, n);
}

int sumapadresapo_rec (int i, int* A, int n){
    
    if (i <= ceil((n-1)/2) -1){
        if (A[i] > A[2*(i+1)-1] && A[i] > A[2*(i+1)]){
            printf("hola");
            return A[i] + sumapadresapo_rec(++i, A, n);
        }
        else {
            return sumapadresapo_rec(++i, A, n);
        }
    }
    else {
        return 0;
    }
}

//problema 7


//problema 8
/*
int parejas(int* A, int n, int j, int k){
    return parejas8_rec(A, n, 0, j, k, 0, k, 0, 0);
}

int parejas8_rec(int* A, int n, int i, int j, int k, int ij, int ik, int sumj, int sumk){
    int con = 0;

    if (i == n){
        return 0;
    }
    else{
        if (ij < j){
            sumj += A[ij];
        }
        return con + parejas8_rec(A, n, i, j, k, ij, ik, sumj, sumk);
    }
}
*/
//problema 9

void matrizM(int n, int M[N][N]){
    matrizM_rec(n, 0, 0, M);
}

void matrizM_rec(int n, int i, int j, int M[N][N]){

    if (i == n){

    }
    else{
        if (j <= i){
            if (i == 0 && j == 0){
                M[i][j] = 1;
            }
            else if(j == 0){
                M[i][j] = M[i-1][i-1];
                M[j][i] = M[i][j];
            }
            else{
                M[i][j] = M[i][j-1] + M[i-1][j-1];
                M[j][i] = M[i][j];
            }
            j++;
        }
        else {
            i++;
            j = 0;

        }
        matrizM_rec(n, i, j, M);
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

//funcion imprimir matriz simetrica

char* ImprimirMaSim(int a[N][N], int n){
    char* b = (char*) malloc(n*n*n*sizeof(char));
    char* aux = (char*) malloc(n*sizeof(char));
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
            sprintf(aux, "%d", a[i][j]);
            strcat(b, aux);
            strcat(b, " ");
        }
        strcat(b, "\n");
    }
    return b;
}

//main vec
/*
int main(){
    int a[6] = {4, 0, 2, 4, 3, 3};
    int b[7] = {9, 3, 5, 7, 8, 2, 3};
    int resultado = parejas(a, 6);
    printf("Vectores del producto:\n%s\n%s\nResultado: %i\n", ImprimirVec(a, 6), ImprimirVec(b, 7), resultado);
    return 0;
}
*/

//main matriz sim

int main(){
    int a[N][N];
    matrizM(N, a);
    printf("%s\n Esta es la matriz simetrica generada\n", ImprimirMaSim(a, 4));
    return 0;
}