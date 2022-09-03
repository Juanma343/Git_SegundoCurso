#include "../TADS/Arboles/Agen_listas.hpp"

struct persona
{
    double dinero;
    bool estado;        //0 muerto 1 vivo
};

void muere(Agen<persona> A, typename Agen<persona>::nodo n){
    //mirar nodo nulo
    if(descendiente(A, n)){
        muereRec(A, n, A.elemento(n).dinero);
    }
    A.elemento(n).dinero = 0;   
    A.elemento(n).estado = false;

}

void muereRec(Agen<persona>& A, typename Agen<persona>::nodo n, double d){
    //mirar nodo nulo
    int n = contarHijos(A, n);
    if (n != 0){
        double riqueza = d / n;
        Agen<persona>::nodo hijo = A.hijoIzqdo(n);
        while (hijo != Agen<persona>::NODO_NULO){
            if(A.elemento(hijo).estado == 1){
                A.elemento(hijo).dinero += riqueza;
            }
            else{
                muereRec(A, hijo, riqueza);
            }
            hijo = A.hermDrcho(hijo);
        }
    }
    
}
        

bool descendiente(Agen<persona> A, typename Agen<persona>::nodo n){
    //contar nodo nulo
    Agen<persona>::nodo hijo = A.hijoIzqdo(n);
    bool aux = false;
    while(hijo != Agen<persona>::NODO_NULO){
        if(A.elemento(hijo).estado){
            return true;
        }
        else {
            aux = aux && descendiente(A, hijo);
        }
    }
    if (hijo == Agen<persona>::NODO_NULO){
        return aux;
    }
}

int contarHijos(Agen<persona> A, typename Agen<persona>::nodo n){
    Agen<persona>::nodo hijo = A.hijoIzqdo(n);
    int aux = 0;
    while(hijo != Agen<persona>::NODO_NULO){
        if(A.elemento(hijo).estado){
            aux++;
        }
        else if(descendiente(A, hijo)){
            aux++;
        }
    }
    return aux;
}