#include "../TADS/Abin_busqueda.hpp"
#include <vector>

/**************************************************/
/* Ejercicio 1                                    */
/**************************************************/

template <typename t>
void eliminarSunarbol(const t& el){

    //busqueda no const
    Abb<t>* A = this;
    while(el != A->elemento()){
        if(el < A->elemento()){
            A = A->izqdo;
        }
        else if(el > A->elemento()){
            A = A->drcho;
        }
    }
    //eliminacion
    while(A->elemento() != nullptr){
        A->eliminar(A->elemento());
    }
}

/**************************************************/
/* Ejercicio 2                                    */
/**************************************************/

template <typename t>
void equilibrar(Abin<t>& A){
    std::vector<t> vec;
    extraedatos(vec, A);
    Abb<t> B;
    insertarDatos(B, vec, 0, vec.size() - 1);
    A = B;
}

template <typename t>
void extraedatos(std::vector<t>& vec, Abb<t> A){
    if (A.izqdo() == NULL ){
        extraedatos(vec, A.izqdo());
    }

    vec.push_back(A.elemento());

    if (A.drcho() == NULL ){
        extraedatos(vec, A.drcho());
    }
    
}

template <typename t>
void insertarDatos(Abb<t>& A, std::vector<t> vec, int inicio, int fin){
    A.~Abb();
    if(vec[(inicio + fin)/2] != NULL;){
        A.insertar(vec[vec.size()/2]);
        insertarDatos(A,Vec,inicio, (inicio + fin)/2);
        insertarDatos(A,Vec, (inicio + fin)/2, inicio);

    }
    
}

/**************************************************/
/* Ejercicio 3                                    */
/**************************************************/

template <typename t>
void equilibrar(Abin<t>& A){
    std::vector<t> vec;
    extraedatos2(vec, A, b);
    Abb<t> C;
    insertarDatos(B, vec, 0, vec.size() - 1);
    A = C;
}

template <typename t>
void extraedatos2(std::vector<t>& vec, Abb<t> A){
    if (A.izqdo() == NULL ){
        extraedatos(vec, A.izqdo());
    }

    vec.push_back(A.elemento());

    if (A.drcho() == NULL ){
        extraedatos(vec, A.drcho());
    }
    
}

template <typename t>
void insertarDatos(Abb<t>& A, std::vector<t> vec, int inicio, int fin){
    A.~Abb();
    if(vec[(inicio + fin)/2] != NULL;){
        A.insertar(vec[vec.size()/2]);
        insertarDatos(A,Vec,inicio, (inicio + fin)/2);
        insertarDatos(A,Vec, (inicio + fin)/2, inicio);

    }
    
}

//infimo

template <typename t>
const t& infimo(const t& e, Abb<t> A){
    return infimo_rec(e, A, e);
}

template <typename t>
const t& infimo_rec(const t& e, Abb<t> A, t& infi){
    if (A.vacio()){ // Árbol vacío, e no encontrado.

        return infi;

    }
    else if (e < A.elemento()){ // Buscar en subárbol izqdo.

        return A.izquierda().infimo_rec(e, A, infi);

    }
    else if (A.elemento() < e){ // Buscar en subárbol drcho.
        if(infi == e){
            infi = A.elemento();
        }
        else{
            infi = std::max(infi, A.elemento());
        }
        
        return A.derecha().infimo_rec(e, A, infi);

    }
    else{ // Encontrado e en la raíz.

        return infi;

    }
}