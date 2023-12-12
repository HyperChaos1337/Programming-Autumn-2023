#include "hexcalculator.h"

HexCalculator::HexCalculator(){}

QString HexCalculator::add(const HexNumber &hex1, const HexNumber &hex2){
    bool ok1, ok2;
    int result = hex1.getValue().toInt(&ok1, 16) + hex2.getValue().toInt(&ok2, 16);
    return QString::number(result, 16).toUpper();
}
QString HexCalculator::subtract(const HexNumber &hex1, const HexNumber &hex2){
    bool ok1, ok2;
    int first = hex1.getValue().toInt(&ok1, 16);
    int second = hex2.getValue().toInt(&ok2, 16);
    if(second <= first) {
        int result = first-second;
        return QString::number(result, 16).toUpper();
    }
    else return "Underflow";
}
QString HexCalculator::multiply(const HexNumber &hex1, const HexNumber &hex2){
    bool ok1, ok2;
    int result = hex1.getValue().toInt(&ok1, 16) * hex2.getValue().toInt(&ok2, 16);
    return QString::number(result, 16).toUpper();
}
QString HexCalculator::divide(const HexNumber &hex1, const HexNumber &hex2){
    bool ok1, ok2;
    int divisor = hex2.getValue().toInt(&ok2, 16);
    if (divisor != 0) {
        int result = hex1.getValue().toInt(&ok1, 16) / divisor;
        return QString::number(result, 16).toUpper();
    }
    else return "Cannot divide by Zero";
}
