#include "interface.h"
#include "ui_interface.h"
#include <QString>
#include <QMessageBox>

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    resize(400, 500);
    setWindowTitle("Matrix Calculator");
    ui->sizeBox->setMinimum(1);
    ui->sizeBox->setMaximum(3);
    ui->sizeBox->setValue(3);
    initInputMatrix();
    connectButtons();
}

Interface::~Interface(){
    delete ui;
}

void Interface::initInputMatrix(){
    int ypos = -1, xpos = 0;
    int size = ui->sizeBox->value() * ui->sizeBox->value();
    for (int i = 0; i < size; ++i) {
        if (i % ui->sizeBox->value() == 0) {
            ypos++;
            xpos = 0;
        }
        QLineEdit* text = new QLineEdit(this);
        if(ui->comboBox->currentIndex() == 0) text->setText(QString::fromStdString("1/1"));
        else if(ui->comboBox->currentIndex() == 1) text->setText(QString::fromStdString("1 + i"));
        else text->setText(QString::fromStdString("1.00"));
        text->setMaximumWidth(50);
        connect(text, &QLineEdit::editingFinished, this, &Interface::disableButtons);
        text->move(QPoint(210 - ui->sizeBox->value() * 45 + xpos++ * 100, 25 + ypos * 50));
        text->show();
        lines.push_back(text);
    }
}
void Interface::refreshMatrix(){
    if(!lines.empty()) qDeleteAll(lines);
    lines.clear();
    initInputMatrix();
}
void Interface::createMatrix(){
    QString msg;
    enableButtons();
    int i = -1, j = 0;
    int size = ui->sizeBox->value() * ui->sizeBox->value();
    msg = ui->sizeBox->text() + ";";
    for (int k = 0; k < size; ++k,j++) {
        if (k % ui->sizeBox->value() == 0) {
            i++;
            j = 0;
        }
        msg += lines[k]->text() + ";";
    }
    emit request(msg);
}

void Interface::showDeterminant(){
    QMessageBox::information(this, "Result",
                             "Matrix determinant = " + det);
}
void Interface::showTranspose(){
    if(transposedLines != nullptr) {
        QString temp;
        for(int i = 0; i < ui->sizeBox->value() * ui->sizeBox->value(); ++i) {
            temp = lines[i]->text();
            lines[i]->setText(transposedLines[i]);
            transposedLines[i] = temp;
        }
    }
    QMessageBox::information(this, "Result", "Matrix has been transposed");
}
void Interface::showRank(){
    QMessageBox::information(this, "Result",
                             "Rank = " + rankMatrix);
}

void Interface::connectButtons(){
    connect(ui->sizeBox, &QSpinBox::valueChanged, this, &Interface::refreshMatrix);
    connect(ui->createButton, &QPushButton::clicked, this, &Interface::createMatrix);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &Interface::refreshMatrix);
    connect(ui->detButton, &QPushButton::clicked, this, &Interface::showDeterminant);
    connect(ui->transposeButton, &QPushButton::clicked, this, &Interface::showTranspose);
    connect(ui->rankButton, &QPushButton::clicked, this, &Interface::showRank);
}
void Interface::enableButtons(){
    ui->detButton->setEnabled(true);
    ui->transposeButton->setEnabled(true);
    ui->rankButton->setEnabled(true);
}
void Interface::disableButtons(){
    ui->detButton->setEnabled(false);
    ui->transposeButton->setEnabled(false);
    ui->rankButton->setEnabled(false);
}

void Interface::answer(QString msg){
    QStringList res = QString::fromStdString(msg.toStdString()).split(";");
    int size = ui->sizeBox->value() * ui->sizeBox->value();
    transposedLines = new QString[size];
    det = res[0];
    detDecimal = res[1];
    rankMatrix = res[2];
    for(int i = 0; i < size; ++i) {
        transposedLines[i] = res[i+3];
    }
}
