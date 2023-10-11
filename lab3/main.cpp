#include "interface.h"
#include <iostream>
#include <QApplication>
#include <QString>

int main(int argc, char *argv[]){

    srand(time(nullptr));
    QApplication a(argc, argv);
    TInterface w;
    w.initInputGUI();
    w.connectedButtons();
    w.show();
    return a.exec();

}
