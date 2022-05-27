int ProductoEscalar(int* a, int* b, int n){
    if (n -1 > 0){
        return a[n-1] * b[n-1] + ProductoEscalar(a, b, --n);
    }
    else {
        return 0;
    }

}
int main(){
    int a[4] = {1, 2, 3, 4};
    int b[4] = {4, 3, 2, 1};
    int resultado = ProductoEscalar(a, b, 4);
    printf("Vectores del producto:\n1, 2, 3 ,4\n4, 3, 2, 1\nResultado: %i", resultado);
    return 0;
}