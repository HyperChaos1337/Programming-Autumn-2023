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

class TInterface : public QWidget
{
    Q_OBJECT

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
private:
    Ui::TInterface *ui;
    QVector<QVector<qint16>> matrix;
    bool permission;
private slots:
    void connectButtons();
    void selectFile();
    bool isValid(const QString& fileContent);
    void drawGraph();
};
#endif // TINTERFACE_H
