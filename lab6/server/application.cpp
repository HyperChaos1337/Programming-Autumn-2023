#include "application.h"
#include "matrix.h"
#include "t_complex.h"
#include "t_rational.h"
#include <QByteArray>
#include <QString>
#include <iostream>

TApplication::TApplication(int argc, char *argv[])
    : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                        QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg){

    QString answer;
    QStringList res = QString::fromStdString(msg.toStdString()).split(";");
    int type = res[res.size() - 1].toInt();
    if(type == 0){
        Matrix<TRational> matrix(res[0].toInt());
        int i = -1, j = 0;
        int size = matrix.get_order() * matrix.get_order();
        for (int k = 0; k < size; ++k,j++) {
            if (k % matrix.get_order() == 0) {
                i++;
                j = 0;
            }
            QStringList num = res[k+1].split("/");
            matrix.get_matrix()[i][j].set_num(num[0].toInt());
            matrix.get_matrix()[i][j].set_den(num[1].toInt());
        }

        TRational result = matrix.determinant();
        answer += result.to_str() + ";";
        answer += QString::fromStdString(std::to_string((double)((double)result.get_num()
                                                                  / (double)result.get_den()))) + ";";
        answer += QString::fromStdString(std::to_string(matrix.rank())) + ";";

        matrix.transpose();

        for (int i = 0; i < matrix.get_order(); i++)
            for (int j = 0; j < matrix.get_order(); j++) {
                answer += matrix.get_matrix()[i][j].to_str() + ";";
            }
    }
    else if(type == 1){
        Matrix<TComplex> matrix(res[0].toInt());
        int i = -1, j = 0;
        int size = matrix.get_order() * matrix.get_order();
        for (int k = 0; k < size; ++k,j++) {
            if (k % matrix.get_order() == 0) {
                i++;
                j = 0;
            }
            QStringList num = res[k+1].split(" ");
            matrix.get_matrix()[i][j].set_real(num[0].toInt());
            if(num[1] == "+") {
                if(num[2] != "i") matrix.get_matrix()[i][j].set_imaginary(num[2].split("i")[0].toInt());
                else matrix.get_matrix()[i][j].set_imaginary(1);
            }
            else {
                if(num[2] != "i") matrix.get_matrix()[i][j].set_imaginary(-num[2].split("i")[0].toInt());
                else matrix.get_matrix()[i][j].set_imaginary(-1);
            }
        }
        TComplex result = matrix.determinant();
        answer += result.to_str() + ";";
        answer += QString::fromStdString(" ") + ";";
        answer += QString::fromStdString(std::to_string(matrix.rank())) + ";";
        matrix.transpose();
        for (int i = 0; i < matrix.get_order(); i++)
            for (int j = 0; j < matrix.get_order(); j++) {
                answer += matrix.get_matrix()[i][j].to_str() + ";";
            }
    }
    else{
        std::vector<std::vector<double>> array;
        Matrix<double> matrix(res[0].toInt(), array);
        int i = -1, j = 0;
        int size = matrix.get_order() * matrix.get_order();
        for (int k = 0; k < size; ++k,j++) {
            if (k % matrix.get_order() == 0) {
                i++;
                j = 0;
            }
            matrix.get_matrix()[i][j] = res[k+1].toDouble();
        }
        double result = matrix.determinant(matrix.get_matrix());
        answer += std::to_string(result) + ";";
        answer += QString::fromStdString(" ") + ";";
        answer += QString::fromStdString(std::to_string(matrix.rank(matrix.get_matrix()))) + ";";
        matrix.transpose();
        for (int i = 0; i < matrix.get_order(); i++)
            for (int j = 0; j < matrix.get_order(); j++) {
                answer += std::to_string(matrix.get_matrix()[i][j]) + ";";
            }
    }
    comm->send(QByteArray().append(answer.toStdString()));
}
