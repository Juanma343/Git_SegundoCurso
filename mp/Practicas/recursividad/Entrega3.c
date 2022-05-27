#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 4



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

int main(){
    int a[N][N];
    matrizM(N, a);
    printf("%s\n Esta es la matriz simetrica generada\n", ImprimirMaSim(a, 4));
    return 0;
}