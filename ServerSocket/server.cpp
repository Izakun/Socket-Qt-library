#include "server.h"

TCPsocket::TCPsocket(QObject *parent) :
    QObject(parent)
{
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 1234)) // defind the port for the listener (here 1234)
    {
        qDebug() << "Server not stard"; // show this if it fail
    }
    else
    {
        qDebug() << "Server start"; // show this if it completed
    }
}

void TCPsocket::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();

    socket->write("New client"); // send this message in the client app
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close(); // close connection
}
