#include "interface.h"
#include <iostream>
#include <QApplication>
#include <QString>

int main(int argc, char *argv[]){

    /*
    rational num1(1, 120), num2(1, 168), num3(1, 180), num4(1, 192), num5(1, 126), num6(1, 150);
    rational sum1 = num1 + num2;
    sum1.simplify();
    sum1.change_sign();
    rational sum2 = sum1 + num3;
    sum2.simplify();
    sum2.change_sign();
    rational sum3 = sum2 - num4;
    sum3.simplify();
    sum3.change_sign();
    rational sum4 = sum3 - num5;
    sum4.simplify();
    sum4.change_sign();
    rational sum5 = sum4 - num6;
    sum5.simplify();
    sum5.change_sign();

    std::cout << "sum1 = " << sum1.get_num() << "/" << sum1.get_den() << "\n";
    std::cout << "sum2 = " << sum2.get_num() << "/" << sum2.get_den() << "\n";
    std::cout << "sum3 = " << sum3.get_num() << "/" << sum3.get_den() << "\n";
    std::cout << "sum4 = " << sum4.get_num() << "/" << sum4.get_den() << "\n";
    std::cout << "sum5 = " << sum5.get_num() << "/" << sum5.get_den() << "\n";
*/

    srand(time(nullptr));
    QApplication a(argc, argv);
    TInterface w;
    w.initInputGUI();
    w.connectedButtons();
    w.show();
    return a.exec();

}
