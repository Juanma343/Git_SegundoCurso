#include "pedido-articulo.hpp"
#include "pedido.hpp"
#include "usuario.hpp"
#include <iomanip>
#include <map>

bool OrdenaArticulos::operator ()(const Articulo* ar1,const  Articulo* ar2)const {
    return ar1->referencia() < ar2->referencia();
}
bool OrdenaPedidos::operator ()(const Pedido* pe1, const Pedido* pe2)const {
    return pe1->numero() < pe2->numero();
}

//linea pedidos

LineaPedido::LineaPedido(double precio, unsigned int cantidad): precio_(precio), cantidad_(cantidad) {}

std::ostream& operator << (std::ostream& os, LineaPedido lp){

    os << std::fixed << std::setprecision(2) << lp.precio_venta() << " €\t" << lp.cantidad();
    return os;
}

std::ostream& operator << (std::ostream& os, const Pedido_Articulo::ItemsPedido& it){

    double total = 0;
    os << "\n" ;
    os << "  PVP  " << "Cantidad\t\t" << "Articulos" << '\n' << std::endl;
    os << std::setw(30) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl;
    for (auto ite = it.begin(); ite != it.end(); ite++){
        os << ite->second.precio_venta() << " € " << ite->second.cantidad() << "\t" << "["<< ite->first->referencia() << "]\t\"" << ite->first->titulo() << "\"" << '\n' << std::endl;
        total += ite->second.precio_venta() * ite->second.cantidad();
    }
    os << std::setw(30) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl;
    os << "Total\t" << total << " €" << std::endl;

    return os;
}

std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::Pedidos& pe){
    double price = 0;
    unsigned t = 0;

    os << "\n" ;
    os << std::setw(70) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    os << "PVP \t Cant.\t Fecha venta\n" ;
    os << std::setw(70) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;

    for(auto it = pe.begin(); it != pe.end() ; it++){
        os << " " << it->second.precio_venta() << " €\t" << it->second.cantidad() << "\t" << it->first->fecha() << std::endl ;
        price = price + it->second.cantidad() * it->second.precio_venta() ;
        t += it->second.cantidad() ;
    }
    os << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    os << std::fixed << std::setprecision(2) << price << " €\t" << t << std::endl ;

    return os ;

}

void Pedido_Articulo::pedir (Pedido& ped, Articulo& art, double precio, unsigned int cantidad){
    
    pedArt[&ped].insert(std::make_pair(&art,LineaPedido(precio, cantidad)));
    artPed[&art].insert(std::make_pair(&ped,LineaPedido(precio, cantidad)));
}
void Pedido_Articulo::pedir (Articulo& art, Pedido& ped, double precio, unsigned int cantidad){

    pedArt[&ped].insert(std::make_pair(&art,LineaPedido(precio, cantidad)));
    artPed[&art].insert(std::make_pair(&ped,LineaPedido(precio, cantidad)));
}

Pedido_Articulo::ItemsPedido& Pedido_Articulo::detalle(Pedido& ped){

    return pedArt[&ped];
}

const Pedido_Articulo::Pedidos& Pedido_Articulo::ventas(Articulo& art){

    return artPed[&art];
}


std::ostream& Pedido_Articulo::mostrarDetallePedidos(std::ostream& os){
    
    double total = 0.0; 
    for(auto it = pedArt.begin(); it != pedArt.end(); it++){
        os << "Pedido núm." << it->first->numero() << "\t" ;
        os << "Cliente: " << it->first->tarjeta()->titular()->nombre() << "\t";
        os << "Fecha: " << it->first->fecha() << it->second;
        total = total + it->first->total();
    }
    os << "\nTOTAL VENTAS\t" << std::fixed << std::setprecision(2) << total << " €" << std::endl;
    return os;
}
std::ostream& Pedido_Articulo::mostrarVentasArticulos(std::ostream& os){

    for (auto it = artPed.begin(); it != artPed.end(); it++){
        os << "Ventas" << "[" << (it->first)->referencia() << "]" << "\"" << it->first->titulo() << "\"" << it->second << std::endl ;
    }
    return os;
}

//pedido_Articulos

