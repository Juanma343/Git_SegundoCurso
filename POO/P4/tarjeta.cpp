#include "tarjeta.hpp"
#include "usuario.hpp"
#include "cadena.hpp"
#include <cstddef>
#include <ctype.h>
#include <algorithm>
#include <functional>

Cadena quitaespacios(const Cadena& cad)
{
    Cadena aux (cad) ;

    std::remove_if(aux.begin(),aux.end()+1,[](char a){return isspace(a);});

    return Cadena(aux.c_str()) ;
}

bool esNumero(char* a){
    int i = 0;
    while(a[i] != '\0'){
        if(!(isdigit(a[i]))){
            return false;
        }
        i++;
    }
    
    return true;
}

struct EsDigito{
    public:
        bool operator ()(char a)const {
            return isdigit(a);
        }
        typedef char argument_type;
};

Numero::Numero(const Cadena& cad): numero(quitaespacios(cad)){
    

    //comprobar
    if (numero.length() <= 13 || numero.length() > 19){
        throw Incorrecto(Razon::LONGITUD);
    }
    else if(std::find_if(numero.begin(), numero.end(), std::not1(EsDigito())) != numero.end()){
        throw Incorrecto(Razon::DIGITOS);
    }
    else if(!(luhn(Cadena(numero.c_str())))){
        throw Incorrecto(Razon::NO_VALIDO);
    }
    
}
Numero::operator const char *()const{
    return numero.c_str();
}
bool operator <(const Numero& n1, const Numero& n2){
    return (n1.numero < n2.numero);
}

std::unordered_set<Numero> Tarjeta::con_nu;

Tarjeta::Tarjeta(Numero numero, Usuario& titular,Fecha caducidad): numero_(numero), titular_(&titular), caducidad_(caducidad), activa_(true) {
    bool var = con_nu.insert(numero).second;
    if (var != false){
        Fecha a;
        if (caducidad_ <= a){
            con_nu.erase(numero);
            throw Tarjeta::Caducada(caducidad);
        }
        if (caducidad_ >= a) {
            titular.es_titular_de(*this);
        }
    }
    else{
        throw Tarjeta::Num_duplicado(numero);
    }
}

Tarjeta::Tipo Tarjeta::tipo()const{
    if((numero_[0] == '3' && numero_[1] == '4') || (numero_[3] == '3' && numero_[1] == '7')){
        return Tipo(AmericanExpress);
    }
    else if (numero_[0] == '3' && !((numero_[0] == '3' && numero_[1] == '4') || (numero_[3] == '3' && numero_[1] == '7'))){
        return Tipo(JCB);
    }
    else if (numero_[0] == '4'){
        return Tipo(VISA);
    }
    else if (numero_[0] == '5'){
        return Tipo(Mastercard);
    }
    else if (numero_[0] == '6'){
        return Tipo(Maestro);
    }
    else{
        return Tipo(Otro);
    }
}

bool Tarjeta::activa(bool nuevo){
    if (nuevo == false){
        activa_ = false;
    }
    else{
        activa_ = true;
    }
    return activa_;
}

void Tarjeta::anular_titular(){
    titular_ = nullptr;
    activa_ = false;
}

Tarjeta::~Tarjeta(){
    if(Usuario* usu = const_cast<Usuario*>(titular_)){
        usu->no_es_titular_de(*this);
    }
    Numero a = numero_;
    con_nu.erase(a);
    
}

std::ostream& operator <<(std::ostream& os, const Tarjeta::Tipo& tip){
    switch(tip)
    {
        case 0: os << "Tipo indeterminado" ; break;
        case 1: os << "VISA" ; break ;
        case 2: os << "Mastercard"; break ;
        case 3: os << "Maestro"; break ;
        case 4: os << "JCB" ; break ;
        case 5: os << "AmericanExpress" ; break ;
        default: os << "Tipo indeterminado"; break ;
    }

    return os ;
}

std::ostream& operator <<(std::ostream& os, const Tarjeta& tar){
    Cadena aux1 = tar.titular()->nombre() + " " + tar.titular()->apellidos();


	for(size_t i=0; i< aux1.length(); i++)
	{
		aux1[i] = toupper(aux1[i]);
	}

    os << tar.tipo() << "\n" << Cadena(tar.numero()) << "\n" << aux1 << "\nCaduca: ";

    Cadena mes;
    if (tar.caducidad().mes() < 10){
        os << 0 << tar.caducidad().mes();
    }
    else{
        os << tar.caducidad().mes();
    }

    os << "/" << (tar.caducidad().anno() % 100) << std::endl;
    return os;
}
bool operator <(const Tarjeta& tar1, const Tarjeta& tar2){
    return (tar1.numero() < tar2.numero());
}