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

    for(auto i: carro){
        if (i.first->stock() < i.second){
            const_cast<Usuario::Articulos&>(usr.compra()).clear();
            throw SinStock(i.first);
        }
    }
    carro = usr.compra();
    for(auto it: carro){
        pedar.pedir(*(it.first), *this, it.first->precio(), it.second);
        it.first->stock() -= it.second;
        total_ += it.first->precio() * it.second;
        usr.compra().erase(it.first);
    }
    usped.asocia(*this, usr);
    ++cantidad;
        
    
}

std::ostream& operator << (std::ostream& os, Pedido pe){

    os << "Núm. pedido: " << pe.numero() << std::endl;
    os << "Fecha:       " << pe.fecha() << std::endl;
    os << "Pagado con:  " << pe.tarjeta()->tipo() << " n.º: "<< pe.tarjeta()->numero() << std::endl;
    os << "Importe:     " << std::fixed << std::setprecision(2) << pe.total() << " €" << std::endl;
    return os;

}
