#include "../TADS/Arboles/Abin_H.hpp"

//ejercicio 2
template <typename t>
Abin<t> reflejado (Abin<t> A){
    Abin<t> B;
    if (A.arbolVacio()){
        return B;
    }
    else{
        B.insertarRaiz(A.raiz());
        return reflejadoRec(A.raiz(), B.raiz(), A, B);
    }
}

template <typename t>
Abin<t> reflejadoRec (typename Abin<t>::nodo na, typename Abin<t>::nodo nb, Abin<t> A, Abin<t> B){
   
    if (A.hijoIzqdo(na) != Abin<t>::NODO_NULO){
        B.insertarHijoDrcho(A.hijoIzqdo(na), nb);
        reflejadoRec(A.hijoIzqdo(na), B.hijoDrcho(nb), A, B);
    }
    if (A.hijoDrcho(na) != Abin<t>::NODO_NULO){
        B.insertarHijoIzqdo(A.hijoDrcho(na), nb);
        reflejadoRec(A.hijoDrcho(na), B.hijoIzqdo(nb), A, B);
    }
    return B;

}

