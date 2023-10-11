#include "interface.h"
#include "./ui_tinterface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TInterface)
{
    ui->setupUi(this);
    setFixedSize(640, 480);
    matrix.default_matrix();

    setWindowTitle("Matrix Calculator");

    show_button = new QPushButton("Show Matrix", this);
    show_button->setGeometry(375, 190, 130, 30);

    create_button = new QPushButton("Create Matrix", this);
    create_button->setGeometry(375, 240, 130, 30);

    det_button = new QPushButton("Calculate Determinant", this);
    det_button->setGeometry(375, 290, 130, 30);

    transpose_button = new QPushButton("Transpose Matrix", this);
    transpose_button->setGeometry(375, 340, 130, 30);

    rank_button = new QPushButton("Calculate Rank", this);
    rank_button->setGeometry(375, 390, 130, 30);

    matrix_field = new QLabel("", this);
    matrix_field->setGeometry(50, 30, 200, 200);

    hint = new QLabel("Input matrix here:", this);
    hint->setGeometry(395, 10, 200, 15);

    determinant = new QLabel("Determinant = ", this);
    determinant->setGeometry(50, 200, 200, 50);

    rank = new QLabel("Rank = ", this);
    rank->setGeometry(50, 250, 200, 50);

}

void TInterface::initInputGUI(){

    int x = 0, y = -1;
    int size = matrix.get_order() * matrix.get_order();
    for(int i = 0; i < size; i++){
        if(i % matrix.get_order() == 0){
            y++;
            x = 0;
        }
        QLineEdit* text = new QLineEdit(this);
        text->setText("");
        text->setMaximumWidth(50);
        text->move(QPoint(450-matrix.get_order()*45 + x++ * 100, 50 + y * 50));
        text->show();
        lines.push_back(text);
    }

}

void TInterface::connectedButtons(){
    connect(show_button, &QPushButton::clicked, this, &TInterface::showMatrix);
    connect(det_button, &QPushButton::clicked, this, &TInterface::showDeterminant);
    connect(rank_button, &QPushButton::clicked, this, &TInterface::showRank);
    connect(transpose_button, &QPushButton::clicked, this, &TInterface::showTranspose);
}


void TInterface::showMatrix(){

    QString str("");
    for(int i = 0; i < matrix.get_order(); i++){
        for(int j = 0; j < matrix.get_order(); j++){
            str << matrix.get_matrix()[i][j];
            str = str + "\t" + "\t";
        }
        str = str + "\n" + "\n" + "\n";
    }
    matrix_field->setText(str);

}

void TInterface::showDeterminant(){

    QString str("");
    str += QString().setNum(matrix.determinant().get_num());
    str += "/";
    str += QString().setNum(matrix.determinant().get_den());
    determinant->setText("Determinant = " + str);

}

void TInterface::showRank(){
    QString str("");
    str += QString().setNum(matrix.rank(matrix.get_matrix()));
    rank->setText("Rank = " + str);
}

void TInterface::showTranspose(){
    QString str("");
    matrix_field->setText("");
    matrix.transpose();
    for(int i = 0; i < matrix.get_order(); i++){
        for(int j = 0; j < matrix.get_order(); j++){
            str << matrix.get_matrix()[i][j];
            str = str + "\t" + "\t";
        }
        str = str + "\n" + "\n" + "\n";
    }
    matrix_field->setText(str);
}

TInterface::~TInterface()
{
    delete ui;
}

