#include "usuario.hpp"
#include "tarjeta.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iomanip>
//stekey(key)
//playdes(vector de 16, cadena)
//kickdes(al reves que el anterios)



Clave::Clave(const char* contrasenna){
    const char* crypto = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210/.";
    char* cifrar = new char [2];

    if(strlen(contrasenna) < 5)
    {
        throw Incorrecta(Razon::CORTA);
    }

    cifrar[0] = crypto[rand() % 64];
    cifrar[1] = crypto[rand() % 64];

    if(crypt(contrasenna,cifrar) == NULL)
    {
        throw Incorrecta(Razon::ERROR_CRYPT);
    }

    contrasenna_ = crypt(contrasenna,cifrar);
}

bool Clave::verifica(char* contrasenna)const{
    return strcmp(crypt(contrasenna, contrasenna_.c_str()), contrasenna_.c_str()) == 0;
}

std::unordered_set<Cadena> Usuario::con_id;

Usuario::Usuario(Cadena id, Cadena nombre, Cadena apellidos, Cadena direccion, Clave contrasenna):identificador_(id), nombre_(nombre), apellidos_(apellidos), direccion_(direccion), contrasenna_(contrasenna){
    if (con_id.insert(id).second == false){
        throw Id_duplicado(id);
    }
}

void Usuario::compra(Articulo& arti,unsigned int cant)noexcept{
    if (cant != 0){
        cesta_[&arti] = cant;
    }
    else{
        cesta_.erase(&arti);
    }
}

void Usuario::es_titular_de(Tarjeta& tar)noexcept{
    if(this == tar.titular()){
        tarjetas_[tar.numero()] = &tar;
    }
    
}
void Usuario::no_es_titular_de(const Tarjeta& tar)noexcept{
    tarjetas_.erase(tar.numero());
}

Usuario::~Usuario(){
    for(auto it = tarjetas_.begin(); it != tarjetas_.end(); it++){
        it->second->anular_titular();
    }
    Cadena a (identificador_);
    con_id.erase(a);
}

std::ostream& operator<<(std::ostream& os,const Usuario& usuario){
    os << usuario.id() << " [" << usuario.contrasenna_.clave() << "] " << usuario.nombre() << " " << usuario.apellidos() << "\n" << usuario.direccion() << "\nTarjetas:" << "\n";
    for (auto it = usuario.tarjetas().begin(); it != usuario.tarjetas().end(); it++){
        os << *(it->second) << "\n";
    }
    return os;
}



std::ostream& mostrar_carro(std::ostream& os,const Usuario& us){
    os << "Carrito de compra de " << us.id() << " [Artículos: "<< us.n_articulos() << "]\n" << "Cant.Artículo" << std::endl
       << std::setw(100) << std::setfill('=') << '\n' << std::endl;

        for(auto i = us.compra().begin(); i != us.compra().end(); i++){
            os << std::setw(4) << i->second << "    [" << (*i->first).referencia() << "] \"" << (*i->first).titulo() << "\", " << (*i->first).f_publi().anno() << ". " << std::fixed << std::setprecision(2) << (*i->first).precio() << " €" << std::endl;
        }
    return os;
}