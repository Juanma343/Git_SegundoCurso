#ifndef _USUARIO_HPP_
#define _USUARIO_HPP_

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "articulo.hpp"
#include <iostream>
#include <unordered_set>
#include <map>
#include <unordered_map>


class Tarjeta;
class Numero;
class Clave{
    public:
        Clave() = default;
        Clave(const char* contrasenna);
        Cadena clave()const;
        bool verifica(char* contrasenna)const;

        enum  Razon{CORTA, ERROR_CRYPT};

        class Incorrecta{
            public:
                Incorrecta(Razon razon):razon_(razon){}
                Razon razon()const{return razon_;}
            private:
                Razon razon_;
        };
    private:
        Cadena contrasenna_;
};

inline Cadena Clave::clave()const{ return contrasenna_;}

class Usuario{
    public:
        Usuario(Cadena identificador, Cadena nombre, Cadena apellidos, Cadena direccion, Clave contrasenna);
        Usuario(const Usuario& a) = delete;
        typedef std::map<Numero , Tarjeta*> Tarjetas;
        typedef std::unordered_map<Articulo*, unsigned int> Articulos;

        const Cadena& id()const noexcept;
        const Cadena& nombre()const noexcept;
        const Cadena& apellidos()const noexcept;
        const Cadena& direccion()const noexcept;
        const Clave& clave()const noexcept;
        const Tarjetas& tarjetas()const noexcept;
        const Articulos& compra()const noexcept;
        Articulos& compra() noexcept;

        void compra(Articulo& arti,unsigned int cant = 1)noexcept;
        
        void es_titular_de(Tarjeta& tar)noexcept;
        void no_es_titular_de(const Tarjeta& tar)noexcept;

        unsigned int n_articulos()const noexcept;

        friend std::ostream& operator<<(std::ostream& os,const Usuario& usuario);

        ~Usuario();

        class Id_duplicado{
            public:
                Id_duplicado(Cadena error): error_(error){}
                Cadena idd()const{
                    return error_;
                }
            private:
                Cadena error_;
        };
    private:
        //Usuario(const Usuario&) = default;
        static std::unordered_set<Cadena> con_id;
        const Cadena identificador_;
        const Cadena nombre_;
        const Cadena apellidos_;
        const Cadena direccion_;

        Clave contrasenna_;

        Tarjetas tarjetas_;

        Articulos cesta_;

        void anula_titular();
};

inline const Cadena& Usuario::id()const noexcept{return identificador_;}//prefuntar
inline const Cadena& Usuario::nombre()const noexcept{return nombre_;}
inline const Cadena& Usuario::apellidos()const noexcept{return apellidos_;}
inline const Cadena& Usuario::direccion()const noexcept{return direccion_;}
//inline const Clave& Usuario::clave()const noexcept{return contrasenna_;}
inline const Usuario::Tarjetas& Usuario::tarjetas()const noexcept{return tarjetas_;}
inline const Usuario::Articulos& Usuario::compra()const noexcept{return cesta_;}
inline Usuario::Articulos& Usuario::compra()noexcept{return cesta_;}

inline unsigned int Usuario::n_articulos()const noexcept{
    return cesta_.size();
}

//std::ostream& operator<<(std::ostream& os,const Usuario& usuario);

//std::ostream& operator<<(std::ostream& os,const Usuario usuario);

std::ostream& mostrar_carro(std::ostream& so,const Usuario& us);

#endif