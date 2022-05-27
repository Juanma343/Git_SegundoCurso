#include <iostream>
#include "fecha.hpp"

Fecha& Fecha::operator ++(){
    
    int diasMes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    dia_++;
    if (mes_ == 2 && (anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0))){
        if(dia_ > diasMes[mes_] + 1){
            dia_ = 1;
            mes_++;
        }
    }
    else if(dia_ > diasMes[mes_] || dia_ <= 0){
        dia_ = 1;
        mes_++;
        if (mes_ > 12){
            mes_ = 1;
            anno_++;
        }
    }

    validar();

    return *this;
}
Fecha Fecha::operator ++(int){

    Fecha temp(*this);
    ++*this;
    return temp;

}
Fecha& Fecha::operator --(){

    int diasMes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    dia_--;
    if (mes_ == 3 && (anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0))){
        if(dia_ == 0){
            mes_--;
            dia_ = diasMes[mes_] + 1;
            
        }
    }
    else if(dia_ == 0){
        mes_--;
        if (mes_ == 0){             //fallo del core, la comprobacion de que mes es == 0 es antes de meterlo como parametro de diasMes[]
            anno_--;
            mes_ = 12;
        }
        dia_ = diasMes[mes_];
        
    }

    validar();

    return *this;
}
Fecha Fecha::operator --(int){

    Fecha temp(*this);
    --*this;
    return temp;
}

Fecha operator + (const Fecha a, int n){

    Fecha temp(a);
    while(n > 0){
        (temp)++;
        n--;
    }

    temp.validar();

    return temp;
}
Fecha operator + (int n, const Fecha a){

    Fecha temp(a);
    while(n > 0){
        (temp)++;
        n--;
    }

    temp.validar();

    return temp;
}
Fecha operator - (const Fecha a, int n){

    Fecha temp(a);
    while(n > 0){
        (temp)--;
        n--;
    }

    temp.validar();

    return temp;
}
Fecha operator - (int n, const Fecha a){

    Fecha temp(a);
    while(n > 0){
        (temp)--;
    }

    temp.validar();

    return temp;
}
Fecha& Fecha::operator += (int n){
    
    while(n > 0){
        (*this)++;
        n--;
    }

    validar();

    return *this;
}
Fecha& Fecha::operator -= (int n){

    while(n > 0){
        (*this)--;
        n--;
    }

    validar();

    return *this;
}

bool operator == (const Fecha a, const Fecha b){
    bool salida = true;

    if (a.dia_ != b.dia_){
        salida = false;
    }
    else if (a.mes_ != b.mes_){
        salida = false;
    }
    else if (a.anno_ != b.anno_){
        salida = false;
    }

    return salida;
}
bool operator != (const Fecha a, const Fecha b){return !(a == b);}
bool operator < (const Fecha a, const Fecha b){

    bool salida;

    if (a.anno_ < b.anno_){
        salida = true;
    }
    else if (a.anno_ == b.anno_){
        if (a.mes_ < b.mes_){
            salida = true;
        }
        else if (a.mes_ == b.mes_) {
            if (a.dia_ < b.dia_){
                salida = true;
            }
            else if (a.dia_ < b.dia_){
                salida = false;
            }
            else {
                salida = false;
            }
        }
        else{
            salida = false;
        }
    }
    else {
        salida = false;
    }
    
    return salida;
}
bool operator > (const Fecha a, const Fecha b){
    return b < a;
}
bool operator <= (const Fecha a, const Fecha b){
    return (a < b || a == b);
}
bool operator >= (const Fecha a, const Fecha b){
    return (a > b || a == b);
}

const char * Fecha::cadena ()const{

    
    char dia_s[7][15] = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado" };
    char mes_a[12][15] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };


    tm dia = {}; 
    dia.tm_mday = dia_;
    dia.tm_mon = mes_-1;
    dia.tm_year = anno_-1900;

    mktime(&dia);

    char *cadena = new char[60]; 

    
    sprintf(cadena,"%s %d de %s de %d", dia_s[dia.tm_wday], dia.tm_mday, mes_a[dia.tm_mon], dia.tm_year + 1900);
    return cadena;
}
std::ostream& operator << (std::ostream& os, const Fecha& a){
    char dia_s[7][15] = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado" };
    char mes_a[12][15] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };


    tm dia = {}; 
    dia.tm_mday = a.dia_;
    dia.tm_mon = a.mes_-1;
    dia.tm_year = a.anno_-1900;

    mktime(&dia);

    char *cadena = new char[60]; 

    sprintf(cadena,"%s %d de %s de %d", dia_s[dia.tm_wday], dia.tm_mday, mes_a[dia.tm_mon], dia.tm_year + 1900);
    os << cadena;
    return os;
}
std::istream& operator >> (std::istream& i, Fecha& a){

    char* ca = new char[11];

    i.width(11);
    i >> ca;
    try{
        a = Fecha(ca);
    }
    catch(Fecha::Invalida a){
        i.setstate(std::ios_base::failbit);
        throw a;
    }
    
    
    return i;

}


/*
Fecha& Fecha::operator = (const Fecha A){

    dia_ = A.dia_;
    mes_ = A.mes_;
    anno_ = A.anno_;

    return *this;

}
*/
Fecha::Fecha(int d, int m, int a): dia_(d), mes_(m), anno_(a) {


    verificarFecha();
    validar();
}

Fecha::Fecha (const char* a){

    if(3 != sscanf(a, "%d/%d/%d", &dia_ , &mes_, &anno_)){
        throw Fecha::Invalida ("Fecha invalida");
    }

    verificarFecha();
    validar();

}


