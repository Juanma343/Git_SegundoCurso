#include "../TADS/Arboles/Agen_listas.hpp"

template <typename t>
int desequilibrio(Agen<t> A){
    if (A.arbolVacio()){
        return 0;
    }
    else {
        return desequilibrioRec(0, A.raiz(), A);
    }
}

template <typename t>
int desequilibrioRec(int max, typename Agen<t>::nodo n, Agen<t> A){
    int max = 0, min = 0;
    while(n != Agen<t>::NODO_NULO){

    }
}