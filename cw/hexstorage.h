#ifndef HEXSTORAGE_H
#define HEXSTORAGE_H

#include "hexnumber.h"

#include <QVector>

class HexStorage{
private:
    HexStorage();
    static HexStorage *hexStorage;
    QVector<HexNumber> storage;
    const qint16 M = 4;
public:
    static HexStorage* get(){
        if(hexStorage == nullptr)
            hexStorage = new HexStorage;
        return hexStorage;
    }
public:
    void save(int pos, const HexNumber& number);
    const QVector<HexNumber>& getStorage();
    QString getAt(int pos);
};

#endif // HEXSTORAGE_H
