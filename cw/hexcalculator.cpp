#include "hexcalculator.h"

HexCalculator::HexCalculator(){}

QString HexCalculator::add(const HexNumber &hex1, const HexNumber &hex2){
    int result = hex1.getValue().toInt(nullptr, 16) + hex2.getValue().toInt(nullptr, 16);
    return QString::number(result, 16).toUpper();
}
QString HexCalculator::subtract(const HexNumber &hex1, const HexNumber &hex2){
    int first = hex1.getValue().toInt(nullptr, 16);
    int second = hex2.getValue().toInt(nullptr, 16);
    if(second <= first) {
        int result = first-second;
        return QString::number(result, 16).toUpper();
    }
    else return "Underflow";
}
QString HexCalculator::multiply(const HexNumber &hex1, const HexNumber &hex2){
    int result = hex1.getValue().toInt(nullptr, 16) * hex2.getValue().toInt(nullptr, 16);
    return QString::number(result, 16).toUpper();
}
QString HexCalculator::divide(const HexNumber &hex1, const HexNumber &hex2){
    int divisor = hex2.getValue().toInt(nullptr, 16);
    if (divisor != 0) {
        int result = hex1.getValue().toInt(nullptr, 16) / divisor;
        return QString::number(result, 16).toUpper();
    }
    else return "Cannot divide by Zero";
}
