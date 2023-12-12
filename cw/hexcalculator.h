#ifndef HEXCALCULATOR_H
#define HEXCALCULATOR_H

#include "hexnumber.h"

class HexCalculator{
public:
    HexCalculator();
    static QString add(const HexNumber& hex1, const HexNumber& hex2);
    static QString subtract(const HexNumber& hex1, const HexNumber& hex2);
    static QString multiply(const HexNumber& hex1, const HexNumber& hex2);
    static QString divide(const HexNumber& hex1, const HexNumber& hex2);
};

#endif // HEXCALCULATOR_H
