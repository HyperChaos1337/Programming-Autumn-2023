#ifndef OOP_LAB1_T_RATIONAL_H
#define OOP_LAB1_T_RATIONAL_H

#include <iostream>
#include <QString>

class TRational{
private:
    long long num, den;
public:
    TRational();
    TRational(long long num, long long den);

    TRational simplify();
    TRational change_sign();

    long long gcd(long long a, long long b);

    void set_num(long long num);
    void set_den(long long den);

    long long get_num();
    long long get_den();

    std::string to_str();

    TRational operator+(const TRational& rational);
    TRational operator-(const TRational& rational);
    TRational operator*(const TRational& rational);
    TRational operator=(const TRational& rational);
    TRational operator/(const TRational& rational);
    bool operator==(const TRational& rational);
    bool operator!=(const TRational& rational);

    friend QString& operator<<(QString& s, TRational& rational);

};

#endif
