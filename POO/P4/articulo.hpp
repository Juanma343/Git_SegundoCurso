#ifndef _ARTICULO_HPP_
#define _ARTICULO_HPP_

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include <set>

class Autor{
    public:
        Autor(const Cadena nombre, const Cadena apallidos, const Cadena direccion)noexcept:nombre_(nombre), apellidos_(apallidos), direccion_(direccion){}
        const Cadena& nombre()const noexcept{return nombre_;}
        const Cadena& apellidos() const noexcept{return apellidos_;}
        const Cadena& direccion()const noexcept{return direccion_;}
    private:
        const Cadena nombre_;
        const Cadena apellidos_;
        const Cadena direccion_;
};

class Articulo
{
public:
    typedef std::set<Autor*> Autores;
    Articulo(const Autores autores, const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio);
    class Autores_vacios{};
    const Cadena& referencia()const;
    const Cadena& titulo()const;
    const Fecha& f_publi() const;
    const double& precio() const;
    const Autores& autores() const{return autores_;}
    double& precio();
    virtual void impresion_especifica(std::ostream& os)const = 0;
    virtual ~Articulo(){}
private:
    const Autores autores_;
    const Cadena referencia_;
    const Cadena titulo_;
    const Fecha fechaDePublicacion_;
    double precio_;

};

inline const Cadena& Articulo::referencia() const{return referencia_;}
inline const Cadena& Articulo::titulo() const{return titulo_;}
inline const Fecha& Articulo::f_publi() const{return fechaDePublicacion_;}
inline const double& Articulo::precio() const{return precio_;}
inline double& Articulo::precio(){return precio_;}
std::ostream& operator << (std::ostream& os,const Articulo& pro);

class ArticuloAlmacenable: public Articulo{
    public:
        ArticuloAlmacenable(const Autores autores, const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio, unsigned int stock): Articulo(autores, referencia, titulo, fechaDePublicacion, precio), stock_(stock){}
        virtual unsigned int& stock(){return stock_;}
        virtual const unsigned int& stock()const{return stock_;}
    private:
        unsigned int stock_;
};

class Libro: public ArticuloAlmacenable{
    public:
        Libro(const Autores autores, const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio, unsigned int n_pag, unsigned int stock = 0): ArticuloAlmacenable(autores, referencia, titulo, fechaDePublicacion, precio, stock), n_pag_(n_pag){}
        unsigned int n_pag()const{return n_pag_;}
        void impresion_especifica(std::ostream& os)const;

    private:
        const unsigned int n_pag_;
};

class Cederron: public ArticuloAlmacenable{
    public:
        Cederron(const Autores autores, const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio, unsigned int MB, unsigned int stock = 0): ArticuloAlmacenable(autores, referencia, titulo, fechaDePublicacion, precio, stock), MB_(MB){}
        unsigned int& tam(){return MB_;}
        const unsigned int& tam()const{return MB_;}
        void impresion_especifica(std::ostream& os)const;
    private:
        unsigned int MB_;
};

class LibroDigital: public Articulo{
    public:
        LibroDigital(const Autores autores, const Cadena referencia, const Cadena titulo, const Fecha fechaDePublicacion, double precio, const Fecha& fechaExp): Articulo(autores, referencia, titulo, fechaDePublicacion, precio), fechaExp_(fechaExp){}
        const Fecha& f_expir()const{return fechaExp_;}
        void impresion_especifica(std::ostream& os)const;
    private:
        Fecha fechaExp_;
};

#endif