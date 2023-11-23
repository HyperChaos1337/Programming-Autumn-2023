#ifndef INTERFACE_H
#define INTERFACE_H

#include <QLineEdit>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT

signals:
    void request(QString);
private:
    Ui::Interface *ui;
    QList<QLineEdit*> lines;
    QString* transposedLines = nullptr;
    QString rankMatrix = "0";
    QString detDecimal = "0";
    QString det = "0";
public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
public slots:
    void initInputMatrix();
    void refreshMatrix();
    void createMatrix();

    void showDeterminant();
    void showTranspose();
    void showRank();

    void connectButtons();
    void enableButtons();
    void disableButtons();

    void answer(QString msg);
};
#endif // INTERFACE_H
