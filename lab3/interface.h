#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TInterface; }
QT_END_NAMESPACE

class TInterface : public QWidget{
    Q_OBJECT
    Matrix matrix;
private:
    Ui::TInterface *ui;
    QLabel *matrix_field, *hint, *determinant, *rank;
    QPushButton *random_button, *create_button, *det_button, *rank_button, *transpose_button;
    QVector<QLineEdit*> lines;
public:
    TInterface(QWidget *parent = nullptr);
    void initInputGUI();
    void connectButtons();
    void enableButtons();
    void refresh();
    void showMatrix();
    void initExec();
    ~TInterface();
public slots:
    void randomMatrix();
    void createMatrix();
    void showDeterminant();
    void showRank();
    void showTranspose();
};
#endif // TINTERFACE_H
