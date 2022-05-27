#ifndef _ARTICULO_HPP_
#define _ARTICULO_HPP_

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"


class Articulo
{
public:
    Articulo(const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio, size_t existencias);
    const Cadena& referencia()const;
    const Cadena& titulo()const;
    const Fecha& f_publi() const;
    const double& precio() const;
    double& precio();
    const size_t& stock()const;
    size_t& stock();
    ~Articulo();
private:
    const Cadena referencia_;
    const Cadena titulo_;
    const Fecha fechaDePublicacion_;
    double precio_;
    size_t existencias_;

};

inline const Cadena& Articulo::referencia() const{return referencia_;}
inline const Cadena& Articulo::titulo() const{return titulo_;}
inline const Fecha& Articulo::f_publi() const{return fechaDePublicacion_;}
inline const double& Articulo::precio() const{return precio_;}
inline double& Articulo::precio(){return precio_;}
inline const size_t& Articulo::stock() const{return existencias_;}
inline size_t& Articulo::stock(){return existencias_;}

std::ostream& operator << (std::ostream& os,const Articulo pro);

#endif