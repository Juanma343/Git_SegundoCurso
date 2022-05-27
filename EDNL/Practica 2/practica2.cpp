#include <iostream>
#include "../TADS/Abin_vec1_H.hpp"


/*--------------------------------------------------------*/
/* Problema 1                                             */
/*--------------------------------------------------------*/

template <typename t>
bool compararHijos(typename Abin<t>::nodo a, typename Abin<t>::nodo b){

    return (a != typename Abin<t>::NODO_NULO && b != typename Abin<t>::NODO_NULO) || (a == typename Abin<t>::NODO_NULO && b == typename Abin<t>::NODO_NULO);

}

template <typename t>
bool compararnulos(typename Abin<t>::nodo a, typename Abin<t>::nodo b){

    return (a == typename Abin<t>::NODO_NULO || b == typename Abin<t>::NODO_NULO);

}

template <typename t>
bool arbolesSim_rec(typename Abin<t>::Abin& A, typename Abin<t>::nodo a, typename Abin<t>::Abin& B, typename Abin<t>::nodo b){

    if (comparanulos(a, b)){    //caso en el que los dos que se le pasan son nulos
        return true;
    }
    if (compararHijos(A.hijoIzqdo(), B.hijoIzqdo()) && 
    compararHijos(A.hijoDrcho(), B.hijoDrcho())){   //compartacion de que son o los dos nodos con cosas o nulos
        return arbolesSim_vec(A, A.hijoIzqdo(), B, B.hijoIzqdo()) && arbolesSim_vec(A, A.hijoDrcho(), B, B.hijoDrcho());
    }
    else {
        return false
    }
}


template <typename t>
bool arbolesSim(typename Abin<t>::Abin& A, typename Abin<t>::Abin& B){

    if ( A.aroblVacio() == A.arbolVacio() ){
        return true;
    }
    else{
        return arbolesSim_vec(A, A.raiz(), B, B.raiz());
    }
}

/*--------------------------------------------------------*/
/* Problema 2                                             */
/*--------------------------------------------------------*/

template <typename t>
Abin<t>& arbolReflejo_rec(Abin<t> A, typename Abin<t>::nodo a){

    typename Abin<t>::Abin reflejo;
    reflejo.insertarRaiz(A.elemento(a));

    if (A.hijoDrcho != typename Abin<t>::NODO_NULO){
        reflejo.insertarHijoIzqdo(A.raiz(), arbolReflejo_rec(A, A.hijoDrcho(a)));
    }
    if (A.hijoIzqdo != typename Abin<t>::NODO_NULO){
        reflejo.insertarHijoDrcho(A.raiz(), arbolReflejo_rec(A, A.hijoIzqdo(a)));
    }

    return reflejo;
}


template <typename t>
Abin<t>& arbolReflejo(Abin<t> A){

    typename Abin<t>::Abin reflejo;

    if (!(a.arbolVacio())){ //si el arbol esta vacio devuelve reflejo vacio
    
        reflejo.insertarRaiz(A.raiz());
        if (A.hijoDrcho != typename Abin<t>::NODO_NULO){
            reflejo.insertarHijoIzqdo(reflejo.raiz(), arbolReflejo_rec(A, A.hijoDrcho(A.raiz())));
        }
        if (A.hijoIzqdo != typename Abin<t>::NODO_NULO){
            reflejo.insertarHijoDrcho(reflejo.raiz(), arbolReflejo_rec(A, A.hijoIzqdo(A.raiz())));
        }
        

    }
    
    return reflejo;
}

/*--------------------------------------------------------*/
/* Problema 3                                             */
/*--------------------------------------------------------*/


//no comprobar que sea arbol vacion
struct expresion
{
    char operador_;
    double numero_;
    expresion(char operador = 'n', int numero = 0) : operador_{operador}, numero_{numero}{}
};

