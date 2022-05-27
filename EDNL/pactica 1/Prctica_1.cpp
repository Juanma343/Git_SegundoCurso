#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "abin_E-S.h"


//Problema 1

template <typename T>
int numeronodosabin(Abin<T> A){
    return numeronodosabin_Rec(A.raiz(),A);
}

template <typename T>
int numeronodosabin_Rec(nodo n, abin<t> A){ //poner siempre en la funcion recursiva las variables que cambien

    if (n == nullptr){              //se empieza por los casos escepcioneles y se poene en el else lo que hace la funcion
        return 0;
    }
    else{
        return 1 + numeronodosabin_Rec(n.hijoizquierdo(),A) + numeronodosabin_Rec(n.hijoderecho(),A);   //sdevuleve el 1 del nodo en el que esra mas la sumas de los nosdes de los dos hijos
    }

}

//Problema 2

template <typename T>
int alturaabin(Abin<T> A){
    return alturaabin_Rec(A.raiz(),A);
}

template <typename T>
int alturaabin_Rec(nodo n,Abin<T> T){
    //altira del arbol vacio es 0 y la del nodo nulo es dependiendo del profesor, para dlh es -1 pero una longitud negativa no tiene sentido
    if (n = nullptr){
        return -1;
    }
    else{
        return 1 + std::max(numeronodosabin_Rec(n.hijoizquierdo(),A),numeronodosabin_Rec(n.hijoderecho(),A))//la altura de un nodo es la maximas de sus hijos mas uno
        //la altura de una hoja es 0
    }
}

//Problema 3

template <typename T>
int profundidad( nodo n, Abin<T> A){    //no esta definido la profundidad de un arbol explicitamebte
                                        //intentar hacerlo en interativo en casa a josefi hacerle esta
    if (n == nullptr){
        return -1;
    }
    else{
        return 1 + profundidad(n.padre());
    }
    /*tambien sirve n= raiz del arbol ya que el enunciado dice que n sera un nodo del arbol, no hay posivilidad de que salga un nodo nulo
    if ( n == A.raiz()){
        return 0
    }*/
}

//problema 4 y 5

//no usar las funciones de antes por que es un tad y es menos eficiente
//usar la iterativa no la recursiva para los metodos de un tad
//leere directamente los datos de la estructura

//problemas 6
template <typename T>
int alturaNodo(nodo n, Abin<t> A){
    if (n == nullptr){
        return -1;
    }
    else{
        return 1 + alturaNodo(n.padre(),A);
    }
}

int max3 (int a, int b, int c){
    return std::max(std::max (a, b), c);
}

template <typename T>
int desequilibrioabin_Rec(nodo n, Abin<T> A){
    
    if(n == nullptr){
        return 0;
    }
    else{
        return max3(desequilibrioabin_rec(n.hijoizquierdo(),A),desequilibrioabin_rec(n.hijoderecho(),A),diffalt(n,A));  //max3 la funcion no deveria de funcianar no existe
    }
    
}

template <typename T>
int desequilibrioabin(Abin<T> A){                   //pide desequilibrio del arbol no del nodo, asi que hay que contar su propio deequilibrio
    return desequilibrioabin_Rec(A.raiz(),A);
}

int difalt (nodo n, Abin<t> A){
    return 
}

//ejercicio 7 enfoque iteractivo y por niveles
//pista recursiva en el caso de arvol vacio y de un solo nodo lo son 

template <typename T>
bool arbolSeudocompleto(abin<t> A){
    return arbolSeudocompleto_rec(nodo n, abin<t> A);
}

bool arbolSeudoestatico_rec( nodo n, abin<t> A){
    if (n == nullptr){
        return true;
    }
    else{
        if (alturaNodo() = alturaArbol(A)-1 AND (n.hijoizquierdo() = nullptr OR n.hijoderecho() = nullptr)){
            return = false;
        }
        else{
            return arbolSeudocompleto_Rec(n.hijoizquirdo(),A) AND arbolSeudocompleto_Rec(n.hijoderecho(),A);
        }
    }
}   //llamar a la altura tanntaz veces es muy ineficiente l aaltura es de orden n
//parte de la huerta

    si (altira hijos izquierod > altura arvol derecho){
        devolver la funcion del pseudocompleta de hijo izquierda
    }
    si no(altira hijos izquierod < altura arvol derecho){
        devolver la funcion del pseudocompleta de hijo derecha
    }
    else {
        return la funcion del pseudocompleta de hijo derecha and la funcion del pseudocompleta de hijo izquierda
    }