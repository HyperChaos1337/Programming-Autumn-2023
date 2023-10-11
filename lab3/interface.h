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

class TInterface : public QWidget
{
    Q_OBJECT
    Matrix matrix;

public:
    TInterface(QWidget *parent = nullptr);
    void initInputGUI();
    void connectedButtons();
    ~TInterface();

private:
    Ui::TInterface *ui;
    QLabel *matrix_field, *hint, *determinant, *rank;
    QPushButton *create_button, *show_button, *det_button, *rank_button, *transpose_button;
    QVector<QLineEdit*> lines;

public slots:
    void showMatrix();
    void showDeterminant();
    void showRank();
    void showTranspose();
};
#endif // TINTERFACE_H
