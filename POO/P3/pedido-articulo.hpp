#ifndef _PEDIDO_ARTICULO_HPP_
#define _PEDIDO_ARTICULO_HPP_

//#include "pedido.hpp"
#include "articulo.hpp"
#include <map>


class Pedido;

class LineaPedido{
    public:
        explicit LineaPedido(double precio, unsigned int cantidad = 1);

        const double& precio_venta()const{return precio_;}
        const unsigned int& cantidad()const{return cantidad_;}
    private:
        double precio_;
        unsigned int cantidad_;
};

std::ostream& operator << (std::ostream& os, LineaPedido lp);

class OrdenaArticulos{
    public:
        bool operator ()(const Articulo* ar1, const Articulo* ar2)const;
};

class OrdenaPedidos{
    public:
        bool operator ()(const Pedido* pe1, const Pedido* pe2)const;
};


class Pedido_Articulo{
    public:
        typedef std::map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
        typedef std::map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;

//no inline
        void pedir (Pedido& ped, Articulo& art, double precio, unsigned int cantidad);
        void pedir (Articulo& art, Pedido& ped, double precio, unsigned int cantidad);
//-----------------------------------------------

        ItemsPedido& detalle(Pedido& ped);
        const Pedidos& ventas(Articulo& art);

        std::ostream& mostrarDetallePedidos(std::ostream& os);
        std::ostream& mostrarVentasArticulos(std::ostream& os);
    private:
        std::map<Pedido*, ItemsPedido, OrdenaPedidos> pedArt;
        std::map<Articulo*, Pedidos, OrdenaArticulos> artPed;

};

std::ostream& operator << (std::ostream& os, const Pedido_Articulo::ItemsPedido& it);
std::ostream& operator << (std::ostream& os, const Pedido_Articulo::Pedidos& pe);

#endif