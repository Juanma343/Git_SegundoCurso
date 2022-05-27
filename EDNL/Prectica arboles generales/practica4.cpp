#include "../TADS/Agen_listas.hpp"
#include <algorithm>

/****************************/
/* Ejercicio 1              */
/****************************/

template <typename t>
int gradoAgen(Agen<t> A){
    if (A.arbolVacio()){
        return 0;
    }
    else{
        int i = 1;
        int tamañohijos = gradoAgen_rec(A, A.hijoIzqdo(A.raiz()));
        Abin::nodo aux = A.hermDrcho(A.raiz());
        while(aux != Abin::NODO_NULO){
            i++;
            aux = A.hermDrcho(aux);
            tamañohijos = std::max(tamañohijos, gradoAgen_rec(A, A.hijoIzqdo(aux)));

        }
        return std::max(i, tamañohijos);
    }
}

/****************************/
/* Ejercicio 2              */
/****************************/

//el mismo que abin

/****************************/
/* Ejercicio 2              */
/****************************/
template <typename t>
int gradodes(Abin<t> A){
    return gradoses(A, A.raiz());
}

template <typename t>
int gradodes_rec(Abin<t> A,typename Agen<t>::nodo n){
    if (n == Agen<t>::NODO_NULO){
        return 0;
    }
    else{
        int max = 0, min = 0, aux = 0;
        //typename Aben<t>::nodo n = A.hermDrcho(n);
        while (n != Agen<t>::NODO_NULO){
            aux = altura(A, n);
            if (aux < min){
                if (min > max){
                    max = min;
                }
                min = altura;
            }
            else if (aux > max){
                max = altura;
            }
            n = A.hermDrcho(n);
        }
        return max - min;
    }
}