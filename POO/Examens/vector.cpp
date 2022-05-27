#include <initializer_list>
#include <algorithm>
#include <stdexcept>
class Vector{
    public:
        explicit Vector(size_t tam, double num);
        Vector(std::initializer_list<double> lit);
        double& at(size_t i);
        ~Vector();
    private:
        size_t tam_;
        double* vec_;
};

Vector::Vector(size_t tam, double num):tam_(tam), vec_(new double[tam]){
    for (int i = 0; i < tam; i++){
        vec_[i] = num;
    }
}

Vector::Vector(std::initializer_list<double> lit):vec_(new double[lit.size()]), tam_(lit.size()){
    std::copy(lit.begin(), lit.end(), vec_);
}

Vector::~Vector(){
    delete []vec_;
}

double& Vector::at(size_t i){
    if (i >= tam_){
        throw std::out_of_range ("Error");
    }
    return vec_[i];
}