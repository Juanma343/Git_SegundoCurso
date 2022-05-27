#include "cadena.hpp"

Cadena::Cadena(const int tam, const char s): s_(new char[tam + 1]), tam_(tam) {
    
    for(int i = 0; i < tam; i++){
        s_[i] = s;
    }
    s_[tam] = '\0';

}

Cadena::Cadena(const Cadena& cad): s_(new char[cad.tam_ + 1]), tam_(cad.tam_)  {

    strcpy(s_, cad.s_);

}

Cadena::Cadena(const char* s): s_(new char[strlen(s) + 1]), tam_(strlen(s)) {

    strcpy(s_, s);

}

Cadena::Cadena(Cadena&& cad): s_(cad.s_), tam_(cad.tam_){

    cad.tam_ = 0;
    cad.s_ = nullptr;

}

const char *Cadena::c_str() const{

    return s_;

}

std::ostream& operator << (std::ostream& os, const Cadena& cad){
    os << cad.s_;
    return os;
}

std::istream& operator >> (std::istream& is, Cadena& cad){
    char a[33] = {'\0'};
    
    is.width(33);
    is >> a;

    cad = Cadena(a);

    return is;
}

Cadena& Cadena::operator = (const char* s) {

    if(strcmp(s_, s) != 0){
        delete []s_;
        s_ = new char[strlen(s) + 1];
        tam_ = strlen(s);
        strcpy(s_, s);
    }
    
    return *this;

}

Cadena& Cadena::operator =(const Cadena& cad){

    tam_ = cad.tam_;
    s_ = new char[tam_ + 1];
    strcpy(s_, cad.s_);
    
    
    return *this;

}

Cadena& Cadena::operator = (Cadena&& cad){

    tam_ = cad.tam_;
    strcpy(s_, cad.s_);

    cad.tam_ = 0;
    cad.s_ = nullptr;

    return *this;
}

size_t Cadena::length()const{
    return tam_;
}

Cadena& Cadena::operator +=(const Cadena& cad){

    tam_ += cad.tam_;
    strcat(s_, cad.s_);

    return *this;

}

Cadena Cadena::operator +(const Cadena& cad)const{

    Cadena a(*this);

    a += cad;

    return a;

}

Cadena& Cadena::operator +=(const char* cad){

    tam_ += strlen(cad);
    strcat(s_, cad);

    return *this;

}

Cadena Cadena::operator +(const char* cad)const{

    Cadena a(*this);

    a += cad;

    return a;

}

bool operator <(const Cadena& cad1, const Cadena& cad){
    bool salida;
    
    if (strcmp(cad1.c_str(), cad.c_str()) < 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;
}
bool operator >(const Cadena& cad1, const Cadena& cad){
    return cad < cad1;
}
bool operator <=(const Cadena& cad1, const Cadena& cad){
    return cad1 < cad || cad1 == cad;
}
bool operator >=(const Cadena& cad1, const Cadena& cad){
    return cad1 > cad || cad == cad1;
}
bool operator ==(const Cadena& cad1, const Cadena& cad){
    bool salida;
    
    if (strcmp(cad1.c_str(), cad.c_str()) == 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;
}
bool operator !=(const Cadena& cad1, const Cadena& cad){
    return !(cad1 == cad);
}


Cadena Cadena::substr(const int ind, const int n)const{

    

    if(n + ind <= tam_ && n > 0 && ind >= 0 && ind <= tam_){
        Cadena a(n);
        for (int i = 0; i <= n && i <= tam_; i++){
            a.s_[i] = s_[ind + i];
        }
        a.s_[a.tam_] = '\0';
        return a;
    }
    else{
        throw std::out_of_range("Fuera de rango");
    }
    

}

Cadena::~Cadena(){
    //s_ = nullptr;
    delete [] s_;
}