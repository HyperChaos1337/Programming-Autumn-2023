#include "hexstorage.h"

HexStorage::HexStorage(){
    for(int i = 0; i < M; i++) storage.push_back(HexNumber("0"));
}

QString HexStorage::print(){

    QString res;

    for(const HexNumber &element: storage)
        res = res + element.getValue() + " ";

    return res;

}

void HexStorage::save(int pos, const HexNumber &number){

}
