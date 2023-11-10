#ifndef OOP_LAB1_T_COMPLEX_H
#define OOP_LAB1_T_COMPLEX_H

#include <iostream>

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
    friend std::ostream& operator<<(std::ostream& stream, const TComplex& complex);
    friend std::istream& operator>>(std::istream& stream, TComplex& complex);
    TComplex operator+(const TComplex& complex);
    TComplex operator-(const TComplex& complex);
    TComplex operator*(const TComplex& complex);
    TComplex operator=(const TComplex& complex);

};


#endif