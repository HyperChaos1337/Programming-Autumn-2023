#ifndef OOP_LAB1_T_RATIONAL_H
#define OOP_LAB1_T_RATIONAL_H

#include <iostream>
#include <QString>

class TRational{
private:
    long  num, den;
public:
    TRational();
    TRational(long long num, long long den);

    TRational simplify();
    TRational change_sign();

    long long gcd(long long a, long long b);
    long long lcm(long long a, long long b);

    void set_num(long long num);
    void set_den(long long den);

    long long get_num();
    long long get_den();

    TRational operator+(const TRational& rational1);
    TRational operator-(const TRational& rational1);
    TRational operator*(const TRational& rational1);
    TRational operator=(const TRational& rational);

    friend std::istream& operator>>(std::istream& in, TRational& rational);
    friend std::ostream& operator<<(std::ostream& out, const TRational& rational);
    friend QString& operator<<(QString& s, TRational& rational);

};

#endif
