#ifndef HEXNUMBER_H
#define HEXNUMBER_H

#pragma once
#include <QString>

class HexNumber {
private:
    QString value;
public:
    HexNumber(QString value);
    void setValue(QString value);
    const QString& getValue() const;
};


#endif // HEXNUMBER_H
