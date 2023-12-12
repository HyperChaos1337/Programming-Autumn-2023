#ifndef HEXSTORAGE_H
#define HEXSTORAGE_H

#include "hexnumber.h"

#include <QVector>

class HexStorage{
private:
    const qint16 M = 4;
    QVector<HexNumber> storage;
public:
    HexStorage();
    QString print();
    void save(int pos, const HexNumber& number);
};

#endif // HEXSTORAGE_H
