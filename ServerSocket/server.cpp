#include "server.h"

TCPsocket::TCPsocket(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Serveur non lancé";
    }
    else
    {
        qDebug() << "Serveur lancé!";
    }
}

void TCPsocket::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("Nouveau client");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
}
