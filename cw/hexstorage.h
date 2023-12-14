#ifndef HEXSTORAGE_H
#define HEXSTORAGE_H

#include "hexnumber.h"

#include <QVector>

class HexStorage{
private:
    HexStorage();
    static HexStorage *hexStorage;
    QVector<HexNumber> storage;
    const short M = 4;
public:
    static HexStorage* get(){
        if(hexStorage == nullptr)
            hexStorage = new HexStorage;
        return hexStorage;
    }
public:
    HexStorage(const HexStorage&) = delete;
    void operator = (const HexStorage&) = delete;
    void save(int pos, const HexNumber& number);
    const QVector<HexNumber>& getStorage();
    const QString& getAt(int pos);
};

#endif // HEXSTORAGE_H
