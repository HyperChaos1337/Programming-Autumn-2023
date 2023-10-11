#include "t_rational.h"

TRational::TRational(){}
TRational::TRational(long long num, long long den):num(num),den(den){}

long long TRational::gcd(long long a, long long b){
    return b ? gcd(b, a%b) : a;
}

long long TRational::lcm(long long a, long long b){
    return (a*b)/gcd(a,b);
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

    if(den < 0){
        num = -num;
        den = -den;
    }

    auto del = gcd(num, den);

    num /= del;
    den /= del;
    return *this;

}

TRational TRational::change_sign(TRational &rational){
    if (rational.den < 0){
        rational.den = -rational.den;
        rational.num = -rational.num;
    }
    return TRational(rational.num, rational.den);
}

TRational TRational::operator+(const TRational &rational1){
    return TRational(num*rational1.den + den*rational1.num, den * rational1.den);
}

TRational TRational::operator-(const TRational &rational1){
    return TRational(num*rational1.den - den*rational1.num, den * rational1.den);
}

TRational TRational::operator*(const TRational &rational1){
    return TRational(num * rational1.num, den * rational1.den);
}

TRational TRational::operator=(const TRational &rational) {
    return TRational(num = rational.num, den = rational.den);
}

std::istream& operator>>(std::istream& in, TRational& rational){
    return in >> rational.num >> rational.den;
}

std::ostream& operator<<(std::ostream& out, const TRational& rational){
    if(rational.num == rational.den) out << rational.den;
    else if(rational.den == 1) out << rational.num;
    else out << rational.num << " / " << rational.den;
    return out;
}

QString& operator <<(QString& s, TRational& rational){
    if(rational.num == rational.den){
        s += QString().setNum(rational.den);
        return s;
    }
    else if(rational.den == 1){
        s += QString().setNum(rational.num);
        return s;
    }
    else {
        s += QString().setNum(rational.num);
        s += "/";
        s += QString().setNum(rational.den);
        return s;
    }
}
