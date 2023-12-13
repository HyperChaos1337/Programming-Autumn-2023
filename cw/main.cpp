#include "interface.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    Interface interface;
    interface.show();
    return app.exec();
}
