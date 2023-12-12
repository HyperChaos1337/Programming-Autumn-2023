#include "hexnumber.h"

HexNumber::HexNumber(QString value){
    this->value = value;  
}

void HexNumber::setValue(QString value){
    this->value = value;
}

QString HexNumber::getValue() const{
    return value;
}
