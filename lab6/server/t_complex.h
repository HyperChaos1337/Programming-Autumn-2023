#ifndef OOP_LAB1_T_COMPLEX_H
#define OOP_LAB1_T_COMPLEX_H

#include <cmath>
#include <string>

class TComplex{
private:
    int real;
    int imaginary;
public:
    TComplex();
    TComplex(int real, int imaginary);
    void set_real(int Re);
    void set_imaginary(int Im);
    int get_real();
    int get_imaginary();
    std::string to_str();
    TComplex operator+(const TComplex& complex);
    TComplex operator-(const TComplex& complex);
    TComplex operator*(const TComplex& complex);
    TComplex operator/(const TComplex& complex);
    TComplex operator=(const TComplex& complex);
    bool operator==(const TComplex& complex);
    bool operator!=(const TComplex& complex);
};


#endif
