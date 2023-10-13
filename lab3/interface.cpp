#include "interface.h"
#include "./ui_tinterface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TInterface)
{
    ui->setupUi(this);
    setFixedSize(640, 480);

    matrix.clear_matrix();

    setWindowTitle("Matrix Calculator");

    random_button = new QPushButton("Random Matrix", this);
    random_button->setGeometry(375, 190, 130, 30);

    create_button = new QPushButton("Create Matrix", this);
    create_button->setGeometry(375, 240, 130, 30);

    det_button = new QPushButton("Calculate Determinant", this);
    det_button->setGeometry(375, 290, 130, 30);
    det_button->setEnabled(false);

    transpose_button = new QPushButton("Transpose Matrix", this);
    transpose_button->setGeometry(375, 340, 130, 30);
    transpose_button->setEnabled(false);

    rank_button = new QPushButton("Calculate Rank", this);
    rank_button->setGeometry(375, 390, 130, 30);
    rank_button->setEnabled(false);

    matrix_field = new QLabel("", this);
    matrix_field->setGeometry(50, 30, 200, 200);

    hint = new QLabel("Input matrix here:", this);
    hint->setGeometry(395, 10, 200, 15);

    determinant = new QLabel("", this);
    determinant->setGeometry(50, 200, 200, 50);

    rank = new QLabel("", this);
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

void TInterface::connectButtons(){

    connect(random_button, &QPushButton::clicked, this, &TInterface::randomMatrix);
    connect(create_button, &QPushButton::clicked, this, &TInterface::createMatrix);
    connect(det_button, &QPushButton::clicked, this, &TInterface::showDeterminant);
    connect(rank_button, &QPushButton::clicked, this, &TInterface::showRank);
    connect(transpose_button, &QPushButton::clicked, this, &TInterface::showTranspose);

}


void TInterface::enableButtons(){

    det_button->setEnabled(true);
    transpose_button->setEnabled(true);
    rank_button->setEnabled(true);

}

void TInterface::refresh(){

    matrix_field->setText("");
    determinant->setText("Determinant = ");
    rank->setText("Rank = ");

}
void TInterface::showMatrix(){
    matrix_field->setText(matrix.mat_to_str());
}

void TInterface::randomMatrix(){

    refresh();
    enableButtons();
    matrix.random_matrix();
    showMatrix();

}
void TInterface::createMatrix(){

    refresh();
    enableButtons();

    int i = -1, j = 0;
    int size = matrix.get_order()*matrix.get_order();
    for(int k = 0; k < size; ++k, j++){
        if(k % matrix.get_order() == 0){
            i++;
            j = 0;
        }
        QStringList values = lines[k]->text().split("/");
        matrix.get_matrix()[i][j].set_num(values[0].toInt());
        matrix.get_matrix()[i][j].set_den(values[1].toInt());
        matrix.get_matrix()[i][j].simplify();
    }
    showMatrix();

}
void TInterface::showDeterminant(){

    matrix.set_determinant(matrix.determinant());
    determinant->setText("Determinant = " + matrix.det_to_str());

}
void TInterface::showRank(){

    QString str = QString().setNum(matrix.rank());
    rank->setText("Rank = " + str);

}
void TInterface::showTranspose(){

    matrix.transpose();
    matrix_field->setText(matrix.mat_to_str());

}

void TInterface::initExec(){

    initInputGUI();
    connectButtons();

}

TInterface::~TInterface(){
    delete ui;
}
