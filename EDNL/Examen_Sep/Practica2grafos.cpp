#include "../TADS/Grafos/grafoPMC.h"
#include "../TADS/Grafos/alg_grafoPMC.h"

//Ejercicio 1

//Ejercicio 2


struct casilla{
    size_t i, j;
    casilla(size_t x, size_t y): i(x), j(y){}
};

struct pared{
    casilla a;
    casilla b;
};

struct ruta{
    vector<casilla> C;
    int longi;
    ruta(vector<casilla> c, int longitud): C(c), longi(longitud){}
};

typename GrafoP<size_t>::vertice caminoNodo(casilla A, size_t n){
    return A.i * n + A.j;
}

casilla nodoCamino(typename GrafoP<size_t>::vertice A, size_t n){
    return casilla(A / n, A % n);
}

ruta laberinto(size_t N, vector<pared> paredes, casilla org, casilla des){
    GrafoP<size_t> G(N*N);
    for(int i = 0; i < paredes.size(); i++){
        pared p = paredes[i];
        G[caminoNodo(p.a, N)][caminoNodo(p.b, N)] = GrafoP<size_t>::INFINITO;
    }

    vector<typename GrafoP<size_t>::vertice> P;
    vector<size_t> costes = Dijkstra (G, caminoNodo(org, N), P);

    vector<casilla> cam;
    typename GrafoP<size_t>::vertice norg = caminoNodo(org, N);
    for (int i = 0; P[i] != norg; i++){
        cam.insert(cam.begin(), nodoCamino(P[i], N));
    }

    return ruta(cam, cam.size());

}

//Ejercicio 5

enum alergico {avion, tren, carretera};
typedef double dinero;
typedef typename GrafoP<dinero>::vertice ciudad;

template <typename t>
vector<ciudad> viajeroAler (alergico a, dinero d, ciudad c, GrafoP<dinero> avion, GrafoP<dinero> tren, GrafoP<dinero> carretera){
    if (a != 'avion'){
        matriz<ciudad> camAvion;
        matriz<dinero> cosAvion = Floyd(avion, camAvion);
    }
    if (a != 'tren'){
        matriz<ciudad> camtren;
        matriz<dinero> costren = Floyd(tren, camtren);
    }
    if (a != 'carretera'){
        matriz<ciudad> camcarretera;
        matriz<dinero> coscarretera = Floyd(carretera, camcarretera);
    }

    //mirar el de pedro

}

//Ejercicio 6