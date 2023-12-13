#include "hexstorage.h"

HexStorage::HexStorage(){
    for(int i = 0; i < M; i++) storage.push_back(HexNumber("F"));
}

void HexStorage::save(int pos, const HexNumber &number){
    storage.insert(pos, number);
}

QString HexStorage::getAt(int pos){
    return storage.at(pos).getValue();
}

const QVector<HexNumber>& HexStorage::getStorage(){
    return storage;
}
