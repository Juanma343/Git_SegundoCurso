#include <iostream>
class hola{
    size_t n_;
    size_t m_;
    double d_;
    public:
        hola(size_t n = 0, size_t m = 0, double d = 0 ): n_(n), m_(m), d_(d){}
        void imprimir(){
            std::cout << n_ <<" "<< m_ <<" "<<  d_ << std::endl;
        }
    
};

int main(){

    hola b(1);
    hola a();
    hola c(1,2);
    hola d(1, 2 ,3.);


    a.imprimir();
    b.imprimir();
    c.imprimir();
    d.imprimir();
    
}