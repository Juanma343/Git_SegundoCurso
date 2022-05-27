
#ifndef _CADENA_HPP_
#define _CADENA_HPP_

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <string>
#include <iterator>

class Cadena{
    public:
        explicit Cadena(const int tam = 0, const char s = ' ');
        Cadena(const Cadena& cad);
        Cadena(const char* s);  //preguntar si esto combierte variable implicita si es una variable-l
        Cadena(Cadena&& cad);

        typedef char* iterator; 
        typedef const char* const_iterator; 
        typedef std::reverse_iterator<iterator> reverse_iterator; 
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator; 

        iterator begin(){return s_;}
        const_iterator begin() const{return s_;}
        const_iterator cbegin() const{return s_;}
        reverse_iterator rbegin(){return reverse_iterator(end());}
        const_reverse_iterator rbegin()const{return const_reverse_iterator(end());}
        const_reverse_iterator crbegin()const{return const_reverse_iterator(end());}


        iterator end(){return s_ + tam_;}
        const_iterator end() const{return s_ + tam_;}
        const_iterator cend() const{return s_ + tam_;}
        reverse_iterator rend(){return reverse_iterator(begin());}
        const_reverse_iterator rend()const{return const_reverse_iterator(begin());}
        const_reverse_iterator crend()const{return const_reverse_iterator(begin());}



        const char* c_str() const;
        
        Cadena& operator = (const char* s);
        Cadena& operator = (const Cadena& cad);
        Cadena& operator = (Cadena&& cad);
        
        size_t length()const;
        Cadena& operator +=(const Cadena& cad);
        Cadena operator +(const Cadena& cad)const;
        Cadena& operator +=(const char*cad);
        Cadena operator +(const char* cad)const;    //preguntar, si funciona con con el const del parametro// hay que ponerlo
        friend std::ostream& operator << (std::ostream& os, const Cadena& cad);
        friend std::istream& operator >> (std::istream& is, Cadena& cad);
        char& operator[](int a){
            return  s_[a];
        }
        char& at(int a){
            return  (a < tam_) ?  s_[a] : throw std::out_of_range ("Supera el tamaño del vector");
        }
        const char operator[](int a) const{
            return  s_[a];
        }
        const char at(int a) const{
            return  (a < tam_) ?  s_[a] : throw std::out_of_range ("Supera el tamaño del vector");
        }
        Cadena substr(const int ind, const int i)const;
        ~Cadena();
    private:
        char* s_;
        int tam_;
};

bool operator <(const Cadena& cad1, const Cadena& cad);
bool operator >(const Cadena& cad1, const Cadena& cad);
bool operator <=(const Cadena& cad1, const Cadena& cad);
bool operator >=(const Cadena& cad1, const Cadena& cad);
bool operator ==(const Cadena& cad1, const Cadena& cad);
bool operator !=(const Cadena& cad1, const Cadena& cad);

// Para P2 y ss.
// Especialización de la plantilla hash<T>para definir la
// función hash a utilizar con contenedores desordenados de
// Cadena, unordered_[set|map|multiset|multimap].
namespace std{// Estaremos dentro del espacio de nombres std
template<>// Es una especialización de una plantilla para Cadena
struct hash<Cadena> {// Es una clase con solo un operador publico
    size_t operator() (const Cadena& cad)const// El operador función
    {
        hash<string>hs;// Creamos un objeto hash de string
        const char*p=cad.c_str();// Obtenemos la cadena de la Cadena
        string  s(p);// Creamos un string desde una cadena
        size_t  res=hs(s);// El hash del string. Como hs.operator()(s);
        return res;// Devolvemos el hash del string
    }
};
}


#endif