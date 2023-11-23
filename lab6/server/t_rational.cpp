#include "t_rational.h"

TRational::TRational(){}
TRational::TRational(long long num, long long den):num(num),den(den){}

long long TRational::gcd(long long a, long long b){
    return b ? gcd(b, a%b) : a;
}

void TRational::set_num(long long num){
    this->num = num;
}
void TRational::set_den(long long den){
    this->den = den;
}

long long TRational::get_num(){
    return num;
}
long long TRational::get_den(){
    return den;
}

TRational TRational::simplify(){

    if (den < 0){
        den = -den;
        num = -num;
    }
    auto del = gcd(num, den);
    num /= del;
    den /= del;
    return *this;

}

TRational TRational::change_sign(){
    if (den < 0){
        den = -den;
        num = -num;
    }
    return *this;
}

TRational TRational::operator+(const TRational &rational){
    return TRational(num*rational.den + den*rational.num, den * rational.den).simplify();
}

TRational TRational::operator-(const TRational &rational){
    return TRational(num*rational.den - den*rational.num, den * rational.den).simplify();
}

TRational TRational::operator*(const TRational &rational){
    return TRational(num * rational.num, den * rational.den).simplify();
}

TRational TRational::operator=(const TRational &rational) {
    return TRational(num = rational.num, den = rational.den).simplify();
}
TRational TRational::operator /(const TRational &rational){
    return TRational(num * rational.den, den * rational.num).simplify();
}

bool TRational::operator ==(const TRational &rational){
    return num == rational.num && den == rational.den;
}
bool TRational::operator !=(const TRational &rational){
    return num != rational.num || den != rational.den;
}

std::string TRational::to_str(){
    if(num == 0) return "0";
    return std::to_string(num) + "/" + std::to_string(den);
}
