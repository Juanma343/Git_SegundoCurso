
#ifndef _CADENA_HPP_
#define _CADENA_HPP_

#include <iostream>
#include <cstdlib>
#include <string.h>

class Cadena{
    public:
        explicit Cadena(const int tam = 0, const char s = ' ');
        Cadena(const Cadena& cad);
        Cadena(const char* s);  //preguntar si esto combierte variable implicita si es una variable-l
        operator const char*() const;
        
        Cadena& operator = (const char* s);
        Cadena& operator =(const Cadena& cad);
        
        size_t length()const;
        Cadena& operator +=(const Cadena& cad);
        Cadena operator +(const Cadena& cad)const;
        Cadena& operator +=(const char*cad);
        Cadena operator +(const char* cad)const;    //preguntar, si funciona con con el const del parametro// hay que ponerlo
        bool operator <(const Cadena& cad)const;
        bool operator >(const Cadena& cad)const;
        bool operator <=(const Cadena& cad)const;
        bool operator >=(const Cadena& cad)const;
        bool operator ==(const Cadena& cad)const;
        bool operator !=(const Cadena& cad)const;
        inline char& operator[](int a){
            return  s_[a];
        }
        inline char& at(int a){
            return  (a < tam_) ?  s_[a] : throw std::out_of_range ("Supera el tamaño del vector");
        }
        inline const char operator[](int a) const{
            return  s_[a];
        }
        inline const char at(int a) const{
            return  (a < tam_) ?  s_[a] : throw std::out_of_range ("Supera el tamaño del vector");
        }
        Cadena substr(const int ind, const int i)const;
        ~Cadena();
    private:
        char* s_;
        int tam_;
};



inline bool operator <(char* a_, Cadena& cad){
    Cadena a (a_);
    return a < cad;
}
inline bool operator >(char* a_, Cadena& cad){
    Cadena a (a_);
    return a > cad;
}
inline bool operator <=(char* a_, Cadena& cad){
    Cadena a (a_);
    return a <= cad;
}
inline bool operator >=(char* a_, Cadena& cad){
    Cadena a (a_);
    return a >= cad;
}
inline bool operator ==(char* a_, Cadena& cad){
    Cadena a (a_);
    return a == cad;
}
inline bool operator !=(char* a_, Cadena& cad){
    Cadena a (a_);
    return a != cad;
}


#endif