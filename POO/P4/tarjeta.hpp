#ifndef _TARJETA_HPP_
#define _TARJETA_HPP_

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include <unordered_set>

 
bool luhn(const Cadena& num);

class Clave;
class Usuario;
class Numero{
    public:
        enum Razon{DIGITOS, NO_VALIDO, LONGITUD};
        Numero(  const Cadena& cad);
        operator const char *()const;
        friend bool operator <(const Numero& n1, const Numero& n2);

        class Incorrecto{
        public:
            Incorrecto(Razon r): fallo_(r) {}
            const Razon& razon() const {return fallo_;};
        private:
            Razon fallo_;
        };
    private:
        Cadena numero;
        

};



class Tarjeta{
    public:
        Tarjeta(Numero numero, Usuario& titular, Fecha caducidad);
        Tarjeta(const Tarjeta& a) = delete;
        enum Tipo {Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress};

        const Numero& numero()const;
        const Usuario* titular()const{return titular_;}
        const Fecha& caducidad()const;
        const bool& activa()const;

        Tipo tipo()const;

        bool activa(bool nuevo = true);

        void anular_titular();

        ~Tarjeta();

        class Caducada{
            public:
                Caducada(Fecha fec):caducidad_(fec) {}
                Fecha cuando()const{return caducidad_;}
            private:
                Fecha caducidad_;
        };
        class Num_duplicado{
            public:
                Num_duplicado(Numero duplicado):duplicado_(duplicado) {}
                Numero que()const{return duplicado_;}
            private:
                Numero duplicado_;
        };
        class Desactivada{};
        
    private:
        
        static std::unordered_set<Numero> con_nu;
        const Numero numero_;
        mutable Usuario* titular_;
        const Fecha caducidad_;
        bool activa_;

};

std::ostream& operator <<(std::ostream& os, const Tarjeta::Tipo& tip);
std::ostream& operator <<(std::ostream& os, const Tarjeta& tar);
bool operator <(const Tarjeta& tar1, const Tarjeta& tar2);

namespace std{// Estaremos dentro del espacio de nombres std
template<>// Es una especialización de una plantilla para Cadena
struct hash<Numero> {// Es una clase con solo un operador publico
    size_t operator() (const Numero& cad)const// El operador función
    {
        hash<string>hs;// Creamos un objeto hash de string
        const char*p=cad;// Obtenemos la cadena de la Cadena
        string  s(p);// Creamos un string desde una cadena
        size_t  res=hs(s);// El hash del string. Como hs.operator()(s);
        return res;// Devolvemos el hash del string
    }
};
}

inline const Numero& Tarjeta::numero()const{return numero_;}
inline const Fecha& Tarjeta::caducidad()const{return caducidad_;}
inline const bool& Tarjeta::activa()const{return activa_;}

#endif