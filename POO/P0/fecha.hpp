#ifndef _FECHA_HPP_
#define _FECHA_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

class Fecha
{
public:
    static const int AnnoMaximo = 2037;
    static const int AnnoMinimo = 1902;
    explicit Fecha(int d = 0, int m = 0, int a = 0);
    Fecha (const char* a);
    int dia() const;
    int mes() const;
    int anno() const;
    //Fecha& operator = (const Fecha A);
    Fecha& operator ++();
    Fecha operator ++(int);
    Fecha& operator --();
    Fecha operator --(int);
    friend Fecha operator + (const Fecha a, int n);
    friend Fecha operator - (const Fecha a, int n);
    friend Fecha operator + (int n, const Fecha a);
    friend Fecha operator - (int n, const Fecha a);
    Fecha& operator += (int n);
    Fecha& operator -= (int n);

    bool operator == (const Fecha a) const;
    bool operator != (const Fecha a) const;
    bool operator <= (const Fecha a) const;
    bool operator >= (const Fecha a) const;
    bool operator < (const Fecha a) const;
    bool operator > (const Fecha a) const;
    
    operator const char * ()const;

    class Invalida{
    public:
        Invalida(char* a) : codigo(a){}
        inline const char* por_que()const {
            return codigo;
        }
    private:
        char* codigo;
    };

private:
    
    int dia_;
    int mes_;
    int anno_;
    void verificarFecha();
    void validar();
    
    
};

inline int Fecha::dia() const{
    return dia_;
}

inline int Fecha::mes() const{
    return mes_;
}

inline int Fecha::anno() const{
    return anno_;
}

//cpp

//dia de la semana
inline void Fecha::verificarFecha(){                                       //se encarga de asignar a los argumentos vacios la Fecha actual
     
    std::time_t t = std::time(0);
    std::tm* nuevo = std::localtime(&t);


    if (dia_ == 0){
        
        dia_ = nuevo->tm_mday;

    }

    if (mes_ == 0){

        mes_ = nuevo->tm_mon + 1;

    }

    if (anno_ == 0){

        anno_ = nuevo->tm_year + 1900;

    }

}

inline void Fecha::validar (){

    int diasMes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


    if (mes_ > 12 || mes_ <= 0){
        throw Fecha::Invalida ("Fecha invalida");
    }
    if (mes_ == 2 && (anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0))){
        if(dia_ > diasMes[mes_] + 1 || dia_ <= 0){
            throw Fecha::Invalida ("Fecha invalida");
        }
    }
    else if(dia_ > diasMes[mes_] || dia_ <= 0){
        throw Fecha::Invalida ("Fecha invalida");
    }
    if (anno_ < AnnoMinimo || anno_ > AnnoMaximo){
        throw Fecha::Invalida ("Fecha invalida");
    }
    

}




#endif