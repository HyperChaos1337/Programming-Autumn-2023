#ifndef HEXCALCULATOR_H
#define HEXCALCULATOR_H

#include "hexnumber.h"

class HexCalculator{
private:
    HexCalculator();
    static HexCalculator* hexCalculator;
public:
    static HexCalculator* get(){
        if(hexCalculator == nullptr)
            hexCalculator == new HexCalculator;
        return hexCalculator;
    }
public:
    HexCalculator(const HexCalculator&) = delete;
    void operator = (const HexCalculator&) = delete;
    QString add(const HexNumber& hex1, const HexNumber& hex2);
    QString subtract(const HexNumber& hex1, const HexNumber& hex2);
    QString multiply(const HexNumber& hex1, const HexNumber& hex2);
    QString divide(const HexNumber& hex1, const HexNumber& hex2);
};

#endif // HEXCALCULATOR_H
