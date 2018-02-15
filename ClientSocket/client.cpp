#include "client.h"

ClientSocket::ClientSocket(QObject *parent) :
    QObject(parent)
{
}

void ClientSocket::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 1234);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connecté";

        // send
        socket->write("Connecte au server");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Réponse: " << socket->readAll();
        qDebug() << "Nombre de caractere" << socket->bytesAvailable();

        socket->close();
    }
    else
    {
        qDebug() << "Non connetcé";
    }

    // sent

    // got

    // closed
}
