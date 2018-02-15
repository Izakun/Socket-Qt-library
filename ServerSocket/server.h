#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class TCPsocket : public QObject
{
    Q_OBJECT
public:
    explicit TCPsocket(QObject *parent = 0);
    
signals:
    
public slots:
    void newConnection();

private:
    QTcpServer *server;
    
};

#endif // SERVERSOCKET_H
