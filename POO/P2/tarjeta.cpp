#include "tarjeta.hpp"
#include "usuario.hpp"
#include "cadena.hpp"
#include <cstddef>
#include <ctype.h>

void quitaespacios(const char* cadena, char* cadenasin)
{
    int i,j;
    i=0;
    j=0;
    while (cadena[i]!='\0') {
        if(cadena[i]!=' ' && cadena[i]!='\v' && cadena[i]!='\r' && cadena[i]!='\t' && cadena[i]!='\f'){
            cadenasin[j]=cadena[i];
            j++;
        }
        i++;
    }
    cadenasin[j]='\0';
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

Numero::Numero( Cadena cad){
    //quitar los espacios de la cadena
    char *cones = new  char[cad.length()];
    char *sines = new  char[cad.length()];
    strcpy(cones, cad.c_str());
    quitaespacios(cones, sines);

    //comprobar
    if (strlen(sines) < 13 || strlen(sines) > 19){
        throw Incorrecto(Razon::LONGITUD);
    }
    else if(!(esNumero(sines))){
        throw Incorrecto(Razon::DIGITOS);
    }
    else if(!(luhn(Cadena(sines)))){
        throw Incorrecto(Razon::NO_VALIDO);
    }
    numero = sines;

    
}
Numero::operator const char *()const{
    return numero.c_str();
}
bool operator <(const Numero& n1, const Numero& n2){
    return (n1.numero < n2.numero);
}

std::unordered_set<Numero> Tarjeta::con_nu;

Tarjeta::Tarjeta(Numero numero, Usuario& titular,Fecha caducidad): numero_(numero), titular_(&titular), caducidad_(caducidad), activa_(true) {
    if (con_nu.insert(numero).second != false){
        Fecha a;
        if (caducidad_ < a){
            throw Tarjeta::Caducada(caducidad);
        }
        if (con_nu.insert(numero).second == false){
            throw Tarjeta::Num_duplicado(numero);
        }
        if (caducidad_ >= a || con_nu.insert(numero).second == true) {
            titular.es_titular_de(*this);
        }
    }
    
}

Tarjeta::Tipo Tarjeta::tipo()const{
    char* aux = new char[30];
    quitaespacios(numero_, aux);
    if((aux[0] == '3' && aux[1] == '4') || (aux[3] == '3' && aux[1] == '7')){
        return Tipo(AmericanExpress);
    }
    else if (aux[0] == '3' && !((aux[0] == '3' && aux[1] == '4') || (aux[3] == '3' && aux[1] == '7'))){
        return Tipo(JCB);
    }
    else if (aux[0] == '4'){
        return Tipo(VISA);
    }
    else if (aux[0] == '5'){
        return Tipo(Mastercard);
    }
    else if (aux[0] == '6'){
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
        case 0: os << "Otro" ; break;
        case 1: os << "VISA" ; break ;
        case 2: os << "Mastercard"; break ;
        case 3: os << "Maestro"; break ;
        case 4: os << "JCB" ; break ;
        case 5: os << "AmericanExpress" ; break ;
        default: os << "Otra"; break ;
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