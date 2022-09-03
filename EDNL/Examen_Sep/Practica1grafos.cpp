#include <iostream>
#include "..\TADS\Grafos\alg_grafoPMC.h"
#include "..\TADS\Grafos\grafoPMC.h"

template <typename tCoste>
matriz<tCoste> camindosZuelandia (GrafoP<tCoste> Zuelandia, const vector<typename GrafoP<tCoste>::vertice>& ciudades,const matriz<bool> carreteras, const typename GrafoP<tCoste>::vertice& capital){

    const tCoste infi = GrafoP<tCoste>::INFINITO;
    typedef typename GrafoP<tCoste>::vertice vertice;

    //ciudades
    for (vertice k = 0; k < ciudades.size() ; k++){
        for (vertice i = 0; i < Zuelandia.numVert(); i++){
            Zuelandia[i][ciudades[k]] = infi;
            Zuelandia[ciudades[k]][i] = infi;
        }
    }

    //caminos
    for (vertice i = 0; i < Zuelandia.numVert(); i++){
        for (vertice j = 0; j < Zuelandia.numVert(); j++){
            if (carreteras[i][j]){
                Zuelandia[i][j] = infi;
            }
        }
    }

    matriz<vertice> caminos;
    matriz<tCoste> caminosCorrectos = Floyd<tCoste>(Zuelandia, caminos);
    //falta al suma de los caminos de i hast k y de ka hast j 
    //mas eficiente dijistre y dijistre invertido pero en el examen hacer con floyd por si teiensd que impl,ementar la funcion
}

//Ejercicio 2

