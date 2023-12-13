#include "interface.h"
#include <QApplication>

int main(int argc, char *argv[]){
    qDebug() << HexStorage::get()->getAt(0);
    /*
    QApplication a(argc, argv);
    Interface w;
    w.show();
    return a.exec();
*/
}
