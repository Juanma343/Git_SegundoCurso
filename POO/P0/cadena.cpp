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

Cadena::operator const char *() const{

    return s_;

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

bool Cadena::operator <(const Cadena& cad)const{

    bool salida;
    
    if (strcmp(s_, cad.s_) < 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;

}
bool Cadena::operator >(const Cadena& cad)const{

    bool salida;
    
    if (strcmp(s_, cad.s_) > 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;

}
bool Cadena::operator <=(const Cadena& cad)const{

    bool salida;
    
    if (strcmp(s_, cad.s_) <= 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;

}
bool Cadena::operator >=(const Cadena& cad)const{

    bool salida;
    
    if (strcmp(s_, cad.s_) >= 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;

}
bool Cadena::operator ==(const Cadena& cad)const{

    bool salida;
    
    if (strcmp(s_, cad.s_) == 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;

}
bool Cadena::operator !=(const Cadena& cad)const{

    bool salida;
    
    if (strcmp(s_, cad.s_) != 0){
        salida = true;
    }
    else{
        salida = false;
    }

    return salida;

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
    delete []s_;
}