//añadir nodo n
double solArbol_rec(Abin<expresion>::Abin& sol, Abin<expresion>::nodo a){

    if (sol.elemento(a).operador_ == '+'){
        return solArbol_rec(sol, sol.hijoIzqdo(a)) + solArbol_rec(sol, sol.hijoDrcho(a));
    }
    else if (sol.elemento(a).operador_ == '-'){
        return solArbol_rec(sol, sol.hijoIzqdo(a)) - solArbol_rec(sol, sol.hijoDrcho(a));
    }
    else if (sol.elemento(a).operador_ == '*'){
        return solArbol_rec(sol, sol.hijoIzqdo(a)) * solArbol_rec(sol, sol.hijoDrcho(a));
    }
    else if (sol.elemento(a).operador_ == '/'){
        return solArbol_rec(sol, sol.hijoIzqdo(a)) / solArbol_rec(sol, sol.hijoDrcho(a));
    }
    else if (sol.elemento(a).operador_ == 'n'){
        return sol.elemento(a).numero_;
    }
}

double solArbol(Abin<expresion>::Abin& sol){

    assert(sol.arbolVacio());

    if (sol.elemento(sol.raiz()).operador_ == '+'){
        return solArbol_rec(sol, sol.hijoIzqdo(sol.raiz())) + solArbol_rec(sol, sol.hijoDrcho(sol.raiz()));
    }
    else if (sol.elemento(sol.raiz()).operador_ == '-'){
        return solArbol_rec(sol, sol.hijoIzqdo(sol.raiz())) - solArbol_rec(sol, sol.hijoDrcho(sol.raiz()));
    }
    else if (sol.elemento(sol.raiz()).operador_ == '*'){
        return solArbol_rec(sol, sol.hijoIzqdo(sol.raiz())) * solArbol_rec(sol, sol.hijoDrcho(sol.raiz()));
    }
    else if (sol.elemento(sol.raiz()).operador_ == '/'){
        return solArbol_rec(sol, sol.hijoIzqdo(sol.raiz())) / solArbol_rec(sol, sol.hijoDrcho(sol.raiz()));
    }
    else if (sol.elemento(sol.raiz()).operador_ == 'n'){
        return sol.elemento(sol.raiz()).numero_;
    }
}

/*--------------------------------------------------------*/
/* Problema 4                                             */
/*--------------------------------------------------------*/

template <typename T>
class Abin2{
public:
    typedef size_t nodo;
    static const nodo NODONULLO;
    Abin& insertarRaiz(nodo n);
    Abin& insertarHijoIzquierdo(nodo n);
    nodo padre(nodo n);



private:
    T* nodos;
    nodo maxNodos;
    T elementoNullo;
    nodo altura(nodo n);    //
};

template <typename T>
Abin2<T>::nodo Abin2<T>::altura(Abin2<T>::nodo n){
    
    size_t p = 0, H = maxNodos;
    size_t raiz = maxNodos/2;
    size_t temp = 0;
    
    while (n != temp){
        if (n < temp){
            temp /= 2;
            p++;
        }
        else if(n > temp){
            temp = (maxNodos - temp) / 2;
            p++;
        }

    }
    while (H > 1)
    {
        H++;
    }
    


    return H - p;
}

/*--------------------------------------------------------*/
/* Problema nodos verdes                                  */
/*--------------------------------------------------------*/

template <typename t>
bool dosHijos(typename Abin<t>::Abin A, Abin<t>::nodo n){

    if (n == typename Abin<t>::NODO_NULO){
        return false;
    }
    else{
        if (A.hijoDrcho(n) == Abin<t>::NODO_NULO || A.hijoIzqdo(n) == Abin<t>::NODO_NULO){
            return false;
        }
        else{
            return true;
        }
    }
}

template <typename t>
bool unHijo(typename Abin<t>::Abin A, Abin<t>::nodo n){

    if (n == typename Abin<t>::NODO_NULO){
        return false;
    }
    else{
        if ((A.hijoDrcho(n) == Abin<t>::NODO_NULO && A.hijoIzqdo(n) == Abin<t>::NODO_NULO) || A.hijoDrcho(n) != Abin<t>::NODO_NULO && A.hijoIzqdo(n) != Abin<t>::NODO_NULO ){
            return false;
        }
        else{
            return true;
        }
    }
}


