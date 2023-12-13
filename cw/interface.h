#ifndef INTERFACE_H
#define INTERFACE_H

#include "hexcalculator.h"
#include "hexstorage.h"

#include <QWidget>
#include <QMessageBox>

inline HexCalculator* HexCalculator::hexCalculator = nullptr;
inline HexStorage* HexStorage::hexStorage = nullptr;

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget{
    Q_OBJECT
public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
private:
    Ui::Interface *ui;
    HexNumber *leftOperand, *rightOperand;
private slots:
    void connectSignals();
    void blockButtons(bool flag);
    void makeCheckable();
    void setUnblockedSave(bool flag);

    void clrscr();
    void backspace();

    void hexDigits();
    void operation();
    void result();

    void store();
    void call();

    void showInfo();
};
#endif // INTERFACE_H
