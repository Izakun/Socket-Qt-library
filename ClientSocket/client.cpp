#include "client.h"

ClientSocket::ClientSocket(QObject *parent) :
    QObject(parent)
{
}

void ClientSocket::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 1234); // defind the ip of the server and the port of the server

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected"; // show this if the connection work

        // send
        socket->write("Connected to the server"); // write this on the client
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Respons: " << socket->readAll();  // write the respons of the server (New client)
        qDebug() << "Char number:" << socket->bytesAvailable(); // write the number of the char (11)

        socket->close();
    }
    else
    {
        qDebug() << "Connection faild"; // show this if the connection failed
    }
}