template <typename t>
typename Abin<t>::Abin nodosVerdes(typename Abin<t>::Abin A){

    if (A.arbolVacio() == true){
        return 0;   //conseideramos que el arbol vacio tiene 0 nodos verdes
    }
    else{
        if ((doshijos(A, A.hijoDrcho(A.raiz())) && unHijo(A, A.hijoIzqdo(A.raiz()))) || (doshijos(A, A.hijoIzqdo(A.raiz())) && unHijo(A, A.hijoDrcho(A.raiz())))){
            return 1 + nodosVerdes_rec(A, A.hijoDrcho) + nodosVerdes_rec(A, A.hijoIzqdo);
        }
        else{
            return 0 + nodosVerdes_rec(A, A.hijoDrcho) + nodosVerdes(A, A.hijoIzqdo);
        }
    }
} 

template <typename t>
typename Abin<t>::Abin nodosVerdes_rec(typename Abin<t>::Abin A){

    if (n == typename Abin<t>::NODO_NULO){
        return 0;
    }
    else{
        if ((doshijos(A, A.hijoDrcho(A.raiz())) && unHijo(A, A.hijoIzqdo(A.raiz()))) || (doshijos(A, A.hijoIzqdo(A.raiz())) && unHijo(A, A.hijoDrcho(A.raiz())))){
            return 1 + nodosVerdes_rec(A, A.hijoDrcho) + nodosVerdes_rec(A, A.hijoIzqdo);
        }
        else{
            return 0 + nodosVerdes_rec(A, A.hijoDrcho) + nodosVerdes_rec(A, A.hijoIzqdo);
        }
    }
} 

/*--------------------------------------------------------*/
/* Problema descendientes                                 */
/*--------------------------------------------------------*/

template <typename t>
int contarDescendientes_rec(Abin<t> A){
    if (A.arbolVacio() == true){
        return 0;
    }
    else{
        return contarDescendientes_rec(A,A.raiz);
    }
}


template <typename t>
int contarDescendientes_rec(Abin<t> A, typename Abin<t>::nodo n){

    if (n == Abin<t>::NODO_NULLO){
        return 0;
    }
    else {
        int altura = A.altura();
        if (altura = 2){
            if ((dosHijos(A,A.hijoDrcho(n)) || dosHijos(A,A.hijoIzqdo(n))) && (A.hijoDrcho(n) == Abin<t>::NODO_NULO && A.hijoIzqdo(n) == Abin<t>:: NODO_NULO)){
                return 1;
            }
        }
        else if (altura = 3){
            if (doshijos(A,n)){
                return 1;
            }
            else {
                if (doshijos(A,A.hijoDrcho(n)) || dosHijos(A,A.hijoIzqdo(n))){
                    return 1;
                }
                else if (dosHijos(A,A.hijoDrcho(n))){
                    typename Abin<t>::nodo co = A.hijoDrcho(n);
                    if (doshijos(A,A.hijoDrcho(co)) || dosHijos(A,A.hijoIzqdo(co))){
                        return 1;
                    }
                }
                else if (dosHijos(A,A.hijoIzqdo(n))){
                    typename Abin<t>::nodo co = A.hijoIzqdo(n);
                    if (doshijos(A,A.hijoDrcho(co)) || dosHijos(A,A.hijoIzqdo(co))){
                        return 1;
                    }
                }
            }
            
        }
        else if (altura = 4){
            if (!(dosHijos(A, n))){
                return 1;
            }
        }
        else{
            return contarDescendientes_rec(A, A.hijoDrcho(A.raiz)) + contarDescendientes_rec(A, A.hijoIzqdo(A.raiz));
        }
    }
}


/*--------------------------------------------------------*/
/* Problema nodos                                         */
/*--------------------------------------------------------*/

int nodosNivel(const Abin<t> A){
    int prof = 3, aux = 0, acum = 0;

    if(!(A.arbolVacio())){
        int H = alturaNodo(A.raiz(), A);
        while (prof < H + 1){
            aux = nodosNivel_rec(n, A.raiz(), A);
            if (aux == 3){
                acum += 3;
            }
            n++;
        }
    }
    return acum;
}

int nodosNivel_rec(int prof, Abin<t>::nodo no, const Abin<t> A){
    if (no != Abin<t>::NODO_NULO){
        if(prof == 0){
            return 1;
        }
        else {
            return nodosNivel_rec(prof - 1, A.hijoIzqdo(no), A) + nodosNivel_rec(prof -1 , A.hijoDrcho(no), A);
        }
    }
    else{
        return 0;
    }
}