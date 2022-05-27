#ifndef _USUARIO_PEDIDO_HPP_
#define _USUARIO_PEDIDO_HPP_

#include "usuario.hpp"
#include "pedido.hpp"

class Usuario_Pedido{
    public:
        void asocia (Usuario& usr, Pedido& ped);
        void asocia (Pedido& ped, Usuario& usr);

        std::unordered_set<Pedido*>& pedidos (Usuario& usr){return usrPed.at(&usr);}
        Usuario* cliente (Pedido& ped){return pedUsr.at(&ped);}
    private:
        std::unordered_map<Usuario*, std::unordered_set<Pedido*>> usrPed;
        std::unordered_map<Pedido*, Usuario*> pedUsr;
};

#endif