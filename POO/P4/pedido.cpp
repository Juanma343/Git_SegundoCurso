#include "pedido.hpp"
#include "pedido-articulo.hpp"
#include "usuario-pedido.hpp"
#include <iomanip>

unsigned int Pedido::cantidad = 0;

Pedido::Pedido(Usuario_Pedido& usped, Pedido_Articulo& pedar, Usuario& usr,const Tarjeta& tar, const Fecha& fec): numero_pedido(cantidad + 1), tarjeta_(&tar), fecha_pedido(fec), total_(0) {
    
    
    if(tarjeta_->caducidad() < fec)//preguntar
    {
        throw Tarjeta::Caducada(tarjeta_->caducidad());
    }

    if(usr.n_articulos() == 0)
    {
        throw Vacio(usr);
    }

    if(tarjeta_->titular() != &usr )
    {
        throw Impostor(usr);
    }

    if(tarjeta_->activa() != true)
    {
        throw Tarjeta::Desactivada();
    }
    
    auto carro = usr.compra();

    int cont = 0;

    for(auto i: carro){
        if(ArticuloAlmacenable * ar = dynamic_cast<ArticuloAlmacenable*>(i.first)){
            if (ar->stock() < i.second){
                const_cast<Usuario::Articulos&>(usr.compra()).clear();//que hace const cast
                throw SinStock(i.first);
            }
            cont++;
        }
    }
    if (cont == 0){
        throw Vacio(usr);
    }
    carro = usr.compra();
    for(auto it: carro){
        if(ArticuloAlmacenable * ar = dynamic_cast<ArticuloAlmacenable*>(it.first)){
            pedar.pedir(*(ar), *this, ar->precio(), it.second);
            ar->stock() -= it.second;
            total_ += ar->precio() * it.second;
            usr.compra().erase(ar);
        }
        else if(LibroDigital * li = dynamic_cast<LibroDigital*>(it.first)){
            if(li->f_expir() > fec){
                pedar.pedir(*(li), *this, li->precio(), it.second);
                total_ += li->precio() * it.second;
                usr.compra().erase(li);
            }
            else{
                usr.compra().erase(li);
            }
        }
    }
    usped.asocia(*this, usr);
    ++cantidad;
        
    
}

std::ostream& operator << (std::ostream& os, Pedido pe){//problemas enseñar cout

    os << "Núm. pedido: " << pe.numero() << std::endl;
    os << "Fecha:       " << pe.fecha() << std::endl;
    os << "Pagado con:  " << pe.tarjeta()->tipo() << " n.º: "<< pe.tarjeta()->numero() << std::endl;
    os << "Importe:     " << std::fixed << std::setprecision(2) << pe.total() << " €" << std::endl;
    return os;

}
