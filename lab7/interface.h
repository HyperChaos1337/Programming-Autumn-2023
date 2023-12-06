#ifndef TINTERFACE_H
#define TINTERFACE_H

#include "graph.h"

#include <QFile>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class TInterface; }
QT_END_NAMESPACE

class TInterface : public QWidget{
    Q_OBJECT
public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
private:
    Ui::TInterface *ui;
    //Матрица смежности
    QVector<QVector<qint16>> matrix;
    //Флаг для определения возможности создания графа
    bool permission;
private slots:
    //Выбор файла из каталога
    void selectFile();
    //Проверка содержимого на валидность
    bool isValid(const QString& fileContent);
    //Рисование виджета в окне
    void drawGraph();
};
#endif // TINTERFACE_H
