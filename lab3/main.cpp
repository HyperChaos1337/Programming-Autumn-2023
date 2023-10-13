#include "interface.h"
#include <iostream>
#include <QApplication>
#include <QString>

int main(int argc, char *argv[]){

    srand(time(nullptr));
    QApplication a(argc, argv);
    TInterface interface;
    interface.initExec();
    interface.show();
    return a.exec();

}
