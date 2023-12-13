#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface){
    ui->setupUi(this);
    connectSignals();
    makeCheckable();
    setUnblockedSave(false);
    leftOperand = new HexNumber(nullptr);
    rightOperand = new HexNumber(nullptr);
}

Interface::~Interface(){
    delete ui;
    delete leftOperand;
    delete rightOperand;
}

void Interface::connectSignals(){

    connect(ui->infoButton, &QPushButton::clicked, this, &Interface::showInfo);

    connect(ui->pushButton0, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton1, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton2, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton3, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton4, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton5, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton6, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton7, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton8, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButton9, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButtonA, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButtonB, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButtonC, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButtonD, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButtonE, &QPushButton::clicked, this, &Interface::hexDigits);
    connect(ui->pushButtonF, &QPushButton::clicked, this, &Interface::hexDigits);

    connect(ui->eraseButton, &QPushButton::clicked, this, &Interface::clrscr);
    connect(ui->backspaceButton, &QPushButton::clicked, this, &Interface::backspace);

    connect(ui->plusButton, &QPushButton::clicked, this, &Interface::operation);
    connect(ui->subButton, &QPushButton::clicked, this, &Interface::operation);
    connect(ui->multButton, &QPushButton::clicked, this, &Interface::operation);
    connect(ui->divButton, &QPushButton::clicked, this, &Interface::operation);

    connect(ui->eqButton, &QPushButton::clicked, this, &Interface::result);

    connect(ui->saveButton1, &QPushButton::clicked, this, &Interface::store);
    connect(ui->saveButton2, &QPushButton::clicked, this, &Interface::store);
    connect(ui->saveButton3, &QPushButton::clicked, this, &Interface::store);
    connect(ui->saveButton4, &QPushButton::clicked, this, &Interface::store);

    connect(ui->callButton1, &QPushButton::clicked, this, &Interface::call);
    connect(ui->callButton2, &QPushButton::clicked, this, &Interface::call);
    connect(ui->callButton3, &QPushButton::clicked, this, &Interface::call);
    connect(ui->callButton4, &QPushButton::clicked, this, &Interface::call);

}
void Interface::blockButtons(bool flag){

    ui->plusButton->setDisabled(flag);
    ui->subButton->setDisabled(flag);
    ui->multButton->setDisabled(flag);
    ui->divButton->setDisabled(flag);
    ui->eqButton->setDisabled(flag);

    ui->pushButton0->setDisabled(flag);
    ui->pushButton1->setDisabled(flag);
    ui->pushButton2->setDisabled(flag);
    ui->pushButton3->setDisabled(flag);
    ui->pushButton4->setDisabled(flag);
    ui->pushButton5->setDisabled(flag);
    ui->pushButton6->setDisabled(flag);
    ui->pushButton7->setDisabled(flag);
    ui->pushButton8->setDisabled(flag);
    ui->pushButton9->setDisabled(flag);
    ui->pushButtonA->setDisabled(flag);
    ui->pushButtonB->setDisabled(flag);
    ui->pushButtonC->setDisabled(flag);
    ui->pushButtonD->setDisabled(flag);
    ui->pushButtonE->setDisabled(flag);
    ui->pushButtonF->setDisabled(flag);

    ui->backspaceButton->setDisabled(flag);

    ui->callButton1->setDisabled(flag);
    ui->callButton2->setDisabled(flag);
    ui->callButton3->setDisabled(flag);
    ui->callButton4->setDisabled(flag);

}
void Interface::makeCheckable(){

    ui->plusButton->setCheckable(true);
    ui->subButton->setCheckable(true);
    ui->multButton->setCheckable(true);
    ui->divButton->setCheckable(true);

}
void Interface::setUnblockedSave(bool flag){

    ui->saveButton1->setEnabled(flag);
    ui->saveButton2->setEnabled(flag);
    ui->saveButton3->setEnabled(flag);
    ui->saveButton4->setEnabled(flag);

}

void Interface::clrscr(){

    blockButtons(false);
    setUnblockedSave(false);
    leftOperand->setValue(nullptr);
    rightOperand->setValue(nullptr);
    ui->result->setText("0");
    ui->logs->setText("");

}
void Interface::backspace(){

    ui->result->setText(ui->result->text().removeLast());

    if(ui->result->text().size() == 0)
        ui->result->setText("0");

}

void Interface::hexDigits(){

    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if(ui->result->text() == '0')
        ui->result->setText("");

    ui->result->setText(ui->result->text() + button->text());

}
void Interface::operation(){

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    leftOperand->setValue(ui->result->text());
    ui->logs->setText(leftOperand->getValue());

    if(!ui->logs->text().contains(button->text()))
        ui->logs->setText(ui->logs->text() + button->text());

    ui->result->setText("");
    button->setChecked(true);

}
void Interface::result(){

    rightOperand->setValue(ui->result->text());
    HexNumber* result = new HexNumber(nullptr);

    if(ui->plusButton->isChecked()){
        result->setValue(HexCalculator::get()->add(*leftOperand, *rightOperand));
        ui->logs->setText(ui->logs->text() + rightOperand->getValue());
        ui->result->setText(result->getValue());
        ui->plusButton->setChecked(false);
    }

    if(ui->subButton->isChecked()){
        result->setValue(HexCalculator::get()->subtract(*leftOperand, *rightOperand));
        ui->logs->setText(ui->logs->text() + rightOperand->getValue());
        ui->result->setText(result->getValue());
        ui->subButton->setChecked(false);
    }
    if(ui->multButton->isChecked()){
        result->setValue(HexCalculator::get()->multiply(*leftOperand, *rightOperand));
        ui->logs->setText(ui->logs->text() + rightOperand->getValue());
        ui->result->setText(result->getValue());
        ui->multButton->setChecked(false);
    }
    if(ui->divButton->isChecked()){
        result->setValue(HexCalculator::get()->divide(*leftOperand, *rightOperand));
        ui->logs->setText(ui->logs->text() + rightOperand->getValue());
        ui->result->setText(result->getValue());
        ui->divButton->setChecked(false);
    }

    if(!ui->logs->text().contains('='))
        ui->logs->setText(ui->logs->text() + ui->eqButton->text());

    blockButtons(true);

    if(ui->result->text() == "Cannot divide by Zero" ||
        ui->result->text() == "Underflow" ||
        ui->result->text() == "0") setUnblockedSave(false);
    else setUnblockedSave(true);
    delete result;

}

void Interface::store(){

}
void Interface::call(){

}

void Interface::showInfo(){

    QMessageBox::information(this, "Information",
                             "Hello there\n"
                             "It's cold here(");

}
