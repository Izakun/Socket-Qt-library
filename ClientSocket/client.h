#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QObject *parent = 0);

    void Connect();
    
signals:
    
public slots:

private:
    QTcpSocket *socket;
    
};

#endif // ClientSocket_H
