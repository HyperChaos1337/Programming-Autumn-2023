#include "t_complex.h"

TComplex::TComplex():real(0), imaginary(0){}
TComplex::TComplex(double real, double imaginary):real(real), imaginary(imaginary){}

std::ostream& operator<<(std::ostream& stream, const TComplex& complex){
    return stream << complex.real << "+" << complex.imaginary << "i ";
}

std::istream& operator>>(std::istream& stream, TComplex& complex){
    return stream >> complex.real >> complex.imaginary;
}

void TComplex::set_real(double Re){
    this->real = Re;
}
void TComplex::set_imaginary(double Im){
    this->imaginary = Im;
}

int TComplex::get_real(){
    return real;
}
int TComplex::get_imaginary(){
    return imaginary;
}

TComplex TComplex::operator+(const TComplex &complex){
    return TComplex(real + complex.real, imaginary + complex.imaginary);
}
TComplex TComplex::operator-(const TComplex &complex){
    return TComplex(real - complex.real, imaginary - complex.imaginary);
}
TComplex TComplex::operator*(const TComplex &complex){
    return TComplex(real*complex.real-imaginary*complex.imaginary,
                    imaginary*complex.real + real*complex.imaginary);
}
TComplex TComplex::operator=(const TComplex &complex){
    return TComplex(real = complex.real,
                    imaginary = complex.imaginary);
}