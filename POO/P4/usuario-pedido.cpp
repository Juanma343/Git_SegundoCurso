#include "usuario-pedido.hpp"

void Usuario_Pedido::asocia (Usuario& usr, Pedido& ped){usrPed[&usr].insert(&ped);pedUsr[&ped] = &usr;}
void Usuario_Pedido::asocia (Pedido& ped, Usuario& usr){usrPed[&usr].insert(&ped);pedUsr[&ped] = &usr;}