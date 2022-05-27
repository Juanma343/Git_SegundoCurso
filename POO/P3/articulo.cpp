#include "articulo.hpp"

Articulo::Articulo(const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio, size_t existencias = 0):referencia_(referencia), titulo_(titulo), fechaDePublicacion_(fechaDePublicacion), precio_(precio), existencias_(existencias) {

}

Articulo::~Articulo(){}

std::ostream& operator << (std::ostream& os,const Articulo pro){
    os << "[" << pro.referencia() << "] \"" << pro.titulo() << "\", " << pro.f_publi().anno() << ". " << pro.precio() << " €" << std::endl;
    return os;
}