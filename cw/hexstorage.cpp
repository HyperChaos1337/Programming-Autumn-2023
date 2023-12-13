#include "hexstorage.h"

HexStorage::HexStorage(){
    for(int i = 0; i < M; i++) storage.push_back(HexNumber(nullptr));
}

void HexStorage::save(int pos, const HexNumber &number){
    for(int i = 0; i < M; i++){
        if(storage.at(i).getValue() == number.getValue())
            return;
    }
    storage[pos] = number;
}

QString HexStorage::getAt(int pos){

    return storage.at(pos).getValue();
}

const QVector<HexNumber>& HexStorage::getStorage(){
    return storage;
}
