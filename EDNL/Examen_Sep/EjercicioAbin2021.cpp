#include <iostream>
#include "..\TADS\Arboles\Abin_H.hpp"

template <typename t>
void podaPropios(Abin<t>& A){
    if(!A.arbolVacio()){
        podaPropiosRec(A, A.raiz());
    }
}

template <typename t>
void podaPropiosRec(Abin<t>& A, typename Abin<t>::nodo n){
    if(n != Abin<t>::NODO_NULO){
        if(propios(A, n)){
            poda(A, n);
        }
        else{
            podaPropiosRec(A, A.hijoDrcho(n));
            podaPropiosRec(A, A.hijoIzqdo(n));
        }
    }
}

template <typename t>
bool propio(Abin<t> A, typename Abin<t>::nodo n){
    return arriba(A, n) && abajo(A, n);
}

template <typename t>
bool arriba(Abin<t> A, typename Abin<t>::nodo n){
    if (A.elemento(n) >= A.elemento(A.padre(n))){
        return true && arribaRec(A, n, A.padre(n));
    }
    else{
        return false
    }
}

//poner padre
template <typename t>
bool arribaRec(Abin<t> A, typename Abin<t>::nodo n, typename Abin<t>::nodo p){
    if (A.elemento(n) >= A.elemento(A.padre(p))){
        return true && arribaRec(A, n, A.padre(p));
    }
    else{
        return false
    }
}


template <typename t>
bool abajo(Abin<t> A, typename Abin<t>::nodo n){
    if (A.elemento(n) <= A.elemento(A.hijoDrcho(n)) && A.elemento(n) <= A.elemento(A.hijoIzqdo(n))){
        return true && abajoRec(A, n, A.hijoDrcho(n)) && abajoRec(A, n, A.hijoIzqdo(n));
    }
    else{
        return false
    }
}

template <typename t>
bool arribaRec(Abin<t> A, typename Abin<t>::nodo n, typename Abin<t>::nodo p){
    if (A.elemento(n) <= A.elemento(A.hijoDrcho(p)) && A.elemento(n) <= A.elemento(A.hijoIzqdo(p))){
        return true && abajoRec(A, n, A.hijoDrcho(p)) && abajoRec(A, n, A.hijoIzqdo(p));
    }
    else{
        return false
    }
}

template <typename t>
void poda(Abin<t>& A, typename Abin<t>::nodo n){
    if (esHoja(A.hijoIzqdo(n))){
    
    }
}

template <typename t>
bool esHoja(Abin<t>& A, typename Abin<t>::nodo n){
    if (A.hijoIzqdo(n) == Abin<t>::NODO_NULO && A.hijoDrcho(n) == Abin<t>::NODO_NULO){
        return true;
    }
    else
}