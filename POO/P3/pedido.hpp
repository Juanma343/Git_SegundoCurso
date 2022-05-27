#ifndef _PEDIDO_HPP_
#define _PEDIDO_HPP_

//3,5,4,2(relacion pedido tarjeta),1(modificar)
//objetos funcion //importante
#include "tarjeta.hpp"
#include "articulo.hpp"
//#include "usuario_pedido.hpp"


class Pedido_Articulo;
class Usuario_Pedido;

class Pedido{
    public:
        Pedido(Usuario_Pedido& usped, Pedido_Articulo& pedar, Usuario& usr, const Tarjeta& tar, const Fecha& fec = Fecha());
        class Vacio{
            public:
                Vacio(Usuario& U): usuario_(&U){}
                Usuario& usuario()const{return *usuario_;}
            private:
                Usuario* usuario_;
        };
        class Impostor{
            public:
                Impostor(Usuario& U): usuario_(&U){}
                Usuario& usuario()const{return *usuario_;}
            private:
                Usuario* usuario_;
        };//clear para el caso de que las existencias superen el carro
        class SinStock{
            public:
                SinStock(Articulo* A): articulo_(A){}
                Articulo& articulo()const{return *articulo_;}
            private:
                Articulo* articulo_;
        };
        int numero() const{return numero_pedido;}
        const Tarjeta* tarjeta() const{return tarjeta_;}
        const Fecha& fecha() const{return fecha_pedido;}
        double total() const{return total_;}
        static unsigned int n_total_pedidos() {return cantidad;}
    private:
        int numero_pedido;
        const Tarjeta* tarjeta_;
        Fecha fecha_pedido;
        double total_;
        static unsigned int cantidad;//m
};

std::ostream& operator << (std::ostream& os, Pedido pe);

#endif