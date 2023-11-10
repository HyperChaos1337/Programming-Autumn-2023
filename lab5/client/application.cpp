#include "application.h"

#include <QByteArray>

TApplication::TApplication(int argc, char *argv[])
            : QApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10001,
                         QHostAddress("127.0.0.1"), 10000};
    comm = new TCommunicator(pars, this);

    interface = new Interface();
    interface->show();

    connect(comm, &TCommunicator::recieved,this,
            &TApplication::fromCommunicator);
    connect(interface, &Interface::request,
            this, &TApplication::toCommunicator);

}

void TApplication::fromCommunicator(QByteArray msg){
    interface->answer(QString(msg));
}

void TApplication::toCommunicator(QString msg){
    comm->send(QByteArray().append(msg.toStdString()));
}
