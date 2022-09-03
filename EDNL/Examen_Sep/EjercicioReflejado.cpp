#include <iostream>
#include "..\TADS\Arboles\Abin_H.hpp"


//mi modo
template <typename t>
int ArbolRef(Abin<t> A){
    if (A.arbolVacio()){
        return 0;
    }
    else {
        ArbolRefaux(A, A.raiz());
    }
}

template <typename t>
int ArbolRefaux(Abin<t> A, typename Abin<t>::nodo n){
    if (n == Abin<t>::NODO_NULO){
        return 0;
    }
    else if (A.hijoDrcho(n) != Abin<t>::NODO_NULO && A.hijoIzqdo(n) != Abin<t>::NODO_NNULO){
        if (buscarRef(A, A.hijoIzqdo(n), A.hijoDrcho(n))){
            return 2 + ArbolRefaux(A, A.hijoIzqdo(n)) + ArbolRefaux(A, A.hijoDrcho(n));
        }
        else{
            return ArbolRefaux(A, A.hijoIzqdo(n)) + ArbolRefaux(A, A.hijoDrcho(n));
        }
    }
    else if (A.hijoDrcho(n) != Abin<t>::NODO_NULO){
        return ArbolRefaux(A, A.hijoDrcho(n));
    }
    else if (A.hijoIzqdo(n) != Abin<t>::NODO_NULO){
        return ArbolRefaux(A, A.hijoIzqdo(n));
    }
    
}

template <typename t>
bool buscarRef (Abin<t> A, typename Abin<t>::nodo a, typename Abin<t>::nodo b){

    if (a == Abin<t>::NODO_NULO && b == Abin<t>::NODO_NULO){
        return true;
    }
    else if (a == Abin<t>::NODO_NULO || b == Abin<t>::NODO_NULO){
        return false;
    }
    else if (A.elemento(a) == A.elemento(b)){
        return true && buscarRef(A, A.hijoDrcho(a), A.hijoIzqdo(a)) && buscarRef(A, A.hijoDrcho(b), A.hijoIzqdo(b));
    }
    else {
        return false;
    }
}