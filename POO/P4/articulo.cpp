#include "articulo.hpp"
#include <iomanip>

Articulo::Articulo(const Autores autores, const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio): autores_(autores), referencia_(referencia), titulo_(titulo), fechaDePublicacion_(fechaDePublicacion), precio_(precio) {
    if(autores_.empty()){
        throw Autores_vacios();
    }
}


std::ostream& operator << (std::ostream& os,const Articulo& pro){
    os << '[' << pro.referencia() << "] \"" << pro.titulo() << "\"" ;
    int cont = 0;
    for(auto i: pro.autores()){
        if(cont == 0){
            os << ", de ";
        }else{
            os << ", ";
        }+
        os << i->apellidos();
    }
    os << ". ";

    os << pro.f_publi().anno() << ". " << std::fixed << std::setprecision(2) << pro.precio() << " €" << std::endl << "\t";
	pro.impresion_especifica(os);

    return os;
}

void Libro::impresion_especifica(std::ostream& os)const{
    os  << n_pag_ << " págs., " << stock() << " unidades.";
}

void Cederron::impresion_especifica(std::ostream& os)const{
    os << MB_ << " MB, " << stock() << " unidades.";
}

void LibroDigital::impresion_especifica(std::ostream& os)const{
    os << "A la venta hasta el " << fechaExp_ << ".";
}
//