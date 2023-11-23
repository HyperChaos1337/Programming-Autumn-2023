#include "t_complex.h"

TComplex::TComplex():real(0), imaginary(0){}
TComplex::TComplex(int real, int imaginary):real(real), imaginary(imaginary){}

void TComplex::set_real(int Re){
    this->real = Re;
}
void TComplex::set_imaginary(int Im){
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
TComplex TComplex::operator/(const TComplex &complex){
    int den = pow(complex.real, 2) + pow(complex.imaginary, 2);
    return TComplex((real * complex.real + imaginary * complex.imaginary) / den,
                    (imaginary * complex.real - real * complex.imaginary) / den);
}
TComplex TComplex::operator=(const TComplex &complex){
    return TComplex(real = complex.real,
                    imaginary = complex.imaginary);
}

bool TComplex::operator ==(const TComplex &complex){
    return real == complex.real && imaginary == complex.imaginary;
}
bool TComplex::operator !=(const TComplex &complex){
    return real != complex.real || imaginary != complex.imaginary;
}

std::string TComplex::to_str(){
    int ai = real, bi = imaginary;
    return (bi > 0) ? (bi == 1) ? std::to_string(ai) + " + " + "i  " : std::to_string(ai) + " + " + std::to_string(bi) + "i " : (bi == 0) ?
                                                                                                                                std::to_string(ai)
                                                                                                                                          : (bi ==
                                                                                                                                             -1)
                                                                                                                                                ?
                                                                                                                                                std::to_string(ai)
                                                                                                                                                    + " - "
                                                                                                                                                    + "i  "
                                                                                                                                                :
                                                                                                                                                std::to_string(ai)
                                                                                                                                                    + " - "
                                                                                                                                                    + std::to_string((int)fabs(imaginary))
                                                                                                                                                    + "i ";
}
